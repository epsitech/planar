/**
  * \file PlnrPlotDomdat2dvid.cpp
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

#include "PlnrPlotDomdat2dvid.h"

DpchRetPlnrPlotDomdat2dvid* PlnrPlotDomdat2dvid::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDomdat2dvid* dpchinv
		) {
	DpchRetPlnrPlotDomdat2dvid* dpchret = new DpchRetPlnrPlotDomdat2dvid();

	double altzmax = dpchinv->altzmax;
	double altzmin = dpchinv->altzmin;
	string annotColor = dpchinv->annotColor;
	uint annotHeight = dpchinv->annotHeight;
	bool ctrzero = dpchinv->ctrzero;
	uint frmrate = dpchinv->frmrate;
	bool logscale = dpchinv->logscale;
	ubigint refFile = dpchinv->refFile;
	bool spczlim = dpchinv->spczlim;
	string srefDom = dpchinv->srefDom;
	string tdim = dpchinv->tdim;
	string xdim = dpchinv->xdim;
	string ydim = dpchinv->ydim;
	vector<string> zslcDims = dpchinv->zslcDims;
	vector<int> zslcIcs = dpchinv->zslcIcs;
	string zvar = dpchinv->zvar;

// IP run --- IBEGIN
	ostringstream str, str2, str3;
	string s;

	PlnrMFile* fil = NULL;

	string path;

	int cdfRoot;

	int dimid, pathid, varid;
	size_t attrlen;
	char* dimname;

	unsigned int length, width, height;

	double t0, t1, dt;
	double x0, x1, dx;
	double y0, y1, dy;

	vector<double> tvec;
	vector<double> xvec;
	vector<double> yvec;

	vector<double> zvec;

	string pretext;
	bool plusminus;
	double absmax;
	int predig, postdig;
	unsigned int ixwidth;
	unsigned int strwidth;

	bool good;

	unsigned char* imgdat = NULL;

	string tmpfolder;
	string pngfile;

	// --- load and vaildate data

	// -- cdf file via archive
	dbsplnr->tblplnrmfile->loadRecByRef(refFile, &fil);
	s = xchg->acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// -- t data via dim or from dedicated vector
	path = "doms;" + srefDom;

	good = Cdf::getDim(cdfRoot, path, tdim, dimid, length);

	if (good) {
		if (Cdf::getDouble(cdfRoot, path, StrMod::lc(tdim.substr(3)) + "0", t0)) {
			// geometry dimensions have dim0, dim1, ddim
			Cdf::getDouble(cdfRoot, path, StrMod::lc(tdim.substr(3)) + "1", t1);
			Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(tdim.substr(3)), dt);

			tvec.resize(0); tvec.resize(length);

			for (unsigned int i=0;i<length;i++) tvec[i] = t0 + ((double) i)*dt;

			pretext = StrMod::lc(tdim.substr(3)) + " [um] = ";

		} else if (Cdf::getDoubleVec(cdfRoot, path, StrMod::lc(tdim.substr(3)), tvec)) {
			t0 = tvec[0];
			t1 = tvec[tvec.size()-1];
			dt = fabs(t1-t0) / ((double) (tvec.size()-1));

			// non-geometry dimensions have corresponding variable
			pretext = StrMod::lc(tdim.substr(3)) + " = ";

			// try to find "long_name" variable attribute
			if (Cdf::getGroup(cdfRoot, path, pathid)) {
				if (nc_inq_varid(pathid, StrMod::lc(tdim.substr(3)).c_str(), &varid) == NC_NOERR) {
					if (nc_inq_attlen(pathid, varid, "long_name", &attrlen) == NC_NOERR) {
						dimname = new char[attrlen+1];

						nc_get_att_text(pathid, varid, "long_name", dimname);
						dimname[attrlen] = '\0';

						pretext = dimname;
						pretext = pretext + " = ";

						delete[] dimname;
					};
				};
			};

		} else {
			good = false;
		};
	};

	// -- determine required output format
	if (good) {
		plusminus = ((t0 < 0.0) || (t1 < 0.0));

		absmax = fabs(t1);
		if (fabs(t0) > fabs(t1)) absmax = fabs(t0);

		predig = lround(ceil(log10(absmax)));
		if (predig < 0) predig = 0;

		postdig = -lround(log10(fabs(dt)));
		if (postdig < 0) postdig = 0;

		strwidth = 0;
		if (plusminus) strwidth++;
		if (predig == 0) {
			strwidth += 2 + postdig; // assume that postdig can't be 0 - '0.' ...
		} else {
			strwidth += predig;
			if (postdig != 0) strwidth += 1 + postdig;
		};

		ixwidth = ceil(log10(tvec.size()));
	};

	// -- x data via dim
	if (good) {
		good = Cdf::getDim(cdfRoot, path, xdim, dimid, width);

		if (good) {
			Cdf::getDouble(cdfRoot, path, StrMod::lc(xdim.substr(3)) + "0", x0);
			Cdf::getDouble(cdfRoot, path, StrMod::lc(xdim.substr(3)) + "1", x1);
			Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(xdim.substr(3)), dx);

			xvec.resize(0); xvec.resize(width);

			for (unsigned int i=0;i<width;i++) xvec[i] = x0 + ((double) i)*dx;
		};
	};

	// -- y data via dim
	if (good) {
		good = Cdf::getDim(cdfRoot, path, ydim, dimid, height);

		if (good) {
			Cdf::getDouble(cdfRoot, path, StrMod::lc(ydim.substr(3)) + "0", y0);
			Cdf::getDouble(cdfRoot, path, StrMod::lc(ydim.substr(3)) + "1", y1);
			Cdf::getDouble(cdfRoot, path, "d" + StrMod::lc(ydim.substr(3)), dy);

			yvec.resize(0); yvec.resize(height);

			for (unsigned int i=0;i<height;i++) yvec[i] = y0 + ((double) i)*dy;
		};
	};

	// --- generate output
	tmpfolder = Tmp::newfolder(xchg->tmppath);

	// -- z data loop; in zvec, tdim varies the slowest and ydim varies the fastest
	if (good) {
		zslcDims.push_back(tdim);
		zslcIcs.push_back(0);

		for (unsigned int i=0;i<tvec.size();i++) {
			zslcIcs[zslcIcs.size()-1] = i;

			good = Cdf::getDoubleVecSlc(cdfRoot, path, zvar, zslcDims, zslcIcs, xvec.size()*yvec.size(), zvec);
			if (!good) break;

			// - generate single frame
			preparePng(zvec, spczlim, logscale, ctrzero, altzmin, altzmax, width, height, &imgdat);

			if (annotHeight > 0) {
				// tdim related annotation
				str.str("");
				str.width(strwidth);
				if (postdig != 0) str.precision(postdig);

				if (postdig == 0) {
					str << right << lround(tvec[i]);
				} else {
					str << fixed << tvec[i];
				};
				addPngDottext(imgdat, width, height, pretext + str.str(), "sw", annotHeight, annotColor);

				// frame counter
				str2.str("");
				str2 << (i+1) << "/" << tvec.size();
				addPngDottext(imgdat, width, height, str2.str(), "se", annotHeight, annotColor);
			};

			// - write .png and move to collective folder
			pngfile = writePng(xchg->tmppath, imgdat, width, height);

			str3.str("");
			str3.fill('0');
			str3.width(ixwidth);
			str3 << right << (i+1);

			s = "mv " + xchg->tmppath + "/" + pngfile + " " + xchg->tmppath + "/" + tmpfolder + "/frm" + str3.str() + ".png";
			system(s.c_str());
		};
	};

	nc_close(cdfRoot);

	// -- generate video from single frames
	if (good) {
		dpchret->mpgfile = Tmp::newfile(xchg->tmppath, "avi");

		str2.str("");
		str2 << "avconv -y -f image2 -i " << xchg->tmppath << "/" << tmpfolder << "/frm%0" << ixwidth << "d.png -r " << frmrate << " -s " << width << "x" << height << " " << xchg->tmppath << "/" << dpchret->mpgfile;
		system(str2.str().c_str());
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


