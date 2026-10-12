#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$repo_root"

if [[ -f "venv/bin/activate" ]]; then
    # Project build tools expect the repository virtualenv when it is available.
    # shellcheck disable=SC1091
    source "venv/bin/activate"
fi

splat=0
verbose=0
for arg in "$@"; do
    case "$arg" in
        --clean)
            make distclean
            # --clean implies a full regeneration, so behave like --splat.
            splat=1
            ;;
        --splat)
            splat=1
            ;;
        --verbose)
            verbose=1
            ;;
        *)
            echo "Unknown argument: $arg" >&2
            exit 1
            ;;
    esac
done

# Suppress progress output unless --verbose is given. The Makefile only
# silences progress messages for direct `make` when QUIET=1 is passed.
quiet=()
if [[ "$verbose" -eq 0 ]]; then
    quiet=(QUIET=1)
fi

if [[ "$splat" -eq 1 ]]; then
    make "${quiet[@]}" setup
fi

exec make -j "${quiet[@]}"
