# file copy.sh
# copy script for Plnr combined daemon, release plnrcmbd_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

export set SRCROOT=/Users/epsi/src
export set LIBROOT=/Users/epsi/lib
export set BINROOT=/Users/epsi/bin

mkdir $SRCROOT/plnrcmbd
mkdir $SRCROOT/plnrcmbd/IexPlnr
mkdir $SRCROOT/plnrcmbd/VecPlnr
mkdir $SRCROOT/plnrcmbd/CrdPlnrNav
mkdir $SRCROOT/plnrcmbd/CrdPlnrUsg
mkdir $SRCROOT/plnrcmbd/CrdPlnrUsr
mkdir $SRCROOT/plnrcmbd/CrdPlnrPrs
mkdir $SRCROOT/plnrcmbd/CrdPlnrFil
mkdir $SRCROOT/plnrcmbd/CrdPlnrDtp
mkdir $SRCROOT/plnrcmbd/CrdPlnrCtp
mkdir $SRCROOT/plnrcmbd/CrdPlnrMat
mkdir $SRCROOT/plnrcmbd/CrdPlnrPrj
mkdir $SRCROOT/plnrcmbd/CrdPlnrDsn
mkdir $SRCROOT/plnrcmbd/CrdPlnrDom
mkdir $SRCROOT/plnrcmbd/CrdPlnrDgd
mkdir $SRCROOT/plnrcmbd/CrdPlnrDvc
mkdir $SRCROOT/plnrcmbd/CrdPlnrSru
mkdir $SRCROOT/plnrcmbd/CrdPlnrStk
mkdir $SRCROOT/plnrcmbd/CrdPlnrLyr
mkdir $SRCROOT/plnrcmbd/CrdPlnrClc
mkdir $SRCROOT/plnrcmbd/CrdPlnrCli
mkdir $SRCROOT/plnrcmbd/CrdPlnrTpo
mkdir $SRCROOT/plnrcmbd/CrdPlnrArr
mkdir $SRCROOT/plnrcmbd/CrdPlnrAri
mkdir $SRCROOT/plnrcmbd/CrdPlnrRtc
mkdir $SRCROOT/plnrcmbd/PlnrExp
mkdir $SRCROOT/plnrcmbd/PlnrMeep
mkdir $SRCROOT/plnrcmbd/PlnrMesh
mkdir $SRCROOT/plnrcmbd/PlnrPlot
mkdir $SRCROOT/plnrcmbd/PlnrRast
mkdir $SRCROOT/plnrcmbd/PlnrWgmode

mkdir $LIBROOT/plnrcmbd

mkdir $BINROOT/plnrcmbd

cp makeall.sh $SRCROOT/plnrcmbd/

cp Makefile $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/Plnrcmbd.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/Plnrcmbd.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/PlnrcmbdAppsrv.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/PlnrcmbdAppsrv.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/PlnrcmbdJobprc.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/PlnrcmbdJobprc.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/PlnrcmbdOpprc.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/PlnrcmbdOpprc.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/Plnrcmbd_exe.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/Plnrcmbd_exe.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/Plnr.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/Plnr.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/Root*.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/Root*.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/Sess*.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/Sess*.cpp $SRCROOT/plnrcmbd/

