#!/usr/bin/env bash

case $1 in
    up)
        light -A 5
        notify-send "Brightness" --hint=int:value:$(light) -i ~/.icons/48x48/status/notification-display-brightness.svg
        ;;
    down)
        light -U 5
        notify-send "Brightness" --hint=int:value:$(light) -i ~/.icons/48x48/status/notification-display-brightness.svg
        ;;
    *)
        exit 1 ;;
esac

exit 0
