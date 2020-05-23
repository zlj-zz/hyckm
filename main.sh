#!/bin/env bash

# File Name: main.sh
# Created Time: 2020-05-21
# Author: zachary
# Last Modified: 2020-05-22 23:29:51
# Description: change your keyboard mapping


#hyckm_path=$PWD
hyckm_path=$HOME/.hyckm
. $hyckm_path/src/keyboardmapping.sh
. $hyckm_path/src/text.sh
. $hyckm_path/src/func.sh

version=0.1
#map_path=./.Xmodmaprc
map_path=$HOME/.Xmodmaprc

if [[ "$#" == 0 ]]; then
  check_
  #clear
  info_; start_
  #sleep 1
  #clear
else
  for opt in "$@"; do
    case $opt in
      -h|--help)
        help_
        ;;
      -v|--version)
        echo "hyckm version $version"
        exit 0
        ;;
      -r|--revert)
        revert_
        exit 0
        ;;
      *)
        echo "error parameter !"
        exit 1
        ;;
    esac
  done
fi
