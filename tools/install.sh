#!/usr/bin/env bash
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TOOLS_BIN="$REPO_ROOT/tools/bin"

cd "$REPO_ROOT"

if [ ! -f /etc/os-release ]; then
    echo "Cannot detect Linux distribution: /etc/os-release not found."
    exit 1
fi

# shellcheck disable=SC1091
. /etc/os-release

is_debian_like() {
    [ "${ID:-}" = "debian" ] || [ "${ID:-}" = "ubuntu" ] || [[ " ${ID_LIKE:-} " == *" debian "* ]]
}

is_arch_like() {
    [ "${ID:-}" = "arch" ] || [[ " ${ID_LIKE:-} " == *" arch "* ]]
}

configure_local_mips_wrappers() {
    if command -v mips-linux-gnu-as >/dev/null 2>&1; then
        return
    fi

    if ! command -v mips-elf-as >/dev/null 2>&1; then
        cat <<'EOF'

Missing MIPS binutils:
  The repo expects mips-linux-gnu-* binutils.
  On Arch, install mips-elf-binutils from the AUR, then rerun this script:

    yay -S mips-elf-binutils

EOF
        return 1
    fi

    mkdir -p "$TOOLS_BIN"
    for tool in as ld objcopy objdump strip; do
        cat > "$TOOLS_BIN/mips-linux-gnu-$tool" <<EOF
#!/usr/bin/env bash
exec "mips-elf-$tool" "\$@"
EOF
        chmod +x "$TOOLS_BIN/mips-linux-gnu-$tool"
    done

    echo "Created repo-local mips-linux-gnu-* wrappers in tools/bin."
}

install_debian_packages() {
    echo "Installing packages for Debian or derivative (apt)..."
    sudo apt-get update
    sudo apt-get install -y python3 python3-venv python3-pip gcc-mips-linux-gnu
}

install_arch_packages() {
    echo "Installing packages for Arch Linux or derivative (pacman)..."
    sudo pacman -Syu --needed python python-pip base-devel git make wget

    if command -v mips-linux-gnu-as >/dev/null 2>&1 || command -v mips-elf-as >/dev/null 2>&1; then
        return
    fi

    for aur_helper in yay paru; do
        if command -v "$aur_helper" >/dev/null 2>&1; then
            echo "Installing mips-elf-binutils from the AUR with $aur_helper..."
            "$aur_helper" -S --needed mips-elf-binutils
            return
        fi
    done
}

setup_python_venv() {
    if [ ! -f requirements.txt ]; then
        echo "requirements.txt not found!"
        exit 1
    fi

    echo "Creating virtual environment..."
    python3 -m venv venv

    echo "Activating virtual environment..."
    # shellcheck disable=SC1091
    source venv/bin/activate

    if ! grep -Fq "$TOOLS_BIN" venv/bin/activate; then
        cat >> venv/bin/activate <<EOF

# Add repo-local tool wrappers created by tools/install.sh.
export PATH="$TOOLS_BIN:\$PATH"
EOF
    fi
    export PATH="$TOOLS_BIN:$PATH"

    echo "Installing Python dependencies..."
    python -m pip install -r requirements.txt
}

if is_debian_like; then
    install_debian_packages
elif is_arch_like; then
    install_arch_packages
else
    echo "Unsupported distribution: ${PRETTY_NAME:-${ID:-unknown}}"
    echo "Supported distributions: Debian/Ubuntu derivatives and Arch Linux derivatives."
    exit 1
fi

configure_local_mips_wrappers
setup_python_venv

cat <<'EOF'

Setup complete. The virtual environment is ready and dependencies are installed.
Run this before building in a new shell:

  source venv/bin/activate

EOF
