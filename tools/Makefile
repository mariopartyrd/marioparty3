MAKE = make


UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
	HOST_TRIPLE := x86_64-pc-windows-msvc
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
	HOST_TRIPLE := x86_64-unknown-linux-musl
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := mac
	MAKE := gmake
	CPPFLAGS += -xc++
	HOST_TRIPLE := x86_64-apple-darwin
endif


ifeq ($(DETECTED_OS),windows)
$(error This repo does not support compiling on native Windows yet, please use WSL instead.)
endif


KMC_DIR         := gcc_2.7.2/$(DETECTED_OS)
KMC_GCC         := $(KMC_DIR)/gcc
KMC_BINUTILS    := $(KMC_DIR)/as

IDO_53_DIR      := ido_recomp/$(DETECTED_OS)/5.3
IDO_53_CC       := $(IDO_53_DIR)/cc

SLINKY_DIR      := slinky
SLINKY          := $(SLINKY_DIR)/slinky-cli


all: $(KMC_GCC) $(KMC_BINUTILS) $(IDO_53_CC) $(SLINKY)

clean:
	$(RM) -rf $(KMC_DIR) gcc_2.7.2 $(IDO_53_DIR) ido_recomp $(SLINKY_DIR)

distclean: clean
	cargo clean --manifest-path rstools/Cargo.toml

.PHONY: all clean distclean

$(KMC_GCC): | $(KMC_DIR)
	wget https://github.com/decompals/mips-gcc-2.7.2/releases/latest/download/gcc-2.7.2-$(DETECTED_OS).tar.gz
	tar xf gcc-2.7.2-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) gcc-2.7.2-$(DETECTED_OS).tar.gz

$(KMC_BINUTILS): | $(KMC_DIR)
	wget https://github.com/decompals/mips-binutils-2.6/releases/latest/download/binutils-2.6-$(DETECTED_OS).tar.gz
	tar xf binutils-2.6-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) binutils-2.6-$(DETECTED_OS).tar.gz

$(IDO_53_CC): | $(IDO_53_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-$(DETECTED_OS).tar.gz
	tar xf ido-5.3-recomp-$(DETECTED_OS).tar.gz -C $(IDO_53_DIR)
	$(RM) ido-5.3-recomp-$(DETECTED_OS).tar.gz

$(SLINKY): | $(SLINKY_DIR)
	wget https://github.com/decompals/slinky/releases/download/0.3.0/slinky-cli-$(HOST_TRIPLE).tar.gz
	tar xf slinky-cli-$(HOST_TRIPLE).tar.gz -C $(SLINKY_DIR)
	$(RM) slinky-cli-$(HOST_TRIPLE).tar.gz

$(KMC_DIR):
	mkdir -p $@

$(IDO_53_DIR):
	mkdir -p $@

$(SLINKY_DIR):
	mkdir -p $@