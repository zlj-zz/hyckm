/*
Copyright(C) 1997-2020, Tech. Co.,Ltd.
FileName: func.c
Author: zachary
Date: 2020-05-23 14:19:48
Last Modified: 
Description: function
 */


void check_xmodmap(){
  char* path = "/usr/bin/xmodmap";
  FILE* fp = fopen(path, "r");

  if (fp == NULL) {
    printf("error: don't find 'xmodmap'.\n");
    exit(0);
  }
}

char* version = "0.1";
void help_info(){
  printf("hyckm %s - (C) 2020 Zachary\n", version);
  printf("Usage: hyckm [command]\n\n");

  printf("    -h  --help      : Show this message\
        \n    -v  --version   : Display version information\
        \n    -r  --revert    : Revert the keyboard mapping\n\n");
}

void sys_info(char* param){
    if (!strcmp(param, "-h") || !strcmp(param, "--help")){
      help_info();
    }else if (!strcmp(param, "-v") || !strcmp(param, "--version")){
      printf("hyckm version (%s)\n", version);
    }else if (!strcmp(param, "-r") || !strcmp(param, "--revert")){

    }else {
      printf("error: no parameter !\n");
    }
}

void tips_info(){
  printf("       ==================\
        \n       = WELCOME to USE =\
        \n       ==================\n");

  printf("\nWhat keymap you want to change ? If want to map 'Escape' to 'Caps_Lock', like (Escape Caps_Lock).");
  printf("\nSupport a-z(lower case) 0-9 F1-F12\n");

  printf("\nSome keys you should input such names, there are:\n");
  printf("   -------            -------------               -----------\
        \n   | ESC | : Escape   | Cpas Lock | : Caps_Lock   | Shift ↑ | : Shift_L  Shift_R\
        \n   -------            -------------               -----------\
        \n   --------                          -------\
        \n   | Ctrl | : Control_L  Control_R   | Alt | : Alt_L  Alt_R\
        \n   --------                          -------\
        \n   -----------            ---------\
        \n   | Enter ⏎ | : Return   | Win ◆ | : Super_L\
        \n   -----------            ---------\
        \n   ---------------\
        \n   | ← Backspace | : BackSpace\
        \n   ---------------\n");
}

void _run(){
  system("sh $HOME/.hyckm/main.sh");
}

char *join(char *a, char *b) {
  char *c = (char *) malloc(strlen(a) + strlen(b) + 1); 
  //局部变量，用malloc申请内存,strlen不算'\0'，所以需要+1
  if (c == NULL) exit (1);
  char *tempc = c; //把首地址存下来
  while (*a != '\0') {
      *c++ = *a++;
  }
  while ((*c++ = *b++) != '\0') {
      ;
  }
  //注意，此时指针c已经指向拼接之后的字符串的结尾'\0' !
  return tempc;
  //返回值是局部malloc申请的指针变量，需在函数调用结束后free。
}
