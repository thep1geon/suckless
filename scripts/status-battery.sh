#!/bin/env bash

if [[ "$1" = "" ]]; then
    echo "n/a"
    exit 1
fi

BATTERY_0="󰂎"
BATTERY_10="󰁺"
BATTERY_20="󰁻"
BATTERY_30="󰁼"
BATTERY_40="󰁽"
BATTERY_50="󰁾"
BATTERY_60="󰁿"
BATTERY_70="󰂀"
BATTERY_80="󰂁"
BATTERY_90="󰂂"
BATTERY_100="󰁹"
BATTERY_CHARGING="󰂄"

battery_from_perc() {
    p=$(("$1" / 10 * 10))
    case $p in
        0)
            echo "$BATTERY_0" ;;
        10)
            echo "$BATTERY_10" ;;
        20)
            echo "$BATTERY_20" ;;
        30)
            echo "$BATTERY_30" ;;
        40)
            echo "$BATTERY_40" ;;
        50)
            echo "$BATTERY_50" ;;
        60)
            echo "$BATTERY_60" ;;
        70)
            echo "$BATTERY_70" ;;
        80)
            echo "$BATTERY_80" ;;
        90)
            echo "$BATTERY_90" ;;
        100)
            echo "$BATTERY_100" ;;
    esac
}

bat=""

perc="$(cat /sys/class/power_supply/"$1"/capacity)"
state="$(cat /sys/class/power_supply/"$1"/status)"

if [[ "$state" = "Charging" ]]; then
    bat="$BATTERY_CHARGING"
else
    bat="$(battery_from_perc "$perc")"
fi

printf "%s %s" "$bat" "$perc%"
