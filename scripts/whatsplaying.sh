#!/bin/env bash

title="$(playerctl metadata title)"
artist="$(playerctl metadata artist)"
album="$(playerctl metadata album)"

notify-send "󰝚 $title  $artist 󰀥 $album"
