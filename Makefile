BINFOLDER := bin/
INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall

SRCFILES := $(wildcard src/main.c)

all: $(SRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/main
#all:
#	gcc src/main.c obj/main.o -o bin/main

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean
clean:
	rm -fr obj/*
	rm -fr bin/*
	rm -fr database/*

run:
	bin/main
