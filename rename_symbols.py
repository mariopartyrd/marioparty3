import os
import re
import sys

# ==============================
# Configuration
# ==============================
SYMBOL_ADDRS_FILE = "symbol_addrs.txt"
EXCLUDED_EXTENSIONS = {".s", ".txt", ".map", ".d"}
ROOT_DIR = "."  # start from current directory

# Regex for func_RAM_ROM_segment pattern
FUNC_PATTERN = re.compile(r"^func_([0-9A-Fa-f]+)_([0-9A-Fa-f]+)_([A-Za-z0-9_]+)$")

# Regex for "old = new" or "old new" format
LINE_PATTERN = re.compile(r"^\s*([^=\s]+)\s*(?:=|\s)\s*([A-Za-z0-9_]+)\s*$")


def parse_symbol_mappings(mapping_text):
    """Parse a list of symbol rename lines."""
    mappings = {}
    for line in mapping_text.splitlines():
        line = line.strip()
        if not line or line.startswith("//"):
            continue
        match = LINE_PATTERN.match(line)
        if match:
            old, new = match.groups()
            mappings[old.strip()] = new.strip()
    return mappings


def append_symbol_to_addrs(symbol_file, old, new):
    """Add a new line to symbol_addrs.txt for func_RAM_ROM_segment symbols."""
    match = FUNC_PATTERN.match(old)
    if not match:
        return False
    ram, rom, seg = match.groups()
    entry = f"{new} = 0x{ram.upper()}; //rom:0x{rom.upper()} segment:{seg}\n"

    # Avoid duplicates
    if os.path.exists(symbol_file):
        with open(symbol_file, "r", encoding="utf-8") as f:
            if new in f.read():
                return False

    with open(symbol_file, "a", encoding="utf-8") as f:
        f.write(entry)
    print(f"✅ Added {new} to {symbol_file}")
    return True


def replace_symbols_in_repo(mappings, root_dir):
    """Replace symbol names across repo, skipping excluded file types."""
    print("🔍 Replacing symbols in repo...")
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            _, ext = os.path.splitext(filename)
            if ext in EXCLUDED_EXTENSIONS:
                continue
            if filename == os.path.basename(SYMBOL_ADDRS_FILE):
                continue  # don't rewrite symbol_addrs.txt

            filepath = os.path.join(dirpath, filename)
            try:
                with open(filepath, "r", encoding="utf-8") as f:
                    text = f.read()
            except (UnicodeDecodeError, OSError):
                continue  # skip binary/unreadable files

            original = text
            for old, new in mappings.items():
                text = re.sub(rf"\b{re.escape(old)}\b", new, text)

            if text != original:
                with open(filepath, "w", encoding="utf-8") as f:
                    f.write(text)
                print(f"✏️  Updated: {filepath}")


def main():
    if len(sys.argv) < 2:
        print("Usage: python rename_symbols.py <mapping_file.txt>")
        sys.exit(1)

    mapping_file = sys.argv[1]
    with open(mapping_file, "r", encoding="utf-8") as f:
        mapping_text = f.read()

    mappings = parse_symbol_mappings(mapping_text)
    print(f"📘 Loaded {len(mappings)} mappings.")

    # Ensure symbol_addrs.txt exists
    if not os.path.exists(SYMBOL_ADDRS_FILE):
        open(SYMBOL_ADDRS_FILE, "w").close()

    # Append entries for any func_... symbols
    for old, new in mappings.items():
        append_symbol_to_addrs(SYMBOL_ADDRS_FILE, old, new)

    # Perform replacements across repo
    replace_symbols_in_repo(mappings, ROOT_DIR)

    print("✅ All done!")


if __name__ == "__main__":
    main()
