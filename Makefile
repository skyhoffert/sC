# Filename: Makefile
# Description: Makefile for sC library.
# Revision: RevA
# Release Date: 2022-02-17
# Primary Author: Sky Hoffert
# Secondary Author(s): N/A
# Target Audience: Authors and testers of the sC library.

BINDIR=bin/
LIBDIR=lib/
TESTDIR=test/

CC=gcc
CFLAGS=-fPIC -Wall -I$(LIBDIR)
CLIBS=-lm

all: $(BINDIR)sC.test tmp

clean:
	$(info Cleaning.)
	rm -rf $(BINDIR)*

tmp: tmp.c
	$(CC) $(CFLAGS) -o tmp tmp.c -lm

$(BINDIR)sC.test: $(TESTDIR)sC.test.c $(LIBDIR)sC.h
	$(info Building sC test.)
	$(CC) $(CFLAGS) -o $(BINDIR)s.test \
		$(TESTDIR)sC.test.c $(CLIBS)
