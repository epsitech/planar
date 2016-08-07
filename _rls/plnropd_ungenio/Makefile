# file Makefile
# make file for Plnr operation daemon, release plnropd_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

SRCROOT = /Users/epsi/src
LIBROOT = /Users/epsi/lib
BINROOT = /Users/epsi/bin

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DPLNROPD
LDFLAGS =

INCS = -I/opt/local/include/libxml2 -I/usr/local/mysql/include -I/opt/local/include/postgresql84 -I/opt/local/include -I/usr/include
INCS += -I$(SRCROOT)
INCS += -I$(SRCROOT)/dbsplnr
INCS += -I$(SRCROOT)/plnropd -I$(SRCROOT)/plnropd/VecPlnr
INCS += -I$(SRCROOT)/plnropd/PlnrExp -I$(SRCROOT)/plnropd/PlnrMeep -I$(SRCROOT)/plnropd/PlnrMesh -I$(SRCROOT)/plnropd/PlnrPlot -I$(SRCROOT)/plnropd/PlnrRast -I$(SRCROOT)/plnropd/PlnrWgmode

LIBS = -L$(LIBROOT)/plnropd
LIBS += -lplnrexp -lplnrmeep -lplnrmesh -lplnrplot -lplnrrast -lplnrwgmode
LIBS += -L$(LIBROOT)
LIBS += -ldbsplnr -lvecplnr
LIBS += -ldbdartcore
LIBS += -L/opt/local/lib -lxml2
LIBS += -L/usr/local/mysql/lib -lmysqlclient
LIBS += -L/opt/local/lib -lpq
LIBS += -lmicrohttpd
LIBS += -L/usr/lib -lcurl
LIBS += -L/opt/local/lib -lnetcdf -lhdf5_hl -lhdf5 -lz
LIBS += -L/usr/lib -lpng
LIBS += -L/opt/local/lib -lnetcdf -lhdf5_hl -lhdf5 -lz

PCHS = Plnropd.h.gch

OBJECTS = Plnr.o PlnropdEngsrv.o PlnropdOpprc.o Plnropd.o

OBJECTS += Plnropd_exe.o

EXE = Plnropd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

.cpp.o :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $(EXE)

pch:	$(PCHS)

install:
	cp $(EXE) $(BINROOT)/plnropd/

clean:
	rm -f *.gch
	rm -f *.o

