#!/bin/env bash

for dir in ./* ; do
    if [[ "$dir" == "./install.sh" ]]; then
        continue
    fi

    cd "$dir"
    sudo rm config.h
    sudo make clean install
    cd ..
done
