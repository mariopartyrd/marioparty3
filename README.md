[![](https://img.shields.io/discord/994839212618690590?color=%235865F2&label=Discord&logo=discord&logoColor=ffffff&style=plastic)](https://discord.gg/T4faGveujK)<br/>
![Mario Party Decompilation Discord](https://media.discordapp.net/attachments/872764411851452416/994832403195498506/MarioParty3Logo4.png)

# Building

## Prerequisites

This project supports:

- Ubuntu (22.04 LTS) WSL 2 on Windows
- Native Debian or Arch Linux

## Setup

1. Run `./tools/install.sh` to get the dependencies and set up a virtual Python environment.
2. Copy a US ROM of Mario Party 3 named `baserom.us.z64` to the root of the repo.
3. Run `cd tools && make` to install additional dependencies.
4. Run `make setup` from the repository root, which will generate assembly files for nonmatched functions and a linker script.
5. Run `make -j` to compile.

To fully clear out the asm files, run `make distclean` which will require another `make setup` and `make -j` to compile again

Before building in a new shell, run `source venv/bin/activate` to establish the virtual environment.
