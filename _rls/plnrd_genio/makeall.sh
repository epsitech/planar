# file makeall.sh
# make script for Plnr daemon, release plnrd_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

make Plnrd.h.gch

cd IexPlnr
make -j4
make install
cd ..

cd VecPlnr
make -j4
make install
cd ..

cd CrdPlnrNav
make -j4
make install
cd ..

cd CrdPlnrUsg
make -j4
make install
cd ..

cd CrdPlnrUsr
make -j4
make install
cd ..

cd CrdPlnrPrs
make -j4
make install
cd ..

cd CrdPlnrFil
make -j4
make install
cd ..

cd CrdPlnrDtp
make -j4
make install
cd ..

cd CrdPlnrCtp
make -j4
make install
cd ..

cd CrdPlnrMat
make -j4
make install
cd ..

cd CrdPlnrPrj
make -j4
make install
cd ..

cd CrdPlnrDsn
make -j4
make install
cd ..

cd CrdPlnrDom
make -j4
make install
cd ..

cd CrdPlnrDgd
make -j4
make install
cd ..

cd CrdPlnrDvc
make -j4
make install
cd ..

cd CrdPlnrSru
make -j4
make install
cd ..

cd CrdPlnrStk
make -j4
make install
cd ..

cd CrdPlnrLyr
make -j4
make install
cd ..

cd CrdPlnrClc
make -j4
make install
cd ..

cd CrdPlnrCli
make -j4
make install
cd ..

cd CrdPlnrTpo
make -j4
make install
cd ..

cd CrdPlnrArr
make -j4
make install
cd ..

cd CrdPlnrAri
make -j4
make install
cd ..

cd CrdPlnrRtc
make -j4
make install
cd ..

make -j4
make install

rm Plnrd.h.gch

