#!/usr/bin/env bash

case "$(echo -e "kill\nlock\nsuspend\nreboot\nshutdown" | dmenu -c -R -p "System Menu:")" in
	kill) ps -u $USER -o pid,comm,%cpu,%mem | dmenu -c -R -l 10 -p Kill: | awk '{print $1}' | xargs -r kill ;;
    lock) slock ;;
	suspend) slock systemctl suspend -i ;;
	reboot) systemctl reboot -i ;;
	shutdown) shutdown now ;;
	*) exit 1 ;;
esac
