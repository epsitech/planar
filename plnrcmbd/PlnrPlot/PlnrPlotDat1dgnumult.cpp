/**
  * \file PlnrPlotDat1dgnumult.cpp
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

#include "PlnrPlotDat1dgnumult.h"

DpchRetPlnrPlotDat1dgnumult* PlnrPlotDat1dgnumult::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDat1dgnumult* dpchinv
		) {
	DpchRetPlnrPlotDat1dgnumult* dpchret = new DpchRetPlnrPlotDat1dgnumult();

	vector<ubigint> refsFile = dpchinv->refsFile;
	string title = dpchinv->title;
	vector<string> xpaths = dpchinv->xpaths;
	string xtitle = dpchinv->xtitle;
	vector<string> xvars = dpchinv->xvars;
	vector<string> ypaths = dpchinv->ypaths;
	string ytitle = dpchinv->ytitle;
	vector<string> yvars = dpchinv->yvars;

// IP run --- IBEGIN
	ostringstream str;
	bool first;

	PlnrMFile* fil = NULL;

	string outfolder;
	string outpath;

	fstream gpfile;
	fstream txtfile;

	int cdfRoot;

	vector<double> xvec;
	vector<double> yvec;

	string ylong_name;

	// --- generate input for gnuplot
	outfolder = Tmp::newfolder(xchg->tmppath);

	// gnuplot file
	str.str(""); str << xchg->tmppath << "/" << outfolder << "/plot.gp";
	gpfile.open(str.str().c_str(), ios::out);

	gpfile << "cd \"" << xchg->tmppath << "/" << outfolder << "\"" << endl;
	gpfile << "set terminal png size 800,600 xffffff" << endl;
	gpfile << "set output \"plot.png\"" << endl;
	gpfile << "set title \"" << title << "\"" << endl;
	gpfile << "set xlabel \"" << xtitle << "\"" << endl;
	gpfile << "set ylabel \"" << ytitle << "\"" << endl;

	// --- retrieve and copy data
	first = true;
	for (unsigned int i=0;i<refsFile.size();i++) {
		// cdf file via archive
		dbsplnr->tblplnrmfile->loadRecByRef(refsFile[i], &fil);
		str.str(""); str << xchg->acvpath << "/" << fil->Archivename.substr(0, 5) << "/" << fil->Archivename;
		delete fil;

		nc_open(str.str().c_str(), 0, &cdfRoot);
		Cdf::getDoubleVec(cdfRoot, xpaths[i], xvars[i], xvec);
		Cdf::getDoubleVec(cdfRoot, ypaths[i], yvars[i], yvec);
		Cdf::getAttr(cdfRoot, ypaths[i], yvars[i], "long_name", ylong_name);
		nc_close(cdfRoot);

		// one text file for each pair xpath/ypath
		str.str(""); str << xchg->tmppath << "/" << outfolder << "/data" << i << ".txt";
		txtfile.open(str.str().c_str(), ios::out);
		txtfile.setf(ios::scientific);

		for (unsigned int j=0;j<xvec.size();j++) txtfile << xvec[j] << "\t" << yvec[j] << endl;

		txtfile.close();

		// make entry in gnuplot input file
		if (first) {
			gpfile << "plot ";
			first = false;
		} else {
			gpfile << ", \\" << endl << "\t";
		};
		gpfile << "\"data" << i << ".txt\" using 1:2 with lines tit \"" << ylong_name << "\"";
	};
	gpfile << endl;
	gpfile.close();

	// --- run gnuplot
	str.str(""); str << "gnuplot " << xchg->tmppath << "/" << outfolder << "/plot.gp";
	system(str.str().c_str());

	// --- tar-gzip folder
	str.str(""); str << "tar -czvf " << xchg->tmppath << "/" << outfolder << ".tgz -C " << xchg->tmppath << outfolder << "/";
	system(str.str().c_str());

	str.str(""); str << outfolder << ".tgz";
	dpchret->tgzfile = str.str();
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


