#!/bin/bash

# Debian and derivatives (apt)
if cat /etc/os-release | grep -E 'ID=debian|ID_LIKE=(.*)debian' &> /dev/null; then
    supported=true

    echo "Installing packages for Debian or derivative (apt)"

    sudo apt install python3-venv
    # Add i386 arch for wine32
    sudo apt -y install python3-pip
    sudo apt-get install -y gcc-mips-linux-gnu
    # Check if requirements.txt exists
    if [ ! -f "requirements.txt" ]; then
    echo "requirements.txt not found!"
    exit 1
    fi

    # Create a virtual environment in the 'venv' directory
    echo "Creating virtual environment..."
    python3 -m venv venv

    # Activate the virtual environment
    echo "Activating virtual environment..."
    source venv/bin/activate

    # Install the required dependencies
    echo "Installing dependencies..."
    pip install -r requirements.txt

    echo "Setup complete! Virtual environment is ready and dependencies are installed."

    # Keep the virtual environment activated (optional)
    exec "$SHELL"
fi