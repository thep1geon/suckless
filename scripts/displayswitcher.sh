#!/bin/env bash

case "$(printf "Laptop\nDual Monitor\nCancel" | dmenu -l 3)" in
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
