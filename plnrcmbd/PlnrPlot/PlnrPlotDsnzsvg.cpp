/**
  * \file PlnrPlotDsnzsvg.cpp
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

#include "PlnrPlotDsnzsvg.h"

DpchRetPlnrPlotDsnzsvg* PlnrPlotDsnzsvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDsnzsvg* dpchinv
		) {
	DpchRetPlnrPlotDsnzsvg* dpchret = new DpchRetPlnrPlotDsnzsvg();

	bool eqz = dpchinv->eqz;
	uint height = dpchinv->height;
	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;
	bool showdoms = dpchinv->showdoms;
	uint width = dpchinv->width;

// IP run --- IBEGIN
	ostringstream sqlstr;
	vector<ubigint> refs;
	ubigint ref;

	ubigint refBasedsn;
	ubigint refModdsn;

	ostringstream str;

	string svgpath;
	fstream svgfile;

	// design elements
	ListPlnrMLevel lvls;
	ListPlnrMLevel lvls2;
	PlnrMLevel* lvl = NULL;
	PlnrMLevel* lvl2 = NULL;
	map<ubigint, unsigned int> lvlics;

	ListPlnrMStack stks;
	PlnrMStack* stk = NULL;
	map<ubigint, unsigned int> stkics;
	map<string, unsigned int> stkics2;

	string stksref;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	// domain elements
	ListPlnrMDomaingd dgs;
	PlnrMDomaingd* dg = NULL;

	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;
	unsigned int domcnt;

	set<unsigned int> domlvlics;
	map<string, unsigned int> domlvlics2;

	// other
	double b1;

	double ymin, ymax;
	double a22, b2;

	bool showstk;

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

	// load stacks of base design
	sqlstr.str(""); sqlstr << "SELECT modRefPlnrMDesign FROM TblPlnrMDesign WHERE ref = " << refPlnrMDesign;
	dbsplnr->loadUbigintBySQL(sqlstr.str(), refBasedsn);

	if (refBasedsn == 0) {
		refBasedsn = refPlnrMDesign;
		refModdsn = 0;
	} else {
		refModdsn = refPlnrMDesign;
	};

	dbsplnr->tblplnrmstack->loadRstByDsn(refBasedsn, false, stks);

	// map stack ref vs. index of corresponding list
	for (unsigned int i=0;i<stks.nodes.size();i++) {
		stk = stks.nodes[i];

		stkics[stk->ref] = i;
		stkics2[stk->sref] = i;
	};

	// load design primitives
	dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::DSN, refPlnrMDesign, false, lvls);
	dbsplnr->tblplnrmlayer->loadRstByDsnHktHku(0, VecPlnrVMLayerHkTbl::DSN, refPlnrMDesign, false, lyrs);

	// map ref vs. index of corresponding list
	for (unsigned int i=0;i<lvls.nodes.size();i++) lvlics[lvls.nodes[i]->ref] = i;

	// flag levels that are domainguides
	dbsplnr->tblplnrmdomaingd->loadRstByDsn(refBasedsn, false, dgs);

	for (unsigned int i=0;i<dgs.nodes.size();i++) {
		dg = dgs.nodes[i];

		if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LVL) {
			// find level
			for (unsigned int j=0;j<lvls.nodes.size();j++) {
				lvl = lvls.nodes[j];

				if (lvl->sref.compare(dg->sref) == 0) {
					domlvlics.insert(j);
					domlvlics2[dg->sref] = j;
					break;
				};
			};
		};
	};

	// flag levels that are used in domains
	dbsplnr->tblplnrmdomain->loadRstByDsn(refBasedsn, false, doms);

	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		if (dom->flrSrefPlnrMLevel.find('.') != string::npos) {
			if (findstklvl(dbsplnr, dom->flrSrefPlnrMLevel, stks, stkics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlvlics.insert(lvlics[ref]);
				domlvlics2[dom->flrSrefPlnrMLevel] = lvlics[ref];
			};
		};
		if (dom->ceilSrefPlnrMLevel.find('.') != string::npos) {
			if (findstklvl(dbsplnr, dom->ceilSrefPlnrMLevel, stks, stkics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlvlics.insert(lvlics[ref]);
				domlvlics2[dom->ceilSrefPlnrMLevel] = lvlics[ref];
			};
		};
	};

	// determine x boundaries
	showstk = ( (((double) width)-10.0-100.0) >= (((double) stks.nodes.size())*100.0) );

	if (showstk) {
		b1 = 0.5*((double) width) - 0.5*(100.0 + (((double) stks.nodes.size())*100.0));
	} else {
		b1 = 0.5*((double) width) - 0.5*100.0;
	};

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

		svgfile << "\t\t\t\t<line class=\"";
		if (domlvlics.find(i) != domlvlics.end()) {
			svgfile << "dgz";
		} else {
			svgfile << "z";
		};
		svgfile << "\" id=\"" << lvl->sref << "\" x1=\"" << x << "\" x2=\"";

		if (showstk) {
			svgfile << (x+100.0+100.0*((double) stks.nodes.size()));
		} else {
			svgfile << (x+100.0);
		};

		svgfile << "\" y1=\"";
		if (eqz) {
			svgfile << (a22*((double) i) + b2) << "\" y2=\"" << (a22*((double) i) + b2);
		} else {
			svgfile << (a22*lvl->z + b2) << "\" y2=\"" << (a22*lvl->z + b2);
		};

		svgfile << "\" onmouseover=\"tt(event, '" << lvl->sref;
		if (! ((hasninf && (i==0)) || (haspinf && (i==(lvls.nodes.size()-1))))) svgfile << "(z=" << lvl->z << ")";
		svgfile << "', '";

		// alternate sref's
		sqlstr.str(""); sqlstr << "SELECT stkRefPlnrMLevel FROM TblPlnrRMLevelMLevel WHERE dsnRefPlnrMLevel = " << lvl->ref;
		dbsplnr->loadRefsBySQL(sqlstr.str(), false, refs);
		dbsplnr->tblplnrmlevel->loadRstByRefs(refs, false, lvls2);

		for (unsigned int j=0;j<lvls2.nodes.size();j++) {
			lvl2 = lvls2.nodes[j];

			if (j == 0) {
				svgfile << "origin: ";
			} else {
				svgfile << ",";
			};

			svgfile << stks.nodes[stkics[lvl2->hkUref]]->sref << "." << lvl2->sref;
		};

		svgfile << "')\"/>" << endl;
	};
	svgfile << "\t\t\t</g>" << endl;

	// --- layers
	if (showstk) {
		svgfile << "\t\t\t<g id=\"layers\">" << endl;

		stksref = "";

		for (unsigned int i=0;i<lyrs.nodes.size();i++) {
			lyr = lyrs.nodes[i];

			if (lyr->sref.substr(0, lyr->sref.find('.')).compare(stksref) != 0) {
				stksref = lyr->sref.substr(0, lyr->sref.find('.'));
				x += 100.0;
			};

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
	};

	// --- domains
	if (showdoms) {
		svgfile << "\t\t\t<g id=\"domains\">" << endl;

		domcnt = 0;
		for (unsigned int i=0;i<doms.nodes.size();i++) {
			dom = doms.nodes[i];

			if ( (dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ)
						|| (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) ) {
				// display cub_xyz, zcsbox_xyz, zline_xyz, zline_z as vline
				svgfile << "\t\t\t\t<line class=\"domline\" id=\"";
				svgfile << dom->sref;

				if (eqz) {
					svgfile << " x2=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" y2=\"" << (a22*((double) domlvlics2[dom->flrSrefPlnrMLevel]) + b2) << "\"";
				} else {
					lvl = lvls.nodes[domlvlics2[dom->flrSrefPlnrMLevel]];
					svgfile << "\" x1=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" y1=\"" << (a22*lvl->z + b2) << "\"";
				};

				if (eqz) {
					svgfile << " x2=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" y2=\"" << (a22*((double) domlvlics2[dom->ceilSrefPlnrMLevel]) + b2) << "\"";
				} else {
					lvl = lvls.nodes[domlvlics2[dom->ceilSrefPlnrMLevel]];
					svgfile << " x2=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" y2=\"" << (a22*lvl->z + b2) << "\"";
				};

				svgfile << " onmouseover=\"tt(event, '" << dom->sref << "(" << VecPlnrVMDomainBasetype::getSref(dom->ixVBasetype) << ")";

				svgfile << "', '";
				if (dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")";
					svgfile << dom->vtx2SrefPlnrMVertex << "(" << dom->lgd2SrefPlnrMLineguide << ")";
					svgfile << dom->vtx3SrefPlnrMVertex << "(" << dom->lgd3SrefPlnrMLineguide << ")";
					svgfile << dom->vtx4SrefPlnrMVertex << "(" << dom->lgd4SrefPlnrMLineguide << ")";
				} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")";
					svgfile << dom->vtx2SrefPlnrMVertex;
				} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex;
				};
				svgfile << "')\"/>" << endl;

				domcnt++;

			} else if ( (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ)
						|| (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_Z) ) {
				// display xybox_xyz, xyline_xyz, point_xyz, point_z as dot
				svgfile << "\t\t\t\t<circle class=\"dompoint\" id=\"";
				svgfile << dom->sref;

				if (eqz) {
					svgfile << "\" cx=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" cy=\"" << (a22*((double) domlvlics2[dom->flrSrefPlnrMLevel]) + b2) << "\" r=\"2.0\"";
				} else {
					lvl = lvls.nodes[domlvlics2[dom->flrSrefPlnrMLevel]];
					svgfile << "\" cx=\"" << (b1+100.0-((double) domcnt)*10.0) << "\" cy=\"" << (a22*lvl->z + b2) << "\" r=\"2.0\"";
				};

				svgfile << " onmouseover=\"tt(event, '" << dom->sref << "(" << VecPlnrVMDomainBasetype::getSref(dom->ixVBasetype) << ")";

				svgfile << "', '";
				if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")";
					svgfile << dom->vtx2SrefPlnrMVertex << "(" << dom->lgd2SrefPlnrMLineguide << ")";
					svgfile << dom->vtx3SrefPlnrMVertex << "(" << dom->lgd3SrefPlnrMLineguide << ")";
					svgfile << dom->vtx4SrefPlnrMVertex << "(" << dom->lgd4SrefPlnrMLineguide << ")";
				} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")";
					svgfile << dom->vtx2SrefPlnrMVertex;
				} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) {
					svgfile << dom->vtx1SrefPlnrMVertex;
				};
				svgfile << "')\"/>" << endl;

				domcnt++;
			};
		};

		svgfile << "\t\t\t</g>" << endl;
	};

	// finish up
	svgfile << "\t\t</svg>" << endl;

	writeSvgFooter(svgfile);
	svgfile.close();

	dpchret->svgfile = svgpath;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
bool PlnrPlotDsnzsvg::findstklvl(
			DbsPlnr* dbsplnr
			, const string& sref
			, const ListPlnrMStack& stks
			, map<string, unsigned int>& stkics2
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMDesign
			, ubigint& ref
		) {
	ostringstream sqlstr;

	PlnrMStack* stk = NULL;

	stk = stks.nodes[stkics2[sref.substr(0, sref.find('.'))]];

	sqlstr.str(""); sqlstr << "SELECT ref FROM TblPlnrMLevel WHERE x0RefPlnrMDesign = " << refModdsn << " AND hkIxVTbl = " << VecPlnrVMLevelHkTbl::STK << " AND hkUref = " << stk->ref
				<< " AND sref = '" << sref.substr(sref.find('.')+1) << "'";
	if (!dbsplnr->loadUbigintBySQL(sqlstr.str(), ref)) {
		sqlstr.str(""); sqlstr << "SELECT ref FROM TblPlnrMLevel WHERE x0RefPlnrMDesign = 0 AND hkIxVTbl = " << VecPlnrVMLevelHkTbl::STK << " AND hkUref = " << stk->ref
					<< " AND sref = '" << sref.substr(sref.find('.')+1) << "'";
		dbsplnr->loadUbigintBySQL(sqlstr.str(), ref);
	};

	sqlstr.str(""); sqlstr << "SELECT TblPlnrMLevel.ref FROM TblPlnrMLevel, TblPlnrRMLevelMLevel WHERE TblPlnrMLevel.ref = TblPlnrRMLevelMLevel.dsnRefPlnrMLevel AND TblPlnrMLevel.hkIxVTbl = "
				<< VecPlnrVMLevelHkTbl::DSN << " AND TblPlnrMLevel.hkUref = " << refPlnrMDesign << " AND TblPlnrRMLevelMLevel.stkRefPlnrMLevel = " << ref;

	if (dbsplnr->loadUbigintBySQL(sqlstr.str(), ref)) return true;

	return false;
};
// IP cust --- IEND


