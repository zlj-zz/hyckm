#!/bin/env bash

# File Name: change_key.sh
# Description: the script write keyboard mapping to file
# Author: zachary
# Created Time: 2020-06-05
# Last Modified: 2020-06-07

hyckm_path=$HOME/.hyckm
. $hyckm_path/src/keyboardmapping.sh

map_path=$HOME/.Xmodmaprc

function changekey() {
  #read -p "input them :" formkey tokey
  formkey=$1
  tokey=$2
  if [[ ${dic[$formkey]} && ${dic[$tokey]} ]]; then
    keycode=${dic[$tokey]}
    if [[ $keycode =~ 1[0-9]$ || $keycode == 49 ]]; then
      echo "keycode ${dic[$formkey]}=${key2string[$keycode]}" >> $map_path
      #echo -e "--------------------------------ok\n"
      #Proceess
    else
      echo "keycode ${dic[$formkey]}=$tokey" >> $map_path
      #echo -e "--------------------------------ok\n"
      #Proceess
    fi
  #else
    #echo -e "Don't input unsupports keys ! \n"
  fi
}

changekey $1 $2
