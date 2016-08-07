/**
  * \file PlnrPlotDevsvg.cpp
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

#include "PlnrPlotDevsvg.h"

DpchRetPlnrPlotDevsvg* PlnrPlotDevsvg::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotDevsvg* dpchinv
		) {
	DpchRetPlnrPlotDevsvg* dpchret = new DpchRetPlnrPlotDevsvg();

	uint height = dpchinv->height;
	ubigint refBasedsn = dpchinv->refBasedsn;
	ubigint refModdsn = dpchinv->refModdsn;
	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;
	vector<ubigint> refsSru = dpchinv->refsSru;
	vector<ubigint> refsSubdev = dpchinv->refsSubdev;
	bool showfces = dpchinv->showfces;
	bool showgds = dpchinv->showgds;
	bool showvtxs = dpchinv->showvtxs;
	uint width = dpchinv->width;

// IP run --- IBEGIN
	ostringstream str;
	bool found, first;
	unsigned int cnt;

	string svgpath;
	fstream svgfile;

	ListPlnrMVertex vtxs;
	PlnrMVertex* vtx = NULL;
	PlnrMVertex* vtx2 = NULL;
	vector<bool> vtxacts;
	map<ubigint, unsigned int> vtxics;

	ListPlnrMLineguide lgs;
	PlnrMLineguide* lg = NULL;
	vector<bool> lgacts;
	map<ubigint, unsigned int> lgics;

	ListPlnrLRMLineguideMVertex lrvs;
	PlnrLRMLineguideMVertex* lrv = NULL;
	vector<bool> lrvacts;

	ListPlnrMArcguide ags;
	PlnrMArcguide* ag = NULL;
	vector<bool> agacts;
	map<ubigint, unsigned int> agics;

	ListPlnrLRMArcguideMVertex arvs;
	PlnrLRMArcguideMVertex* arv = NULL;
	vector<bool> arvacts;

	ListPlnrMStructure srus;
	PlnrMStructure* sru = NULL;
	map<ubigint, unsigned int> sruics;

	vector<unsigned int> srufceics0;
	vector<unsigned int> srufceics1;

	ubigint refSru;

	ListPlnrMFace fces;
	PlnrMFace* fce = NULL;
	vector<bool> fceacts;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	double xmin, xmax, ymin, ymax;
	double a11, a22, b1, b2;

	// generate file in temp folder and open
	svgpath = Tmp::newfile(xchg->tmppath, "xml");
	str.str(""); str << xchg->tmppath << "/" << svgpath;

	svgfile.open(str.str().c_str(), ios::out);
	svgfile.setf(ios::fixed);
	svgfile.precision(3);
	writeSvgHeader(svgfile);

	// load device primitives
	Plnr::getDeviceExp(dbsplnr, refPlnrMDevice, refBasedsn, refModdsn, refsSubdev, true, vtxs, vtxacts, lgs, lgacts, ags, agacts, srus, srufceics0, srufceics1, fces, fceacts);

	// map ref vs. index of corresponding list
	for (unsigned int i=0;i<vtxs.nodes.size();i++) vtxics[vtxs.nodes[i]->ref] = i;
	for (unsigned int i=0;i<lgs.nodes.size();i++) lgics[lgs.nodes[i]->ref] = i;
	for (unsigned int i=0;i<ags.nodes.size();i++) agics[ags.nodes[i]->ref] = i;
	for (unsigned int i=0;i<srus.nodes.size();i++) sruics[srus.nodes[i]->ref] = i;

	// find boundaries and calculate linear transform to fit device into w x h (x' = a11*x + b1, y' = a22*y + b2)
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
			if (vtxacts[i]) {
				vtx = vtxs.nodes[i];

				svgfile << "\t\t\t\t<circle class=\"v\" id=\"" << vtx->sref << "\" cx=\"" << (a11*vtx->x + b1) << "\" cy=\"" << (a22*vtx->y + b2) << "\" r=\"2.0\" onmouseover=\"tt(event, '" << vtx->sref << "(" << vtx->x << "," << vtx->y << ")')\"/>" << endl;
			};
		};
		svgfile << "\t\t\t</g>" << endl;
	};

	if (showgds) {
		// --- lineguides
		svgfile << "\t\t\t<g id=\"lineguides\">" << endl;
		for (unsigned int i=0;i<lgs.nodes.size();i++) {
			if (lgacts[i]) {
				lg = lgs.nodes[i];
				Plnr::getLrvExp(dbsplnr, lg->ref, refsSubdev, true, lrvs, lrvacts);

				// find first and last active vertices
				found = false;
				for (unsigned int j=0;j<lrvacts.size();j++) {
					if (lrvacts[j]) {
						vtx = vtxs.nodes[vtxics[lrvs.nodes[j]->refPlnrMVertex]];

						found = true;
						break;
					};
				};

				if (found) {
					found = false;
					for (unsigned int j=lrvacts.size()-1;j>=0;j--) {
						if (lrvacts[j]) {
							vtx2 = vtxs.nodes[vtxics[lrvs.nodes[j]->refPlnrMVertex]];

							found = true;
							break;
						};
					};
				};

				if (found && (vtx != vtx2)) {
					// draw line
					svgfile << "\t\t\t\t<line class=\"l\" id=\"" << lg->sref << "\" x1=\"" << (a11*vtx->x + b1) << "\" y1=\"" << (a22*vtx->y + b2) << "\" x2=\"" << (a11*vtx2->x + b1) << "\" y2=\"" << (a22*vtx2->y + b2) << "\" onmouseover=\"tt(event, '" << lg->sref << "', '";

					// vertex line-up
					cnt = 0;
					for (unsigned int j=0;j<lrvs.nodes.size();j++) if (lrvacts[j]) cnt++;

					if (cnt > 10) {
						svgfile << cnt << " vertices";
					} else {
						first = true;
						for (unsigned int j=0;j<lrvs.nodes.size();j++) {
							if (lrvacts[j]) {
								lrv = lrvs.nodes[j];

								if (first) {
									first = false;
								} else {
									svgfile << "-";
								};

								svgfile << vtxs.nodes[vtxics[lrv->refPlnrMVertex]]->sref;
							};
						};
					};

					svgfile << "')\"/>" << endl;
				};
			};
		};
		svgfile << "\t\t\t</g>" << endl;

		// --- arcguides
		svgfile << "\t\t\t<g id=\"arcguides\">" << endl;
		for (unsigned int i=0;i<ags.nodes.size();i++) {
			if (agacts[i]) {
				ag = ags.nodes[i];
				Plnr::getArvExp(dbsplnr, ag->ref, refsSubdev, true, arvs, arvacts);
				vtx = vtxs.nodes[vtxics[ag->ctrRefPlnrMVertex]];

				svgfile << "\t\t\t\t<circle class=\"a\" id=\"" << ag->sref << "\" cx=\"" << (a11*vtx->x + b1) << "\" cy=\"" << (a22*vtx->y + b2) << "\" r=\"" << (a11*ag->r) << "\" onmouseover=\"tt(event, '" << ag->sref << "(" << vtx->sref << ",r=" << ag->r << ")', '";

				// vertex line-up
				cnt = 0;
				for (unsigned int j=0;j<arvs.nodes.size();j++) if (arvacts[j]) cnt++;

				if (cnt > 10) {
					svgfile << cnt << " vertices";
				} else {
					first = true;
					for (unsigned int j=0;j<arvs.nodes.size();j++) {
						if (arvacts[j]) {
							arv = arvs.nodes[j];

							if (first) {
								first = false;
							} else {
								svgfile << "-";
							};

							svgfile << vtxs.nodes[vtxics[arv->refPlnrMVertex]]->sref;
						};
					};
				};

				svgfile << "')\"/>" << endl;
			};
		};
		svgfile << "\t\t\t</g>" << endl;
	};

	// --- faces (by structure)
	if (showfces) {
		svgfile << "\t\t\t<g id=\"faces\">" << endl;
		for (unsigned int i=0;i<refsSru.size();i++) {
			refSru = refsSru[i];

			sru = srus.nodes[sruics[refSru]];
			for (unsigned int j=srufceics0[sruics[refSru]];j<srufceics1[sruics[refSru]];j++) {
				if (fceacts[j]) {
					fce = fces.nodes[j];
					dbsplnr->tblplnrrmfacemvertex->loadRstByFce(fce->ref, false, frvs);

					svgfile << "\t\t\t\t<path class=\"f\" id=\"" << fce->sref << "\" d=\"";

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

					svgfile << "\" onmouseover=\"tt(event, '" << sru->sref << "." << fce->sref << "', '";

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

					svgfile << "')\"/>" << endl;
				};
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

// IP cust --- INSERT


