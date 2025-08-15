#!/bin/env bash


case "$(echo -e "Monitor\nWindow\nSelect" | dmenu -l 0 -p "Screenshot Menu:")" in
    Monitor)
        kill -SIGUSR1 $(pidof dwm)
        mon=$(cat ~/suckless/dwm/mon)
        sleep 1
        scrot -M $mon -z -F /home/magic/Pictures/Screenshots/%b-%d-%Y-%H:%M.png \
            -e 'notify-send -i $f "Screenshot taken" "Saved at $f"'
        ;;
    Window)
        sleep 1
        scrot 10 -u -z -F /home/magic/Pictures/Screenshots/%b-%d-%Y-%H:%M.png \
            -e 'notify-send -i $f "Screenshot taken" "Saved at $f"'
        ;;
    Select)
        sleep 1
        scrot -s -f -z -F /home/magic/Pictures/Screenshots/%b-%d-%Y-%H:%M.png \
            -e 'notify-send -i $f "Screenshot taken" "Saved at $f"'
        ;;
	*) 
        exit 1
        ;;
esac

exit 0;
