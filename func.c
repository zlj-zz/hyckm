/*
 * Copyright(C) 2020, Tech. Co.,Ltd.
 *
 * FileName: func.c
 * Author: zachary
 * Date: 2020-05-23
 * Last Modified: 2020-06-07
 * Description: needed function
 */

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "func.h"

void help_info()
{ /*{{{*/
    printf("hyckm %s - (C) 2020 Zachary\n", VERSION);
    printf("\e[1mUsage\e[m: hyckm [command]\n\n");

    printf("    -h  --help      : Show this message\
          \n    -v  --version   : Display version information\
          \n    -r  --revert    : Revert the keyboard mapping\n\n");
} /*}}}*/

void version_info()
{ /*{{{*/
    printf("hyckm version (%s)\n", VERSION);
    printf("  -- To help you change your keyboard mapping.\n\n");
} /*}}}*/

char* join(char* a, char* b)
{ /*{{{*/
    char* c = (char*)malloc(strlen(a) + strlen(b) + 1);
    if (c == NULL)
        exit(1);
    char* tempc = c; //把首地址存下来
    while (*a != '\0') {
        *c++ = *a++;
    }
    while ((*c++ = *b++) != '\0') {
        ;
    }
    //注意，此时指针c已经指向拼接之后的字符串的结尾'\0' !
    return tempc;
    //返回值是局部malloc申请的指针变量，需在函数调用结束后free。
} /*}}}*/

void initial()
{ /*{{{*/
    initscr();
    noecho();
    //curs_set(0);  // hide cursor
    //box(stdscr, '|', '-');
    nodelay(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    keypad(stdscr, TRUE);
    refresh();
} /*}}}*/

int my_mvaddstr(int y, int x, char* str)
{ /*{{{*/
    for (; x < 0; ++x, ++str)
        if (*str == '\0')
            return ERR;
    for (; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)
            return ERR;
    return OK;
} /*}}}*/

int add_head_info()
{ /*{{{*/
    static char* welcome[3]
        = { WEL1, WEL2, WEL3 };

    static char* tips[16]
        = {
              TIP0, TIP1, TIP2, TIP3, TIP4, TIP5,
              TIP6, TIP7, TIP8,
              TIP9, TIP10, TIP11,
              TIP12, TIP13, TIP14, TIP15
          };

    int x = (COLS - 1) / 2, i;

    for (i = 0; i < 3; i++)
        my_mvaddstr(i, x - 13, welcome[i]);
    for (++i; i < 16; ++i)
        my_mvaddstr(i, TIP_IDENT, tips[i]);

    getch();
    refresh();

    return i;
} /*}}}*/

int check_file_if_exists(char* path)
{ /*{{{*/
    if (access(path, R_OK) != 0)
        return 0;
    return 1; // exists
} /*}}}*/

void create_xmodmaprc(char* file_path, int row)
{ /*{{{*/
    system(join(
        join("touch ", file_path),
        join(" && echo \"clear Lock\" >> ", file_path)));

    if (row != -1) {
        my_mvaddstr(row + 1, INTERACTION_IDENT, INTERACTION0);
        getch();
        refresh();
    }
} /*}}}*/

void process_Xmodmaprc(int* row)
{ /*{{{*/
    char* file_path = join(getenv("HOME"), MAPFILE);
    if (check_file_if_exists(file_path) == 1) {
        my_mvaddstr(++(*row), INTERACTION_IDENT, INTERACTION1);
        getch();
        refresh();

        int ch = 0;
        nodelay(stdscr, false);

        do {
            ch = getch();
            addch(ch);
            if (ch == '1') {
                break;
            } else if (ch == '2') {
                system("rm ~/.Xmodmaprc");
                create_xmodmaprc(file_path, -1);
                ++(*row);
                break;
            } else {
                endwin();
                printf("Nothing has been changed.\n");
                exit(1);
            }
        } while (1);
    } else {
        create_xmodmaprc(file_path, ++(*row));
    }
    nodelay(stdscr, true);
} /*}}}*/

void deleteln_of_i(int i, int* row)
{ /*{{{*/
    if (i < 1)
        return;

    deleteln();
    for (int j = 0; j < i - 1; j++) {
        move(--(*row), 0);
        deleteln();
    }
} /*}}}*/

int key_if_valid(char* key)
{ /*{{{*/

    static char KEYBOARD_MAPPING[70][10] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
        "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
        "F1", "F2", "F3", "F4", "F5", "F6",
        "F7", "F8", "F9", "F10", "F11", "F12",
        "~", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
        "`", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
        "Escape", "BackSpace", "Tab", "Caps_Lock", "space",
        "Shift_L", "Shift_R", "Control_L", "Control_R", "Return"
    };

    for (int i = 0; i < 70; i++)
        if (strcmp(key, KEYBOARD_MAPPING[i]) == 0)
            return 1;

    return 0;
} /*}}}*/

void write_keymapping_to_file(char* key1, char* key2)
{ /*{{{*/
    char* script = join(join(join(MAPPINGSCRIPT, key1), " "), key2);
    system(script);
} /*}}}*/

void key_mapping_loop(int* ch, int* row)
{ /*{{{*/
    do {
        nodelay(stdscr, true);
        my_mvaddstr(*row, INTERACTION_IDENT, INTERACTION2);
        getch();
        refresh();

        nodelay(stdscr, false);
        *ch = getch();
        addch(*ch);
        refresh();

        if (!(*ch == 'y' || *ch == 'Y')) {
            break;
        }

        char str1[10], str2[10]; // str1 mapping to str2
        echo();
        do {
            my_mvaddstr(*row, INTERACTION_IDENT, INTERACTION3);
            scanw("%s", str1);
            my_mvaddstr(++(*row), INTERACTION_IDENT, INTERACTION4);
            scanw("%s", str2);

            if (key_if_valid(str1) && key_if_valid(str2)) {
                my_mvaddstr(++(*row), INTERACTION_IDENT, INTERACTION6);
                refresh();
                sleep(1);
                deleteln_of_i(3, row);
                write_keymapping_to_file(str1, str2);
                break;
            } else {
                my_mvaddstr(++(*row), INTERACTION_IDENT, INTERACTION5);
                refresh();
                sleep(2);
                deleteln_of_i(3, row);
            }
        } while (1);
        noecho();

    } while (1);
    nodelay(stdscr, true);
} /*}}}*/

void revert_mapping()
{ /*{{{*/
    system("sh $HOME/.hyckm/src/revert.sh");
} /*}}}*/

void run_mapping()
{/*{{{*/
    initial();
    int row = add_head_info();
    int ch = 0;

    process_Xmodmaprc(&row);
    row += 2;
    key_mapping_loop(&ch, &row);

    my_mvaddstr(row, INTERACTION_IDENT, INTERACTION7);
    getch();
    refresh();
    nodelay(stdscr, false);
    ch = getch();
    addch(ch);
    refresh();
    if (ch == 'y' || ch == 'Y') {
        system(SHELLCOMMAND1);
    }
    deleteln();

    nodelay(stdscr, true);
    my_mvaddstr(row, INTERACTION_IDENT, INTERACTION8);
    getch();
    refresh();
    nodelay(stdscr, false);
    ch = getch();
    addch(ch);
    refresh();
    if (ch == 'y' || ch == 'Y') {
        system(SHELLCOMMAND2);
        endwin();
    } else {
        endwin();
        printf(INTERACTION9);
    }

    printf(OVER);
    exit(0);
}/*}}}*/

