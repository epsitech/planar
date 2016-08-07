# file copy.sh
# copy script for Plnr daemon, release plnrd_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

export set SRCROOT=/Users/epsi/src
export set LIBROOT=/Users/epsi/lib
export set BINROOT=/Users/epsi/bin
export set CMBDSRCROOT=../../../srcman/plnrcmbd

mkdir $SRCROOT/plnrd
mkdir $SRCROOT/plnrd/IexPlnr
mkdir $SRCROOT/plnrd/VecPlnr
mkdir $SRCROOT/plnrd/CrdPlnrNav
mkdir $SRCROOT/plnrd/CrdPlnrUsg
mkdir $SRCROOT/plnrd/CrdPlnrUsr
mkdir $SRCROOT/plnrd/CrdPlnrPrs
mkdir $SRCROOT/plnrd/CrdPlnrFil
mkdir $SRCROOT/plnrd/CrdPlnrDtp
mkdir $SRCROOT/plnrd/CrdPlnrCtp
mkdir $SRCROOT/plnrd/CrdPlnrMat
mkdir $SRCROOT/plnrd/CrdPlnrPrj
mkdir $SRCROOT/plnrd/CrdPlnrDsn
mkdir $SRCROOT/plnrd/CrdPlnrDom
mkdir $SRCROOT/plnrd/CrdPlnrDgd
mkdir $SRCROOT/plnrd/CrdPlnrDvc
mkdir $SRCROOT/plnrd/CrdPlnrSru
mkdir $SRCROOT/plnrd/CrdPlnrStk
mkdir $SRCROOT/plnrd/CrdPlnrLyr
mkdir $SRCROOT/plnrd/CrdPlnrClc
mkdir $SRCROOT/plnrd/CrdPlnrCli
mkdir $SRCROOT/plnrd/CrdPlnrTpo
mkdir $SRCROOT/plnrd/CrdPlnrArr
mkdir $SRCROOT/plnrd/CrdPlnrAri
mkdir $SRCROOT/plnrd/CrdPlnrRtc

mkdir $LIBROOT/plnrd

mkdir $BINROOT/plnrd

cp makeall.sh $SRCROOT/plnrd/

cp Makefile $SRCROOT/plnrd/

cp ../../plnrd/Plnrd.h $SRCROOT/plnrd/
cp ../../plnrd/Plnrd.cpp $SRCROOT/plnrd/

cp ../../plnrd/PlnrdAppsrv.h $SRCROOT/plnrd/
cp ../../plnrd/PlnrdAppsrv.cpp $SRCROOT/plnrd/

cp ../../plnrd/PlnrdJobprc.h $SRCROOT/plnrd/
cp ../../plnrd/PlnrdJobprc.cpp $SRCROOT/plnrd/

cp ../../plnrd/PlnrdOpengconsrv.h $SRCROOT/plnrd/
cp ../../plnrd/PlnrdOpengconsrv.cpp $SRCROOT/plnrd/

cp ../../plnrd/PlnrdOpengcli.h $SRCROOT/plnrd/
cp ../../plnrd/PlnrdOpengcli.cpp $SRCROOT/plnrd/

