#!/bin/bash

function powermenu {
    options="Cancel\nLock\nSuspend\nReboot\nShutdown" 
    selected=$(echo -e $options | dmenu -i)
    if [[ $selected = "Cancel" ]]; then
        return
    elif [[ $selected = "Lock" ]]; then
        slock
    elif [[ $selected = "Suspend" ]]; then
        systemctl suspend
    elif [[ $selected = "Reboot" ]]; then
        reboot
    elif [[ $selected = "Shutdown" ]]; then
        poweroff
    fi
}

powermenu
