#!/bin/env bash

wallpaper=$(sxiv ~/Pictures -t -o)

feh --bg-fill $wallpaper

notify-send -i $wallpaper "Wallpaper changed"

# Nothing was selected
# if [[ $wallpaper = "" ]]; then
#     exit 1
# fi
#
# wal --cols16 -i $wallpaper
#
# pywal-discord -t abou
#
# ln -sf ~/.cache/wal/colors-dunstrc ~/.config/dunst/dunstrc && pkill dunst
#
# sudo_password=$(dmenu -P <&-)
# # No password was given
# if [[ $wallpaper = "" ]]; then
#     exit 1
# fi
#
# cd ~/suckless/dwm
# rm -f config.h
# echo $sudo_password | sudo -S make -j 16 clean install
# cd -
#
# cd ~/suckless/st
# rm -f config.h
# echo $sudo_password | sudo -S make -j 16 clean install
# cd -
#
# cd ~/suckless/dmenu
# rm -f config.h
# echo $sudo_password | sudo -S make -j 16 clean install
# cd -
#
# cd ~/suckless/slstatus
# rm -f config.h
# echo $sudo_password | sudo -S make -j 16 clean install
# cd -
#
# notify-send -i $wallpaper "Wallpaper changed" "Restart DWM to update the colors"

exit 0
