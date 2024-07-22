#!/bin/bash

# Inspired by https://askubuntu.com/a/1491373

# Script that auto switches Ubuntu themes to Dark or Light, 
# depending on the time of day

# Copy this script file to /usr/local/bin/switch-theme.sh
# Add following lines to crontab -e
# 0 10 * * * bash /usr/bin/local/switch-theme.sh light
# 0 19 * * * bash /usr/bin/local/switch-theme.sh dark
# @reboot bash /usr/bin/local/switch-theme.sh

set_theme() {
	# Check if the log file and directory exists
	if [ ! -d ~/Scripts ]; then
		mkdir ~/Scripts
	fi
	if [ ! -f ~/Scripts/switch-theme.log ]; then
		touch ~/Scripts/switch-theme.log
	fi

    echo `date` Starting script execution - setting theme $1 >> ~/Scripts/switch-theme.log
    if [[ "$1" == "dark" ]]; then
        new_gtk_theme="Yaru-orange-dark"
        # Some apps also need color scheme
        new_color_scheme="prefer-dark"
        new_icon_theme="Yaru-orange-dark"
    elif [[ "$1" == "light" ]]; then
        new_gtk_theme="Yaru-orange"
        new_color_scheme="prefer-light"
        new_icon_theme="Yaru-orange"
    else
        echo "[!] Unsupported theme: $1"
        return
    fi

    current_gtk_theme=$(gsettings get org.gnome.desktop.interface gtk-theme)
    current_color_scheme=$(gsettings get org.gnome.desktop.interface color-scheme)
    if [[ "${current_gtk_theme}" == "'${new_gtk_theme}'" ]]; then
        echo "`date` [i] Already using gtk '${new_gtk_theme}' theme" >> ~/Scripts/switch-theme.log
    else
        echo "`date` [-] Setting gtk theme to ${new_gtk_theme}" >> ~/Scripts/switch-theme.log
        gsettings set org.gnome.desktop.interface gtk-theme "${new_gtk_theme}"
        gsettings set org.gnome.desktop.interface color-scheme "${new_color_scheme}"
        gsettings set org.gnome.desktop.interface icon-theme "${new_icon_theme}"
        echo "`date` [✓] gtk theme changed to ${new_gtk_theme}" >> ~/Scripts/switch-theme.log
    fi
}

# If script run without argument
if [[ -z "$1" ]]; then
    currenttime=$(date +%H:%M)
    if [[ "$currenttime" > "19:00" || "$currenttime" < "10:00" ]]; then
        set_theme dark
    else
        set_theme light
    fi
else
    set_theme $1
fi