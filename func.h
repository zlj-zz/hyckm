/*
 * Copyright(C) 2020, Tech. Co.,Ltd.
 * FileName: func.h
 * Author: zachary
 *
 * Date: 2020-05-24
 * Last Modified: 2020-06-06
 * Description: function all here.
 */

#ifndef _FUNC_H
#define _FUNC_H

void help_info();    // print help infomation
void version_info(); // print version infomation
int my_mvaddstr(int y, int x, char* str);
int add_head_info();
int check_file_if_exists(char* path); // check file
void create_xmodmaprc(char* file_path, int row);
void process_Xmodmaprc(int* row);
void deleteln_of_i(int i, int* row);
int key_if_valid(char* key);
void write_keymapping_to_file(char* key1, char* key2);
void key_mapping_loop(int* ch, int* row);
void revert_mapping(); // revert the keyboard mapping
void run_mapping();

#endif

#define WEL1 "============================"
#define WEL2 "= Welcome to use the HYCKM ="
#define WEL3 "============================"

#define TIP_IDENT 5
#define TIP0    "   "
#define TIP1    "What keymap you want to change ?"
#define TIP2    "If want to map 'Escape' to 'Caps_Lock', like (Escape Caps_Lock)."
#define TIP3    "Support a-z(please input lower case) 0-9 F1-F12."
#define TIP4    "   "
#define TIP5    "Some keys you should input such names, there are:"
#define TIP6    "-------            -------------               -----------              "
#define TIP7    "| ESC | : Escape   | Cpas Lock | : Caps_Lock   | Shift ^ | : Shift_(L/R)"
#define TIP8    "-------            -------------               -----------              "
#define TIP9    "--------                   -------               ---------          "
#define TIP10   "| Ctrl | : Control_(L/R)   | Alt | : Alt_(L/R)   | Win * | : Super_L"
#define TIP11   "--------                   -------               ---------          "
#define TIP12   "---------            ----------------            "
#define TIP13   "| Enter | : Return   | <- Backspace | : BackSpace"
#define TIP14   "---------            ----------------            "
#define TIP15   "   "

#define INTERACTION_IDENT 5
#define INTERACTION0 "Created file '~/.Xmodmaprc' "
#define INTERACTION1 "The '~/.Xmodmaprc' exists (1:append 2:recreate other:quit):"
#define INTERACTION2 "If change key ? (y/n):"
#define INTERACTION3 "Please input (2 keys), the from key:"
#define INTERACTION4 ";the to key:"
#define INTERACTION5 "Some keys is invalid ! 1 second later, try again."
#define INTERACTION6 "OK, no problem."
#define INTERACTION7 "Do you want to add it to system startup ? (y/n):"
#define INTERACTION8 "Do you want to change the keys immediately ? (y/n):"
#define INTERACTION9 "you can type 'xmodmap ~/.Xmodmaprc' to take effect your changes.\n"

#define OVER "Mapping Over.\n"

#define SHELLCOMMAND1 "echo \"if [[ -e ~/.Xmodmaprc ]];then xmodmap ~/.Xmodmaprc; fi\" >> ~/.bash_profile"
#define SHELLCOMMAND2 "xmodmap ~/.Xmodmaprc"

