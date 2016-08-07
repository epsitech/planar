# file makeall.sh
# make script for Plnr operation daemon, release plnropd_ungenio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

make Plnropd.h.gch

cd VecPlnr
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

rm Plnropd.h.gch

