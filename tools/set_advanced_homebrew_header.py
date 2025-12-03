#!/usr/bin/env python3
import os

ROM_PATH = "build/marioparty3.z64"
OFFSET   = 0x3F
VALUE    = 0x20

def main():
    if not os.path.isfile(ROM_PATH):
        print(f"Error: ROM not found: {ROM_PATH}")
        return

    with open(ROM_PATH, "r+b") as f:
        f.seek(OFFSET)
        f.write(bytes([VALUE]))

    #print(f"Patched {ROM_PATH}: offset 0x{OFFSET:X} = 0x{VALUE:02X}")

if __name__ == "__main__":
    main()
