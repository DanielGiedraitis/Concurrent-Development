# Author: Daniel Giedraitis (C00260331)
# Date Created: 10/11/2023
# Purpose: It contains rules that tell the system how to compile the code.
# GitHub URL: https://github.com/DanielGiedraitis/Concurrent-Development
# Licence: GPL-3.0

CPPFILES= quicksort.cpp
HFILES=
CC=g++
CFLAGS= -std=c++11  -fopenmp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

QUICK: quicksort.o
	$(CC) -o qsort.out quicksort.o $(CFLAGS) $(DEBUGFLAGS)


DSORT: DEBUGFLAGS = -g -O0
DSORT: QUICK

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
