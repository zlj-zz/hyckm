#========================================
#    Makefile: makefile for hyckm 0.2
#  Copyright 2020
#                     Zachary Zhang
#   {https://github.com/zlj-zz/hyckm}
#  Last Modified: 2020/06/03
#========================================

VERSION=0.2
SRC=hyckm.c func.c config.c
OBJ=${SRC:.c=.o}
CC=gcc
CFLAGS=-O -Wall
PATH_=~/.local
PREFIX=/usr/local

all: hyckm

hyckm: ${OBJ}
	${CC} ${CFLAGS} -o $@ ${OBJ} -lncurses

clean:
	rm -f hyckm *.o

install: all
	cp -f hyckm ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/hyckm
	@echo "install finished ! [version ${VERSION}]"
	@echo " use 'hyckm' to start or 'hyckm -h' to watch help."

uninstall:
	rm -f ${PREFIX}/bin/hyckm
	@echo "uninstall finished !"

.PHONY: all clean install uninstall


