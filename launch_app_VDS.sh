#!/bin/bash

# Exit on critical errors
set -euo pipefail

# Get the absolute path of the script location
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
FIRST_RUN_FLAG="$SCRIPT_DIR/.dependencies_installed"
EXECUTABLE="$SCRIPT_DIR/build/ChickChick"
ICON_PATH="$SCRIPT_DIR/build/ICON/STS.png"

# ----------------------
# Early Validation Checks
# ----------------------
if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: ChickChick executable not found at $EXECUTABLE"
    exit 1
fi

# ----------------------
# Enhanced Dependency Check
# ----------------------
check_dependencies() {
    echo "Checking system dependencies..."
    
    # Get all missing libraries (system-wide check)
    MISSING_LIBS=$(ldd "$EXECUTABLE" 2>/dev/null | grep "not found" | cut -d' ' -f1 | sort -u)
    
    # Check specifically for missing Qt libraries
    MISSING_QT_LIBS=$(echo "$MISSING_LIBS" | grep -iE "libQt|Qt5")
    
    if [ -n "$MISSING_LIBS" ]; then
        echo "Missing dependencies detected:"
        echo "$MISSING_LIBS"
        [ -n "$MISSING_QT_LIBS" ] && echo "Qt-related missing libraries: $MISSING_QT_LIBS"
        return 1
    fi
    
    echo "All required libraries are present."
    return 0
}

# ----------------------
# Installation Improvements
# ----------------------
install_dependencies() {
    case $DISTRO in
        ubuntu|debian)
            echo "Installing Qt5 and SQLite for Debian/Ubuntu..."
            sudo apt-get install -y \
                libqt5core5a libqt5gui5 libqt5widgets5 \
                libqt5network5 libqt5sql5 libqt5sql5-sqlite \
                libqt5serialport5 libqt5printsupport5 libqt5xml5 \
                libsqlite3-0
            ;;
        fedora|centos|rhel)
            echo "Installing Qt5 for Fedora/CentOS..."
            sudo dnf install -y \
                qt5-qtbase qt5-qtbase-gui qt5-qtserialport \
                qt5-qtbase-sqlite qt5-qtxml sqlite
            ;;
        arch)
            echo "Installing Qt5 for Arch..."
            sudo pacman -Syu --noconfirm \
                qt5-base qt5-serialport qt5-tools sqlite
            ;;
        *)
            echo "Unsupported distribution: $DISTRO"
            return 1
            ;;
    esac
}

# ----------------------
# Main Execution Flow
# ----------------------
if [ ! -f "$FIRST_RUN_FLAG" ]; then
    detect_distro
    if ! check_dependencies; then
        install_dependencies || {
            echo "Warning: Some dependencies might still be missing"
            echo "Application may run with limited functionality"
        }
        touch "$FIRST_RUN_FLAG"
    fi
fi

# Final check (non-critical)
if ! check_dependencies; then
    echo "Warning: Some dependencies are missing, but attempting to start anyway..."
fi

# Desktop shortcut creation
echo "Creating desktop shortcut..."
SHORTCUT_PATH="$HOME/.local/share/applications/ChickChick.desktop"
ICON_LINE="Icon=$ICON_PATH"
[ ! -f "$ICON_PATH" ] && {
    echo "Warning: Icon file missing at $ICON_PATH"
    ICON_LINE="#Icon=application-default-icon"
}

mkdir -p "$(dirname "$SHORTCUT_PATH")"
cat > "$SHORTCUT_PATH" << EOF
[Desktop Entry]
Name=ChickChick
Exec=$SCRIPT_DIR/launch_app_VDS.sh
Terminal=false
$ICON_LINE
Type=Application
Comment=Chicken Solution
Categories=Utility;
EOF

chmod +x "$SHORTCUT_PATH"

# Launch application
echo "Launching application..."
export BUILD_PATH="$SCRIPT_DIR/build/"
"$EXECUTABLE"