#!/bin/env bash


player=""

while IFS= read -r p; do
    if [[ "$(playerctl --player=$p status)" = "Playing" ]]; then
        player=$p
    fi
done <<< "$(playerctl -l)"

title="$(playerctl metadata title --player=$player)"
artist="$(playerctl metadata artist --player=$player)"

printf "%.*s  %.*s" 16 "$title" 16 "$artist"
