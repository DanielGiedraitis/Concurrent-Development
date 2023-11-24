# Author: Daniel Giedraitis (C00260331)
# Date Created: 10/11/2023
# Purpose: It contains rules that tell the system how to compile the code.
# GitHub URL: https://github.com/DanielGiedraitis/Concurrent-Development
# Licence: GPL-3.0

CPPFILES= reduction.cpp
HFILES=
CC=g++
CFLAGS= -std=c++11  -fopenmp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lgomp  $(DEBUGFLAGS)

REDUCE: reduction.o
	$(CC) -o reduce.out reduction.o $(CFLAGS) $(DEBUGFLAGS)


DREDUCE: DEBUGFLAGS = -g -O0
DREDUCE: REDUCE

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