cp ../../plnrd/Plnrd_exe.h $SRCROOT/plnrd/
cp ../../plnrd/Plnrd_exe.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/Plnr.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/Plnr.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/Root*.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/Root*.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/Sess*.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/Sess*.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/gbl/*.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/gbl/*.cpp $SRCROOT/plnrd/

cp Makefile_IexPlnr $SRCROOT/plnrd/IexPlnr/Makefile

cp $CMBDSRCROOT/IexPlnr/IexPlnr*.h $SRCROOT/plnrd/IexPlnr/
cp $CMBDSRCROOT/IexPlnr/IexPlnr*.cpp $SRCROOT/plnrd/IexPlnr/

cp Makefile_VecPlnr $SRCROOT/plnrd/VecPlnr/Makefile

cp $CMBDSRCROOT/VecPlnr/Vec*.h $SRCROOT/plnrd/VecPlnr/
cp $CMBDSRCROOT/VecPlnr/Vec*.cpp $SRCROOT/plnrd/VecPlnr/

cp Makefile_CrdPlnrNav $SRCROOT/plnrd/CrdPlnrNav/Makefile

cp $CMBDSRCROOT/CrdPlnrNav/*.h $SRCROOT/plnrd/CrdPlnrNav/
cp $CMBDSRCROOT/CrdPlnrNav/*.cpp $SRCROOT/plnrd/CrdPlnrNav/

cp Makefile_CrdPlnrUsg $SRCROOT/plnrd/CrdPlnrUsg/Makefile

cp $CMBDSRCROOT/CrdPlnrUsg/*.h $SRCROOT/plnrd/CrdPlnrUsg/
cp $CMBDSRCROOT/CrdPlnrUsg/*.cpp $SRCROOT/plnrd/CrdPlnrUsg/

cp Makefile_CrdPlnrUsr $SRCROOT/plnrd/CrdPlnrUsr/Makefile

cp $CMBDSRCROOT/CrdPlnrUsr/*.h $SRCROOT/plnrd/CrdPlnrUsr/
cp $CMBDSRCROOT/CrdPlnrUsr/*.cpp $SRCROOT/plnrd/CrdPlnrUsr/

cp Makefile_CrdPlnrPrs $SRCROOT/plnrd/CrdPlnrPrs/Makefile

cp $CMBDSRCROOT/CrdPlnrPrs/*.h $SRCROOT/plnrd/CrdPlnrPrs/
cp $CMBDSRCROOT/CrdPlnrPrs/*.cpp $SRCROOT/plnrd/CrdPlnrPrs/

cp Makefile_CrdPlnrFil $SRCROOT/plnrd/CrdPlnrFil/Makefile

cp $CMBDSRCROOT/CrdPlnrFil/*.h $SRCROOT/plnrd/CrdPlnrFil/
cp $CMBDSRCROOT/CrdPlnrFil/*.cpp $SRCROOT/plnrd/CrdPlnrFil/

cp Makefile_CrdPlnrDtp $SRCROOT/plnrd/CrdPlnrDtp/Makefile

cp $CMBDSRCROOT/CrdPlnrDtp/*.h $SRCROOT/plnrd/CrdPlnrDtp/
cp $CMBDSRCROOT/CrdPlnrDtp/*.cpp $SRCROOT/plnrd/CrdPlnrDtp/

cp Makefile_CrdPlnrCtp $SRCROOT/plnrd/CrdPlnrCtp/Makefile

cp $CMBDSRCROOT/CrdPlnrCtp/*.h $SRCROOT/plnrd/CrdPlnrCtp/
cp $CMBDSRCROOT/CrdPlnrCtp/*.cpp $SRCROOT/plnrd/CrdPlnrCtp/

cp Makefile_CrdPlnrMat $SRCROOT/plnrd/CrdPlnrMat/Makefile

cp $CMBDSRCROOT/CrdPlnrMat/*.h $SRCROOT/plnrd/CrdPlnrMat/
cp $CMBDSRCROOT/CrdPlnrMat/*.cpp $SRCROOT/plnrd/CrdPlnrMat/

cp Makefile_CrdPlnrPrj $SRCROOT/plnrd/CrdPlnrPrj/Makefile

cp $CMBDSRCROOT/CrdPlnrPrj/*.h $SRCROOT/plnrd/CrdPlnrPrj/
cp $CMBDSRCROOT/CrdPlnrPrj/*.cpp $SRCROOT/plnrd/CrdPlnrPrj/

cp Makefile_CrdPlnrDsn $SRCROOT/plnrd/CrdPlnrDsn/Makefile

cp $CMBDSRCROOT/CrdPlnrDsn/*.h $SRCROOT/plnrd/CrdPlnrDsn/
cp $CMBDSRCROOT/CrdPlnrDsn/*.cpp $SRCROOT/plnrd/CrdPlnrDsn/

cp Makefile_CrdPlnrDom $SRCROOT/plnrd/CrdPlnrDom/Makefile

cp $CMBDSRCROOT/CrdPlnrDom/*.h $SRCROOT/plnrd/CrdPlnrDom/
cp $CMBDSRCROOT/CrdPlnrDom/*.cpp $SRCROOT/plnrd/CrdPlnrDom/

cp Makefile_CrdPlnrDgd $SRCROOT/plnrd/CrdPlnrDgd/Makefile

cp $CMBDSRCROOT/CrdPlnrDgd/*.h $SRCROOT/plnrd/CrdPlnrDgd/
cp $CMBDSRCROOT/CrdPlnrDgd/*.cpp $SRCROOT/plnrd/CrdPlnrDgd/

cp Makefile_CrdPlnrDvc $SRCROOT/plnrd/CrdPlnrDvc/Makefile

cp $CMBDSRCROOT/CrdPlnrDvc/*.h $SRCROOT/plnrd/CrdPlnrDvc/
cp $CMBDSRCROOT/CrdPlnrDvc/*.cpp $SRCROOT/plnrd/CrdPlnrDvc/

cp Makefile_CrdPlnrSru $SRCROOT/plnrd/CrdPlnrSru/Makefile

cp $CMBDSRCROOT/CrdPlnrSru/*.h $SRCROOT/plnrd/CrdPlnrSru/
cp $CMBDSRCROOT/CrdPlnrSru/*.cpp $SRCROOT/plnrd/CrdPlnrSru/

cp Makefile_CrdPlnrStk $SRCROOT/plnrd/CrdPlnrStk/Makefile

cp $CMBDSRCROOT/CrdPlnrStk/*.h $SRCROOT/plnrd/CrdPlnrStk/
cp $CMBDSRCROOT/CrdPlnrStk/*.cpp $SRCROOT/plnrd/CrdPlnrStk/

cp Makefile_CrdPlnrLyr $SRCROOT/plnrd/CrdPlnrLyr/Makefile

cp $CMBDSRCROOT/CrdPlnrLyr/*.h $SRCROOT/plnrd/CrdPlnrLyr/
cp $CMBDSRCROOT/CrdPlnrLyr/*.cpp $SRCROOT/plnrd/CrdPlnrLyr/

cp Makefile_CrdPlnrClc $SRCROOT/plnrd/CrdPlnrClc/Makefile

cp $CMBDSRCROOT/CrdPlnrClc/*.h $SRCROOT/plnrd/CrdPlnrClc/
cp $CMBDSRCROOT/CrdPlnrClc/*.cpp $SRCROOT/plnrd/CrdPlnrClc/

cp Makefile_CrdPlnrCli $SRCROOT/plnrd/CrdPlnrCli/Makefile

cp $CMBDSRCROOT/CrdPlnrCli/*.h $SRCROOT/plnrd/CrdPlnrCli/
cp $CMBDSRCROOT/CrdPlnrCli/*.cpp $SRCROOT/plnrd/CrdPlnrCli/

cp Makefile_CrdPlnrTpo $SRCROOT/plnrd/CrdPlnrTpo/Makefile

cp $CMBDSRCROOT/CrdPlnrTpo/*.h $SRCROOT/plnrd/CrdPlnrTpo/
cp $CMBDSRCROOT/CrdPlnrTpo/*.cpp $SRCROOT/plnrd/CrdPlnrTpo/

cp Makefile_CrdPlnrArr $SRCROOT/plnrd/CrdPlnrArr/Makefile

cp $CMBDSRCROOT/CrdPlnrArr/*.h $SRCROOT/plnrd/CrdPlnrArr/
cp $CMBDSRCROOT/CrdPlnrArr/*.cpp $SRCROOT/plnrd/CrdPlnrArr/

cp Makefile_CrdPlnrAri $SRCROOT/plnrd/CrdPlnrAri/Makefile

cp $CMBDSRCROOT/CrdPlnrAri/*.h $SRCROOT/plnrd/CrdPlnrAri/
cp $CMBDSRCROOT/CrdPlnrAri/*.cpp $SRCROOT/plnrd/CrdPlnrAri/

cp Makefile_CrdPlnrRtc $SRCROOT/plnrd/CrdPlnrRtc/Makefile

cp $CMBDSRCROOT/CrdPlnrRtc/*.h $SRCROOT/plnrd/CrdPlnrRtc/
cp $CMBDSRCROOT/CrdPlnrRtc/*.cpp $SRCROOT/plnrd/CrdPlnrRtc/

cp $CMBDSRCROOT/PlnrExp/PlnrExp_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrExp/PlnrExp_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrExp/SqkPlnrExp.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrExp/SqkPlnrExp.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/PlnrMeep/PlnrMeep_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMeep/PlnrMeep_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMeep/SqkPlnrMeep.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMeep/SqkPlnrMeep.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/PlnrMesh/PlnrMesh_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMesh/PlnrMesh_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMesh/SqkPlnrMesh.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrMesh/SqkPlnrMesh.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/PlnrPlot/PlnrPlot_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrPlot/PlnrPlot_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrPlot/SqkPlnrPlot.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrPlot/SqkPlnrPlot.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/PlnrRast/PlnrRast_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrRast/PlnrRast_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrRast/SqkPlnrRast.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrRast/SqkPlnrRast.cpp $SRCROOT/plnrd/

cp $CMBDSRCROOT/PlnrWgmode/PlnrWgmode_blks.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrWgmode/PlnrWgmode_blks.cpp $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrWgmode/SqkPlnrWgmode.h $SRCROOT/plnrd/
cp $CMBDSRCROOT/PlnrWgmode/SqkPlnrWgmode.cpp $SRCROOT/plnrd/

