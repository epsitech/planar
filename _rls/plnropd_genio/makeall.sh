# file makeall.sh
# make script for Plnr operation daemon, release plnropd_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

make Plnropd.h.gch

cd VecPlnr
make -j4
make install
cd ..

cd PlnrExp
make -j4
make install
cd ..

cd PlnrMeep
make -j4
make install
cd ..

cd PlnrMesh
make -j4
make install
cd ..

cd PlnrPlot
make -j4
make install
cd ..

cd PlnrRast
make -j4
make install
cd ..

cd PlnrWgmode
make -j4
make install
cd ..

make -j4
make install

rm Plnropd.h.gch

