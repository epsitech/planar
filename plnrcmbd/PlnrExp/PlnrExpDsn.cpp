/**
  * \file PlnrExpDsn.cpp
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

#include "PlnrExpDsn.h"

DpchRetPlnr* PlnrExpDsn::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpDsn* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;

// IP run --- IBEGIN
	// expand single design (does not include modified sub-designs in case of base design)

	ostringstream str;
	vector<ubigint> refs;
	ubigint ref;
	uint num;
	bool found;

	map<string, string> env; // dummy

	PlnrMDesign* dsn = NULL;
	ubigint refBasedsn, refModdsn;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	ListPlnrMStack stks;
	PlnrMStack* stk = NULL;

	vector<ubigint> refsSubdev;

	bool expxy, expz;

	// device vertices
	ListPlnrMVertex devvtxs;
	PlnrMVertex* devvtx = NULL;
	vector<bool> devvtxacts;

	// device lineguides
	ListPlnrMLineguide devlgs;
	PlnrMLineguide* devlg = NULL;
	vector<bool> devlgacts;

	ListPlnrLRMLineguideMVertex devlrvs;
	PlnrLRMLineguideMVertex* devlrv = NULL;
	vector<bool> devlrvacts;

	// device arcguides
	ListPlnrMArcguide devags;
	PlnrMArcguide* devag = NULL;
	vector<bool> devagacts;

	ListPlnrLRMArcguideMVertex devarvs;
	PlnrLRMArcguideMVertex* devarv = NULL;
	vector<bool> devarvacts;

	// device structures
	ListPlnrMStructure devsrus;
	PlnrMStructure* devsru = NULL;

	vector<unsigned int> devsrufceics0; // index to devfces
	vector<unsigned int> devsrufceics1; // index to devfces

	// device faces
	ListPlnrMFace devfces;
	PlnrMFace* devfce = NULL;
	vector<bool> devfceacts;

	// design vertices
	ListPlnrMVertex vtxs;
	PlnrMVertex* vtx = NULL;
	PlnrMVertex* vtx2 = NULL;
	uint vtxcnt = 0;

	// design lineguides
	ListPlnrMLineguide lgs;
	PlnrMLineguide* lg = NULL;
	PlnrMLineguide* lg2 = NULL;
	uint lgcnt = 0;

	ListPlnrLRMLineguideMVertex lrvs;
	ListPlnrLRMLineguideMVertex lrvs2;
	PlnrLRMLineguideMVertex* lrv = NULL;
	uint lrvcnt;

	// design arcguides
	ListPlnrMArcguide ags;
	PlnrMArcguide* ag = NULL;
	uint agcnt = 0;
	unsigned int vcix;

	ListPlnrLRMArcguideMVertex arvs;
	PlnrLRMArcguideMVertex* arv = NULL;
	uint arvcnt;

	// design structures
	ListPlnrMStructure srus;
	PlnrMStructure* sru = NULL;

	// design faces
	ListPlnrMFace fces;
	PlnrMFace* fce = NULL;
	uint fcecnt = 0;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	vector<unsigned int> vics;
	vector<unsigned int> icsRte;
	vector<unsigned int> gics;
	vector<unsigned int> icsDir;

	// stack levels
	ListPlnrMLevel stklvls;
	PlnrMLevel* stklvl = NULL;

	// stack layers
	ListPlnrMLayer stklyrs;
	PlnrMLayer* stklyr = NULL;

	// design levels
	ListPlnrMLevel lvls;
	PlnrMLevel* lvl = NULL;
	PlnrMLevel* lvl2 = NULL;
	uint lvlcnt = 0;

	// design layers
	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	// xy vs. z
	ListPlnrRMStackMStructure srss;
	PlnrRMStackMStructure* srs = NULL;

	ListPlnrRMLayerMStructure lrss;
	PlnrRMLayerMStructure* lrs = NULL;

	ListPlnrMBlock blks;
	PlnrMBlock* blk = NULL;

	// domains
	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;

	// domain guides
	ListPlnrMDomaingd dgs;
	PlnrMDomaingd* dg = NULL;

	PlnrJMDomaingd* dgj = NULL;

	PlnrMVertex* dgvtx = NULL;
	set<unsigned int> dgvtxics; // index to vtxs

	PlnrMLineguide* dglg = NULL;
	set<unsigned int> dglgics; // index to lgs

	map<string, double> dglgx0s;
	map<string, double> dglgy0s;
	map<string, double> dglgdxs;
	map<string, double> dglgdys;

	PlnrMLevel* dglvl = NULL;
	set<unsigned int> dglvlics; // index to lvls

	// snap
	const double xysnapnorm = 1e-4 * 1e-4;
	const double zsnapnorm = 1e-5 * 1e-5;
	bool snap;

	vector<bool> vtxacts;

	map<ubigint, unsigned int> dsnvtxics; // TblPlnrMVertex[DSN].ref -> ix(vtxs)

	vector<bool> lgacts;

	bool flip;
	double lam, lam0, lam1, lam2;
	double lam12;

	vector<double> lgdxs;
	vector<double> lgdys;
	vector<double> lglam1s;

	vector<unsigned int> lrvix0s; // index to lrvs
	vector<unsigned int> lrvix1s; // index to lrvs
	unsigned int lrvix;

	vector<unsigned int> lgvtxics; // index to vtxs
	vector<unsigned int> lgvtxics2; // index to vtxs
	vector<double> lgvtxlams;
	vector<double> lgvtxlams2;

	vector<unsigned int> agvtxics; // index to vtxs
	vector<double> agvtxlams;

	vector<bool> lvlacts;

	// mapping device - design
	map<string, unsigned int> devvtxics; // TblPlnrMVertex[DEV].sref -> ix(devvtxs)

	map<string, unsigned int> vtxics; // TblPlnrMVertex[DEV].sref -> ix(vtxs) (accumulated with TblPlnrMDevice.sref)
	map<ubigint, ubigint> devvtxdsnrefs; // TblPlnrMVertex[DEV].ref -> TblPlnrMVertex[DSN].ref
	map<ubigint, unsigned int> devvtxdsnics; // TblPlnrMVertex[DEV].ref -> ix(vtxs)

	map<string, unsigned int> lgics; // TblPlnrMLineguide[DEV].sref -> ix(lgs) (accumulated with TblPlnrMDevice.sref)
	map<ubigint, ubigint> devlgdsnrefs; // TblPlnrMLineguide[DEV].ref -> TblPlnrMLineguide[DSN].ref

	map<string, unsigned int> agics; // TblPlnrMArcguide[DEV].sref -> ix(ags) (accumulated with TblPlnrMDevice.sref)
	map<ubigint, ubigint> devagdsnrefs; // TblPlnrMArcguide[DEV].ref -> TblPlnrMArcguide[DSN].ref

	map<ubigint, ubigint> devsrudsnrefs; // TblPlnrMStructure[DEV].ref -> TblPlnrMStructure[DSN].ref (accumulated)

	map<ubigint, ubigint> devfcedsnrefs; // TblPlnrMFace[DEVSRU].ref -> TblPlnrMFace[DSNSRU].ref

	// mapping stack - design
	map<string, unsigned int> lvlics; // TblPlnrMLevel[STK].sref -> ix(lvls) (accumulated with TblPlnrMStack.sref)
	map<ubigint, ubigint> stklvldsnrefs; // TblPlnrMLevel[STK].ref -> TblPlnrMLevel[DSN].ref

	map<string, unsigned int> stklyrics; // TblPlnrMLayer[STK].sref -> refs (TblPlnrMLayer[DSN].ref)

	// other
	unsigned int ixAv1, ixAv2; // indices to devvtxs
	unsigned int ixPav1, ixPav2; // indices to vtxs

	double phi, cphi, sphi, x, y, x0, y0, d, dphi;
	double dx, dy, dz, dxp, dyp;
	double x02, y02, dx2, dy2;

	bool ffill, cfill;

	// load design
	dbsplnr->tblplnrmdesign->loadRecByRef(refPlnrMDesign, &dsn);

	if (dsn->modRefPlnrMDesign == 0) {
		refBasedsn = refPlnrMDesign;
		refModdsn = 0;

		expxy = (dsn->ixVDim != VecPlnrVMDesignDim::Z);
		expz = (dsn->ixVDim != VecPlnrVMDesignDim::XY);

	} else {
		refBasedsn = dsn->modRefPlnrMDesign;
		refModdsn = refPlnrMDesign;

		// determine which of xy and z expansion are required
		expxy = (dsn->ixWModtype & (VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO + VecPlnrWMDesignModtype::DOMXY));
		expz = (dsn->ixWModtype & (VecPlnrWMDesignModtype::SNOLN + VecPlnrWMDesignModtype::SLN + VecPlnrWMDesignModtype::MLT + VecPlnrWMDesignModtype::DOMZ));
	};

	// collapse if expanded
	//collapseDesign(dbsplnr, refPlnrMDesign);

	// load (expanded) devices and stacks
	dbsplnr->tblplnrmdevice->loadRstByDsnSup(refBasedsn, 0, false, devs);
	dbsplnr->tblplnrmstack->loadRstByDsn(refBasedsn, false, stks);

	// load domains and domainguides with mod design override
	dbsplnr->tblplnrmdomain->loadRstByDsn(refBasedsn, false, doms);

	dbsplnr->tblplnrmdomaingd->loadRstByDsn(refBasedsn, false, dgs);
	for (unsigned int i=0;i<dgs.nodes.size();i++) {
		dg = dgs.nodes[i];

		// take into account envdft(...) entries for base design
		dg->d = Fct::evalDgdD(env, dg, true);
		dg->dphi = Fct::evalDgdDph(env, dg, true);

		if (dbsplnr->tblplnrjmdomaingd->loadRecByDgdDsn(dg->ref, refModdsn, &dgj)) {
			dg->d = dgj->d;
			dg->dphi = dgj->dphi;

			delete dgj;
		};
	};

	if (expxy) {
		dbsplnr->begin();

		// --- add (expanded) devices
		for (unsigned int i=0;i<devs.nodes.size();i++) {
			dev = devs.nodes[i];

			// load sub-device ref's
			dbsplnr->tblplnrmdevice->loadRefsBySup(dev->ref, false, refsSubdev);

			// load device expansion including design modifications and all sub-devices
			Plnr::getDeviceExp(dbsplnr, dev->ref, refBasedsn, refModdsn, refsSubdev, true, devvtxs, devvtxacts, devlgs, devlgacts, devags, devagacts, devsrus, devsrufceics0, devsrufceics1, devfces, devfceacts);

			// -- vertices

			// - generate device sref mapping (<-)
			for (unsigned int j=0;j<devvtxs.nodes.size();j++) {
				if (devvtxacts[j]) {
					devvtx = devvtxs.nodes[j];
					devvtxics[devvtx->sref] = j;
				};
			};

			// - align with design

			// determine coefficients for matrix transform according to align type
			cphi = 1.0;
			sphi = 0.0;
			x0 = 0.0;
			y0 = 0.0;

			if (dev->ixVAligntype == VecPlnrVMDeviceAligntype::RDEV) {
				// find align vertices 1,2 in device vertices (by srefs)
				if ((devvtxics.find(dev->av1SrefPlnrMVertex) != devvtxics.end()) && (devvtxics.find(dev->av2SrefPlnrMVertex) != devvtxics.end())) {
					ixAv1 = devvtxics[dev->av1SrefPlnrMVertex];
					ixAv2 = devvtxics[dev->av2SrefPlnrMVertex];

					// find partner align vertices 1,2 in design vertices (by srefs)
					if ((vtxics.find(dev->pav1SrefPlnrMVertex) != vtxics.end()) && (vtxics.find(dev->pav2SrefPlnrMVertex) != vtxics.end())) {
						ixPav1 = vtxics[dev->pav1SrefPlnrMVertex];
						ixPav2 = vtxics[dev->pav2SrefPlnrMVertex];

						dx = devvtxs.nodes[ixAv2]->x - devvtxs.nodes[ixAv1]->x; // xav2 - xav1
						dy = devvtxs.nodes[ixAv2]->y - devvtxs.nodes[ixAv1]->y; // yav2 - yav1

						dxp = vtxs.nodes[ixPav2]->x - vtxs.nodes[ixPav1]->x; // xpav2 - xpav1
						dyp = vtxs.nodes[ixPav2]->y - vtxs.nodes[ixPav1]->y; // ypav2 - ypav1

						// rotation angle
						phi = atan2(dyp, dxp) - atan2(dy, dx);
						sphi = sin(phi);
						cphi = cos(phi);

						// translation after rotation is applied to av1
						x0 = (cphi*devvtxs.nodes[ixAv1]->x - sphi*devvtxs.nodes[ixAv1]->y) - vtxs.nodes[ixPav1]->x;
						y0 = (sphi*devvtxs.nodes[ixAv1]->x + cphi*devvtxs.nodes[ixAv1]->y) - vtxs.nodes[ixPav1]->y;
					};
				};

			} else if (dev->ixVAligntype == VecPlnrVMDeviceAligntype::ABS) {
				// find align vertex 1 in device vertices (by sref)
				if (devvtxics.find(dev->av1SrefPlnrMVertex) != devvtxics.end()) {
					ixAv1 = devvtxics[dev->av1SrefPlnrMVertex];

					// rotation from value specified
					cphi = cos(degToRad(dev->phi));
					sphi = sin(degToRad(dev->phi));

					// translation after rotation is applied to av1
					x0 = (cphi*devvtxs.nodes[ixAv1]->x - sphi*devvtxs.nodes[ixAv1]->y) - dev->x;
					y0 = (sphi*devvtxs.nodes[ixAv1]->x + cphi*devvtxs.nodes[ixAv1]->y) - dev->y;
				};
			};

			// perform actual transform on all device vertices
			for (unsigned int j=0;j<devvtxs.nodes.size();j++) {
				if (devvtxacts[j]) {
					devvtx = devvtxs.nodes[j];

					x = cphi*devvtx->x - sphi*devvtx->y - x0;
					y = sphi*devvtx->x + cphi*devvtx->y - y0;

					devvtx->x = x;
					devvtx->y = y;
				};
			};

			// - add to design vertices, generate ref mapping
			for (unsigned int j=0;j<devvtxs.nodes.size();j++) {
				if (devvtxacts[j]) {
					devvtx = devvtxs.nodes[j];

					str.str(""); str << "v" << vtxcnt;

					vtx = addVertex(dbsplnr, 0, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, str.str(), devvtx->x, devvtx->y, vtxs);
					addVtxVtx(dbsplnr, devvtx->ref, vtx->ref);

					devvtxdsnrefs[devvtx->ref] = vtxs.nodes[vtxcnt]->ref;
					devvtxdsnics[devvtx->ref] = vtxcnt;

					// add to design sref mapping (<-)
					str.str(""); str << dev->sref << "." << devvtx->sref;
					vtxics[str.str()] = vtxcnt;

					vtxcnt++;
				};
			};

			// -- lineguides

			// - add to design lineguides, generate ref mapping
			for (unsigned int j=0;j<devlgs.nodes.size();j++) {
				if (devlgacts[j]) {
					devlg = devlgs.nodes[j];

					str.str(""); str << "l" << lgcnt;

					vics.resize(0);
					lg = addLineguideByVics(dbsplnr, 0, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, str.str(), vics, vtxs, lgs); // vics empty, vtxs not used (lineguide-vertices filled in next section)
					addLgdLgd(dbsplnr, devlg->ref, lg->ref);

					devlgdsnrefs[devlg->ref] = lgs.nodes[lgcnt]->ref;

					// add to design sref mapping (<-)
					str.str(""); str << dev->sref << "." << devlg->sref;
					lgics[str.str()] = lgcnt;

					lgcnt++;
				};
			};

			// - copy lineguide-vertices
			for (unsigned int j=0;j<devlgs.nodes.size();j++) {
				if (devlgacts[j]) {
					devlg = devlgs.nodes[j];

					Plnr::getLrvExp(dbsplnr, devlg->ref, refsSubdev, true, devlrvs, devlrvacts);

					// add to design lineguide-vertices (adapt lineguide and vertex ref's)
					lrvcnt = 0;
					for (unsigned int k=0;k<devlrvs.nodes.size();k++) {
						if (devlrvacts[k]) {
							devlrv = devlrvs.nodes[k];

							lrvcnt++;
							lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, devlgdsnrefs[devlrv->lgdRefPlnrMLineguide], lrvcnt, devvtxdsnrefs[devlrv->refPlnrMVertex]);
							dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);
						};
					};
				};
			};

			// -- arcguides

			// - add to design arcguides (adapt center vertex ref), generate ref mapping
			for (unsigned int j=0;j<devags.nodes.size();j++) {
				if (devagacts[j]) {
					devag = devags.nodes[j];

					str.str(""); str << "a" << agcnt;

					// find center vertex index
					ref = devvtxdsnrefs[devag->ctrRefPlnrMVertex];
					vcix = 0;
					for (unsigned int k=0;k<vtxs.nodes.size();k++) {
						vtx = vtxs.nodes[k];

						if (vtx->ref == ref) {
							vcix = k;
							break;
						};
					};

					vics.resize(0);
					ag = addArcguideByVics(dbsplnr, 0, VecPlnrVMArcguideHkTbl::DSN, refPlnrMDesign, str.str(), vcix, devag->r, vics, vtxs, ags);
					ag->devRefPlnrMArcguide = devag->ref; dbsplnr->tblplnrmarcguide->updateRec(ag);

					devagdsnrefs[devag->ref] = ags.nodes[agcnt]->ref;

					// add to design sref mapping (<-)
					str.str(""); str << dev->sref << "." << ag->sref;
					agics[str.str()] = agcnt;

					agcnt++;
				};
			};

			// - copy arcguide-vertices
			for (unsigned int j=0;j<devags.nodes.size();j++) {
				if (devagacts[j]) {
					devag = devags.nodes[j];

					Plnr::getArvExp(dbsplnr, devag->ref, refsSubdev, true, devarvs, devarvacts);

					// add to design arcguide-vertices (adapt arcguide and vertex ref's)
					arvcnt = 0;
					for (unsigned int k=0;k<devarvs.nodes.size();k++) {
						if (devarvacts[k]) {
							devarv = devarvs.nodes[k];

							arvcnt++;
							arv = new PlnrLRMArcguideMVertex(0, VecPlnrVLat::INI, devagdsnrefs[devarv->agdRefPlnrMArcguide], arvcnt, devvtxdsnrefs[devarv->refPlnrMVertex]);
							dbsplnr->tblplnrlrmarcguidemvertex->insertRec(arv); arvs.nodes.push_back(arv);
						};
					};
				};
			};

			// -- structures and faces
			for (unsigned int j=0;j<devsrus.nodes.size();j++) {
				devsru = devsrus.nodes[j];

				// copy structure to design
				str.str(""); str << dev->sref << "." << devsru->sref;
				sru = new PlnrMStructure(0, VecPlnrVMStructureHkTbl::DSN, refPlnrMDesign, str.str(), 1e6, -1e6, 1e6, -1e6);
				dbsplnr->tblplnrmstructure->insertRec(sru); srus.nodes.push_back(sru);

				devsrudsnrefs[devsru->ref] = sru->ref;

				// - add to design faces, generate ref mapping
				for (unsigned int k=devsrufceics0[j];k<devsrufceics1[j];k++) {
					if (devfceacts[k]) {
						devfce = devfces.nodes[k];

						str.str(""); str << "f" << fcecnt;

						vics.resize(0); icsRte.resize(0); gics.resize(0); icsDir.resize(0);
						fce = addFaceByVgics(dbsplnr, 0, sru->ref, str.str(), vics, icsRte, gics, icsDir, vtxs, lgs, ags, fces); // vics/icsRte/gics/icsDir empty, vtxs/lgs/ags not used
						fce->devRefPlnrMFace = devfce->ref; dbsplnr->tblplnrmface->updateRec(fce);

						devfcedsnrefs[devfce->ref] = fces.nodes[fcecnt]->ref;

						fcecnt++;
					};
				};

				// - copy face-vertices
				for (unsigned int k=devsrufceics0[j];k<devsrufceics1[j];k++) {
					if (devfceacts[k]) {
						devfce = devfces.nodes[k];

						dbsplnr->tblplnrrmfacemvertex->loadRstByFce(devfce->ref, false, frvs);
						
						// adapt face and vertex refs
						for (unsigned int l=0;l<frvs.nodes.size();l++) {
							frv = frvs.nodes[l];

							// adapt lateral structure limits
							x = vtxs.nodes[devvtxdsnics[frv->refPlnrMVertex]]->x;
							y = vtxs.nodes[devvtxdsnics[frv->refPlnrMVertex]]->y;

							if (x < sru->x0) sru->x0 = x;
							if (x > sru->x1) sru->x1 = x;
							if (y < sru->y0) sru->y0 = y;
							if (y > sru->y1) sru->y1 = y;

							frv->ref = 0;
							frv->fceRefPlnrMFace = devfcedsnrefs[devfce->ref];
							frv->refPlnrMVertex = devvtxdsnrefs[frv->refPlnrMVertex];

							if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
								frv->rteUref = devlgdsnrefs[frv->rteUref];
							} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
								frv->rteUref = devagdsnrefs[frv->rteUref];
							};

							dbsplnr->tblplnrrmfacemvertex->insertRec(frv);
						};
					};
				};

				// - store adapted lateral structure limits
				dbsplnr->tblplnrmstructure->updateRec(sru);
			};

			// -- clean up
			devvtxics.clear();

			devvtxdsnrefs.clear();
			devvtxdsnics.clear();

			devlgdsnrefs.clear();

			devagdsnrefs.clear();

			devfcedsnrefs.clear();
		};

		dbsplnr->commit();
	};

	if (expz) {
		dbsplnr->begin();

		// generate negative and positive infinity levels
		lvl = addLevel(dbsplnr, 0, VecPlnrVMLevelHkTbl::DSN, refPlnrMDesign, "zninf", -1.0e6, lvls);
		lvl = addLevel(dbsplnr, 0, VecPlnrVMLevelHkTbl::DSN, refPlnrMDesign, "zpinf", 1.0e6, lvls);

		// --- add (expanded) stacks
		for (unsigned int i=0;i<stks.nodes.size();i++) {
			stk = stks.nodes[i];

			// -- load stack expansion including design modifications
			Plnr::getStackExp(dbsplnr, stk->ref, refBasedsn, refModdsn, true, stklvls, stklyrs);

			// -- translate z
			dz = 0.0;

			// - classify alignment case to determine translation
			ffill = (stklyrs.nodes[0]->ixVTtype == VecPlnrVMLayerTtype::FFILL);
			cfill = (stklyrs.nodes[stklyrs.nodes.size()-1]->ixVTtype == VecPlnrVMLayerTtype::CFILL);

			if (stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::ABS) {
				if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::ABS) {
					// forbidden

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::SLYR) {
					if (!ffill && !cfill) {
						dz = stk->zFlr;
						stklvls.nodes[0]->z = dz;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::REL) {
					if (!ffill && cfill) {
						dz = stk->zFlr;
						stklvls.nodes[0]->z = dz;
						if (lvlics.find(stk->ceilSrefPlnrMLevel) != lvlics.end()) stklvls.nodes[stklvls.nodes.size()-1]->z = lvls.nodes[lvlics[stk->ceilSrefPlnrMLevel]]->z;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::PINF) {
					if (!ffill && cfill) {
						dz = stk->zFlr;
						stklvls.nodes[0]->z = dz;
					};
				};

			} else if (stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::REL) {
				if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::ABS) {
					if (ffill && !cfill) {
						dz = stk->zCeil - stklvls.nodes[stklvls.nodes.size()-1]->z;
						if (lvlics.find(stk->flrSrefPlnrMLevel) != lvlics.end()) stklvls.nodes[0]->z = lvls.nodes[lvlics[stk->flrSrefPlnrMLevel]]->z;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::SLYR) {
					if (!ffill && !cfill) {
						if (lvlics.find(stk->flrSrefPlnrMLevel) != lvlics.end()) dz = lvls.nodes[lvlics[stk->flrSrefPlnrMLevel]]->z;
						stklvls.nodes[0]->z = dz;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::REL) {
					if (ffill && !cfill) {
						if (lvlics.find(stk->ceilSrefPlnrMLevel) != lvlics.end()) dz = lvls.nodes[lvlics[stk->ceilSrefPlnrMLevel]]->z - stklvls.nodes[stklvls.nodes.size()-1]->z;
						if (lvlics.find(stk->flrSrefPlnrMLevel) != lvlics.end()) stklvls.nodes[0]->z = lvls.nodes[lvlics[stk->flrSrefPlnrMLevel]]->z;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;

					} else if (!ffill && cfill) {
						if (lvlics.find(stk->flrSrefPlnrMLevel) != lvlics.end()) dz = lvls.nodes[lvlics[stk->flrSrefPlnrMLevel]]->z;
						stklvls.nodes[0]->z = dz;
						if (lvlics.find(stk->ceilSrefPlnrMLevel) != lvlics.end()) stklvls.nodes[stklvls.nodes.size()-1]->z = lvls.nodes[lvlics[stk->ceilSrefPlnrMLevel]]->z;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::PINF) {
					if (!ffill && cfill) {
						if (lvlics.find(stk->flrSrefPlnrMLevel) != lvlics.end()) dz = lvls.nodes[lvlics[stk->flrSrefPlnrMLevel]]->z;
						stklvls.nodes[0]->z = dz;
					};
				};

			} else if (stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::NINF) {
				if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::ABS) {
					if (ffill && !cfill) {
						dz = stk->zCeil - stklvls.nodes[stklvls.nodes.size()-1]->z;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::SLYR) {
					if (ffill && !cfill) {
						// no alignment required
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::REL) {
					if (ffill && !cfill) {
						if (lvlics.find(stk->ceilSrefPlnrMLevel) != lvlics.end()) dz = lvls.nodes[lvlics[stk->ceilSrefPlnrMLevel]]->z - stklvls.nodes[stklvls.nodes.size()-1]->z;
						stklvls.nodes[stklvls.nodes.size()-1]->z += dz;
					};

				} else if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::PINF) {
					if (ffill && cfill) {
						// no alignment required
					};
				};
			};

			// - perform actual translation
			if (dz != 0.0) for (unsigned int j=1;j<(stklvls.nodes.size()-1);j++) stklvls.nodes[j]->z += dz;

			// - adapt layer thicknesses in special cases

			// first layer for rel-rel-ffill-!cfill, rel-abs-ffill-!cfill
			if (ffill && !cfill) {
				if (stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::REL) {
					if ((stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::REL) || (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::ABS)) {
						str.str(""); str << (stklvls.nodes[1]->z - stklvls.nodes[0]->z);
						stklyrs.nodes[0]->t = str.str();
					};
				};
			};

			// last layer for abs-rel-!ffill-cfill, rel-rel-!ffill-cfill
			if (!ffill && cfill) {
				if (stk->ixVCeilAligntype == VecPlnrVMStackCeilAligntype::REL) {
					if ((stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::REL) || (stk->ixVFlrAligntype == VecPlnrVMStackFlrAligntype::ABS)) {
						str.str(""); str << (stklvls.nodes[stklvls.nodes.size()-1]->z - stklvls.nodes[stklvls.nodes.size()-2]->z);
						stklyrs.nodes[stklyrs.nodes.size()-1]->t = str.str();
					};
				};
			};

			// -- add to design levels, generate ref mapping
			for (unsigned int j=0;j<stklvls.nodes.size();j++) {
				stklvl = stklvls.nodes[j];

				if (stklvl->z == -1.0e6) {
					// negative infinity
					addLvlLvl(dbsplnr, stklvl->ref, lvls.nodes[0]->ref);

					stklvldsnrefs[stklvl->ref] = lvls.nodes[0]->ref;

					// add to design sref mapping (<-)
					str.str(""); str << stk->sref << "." << stklvl->sref;
					lvlics[str.str()] = 0;

				} else if (stklvl->z == 1.0e6) {
					// positive infinity
					addLvlLvl(dbsplnr, stklvl->ref, lvls.nodes[1]->ref);

					stklvldsnrefs[stklvl->ref] = lvls.nodes[1]->ref;

					// add to design sref mapping (<-)
					str.str(""); str << stk->sref << "." << stklvl->sref;
					lvlics[str.str()] = 1;

				} else {
					str.str(""); str << "z" << lvlcnt;

					lvl = addLevel(dbsplnr, 0, VecPlnrVMLevelHkTbl::DSN, refPlnrMDesign, str.str(), stklvl->z, lvls);
					addLvlLvl(dbsplnr, stklvl->ref, lvl->ref);

					stklvldsnrefs[stklvl->ref] = lvls.nodes[lvlcnt+2]->ref;

					// add to design sref mapping (<-)
					str.str(""); str << stk->sref << "." << stklvl->sref;
					lvlics[str.str()] = lvlcnt+2;

					lvlcnt++;
				};
			};

			// - add to design layers
			for (unsigned int j=0;j<stklyrs.nodes.size();j++) {
				stklyr = stklyrs.nodes[j];

				str.str(""); str << stk->sref << "." << stklyr->sref;

				lyr = new PlnrMLayer(*stklyr);

				lyr->x1RefPlnrMDesign = 0;
				lyr->hkIxVTbl = VecPlnrVMLayerHkTbl::DSN;
				lyr->hkUref = refPlnrMDesign;
				lyr->hkNum = lyrs.nodes.size();
				lyr->ixVTtype = VecPlnrVMLayerTtype::ABS;
				lyr->sref = str.str();
				lyr->flrRefPlnrMLevel = stklvldsnrefs[lyr->flrRefPlnrMLevel];
				if (lyr->ctrRefPlnrMLevel != 0) lyr->ctrRefPlnrMLevel = stklvldsnrefs[lyr->ctrRefPlnrMLevel];
				lyr->ceilRefPlnrMLevel = stklvldsnrefs[lyr->ceilRefPlnrMLevel];

				dbsplnr->tblplnrmlayer->insertRec(lyr); lyrs.nodes.push_back(lyr);
			};

			// -- clean up
			stklvldsnrefs.clear();
		};

		dbsplnr->commit();
	};

	if ((dsn->ixVDim == VecPlnrVMDesignDim::XYZ) && (expxy || expz)) {
		// --- blocks xyz design

		dbsplnr->begin();

		// -- load structure mapping (device-design) if xy not expanded
		if (!expxy) {
			for (unsigned int i=0;i<devs.nodes.size();i++) {
				dev = devs.nodes[i];

				dbsplnr->tblplnrmstructure->loadRstByHktHku(VecPlnrVMStructureHkTbl::DEV, dev->ref, false, devsrus);
				for (unsigned int j=0;j<devsrus.nodes.size();j++) {
					devsru = devsrus.nodes[j];
					str.str(""); str << dev->sref << "." << devsru->sref;

					dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DSN, refBasedsn, str.str(), ref);

					devsrudsnrefs[devsru->ref] = ref;
				};
			};
		};

		// -- traverse stack-structure's by stack
		for (unsigned int i=0;i<stks.nodes.size();i++) {
			stk = stks.nodes[i];

			// - load layer mapping (stack-design); an index on lyrs can't be used because !expz is possible
			refs.resize(0);
			stklyrics.clear();

			dbsplnr->tblplnrmlayer->loadRstByHktHku(VecPlnrVMLayerHkTbl::STK, stk->ref, false, stklyrs);

			for (unsigned int j=0;j<stklyrs.nodes.size();j++) {
				stklyr = stklyrs.nodes[j];

				if (stklyr->ixVBasetype != VecPlnrVMLayerBasetype::TPL) {
					str.str(""); str << stk->sref << "." << stklyr->sref;
					if (expz) {
						dbsplnr->tblplnrmlayer->loadRefByHktHkuSrf(VecPlnrVMLayerHkTbl::DSN, refPlnrMDesign, str.str(), ref);
					} else {
						dbsplnr->tblplnrmlayer->loadRefByHktHkuSrf(VecPlnrVMLayerHkTbl::DSN, refBasedsn, str.str(), ref);
					};

					stklyrics[stklyr->sref] = refs.size();
					refs.push_back(ref);
				};
			};

			// - generate one block per structure and layer
			dbsplnr->tblplnrrmstackmstructure->loadRstByStk(stk->ref, false, srss);
			for (unsigned int j=0;j<srss.nodes.size();j++) {
				srs = srss.nodes[j];

				if ((stk->ixVBasetype == VecPlnrVMStackBasetype::PERTPL) || (srs->fromSrefPlnrMLayer.length() == 0)) {
					for (unsigned int k=0;k<refs.size();k++) {
						dbsplnr->tblplnrmblock->appendNewRecToRst(blks, NULL, refPlnrMDesign, devsrudsnrefs[srs->refPlnrMStructure], refs[k]);
					};

				} else if (srs->fromSrefPlnrMLayer.compare(srs->toSrefPlnrMLayer) == 0) {
					dbsplnr->tblplnrmblock->appendNewRecToRst(blks, NULL, refPlnrMDesign, devsrudsnrefs[srs->refPlnrMStructure], refs[stklyrics[srs->fromSrefPlnrMLayer]]);

				} else {
					for (unsigned int k=stklyrics[srs->fromSrefPlnrMLayer];k<=stklyrics[srs->toSrefPlnrMLayer];k++) {
						dbsplnr->tblplnrmblock->appendNewRecToRst(blks, NULL, refPlnrMDesign, devsrudsnrefs[srs->refPlnrMStructure], refs[k]);
					};
				};
			};
		};

		dbsplnr->commit();

	} else if ((dsn->ixVDim == VecPlnrVMDesignDim::XY) && expxy) {
		// --- blocks xy design (xy is neccessarily expanded, i.e. devsrudsnrefs is valid)

		dbsplnr->begin();

		// -- traverse layer-structure's by layer
		dbsplnr->loadRefsBySQL("SELECT TblPlnrMLayer.ref FROM TblPlnrMLayer, TblPlnrMStack WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK)
					+ " AND TblPlnrMLayer.hkUref = TblPlnrMStack.ref AND TblPlnrMStack.dsnRefPlnrMDesign = " + to_string(refBasedsn), false, refs);

		for (unsigned int i=0;i<refs.size();i++) {
			dbsplnr->tblplnrrmlayermstructure->loadRstByLyr(refs[i], false, lrss);

			// - generate one block per structure and layer
			for (unsigned int j=0;j<lrss.nodes.size();j++) {
				lrs = lrss.nodes[j];

				blk = new PlnrMBlock(0, refPlnrMDesign, devsrudsnrefs[lrs->refPlnrMStructure], lrs->refPlnrMLayer);
				dbsplnr->tblplnrmblock->insertRec(blk);
				blks.nodes.push_back(blk);
			};
		};

		dbsplnr->commit();
	};

	if (expxy) {
		// generate design vertex index
		for (unsigned int i=0;i<vtxs.nodes.size();i++) dsnvtxics[vtxs.nodes[i]->ref] = i;

		// --- add xy domainguides: vertices (vtxlg, vtxag, vtxprplg, vtxlgx) and lineguides (lpgar, lgpar2, lgprpag, lgprplg, lgvtx)
		for (unsigned int i=0;i<dgs.nodes.size();i++) {
			dg = dgs.nodes[i];

			if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLG) {
				// -- vertex on lineguide with distance from existing vertex on same lineguide
				// uses av1SrefPlnrMVertex, al1SrefPlnrMLineguide, d

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize al1SrefPlnrMLineguide (allowed: one lrv)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, false, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);
				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				d = atof(dg->d.c_str());

				// generate new vertex
				dgvtx = new PlnrMVertex(0, 0, VecPlnrVLat::INI, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, dg->sref, vtx->x + dx*d, vtx->y + dy*d);
				dbsplnr->tblplnrmvertex->insertRec(dgvtx);

				// merge new vertex into vtxs and flag as dg vertex
				vtxs.nodes.push_back(dgvtx);
				vtxics[dg->sref] = vtxs.nodes.size()-1;
				dsnvtxics[dgvtx->ref] = vtxs.nodes.size()-1;
				dgvtxics.insert(vtxs.nodes.size()-1);

				// add lrv at appropriate num
				if (dx != 0.0) {
					lam = (dgvtx->x - x0)/dx;
				} else if (dy != 0.0) {
					lam = (dgvtx->y - y0)/dy;
				};

				num = 0;
				if (lrvs.nodes.size() > 0) {
					for (unsigned int j=0;j<lrvs.nodes.size();j++) {
						if (lgvtxlams[j] > lam) break;
						num = lrvs.nodes[j]->lgdNum;
					};

					dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = lgdNum+1 WHERE lgdRefPlnrMLineguide = " + to_string(lg->ref) + " AND lgdNum > " + to_string(num));
				};
				num += 1;

				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, lg->ref, num, dgvtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXAG) {
				// -- vertex on arcguide with angular distance from existing vertex on same arcguide
				// uses av1SrefPlnrMVertex, srefPlnrMArcguide, dphi

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize srefPlnrMArcguide
				if (agics.find(dg->srefPlnrMArcguide) != agics.end()) ag = ags.nodes[agics[dg->srefPlnrMArcguide]];
				charAgd(dbsplnr, ag, false, arvs, agvtxics, agvtxlams, x0, y0, lam1, vtxs, dsnvtxics);

				dphi = degToRad(atof(dg->dphi.c_str()));

				// generate new vertex
				dgvtx = new PlnrMVertex(0, 0, VecPlnrVLat::INI, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, dg->sref, x0 + ag->r*cos(atan2(vtx->y-y0, vtx->x-x0) + dphi), y0 + ag->r*sin(atan2(vtx->y-y0, vtx->x-x0) + dphi));
				dbsplnr->tblplnrmvertex->insertRec(dgvtx);

				// merge new vertex into vtxs and flag as dg vertex
				vtxs.nodes.push_back(dgvtx);
				vtxics[dg->sref] = vtxs.nodes.size()-1;
				dsnvtxics[dgvtx->ref] = vtxs.nodes.size()-1;
				dgvtxics.insert(vtxs.nodes.size()-1);

				// add arv at appropriate num
				lam = atan2(vtx->y-y0, vtx->x-x0) + dphi;
				while (lam < 0.0) lam += 2.0*pi;

				num = 0;
				if (arvs.nodes.size() > 0) {
					for (unsigned int j=0;j<arvs.nodes.size();j++) {
						if (agvtxlams[j] > lam) break;
						num = arvs.nodes[j]->agdNum;
					};

					dbsplnr->executeQuery("UPDATE TblPlnrLRMArcguideMVertex SET agdNum = agdNum+1 WHERE agdRefPlnrMArcguide = " + to_string(ag->ref) + " AND agdNum >= " + to_string(num));
				};
				num += 1;

				arv = new PlnrLRMArcguideMVertex(0, VecPlnrVLat::INI, ag->ref, num, dgvtx->ref);
				dbsplnr->tblplnrlrmarcguidemvertex->insertRec(arv); arvs.nodes.push_back(arv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXPRPLG) {
				// -- vertex on line perpendicular to existing lineguide at vertex on that lineguide
				// uses av1SrefPlnrMVertex, al1SrefPlnrMLineguide, d

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize al1SrefPlnrMLineguide (allowed: one lrv)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, true, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);
				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				d = atof(dg->d.c_str());

				// generate new vertex (line is (-dy,dx))
				dgvtx = new PlnrMVertex(0, 0, VecPlnrVLat::INI, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, dg->sref, vtx->x - dy*d, vtx->y + dx*d);
				dbsplnr->tblplnrmvertex->insertRec(dgvtx);

				// merge new vertex into vtxs and flag as dg vertex
				vtxs.nodes.push_back(dgvtx);
				vtxics[dg->sref] = vtxs.nodes.size()-1;
				dsnvtxics[dgvtx->ref] = vtxs.nodes.size()-1;
				dgvtxics.insert(vtxs.nodes.size()-1);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLGX) {
				// -- vertex at intersection of existing lineguides
				// uses al1SrefPlnrMLineguide, al2SrefPlnrMLineguide

				// find and characterize al1SrefPlnrMLineguide (allowed: zero/one lrv's)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, false, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);
				if (lrvs.nodes.size() == 0) {
					x0 = dglgx0s[dg->al1SrefPlnrMLineguide];
					y0 = dglgy0s[dg->al1SrefPlnrMLineguide];
				};
				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				// find and characterize al2SrefPlnrMLineguide (allowed: zero/one lrv's)
				if (lgics.find(dg->al2SrefPlnrMLineguide) != lgics.end()) lg2 = lgs.nodes[lgics[dg->al2SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg2->ref, false, lrvs2, lgvtxics2, lgvtxlams2, x02, y02, dx2, dy2, lam12, vtxs, dsnvtxics);
				if (lrvs2.nodes.size() == 0) {
					x02 = dglgx0s[dg->al2SrefPlnrMLineguide];
					y02 = dglgy0s[dg->al2SrefPlnrMLineguide];
				};
				if ((dx2 == 0.0) && (dy2 == 0.0)) {
					dx2 = dglgdxs[dg->al2SrefPlnrMLineguide];
					dy2 = dglgdys[dg->al2SrefPlnrMLineguide];
				};

				// find xsec, solve for lam, lam2:
				// x0 + lam*dx = x02 + lam2*dx2
				// y0 + lam*dy = y02 + lam2*dy2
				lam = (1.0/(-dx*dy2+dx2*dy)) * (-dy2*(x02-x0) + dx2*(y02-y0));
				lam2 = (1.0/(-dx*dy2+dx2*dy)) * (-dy*(x02-x0) + dx*(y02-y0));

				// generate new vertex
				dgvtx = new PlnrMVertex(0, 0, VecPlnrVLat::INI, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, dg->sref, x0 + lam*dx, y0 + lam*dy);
				dbsplnr->tblplnrmvertex->insertRec(dgvtx);

				// merge new vertex into vtxs and flag as dg vertex
				vtxs.nodes.push_back(dgvtx);
				vtxics[dg->sref] = vtxs.nodes.size()-1;
				dsnvtxics[dgvtx->ref] = vtxs.nodes.size()-1;
				dgvtxics.insert(vtxs.nodes.size()-1);

				// add lrv (2x) at appropriate num
				num = 0;
				if (lrvs.nodes.size() > 0) {
					for (unsigned int j=0;j<lrvs.nodes.size();j++) {
						if (lgvtxlams[j] > lam) break;
						num = lrvs.nodes[j]->lgdNum;
					};

					dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = lgdNum+1 WHERE lgdRefPlnrMLineguide = " + to_string(lg->ref) + " AND lgdNum > " + to_string(num));
				};
				num += 1;

				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, lg->ref, num, dgvtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

				num = 0;
				if (lrvs2.nodes.size() > 0) {
					for (unsigned int j=0;j<lrvs2.nodes.size();j++) {
						if (lgvtxlams2[j] > lam2) break;
						num = lrvs2.nodes[j]->lgdNum;
					};

					dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET lgdNum = lgdNum+1 WHERE lgdRefPlnrMLineguide = " + to_string(lg2->ref) + " AND lgdNum > " + to_string(num));
				};
				num += 1;

				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, lg2->ref, num, dgvtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR) {
				// -- lineguide with distance in parallel to existing lineguide
				// uses al1SrefPlnrMLineguide, d

				// find and characterize al1SrefPlnrMLineguide (allowed: one lrv)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, true, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);

				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				d = atof(dg->d.c_str());

				dglgdxs[dg->sref] = dx;
				dglgdys[dg->sref] = dy;
				dglgx0s[dg->sref] = x0 - dy*d;
				dglgy0s[dg->sref] = y0 + dx*d;

				// generate new lineguide
				dglg = new PlnrMLineguide(0, 0, VecPlnrVLat::INI, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, dg->sref);
				dbsplnr->tblplnrmlineguide->insertRec(dglg);

				// merge new lineguide into lgs and flag as dg lineguide
				lgs.nodes.push_back(dglg);
				lgics[dg->sref] = lgs.nodes.size()-1;
				dglgics.insert(lgs.nodes.size()-1);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR2) {
				// -- lineguide through vertex in parallel to existing lineguide
				// uses av1SrefPlnrMVertex, al1SrefPlnrMLineguide

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize al1SrefPlnrMLineguide (allowed: one lrv)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, true, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);
				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				dglgdxs[dg->sref] = dx;
				dglgdys[dg->sref] = dy;

				// generate new lineguide
				dglg = new PlnrMLineguide(0, 0, VecPlnrVLat::INI, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, dg->sref);
				dbsplnr->tblplnrmlineguide->insertRec(dglg);

				// merge new lineguide into lgs and flag as dg lineguide
				lgs.nodes.push_back(dglg);
				lgics[dg->sref] = lgs.nodes.size()-1;
				dglgics.insert(lgs.nodes.size()-1);

				// add single lrv at num=1
				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, dglg->ref, 1, vtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPAG) {
				// -- lineguide perpendicular to existing arcguide at vertex on that arcguide
				// uses av1SrefPlnrMVertex, srefPlnrMArcguide

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize srefPlnrMArcguide
				if (agics.find(dg->srefPlnrMArcguide) != agics.end()) ag = ags.nodes[agics[dg->srefPlnrMArcguide]];
				charAgd(dbsplnr, ag, true, arvs, agvtxics, agvtxlams, x0, y0, lam1, vtxs, dsnvtxics);

				dglgdxs[dg->sref] = (vtx->x-x0) / ag->r;
				dglgdys[dg->sref] = (vtx->y-y0) / ag->r;

				// generate new lineguide
				dglg = new PlnrMLineguide(0, 0, VecPlnrVLat::INI, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, dg->sref);
				dbsplnr->tblplnrmlineguide->insertRec(dglg);

				// merge new lineguide into lgs and flag as dg lineguide
				lgs.nodes.push_back(dglg);
				lgics[dg->sref] = lgs.nodes.size()-1;
				dglgics.insert(lgs.nodes.size()-1);

				// add single lrv at num=1
				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, dglg->ref, 1, vtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPLG) {
				// -- line guide perpendicular to existing lineguide at vertex on that lineguide
				// uses av1SrefPlnrMVertex, al1SrefPlnrMLineguide

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find and characterize al1SrefPlnrMLineguide (allowed: one lrv)
				if (lgics.find(dg->al1SrefPlnrMLineguide) != lgics.end()) lg = lgs.nodes[lgics[dg->al1SrefPlnrMLineguide]];
				charLgd(dbsplnr, lg->ref, true, lrvs, lgvtxics, lgvtxlams, x0, y0, dx, dy, lam1, vtxs, dsnvtxics);
				if ((dx == 0.0) && (dy == 0.0)) {
					dx = dglgdxs[dg->al1SrefPlnrMLineguide];
					dy = dglgdys[dg->al1SrefPlnrMLineguide];
				};

				dglgdxs[dg->sref] = -dy;
				dglgdys[dg->sref] = dx;

				// generate new lineguide
				dglg = new PlnrMLineguide(0, 0, VecPlnrVLat::INI, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, dg->sref);
				dbsplnr->tblplnrmlineguide->insertRec(dglg);

				// merge new lineguide into lgs and flag as dg lineguide
				lgs.nodes.push_back(dglg);
				lgics[dg->sref] = lgs.nodes.size()-1;
				dglgics.insert(lgs.nodes.size()-1);

				// add single lrv at num=1
				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, dglg->ref, 1, vtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);

			} else if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LGVTX) {
				// -- lineguide that spans between two existing vertices	
				// uses av1SrefPlnrMVertex, av2SrefPlnrMVertex

				// find av1SrefPlnrMVertex
				if (vtxics.find(dg->av1SrefPlnrMVertex) != vtxics.end()) vtx = vtxs.nodes[vtxics[dg->av1SrefPlnrMVertex]];

				// find av2SrefPlnrMVertex
				if (vtxics.find(dg->av2SrefPlnrMVertex) != vtxics.end()) vtx2 = vtxs.nodes[vtxics[dg->av2SrefPlnrMVertex]];

				// generate new lineguide
				dglg = new PlnrMLineguide(0, 0, VecPlnrVLat::INI, VecPlnrVMLineguideHkTbl::DSN, refPlnrMDesign, dg->sref);
				dbsplnr->tblplnrmlineguide->insertRec(dglg);

				// merge new lineguide into lgs and flag as dg lineguide
				lgs.nodes.push_back(dglg);
				lgics[dg->sref] = lgs.nodes.size()-1;
				dglgics.insert(lgs.nodes.size()-1);

				// add two lrv's at num=1,2
				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, dglg->ref, 1, vtx->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);
				lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, dglg->ref, 2, vtx2->ref);
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);
			};
		};

		// --- re-name and flag levels used in domains
		for (unsigned int i=0;i<doms.nodes.size();i++) {
			dom = doms.nodes[i];

			if (dom->vtx1SrefPlnrMVertex.length() != 0) if (vtxics.find(dom->vtx1SrefPlnrMVertex) != vtxics.end()) {
				vtx = vtxs.nodes[vtxics[dom->vtx1SrefPlnrMVertex]];
				vtx->sref = dom->vtx1SrefPlnrMVertex;
				dbsplnr->tblplnrmvertex->updateRec(vtx);
				dgvtxics.insert(vtxics[dom->vtx1SrefPlnrMVertex]);
			};
			if (dom->lgd1SrefPlnrMLineguide.length() != 0) if (lgics.find(dom->lgd1SrefPlnrMLineguide) != lgics.end()) {
				lg = lgs.nodes[lgics[dom->lgd1SrefPlnrMLineguide]];
				lg->sref = dom->lgd1SrefPlnrMLineguide;
				dbsplnr->tblplnrmlineguide->updateRec(lg);
				dglgics.insert(lgics[dom->lgd1SrefPlnrMLineguide]);
			};
			if (dom->vtx2SrefPlnrMVertex.length() != 0) if (vtxics.find(dom->vtx2SrefPlnrMVertex) != vtxics.end()) {
				vtx = vtxs.nodes[vtxics[dom->vtx2SrefPlnrMVertex]];
				vtx->sref = dom->vtx2SrefPlnrMVertex;
				dbsplnr->tblplnrmvertex->updateRec(vtx);
				dgvtxics.insert(vtxics[dom->vtx2SrefPlnrMVertex]);
			};
			if (dom->lgd2SrefPlnrMLineguide.length() != 0) if (lgics.find(dom->lgd2SrefPlnrMLineguide) != lgics.end()) {
				lg = lgs.nodes[lgics[dom->lgd2SrefPlnrMLineguide]];
				lg->sref = dom->lgd2SrefPlnrMLineguide;
				dbsplnr->tblplnrmlineguide->updateRec(lg);
				dglgics.insert(lgics[dom->lgd2SrefPlnrMLineguide]);
			};
			if (dom->vtx3SrefPlnrMVertex.length() != 0) if (vtxics.find(dom->vtx3SrefPlnrMVertex) != vtxics.end()) {
				vtx = vtxs.nodes[vtxics[dom->vtx3SrefPlnrMVertex]];
				vtx->sref = dom->vtx3SrefPlnrMVertex;
				dbsplnr->tblplnrmvertex->updateRec(vtx);
				dgvtxics.insert(vtxics[dom->vtx3SrefPlnrMVertex]);
			};
			if (dom->lgd3SrefPlnrMLineguide.length() != 0) if (lgics.find(dom->lgd3SrefPlnrMLineguide) != lgics.end()) {
				lg = lgs.nodes[lgics[dom->lgd3SrefPlnrMLineguide]];
				lg->sref = dom->lgd3SrefPlnrMLineguide;
				dbsplnr->tblplnrmlineguide->updateRec(lg);
				dglgics.insert(lgics[dom->lgd3SrefPlnrMLineguide]);
			};
			if (dom->vtx4SrefPlnrMVertex.length() != 0) if (vtxics.find(dom->vtx4SrefPlnrMVertex) != vtxics.end()) {
				vtx = vtxs.nodes[vtxics[dom->vtx4SrefPlnrMVertex]];
				vtx->sref = dom->vtx4SrefPlnrMVertex;
				dbsplnr->tblplnrmvertex->updateRec(vtx);
				dgvtxics.insert(vtxics[dom->vtx4SrefPlnrMVertex]);
			};
			if (dom->lgd4SrefPlnrMLineguide.length() != 0) if (lgics.find(dom->lgd4SrefPlnrMLineguide) != lgics.end()) {
				lg = lgs.nodes[lgics[dom->lgd4SrefPlnrMLineguide]];
				lg->sref = dom->lgd4SrefPlnrMLineguide;
				dbsplnr->tblplnrmlineguide->updateRec(lg);
				dglgics.insert(lgics[dom->lgd4SrefPlnrMLineguide]);
			};
		};

		// --- snap xy (for now, no snap for litho designs)
		if (dsn->ixVBasetype == VecPlnrVMDesignBasetype::TRLYR) {
			dbsplnr->begin();

			// -- vertices
			vtxacts.resize(vtxs.nodes.size());
			for (unsigned int i=0;i<vtxacts.size();i++) vtxacts[i] = true;

			for (unsigned int i=0;i<vtxs.nodes.size();i++) {
				if (vtxacts[i]) {
					vtx = vtxs.nodes[i];

					for (unsigned int j=i+1;j<vtxs.nodes.size();j++) {
						if (vtxacts[j]) {
							vtx2 = vtxs.nodes[j];

							// - snap condition, use 2-norm
							snap = ( (pow(vtx2->x-vtx->x, 2)+pow(vtx2->y-vtx->y, 2)) < xysnapnorm );

							if (snap) {
								// - mark vtx2 as inactive, remove in database
								vtxacts[j] = false;
								dbsplnr->tblplnrmvertex->removeRecByRef(vtx2->ref);

								// - vtx takes the sref of vtx2 in case vtx2 is a domain guide
								if (dgvtxics.find(j) != dgvtxics.end()) {
									vtx->sref = vtx2->sref;
									dbsplnr->tblplnrmvertex->updateRec(vtx);

									dgvtxics.erase(j);
									dgvtxics.insert(i);
								};

								// - origin join
								dbsplnr->executeQuery("UPDATE TblPlnrRMVertexMVertex SET dsnRefPlnrMVertex = " + to_string(vtx->ref) + " WHERE dsnRefPlnrMVertex = " + to_string(vtx2->ref));

								// - the following SQL statement renders content of ags partially obsolete (we don't care)
								dbsplnr->executeQuery("UPDATE TblPlnrMArcguide SET ctrRefPlnrMVertex = " + to_string(vtx->ref) + " WHERE ctrRefPlnrMVertex = " + to_string(vtx2->ref));
								//for (unsigned int k=0;k<ags.nodes.size();k++) if (ags.nodes[k]->ctrRefPlnrMVertex == vtx2->ref) ags.nodes[k]->ctrRefPlnrMVertex = vtx->ref;

								dbsplnr->executeQuery("UPDATE TblPlnrLRMLineguideMVertex SET refPlnrMVertex = " + to_string(vtx->ref) + " WHERE refPlnrMVertex = " + to_string(vtx2->ref));
								dbsplnr->executeQuery("UPDATE TblPlnrLRMArcguideMVertex SET refPlnrMVertex = " + to_string(vtx->ref) + " WHERE refPlnrMVertex = " + to_string(vtx2->ref));
								dbsplnr->executeQuery("UPDATE TblPlnrRMFaceMVertex SET refPlnrMVertex = " + to_string(vtx->ref) + " WHERE refPlnrMVertex = " + to_string(vtx2->ref));
							};
						};
					};
				};
			};

			// generate design vertex index
			for (unsigned int i=0;i<vtxs.nodes.size();i++) dsnvtxics[vtxs.nodes[i]->ref] = i;

			// -- lineguides
			lrvix0s.resize(lgs.nodes.size());
			lrvix1s.resize(lgs.nodes.size());

			// - load vertex line-up for each lineguide (all vertices should be active)
			lrvs.clear();
			for (unsigned int i=0;i<lgs.nodes.size();i++) {
				lg = lgs.nodes[i];

				lrvix0s[i] = lrvs.nodes.size();
				dbsplnr->tblplnrlrmlineguidemvertex->loadRstByLgd(lg->ref, true, lrvs);
				lrvix1s[i] = lrvs.nodes.size();
			};

			// - initially consider all lineguides with at least two vertices (should be all)
			lgacts.resize(lgs.nodes.size());
			for (unsigned int i=0;i<lgacts.size();i++) lgacts[i] = ((lrvix1s[i]-lrvix0s[i]) >= 2);

			// - calculate geometry of each lineguide
			lgvtxics.resize(lrvs.nodes.size());
			lgvtxlams.resize(lrvs.nodes.size());

			lgdxs.resize(lgs.nodes.size());
			lgdys.resize(lgs.nodes.size());
			lglam1s.resize(lgs.nodes.size());

			for (unsigned int i=0;i<lgs.nodes.size();i++) {
				if (lgacts[i]) {
					lg = lgs.nodes[i];

					// find lineguide vertex indices in vtxs
					for (unsigned int j=lrvix0s[i];j<lrvix1s[i];j++) lgvtxics[j] = dsnvtxics[lrvs.nodes[j]->refPlnrMVertex];

					// determine lineguide length and orientation
					x0 = 0.0;
					y0 = 0.0;
					dx = 0.0;
					dy = 0.0;
					lam1 = 0.0;

					x0 = vtxs.nodes[lgvtxics[lrvix0s[i]]]->x;
					y0 = vtxs.nodes[lgvtxics[lrvix0s[i]]]->y;

					dx = vtxs.nodes[lgvtxics[lrvix1s[i]-1]]->x - x0;
					dy = vtxs.nodes[lgvtxics[lrvix1s[i]-1]]->y - y0;

					// normalize
					lam1 = sqrt(dx*dx + dy*dy);
					dx /= lam1;
					dy /= lam1;

					lgdxs[i] = dx;
					lgdys[i] = dy;
					lglam1s[i] = lam1;

					// determine lambda for each vertex on lineguide
					for (unsigned int j=lrvix0s[i];j<lrvix1s[i];j++) {
						vtx = vtxs.nodes[lgvtxics[j]];

						lam1 = 0.0;

						if (dx != 0.0) {
							lam1 = (vtx->x - x0)/dx;
						} else if (dy != 0.0) {
							lam1 = (vtx->y - y0)/dy;
						};

						lgvtxlams[j] = lam1;
					};
				};
			};

			// - actual snap test and execution
			for (unsigned int i=0;i<lgs.nodes.size();i++) {
				if (lgacts[i]) {
					lg = lgs.nodes[i];

					x0 = vtxs.nodes[lgvtxics[lrvix0s[i]]]->x;
					y0 = vtxs.nodes[lgvtxics[lrvix0s[i]]]->y;
					dx = lgdxs[i];
					dy = lgdys[i];
					lam1 = lglam1s[i];

					for (unsigned int j=i+1;j<lgs.nodes.size();j++) {
						if (lgacts[j]) {
							lg2 = lgs.nodes[j];

							// first requirement for all: coplanarity by dot product
							d = lgdxs[i]*lgdxs[j] + lgdys[i]*lgdys[j];
							if (((fabs(d) - 1.0) > (-xysnapnorm)) && ((fabs(d) - 1.0) < xysnapnorm)) {

								flip = (d < 0.0);

								// second requirement for all: first vertex of lg2 in line with lg
								d = (vtxs.nodes[lgvtxics[lrvix0s[j]]]->x - x0) * dy - (vtxs.nodes[lgvtxics[lrvix0s[j]]]->y - y0) * dx;
								if (pow(d, 2) < xysnapnorm) {

									// check for common vertex
									snap = false;
									for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
										for (unsigned int l=lrvix0s[j];l<lrvix1s[j];l++) {

											if (lgvtxics[k] == lgvtxics[l]) {
												snap = true;
												break;
											};
										};

										if (snap) break;
									};

									if (!snap) {
										// check for one vertex(lg2) in lam range(lg); no need to apply tolerances as vertex snap would have struck in this case
										for (unsigned int k=lrvix0s[j];k<lrvix1s[j];k++) {
											vtx = vtxs.nodes[lgvtxics[k]];

											lam = 0.0;

											if (dx != 0.0) {
												lam = (vtx->x - x0)/dx;
											} else if (dy != 0.0) {
												lam = (vtx->y - y0)/dy;
											};

											if ((lam > 0) && (lam < lam1)) {
												snap = true;
												break;
											};
										};
									};

									if (snap) {
										// mark lg2 as inactive, remove in database
										lgacts[j] = false;
										dbsplnr->tblplnrmlineguide->removeRecByRef(lg2->ref);

										// lg takes the sref of lg2 in case lg2 is a domain guide
										if (dglgics.find(j) != dglgics.end()) {
											lg->sref = lg2->sref;
											dbsplnr->tblplnrmlineguide->updateRec(lg);

											dglgics.erase(j);
											dglgics.insert(i);
										};

										// origin join
										dbsplnr->executeQuery("UPDATE TblPlnrRMLineguideMLineguide SET dsnRefPlnrMLineguide = " + to_string(lg->ref) + " WHERE dsnRefPlnrMLineguide = " + to_string(lg2->ref));

										// adjust face-vertex
										dbsplnr->tblplnrrmfacemvertex->loadRstByRttRtu(VecPlnrVRMFaceMVertexRteTbl::LGD, lg2->ref, false, frvs);
										for (unsigned int k=0;k<frvs.nodes.size();k++) {
											frv = frvs.nodes[k];

											frv->rteUref = lg->ref;
											if (flip) {
												if (frv->ixVDir == VecPlnrVRMFaceMVertexDir::FWD) frv->ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
												else frv->ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
											};

											dbsplnr->tblplnrrmfacemvertex->updateRec(frv);
										};

										// remove vertex line-ups for lg and lgs in database
										dbsplnr->executeQuery("DELETE FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = " + to_string(lg->ref));
										dbsplnr->executeQuery("DELETE FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = " + to_string(lg2->ref));

										// add vertices of lg and lg2 to vertex line-up of lg
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
											lrv = new PlnrLRMLineguideMVertex(*(lrvs.nodes[k]));

											lrv->ref = 0;
											lrv->lgdNum = 0;
											lrvs.nodes.push_back(lrv);
										};

										// adapt indices of lg (part 1)
										lrvix0s[i] = lrvs.nodes.size() - (lrvix1s[i]-lrvix0s[i]);

										for (unsigned int k=lrvix0s[j];k<lrvix1s[j];k++) {
											lrv = new PlnrLRMLineguideMVertex(*(lrvs.nodes[k]));

											// avoid duplicates
											found = false;
											for (unsigned int l=lrvix0s[i];l<lrvs.nodes.size();l++) {
												if (lrv->refPlnrMVertex == lrvs.nodes[l]->refPlnrMVertex) {
													found = true;
													delete lrv;

													break;
												};
											};

											if (!found) {
												lrv->ref = 0;
												lrv->lgdRefPlnrMLineguide = lg->ref;
												lrv->lgdNum = 0;
												lrvs.nodes.push_back(lrv);
											};
										};

										// adapt indices of lg (part 2)
										lrvix1s[i] = lrvs.nodes.size();

										// find lineguide vertex indices in vtxs
										lgvtxics.resize(lrvs.nodes.size());
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) lgvtxics[k] = dsnvtxics[lrvs.nodes[k]->refPlnrMVertex];

										// determine lambda for each vertex on lineguide
										lgvtxlams.resize(lrvs.nodes.size());
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
											vtx = vtxs.nodes[lgvtxics[k]];

											lam = 0.0;

											if (dx != 0.0) {
												lam = (vtx->x - x0)/dx;
											} else if (dy != 0.0) {
												lam = (vtx->y - y0)/dy;
											};

											lgvtxlams[k] = lam;
										};

										// establish proper lgdNum order
										for (uint lrvnum=1 ; lrvnum<=(lrvix1s[i]-lrvix0s[i]) ; lrvnum++) {
											lam = 1e6;

											// find minimum lambda among un-numbered vertices
											for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
												if ((lrvs.nodes[k]->lgdNum == 0) && (lgvtxlams[k] < lam)) {
													lrvix = k;
													lam = lgvtxlams[k];
												};
											};

											// attribute number to minimum vertex
											lrvs.nodes[lrvix]->lgdNum = lrvnum;
										};

										// adjust lam of vertices such that lam's start with 0.0, also adjust x0, y0 of lg
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
											if (lrvs.nodes[k]->lgdNum == 1) {
												lam0 = lgvtxlams[k];
												for (unsigned int l=lrvix0s[i];l<lrvix1s[i];l++) lgvtxlams[l] -= lam0;

												x0 = vtxs.nodes[lgvtxics[k]]->x;
												y0 = vtxs.nodes[lgvtxics[k]]->y;

												break;
											};
										};

										// adjust lam1 of lg
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) {
											if (lrvs.nodes[k]->lgdNum == (lrvix1s[i]-lrvix0s[i])) {
												lglam1s[i] = lgvtxlams[k];
												lam1 = lglam1s[i];
											
												break;
											};
										};

										// insert new lrv's in database
										for (unsigned int k=lrvix0s[i];k<lrvix1s[i];k++) dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrvs.nodes[k]);
									};
								};
							};
						};
					};
				};
			};

			// -- arcguides
			// arcguides could be snapped for equivalent center vertex and radius
			// in mesh generation, no problems can arise from overlapping arcguides
			dbsplnr->commit();

			// --- ensure xsec's of guides used in domains have a vertex, and include resulting vertices in all faces
			// ...
		};
	};

	if (expz) {
		// --- add z domainguides (lvl)
		for (unsigned int i=0;i<dgs.nodes.size();i++) {
			dg = dgs.nodes[i];

			if (dg->ixVBasetype == VecPlnrVMDomaingdBasetype::LVL) {
				d = atof(dg->d.c_str());

				// find srefPlnrMLevel
				if (lvlics.find(dg->srefPlnrMLevel) != lvlics.end()) d += lvls.nodes[lvlics[dg->srefPlnrMLevel]]->z;

				// generate new level
				dglvl = new PlnrMLevel(0, 0, VecPlnrVMLevelHkTbl::DSN, refPlnrMDesign, dg->sref, d);
				dbsplnr->tblplnrmlevel->insertRec(dglvl);

				// merge new level into lvls and flag as dg level
				lvls.nodes.push_back(dglvl);
				lvlics[dg->sref] = lvls.nodes.size()-1;
				dglvlics.insert(lvls.nodes.size()-1);
			};
		};

		// --- re-name and flag levels used in domains
		for (unsigned int i=0;i<doms.nodes.size();i++) {
			dom = doms.nodes[i];

			if (dom->flrSrefPlnrMLevel.length() != 0) if (lvlics.find(dom->flrSrefPlnrMLevel) != lvlics.end()) {
				lvl = lvls.nodes[lvlics[dom->flrSrefPlnrMLevel]];
				lvl->sref = dom->flrSrefPlnrMLevel;
				dbsplnr->tblplnrmlevel->updateRec(lvl);
				dglvlics.insert(lvlics[dom->flrSrefPlnrMLevel]);
			};
			if (dom->ceilSrefPlnrMLevel.length() != 0) if (lvlics.find(dom->ceilSrefPlnrMLevel) != lvlics.end()) {
				lvl = lvls.nodes[lvlics[dom->ceilSrefPlnrMLevel]];
				lvl->sref = dom->ceilSrefPlnrMLevel;
				dbsplnr->tblplnrmlevel->updateRec(lvl);
				dglvlics.insert(lvlics[dom->ceilSrefPlnrMLevel]);
			};
		};

		// --- snap z
		dbsplnr->begin();

		// -- levels
		lvlacts.resize(lvls.nodes.size());
		for (unsigned int i=0;i<lvlacts.size();i++) lvlacts[i] = true;

		for (unsigned int i=0;i<lvls.nodes.size();i++) {
			if (lvlacts[i]) {
				lvl = lvls.nodes[i];

				for (unsigned int j=i+1;j<lvls.nodes.size();j++) {
					if (lvlacts[j]) {
						lvl2 = lvls.nodes[j];

						// - snap condition, use 2-norm
						snap = ( pow(lvl2->z-lvl->z, 2) < zsnapnorm );
				
						if (snap) {
							// - mark lvl2 as inactive, remove in database
							lvlacts[j] = false;
							dbsplnr->tblplnrmlevel->removeRecByRef(lvl2->ref);

							// - lvl takes the sref of lvl2 in case lvl2 is a domain guide
							if (dglvlics.find(j) != dglvlics.end()) {
								lvl->sref = lvl2->sref;
								dbsplnr->tblplnrmlevel->updateRec(lvl);

								dglvlics.erase(j);
								dglvlics.insert(i);
							};

							// - origin join
							dbsplnr->executeQuery("UPDATE TblPlnrRMLevelMLevel SET dsnRefPlnrMLevel = " + to_string(lvl->ref) + " WHERE dsnRefPlnrMLevel = " + to_string(lvl2->ref));

							// - the following SQL statements render content of lyrs partially obsolete (we don't care)
							dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET flrRefPlnrMLevel = " + to_string(lvl->ref) + " WHERE flrRefPlnrMLevel = " + to_string(lvl2->ref));
							dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET ctrRefPlnrMLevel = " + to_string(lvl->ref) + " WHERE ctrRefPlnrMLevel = " + to_string(lvl2->ref));
							dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET ceilRefPlnrMLevel = " + to_string(lvl->ref) + " WHERE ceilRefPlnrMLevel = " + to_string(lvl2->ref));
						};
					};
				};
			};
		};

		dbsplnr->commit();
	};

	// clean up
	delete dsn;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpDsn::charLgd(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMLineguide
			, const bool nolrv
			, ListPlnrLRMLineguideMVertex& lrvs
			, vector<unsigned int>& lgvtxics
			, vector<double>& lgvtxlams
			, double& x0
			, double& y0
			, double& dx
			, double& dy
			, double& lam1
			, const ListPlnrMVertex& vtxs
			, map<ubigint, unsigned int>& dsnvtxics
		) {
	PlnrMVertex* vtx = NULL;

	double lam;

	dbsplnr->tblplnrlrmlineguidemvertex->loadRstByLgd(refPlnrMLineguide, false, lrvs);
	if (!nolrv) {
		lgvtxics.resize(lrvs.nodes.size());
		lgvtxlams.resize(lrvs.nodes.size());
	};

	// find lineguide vertex indices in vtxs
	if (!nolrv) for (unsigned int j=0;j<lrvs.nodes.size();j++) lgvtxics[j] = dsnvtxics[lrvs.nodes[j]->refPlnrMVertex];

	// determine lineguide length and orientation
	x0 = 0.0;
	y0 = 0.0;
	dx = 0.0;
	dy = 0.0;
	lam1 = 0.0;

	if (lrvs.nodes.size() > 0) {
		x0 = vtxs.nodes[dsnvtxics[lrvs.nodes[0]->refPlnrMVertex]]->x;
		y0 = vtxs.nodes[dsnvtxics[lrvs.nodes[0]->refPlnrMVertex]]->y;
	};

	if (lrvs.nodes.size() > 1) {
		dx = vtxs.nodes[dsnvtxics[lrvs.nodes[lrvs.nodes.size()-1]->refPlnrMVertex]]->x - x0;
		dy = vtxs.nodes[dsnvtxics[lrvs.nodes[lrvs.nodes.size()-1]->refPlnrMVertex]]->y - y0;

		// normalize
		lam1 = sqrt(dx*dx + dy*dy);
		dx /= lam1;
		dy /= lam1;
	};

	if (!nolrv) {
		// determine lambda for each vertex on lineguide
		for (unsigned int j=0;j<lrvs.nodes.size();j++) {
			vtx = vtxs.nodes[lgvtxics[j]];

			lam = 0.0;

			if (dx != 0.0) {
				lam = (vtx->x - x0)/dx;
			} else if (dy != 0.0) {
				lam = (vtx->y - y0)/dy;
			};

			lgvtxlams[j] = lam;
		};
	};
};

void PlnrExpDsn::charAgd(
			DbsPlnr* dbsplnr
			, const PlnrMArcguide* ag
			, const bool noarv
			, ListPlnrLRMArcguideMVertex& arvs
			, vector<unsigned int>& agvtxics
			, vector<double>& agvtxlams
			, double& x0
			, double& y0
			, double& lam1
			, const ListPlnrMVertex& vtxs
			, map<ubigint, unsigned int>& dsnvtxics
		) {
	PlnrMVertex* vtx = NULL;
	PlnrMVertex* vtx2 = NULL;

	double lam;

	dbsplnr->tblplnrlrmarcguidemvertex->loadRstByAgd(ag->ref, false, arvs);
	if (!noarv) {
		agvtxics.resize(arvs.nodes.size());
		agvtxlams.resize(arvs.nodes.size());
	};

	// find arcguide vertex indices in vtxs
	if (!noarv) for (unsigned int j=0;j<arvs.nodes.size();j++) agvtxics[j] = dsnvtxics[arvs.nodes[j]->refPlnrMVertex];

	// determine arcguide angular length and orientation
	x0 = vtxs.nodes[dsnvtxics[ag->ctrRefPlnrMVertex]]->x;
	y0 = vtxs.nodes[dsnvtxics[ag->ctrRefPlnrMVertex]]->y;

	if (arvs.nodes[0]->refPlnrMVertex == arvs.nodes[arvs.nodes.size()-1]->refPlnrMVertex) {
		// full circle
		lam1 = 2.0*pi;

	} else {
		// partial circle
		vtx = vtxs.nodes[dsnvtxics[arvs.nodes[0]->refPlnrMVertex]];
		vtx2 = vtxs.nodes[dsnvtxics[arvs.nodes[arvs.nodes.size()-1]->refPlnrMVertex]];

		lam1 = atan2(vtx2->y-y0, vtx2->x-x0) - atan2(vtx->y-y0, vtx->x-x0);
		while (lam1 < 0.0) lam1 += 2.0*pi;
	};

	if (!noarv) {
		vtx = vtxs.nodes[agvtxics[0]];
		agvtxlams[0] = 0.0;

		// determine lambda for each vertex on arcguide
		for (unsigned int j=1;j<arvs.nodes.size();j++) {
			vtx2 = vtxs.nodes[agvtxics[j]];

			lam = atan2(vtx2->y-y0, vtx2->x-x0) - atan2(vtx->y-y0, vtx->x-x0);
			while (lam < 0.0) lam += 2.0*pi;

			agvtxlams[j] = lam;
		};

		if (agvtxics[0] == agvtxics[arvs.nodes.size()-1]) agvtxlams[arvs.nodes.size()-1] = 2.0*pi;
	};
};
// IP cust --- IEND


