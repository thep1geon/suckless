#!/bin/env bash

title="$(playerctl metadata title)"
artist="$(playerctl metadata artist)"
album="$(playerctl metadata album)"

printf "%.*s  %.*s 󰀥 %.*s" 16 "$title" 16 "$artist" 16 "$album" 
