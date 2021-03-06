#!/bin/env bash

# File Name: ckm.sh
# Author: zachary
# Description: function


# create '.Xmodmaprc' file{{{
function create_xmodmaprc() {
  touch $map_path && echo "clear Lock" >> $map_path
}
#}}}

# output change to '.Xmodmaprc'{{{
function changekey() {
  read -p "input them :" formkey tokey
  if [[ ${dic[$formkey]} && ${dic[$tokey]} ]]; then
    keycode=${dic[$tokey]}
    if [[ $keycode =~ 1[0-9]$ || $keycode == 49 ]]; then
      echo "keycode ${dic[$formkey]}=${key2string[$keycode]}" >> $map_path
      #echo -e "--------------------------------ok\n"
      Proceess
    else
      echo "keycode ${dic[$formkey]}=$tokey" >> $map_path
      #echo -e "--------------------------------ok\n"
      Proceess
    fi
  else
    echo -e "Don't input unsupports keys ! \n"
  fi
}
#}}}

# run function{{{
function start_() {
  # '.Xmodmaprc' file process
  if [[ -e $map_path ]]; then
    read -p "The '$map_path' exists (1:append 2:recreate):" sel
    if [[ "$sel" == "2" ]]; then
      rm $map_path
      create_xmodmaprc
    elif [[ "$sel" == "1" ]]; then
      echo
    else
      exit 1
    fi
  else
    create_xmodmaprc
    echo -e "create file '$map_path' \n"
  fi

  # key change cycle
  while true; do
    echo ; read -p "If change key ? (y/n):" flag
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
#}}}

# proceess{{{
function Proceess(){
spa=''
i=0
while [ $i -le 100 ]; do
 printf "[%-50s] %d%% \r" "$spa" "$i";
 sleep 0.005
 ((i=i+2))
 spa+='>'
done
echo
}
#}}}
