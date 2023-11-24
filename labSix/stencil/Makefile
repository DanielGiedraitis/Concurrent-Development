# Author: Daniel Giedraitis (C00260331)
# Date Created: 10/11/2023
# Purpose: It contains rules that tell the system how to compile the code.
# GitHub URL: https://github.com/DanielGiedraitis/Concurrent-Development
# Licence: GPL-3.0

CFILES= stencil.cpp
HFILES=
CC=g++
CFLAGS= -std=c++11  -fopenmp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

STENCIL: stencil.o
	$(CC) -o stencil.out stencil.o $(CFLAGS) $(DEBUGFLAGS)

MANDEL: mandelbroit.o
	$(CC) -o mandelbroit.out mandelbroit.o $(CFLAGS) $(DEBUGFLAGS)


DSTENCIL: DEBUGFLAGS = -g -O0
DSTENCIL: STENCIL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
