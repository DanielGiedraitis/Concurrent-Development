# Author: Daniel Giedraitis (C00260331)
# Date Created: 25/09/2023
# Purpose: Rules for creating object files, building executables (helloThreads and mutualEx), enabling debugging, and cleaning up generated object files.
# GitHub URL: https://github.com/DanielGiedraitis/Concurrent-Development
# Licence: GPL-3.0

CC=g++
CFLAGS= -std=c++11 -pthread -Wall

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
		$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

helloThreads: helloThreads.o Semaphore.o
		$(CC) -o helloThreads helloThreads.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)
	
mutualEx: mutualEx.o Semaphore.o
		$(CC) -o mutualEx mutualEx.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: helloThreads mutualEx

#This is customary and just deletes all .o files
CLEAN:
	rm -f *.o