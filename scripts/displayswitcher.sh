#!/bin/env bash

case "$(echo -e "Laptop\nDual Monitor\nCancel" | dmenu -c -R -p "Display Switcher:")" in
    "Dual Monitor")
        xrandr --output HDMI-2 --auto --rotate normal --left-of eDP-1
        ~/.fehbg
        ;;
	Laptop) 
        xrandr --output HDMI-2 --off
        ~/.fehbg
        ;;
	*) exit 1 ;;
esac
