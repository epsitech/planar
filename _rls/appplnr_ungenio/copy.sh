# file copy.sh
# copy script for Plnr app access library, release appplnr_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

export set SRCROOT=/Users/epsi/src

mkdir $SRCROOT/appplnr

cp makeall.sh $SRCROOT/appplnr/

cp Makefile $SRCROOT/appplnr/

cp ../../appplnr/*.h $SRCROOT/appplnr/
cp ../../appplnr/*.cpp $SRCROOT/appplnr/

