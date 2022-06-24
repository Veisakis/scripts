CC=gcc
CFLAGS=-Wall

LIB_PATH=~/scripts/lib
HEAD_PATH=~/scripts/include

SRC=countvowels.c #$(wildcard *.c)
#OBJ=$(patsubst %.c, %.o, $(SRC))
LIB=arrays

BIN=vowels

all:
	gcc $(CFLAGS) $(SRC) -o $(BIN)	-I $(HEAD_PATH) -L $(LIB_PATH) -l$(LIB)

clean:
	rm $(BIN)
