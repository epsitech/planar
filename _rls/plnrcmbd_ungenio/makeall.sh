# file makeall.sh
# make script for Plnr combined daemon, release plnrcmbd_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

make Plnrcmbd.h.gch

cd IexPlnr
make -j2
make install
cd ..

cd VecPlnr
make -j2
make install
cd ..

cd CrdPlnrNav
make -j2
make install
cd ..

cd CrdPlnrUsg
make -j2
make install
cd ..

cd CrdPlnrUsr
make -j2
make install
cd ..

cd CrdPlnrPrs
make -j2
make install
cd ..

cd CrdPlnrFil
make -j2
make install
cd ..

cd CrdPlnrDtp
make -j2
make install
cd ..

cd CrdPlnrCtp
make -j2
make install
cd ..

cd CrdPlnrMat
make -j2
make install
cd ..

cd CrdPlnrPrj
make -j2
make install
cd ..

cd CrdPlnrDsn
make -j2
make install
cd ..

cd CrdPlnrDom
make -j2
make install
cd ..

cd CrdPlnrDgd
make -j2
make install
cd ..

cd CrdPlnrDvc
make -j2
make install
cd ..

cd CrdPlnrSru
make -j2
make install
cd ..

cd CrdPlnrStk
make -j2
make install
cd ..

cd CrdPlnrLyr
make -j2
make install
cd ..

cd CrdPlnrClc
make -j2
make install
cd ..

cd CrdPlnrCli
make -j2
make install
cd ..

cd CrdPlnrTpo
make -j2
make install
cd ..

cd CrdPlnrArr
make -j2
make install
cd ..

cd CrdPlnrAri
make -j2
make install
cd ..

cd CrdPlnrRtc
make -j2
make install
cd ..

cd PlnrExp
make -j2
make install
cd ..

cd PlnrMeep
make -j2
make install
cd ..

cd PlnrMesh
make -j2
make install
cd ..

cd PlnrPlot
make -j2
make install
cd ..

cd PlnrRast
make -j2
make install
cd ..

cd PlnrWgmode
make -j2
make install
cd ..

make -j2
make install

rm Plnrcmbd.h.gch

