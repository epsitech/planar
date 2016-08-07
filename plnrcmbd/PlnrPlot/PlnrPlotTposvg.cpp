/**
  * \file PlnrPlotTposvg.cpp
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

#include "PlnrPlotTposvg.h"

DpchRetPlnrPlotTposvg* PlnrPlotTposvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotTposvg* dpchinv
		) {
	DpchRetPlnrPlotTposvg* dpchret = new DpchRetPlnrPlotTposvg();

	uint height = dpchinv->height;
	ubigint refPlnrMTapeout = dpchinv->refPlnrMTapeout;
	uint width = dpchinv->width;

// IP run --- IBEGIN
	ostringstream sqlstr;
	vector<ubigint> refs;

	ostringstream str;

	string svgpath;
	fstream svgfile;

	PlnrMTapeout* tpo = NULL;

	ListPlnrMReticle rtcs;
	PlnrMReticle* rtc = NULL;

	ListPlnrMStructure srus;
	PlnrMStructure* sru = NULL;

	vector<double> xmins;
	vector<double> xmaxs;
	vector<double> ymins;
	vector<double> ymaxs;

	double xmin, xmax, ymin, ymax;
	double a11, a22, b1, b2;

	double x, y, rtcw, rtch;

	dbsplnr->tblplnrmtapeout->loadRecByRef(refPlnrMTapeout, &tpo);

	// generate file in temp folder and open
	svgpath = Tmp::newfile(xchg->tmppath, "xml");
	str.str(""); str << xchg->tmppath << "/" << svgpath;

	svgfile.open(str.str().c_str(), ios::out);
	svgfile.setf(ios::fixed);
	svgfile.precision(3);
	writeSvgHeader(svgfile);

	// - load reticles and determine their boundaries
	dbsplnr->tblplnrmreticle->loadRstByHktHku(VecPlnrVMReticleHkTbl::TPO, refPlnrMTapeout, false, rtcs);

	xmins.resize(rtcs.nodes.size());
	xmaxs.resize(rtcs.nodes.size());
	ymins.resize(rtcs.nodes.size());
	ymaxs.resize(rtcs.nodes.size());

	for (unsigned int i=0;i<rtcs.nodes.size();i++) {
		rtc = rtcs.nodes[i];

		sqlstr.str(""); sqlstr << "SELECT refPlnrMStructure FROM TblPlnrMBlock WHERE refPlnrMLayer = " << rtc->refPlnrMLayer;
		dbsplnr->loadRefsBySQL(sqlstr.str(), false, refs);
		dbsplnr->tblplnrmstructure->loadRstByRefs(refs, false, srus);

		// find extrema of structures on layer
		xmin = 1.0e6;
		xmax = -1.0e6;
		ymin = 1.0e6;
		ymax = -1.0e6;

		for (unsigned int j=0;j<srus.nodes.size();j++) {
			sru = srus.nodes[j];

			if (sru->x0 < xmin) xmin = sru->x0;
			if (sru->x1 > xmax) xmax = sru->x1;
			if (sru->y0 < ymin) ymin = sru->y0;
			if (sru->y1 > ymax) ymax = sru->y1;
		};

		xmins[i] = xmin + rtc->x0;
		xmaxs[i] = xmax + rtc->x0;
		ymins[i] = ymin + rtc->y0;
		ymaxs[i] = ymax + rtc->y0;
	};

	// - calculate coordinate transform
	xmin = 1.0e6;
	xmax = -1.0e6;
	ymin = 1.0e6;
	ymax = -1.0e6;

	for (unsigned int i=0;i<rtcs.nodes.size();i++) {
		if (xmins[i] < xmin) xmin = xmins[i];
		if (xmaxs[i] > xmax) xmax = xmaxs[i];
		if (ymins[i] < ymin) ymin = ymins[i];
		if (ymaxs[i] > ymax) ymax = ymaxs[i];
	};

	// scale, invert x on hflip, invert y, then translate to (5.0,<center>) or (<center>,5.0)
	a11 = ((double) (width-10)) / (xmax-xmin);
	a22 = ((double) (height-10)) / (ymax-ymin);

	if (a11 < a22) {
		a22 = a11;

		a22 *= -1.0;
		if (tpo->Hflip) a11 *= -1.0;

		if (tpo->Hflip) {
			b1 = -a11*xmax + 5.0;
		} else {
			b1 = -a11*xmin + 5.0;
		};

		b2 = -a22*0.5*(ymin+ymax) + 0.5*((double) height);

	} else {
		a11 = a22;

		a22 *= -1.0;
		if (tpo->Hflip) a11 *= -1.0;

		b1 = -a11*0.5*(xmin+xmax) + 0.5*((double) width);
		b2 = -a22*ymax + 5.0;
	};

	// - svg element
	svgfile << "\t\t<svg id=\"svg\" width=\"" << width << "\" height=\"" << height << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	// - one rectangle per reticle
	for (unsigned int i=0;i<rtcs.nodes.size();i++) {
		rtc = rtcs.nodes[i];

		if (tpo->Hflip) {
			x = a11*xmaxs[i] + b1;
		} else {
			x = a11*xmins[i] + b1;
		};
		y = a22*ymaxs[i] + b2;

		rtcw = fabs(a11*(xmaxs[i]-xmins[i]));
		rtch = fabs(a22*(ymaxs[i]-ymins[i]));

		svgfile << "\t\t\t<rect class=\"rtc\" id=\"" << rtc->sref << "\" x=\"" << x << "\" y=\"" << y	<< "\" width=\"" << rtcw << "\" height=\"" << rtch
					<< "\" onmouseover=\"tt(event, '" << rtc->sref << "', 'x=[" << xmins[i] << "," << xmaxs[i] << "],y=[" << ymins[i] << "," << ymaxs[i] << "]')\"/>" << endl;
	};

	// finish up
	svgfile << "\t\t</svg>" << endl;

	writeSvgFooter(svgfile);
	svgfile.close();

	delete tpo;

	dpchret->svgfile = svgpath;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


