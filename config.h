/*
 * Copyright(C) 2020, Tech. Co.,Ltd.
 * FileName: config.c
 * Author: zachary
 *
 * Date: 2020-05-24
 * Last Modified: 
 * Description: global config
 */


#ifndef CONFIG_H
#define CONFIG_H
char const* VERSION;
char const* XMODMAP;

#define R_OK 4  /* Test for read permission.  */
#define W_OK 2  /* Test for write permission.  */
#define X_OK 1  /* Test for execute permission.  */
#define F_OK 0  /* Test for existence.  */

#endif

//#ifdef XMOD
//char const* XMODMAP = "/usr/bin/xmodmap";
//#endif
