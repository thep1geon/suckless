#!/bin/env bash

case "$(echo -e "1\n2\nCancel" | dmenu -l 0 -p "Display Count:")" in
	"1") 
        xrandr --output HDMI-2 --off
        ~/.fehbg
        ;;
    "2")
        xrandr --output HDMI-2 --auto --rotate normal --left-of eDP-1
        ~/.fehbg
        ;;
	*) exit 1 ;;
esac
