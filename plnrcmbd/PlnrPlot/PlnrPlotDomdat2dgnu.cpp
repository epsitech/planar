/**
  * \file PlnrPlotDomdat2dgnu.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrPlotDomdat2dgnu.h"

DpchRetPlnrPlotDomdat2dgnu* PlnrPlotDomdat2dgnu::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dgnu* dpchinv
		) {
	DpchRetPlnrPlotDomdat2dgnu* dpchret = new DpchRetPlnrPlotDomdat2dgnu();

	string alttitle = dpchinv->alttitle;
	ubigint refFile = dpchinv->refFile;
	bool spczlim = dpchinv->spczlim;
	string srefDom = dpchinv->srefDom;
	string xdim = dpchinv->xdim;
	string ydim = dpchinv->ydim;
	double zmax = dpchinv->zmax;
	double zmin = dpchinv->zmin;
	vector<string> zslcDims = dpchinv->zslcDims;
	vector<int> zslcIcs = dpchinv->zslcIcs;
	string zvar = dpchinv->zvar;

// IP run --- IBEGIN
	ostringstream str;

	PlnrMFile* fil = NULL;

	string outfolder;
	string outpath;

	fstream gpfile;
	fstream txtfile;

	int cdfRoot;

	int dimid;
	unsigned int width, height;

	string path;

	double x0, x1, dx;
	double y0, y1, dy;

	vector<double> xvec;
	vector<double> yvec;

	vector<double> zvec;

	string title;
	string zlong_name;
	string ztitle;

	bool good;

	// --- load and vaildate data

	// cdf file via archive
	dbsplnr->tblplnrmfile->loadRecByRef(refFile, &fil);
	str.str(""); str << xchg->acvpath << "/" << fil->Archivename.substr(0, 5) << "/" << fil->Archivename;
	delete fil;

	nc_open(str.str().c_str(), 0, &cdfRoot);

	// x data via dim
	str.str(""); str << "doms," << srefDom;
	path = str.str();

	good = Cdf::getDim(cdfRoot, path, xdim, dimid, width);

	if (good) {
		str.str(""); str << StrMod::lc(xdim.substr(3)) << "0";
		Cdf::getDouble(cdfRoot, path, str.str(), x0);
		str.str(""); str << StrMod::lc(xdim.substr(3)) << "1";
		Cdf::getDouble(cdfRoot, path, str.str(), x1);
		str.str(""); str << "d" << StrMod::lc(xdim.substr(3));
		Cdf::getDouble(cdfRoot, path, str.str(), dx);

		xvec.resize(0); xvec.resize(width);

		for (unsigned int i=0;i<width;i++) xvec[i] = x0 + ((double) i)*dx;
	};

	// y data via dim
	if (good) {
		good = Cdf::getDim(cdfRoot, path, ydim, dimid, height);

		if (good) {
			str.str(""); str << StrMod::lc(ydim.substr(3)) << "0";
			Cdf::getDouble(cdfRoot, path, str.str(), y0);
			str.str(""); str << StrMod::lc(ydim.substr(3)) << "1";
			Cdf::getDouble(cdfRoot, path, str.str(), y1);
			str.str(""); str << "d" << StrMod::lc(ydim.substr(3));
			Cdf::getDouble(cdfRoot, path, str.str(), dy);

			yvec.resize(0); yvec.resize(height);

			for (unsigned int i=0;i<height;i++) yvec[i] = y0 + ((double) i)*dy;
		};
	};

	if (good) {
		// z data
		if (zslcDims.size() > 0) {
			good = Cdf::getDoubleVecSlc(cdfRoot, path, zvar, zslcDims, zslcIcs, xvec.size()*yvec.size(), zvec);
		} else {
			good = Cdf::getDoubleVec(cdfRoot, path, zvar, zvec);
		};

		if (good) {
			Cdf::getAttr(cdfRoot, path, zvar, "long_name", zlong_name);
			Cdf::getAttr(cdfRoot, path, zvar, "title", ztitle);
		};

		if (good && spczlim) {
			for (unsigned int i=0;i<zvec.size();i++) {
				if (zvec[i] < zmin) zvec[i] = zmin;
				if (zvec[i] > zmax) zvec[i] = zmax;
			};
		};
	};

	nc_close(cdfRoot);

	// --- generate input for gnuplot
	if (good) {
		outfolder = Tmp::newfolder(xchg->tmppath);

		// single text file for xvec/yvec
		str.str(""); str << xchg->tmppath << "/" << outfolder << "/data.txt";
		txtfile.open(str.str().c_str(), ios::out);
		txtfile.setf(ios::scientific);

		for (unsigned int i=0;i<width;i++) {
			for (unsigned int j=0;j<height;j++) {
				txtfile << xvec[i] << "\t" << yvec[j] << "\t" << zvec[i*height + j] << endl;
			};
		};

		txtfile.close();

		// gnuplot file
		str.str(""); str << xchg->tmppath << "/" << outfolder << "/plot.gp";
		gpfile.open(str.str().c_str(), ios::out);

		gpfile << "cd \"" << xchg->tmppath << "/" << outfolder << "\"" << endl;
		gpfile << "set terminal png size 800,600 xffffff" << endl;
		gpfile << "set output \"plot.png\"" << endl;
		if (alttitle.length() > 0) {
			gpfile << "set title \"" << alttitle << "\"" << endl;
		} else {
			gpfile << "set title \"" << title << "\"" << endl;
		};
		gpfile << "set xlabel \"" << StrMod::lc(xdim.substr(3)) << " [um]\"" << endl;
		gpfile << "set ylabel \"" << StrMod::lc(ydim.substr(3)) << " [um]\"" << endl;
		gpfile << "set palette defined (-1 \"blue\", 0 \"white\", 1 \"red\")" << endl;
		gpfile << "set view map" << endl;
		gpfile << "set pointsize 3" << endl;
		gpfile << "splot \"data.txt\" using 1:2:(0.0):3 with points palette" << endl;

		// --- run gnuplot
		str.str(""); str << "gnuplot " << xchg->tmppath << "/" << outfolder << "/plot.gp";
		system(str.str().c_str());

		// --- tar-gzip folder
		str.str(""); str << "tar -czvf " << xchg->tmppath << "/" << outfolder << ".tgz -C " << xchg->tmppath << outfolder << "/";
		system(str.str().c_str());

		str.str(""); str << outfolder << ".tgz";
		dpchret->tgzfile = str.str();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


