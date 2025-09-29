<img src="https://github.com/user-attachments/assets/1e20e404-6d03-4b4c-945a-bc2e0309969b" width=400 />

# coddog - the dog that sniffs for cod

coddog allows you to more efficiently decompile binaries by reducing redundant work. Whether it's identifying library functions, de-duplicating code, or looking for ways to get the codegen you want for that one portion of a function, coddog will find your cod!

## Features

### **match**: Function matching

Find functions that are similar to a query function

```
~/repos/pokemonsnap$ coddog match func_80348C08_828378 -t 0.7
100.00% - func_802ECC44_5E9D14 (decompiled)
100.00% - func_802E01F4_6C7FD4 (decompiled)
100.00% - func_802C57A4_647C54 (decompiled)
73.33% - finishLevel (decompiled)
73.10% - func_802D9DD8_6C1BB8
71.88% - osAiSetFrequency (decompiled)
70.89% - func_800E1930_A08EC0 (decompiled)
70.19% - func_802D0D0C_7AA29C
```

### **cluster**: Function clustering

Find clusters of functions that are identical or near-identical in one binary. This can be useful for de-duplicating redundant code and turning common functions into #includes.

```
~/repos/pokemonsnap$ coddog cluster -m 10
Cluster func_802C8998_7A1F28 has 23 symbols
Cluster func_802E1110_6C8EF0 has 12 symbols
Cluster func_802C2D00_6451B0 has 12 symbols
Cluster func_802CA858_7A3DE8 has 10 symbols
Cluster func_beach_802C68D8 has 8 symbols
```

### **submatch**: Partial function matching

Find n-length segments of code that are common between the ones found in the given query function and all other functions in a binary (and soon, beyond)

```
~/repos/pokemonsnap$ coddog submatch finishLevel 30
func_credits_801DE060 (decompiled):
        query [41-77] matches func_credits_801DE060 [insn 101-137] (36 total)
func_800A081C:
        query [42-76] matches func_800A081C [insn 165-199] (34 total)
func_8035464C_4F4A5C (decompiled):
        query [43-77] matches func_8035464C_4F4A5C [insn 81-115] (34 total)
updateIdle (decompiled):
        query [23-89] matches updateIdle [insn 107-173] (66 total)
```

## Experimental features

### **compare2**: Find common functions between one binary and another

```
~/repos/pokemonsnap$ coddog compare2 decomp.yaml us ~/repos/stadium/decomp.yaml us
alMainBusPull (decompiled) - alMainBusPull (decompiled) (98.61%)
__ll_div (decompiled) - __ll_div (decompiled) (100.00%)
__osIdCheckSum (decompiled) - __osIdCheckSum (decompiled) (100.00%)
__ull_to_d (decompiled) - __ull_to_d (decompiled) (100.00%)
__osSumcalc (decompiled) - __osSumcalc (decompiled) (100.00%)
__ll_lshift (decompiled) - __ll_lshift (decompiled) (100.00%)
Vec3fDiff (decompiled) - func_8000E958 (100.00%)
```

### **compare-n**: Find common functions between one binary and multiple others
```
~/repos/pokemonsnap$ coddog compare-n decomp.yaml us /home/ethteck/repos/papermario/decomp.yaml
Comparing Pokemon Snap US to Paper Mario US:
func_80369F80_83D730 (decompiled) - npc_set_palswap_2 (decompiled) (90.91%)
alFxParam (decompiled) - au_SEFCmd_06_FineTune (decompiled) (91.67%)
alLink (decompiled) - alLink (decompiled) (93.33%)
alUnlink (decompiled) - alUnlink (decompiled) (90.91%)
func_800C1E04_5ECA4 - osFlashWriteBuffer (decompiled) (92.00%)

Comparing Pokemon Snap US to Paper Mario PAL:
No matches found

Comparing Pokemon Snap US to Paper Mario iQue:
func_80369F80_83D730 (decompiled) - npc_set_palswap_2 (decompiled) (90.91%)
alFxParam (decompiled) - au_SEFCmd_06_FineTune (decompiled) (91.67%)
alLink (decompiled) - alLink (decompiled) (93.33%)
alUnlink (decompiled) - alUnlink (decompiled) (90.91%)

Comparing Pokemon Snap US to Paper Mario JP:
func_80369F80_83D730 (decompiled) - npc_set_palswap_2 (decompiled) (90.91%)
alFxParam (decompiled) - au_SEFCmd_06_FineTune (decompiled) (91.67%)
alLink (decompiled) - alLink (decompiled) (93.33%)
alUnlink (decompiled) - alUnlink (decompiled) (90.91%)
func_800C1E04_5ECA4 - osFlashWriteBuffer (decompiled) (92.00%)
```

### Configuration
coddog reads [decomp.yaml](https://github.com/ethteck/decomp_settings) files to understand the attributes of a project.
