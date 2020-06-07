/*
 * Copyright(C) 2020, Tech. Co.,Ltd.
 * FileName: config.c
 * Author: zachary
 *
 * Date: 2020-05-24
 * Last Modified: 2020-06-02
 * Description: global config
 */

#ifndef _CONFIG_H
#define _CONFIG_H

extern char* VERSION;
extern char* XMODMAP;
extern char* MAPFILE;
extern char* MAPPINGSCRIPT;

#define R_OK 4 /* Test for read permission.  */
#define W_OK 2 /* Test for write permission.  */
#define X_OK 1 /* Test for execute permission.  */
#define F_OK 0 /* Test for existence.  */

#endif
