#!/bin/env bash

# File Name: revert.sh
# Description: revert keyboard mapping
# Author: zachary
# Created Time: 2020-05-24
# Last Modified: 

hyckm_path=$HOME/.hyckm
. $hyckm_path/src/keyboardmapping.sh

revert_() {
  temp=./.Xmodmap-temp

  if [[ -e $temp ]]; then rm $temp; fi
  touch $temp
  echo "clear Lock" >> $temp

  for idx in "${!dic[@]}"; do
    keycode=${dic[$idx]}
    if [[ $keycode =~ 1[0-9]$ || $keycode == 49 ]]; then
      echo -e "keycode $keycode=${key2string[$keycode]}" >> $temp
    else
      echo -e "keycode $keycode=$idx" >> $temp
    fi
  done

  xmodmap $temp && rm $temp
  echo "revert finished !"
}

revert_
