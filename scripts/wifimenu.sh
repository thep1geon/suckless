#!/bin/env bash

# Working with nmcli

function get_password_dmenu {
    dmenu -c -P -p Password: -W 400 -l 0 <&-
}

function get_wifi_options {
    known=$(nmcli -t -f NAME connection show)
    visible=$(nmcli -t -f SSID device wifi list | awk -F: '
    $1 != "" { ssid=$1; if (!seen[ssid]++) print ssid }
    ')
    echo -e "$visible\n$known" | sort -u | dmenu -c -p "Select Network:"
}

function attempt_to_connect {
    if [[ "$2" -eq 3 ]]; then
        notify-send "Failed to connect to $1 too many times"
        exit 1
    fi

    password=$(get_password_dmenu)
    [ -z "$password" ] && exit 1
    if ! nmcli device wifi connect "$1" password "$password" ; then
        notify-send "Failed to connect to $1"
        attempt_to_connect "$1" $(("$2" + 1))
    else
        notify-send "Connected to $1"
    fi
}

case "$(echo -e "Connect\nDisconnect\nSee Connection" | dmenu -c -R -p "Network Menu:")" in
    Connect)
        selection=$(get_wifi_options)
        ssid=$(echo "$selection" | sed 's/ \[.*//')
        [ -z "$ssid" ] && exit 1

        if nmcli -t -f NAME connection show | grep -Fxq "$ssid"; then
            nmcli connection up "$ssid" && notify-send "Connected to $ssid"
        else
            attempt_to_connect "$ssid" 0
        fi
        ;;
    Disconnect)
        device=$(nmcli device | sed -n '2p' | cut -d ' ' -f 1)
        nmcli device disconnect $device
        notify-send "Disconnected from: $device"
        ;;
    "See Connection")
        notify-send "Current Connection: $(nmcli -t -f NAME connection show --active | head -1)"
        ;;
	*) 
        exit 1
        ;;
esac

exit 0;
