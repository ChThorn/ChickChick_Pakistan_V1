#!/bin/bash

# Get the absolute path of the script location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
FIRST_RUN_FLAG="$SCRIPT_DIR/.dependencies_installed"

# Function to detect the Linux distribution
detect_distro() {
    if [ -f /etc/os-release ]; then
        . /etc/os-release
        DISTRO=$ID
    elif [ -f /etc/lsb-release ]; then
        . /etc/lsb-release
        DISTRO=$DISTRIB_ID
    elif [ -f /etc/debian_version ]; then
        DISTRO="debian"
    elif [ -f /etc/fedora-release ]; then
        DISTRO="fedora"
    elif [ -f /etc/arch-release ]; then
        DISTRO="arch"
    else
        DISTRO="unknown"
    fi
    echo "Detected distribution: $DISTRO"
}

# Function to install dependencies based on the distribution
install_dependencies() {
    case $DISTRO in
        ubuntu|debian)
            echo "Installing dependencies for Debian/Ubuntu..."
            sudo apt-get update
            sudo apt-get install -y \
                libqt5core5a \
                libqt5gui5 \
                libqt5widgets5 \
                libqt5network5 \
                libqt5sql5 \
                libqt5sql5-sqlite \
                libqt5serialport5 \
                libqt5printsupport5 \
                libqt5xml5
            ;;
        fedora|centos|rhel)
            echo "Installing dependencies for Fedora/CentOS/RHEL..."
            sudo dnf install -y \
                qt5-qtbase \
                qt5-qtbase-gui \
                qt5-qtserialport \
                qt5-qtbase-sqlite \
                qt5-qtxml
            ;;
        arch)
            echo "Installing dependencies for Arch Linux..."
            sudo pacman -Syu --noconfirm \
                qt5-base \
                qt5-serialport \
                qt5-tools
            ;;
        *)
            echo "Unsupported distribution: $DISTRO"
            echo "Please install the following Qt5 dependencies manually:"
            echo "- Qt5 Core, GUI, Widgets, Network, SQL, SerialPort, PrintSupport, XML"
            read -p "Press Enter to continue without automatic dependency installation..."
            ;;
    esac
}

# Check and create required directories
ensure_directories() {
    mkdir -p "$SCRIPT_DIR/build/DB"
    mkdir -p "$SCRIPT_DIR/build/ICON"
    mkdir -p "$SCRIPT_DIR/build/SETTING"
    mkdir -p "$SCRIPT_DIR/build/LOG"
    # Ensure the log directory is writable
    chmod 755 "$SCRIPT_DIR/build/LOG"
}

# Install dependencies if this is the first run
if [ ! -f "$FIRST_RUN_FLAG" ]; then
    echo "First time setup detected. Checking dependencies..."
    detect_distro
    install_dependencies
    
    # Create flag file to indicate dependencies have been installed
    touch "$FIRST_RUN_FLAG"
    echo "First-time setup complete."
fi

# Define paths relative to the script location
export BUILD_PATH="$SCRIPT_DIR/build/"
# export DB_PATH="$SCRIPT_DIR/build/DB/HISTORY"

# Ensure required directories exist
ensure_directories

# Create/update the .desktop file with current paths
mkdir -p "$HOME/.local/share/applications"
cat > "$HOME/.local/share/applications/ChickChick.desktop" << EOF
[Desktop Entry]
Name=ChickChick
Type=Application
Exec=$SCRIPT_DIR/launch_app.sh
Terminal=false
Icon=$SCRIPT_DIR/build/ICON/ChickChick120.png
Comment=Chicken Solution
NoDisplay=false
Name[en]=ChickChick
EOF

# Make desktop file executable
chmod +x "$HOME/.local/share/applications/ChickChick.desktop"

# Print debug info (optional)
echo "Starting application from: $SCRIPT_DIR"
echo "Desktop file updated at: $HOME/.local/share/applications/ChickChick.desktop"

# Launch the application
if [ -f "$SCRIPT_DIR/build/ChickChick" ]; then
    "$SCRIPT_DIR/build/ChickChick"
else
    echo "Error: ChickChick executable not found at $SCRIPT_DIR/build/ChickChick"
    exit 1
fi
