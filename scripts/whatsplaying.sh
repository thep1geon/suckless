#!/bin/env bash

player=""

while IFS= read -r p; do
    if [[ "$(playerctl --player=$p status)" = "Playing" ]]; then
        player=$p
    fi
done <<< "$(playerctl -l)"

title="$(playerctl metadata title --player=$player)"
artist="$(playerctl metadata artist --player=$player)"
album="$(playerctl metadata album --player=$player)"

notify-send "󰝚 $title" " $artist\n\n󰀥 $album"
