#!/usr/bin/env bash

function get_vol {
    pactl get-sink-volume @DEFAULT_SINK@ | \
        awk '{ print $5 }' | \
        head -1 | \
        sed 's/^\(.*\)%.*$/\1/'
}

function get_mute {
    pactl get-sink-mute @DEFAULT_SINK@ | \
        awk '{ print $2 }'
}

case "$1" in
    up)
        pactl set-sink-volume @DEFAULT_SINK@ +5%
        notify-send --hint=int:value:$(get_vol) "Volume" -i ~/.icons/48x48/status/notification-audio-volume-high.svg
        ;;
    down) 
        pactl set-sink-volume @DEFAULT_SINK@ -5%
        notify-send --hint=int:value:$(get_vol) "Volume" -i ~/.icons/48x48/status/notification-audio-volume-high.svg
        ;;
    mute)
        pactl set-sink-mute @DEFAULT_SINK@ toggle
        case "$(get_mute)" in
            yes)
                notify-send "Volume" "muted" -i ~/.icons/48x48/status/notification-audio-volume-muted.svg
                ;;
            no)
                notify-send "Volume" "unmuted" -i ~/.icons/48x48/status/notification-audio-volume-high.svg
                ;;
            *) exit 2 ;;
        esac
        ;;
	*) exit 1 ;;
esac

exit 0
