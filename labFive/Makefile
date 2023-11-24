# Author: Daniel Giedraitis (C00260331)
# Date Created: 02/11/2023
# Purpose: It contains rules that tell the system how to compile the code and produce a working executable called philosophers.
# Licence: GPL-3.0

CC=g++
CFLAGS= -std=c++11 -pthread -I -Wall
PFILES= main.o Semaphore.o Semaphore.h

# Rule to compile individual .cpp files into .o files
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Rule for RELEASE target to create the 'philosophers' executable
RELEASE: $(PFILES)
	$(CC) -o philosophers $(PFILES) $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags & Build Debug Build
DEBUG: DEBUGFLAGS = -g -O0

# Running DEBUG target invokes RELEASE with debugging flags
DEBUG: RELEASE

# Rule to clean/remove generated .o files
CLEAN:
	rm *.o