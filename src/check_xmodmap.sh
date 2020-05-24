#!/bin/env bash

# File Name: check_xmodmap.sh
# Description: check if install 'xmodmap'
# Author: zachary
# Created Time: 2020-05-23
# Last Modified:


if [[ -e /usr/bin/xmodmap ]]; then
  echo "error: don't find 'xmodmap'."
  exit 1
  #sudo pacman -S xorg-xmodmap
fi
