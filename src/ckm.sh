#!/bin/env bash

#########################################################################
# File Name: ckm.sh
# Author: zachary
# Description: function
#########################################################################

function create_xmodmaprc() {
  touch $map_path
  echo "clear Lock" >> $map_path
}

function changekey() {
  read -p "input them :" formkey tokey
  if [[ ${dic[$formkey]} && ${dic[$tokey]} ]]; then
    echo "keycode ${dic[$formkey]}=$tokey" >> $map_path
    echo -e "--------------------------------ok\n"
  else
    echo -e "Don't input unsupports keys ! \n"
  fi
}

function start_() {
  if [[ -e $map_path ]]; then
    read -p "The '$map_path' exists (1:append 2:recreate):" sel
    if [[ "$sel" == "2" ]]; then
      rm $map_path
      create_xmodmaprc
    elif [[ "$sel" == "1" ]]; then
      create_xmodmaprc
    else
      exit 1
    fi
  else
    create_xmodmaprc
    echo -e "create file '$map_path' \n"
  fi

  while true; do
    read -p "Change key ? (y/n):" flag
    if [[ "$flag" == "n" ]]; then
      break
    fi
    changekey
  done
  echo -e "-------------------------end input \n"

  # add to .bash_profile
  read -p "Do you want to add it to system startup ? (y/n):" confirm
  if [[ "$confirm" == "n" ]]; then
    echo
  else
    echo "if [[ -e $map_path ]];then xmodmap $map_path; fi" >> ~/.bash_profile
    echo -e "successful ! \n"
  fi

  # execute file
  read -p "Do you want to change the keys immediately ? (y/n):" confirm
  if [[ "$confirm" == "n" ]]; then
    echo -e "\nyou can type 'xmodmap $map_path' to take effect your changes."
  else
    xmodmap $map_path
    echo "change key map successful !"
  fi
}

check_() {
  if [[ ! -e /usr/bin/xmodmap ]]; then
    echo "error: don't find 'xmodmap'."
    exit 1
    #sudo pacman -S xorg-xmodmap
  fi
}
