/*
 * Copyright(C) 2020, Tech. Co.,Ltd.
 *
 * FileName: hyckm
 * Author: Zachary
 * Date: 2020-05-23
 * Last Modified: 2020-05-24
 * Version: 0.1
 * Description: To help you change your keyboard mapping
 */
#define FUNC
#define XMOD

#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "func.h"


static int parseArguments(int argc, char ** argv);


int main(int argc, char *argv[])
{
  int flag = parseArguments(argc, argv); // may exit()

  if (access(XMODMAP, R_OK) != 0){ // check if 'xmodmap' command
    printf("error: don't find 'xmodmap'.\n");
    exit(1);
  }

  if (flag){ 
    /*system("clear");*/
    _run();
  }
  return 0;
}

static int parseArguments(int argc, char ** argv){/*{{{*/
  int flag = 1;

  static struct option long_opts[] =
  {
    {"help",    no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {"revert",  no_argument, 0, 'r'},
  };

  int opt, opti = 0;
  while ((opt = getopt_long(argc, argv, "hvr", long_opts, &opti))){
    if (opt == EOF) break;
    flag = 0;
    switch (opt) {
      case 'h':
        help_info();
        break;
      case 'v':
        version_info();
        break;
      case 'r':
        revert();
        break;
      default:
        exit(0);
    }
  }
  return flag;
}/*}}}*/