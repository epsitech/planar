/**
  * \file PlnrPlotDsnxysvg.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 28 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrPlotDsnxysvg.h"

DpchRetPlnrPlotDsnxysvg* PlnrPlotDsnxysvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDsnxysvg* dpchinv
		) {
	DpchRetPlnrPlotDsnxysvg* dpchret = new DpchRetPlnrPlotDsnxysvg();

	string datPngpath = dpchinv->datPngpath;
	string datSrefDom = dpchinv->datSrefDom;
	string datTit = dpchinv->datTit;
	uint height = dpchinv->height;
	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;
	vector<ubigint> refsLyr = dpchinv->refsLyr;
	bool showdoms = dpchinv->showdoms;
	bool showfces = dpchinv->showfces;
	bool showgds = dpchinv->showgds;
	bool showvtxs = dpchinv->showvtxs;
	bool spclyrs = dpchinv->spclyrs;
	uint width = dpchinv->width;

// IP run --- IBEGIN
	vector<ubigint> refs;
	ubigint ref;

	PlnrMDesign* dsn = NULL;

	ubigint refBasedsn;
	ubigint refModdsn;

	ostringstream str;
	bool found;

	string svgpath;
	fstream svgfile;

	// design elements
	ListPlnrMVertex vtxs;
	PlnrMVertex* vtx = NULL;
	ListPlnrMVertex vtxs2;
	PlnrMVertex* vtx2 = NULL;
	map<ubigint, unsigned int> vtxics;

	PlnrMVertex* vtx1 = NULL;
	PlnrMVertex* vtx4 = NULL;

	ListPlnrMLineguide lgs;
	ListPlnrMLineguide lgs2;
	PlnrMLineguide* lg = NULL;
	PlnrMLineguide* lg2 = NULL;
	map<ubigint, unsigned int> lgics;

	ListPlnrLRMLineguideMVertex lrvs;
	PlnrLRMLineguideMVertex* lrv = NULL;

	ListPlnrMArcguide ags;
	PlnrMArcguide* ag = NULL;
	PlnrMArcguide* ag2 = NULL;
	map<ubigint, unsigned int> agics;

	ListPlnrLRMArcguideMVertex arvs;
	PlnrLRMArcguideMVertex* arv = NULL;

	ListPlnrMStructure srus;
	PlnrMStructure* sru = NULL;
	map<ubigint, unsigned int> sruics;
	vector<ubigint> refsSru;

	vector<unsigned int> srufceics0;
	vector<unsigned int> srufceics1;

	ubigint refLyr;

	ListPlnrMFace fces;
	PlnrMFace* fce = NULL;
	PlnrMFace* fce2 = NULL;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	// device elements
	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;
	map<ubigint, unsigned int> devics;
	map<string, unsigned int> devics2;

	// domain elements
	ListPlnrMDomaingd dgs;
	PlnrMDomaingd* dg = NULL;

	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;

	set<unsigned int> domvtxics;
	map<string, unsigned int> domvtxics2;

	set<unsigned int> domlgics;
	map<string, unsigned int> domlgics2;

	// other
	double xmin, xmax, ymin, ymax;
	double a11, a22, b1, b2;
	double w, h, phi;

	// generate file in temp folder and open
	svgpath = Tmp::newfile(xchg->tmppath, "xml");
	str.str(""); str << xchg->tmppath << "/" << svgpath;

	svgfile.open(str.str().c_str(), ios::out);
	svgfile.setf(ios::fixed);
	svgfile.precision(3);

	dbsplnr->tblplnrmdesign->loadRecByRef(refPlnrMDesign, &dsn);
	writeSvgHeader(svgfile, dsn->Title);
	delete dsn;

	// load devices of base design
	dbsplnr->loadUbigintBySQL("SELECT modRefPlnrMDesign FROM TblPlnrMDesign WHERE ref = " + to_string(refPlnrMDesign), refBasedsn);

	if (refBasedsn == 0) {
		refBasedsn = refPlnrMDesign;
		refModdsn = 0;
	} else {
		refModdsn = refPlnrMDesign;
	};

	dbsplnr->tblplnrmdevice->loadRstByDsn(refBasedsn, false, devs);

	// map device ref vs. index of corresponding list
	for (unsigned int i=0;i<devs.nodes.size();i++) {
		dev = devs.nodes[i];

		devics[dev->ref] = i;
		devics2[dev->sref] = i;
	};

	// load design primitives
	dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, false, vtxs);
	dbsplnr->tblplnrmlineguide->loadRstByDsnHktHku(0, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, false, lgs);
	dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DSN, refPlnrMDesign, false, ags);
	dbsplnr->tblplnrmstructure->loadRstByHktHku(VecPlnrVMStructureHkTbl::DSN, refPlnrMDesign, false, srus);

	// load all faces, enforce layer constraint during code generation
	for (unsigned int i=0;i<srus.nodes.size();i++) {
		sru = srus.nodes[i];
		
		srufceics0.push_back(fces.nodes.size());
		dbsplnr->tblplnrmface->loadRstByDsnSru(0, sru->ref, true, fces);
		srufceics1.push_back(fces.nodes.size());
	};

	// map ref vs. index of corresponding list
	for (unsigned int i=0;i<vtxs.nodes.size();i++) vtxics[vtxs.nodes[i]->ref] = i;
	for (unsigned int i=0;i<lgs.nodes.size();i++) lgics[lgs.nodes[i]->ref] = i;
	for (unsigned int i=0;i<ags.nodes.size();i++) agics[ags.nodes[i]->ref] = i;
	for (unsigned int i=0;i<srus.nodes.size();i++) sruics[srus.nodes[i]->ref] = i;

	// flag vertices and lineguides that are domainguides
	dbsplnr->tblplnrmdomaingd->loadRstByDsn(refBasedsn, false, dgs);

	for (unsigned int i=0;i<dgs.nodes.size();i++) {
		dg = dgs.nodes[i];

		if ( (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLG) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXAG) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXPRPLG) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLGX) ) {
			// find vertex
			for (unsigned int j=0;j<vtxs.nodes.size();j++) {
				vtx = vtxs.nodes[j];

				if (vtx->sref.compare(dg->sref) == 0) {
					domvtxics.insert(j);
					domvtxics2[dg->sref] = j;
					break;
				};
			};

		} else if ( (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR2) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPAG) || (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPLG) ) {
			// find lineguide
			for (unsigned int j=0;j<lgs.nodes.size();j++) {
				lg = lgs.nodes[j];

				if (lg->sref.compare(dg->sref) == 0) {
					domlgics.insert(j);
					domlgics2[dg->sref] = j;
					break;
				};
			};
		};
	};

	// flag vertices and lineguides that are used in domains
	dbsplnr->tblplnrmdomain->loadRstByDsn(refBasedsn, false, doms);

	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		if (dom->vtx1SrefPlnrMVertex.find('.') != string::npos) {
			if (finddevvtx(dbsplnr, dom->vtx1SrefPlnrMVertex, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domvtxics.insert(vtxics[ref]);
				domvtxics2[dom->vtx1SrefPlnrMVertex] = vtxics[ref];
			};
		};
		if (dom->vtx2SrefPlnrMVertex.find('.') != string::npos) {
			if (finddevvtx(dbsplnr, dom->vtx2SrefPlnrMVertex, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domvtxics.insert(vtxics[ref]);
				domvtxics2[dom->vtx2SrefPlnrMVertex] = vtxics[ref];
			};
		};
		if (dom->vtx3SrefPlnrMVertex.find('.') != string::npos) {
			if (finddevvtx(dbsplnr, dom->vtx3SrefPlnrMVertex, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domvtxics.insert(vtxics[ref]);
				domvtxics2[dom->vtx3SrefPlnrMVertex] = vtxics[ref];
			};
		};
		if (dom->vtx4SrefPlnrMVertex.find('.') != string::npos) {
			if (finddevvtx(dbsplnr, dom->vtx4SrefPlnrMVertex, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domvtxics.insert(vtxics[ref]);
				domvtxics2[dom->vtx4SrefPlnrMVertex] = vtxics[ref];
			};
		};

		if (dom->lgd1SrefPlnrMLineguide.find('.') != string::npos) {
			if (finddevlg(dbsplnr, dom->lgd1SrefPlnrMLineguide, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlgics.insert(lgics[ref]);
				domlgics2[dom->lgd1SrefPlnrMLineguide] = lgics[ref];
			};
		};
		if (dom->lgd2SrefPlnrMLineguide.find('.') != string::npos) {
			if (finddevlg(dbsplnr, dom->lgd2SrefPlnrMLineguide, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlgics.insert(lgics[ref]);
				domlgics2[dom->lgd2SrefPlnrMLineguide] = lgics[ref];
			};
		};
		if (dom->lgd3SrefPlnrMLineguide.find('.') != string::npos) {
			if (finddevlg(dbsplnr, dom->lgd3SrefPlnrMLineguide, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlgics.insert(lgics[ref]);
				domlgics2[dom->lgd3SrefPlnrMLineguide] = lgics[ref];
			};
		};
		if (dom->lgd4SrefPlnrMLineguide.find('.') != string::npos) {
			if (finddevlg(dbsplnr, dom->lgd4SrefPlnrMLineguide, devs, devics2, refBasedsn, refModdsn, refPlnrMDesign, ref)) {
				domlgics.insert(lgics[ref]);
				domlgics2[dom->lgd4SrefPlnrMLineguide] = lgics[ref];
			};
		};
	};

	// find boundaries and calculate linear transform to fit device into width x height (x' = a11*x + b1, y' = a22*y + b2)
	xmin = 1e6; xmax = -1e6;
	ymin = 1e6; ymax = -1e6;

	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		vtx = vtxs.nodes[i];

		if (vtx->x < xmin) xmin = vtx->x;
		if (vtx->x > xmax) xmax = vtx->x;
		if (vtx->y < ymin) ymin = vtx->y;
		if (vtx->y > ymax) ymax = vtx->y;
	};

	// scale and invert y, then translate to (5.0,<center>) or (<center>,5.0)
	a11 = ((double) (width-10)) / (xmax-xmin);
	a22 = ((double) (height-10)) / (ymax-ymin);

	if (a11 < a22) {
		a22 = a11;
		a22 *= -1.0;

		b1 = -a11*xmin + 5.0;
		b2 = -a22*0.5*(ymin+ymax) + 0.5*((double) height);

	} else {
		a11 = a22;
		a22 *= -1.0;

		b1 = -a11*0.5*(xmin+xmax) + 0.5*((double) width);
		b2 = -a22*ymax + 5.0;
	};

	// --- svg element 
	svgfile << "\t\t<svg id=\"svg\" width=\"" << width << "\" height=\"" << height << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

	// --- vertices
	if (showvtxs) {
		svgfile << "\t\t\t<g id=\"vertices\">" << endl;
		for (unsigned int i=0;i<vtxs.nodes.size();i++) {
			vtx = vtxs.nodes[i];

			svgfile << "\t\t\t\t<circle class=\"";
			if (domvtxics.find(i) != domvtxics.end()) {
				svgfile << "dgv";
			} else {
				svgfile << "v";
			};
			svgfile << "\" id=\"" << vtx->sref << "\" cx=\"" << (a11*vtx->x + b1) << "\" cy=\"" << (a22*vtx->y + b2) << "\" r=\"2.0\" onmouseover=\"tt(event, '" << vtx->sref << "(" << vtx->x << "," << vtx->y << ")', '";


			// alternate sref's
			dbsplnr->loadRefsBySQL("SELECT devRefPlnrMVertex FROM TblPlnrRMVertexMVertex WHERE dsnRefPlnrMVertex = " + to_string(vtx->ref), false, refs);
			dbsplnr->tblplnrmvertex->loadRstByRefs(refs, false, vtxs2);

			for (unsigned int j=0;j<vtxs2.nodes.size();j++) {
				vtx2 = vtxs2.nodes[j];

				if (j == 0) {
					svgfile << "origin: ";
				} else {
					svgfile << ",";
				};

				svgfile << devs.nodes[devics[vtx2->hkUref]]->sref << "." << vtx2->sref;
			};

			svgfile << "')\"/>" << endl;
		};
		svgfile << "\t\t\t</g>" << endl;
	};

	if (showgds) {
		// --- lineguides
		svgfile << "\t\t\t<g id=\"lineguides\">" << endl;
		for (unsigned int i=0;i<lgs.nodes.size();i++) {
			lg = lgs.nodes[i];
			dbsplnr->tblplnrlrmlineguidemvertex->loadRstByLgd(lg->ref, false, lrvs);

			if (lrvs.nodes.size() > 1) {
				// find first and last vertices
				vtx = vtxs.nodes[vtxics[lrvs.nodes[0]->refPlnrMVertex]];
				vtx2 = vtxs.nodes[vtxics[lrvs.nodes[lrvs.nodes.size()-1]->refPlnrMVertex]];

				// draw line
				svgfile << "\t\t\t\t<line class=\"";
				if (domlgics.find(i) != domlgics.end()) {
					svgfile << "dgl";
				} else {
					svgfile << "l";
				};
				svgfile << "\" id=\"" << lg->sref << "\" x1=\"" << (a11*vtx->x + b1) << "\" y1=\"" << (a22*vtx->y + b2) << "\" x2=\"" << (a11*vtx2->x + b1) << "\" y2=\"" << (a22*vtx2->y + b2) << "\" onmouseover=\"tt(event, '" << lg->sref << "', '";

				// vertex line-up
				if (lrvs.nodes.size() > 10) {
					svgfile << lrvs.nodes.size() << " vertices";

				} else {
					for (unsigned int j=0;j<lrvs.nodes.size();j++) {
						lrv = lrvs.nodes[j];

						if (j != 0) svgfile << "-";
						svgfile << vtxs.nodes[vtxics[lrv->refPlnrMVertex]]->sref;
					};
				};

				svgfile << "', '";

				// alternate sref's
				dbsplnr->loadRefsBySQL("SELECT devRefPlnrMLineguide FROM TblPlnrRMLineguideMLineguide WHERE dsnRefPlnrMLineguide = " + to_string(lg->ref), false, refs);
				dbsplnr->tblplnrmlineguide->loadRstByRefs(refs, false, lgs2);

				for (unsigned int j=0;j<lgs2.nodes.size();j++) {
					lg2 = lgs2.nodes[j];

					if (j == 0) {
						svgfile << "origin: ";
					} else {
						svgfile << ",";
					};

					svgfile << devs.nodes[devics[lg2->hkUref]]->sref << "." << lg2->sref;
				};

				svgfile << "')\"/>" << endl;
			};
		};
		svgfile << "\t\t\t</g>" << endl;

		// --- arcguides
		svgfile << "\t\t\t<g id=\"arcguides\">" << endl;
		for (unsigned int i=0;i<ags.nodes.size();i++) {
			ag = ags.nodes[i];
			dbsplnr->tblplnrlrmarcguidemvertex->loadRstByAgd(ag->ref, false, arvs);

			vtx = vtxs.nodes[vtxics[ag->ctrRefPlnrMVertex]];

			svgfile << "\t\t\t\t<circle class=\"a\" id=\"" << ag->sref << "\" cx=\"" << (a11*vtx->x + b1) << "\" cy=\"" << (a22*vtx->y + b2) << "\" r=\"" << (a11*ag->r) << "\" onmouseover=\"tt(event, '" << ag->sref << "(" << vtx->sref << ",r=" << ag->r << ")', '";

			// vertex line-up
			if (arvs.nodes.size() > 10) {
				svgfile << arvs.nodes.size() << " vertices";
			
			} else {
				for (unsigned int j=0;j<arvs.nodes.size();j++) {
					arv = arvs.nodes[j];

					if (j != 0) svgfile << "-";
					svgfile << vtxs.nodes[vtxics[arv->refPlnrMVertex]]->sref;
				};
			};

			svgfile << "', '";

			// alternate sref
			dbsplnr->tblplnrmarcguide->loadRecByRef(ag->devRefPlnrMArcguide, &ag2);
			if (ag2) {
				svgfile << "origin: ";
				svgfile << devs.nodes[devics[ag2->hkUref]]->sref << "." << ag2->sref;

				delete ag2;
			};

			svgfile << "')\"/>" << endl;
		};
		svgfile << "\t\t\t</g>" << endl;
	};

	// --- faces
	if (showfces) {
		// re-determine spclyrs and refsLyr
		if (spclyrs) {
			if (refsLyr.size() == 0)
				// load layer refs
				if (dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN) + " AND hkUref = " + to_string(refPlnrMDesign) + " ORDER BY hkNum ASC", false, refsLyr) == 0)
					if (dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN) + " AND hkUref = " + to_string(refBasedsn) + " ORDER BY hkNum ASC", false, refsLyr) == 0)
						if (dbsplnr->loadRefsBySQL("SELECT TblPlnrMLayer.ref FROM TblPlnrMLayer, TblPlnrMStack WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK)
												+ " AND hkUref = TblPlnrMStack.ref AND TblPlnrMStack.dsnRefPlnrMDesign = " + to_string(refPlnrMDesign) + " ORDER BY TblPlnrMStack.dsnNum ASC, TblPlnrMLayer.hkNum ASC", false, refsLyr) == 0)
							dbsplnr->loadRefsBySQL("SELECT TblPlnrMLayer.ref FROM TblPlnrMLayer, TblPlnrMStack WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK)
										+ " AND hkUref = TblPlnrMStack.ref AND TblPlnrMStack.dsnRefPlnrMDesign = " + to_string(refBasedsn) + " ORDER BY TblPlnrMStack.dsnNum ASC, TblPlnrMLayer.hkNum ASC", false, refsLyr);

			// impossible to distinguish more than eight layers by color
			if (refsLyr.size() > 8) spclyrs = false;
		};

		if (!spclyrs) {
			refsLyr.resize(0);
			refsLyr.push_back(0);
		};

		// traverse layers
		for (unsigned int l=0;l<refsLyr.size();l++) {
			refLyr = refsLyr[l];

			if (spclyrs) svgfile << "\t\t\t<g id=\"lyr" << ((char) (97+l)) << "\">" << endl;
			else svgfile << "\t\t\t<g id=\"faces\">" << endl;

			// determine structures to be shown via blocks
			if (spclyrs) dbsplnr->loadRefsBySQL("SELECT refPlnrMStructure FROM TblPlnrMBlock WHERE refPlnrMDesign = " + to_string(refPlnrMDesign) + " AND refPlnrMLayer = " + to_string(refLyr), false, refsSru);
			else dbsplnr->loadRefsBySQL("SELECT refPlnrMStructure FROM TblPlnrMBlock WHERE refPlnrMDesign = " + to_string(refPlnrMDesign), false, refsSru);

			// traverse structures on current layer
			for (unsigned int m=0;m<refsSru.size();m++) {
				sru = srus.nodes[sruics[refsSru[m]]];

				// traverse faces of current structure
				for (unsigned int j=srufceics0[sruics[refsSru[m]]];j<srufceics1[sruics[refsSru[m]]];j++) {
					fce = fces.nodes[j];
					dbsplnr->tblplnrrmfacemvertex->loadRstByFce(fce->ref, false, frvs);

					if (spclyrs) {
						svgfile << "\t\t\t\t<path class=\"f" << ((char) (97+l)) << "\" id=\"ly" << ((char) (97+l)) << fce->sref << "\" d=\"";
					} else {
						svgfile << "\t\t\t\t<path class=\"fa\" id=\"" << fce->sref << "\" d=\"";
					};

					// - vertex path along guides
					for (unsigned int k=0;k<frvs.nodes.size();k++) {
						frv = frvs.nodes[k];
						vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];

						// move to first vertex
						if (k==0) svgfile << "M ";

						// vertex
						svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

						// guide
						if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
							svgfile << " L ";

						} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
							// arcguide radius (x2)
							ag = ags.nodes[agics[frv->rteUref]];
							svgfile << " A " << (a11*ag->r) << "," << (a11*ag->r) << " 0 ";
	
							// large-arc, for now assume all arcs are < 180°
							svgfile << "0 ";
	
							// sweep
							if (frv->ixVDir == VecPlnrVRMFaceMVertexDir::BWD) svgfile << "1 ";
							else svgfile << "0 ";
						};

						if (k == (frvs.nodes.size()-1)) {
							// close to first vertex
							vtx = vtxs.nodes[vtxics[frvs.nodes[0]->refPlnrMVertex]];
							svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);
						};
					};

					svgfile << "\" onmouseover=\"tt(event, '" << fce->sref << "', '";

					// - vertex path in tooltip
					if (frvs.nodes.size() > 10) {
						svgfile << frvs.nodes.size() << " segments";
					} else {
						for (unsigned int k=0;k<frvs.nodes.size();k++) {
							frv = frvs.nodes[k];

							// vertex
							vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];
							svgfile << vtx->sref;

							// guide
							svgfile << "(";
							if (frv->ixVDir == VecPlnrVRMFaceMVertexDir::BWD) svgfile << "/";

							if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
								lg = lgs.nodes[lgics[frv->rteUref]];
								svgfile << lg->sref;
		
							} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
								ag = ags.nodes[agics[frv->rteUref]];
								svgfile << ag->sref;
							};

							svgfile << ")";
						};
					};

					svgfile << "', '";

					// alternate sref
					dbsplnr->tblplnrmface->loadRecByRef(fce->devRefPlnrMFace, &fce2);
					if (fce2) {
						svgfile << "origin: ";
						svgfile << srus.nodes[sruics[fce->sruRefPlnrMStructure]]->sref << "." << fce2->sref;

						delete fce2;
					};

					svgfile << "')\"/>" << endl;
				};
			};

			svgfile << "\t\t\t</g>" << endl;
		};
	};

	// --- domains
	if (showdoms) {
		svgfile << "\t\t\t<g id=\"domains\">" << endl;

		for (unsigned int i=0;i<doms.nodes.size();i++) {
			dom = doms.nodes[i];

			if ( (dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XY) ) {
				// display cub_xyz, xybox_xyz, xybox_xy as area
				svgfile << "\t\t\t\t<path class=\"dombox\" id=\"";
				svgfile << dom->sref;

				svgfile << "\" d=\"M ";
				vtx = vtxs.nodes[domvtxics2[dom->vtx1SrefPlnrMVertex]];
				svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

				svgfile << " L ";
				vtx = vtxs.nodes[domvtxics2[dom->vtx2SrefPlnrMVertex]];
				svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

				svgfile << " L ";
				vtx = vtxs.nodes[domvtxics2[dom->vtx3SrefPlnrMVertex]];
				svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

				svgfile << " L ";
				vtx = vtxs.nodes[domvtxics2[dom->vtx4SrefPlnrMVertex]];
				svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

				svgfile << " L ";
				vtx = vtxs.nodes[domvtxics2[dom->vtx1SrefPlnrMVertex]];
				svgfile << (a11*vtx->x + b1) << "," << (a22*vtx->y + b2);

				svgfile << "\" onmouseover=\"tt(event, '" << dom->sref << "(" << VecPlnrVMDomainBasetype::getSref(dom->ixVBasetype) << ")', '";
				svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")";
				svgfile << dom->vtx2SrefPlnrMVertex << "(" << dom->lgd2SrefPlnrMLineguide << ")";
				svgfile << dom->vtx3SrefPlnrMVertex << "(" << dom->lgd3SrefPlnrMLineguide << ")";
				svgfile << dom->vtx4SrefPlnrMVertex << "(" << dom->lgd4SrefPlnrMLineguide << ")";

				svgfile << "', '";
				if (dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) svgfile << "z=[" << dom->flrSrefPlnrMLevel << "," << dom->ceilSrefPlnrMLevel << "]";
				else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) svgfile << "z=" << dom->flrSrefPlnrMLevel;
				svgfile << "')\"/>" << endl;

			} else if ( (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY) ) {
				// display zcsbox_xyz, xyline_xyz, xyline_xy as line
				svgfile << "\t\t\t\t<line class=\"domline\" id=\"";
				svgfile << dom->sref;

				vtx = vtxs.nodes[domvtxics2[dom->vtx1SrefPlnrMVertex]];
				svgfile << "\" x1=\"" << (a11*vtx->x + b1) << "\" y1=\"" << (a22*vtx->y + b2) << "\"";

				vtx = vtxs.nodes[domvtxics2[dom->vtx2SrefPlnrMVertex]];
				svgfile << " x2=\"" << (a11*vtx->x + b1) << "\" y2=\"" << (a22*vtx->y + b2) << "\"";

				svgfile << " onmouseover=\"tt(event, '" << dom->sref << "(" << VecPlnrVMDomainBasetype::getSref(dom->ixVBasetype) << ")', '";
				svgfile << dom->vtx1SrefPlnrMVertex << "(" << dom->lgd1SrefPlnrMLineguide << ")" << dom->vtx2SrefPlnrMVertex;

				svgfile << "', '";
				if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) svgfile << "z=[" << dom->flrSrefPlnrMLevel << "," << dom->ceilSrefPlnrMLevel << "]";
				else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) svgfile << "z=" << dom->flrSrefPlnrMLevel;
				svgfile << "')\"/>" << endl;

			} else if ( (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XY) ) {
				// display zline_xyz, point_xyz, point_xy as dot
				svgfile << "\t\t\t\t<circle class=\"dompoint\" id=\"";
				svgfile << dom->sref;
				
				vtx = vtxs.nodes[domvtxics2[dom->vtx1SrefPlnrMVertex]];
				svgfile << "\" cx=\"" << (a11*vtx->x + b1) << "\" cy=\"" << (a22*vtx->y + b2) << "\" r=\"2.0\"";

				svgfile << " onmouseover=\"tt(event, '" << dom->sref << "(" << VecPlnrVMDomainBasetype::getSref(dom->ixVBasetype) << ")', '";
				svgfile << dom->vtx1SrefPlnrMVertex;

				svgfile << "', '";
				if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) svgfile << "z=[" << dom->flrSrefPlnrMLevel << "," << dom->ceilSrefPlnrMLevel << "]";
				else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) svgfile << "z=" << dom->flrSrefPlnrMLevel;
				svgfile << "')\"/>" << endl;
			};
		};

		svgfile << "\t\t\t</g>" << endl;
	};

	// --- data overlay
	if (datSrefDom.length() > 0) {
		// find domain
		found = false;
		for (unsigned int i=0;i<doms.nodes.size();i++) {
			dom = doms.nodes[i];

			if (dom->sref.compare(datSrefDom) == 0) {
				if ((dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XY)) found = true;
				break;
			};
		};

		if (found) {
			vtx1 = vtxs.nodes[domvtxics2[dom->vtx1SrefPlnrMVertex]];
			vtx2 = vtxs.nodes[domvtxics2[dom->vtx2SrefPlnrMVertex]];
			vtx4 = vtxs.nodes[domvtxics2[dom->vtx4SrefPlnrMVertex]];

			w = a11*sqrt(pow(vtx2->x-vtx1->x, 2) + pow(vtx2->y-vtx1->y, 2));
			h = a11*sqrt(pow(vtx4->x-vtx1->x, 2) + pow(vtx4->y-vtx1->y, 2));
			phi = -radToDeg(atan2(vtx2->y-vtx1->y, vtx2->x-vtx1->x));

			svgfile << "\t\t\t<g id=\"dat\" style=\"opacity:.5\" transform=\"translate(" << (a11*vtx4->x + b1) << "," << (a22*vtx4->y + b2) << ") rotate(" << phi << ")\">" << endl;
			svgfile << "\t\t\t\t<image x=\"0\" y=\"0\" width=\"" << w << "px\" height=\"" << h << "px\" preserveAspectRatio=\"none\" xlink:href=\"" << datPngpath << "\" onmouseover=\"tt(event, '" << datTit << "')\"/>" << endl;
			svgfile << "\t\t\t</g>" << endl;
		};
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
bool PlnrPlotDsnxysvg::finddevvtx(
			DbsPlnr* dbsplnr
			, const string& sref
			, const ListPlnrMDevice& devs
			, map<string, unsigned int>& devics2
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMDesign
			, ubigint& ref
		) {
	PlnrMDevice* dev = NULL;

	dev = devs.nodes[devics2[sref.substr(0, sref.find('.'))]];

	if (!dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE x0RefPlnrMDesign = " + to_string(refModdsn) + " AND hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV)
							+ " AND hkUref = " + to_string(dev->ref) + " AND sref = '" + sref.substr(sref.find('.')+1) + "'", ref))
		dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMVertex WHERE x0RefPlnrMDesign = 0 AND hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = "
					+ to_string(dev->ref) + " AND sref = '" + sref.substr(sref.find('.')+1) + "'", ref);
	
	if (dbsplnr->loadUbigintBySQL("SELECT TblPlnrMVertex.ref FROM TblPlnrMVertex, TblPlnrRMVertexMVertex WHERE TblPlnrMVertex.ref = TblPlnrRMVertexMVertex.dsnRefPlnrMVertex AND TblPlnrMVertex.hkIxVTbl = "
				+ to_string(VecPlnrVMVertexHkTbl::DSN) + " AND TblPlnrMVertex.hkUref = " + to_string(refPlnrMDesign) + " AND TblPlnrRMVertexMVertex.devRefPlnrMVertex = " + to_string(ref), ref)) return true;

	return false;
};

bool PlnrPlotDsnxysvg::finddevlg(
			DbsPlnr* dbsplnr
			, const string& sref
			, const ListPlnrMDevice& devs
			, map<string, unsigned int>& devics2
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMDesign
			, ubigint& ref
		) {
	PlnrMDevice* dev = NULL;

	dev = devs.nodes[devics2[sref.substr(0, sref.find('.'))]];

	if (!dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE x0RefPlnrMDesign = " + to_string(refModdsn) + " AND hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV)
							+ " AND hkUref = " + to_string(dev->ref) + " AND sref = '" + sref.substr(sref.find('.')+1) + "'", ref))
		dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMLineguide WHERE x0RefPlnrMDesign = 0 AND hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = "
					+ to_string(dev->ref) + " AND sref = '" + sref.substr(sref.find('.')+1) + "'", ref);

	if (dbsplnr->loadUbigintBySQL("SELECT TblPlnrMLineguide.ref FROM TblPlnrMLineguide, TblPlnrRMLineguideMLineguide WHERE TblPlnrMLineguide.ref = TblPlnrRMLineguideMLineguide.dsnRefPlnrMLineguide AND TblPlnrMLineguide.hkIxVTbl = "
				+ to_string(VecPlnrVMLineguideHkTbl::DSN) + " AND TblPlnrMLineguide.hkUref = " + to_string(refPlnrMDesign) + " AND TblPlnrRMLineguideMLineguide.devRefPlnrMLineguide = " + to_string(ref), ref)) return true;

	return false;
};
// IP cust --- IEND


