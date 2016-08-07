/**
  * \file PlnrPlotStksvg.cpp
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

#include "PlnrPlotStksvg.h"

DpchRetPlnrPlotStksvg* PlnrPlotStksvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotStksvg* dpchinv
		) {
	DpchRetPlnrPlotStksvg* dpchret = new DpchRetPlnrPlotStksvg();

	bool eqz = dpchinv->eqz;
	uint height = dpchinv->height;
	ubigint refBasedsn = dpchinv->refBasedsn;
	ubigint refModdsn = dpchinv->refModdsn;
	ubigint refPlnrMStack = dpchinv->refPlnrMStack;
	uint width = dpchinv->width;

// IP run --- IBEGIN
	ostringstream sqlstr;
	vector<ubigint> refs;

	ostringstream str;

	string svgpath;
	fstream svgfile;

	// stack elements
	ListPlnrMLevel lvls;
	PlnrMLevel* lvl = NULL;
	map<ubigint, unsigned int> lvlics;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	// other
	double b1;

	double ymin, ymax;
	double a22, b2;

	bool hasninf, haspinf;

	double x;

	string mat;

	// generate file in temp folder and open
	svgpath = Tmp::newfile(xchg->tmppath, "xml");
	str.str(""); str << xchg->tmppath << "/" << svgpath;

	svgfile.open(str.str().c_str(), ios::out);
	svgfile.setf(ios::fixed);
	svgfile.precision(3);
	writeSvgHeader(svgfile);

	// load stack primitives
	Plnr::getStackExp(dbsplnr, refPlnrMStack, refBasedsn, refModdsn, true, lvls, lyrs);

	// map ref vs. index of corresponding list
	for (unsigned int i=0;i<lvls.nodes.size();i++) lvlics[lvls.nodes[i]->ref] = i;

	// determine x boundaries
	b1 = 0.5*((double) width) - 0.5*(100.0 + 100.0);

	// determine y boundaries and scaling
	hasninf = (lvls.nodes[0]->z == -1.0e6);
	haspinf = (lvls.nodes[lvls.nodes.size()-1]->z == 1.0e6);

	if (eqz) {
		// all level spacings are equal
		a22 = ((double) (height-10)) / ((double) (lvls.nodes.size()-1));
		a22 *= -1.0;

		b2 = ((double) height) - 5.0;
		
	} else {
		// level spacings to scale
		ymin = 1e6; ymax = -1e6;

		for (unsigned int i=0;i<lvls.nodes.size();i++) {
			lvl = lvls.nodes[i];

			if ((lvl->z != -1.0e6) && (lvl->z != 1.0e6)) {
				if (lvl->z < ymin) ymin = lvl->z;
				if (lvl->z > ymax) ymax = lvl->z;
			};
		};

		if (hasninf) ymin -= 1.0;
		if (haspinf) ymax += 1.0;

		a22 = ((double) (height-10)) / (ymax-ymin);
		a22 *= -1.0;

		b2 = -a22*ymax + 5.0;
	};

	// --- svg element 
	svgfile << "\t\t<svg id=\"svg\" width=\"" << width << "\" height=\"" << height << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	// --- levels
	svgfile << "\t\t\t<g id=\"levels\">" << endl;

	x = b1;
	for (unsigned int i=0;i<lvls.nodes.size();i++) {
		lvl = lvls.nodes[i];

		if (lvl->z == -1.0e6) lvl->z = ymin;
		if (lvl->z == 1.0e6) lvl->z = ymax;

		svgfile << "\t\t\t\t<line class=\"z\" id=\"" << lvl->sref << "\" x1=\"" << x << "\" x2=\"" << (x+200.0);

		svgfile << "\" y1=\"";
		if (eqz) {
			svgfile << (a22*((double) i) + b2) << "\" y2=\"" << (a22*((double) i) + b2);
		} else {
			svgfile << (a22*lvl->z + b2) << "\" y2=\"" << (a22*lvl->z + b2);
		};

		svgfile << "\" onmouseover=\"tt(event, '" << lvl->sref;
		if (!(hasninf && (i==0)) && !(haspinf && (i==(lvls.nodes.size()-1)))) svgfile << "(z=" << lvl->z << ")";
		svgfile << "')\"/>" << endl;
	};
	svgfile << "\t\t\t</g>" << endl;

	// --- layers
	x += 100.0;

	svgfile << "\t\t\t<g id=\"layers\">" << endl;

	for (unsigned int i=0;i<lyrs.nodes.size();i++) {
		lyr = lyrs.nodes[i];

		svgfile << "\t\t\t\t<rect class=\"";

		if ((i%2) == 0) svgfile << "lyre";
		else svgfile << "lyro";

		svgfile << "\" id=\"" << lyr->sref << "\" x=\"" << (x+10.0) << "\" width=\"90.0\"";

		if (eqz) {
			svgfile << " y=\"";
			svgfile << (a22*lvlics[lyr->ceilRefPlnrMLevel] + b2);
			svgfile << "\" height=\"";
			svgfile << (a22*lvlics[lyr->flrRefPlnrMLevel] - a22*lvlics[lyr->ceilRefPlnrMLevel]);

		} else {
			svgfile << " y=\"";
			svgfile << (a22*lvls.nodes[lvlics[lyr->ceilRefPlnrMLevel]]->z + b2);
			svgfile << "\" height=\"";
			svgfile << (a22*lvls.nodes[lvlics[lyr->flrRefPlnrMLevel]]->z - a22*lvls.nodes[lvlics[lyr->ceilRefPlnrMLevel]]->z);
		};

		svgfile << "\" onmouseover=\"tt(event, '" << lyr->sref;
		if (atof(lyr->t.c_str()) != 0.0) svgfile << "(t=" << atof(lyr->t.c_str()) << ")";
		svgfile << "', '";

		sqlstr.str(""); sqlstr << "SELECT Title FROM TblPlnrMMaterial WHERE ref = " << lyr->refPlnrMMaterial;
		dbsplnr->loadStringBySQL(sqlstr.str(), mat);
		svgfile << mat << "')\"/>" << endl;
	};

	svgfile << "\t\t\t</g>" << endl;

	// finish up
	svgfile << "\t\t</svg>" << endl;

	writeSvgFooter(svgfile);
	svgfile.close();

	dpchret->svgfile = svgpath;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


