#!/usr/bin/env bash

case "$(printf "kill\nlock\nsuspend\nreboot\nshutdown" | dmenu -i -c -l 4)" in
	kill) ps -u $USER -o pid,comm,%cpu,%mem | dmenu -i -c -l 10 -p Kill: | awk '{print $1}' | xargs -r kill ;;
    lock) slock ;;
	suspend) slock systemctl suspend -i ;;
	reboot) systemctl reboot -i ;;
	shutdown) shutdown now ;;
	*) exit 1 ;;
esac
