/**
  * \file PlnrPlotDomdat1dgnu.cpp
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

#include "PlnrPlotDomdat1dgnu.h"

DpchRetPlnrPlotDomdat1dgnu* PlnrPlotDomdat1dgnu::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat1dgnu* dpchinv
		) {
	DpchRetPlnrPlotDomdat1dgnu* dpchret = new DpchRetPlnrPlotDomdat1dgnu();

	string alttitle = dpchinv->alttitle;
	string altytitle = dpchinv->altytitle;
	ubigint refFile = dpchinv->refFile;
	string srefDom = dpchinv->srefDom;
	string xdim = dpchinv->xdim;
	vector<string> yslcDims = dpchinv->yslcDims;
	vector<int> yslcIcs = dpchinv->yslcIcs;
	string yvar = dpchinv->yvar;

// IP run --- IBEGIN
	ostringstream str;

	PlnrMFile* fil = NULL;

	string outfolder;
	string outpath;

	fstream gpfile;
	fstream txtfile;

	int cdfRoot;

	int dimid;
	unsigned int dim;

	string path;

	double x0, x1, dx;

	vector<double> xvec;
	vector<double> yvec;

	string title;
	string ylong_name;
	string ytitle;

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

	good = Cdf::getDim(cdfRoot, path, xdim, dimid, dim);

	if (good) {
		str.str(""); str << StrMod::lc(xdim.substr(3)) << "0";
		Cdf::getDouble(cdfRoot, path, str.str(), x0);
		str.str(""); str << StrMod::lc(xdim.substr(3)) << "1";
		Cdf::getDouble(cdfRoot, path, str.str(), x1);
		str.str(""); str << "d" << StrMod::lc(xdim.substr(3));
		Cdf::getDouble(cdfRoot, path, str.str(), dx);

		xvec.resize(0); xvec.resize(dim);

		for (unsigned int i=0;i<dim;i++) xvec[i] = x0 + ((double) i)*dx;
	};

	if (good) {
		// y data
		if (yslcDims.size() > 0) {
			good = Cdf::getDoubleVecSlc(cdfRoot, path, yvar, yslcDims, yslcIcs, xvec.size(), yvec);
		} else {
			good = Cdf::getDoubleVec(cdfRoot, path, yvar, yvec);
		};

		if (good) {
			Cdf::getAttr(cdfRoot, path, yvar, "long_name", ylong_name);
			Cdf::getAttr(cdfRoot, path, yvar, "title", ytitle);
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

		for (unsigned int j=0;j<xvec.size();j++) txtfile << xvec[j] << "\t" << yvec[j] << endl;

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
		if (altytitle.length() > 0) {
			gpfile << "set ylabel \"" << altytitle << "\"" << endl;
		} else {
			gpfile << "set ylabel \"" << ytitle << "\"" << endl;
		};
		gpfile << "plot \"data.txt\" using 1:2 with lines" << endl;

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


