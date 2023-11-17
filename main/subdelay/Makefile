# -*- MakeFile -*-

CC=gcc
CFLAGS=-Wall 
LIBS=-lcustom
LIB_PATH=~/scripts/lib
INC_PATH=~/scripts/include

subdelay: subdelay.c
	$(CC) $^ -o $@ $(CFLAGS) -I $(INC_PATH) -L $(LIB_PATH) $(LIBS)

clean:
	rm subdelay
