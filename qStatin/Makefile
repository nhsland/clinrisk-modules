# 
# Copyright 2010 ClinRisk Ltd.
# 
# This file is part of QStatin (http://svn.clinrisk.co.uk/opensource/qstatin).
# 
# QStatin is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# QStatin is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with QStatin.  If not, see <http://www.gnu.org/licenses/>.
# 

CMDLINE_SRC=$(wildcard commandLine/*.c)
CMDLINE_OBJS = $(CMDLINE_SRC:.c=.o)
EXECUTABLES = $(CMDLINE_SRC:.c=)

LIB_SRC=$(wildcard c/*.c) utils/util.c
LIB_OBJ = $(LIB_SRC:.c=.o)
LIB_OUT = lib/libirisk.a

INCLUDES = -I include

# C++ compiler flags (-g -O2 -Wall)
#CCFLAGS = -g
CCFLAGS = 

# compiler
CC = gcc

# library paths
LIBS = -Llib -lirisk -lm

# compile flags
#LDFLAGS = -g
LDFLAGS = 

.SUFFIXES: .c

default: dep $(LIB_OUT)

executables: $(EXECUTABLES)
	cp $(EXECUTABLES) executables

$(EXECUTABLES): $(LIB_OUT)

.c:
	$(CC) $(INCLUDES) $(LDFLAGS) $< -o $@ $(LIBS)

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(LIB_OUT): $(LIB_OBJ)
	ar rcs $(LIB_OUT) $(LIB_OBJ)

depend: dep

dep:
	makedepend -- $(CFLAGS) -- -I /usr/include/linux $(INCLUDES) $(LIB_SRC)

clean:
	rm -f $(LIB_OBJ) $(LIB_OUT) Makefile.bak
	rm -f $(CMDLINE_OBJ) $(CMDLINE_PROGS) 
	rm -f executables/*

veryClean: clean
	rm -f c/*.c include/irisk/*.h commandLine/*
	cp utils/util.h include/irisk

# DO NOT DELETE

