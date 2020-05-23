/*
Copyright(C) 1997-2020, Tech. Co.,Ltd.
FileName: main.c
Author: zachary
Date: 2020-05-23 14:09:54
Last Modified: 
Version: <++>
Description: <++>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./src/func.c"


int main(int argc, char *argv[])
{
  char* command = "sh $HOME/.hyckm/main.sh ";
  if (argc == 1) {
    system("clear");
    system(command);
    /*check_xmodmap();*/
    /*tips_info();*/
    /*_run();*/
  }else if (argc == 2){
    system(join(command, argv[1]));
    /*sys_info(argv[1]);*/
  }else{
    printf("error: too many parameters !\n");
    exit(1);
  }
  return 0;
}