cp ../../plnrcmbd/gbl/*.h $SRCROOT/plnrcmbd/
cp ../../plnrcmbd/gbl/*.cpp $SRCROOT/plnrcmbd/

cp Makefile_IexPlnr $SRCROOT/plnrcmbd/IexPlnr/Makefile

cp ../../plnrcmbd/IexPlnr/IexPlnr*.h $SRCROOT/plnrcmbd/IexPlnr/
cp ../../plnrcmbd/IexPlnr/IexPlnr*.cpp $SRCROOT/plnrcmbd/IexPlnr/

cp Makefile_VecPlnr $SRCROOT/plnrcmbd/VecPlnr/Makefile

cp ../../plnrcmbd/VecPlnr/Vec*.h $SRCROOT/plnrcmbd/VecPlnr/
cp ../../plnrcmbd/VecPlnr/Vec*.cpp $SRCROOT/plnrcmbd/VecPlnr/

cp Makefile_CrdPlnrNav $SRCROOT/plnrcmbd/CrdPlnrNav/Makefile

cp ../../plnrcmbd/CrdPlnrNav/*.h $SRCROOT/plnrcmbd/CrdPlnrNav/
cp ../../plnrcmbd/CrdPlnrNav/*.cpp $SRCROOT/plnrcmbd/CrdPlnrNav/

cp Makefile_CrdPlnrUsg $SRCROOT/plnrcmbd/CrdPlnrUsg/Makefile

cp ../../plnrcmbd/CrdPlnrUsg/*.h $SRCROOT/plnrcmbd/CrdPlnrUsg/
cp ../../plnrcmbd/CrdPlnrUsg/*.cpp $SRCROOT/plnrcmbd/CrdPlnrUsg/

cp Makefile_CrdPlnrUsr $SRCROOT/plnrcmbd/CrdPlnrUsr/Makefile

cp ../../plnrcmbd/CrdPlnrUsr/*.h $SRCROOT/plnrcmbd/CrdPlnrUsr/
cp ../../plnrcmbd/CrdPlnrUsr/*.cpp $SRCROOT/plnrcmbd/CrdPlnrUsr/

cp Makefile_CrdPlnrPrs $SRCROOT/plnrcmbd/CrdPlnrPrs/Makefile

cp ../../plnrcmbd/CrdPlnrPrs/*.h $SRCROOT/plnrcmbd/CrdPlnrPrs/
cp ../../plnrcmbd/CrdPlnrPrs/*.cpp $SRCROOT/plnrcmbd/CrdPlnrPrs/

cp Makefile_CrdPlnrFil $SRCROOT/plnrcmbd/CrdPlnrFil/Makefile

cp ../../plnrcmbd/CrdPlnrFil/*.h $SRCROOT/plnrcmbd/CrdPlnrFil/
cp ../../plnrcmbd/CrdPlnrFil/*.cpp $SRCROOT/plnrcmbd/CrdPlnrFil/

cp Makefile_CrdPlnrDtp $SRCROOT/plnrcmbd/CrdPlnrDtp/Makefile

cp ../../plnrcmbd/CrdPlnrDtp/*.h $SRCROOT/plnrcmbd/CrdPlnrDtp/
cp ../../plnrcmbd/CrdPlnrDtp/*.cpp $SRCROOT/plnrcmbd/CrdPlnrDtp/

cp Makefile_CrdPlnrCtp $SRCROOT/plnrcmbd/CrdPlnrCtp/Makefile

cp ../../plnrcmbd/CrdPlnrCtp/*.h $SRCROOT/plnrcmbd/CrdPlnrCtp/
cp ../../plnrcmbd/CrdPlnrCtp/*.cpp $SRCROOT/plnrcmbd/CrdPlnrCtp/

cp Makefile_CrdPlnrMat $SRCROOT/plnrcmbd/CrdPlnrMat/Makefile

cp ../../plnrcmbd/CrdPlnrMat/*.h $SRCROOT/plnrcmbd/CrdPlnrMat/
cp ../../plnrcmbd/CrdPlnrMat/*.cpp $SRCROOT/plnrcmbd/CrdPlnrMat/

cp Makefile_CrdPlnrPrj $SRCROOT/plnrcmbd/CrdPlnrPrj/Makefile

cp ../../plnrcmbd/CrdPlnrPrj/*.h $SRCROOT/plnrcmbd/CrdPlnrPrj/
cp ../../plnrcmbd/CrdPlnrPrj/*.cpp $SRCROOT/plnrcmbd/CrdPlnrPrj/

cp Makefile_CrdPlnrDsn $SRCROOT/plnrcmbd/CrdPlnrDsn/Makefile

cp ../../plnrcmbd/CrdPlnrDsn/*.h $SRCROOT/plnrcmbd/CrdPlnrDsn/
cp ../../plnrcmbd/CrdPlnrDsn/*.cpp $SRCROOT/plnrcmbd/CrdPlnrDsn/

cp Makefile_CrdPlnrDom $SRCROOT/plnrcmbd/CrdPlnrDom/Makefile

cp ../../plnrcmbd/CrdPlnrDom/*.h $SRCROOT/plnrcmbd/CrdPlnrDom/
cp ../../plnrcmbd/CrdPlnrDom/*.cpp $SRCROOT/plnrcmbd/CrdPlnrDom/

cp Makefile_CrdPlnrDgd $SRCROOT/plnrcmbd/CrdPlnrDgd/Makefile

cp ../../plnrcmbd/CrdPlnrDgd/*.h $SRCROOT/plnrcmbd/CrdPlnrDgd/
cp ../../plnrcmbd/CrdPlnrDgd/*.cpp $SRCROOT/plnrcmbd/CrdPlnrDgd/

cp Makefile_CrdPlnrDvc $SRCROOT/plnrcmbd/CrdPlnrDvc/Makefile

cp ../../plnrcmbd/CrdPlnrDvc/*.h $SRCROOT/plnrcmbd/CrdPlnrDvc/
cp ../../plnrcmbd/CrdPlnrDvc/*.cpp $SRCROOT/plnrcmbd/CrdPlnrDvc/

cp Makefile_CrdPlnrSru $SRCROOT/plnrcmbd/CrdPlnrSru/Makefile

cp ../../plnrcmbd/CrdPlnrSru/*.h $SRCROOT/plnrcmbd/CrdPlnrSru/
cp ../../plnrcmbd/CrdPlnrSru/*.cpp $SRCROOT/plnrcmbd/CrdPlnrSru/

cp Makefile_CrdPlnrStk $SRCROOT/plnrcmbd/CrdPlnrStk/Makefile

cp ../../plnrcmbd/CrdPlnrStk/*.h $SRCROOT/plnrcmbd/CrdPlnrStk/
cp ../../plnrcmbd/CrdPlnrStk/*.cpp $SRCROOT/plnrcmbd/CrdPlnrStk/

cp Makefile_CrdPlnrLyr $SRCROOT/plnrcmbd/CrdPlnrLyr/Makefile

cp ../../plnrcmbd/CrdPlnrLyr/*.h $SRCROOT/plnrcmbd/CrdPlnrLyr/
cp ../../plnrcmbd/CrdPlnrLyr/*.cpp $SRCROOT/plnrcmbd/CrdPlnrLyr/

cp Makefile_CrdPlnrClc $SRCROOT/plnrcmbd/CrdPlnrClc/Makefile

cp ../../plnrcmbd/CrdPlnrClc/*.h $SRCROOT/plnrcmbd/CrdPlnrClc/
cp ../../plnrcmbd/CrdPlnrClc/*.cpp $SRCROOT/plnrcmbd/CrdPlnrClc/

cp Makefile_CrdPlnrCli $SRCROOT/plnrcmbd/CrdPlnrCli/Makefile

cp ../../plnrcmbd/CrdPlnrCli/*.h $SRCROOT/plnrcmbd/CrdPlnrCli/
cp ../../plnrcmbd/CrdPlnrCli/*.cpp $SRCROOT/plnrcmbd/CrdPlnrCli/

cp Makefile_CrdPlnrTpo $SRCROOT/plnrcmbd/CrdPlnrTpo/Makefile

cp ../../plnrcmbd/CrdPlnrTpo/*.h $SRCROOT/plnrcmbd/CrdPlnrTpo/
cp ../../plnrcmbd/CrdPlnrTpo/*.cpp $SRCROOT/plnrcmbd/CrdPlnrTpo/

cp Makefile_CrdPlnrArr $SRCROOT/plnrcmbd/CrdPlnrArr/Makefile

cp ../../plnrcmbd/CrdPlnrArr/*.h $SRCROOT/plnrcmbd/CrdPlnrArr/
cp ../../plnrcmbd/CrdPlnrArr/*.cpp $SRCROOT/plnrcmbd/CrdPlnrArr/

cp Makefile_CrdPlnrAri $SRCROOT/plnrcmbd/CrdPlnrAri/Makefile

cp ../../plnrcmbd/CrdPlnrAri/*.h $SRCROOT/plnrcmbd/CrdPlnrAri/
cp ../../plnrcmbd/CrdPlnrAri/*.cpp $SRCROOT/plnrcmbd/CrdPlnrAri/

cp Makefile_CrdPlnrRtc $SRCROOT/plnrcmbd/CrdPlnrRtc/Makefile

cp ../../plnrcmbd/CrdPlnrRtc/*.h $SRCROOT/plnrcmbd/CrdPlnrRtc/
cp ../../plnrcmbd/CrdPlnrRtc/*.cpp $SRCROOT/plnrcmbd/CrdPlnrRtc/

cp Makefile_PlnrExp $SRCROOT/plnrcmbd/PlnrExp/Makefile

cp ../../plnrcmbd/PlnrExp/*.h $SRCROOT/plnrcmbd/PlnrExp/
cp ../../plnrcmbd/PlnrExp/*.cpp $SRCROOT/plnrcmbd/PlnrExp/

cp Makefile_PlnrMeep $SRCROOT/plnrcmbd/PlnrMeep/Makefile

cp ../../plnrcmbd/PlnrMeep/*.h $SRCROOT/plnrcmbd/PlnrMeep/
cp ../../plnrcmbd/PlnrMeep/*.cpp $SRCROOT/plnrcmbd/PlnrMeep/

cp Makefile_PlnrMesh $SRCROOT/plnrcmbd/PlnrMesh/Makefile

cp ../../plnrcmbd/PlnrMesh/*.h $SRCROOT/plnrcmbd/PlnrMesh/
cp ../../plnrcmbd/PlnrMesh/*.cpp $SRCROOT/plnrcmbd/PlnrMesh/

cp Makefile_PlnrPlot $SRCROOT/plnrcmbd/PlnrPlot/Makefile

cp ../../plnrcmbd/PlnrPlot/*.h $SRCROOT/plnrcmbd/PlnrPlot/
cp ../../plnrcmbd/PlnrPlot/*.cpp $SRCROOT/plnrcmbd/PlnrPlot/

cp Makefile_PlnrRast $SRCROOT/plnrcmbd/PlnrRast/Makefile

cp ../../plnrcmbd/PlnrRast/*.h $SRCROOT/plnrcmbd/PlnrRast/
cp ../../plnrcmbd/PlnrRast/*.cpp $SRCROOT/plnrcmbd/PlnrRast/

cp Makefile_PlnrWgmode $SRCROOT/plnrcmbd/PlnrWgmode/Makefile

cp ../../plnrcmbd/PlnrWgmode/*.h $SRCROOT/plnrcmbd/PlnrWgmode/
cp ../../plnrcmbd/PlnrWgmode/*.cpp $SRCROOT/plnrcmbd/PlnrWgmode/

