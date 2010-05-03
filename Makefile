##This is the makefile from nicoulaj's fork (http://github.com/nicoulaj)
##Thanks for creating it!
##note: only for building purposes.
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=`pkg-config --cflags --libs gtk+-2.0`

all: ubuntu ubuntu-64 kubuntu kubuntu-64

ubuntu:
$(CC) -m32 -o binaries/adobe_flash_installer-ubuntu adobe_flash_installer-ubuntu.c $(CFLAGS) $(LDFLAGS)

kubuntu:
$(CC) -m32 -o binaries/adobe_flash_installer-kubuntu adobe_flash_installer-kubuntu.c $(CFLAGS) $(LDFLAGS)

ubuntu-64:
$(CC) -m64 -o binaries/adobe_flash_installer-ubuntu-64bit adobe_flash_installer-ubuntu-64bit.c $(CFLAGS) $(LDFLAGS)

kubuntu-64:
$(CC) -m64 -o binaries/adobe_flash_installer-kubuntu-64bit adobe_flash_installer-kubuntu-64bit.c $(CFLAGS) $(LDFLAGS)

