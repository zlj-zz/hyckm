#!/bin/env bash

#########################################################################
# File Name: main.sh
# Created Time: 2020-05-21
# Author: zachary
# Last Modified: 2020-05-21 23:13:38
# Description: change your keyboard map
#########################################################################

declare -A dic
dic=(
  ['`']=49
  [Escape]=9 [Backspace]=22
  [F1]=67 [F2]=68 [F3]=69 [F4]=70 [F5]=71 [F6]=72
  [F7]=73 [F8]=74 [F9]=75 [F10]=76 [F11]=95 [F12]=96
  [1]=10 [2]=11 [3]=12 [4]=13 [5]=14 [6]=15 [7]=16 [8]=17 [9]=18 [0]=19
  [q]=24 [w]=25 [e]=26 [r]=27 [t]=28
  [y]=29 [u]=30 [i]=31 [o]=32 [p]=33
  [a]=38 [s]=39 [d]=40 [f]=41 [g]=42
  [h]=43 [j]=44 [k]=45 [l]=46
  [z]=52 [x]=53 [c]=54 [v]=55 [b]=56
  [n]=57 [m]=58 
  [Tab]=23
  [Caps_Lock]=9
  [Shift_L]=50 [Shift_R]=62
  [Control_L]=37 [Control_R]=105
  [Alt_L]=64 [Alt_R]=108
  [space]=65
  [Super_L]=133 [Return]=36
)

#echo ${dic[*]}
#echo ${!dic[*]}
#echo ${dic[2]}

map_path=./.Xmodmaprc
#map_path=$HOME/.Xmodmaprc
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
function info() {
  echo "       =================="
  echo "       = WELCOME to USE ="
  echo "       =================="

  echo -e "\nWhat keymap you want to change ? If want to map 'Escape' to 'Caps_Lock', like (Escape Caps_Lock)."
  echo -e "Support a-z(lower case) 0-9 F1-F12\n"

  echo "Some keys you should input such names, there are:"
  echo "   -------            -------------               ----------- "
  echo "   | ESC | : Escape   | Cpas Lock | : Caps_Lock   | Shift ↑ | : Shift_L  Shift_R"
  echo "   -------            -------------               ----------- "
  echo "   --------                          -------"
  echo "   | Ctrl | : Control_L  Control_R   | Alt | : Alt_L  Alt_R"
  echo "   --------                          -------"
  echo "   -----------            ---------"
  echo "   | Enter ⏎ | : Return   | Win ◆ | : Super_L"
  echo "   -----------            ---------"
  echo "   ---------------"
  echo "   | ← Backspace | : Backspace"
  echo "   ---------------"
  echo
}

# ------------------------------------------------------------

clear
info

if [[ -e $map_path ]]; then
  read -p "The '$map_path' exists (1:append 2:recreate):" sel
  if [[ "$sel" == "2" ]]; then
    rm $map_path
    create_xmodmaprc
  elif [[ "$sel" == "1" ]]; then
    create_xmodmaprc
  else
    exit
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
  echo "you can type 'xmodmap $map_path' to take effect your changes."
else
  xmodmap $map_path
  echo "change key map successful !"
fi
#sleep 1
#clear

