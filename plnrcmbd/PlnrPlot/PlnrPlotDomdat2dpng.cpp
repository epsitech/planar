/**
  * \file PlnrPlotDomdat2dpng.cpp
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

#include "PlnrPlotDomdat2dpng.h"

DpchRetPlnrPlotDomdat2dpng* PlnrPlotDomdat2dpng::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dpng* dpchinv
		) {
	DpchRetPlnrPlotDomdat2dpng* dpchret = new DpchRetPlnrPlotDomdat2dpng();

	double altzmax = dpchinv->altzmax;
	double altzmin = dpchinv->altzmin;
	string annotColor = dpchinv->annotColor;
	string annotDim = dpchinv->annotDim;
	uint annotHeight = dpchinv->annotHeight;
	string annotPos = dpchinv->annotPos;
	string annotText = dpchinv->annotText;
	bool ctrzero = dpchinv->ctrzero;
	bool logscale = dpchinv->logscale;
	ubigint refFile = dpchinv->refFile;
	bool spczlim = dpchinv->spczlim;
	string srefDom = dpchinv->srefDom;
	string xdim = dpchinv->xdim;
	string ydim = dpchinv->ydim;
	vector<string> zslcDims = dpchinv->zslcDims;
	vector<int> zslcIcs = dpchinv->zslcIcs;
	string zvar = dpchinv->zvar;

// IP run --- IBEGIN
	ostringstream str;
	string s;

	PlnrMFile* fil = NULL;

	string path;

	int cdfRoot;

	int dimid, pathid, varid;
	unsigned int dimlen;
	int ix;
	double dim0, dim1, ddim;
	vector<double> dimvec;
	size_t attrlen;
	char* dimname;

	unsigned int width, height;

	double x0, x1, dx;
	double y0, y1, dy;

	vector<double> xvec;
	vector<double> yvec;

	vector<double> zvec;

	bool good, found;

	unsigned char* imgdat = NULL;

	// --- load and vaildate data

	// -- cdf file via archive
	dbsplnr->tblplnrmfile->loadRecByRef(refFile, &fil);
	s = xchg->acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// -- x data via dim
	path = "doms;" + srefDom;

	good = Cdf::getDim(cdfRoot, path, xdim, dimid, width);

	if (good) {
cout << "good at getting xdim" << endl;

		Cdf::getDouble(cdfRoot, path, StrMod::lc(xdim.substr(3)) + "0", x0);
		Cdf::getDouble(cdfRoot, path, StrMod::lc(xdim.substr(3)) + "1", x1);
		Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(xdim.substr(3)), dx);

		xvec.resize(0); xvec.resize(width);

		for (unsigned int i=0;i<width;i++) xvec[i] = x0 + ((double) i)*dx;
	};

	// -- y data via dim
	if (good) {
		good = Cdf::getDim(cdfRoot, path, ydim, dimid, height);

		if (good) {
cout << "good at getting ydim" << endl;
			Cdf::getDouble(cdfRoot, path, StrMod::lc(ydim.substr(3)) + "0", y0);
			Cdf::getDouble(cdfRoot, path, StrMod::lc(ydim.substr(3)) + "1", y1);
			Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(ydim.substr(3)), dy);

			yvec.resize(0); yvec.resize(height);

			for (unsigned int i=0;i<height;i++) yvec[i] = y0 + ((double) i)*dy;
		};
	};

	// -- z data; in zvec, the ydim is the dimension varying faster
	if (good) {
cout << "xvec.size() = " << xvec.size() << ", yvec.size() = " << yvec.size() << endl;
		good = Cdf::getDoubleVecSlc(cdfRoot, path, zvar, zslcDims, zslcIcs, xvec.size()*yvec.size(), zvec);
	};

	// -- annotation text
	if (good) {
cout << "good at getting slice of length " << zvec.size() << endl;
		s = "";

		if (annotText.length() > 0) {
			s = annotText;

		} else if (annotDim.length() > 0) {
			// retrieve in zslcDims
			found = false;
			for (unsigned int i=0;i<zslcDims.size();i++) {
				if (zslcDims[i].compare(annotDim) == 0) {
					ix = zslcIcs[i];
					found = true;
					break;
				};
			};

			if (found) {
				// determine dimension characteristics and position within
				if (Cdf::getDim(cdfRoot, path, annotDim, dimid, dimlen)) {

					if (ix < 0) {
						// negative index: substract from dimlen unless out of range => center
						if ( ((size_t) -ix) <= dimlen ) {
							ix = dimlen + ix;
						} else {
							ix = dimlen/2;
						};

					} else {
						// positive index: out of range => center
						if ( ((size_t) ix) >= dimlen ) ix = dimlen/2;
					};


					if (Cdf::getDouble(cdfRoot, path, StrMod::lc(annotDim.substr(3)) + "0", dim0)) {
						// geometry dimensions have dim0, dim1, ddim
						Cdf::getDouble(cdfRoot, path, StrMod::lc(annotDim.substr(3)) + "1", dim1);
						Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(annotDim.substr(3)), ddim);
						
						str.str(""); str << StrMod::lc(annotDim.substr(3)) << " [um] = " << (dim0 + ((double) ix)*ddim);
						s = str.str();

					} else {
						// non-geometry dimensions have corresponding variable
						if (Cdf::getDoubleVec(cdfRoot, path, StrMod::lc(annotDim.substr(3)), dimvec)) {
							str.str(""); str << StrMod::lc(annotDim.substr(3));

							// try to find "long_name" variable attribute
							if (Cdf::getGroup(cdfRoot, path, pathid)) {
								if (nc_inq_varid(pathid, StrMod::lc(annotDim.substr(3)).c_str(), &varid) == NC_NOERR) {
									if (nc_inq_attlen(pathid, varid, "long_name", &attrlen) == NC_NOERR) {
										dimname = new char[attrlen+1];

										nc_get_att_text(pathid, varid, "long_name", dimname);
										dimname[attrlen] = '\0';

										str.str(""); str << dimname;

										delete[] dimname;
									};
								};
							};

							str << " = " << dimvec[ix];
							s = str.str();
						};
					};
				};
			};
		};
	};

	nc_close(cdfRoot);

	// --- generate png output
	if (good) {
		preparePng(zvec, spczlim, logscale, ctrzero, altzmin, altzmax, width, height, &imgdat);
cout << "PNG prepared" << endl;

		// annotation
		if (s.length() > 0) addPngDottext(imgdat, width, height, s, annotPos, annotHeight, annotColor);
cout << "dottext added" << endl;

		dpchret->pngfile = writePng(xchg->tmppath, imgdat, width, height);
cout << "output file: " << dpchret->pngfile << endl;
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


