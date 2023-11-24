# Author: Daniel Giedraitis (C00260331)
# Date Created: 10/10/2023
# Purpose: It contains rules that tell the system how to compile the code and produce a working executable called barrier.
# GitHub URL: https://github.com/DanielGiedraitis/Concurrent-Development
# Licence: GPL-3.0

CC=g++
CFLAGS= -std=c++11 -pthread -I -Wall
BFILES=main.o Semaphore.o Barrier.o Semaphore.h Barrier.h

# Rule to compile individual .cpp files into .o files
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Rule for RELEASE target to create the 'barrier' executable
RELEASE: $(BFILES)
	$(CC) -o barrier $(BFILES) $(CFLAGS) $(DEBUGFLAGS)

# DEBUG target with debugging flags
DEBUG: DEBUGFLAGS = -g -O0

# Running DEBUG target invokes RELEASE with debugging flags
DEBUG: RELEASE

# Rule to clean/remove generated .o files
CLEAN:
	rm *.o