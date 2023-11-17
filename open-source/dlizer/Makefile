# -*- MakeFile -*-

# Setup raylib path from terminal
# cannot be done from Makefile, cause it will only affect
# the shell it runs in, which is isolated
#find ~/.local/lib -type f -name *.pc
export PKG_CONFIG_PATH=/home/manousos/.local/lib/raylib/lib/pkgconfig

CC=gcc
CFLAGS=$(shell pkg-config --cflags raylib) -Wall 
LIBS=$(shell pkg-config --libs raylib) -lm

graph: graph.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

clean:
	rm graph
