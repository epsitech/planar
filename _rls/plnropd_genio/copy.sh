# file copy.sh
# copy script for Plnr operation daemon, release plnropd_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

export set SRCROOT=/home/epsi/src
export set LIBROOT=/home/epsi/lib
export set BINROOT=/home/epsi/bin
export set CMBDSRCROOT=../../../srcman/plnrcmbd

mkdir $SRCROOT/plnropd
mkdir $SRCROOT/plnropd/VecPlnr
mkdir $SRCROOT/plnropd/PlnrExp
mkdir $SRCROOT/plnropd/PlnrMeep
mkdir $SRCROOT/plnropd/PlnrMesh
mkdir $SRCROOT/plnropd/PlnrPlot
mkdir $SRCROOT/plnropd/PlnrRast
mkdir $SRCROOT/plnropd/PlnrWgmode

mkdir $LIBROOT/plnropd

mkdir $BINROOT/plnropd

cp makeall.sh $SRCROOT/plnropd/

cp Makefile $SRCROOT/plnropd/

cp ../../plnropd/Plnropd.h $SRCROOT/plnropd/
cp ../../plnropd/Plnropd.cpp $SRCROOT/plnropd/

cp ../../plnropd/PlnropdEngsrv.h $SRCROOT/plnropd/
cp ../../plnropd/PlnropdEngsrv.cpp $SRCROOT/plnropd/

cp ../../plnropd/PlnropdOpprc.h $SRCROOT/plnropd/
cp ../../plnropd/PlnropdOpprc.cpp $SRCROOT/plnropd/

cp ../../plnropd/Plnropd_exe.h $SRCROOT/plnropd/
cp ../../plnropd/Plnropd_exe.cpp $SRCROOT/plnropd/

cp $CMBDSRCROOT/Plnr.h $SRCROOT/plnropd/
cp $CMBDSRCROOT/Plnr.cpp $SRCROOT/plnropd/

cp Makefile_VecPlnr $SRCROOT/plnropd/VecPlnr/Makefile

cp $CMBDSRCROOT/VecPlnr/Vec*.h $SRCROOT/plnropd/VecPlnr/
cp $CMBDSRCROOT/VecPlnr/Vec*.cpp $SRCROOT/plnropd/VecPlnr/

cp Makefile_PlnrExp $SRCROOT/plnropd/PlnrExp/Makefile

cp $CMBDSRCROOT/PlnrExp/PlnrExp*.h $SRCROOT/plnropd/PlnrExp/
cp $CMBDSRCROOT/PlnrExp/PlnrExp*.cpp $SRCROOT/plnropd/PlnrExp/

cp Makefile_PlnrMeep $SRCROOT/plnropd/PlnrMeep/Makefile

cp $CMBDSRCROOT/PlnrMeep/PlnrMeep*.h $SRCROOT/plnropd/PlnrMeep/
cp $CMBDSRCROOT/PlnrMeep/PlnrMeep*.cpp $SRCROOT/plnropd/PlnrMeep/

cp Makefile_PlnrMesh $SRCROOT/plnropd/PlnrMesh/Makefile

cp $CMBDSRCROOT/PlnrMesh/PlnrMesh*.h $SRCROOT/plnropd/PlnrMesh/
cp $CMBDSRCROOT/PlnrMesh/PlnrMesh*.cpp $SRCROOT/plnropd/PlnrMesh/

cp Makefile_PlnrPlot $SRCROOT/plnropd/PlnrPlot/Makefile

cp $CMBDSRCROOT/PlnrPlot/PlnrPlot*.h $SRCROOT/plnropd/PlnrPlot/
cp $CMBDSRCROOT/PlnrPlot/PlnrPlot*.cpp $SRCROOT/plnropd/PlnrPlot/

cp Makefile_PlnrRast $SRCROOT/plnropd/PlnrRast/Makefile

cp $CMBDSRCROOT/PlnrRast/PlnrRast*.h $SRCROOT/plnropd/PlnrRast/
cp $CMBDSRCROOT/PlnrRast/PlnrRast*.cpp $SRCROOT/plnropd/PlnrRast/

cp Makefile_PlnrWgmode $SRCROOT/plnropd/PlnrWgmode/Makefile

cp $CMBDSRCROOT/PlnrWgmode/PlnrWgmode*.h $SRCROOT/plnropd/PlnrWgmode/
cp $CMBDSRCROOT/PlnrWgmode/PlnrWgmode*.cpp $SRCROOT/plnropd/PlnrWgmode/

