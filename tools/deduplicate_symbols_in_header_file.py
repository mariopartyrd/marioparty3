#!/usr/bin/env python3
"""
C Header File Deduplicator
Removes duplicate function declarations and extern variable declarations
"""

import re
import sys
from collections import OrderedDict


def normalize_whitespace(line):
    """Normalize whitespace in a declaration for comparison"""
    # Remove extra spaces while preserving structure
    return ' '.join(line.split())


def is_function_declaration(line):
    """Check if line is a function declaration"""
    line = line.strip()
    # Skip if it's a comment, typedef, struct, enum, or define
    if (line.startswith('//') or line.startswith('/*') or 
        line.startswith('typedef') or line.startswith('struct') or
        line.startswith('enum') or line.startswith('#')):
        return False
    # Check for function declaration pattern (ends with semicolon, has parentheses)
    return '(' in line and line.endswith(';') and not line.startswith('extern')


def is_extern_declaration(line):
    """Check if line is an extern variable declaration"""
    line = line.strip()
    return line.startswith('extern') and line.endswith(';') and '(' not in line


def deduplicate_header(input_file, output_file=None):
    """
    Remove duplicate declarations from C header file
    
    Args:
        input_file: Path to input header file
        output_file: Path to output file (if None, prints to stdout)
    """
    with open(input_file, 'r') as f:
        lines = f.readlines()
    
    seen_declarations = OrderedDict()
    result_lines = []
    
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        
        # Check if it's a function or extern declaration
        if is_function_declaration(stripped) or is_extern_declaration(stripped):
            # Handle multi-line declarations
            full_declaration = line
            while not stripped.endswith(';'):
                i += 1
                if i >= len(lines):
                    break
                line = lines[i]
                full_declaration += line
                stripped = line.strip()
            
            # Normalize for comparison
            normalized = normalize_whitespace(full_declaration.strip())
            
            # Only keep first occurrence
            if normalized not in seen_declarations:
                seen_declarations[normalized] = full_declaration
                result_lines.append(full_declaration)
            # else: skip duplicate
        else:
            # Keep all other lines (comments, typedefs, structs, etc.)
            result_lines.append(line)
        
        i += 1
    
    # Write output
    output_content = ''.join(result_lines)
    
    if output_file:
        with open(output_file, 'w') as f:
            f.write(output_content)
        print(f"Deduplicated header written to: {output_file}")
        print(f"Removed {len(lines) - len(result_lines)} duplicate declaration lines")
    else:
        print(output_content)
    
    return len(lines) - len(result_lines)


def main():
    if len(sys.argv) < 2:
        print("Usage: python deduplicate_header.py <input_file> [output_file]")
        print("If output_file is not provided, result is printed to stdout")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) > 2 else None
    
    try:
        duplicates_removed = deduplicate_header(input_file, output_file)
        if duplicates_removed > 0:
            print(f"Successfully removed {duplicates_removed} duplicate lines")
        else:
            print("No duplicates found")
    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found")
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()