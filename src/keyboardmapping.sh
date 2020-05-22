#!/bin/env bash

#########################################################################
# File Name: boardkeymapping.sh
# Author: zachary
# Description: keyboard mapping
#########################################################################

declare -A dic
dic=(
  [\`]=49 [\~]=49
  [Escape]=9 [BackSpace]=22
  [F1]=67 [F2]=68 [F3]=69 [F4]=70 [F5]=71 [F6]=72
  [F7]=73 [F8]=74 [F9]=75 [F10]=76 [F11]=95 [F12]=96
  [1]=10 [2]=11 [3]=12 [4]=13 [5]=14 [6]=15 [7]=16 [8]=17 [9]=18 [0]=19
  [\!]=10 [\@]=11 [\#]=12 [\$]=13 [\%]=14 [\^]=15 [\&]=16 [\*]=17 [\(]=18 [\)]=19
  [q]=24 [w]=25 [e]=26 [r]=27 [t]=28
  [y]=29 [u]=30 [i]=31 [o]=32 [p]=33
  [a]=38 [s]=39 [d]=40 [f]=41 [g]=42
  [h]=43 [j]=44 [k]=45 [l]=46
  [z]=52 [x]=53 [c]=54 [v]=55 [b]=56
  [n]=57 [m]=58
  [Tab]=23
  [Caps_Lock]=66
  [Shift_L]=50 [Shift_R]=62
  [Control_L]=37 [Control_R]=105
  [Alt_L]=64 [Alt_R]=108
  [space]=65
  [Super_L]=133 [Return]=36
  )

declare -A key2string
key2string=(
  [10]="1 exclam 1 exclam exclamdown onesuperior exclamdown"
  [11]="2 at 2 at masculine twosuperior masculine"
  [12]="3 numbersign 3 numbersign ordfeminine threesuperior ordfeminine"
  [13]="4 dollar 4 dollar cent sterling cent"
  [14]="5 percent 5 percent EuroSign yen EuroSign"
  [15]="6 asciicircum 6 asciicircum hstroke Hstroke hstroke"
  [16]="7 ampersand 7 ampersand eth ETH eth"
  [17]="8 asterisk 8 asterisk thorn THORN thorn"
  [18]="9 parenleft 9 parenleft leftsinglequotemark leftdoublequotemark leftsinglequotemark"
  [19]="0 parenright 0 parenright rightsinglequotemark rightdoublequotemark rightsinglequotemark"
  [49]="grave asciitilde grave asciitilde dead_tilde asciitilde dead_tilde"
  )

#echo ${dic[*]}
#echo ${!dic[*]}
#echo ${dic[2]}
