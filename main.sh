#!/bin/env bash

#########################################################################
# File Name: main.sh
# Created Time: 2020-05-21
# Author: zachary
# Last Modified: 2020-05-22 11:14:48
# Description: change your keyboard mapping
#########################################################################

. ./src/keyboardmapping.sh
. ./src/text.sh
. ./src/ckm.sh

version=0.1
#map_path=./.Xmodmaprc
map_path=$HOME/.Xmodmaprc

if [[ "$#" == 0 ]]; then
  clear
  # print tips
  info_
  # start run
  start_

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
      *)
        echo "error parameter !"
        exit 1
        ;;
    esac
  done
fi
