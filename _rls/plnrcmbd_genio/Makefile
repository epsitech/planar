# file Makefile
# make file for Plnr combined daemon, release plnrcmbd_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

SRCROOT = /home/epsi/src
LIBROOT = /home/epsi/lib
BINROOT = /home/epsi/bin

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DPLNRCMBD
LDFLAGS =

INCS = -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include -I/usr/include
INCS += -I$(SRCROOT)
INCS += -I$(SRCROOT)/dbsplnr
INCS += -I$(SRCROOT)/plnrcmbd -I$(SRCROOT)/plnrcmbd/IexPlnr -I$(SRCROOT)/plnrcmbd/VecPlnr
INCS += -I$(SRCROOT)/plnrcmbd/CrdPlnrNav -I$(SRCROOT)/plnrcmbd/CrdPlnrUsg -I$(SRCROOT)/plnrcmbd/CrdPlnrUsr -I$(SRCROOT)/plnrcmbd/CrdPlnrPrs -I$(SRCROOT)/plnrcmbd/CrdPlnrFil -I$(SRCROOT)/plnrcmbd/CrdPlnrDtp -I$(SRCROOT)/plnrcmbd/CrdPlnrCtp -I$(SRCROOT)/plnrcmbd/CrdPlnrMat -I$(SRCROOT)/plnrcmbd/CrdPlnrPrj -I$(SRCROOT)/plnrcmbd/CrdPlnrDsn -I$(SRCROOT)/plnrcmbd/CrdPlnrDom -I$(SRCROOT)/plnrcmbd/CrdPlnrDgd -I$(SRCROOT)/plnrcmbd/CrdPlnrDvc -I$(SRCROOT)/plnrcmbd/CrdPlnrSru -I$(SRCROOT)/plnrcmbd/CrdPlnrStk -I$(SRCROOT)/plnrcmbd/CrdPlnrLyr -I$(SRCROOT)/plnrcmbd/CrdPlnrClc -I$(SRCROOT)/plnrcmbd/CrdPlnrCli -I$(SRCROOT)/plnrcmbd/CrdPlnrTpo -I$(SRCROOT)/plnrcmbd/CrdPlnrArr -I$(SRCROOT)/plnrcmbd/CrdPlnrAri -I$(SRCROOT)/plnrcmbd/CrdPlnrRtc
INCS += -I$(SRCROOT)/plnrcmbd/PlnrExp -I$(SRCROOT)/plnrcmbd/PlnrMeep -I$(SRCROOT)/plnrcmbd/PlnrMesh -I$(SRCROOT)/plnrcmbd/PlnrPlot -I$(SRCROOT)/plnrcmbd/PlnrRast -I$(SRCROOT)/plnrcmbd/PlnrWgmode

LIBS = -L$(LIBROOT)/plnrcmbd
LIBS += -lcrdplnrnav -lcrdplnrusg -lcrdplnrusr -lcrdplnrprs -lcrdplnrfil -lcrdplnrdtp -lcrdplnrctp -lcrdplnrmat -lcrdplnrprj -lcrdplnrdsn -lcrdplnrdom -lcrdplnrdgd -lcrdplnrdvc -lcrdplnrsru -lcrdplnrstk -lcrdplnrlyr -lcrdplnrclc -lcrdplnrcli -lcrdplnrtpo -lcrdplnrarr -lcrdplnrari -lcrdplnrrtc
LIBS += -lplnrexp -lplnrmeep -lplnrmesh -lplnrplot -lplnrrast -lplnrwgmode
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
LIBS += -L/usr/lib -lpng
LIBS += -L/usr/local/lib -lmeep -lharminv -lfftw3 -lm -llapack -lblas
LIBS += -L/usr/lib -lnetcdf -lhdf5_hl -lhdf5 -lz

PCHS = Plnrcmbd.h.gch

OBJECTS = Plnr.o PlnrcmbdAppsrv.o PlnrcmbdJobprc.o PlnrcmbdOpprc.o Plnrcmbd.o
OBJECTS += RootPlnr.o SessPlnr.o
OBJECTS += Plnrcmbd_exe.o

EXE = Plnrcmbd

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
	cp $(EXE) $(BINROOT)/plnrcmbd/

clean:
	rm -f *.gch
	rm -f *.o

