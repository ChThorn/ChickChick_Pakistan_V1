#!/bin/bash

# Get the absolute path of the script location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
FIRST_RUN_FLAG="$SCRIPT_DIR/.dependencies_installed"
EXECUTABLE="$SCRIPT_DIR/build/ChickChick"

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

# Function to check required dependencies
check_dependencies() {
    echo "Checking executable dependencies..."
    
    if [ ! -f "$EXECUTABLE" ]; then
        echo "Error: Executable not found at $EXECUTABLE"
        return 1
    fi
    
    # Use ldd to identify missing dependencies
    MISSING_LIBS=$(ldd "$EXECUTABLE" 2>/dev/null | grep "not found")
    
    if [ -z "$MISSING_LIBS" ]; then
        echo "All required libraries are present."
        return 0
    else
        echo "Missing libraries detected:"
        echo "$MISSING_LIBS"
        
        # Check specifically for Qt libraries
        if echo "$MISSING_LIBS" | grep -q "libQt"; then
            echo "Missing Qt libraries detected. Will install Qt dependencies."
            return 1
        fi
        
        return 1
    fi
}

# Function to install dependencies based on the distribution
install_dependencies() {
    echo "Installing Qt5 dependencies..."
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
            echo "Continuing without automatic dependency installation..."
            ;;
    esac
}

# Check and create required directories
ensure_directories() {
    echo "Ensuring required directories exist..."
    mkdir -p "$SCRIPT_DIR/build/DB"
    mkdir -p "$SCRIPT_DIR/build/ICON"
    mkdir -p "$SCRIPT_DIR/build/SETTING"
    mkdir -p "$SCRIPT_DIR/build/LOG"
    # Ensure the log directory is writable
    chmod 755 "$SCRIPT_DIR/build/LOG"
}

# Main setup process
if [ ! -f "$FIRST_RUN_FLAG" ]; then
    echo "First time setup detected."
    detect_distro
    
    # Only install if dependencies are missing
    if ! check_dependencies; then
        install_dependencies
        
        # Verify dependencies were installed correctly
        if ! check_dependencies; then
            echo "Warning: Some dependencies may still be missing after installation."
            echo "The application might not run correctly."
        fi
    fi
    
    # Create flag file to indicate setup has been attempted
    touch "$FIRST_RUN_FLAG"
    echo "First-time setup complete."
fi

# Define paths relative to the script location
export BUILD_PATH="$SCRIPT_DIR/build/"

# Ensure required directories exist
ensure_directories

# Create/update the .desktop file with current paths
echo "Creating desktop shortcut..."
mkdir -p "$HOME/.local/share/applications"
cat > "$HOME/.local/share/applications/ChickChick.desktop" << EOF
[Desktop Entry]
Name=ChickChick
Type=Application
Exec=$SCRIPT_DIR/launch_app.sh
Terminal=false
Icon=$SCRIPT_DIR/build/ICON/STS.png
Comment=Chicken Solution
NoDisplay=false
Categories=Utility;
Name[en]=ChickChick
EOF

# Make desktop file executable
chmod +x "$HOME/.local/share/applications/ChickChick.desktop"

# Print debug info
echo "Starting application from: $SCRIPT_DIR"
echo "Desktop file updated at: $HOME/.local/share/applications/ChickChick.desktop"

# Launch the application
if [ -x "$EXECUTABLE" ]; then
    echo "Launching ChickChick..."
    "$EXECUTABLE"
else
    echo "Error: ChickChick executable not found or not executable at $EXECUTABLE"
    echo "Please check if the executable exists and has proper permissions."
    exit 1
fi
