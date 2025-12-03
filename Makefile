### Build Options ###

BASEROM      := baserom.us.z64
TARGET       := marioparty3
COMPARE      ?= 1
NON_MATCHING ?= 0
CHECK        ?= 1
VERBOSE      ?= 0
MOD 		 ?= 0

# Patches
# PATCHES_ASFLAGS := --defsym MP_SAVETYPE_PATCH=1

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif

ifeq ($(OS),Windows_NT)
  DETECTED_OS=windows
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Linux)
    DETECTED_OS=linux
  endif
  ifeq ($(UNAME_S),Darwin)
    DETECTED_OS=macos
    MAKE=gmake
    CPPFLAGS += -xc++
  endif
endif


### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET).z64
ELF       := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP    := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON		:= venv/bin/python3  # Ensure we're using the Python from the virtual environment
N64CKSUM	:= $(PYTHON) tools/n64cksum.py
SPLAT_YAML	:= marioparty3.yaml
MOD_YAML	:= marioparty3_mod.yaml
SPLAT	:= $(PYTHON) -m splat split $(SPLAT_YAML)  # Use splat from the virtual environment
MOD_SPLAT	:= $(PYTHON) -m splat split $(MOD_YAML)  # Use splat from the virtual environment
MOD_LINKER_INJECT := $(PYTHON) ./tools/append_mod_to_linker_script.py
MOD_OVL_TABLE_INJECT := $(PYTHON) ./tools/gen_new_overlay_table_file.py
MOD_SET_SAVE_TYPE := $(PYTHON) ./tools/set_advanced_homebrew_header.py
EMULATOR   := mupen64plus
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip

CC       := tools/gcc_2.7.2/$(DETECTED_OS)/gcc
CC_HOST  := gcc
CPP      := cpp -P

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
 PURPLE    := \033[0;35m
 ENDPURPLE := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###

ASFLAGS        := -G 0 -I include -mips3 -mabi=32
CFLAGS         := -G0 -mips3 -mgp32 -mfp32 -Wa,--vr4300mul-off -D_LANGUAGE_C -DOLD_GCC
CPPFLAGS     := -I include -I $(BUILD_DIR)/include -I src -DF3DEX_GBI_2 -D_LANGUAGE_C
LDFLAGS        := -T undefined_syms.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CHECK_WARNINGS := -Wall -Wextra -Wunused-but-set-variable -Wno-format-security -Wno-unused-parameter -Wno-sign-compare -Wno-unused-variable -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -m32
CFLAGS_CHECK   := -fcommon -fsyntax-only -fsigned-char -nostdinc -fno-builtin -D CC_CHECK -D _LANGUAGE_C -std=gnu90 $(CHECK_WARNINGS)

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

ifeq ($(MOD),1)
CFLAGS += -DMOD
CPPFLAGS += -DMOD
endif

OPTFLAGS := -O1

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' marioparty3.ld -o)
DEPENDS := $(OBJECTS:=.d) 

### Targets ###

build/src/libhmath/%.o: CFLAGS := -O2 -G0 -mips3 -mgp32 -mfp32 -ffast-math

#build/src/libultra/os/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
#build/src/libultra/libc/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
# build/src/2.0L/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)

all: $(ROM)

-include $(DEPENDS)

clean:
	$(V)rm -rf build

distclean: clean
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -f *auto.txt
	$(V)rm -f marioparty3.ld
	$(V)rm -f include/ld_addrs.h

setup: distclean split

modsetup: distclean modsplit

modsplit:
	$(V)rm -rf asm
#	$(V)$(MOD_OVL_TABLE_INJECT)
	$(V)$(MOD_SPLAT)
#	$(V)$(MOD_LINKER_INJECT)

split:
	$(V)rm -rf asm
	$(V)$(SPLAT)
	
test: $(ROM)
	$(V)$(EMULATOR) $<

# Flags for individual files. TODO: move these to a common directory and make this a directory thing instead
build/src/2.0L/audio/%.c.o: OPTFLAGS = -O2
build/src/2.0L/audio/%.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI -D__MIPSEB__
build/src/2.0L/audio/%.c.o: CPPFLAGS = -I include -I include/PR -I include/gcc -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2
build/src/8A6B0.c.o: OPTFLAGS = -O2 #Could also be -O3?
build/src/2.0L/libc/sprintf.c.o: OPTFLAGS = -O2
build/src/2.0L/libc/syncprintf.c.o: OPTFLAGS = -O2
build/src/2.0L/libc/string.c.o: OPTFLAGS = -O2
build/src/2.0L/libc/xprintf.c.o: OPTFLAGS = -O2
build/src/88CF0.c.o: OPTFLAGS = -O2
build/src/88CF0.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# Files that must have -Wa,--vr4300mul-off disabled:
build/src/gamemes.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/pause.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/overlays/ovl_31_vine_with_me/%.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/overlays/ovl_36_motor_rooter/system.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/overlays/ovl_37_silly_screws/%.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/overlays/ovl_39_tick_tock_hop/%.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common
build/src/overlays/ovl_80_shared_board/ECA50.c.o: CFLAGS = -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C -fno-common

# Compile .c files with kmc gcc (use strip to fix objects so that they can be linked with modern gnu ld) 
$(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2/$(DETECTED_OS) && $(CC) $(OPTFLAGS) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@$(STRIP) $@ -N dummy-symbol-name

# Assemble .s files with modern gnu as
$(BUILD_DIR)/asm/%.s.o: asm/%.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
# Only patch save type if MOD=1
	@if [ "$(MOD)" = "1" ]; then \
	    $(MOD_SET_SAVE_TYPE); \
	fi
	$(V)$(N64CKSUM) $@
ifeq ($(COMPARE),1)
ifeq ($(MOD),0)
	@$(DIFF) $(BASEROM) $(ROM) && printf "OK\n" || (echo 'The build succeeded, but did not match the base ROM. To skip this check, use "make COMPARE=0".' && false)
else
	@$(PRINT)$(GREEN)Modified ROM: $(ENDGREEN)$(BLUE)build/marioparty3.z64$(ENDBLUE) built!$(ENDLINE)
endif
endif



### Make Settings ###

.PHONY: all clean distclean test setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
