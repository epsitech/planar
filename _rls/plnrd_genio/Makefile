# file Makefile
# make file for Plnr daemon, release plnrd_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

SRCROOT = /home/epsi/src
LIBROOT = /home/epsi/lib
BINROOT = /home/epsi/bin

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DPLNRD
LDFLAGS =

INCS = -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include -I/usr/include
INCS += -I$(SRCROOT)
INCS += -I$(SRCROOT)/dbsplnr
INCS += -I$(SRCROOT)/plnrd -I$(SRCROOT)/plnrd/IexPlnr -I$(SRCROOT)/plnrd/VecPlnr
INCS += -I$(SRCROOT)/plnrd/CrdPlnrNav -I$(SRCROOT)/plnrd/CrdPlnrUsg -I$(SRCROOT)/plnrd/CrdPlnrUsr -I$(SRCROOT)/plnrd/CrdPlnrPrs -I$(SRCROOT)/plnrd/CrdPlnrFil -I$(SRCROOT)/plnrd/CrdPlnrDtp -I$(SRCROOT)/plnrd/CrdPlnrCtp -I$(SRCROOT)/plnrd/CrdPlnrMat -I$(SRCROOT)/plnrd/CrdPlnrPrj -I$(SRCROOT)/plnrd/CrdPlnrDsn -I$(SRCROOT)/plnrd/CrdPlnrDom -I$(SRCROOT)/plnrd/CrdPlnrDgd -I$(SRCROOT)/plnrd/CrdPlnrDvc -I$(SRCROOT)/plnrd/CrdPlnrSru -I$(SRCROOT)/plnrd/CrdPlnrStk -I$(SRCROOT)/plnrd/CrdPlnrLyr -I$(SRCROOT)/plnrd/CrdPlnrClc -I$(SRCROOT)/plnrd/CrdPlnrCli -I$(SRCROOT)/plnrd/CrdPlnrTpo -I$(SRCROOT)/plnrd/CrdPlnrArr -I$(SRCROOT)/plnrd/CrdPlnrAri -I$(SRCROOT)/plnrd/CrdPlnrRtc

LIBS = -L$(LIBROOT)/plnrd
LIBS += -lcrdplnrnav -lcrdplnrusg -lcrdplnrusr -lcrdplnrprs -lcrdplnrfil -lcrdplnrdtp -lcrdplnrctp -lcrdplnrmat -lcrdplnrprj -lcrdplnrdsn -lcrdplnrdom -lcrdplnrdgd -lcrdplnrdvc -lcrdplnrsru -lcrdplnrstk -lcrdplnrlyr -lcrdplnrclc -lcrdplnrcli -lcrdplnrtpo -lcrdplnrarr -lcrdplnrari -lcrdplnrrtc
LIBS += -liexplnr
LIBS += -L$(LIBROOT)
LIBS += -ldbsplnr -lvecplnr
LIBS += -ldbdartcore
LIBS += -L/usr/lib -lxml2
LIBS += -lmysqlclient
LIBS += -lpq
LIBS += -L/usr/local/lib -lmicrohttpd
LIBS += -lcurl
LIBS += -L/lib/x86_64-linux-gnu/libpthread -lpthread
LIBS += -L/usr/lib -lnetcdf -lhdf5_hl -lhdf5 -lz

PCHS = Plnrd.h.gch

OBJECTS = Plnr.o PlnrdAppsrv.o PlnrdJobprc.o PlnrdOpengcli.o PlnrdOpengconsrv.o Plnrd.o
OBJECTS += PlnrExp_blks.o SqkPlnrExp.o PlnrMeep_blks.o SqkPlnrMeep.o PlnrMesh_blks.o SqkPlnrMesh.o PlnrPlot_blks.o SqkPlnrPlot.o PlnrRast_blks.o SqkPlnrRast.o PlnrWgmode_blks.o SqkPlnrWgmode.o
OBJECTS += RootPlnr.o SessPlnr.o
OBJECTS += Plnrd_exe.o

EXE = Plnrd

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
	cp $(EXE) $(BINROOT)/plnrd/

clean:
	rm -f *.gch
	rm -f *.o

