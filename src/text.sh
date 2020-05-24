#!/bin/env bash

# File Name: text.sh
# Author: zachary
# Description: some hints


function info_() {
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
  echo "   | ← Backspace | : BackSpace"
  echo "   ---------------"
  echo
}

