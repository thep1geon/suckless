#!/usr/bin/env bash

case "$(echo -e "kill\nlock\nsuspend\nreboot\nshutdown" | dmenu -l 0 -p "System Menu:")" in
	kill) ps -u $USER -o pid,comm,%cpu,%mem | dmenu -c -l 15 -p Kill: | awk '{print $1}' | xargs -r kill ;;
    lock) slock ;;
	suspend) slock systemctl suspend -i ;;
	reboot) systemctl reboot -i ;;
	shutdown) shutdown now ;;
	*) exit 1 ;;
esac
