# file copy.sh
# copy script for Plnr database access library, release dbsplnr_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

export set SRCROOT=/home/epsi/src

mkdir $SRCROOT/dbsplnr

cp makeall.sh $SRCROOT/dbsplnr/

cp Makefile $SRCROOT/dbsplnr/

cp ../../dbsplnr/DbsPlnr.h $SRCROOT/dbsplnr/
cp ../../dbsplnr/DbsPlnr.cpp $SRCROOT/dbsplnr/
cp ../../dbsplnr/Plnr*.h $SRCROOT/dbsplnr/
cp ../../dbsplnr/Plnr*.cpp $SRCROOT/dbsplnr/
cp ../../dbsplnr/VecPlnr*.h $SRCROOT/dbsplnr/
cp ../../dbsplnr/VecPlnr*.cpp $SRCROOT/dbsplnr/

