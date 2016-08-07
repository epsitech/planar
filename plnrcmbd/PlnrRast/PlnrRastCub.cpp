/**
  * \file PlnrRastCub.cpp
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

#include "PlnrRastCub.h"

DpchRetPlnrRastCub* PlnrRastCub::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrRastCub* dpchinv
		) {
	DpchRetPlnrRastCub* dpchret = new DpchRetPlnrRastCub();

	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;

// IP run --- IBEGIN
	string cdfpath;
	ostringstream fullpath;

	int res;

	ostringstream sqlstr;

	PlnrMDesign* dsn = NULL;

	ubigint refBasedsn;
	ubigint refModdsn;

	PlnrMCalcitem* cli = NULL;

	uint refIxVTbl;
	ubigint refUref;
	string Filename;

	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;

	bool hasx, hasxy, hasz;
	double dx, dy, dxy, dz;

	ListPlnrMVertex vtxs;
	PlnrMVertex* vtx = NULL;
	map<ubigint, unsigned int> vtxics;

	ListPlnrMArcguide agds;
	PlnrMArcguide* agd = NULL;
	map<ubigint, unsigned int> agdics;
	PlnrMVertex* vtxctr = NULL;

	ListPlnrMLevel lvls;
	map<ubigint, unsigned int> lvlics;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;
	map<ubigint, unsigned int> lyrics;
	unsigned int lyrix;

	vector<double> lyrzmins;
	double lyrzmin;
	vector<double> lyrzmaxs;
	double lyrzmax;
	vector<bool> lyracts;

	ubigint refMat;

	PlnrMLevel* flrlvl = NULL;
	PlnrMLevel* ceillvl = NULL;

	PlnrMVertex* vtx1 = NULL;
	PlnrMVertex* vtx2 = NULL;
	PlnrMVertex* vtx3 = NULL;
	PlnrMVertex* vtx4 = NULL;

	bool found;

	double xmin, xmax, ymin, ymax, zmin, zmax;
	double phi;
	double d, e, f;

	ListPlnrMBlock blks;
	PlnrMBlock* blk = NULL;

	PlnrMStructure* sru = NULL;
	ubigint refPlnrMStructure;

	unsigned int srufaceix0;
	unsigned int srulayerix0;

	ListPlnrMFace fces;
	PlnrMFace* fce = NULL;

	unsigned int fceedgeix0;

	double fcexmin, fcexmax, fceymin, fceymax;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	unsigned int faceix;
	unsigned int edgeix;
	unsigned int layerix;

	// variables for cdf file (general)
	int cdfRoot;
	int cdfDim;

	int cdfFaces;
	vector<double> x0; int cdfX0;
	vector<double> x1; int cdfX1;
	vector<double> y0; int cdfY0;
	vector<double> y1; int cdfY1;
	vector<double> pdx; int cdfPdx;
	vector<double> pdy; int cdfPdy;
	vector<double> z0; int cdfZ0;
	vector<double> z1; int cdfZ1;
	vector<unsigned int> ixEdges0; int cdfIxEdges0;
	vector<unsigned int> ixEdges1; int cdfIxEdges1;
	vector<unsigned int> ixLayers0; int cdfIxLayers0;
	vector<unsigned int> ixLayers1; int cdfIxLayers1;

	int cdfEdges;
	vector<bool> ag; int cdfAg;
	vector<double> lx0; int cdfLx0;
	vector<double> ly0; int cdfLy0;
	vector<double> ldx; int cdfLdx;
	vector<double> ldy; int cdfLdy;
	vector<bool> accw; int cdfAccw;
	vector<double> ax0; int cdfAx0;
	vector<double> ay0; int cdfAy0;
	vector<double> ar; int cdfAr;
	vector<double> aphi0; int cdfAphi0;
	vector<double> aphi1; int cdfAphi1;

	int cdfLayers;
	vector<double> lyrz0; int cdfLyrz0;
	vector<double> lyrz1; int cdfLyrz1;
	vector<unsigned int> ixMats; int cdfIxMats;

	vector<ubigint> mats; int cdfMats;
	map<ubigint, unsigned int> matics;

	// variables for cdf file (domain-specific)
	int cdfDoms;
	int cdfDom;
	unsigned int dimX, dimY, dimXY, dimZ;
	int cdf_ixVBasetype;
	double _x0; int cdf_x0;
	double _x1; int cdf_x1;
	double _dx; int cdf_dx;
	double _y0; int cdf_y0;
	double _y1; int cdf_y1;
	double _dy; int cdf_dy;
	double _xy0; int cdf_xy0;
	double _xy1; int cdf_xy1;
	double _dxy; int cdf_dxy;
	double _z0; int cdf_z0;
	double _z1; int cdf_z1;
	double _dz; int cdf_dz;
	double a11; int cdf_a11;
	double a21; int cdf_a21;
	double b1; int cdf_b1;
	double b2; int cdf_b2;
	double b3; int cdf_b3;

	// generate file in temp folder and open
	cdfpath = Tmp::newfile(xchg->tmppath, "cdf");

	fullpath.str(""); fullpath << xchg->tmppath << "/" << cdfpath;
	res = nc_create(fullpath.str().c_str(), NC_NETCDF4, &cdfRoot);

	// -- find base / modified design
	sqlstr.str(""); sqlstr << "SELECT modRefPlnrMDesign FROM TblPlnrMDesign WHERE ref = " << refPlnrMDesign;
	dbsplnr->loadUbigintBySQL(sqlstr.str(), refBasedsn);

	if (refBasedsn == 0) {
		refBasedsn = refPlnrMDesign;
		refModdsn = 0;
	} else {
		refModdsn = refPlnrMDesign;
	};

	// -- load domains
	dbsplnr->tblplnrmdomain->loadRstByDsn(refBasedsn, false, doms);

	// -- load design vertices, arcguides and levels
	if (dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DSN, refModdsn, false, vtxs) == 0)
		dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DSN, refBasedsn, false, vtxs);
	for (unsigned int j=0;j<vtxs.nodes.size();j++) vtxics[vtxs.nodes[j]->ref] = j;

	if (dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DSN, refModdsn, false, agds) == 0)
		dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DSN, refBasedsn, false, agds);
	for (unsigned int j=0;j<agds.nodes.size();j++) agdics[agds.nodes[j]->ref] = j;

	if (dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::DSN, refModdsn, false, lvls) == 0)
		dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::DSN, refBasedsn, false, lvls);
	for (unsigned int j=0;j<lvls.nodes.size();j++) lvlics[lvls.nodes[j]->ref] = j;

	// -- load design layers and find their z limits
	if (dbsplnr->tblplnrmlayer->loadRstByHktHku(VecPlnrVMLayerHkTbl::DSN, refModdsn, false, lyrs) == 0)
		dbsplnr->tblplnrmlayer->loadRstByHktHku(VecPlnrVMLayerHkTbl::DSN, refBasedsn, false, lyrs);

	lyrzmins.resize(lyrs.nodes.size());
	lyrzmaxs.resize(lyrs.nodes.size());
	lyracts.resize(lyrs.nodes.size());

	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		lyr = lyrs.nodes[j];

		lyrics[lyr->ref] = j;

		lyrzmins[j] = lvls.nodes[lvlics[lyr->flrRefPlnrMLevel]]->z;
		lyrzmaxs[j] = lvls.nodes[lvlics[lyr->ceilRefPlnrMLevel]]->z;
	};

	// -- set up inventory of materials used
	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		lyr = lyrs.nodes[j];

		refMat = lyr->refPlnrMMaterial;
		if (refModdsn != 0) {
			sqlstr.str(""); sqlstr << "SELECT refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE x0RefPlnrMLayer = " << lyr->ref
						<< " AND x1RefPlnrMDesign = " << refModdsn;
			dbsplnr->loadUbigintBySQL(sqlstr.str(), refMat);
		};

		if (matics.find(refMat) == matics.end()) {
			matics[refMat] = mats.size();
			mats.push_back(refMat);
		};
	};

	// -- traverse domains to determine x, y and z range (design coordinates)
	xmin = 1.0e6; xmax = -1.0e6;
	ymin = 1.0e6; ymax = -1.0e6;
	zmin = 1.0e6; zmax = -1.0e6;

	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		flrlvl = NULL;
		ceillvl = NULL;
		vtx1 = NULL;
		vtx2 = NULL;
		vtx3 = NULL;
		vtx4 = NULL;

		// - find boundary levels and vertices
		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->flrSrefPlnrMLevel, &flrlvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->flrSrefPlnrMLevel, &flrlvl);

		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->ceilSrefPlnrMLevel, &ceillvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->ceilSrefPlnrMLevel, &ceillvl);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx1SrefPlnrMVertex, &vtx1))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx1SrefPlnrMVertex, &vtx1);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx2SrefPlnrMVertex, &vtx2))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx2SrefPlnrMVertex, &vtx2);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx3SrefPlnrMVertex, &vtx3))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx3SrefPlnrMVertex, &vtx3);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx4SrefPlnrMVertex, &vtx4))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx4SrefPlnrMVertex, &vtx4);

		// - adapt range
		if (flrlvl) {
			if (flrlvl->z < zmin) zmin = flrlvl->z;
			if (flrlvl->z > zmax) zmax = flrlvl->z;
		};
		if (ceillvl) {
			if (ceillvl->z < zmin) zmin = ceillvl->z;
			if (ceillvl->z > zmax) zmax = ceillvl->z;
		};
		if (vtx1) {
			if (vtx1->x < xmin) xmin = vtx1->x;
			if (vtx1->x > xmax) xmax = vtx1->x;
			if (vtx1->y < ymin) ymin = vtx1->y;
			if (vtx1->y > ymax) ymax = vtx1->y;
		};
		if (vtx2) {
			if (vtx2->x < xmin) xmin = vtx2->x;
			if (vtx2->x > xmax) xmax = vtx2->x;
			if (vtx2->y < ymin) ymin = vtx2->y;
			if (vtx2->y > ymax) ymax = vtx2->y;
		};
		if (vtx3) {
			if (vtx3->x < xmin) xmin = vtx3->x;
			if (vtx3->x > xmax) xmax = vtx3->x;
			if (vtx3->y < ymin) ymin = vtx3->y;
			if (vtx3->y > ymax) ymax = vtx3->y;
		};
		if (vtx4) {
			if (vtx4->x < xmin) xmin = vtx4->x;
			if (vtx4->x > xmax) xmax = vtx4->x;
			if (vtx4->y < ymin) ymin = vtx4->y;
			if (vtx4->y > ymax) ymax = vtx4->y;
		};

		if (flrlvl) delete flrlvl;
		if (ceillvl) delete ceillvl;
		if (vtx1) delete vtx1;
		if (vtx2) delete vtx2;
		if (vtx3) delete vtx3;
		if (vtx4) delete vtx4;
	};

	// -- determine layers overlapping with range
	for (unsigned int j=0;j<lyrs.nodes.size();j++) lyracts[j] = ((lyrzmins[j] < zmax) && (lyrzmaxs[j] > zmin));

	// -- traverse design blocks and add structure primitives
	dbsplnr->tblplnrmblock->loadRstByDsn(refPlnrMDesign, false, blks);

	refPlnrMStructure = 0;

	faceix = 0;
	edgeix = 0;
	layerix = 0;

	for (unsigned int j=0;j<blks.nodes.size();j++) {
		blk = blks.nodes[j];

		// check layer for overlap with range
		lyrix = lyrics[blk->refPlnrMLayer];
		if (lyracts[lyrix]) {
			lyr = lyrs.nodes[lyrix];
			lyrzmin = lyrzmins[lyrix];
			lyrzmax = lyrzmaxs[lyrix];

			// load structure
			dbsplnr->tblplnrmstructure->loadRecByRef(blk->refPlnrMStructure, &sru);

			// check structure for overlap with range
			if ((sru->x0 < xmax) && (sru->x1 > xmin) && (sru->y0 < ymax) && (sru->y1 > ymin)) {

				if (sru->ref != refPlnrMStructure) {
					// new structure
					refPlnrMStructure = sru->ref;
					srufaceix0 = faceix;
					srulayerix0 = layerix;

					// single layer of current block
					lyrz0.push_back(lyrzmin);
					lyrz1.push_back(lyrzmax);
					ixMats.push_back(matics[lyr->refPlnrMMaterial]);
					layerix++;

					// load faces
					dbsplnr->tblplnrmface->loadRstBySru(sru->ref, false, fces);
					for (unsigned int k=0;k<fces.nodes.size();k++) {
						fce = fces.nodes[k];

						dbsplnr->tblplnrrmfacemvertex->loadRstByFce(fce->ref, false, frvs);
						if (frvs.nodes.size() > 0) {
							// check face for overlap with range (for now, consider vertex positions only)
							for (unsigned int l=0;l<frvs.nodes.size();l++) {
								frv = frvs.nodes[l];
								vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];

								if (l == 0) {
									fcexmin = vtx->x;
									fcexmax = vtx->x;
									fceymin = vtx->y;
									fceymax = vtx->y;
								};

								if (vtx->x < fcexmin) fcexmin = vtx->x;
								if (vtx->x > fcexmax) fcexmax = vtx->x;
								if (vtx->y < fceymin) fceymin = vtx->y;
								if (vtx->y > fceymax) fceymax = vtx->y;
							};

							if ((fcexmin < xmax) && (fcexmax > xmin) && (fceymin < ymax) && (fceymax > ymin)) {
								fceedgeix0 = edgeix;
								ixEdges0.push_back(edgeix);

								// traverse edges
								for (unsigned int l=0;l<frvs.nodes.size();l++) {
									frv = frvs.nodes[l];

									vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];
									if (l == (frvs.nodes.size()-1)) {
										vtx2 = vtxs.nodes[vtxics[frvs.nodes[0]->refPlnrMVertex]];
									} else {
										vtx2 = vtxs.nodes[vtxics[frvs.nodes[l+1]->refPlnrMVertex]];
									};

									if (l == 0) {
										// new face
										x0.push_back(fcexmin);
										x1.push_back(fcexmax);
										y0.push_back(fceymin);
										y1.push_back(fceymax);
										z0.push_back(lyrzmin);
										z1.push_back(lyrzmax);
									};

									// edge
									if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
										ag.push_back(false);
										lx0.push_back(vtx->x);
										ly0.push_back(vtx->y);
										ldx.push_back(vtx2->x - vtx->x);
										ldy.push_back(vtx2->y - vtx->y);
										accw.push_back(false); ax0.push_back(0.0); ay0.push_back(0.0); ar.push_back(0.0); aphi0.push_back(0.0); aphi1.push_back(0.0);

									} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
										agd = agds.nodes[agdics[frv->rteUref]];
										vtxctr = vtxs.nodes[vtxics[agd->ctrRefPlnrMVertex]];

										ag.push_back(true);
										lx0.push_back(0.0); ly0.push_back(0.0); ldx.push_back(0.0); ldy.push_back(0.0);
										accw.push_back(frv->ixVDir == VecPlnrVRMFaceMVertexDir::FWD);
										ax0.push_back(vtxctr->x);
										ay0.push_back(vtxctr->y);
										ar.push_back(agd->r);
										aphi0.push_back(atan2(vtx->y-vtxctr->y, vtx->x-vtxctr->x));
										aphi1.push_back(atan2(vtx2->y-vtxctr->y, vtx2->x-vtxctr->x));
									};

									edgeix++;
								};

								// find normalized vector that is non-coplanar to all face edges
								found = false;
								while (!found) {
									d = pi * ((double) rand()) / (((double) RAND_MAX) + 1.0);
									e = cos(d);
									f = sin(d);

									found = true;
									for (unsigned int l=fceedgeix0;l<edgeix;l++) {
										if (!ag[l]) {
											// calculate dot product
											d = (e*ldx[l] + f*ldy[l]) / sqrt(pow(ldx[l], 2) + pow(ldy[l], 2));

											if ((d < -0.95) || (d > 0.95)) {
												found = false;
												break;
											};
										};
									};
								};
								pdx.push_back(e);
								pdy.push_back(f);

								ixEdges1.push_back(edgeix);

								// all layers of the current structure (one at this time)
								ixLayers0.push_back(srulayerix0);
								ixLayers1.push_back(layerix);

								faceix++;
							};
						};
					};

				} else {
					// previous structure (block referring to different active layer)
					lyrz0.push_back(lyrzmin);
					lyrz1.push_back(lyrzmax);
					ixMats.push_back(matics[lyr->refPlnrMMaterial]);
					layerix++;

					// adapt face z
					for (unsigned int k=srufaceix0;k<faceix;k++) {
						if (lyrzmin < z0[k]) z0[k] = lyrzmin;
						if (lyrzmax > z1[k]) z1[k] = lyrzmax;
						ixLayers1[k] = layerix;
					};
				};
			};
			delete sru;
		};
	};

	// add virtual face for fill stack
	x0.push_back(-1.0e6);
	x1.push_back(1.0e6);
	y0.push_back(-1.0e6);
	y1.push_back(1.0e6);
	z0.push_back(-1.0e6);
	z1.push_back(1.0e6);
	pdx.push_back(cos(0.25*pi));
	pdy.push_back(sin(0.25*pi));
	ixEdges0.push_back(edgeix);
	ixEdges1.push_back(edgeix);
	ixLayers0.push_back(layerix);

	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		if (lyracts[j]) {
			lyr = lyrs.nodes[j];

			if (lyr->sref.find("fill.") == 0) {
				// identification by sref
				lyrzmin = lyrzmins[j];
				if (lyrzmin <= zmin) lyrzmin = -1.0e6;
				lyrzmax = lyrzmaxs[j];
				if (lyrzmax >= zmax) lyrzmax = 1.0e6;

				lyrz0.push_back(lyrzmin);
				lyrz1.push_back(lyrzmax);
				ixMats.push_back(matics[lyr->refPlnrMMaterial]);
				layerix++;
			};
		};
	};

	ixLayers1.push_back(layerix);

	// -- write general variables to cdf file, definitions first
	nc_redef(cdfRoot);
		nc_def_dim(cdfRoot, "dimFaces", x0.size(), &cdfDim);
		nc_def_grp(cdfRoot, "faces", &cdfFaces);
			nc_def_var(cdfFaces, "x0", NC_DOUBLE, 1, &cdfDim, &cdfX0);
			nc_def_var(cdfFaces, "x1", NC_DOUBLE, 1, &cdfDim, &cdfX1);
			nc_def_var(cdfFaces, "y0", NC_DOUBLE, 1, &cdfDim, &cdfY0);
			nc_def_var(cdfFaces, "y1", NC_DOUBLE, 1, &cdfDim, &cdfY1);
			nc_def_var(cdfFaces, "pdx", NC_DOUBLE, 1, &cdfDim, &cdfPdx);
			nc_def_var(cdfFaces, "pdy", NC_DOUBLE, 1, &cdfDim, &cdfPdy);
			nc_def_var(cdfFaces, "z0", NC_DOUBLE, 1, &cdfDim, &cdfZ0);
			nc_def_var(cdfFaces, "z1", NC_DOUBLE, 1, &cdfDim, &cdfZ1);
			nc_def_var(cdfFaces, "ixEdges0", NC_UINT, 1, &cdfDim, &cdfIxEdges0);
			nc_def_var(cdfFaces, "ixEdges1", NC_UINT, 1, &cdfDim, &cdfIxEdges1);
			nc_def_var(cdfFaces, "ixLayers0", NC_UINT, 1, &cdfDim, &cdfIxLayers0);
			nc_def_var(cdfFaces, "ixLayers1", NC_UINT, 1, &cdfDim, &cdfIxLayers1);
		nc_def_dim(cdfRoot, "dimEdges", ag.size(), &cdfDim);
		nc_def_grp(cdfRoot, "edges", &cdfEdges);
			nc_def_var(cdfEdges, "ag", NC_UBYTE, 1, &cdfDim, &cdfAg);
			nc_def_var(cdfEdges, "lx0", NC_DOUBLE, 1, &cdfDim, &cdfLx0);
			nc_def_var(cdfEdges, "ly0", NC_DOUBLE, 1, &cdfDim, &cdfLy0);
			nc_def_var(cdfEdges, "ldx", NC_DOUBLE, 1, &cdfDim, &cdfLdx);
			nc_def_var(cdfEdges, "ldy", NC_DOUBLE, 1, &cdfDim, &cdfLdy);
			nc_def_var(cdfEdges, "accw", NC_UBYTE, 1, &cdfDim, &cdfAccw);
			nc_def_var(cdfEdges, "ax0", NC_DOUBLE, 1, &cdfDim, &cdfAx0);
			nc_def_var(cdfEdges, "ay0", NC_DOUBLE, 1, &cdfDim, &cdfAy0);
			nc_def_var(cdfEdges, "ar", NC_DOUBLE, 1, &cdfDim, &cdfAr);
			nc_def_var(cdfEdges, "aphi0", NC_DOUBLE, 1, &cdfDim, &cdfAphi0);
			nc_def_var(cdfEdges, "aphi1", NC_DOUBLE, 1, &cdfDim, &cdfAphi1);
		nc_def_dim(cdfRoot, "dimLayers", lyrz0.size(), &cdfDim);
		nc_def_grp(cdfRoot, "layers", &cdfLayers);
			nc_def_var(cdfLayers, "z0", NC_DOUBLE, 1, &cdfDim, &cdfLyrz0);
			nc_def_var(cdfLayers, "z1", NC_DOUBLE, 1, &cdfDim, &cdfLyrz1);
			nc_def_var(cdfLayers, "ixMats", NC_UINT, 1, &cdfDim, &cdfIxMats);
		nc_def_dim(cdfRoot, "dimMats", mats.size(), &cdfDim);
		nc_def_var(cdfRoot, "mats", NC_UINT64, 1, &cdfDim, &cdfMats);
		nc_def_grp(cdfRoot, "doms", &cdfDoms);
	nc_enddef(cdfRoot);

	Cdf::putDoubleVec(cdfFaces, cdfX0, x0);
	Cdf::putDoubleVec(cdfFaces, cdfX1, x1);
	Cdf::putDoubleVec(cdfFaces, cdfY0, y0);
	Cdf::putDoubleVec(cdfFaces, cdfY1, y1);
	Cdf::putDoubleVec(cdfFaces, cdfPdx, pdx);
	Cdf::putDoubleVec(cdfFaces, cdfPdy, pdy);
	Cdf::putDoubleVec(cdfFaces, cdfZ0, z0);
	Cdf::putDoubleVec(cdfFaces, cdfZ1, z1);
	Cdf::putUintVec(cdfFaces, cdfIxEdges0, ixEdges0);
	Cdf::putUintVec(cdfFaces, cdfIxEdges1, ixEdges1);
	Cdf::putUintVec(cdfFaces, cdfIxLayers0, ixLayers0);
	Cdf::putUintVec(cdfFaces, cdfIxLayers1, ixLayers1);

	Cdf::putBoolVec(cdfEdges, cdfAg, ag);
	Cdf::putDoubleVec(cdfEdges, cdfLx0, lx0);
	Cdf::putDoubleVec(cdfEdges, cdfLy0, ly0);
	Cdf::putDoubleVec(cdfEdges, cdfLdx, ldx);
	Cdf::putDoubleVec(cdfEdges, cdfLdy, ldy);
	Cdf::putBoolVec(cdfEdges, cdfAccw, accw);
	Cdf::putDoubleVec(cdfEdges, cdfAx0, ax0);
	Cdf::putDoubleVec(cdfEdges, cdfAy0, ay0);
	Cdf::putDoubleVec(cdfEdges, cdfAr, ar);
	Cdf::putDoubleVec(cdfEdges, cdfAphi0, aphi0);
	Cdf::putDoubleVec(cdfEdges, cdfAphi1, aphi1);

	Cdf::putDoubleVec(cdfLayers, cdfLyrz0, lyrz0);
	Cdf::putDoubleVec(cdfLayers, cdfLyrz1, lyrz1);
	Cdf::putUintVec(cdfLayers, cdfIxMats, ixMats);

	Cdf::putUbigintVec(cdfRoot, cdfMats, mats);

	// -- traverse domains to determine individual coordinate transforms
	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		hasx = ((dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ));
		hasxy = ((dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ));
		hasz = ((dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ));

		Plnr::getDomrast(dbsplnr, dom, refModdsn, dx, dy, dxy, dz);

		flrlvl = NULL;
		ceillvl = NULL;
		vtx1 = NULL;
		vtx2 = NULL;
		vtx3 = NULL;
		vtx4 = NULL;

		// find boundary levels and vertices
		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->flrSrefPlnrMLevel, &flrlvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->flrSrefPlnrMLevel, &flrlvl);

		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->ceilSrefPlnrMLevel, &ceillvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->ceilSrefPlnrMLevel, &ceillvl);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx1SrefPlnrMVertex, &vtx1))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx1SrefPlnrMVertex, &vtx1);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx2SrefPlnrMVertex, &vtx2))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx2SrefPlnrMVertex, &vtx2);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx3SrefPlnrMVertex, &vtx3))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx3SrefPlnrMVertex, &vtx3);

		if (!dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refModdsn, dom->vtx4SrefPlnrMVertex, &vtx4))
			dbsplnr->tblplnrmvertex->loadRecByHktHkuSrf(VecPlnrVMVertexHkTbl::DSN, refBasedsn, dom->vtx4SrefPlnrMVertex, &vtx4);

		// determine coordinate transform, from domain-centered coordinates to design coordinates
		if (dom->ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) {
			_x0 = -0.5*sqrt(pow(vtx2->x-vtx1->x, 2) + pow(vtx2->y-vtx1->y, 2));
			_x1 = -_x0;
			_dx = (_x1-_x0) / ceil((_x1-_x0) / dx);

			_y0 = -0.5*sqrt(pow(vtx4->x-vtx1->x, 2) + pow(vtx4->y-vtx1->y, 2));
			_y1 = -_y0;
			_dy = (_y1-_y0) / ceil((_y1-_y0) / dy);

			_z0 = -0.5*(ceillvl->z - flrlvl->z);
			_z1 = -_z0;
			_dz = (_z1-_z0) / ceil((_z1-_z0) / dz);

			phi = atan2(vtx2->y-vtx1->y, vtx2->x-vtx1->x);
			a11 = cos(phi);
			a21 = sin(phi);

			b1 = 0.5*(vtx2->x + vtx4->x);
			b2 = 0.5*(vtx2->y + vtx4->y);
			b3 = 0.5*(ceillvl->z + flrlvl->z);

			dimX = lround(fabs((_x1-_x0) / _dx)) + 1;
			dimY = lround(fabs((_y1-_y0) / _dy)) + 1;
			dimZ = lround(fabs((_z1-_z0) / _dz)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
			// dxy/dz relevant discretization parameters, dx/dy not used
			_xy0 = -0.5*sqrt(pow(vtx2->x-vtx1->x, 2) + pow(vtx2->y-vtx1->y, 2));
			_xy1 = -_xy0;
			_dxy = (_xy1-_xy0) / ceil((_xy1-_xy0) / dxy);

			_z0 = -0.5*(ceillvl->z - flrlvl->z);
			_z1 = -_z0;
			_dz = (_z1-_z0) / ceil((_z1-_z0) / dz);

			phi = atan2(vtx2->y-vtx1->y, vtx2->x-vtx1->x);
			a11 = cos(phi);
			a21 = sin(phi);

			b1 = 0.5*(vtx1->x + vtx2->x);
			b2 = 0.5*(vtx1->y + vtx2->y);
			b3 = 0.5*(ceillvl->z + flrlvl->z);

			dimXY = lround(fabs((_xy1-_xy0) / _dxy)) + 1;
			dimZ = lround(fabs((_z1-_z0) / _dz)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) {
			// dx/dy relevant discretization parameters, dxy/dz not used
			_x0 = -0.5*sqrt(pow(vtx2->x-vtx1->x, 2) + pow(vtx2->y-vtx1->y, 2));
			_x1 = -_x0;
			_dx = (_x1-_x0) / ceil((_x1-_x0) / dx);

			_y0 = -0.5*sqrt(pow(vtx4->x-vtx1->x, 2) + pow(vtx4->y-vtx1->y, 2));
			_y1 = -_y0;
			_dy = (_y1-_y0) / ceil((_y1-_y0) / dy);

			phi = atan2(vtx2->y-vtx1->y, vtx2->x-vtx1->x);
			a11 = cos(phi);
			a21 = sin(phi);
			
			b1 = 0.5*(vtx2->x + vtx4->x);
			b2 = 0.5*(vtx2->y + vtx4->y);
			b3 = flrlvl->z;

			dimX = lround(fabs((_x1-_x0) / _dx)) + 1;
			dimY = lround(fabs((_y1-_y0) / _dy)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
			// dz relevant discretization parameter, dx/dy/dxy not used
			_z0 = -0.5*(ceillvl->z - flrlvl->z);
			_z1 = -_z0;
			_dz = (_z1-_z0) / ceil((_z1-_z0) / dz);
			
			b1 = vtx1->x;
			b2 = vtx1->y;
			b3 = 0.5*(ceillvl->z + flrlvl->z);

			dimZ = lround(fabs((_z1-_z0) / _dz)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
			// dxy relevant discretization parameter, dx/dy/dz not used
			_xy0 = -0.5*sqrt(pow(vtx2->x-vtx1->x, 2) + pow(vtx2->y-vtx1->y, 2));
			_xy1 = -_xy0;
			_dxy = (_xy1-_xy0) / ceil((_xy1-_xy0) / dxy);

			phi = atan2(vtx2->y-vtx1->y, vtx2->x-vtx1->x);
			a11 = cos(phi);
			a21 = sin(phi);

			b1 = 0.5*(vtx1->x + vtx2->x);
			b2 = 0.5*(vtx1->y + vtx2->y);
			b3 = flrlvl->z;

			dimXY = lround(fabs((_xy1-_xy0) / _dxy)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) {
			b1 = vtx1->x;
			b2 = vtx1->y;
			b3 = flrlvl->z;
		};

		if (flrlvl) delete flrlvl;
		if (ceillvl) delete ceillvl;
		if (vtx1) delete vtx1;
		if (vtx2) delete vtx2;
		if (vtx3) delete vtx3;
		if (vtx4) delete vtx4;

		// - write domain-specific variables to cdf file, definitions first
		nc_redef(cdfRoot);
			nc_def_grp(cdfDoms, dom->sref.c_str(), &cdfDom);
				if (hasx) {
					nc_def_dim(cdfDom, "dimX", dimX, &cdfDim);
					nc_def_dim(cdfDom, "dimY", dimY, &cdfDim);
				};
				if (hasxy) nc_def_dim(cdfDom, "dimXY", dimXY, &cdfDim);
				if (hasz) nc_def_dim(cdfDom, "dimZ", dimZ, &cdfDim);
				nc_def_var(cdfDom, "ixVBasetype", NC_UINT, 0, NULL, &cdf_ixVBasetype);
				if (hasx) {
					nc_def_var(cdfDom, "x0", NC_DOUBLE, 0, NULL, &cdf_x0);
					nc_def_var(cdfDom, "x1", NC_DOUBLE, 0, NULL, &cdf_x1);
					nc_def_var(cdfDom, "dx", NC_DOUBLE, 0, NULL, &cdf_dx);
					nc_def_var(cdfDom, "y0", NC_DOUBLE, 0, NULL, &cdf_y0);
					nc_def_var(cdfDom, "y1", NC_DOUBLE, 0, NULL, &cdf_y1);
					nc_def_var(cdfDom, "dy", NC_DOUBLE, 0, NULL, &cdf_dy);
				};
				if (hasxy) {
					nc_def_var(cdfDom, "xy0", NC_DOUBLE, 0, NULL, &cdf_xy0);
					nc_def_var(cdfDom, "xy1", NC_DOUBLE, 0, NULL, &cdf_xy1);
					nc_def_var(cdfDom, "dxy", NC_DOUBLE, 0, NULL, &cdf_dxy);
				};
				if (hasz) {
					nc_def_var(cdfDom, "z0", NC_DOUBLE, 0, NULL, &cdf_z0);
					nc_def_var(cdfDom, "z1", NC_DOUBLE, 0, NULL, &cdf_z1);
					nc_def_var(cdfDom, "dz", NC_DOUBLE, 0, NULL, &cdf_dz);
				};
				if (hasx || hasxy) {
					nc_def_var(cdfDom, "a11", NC_DOUBLE, 0, NULL, &cdf_a11);
					nc_def_var(cdfDom, "a21", NC_DOUBLE, 0, NULL, &cdf_a21);
				};
				nc_def_var(cdfDom, "b1", NC_DOUBLE, 0, NULL, &cdf_b1);
				nc_def_var(cdfDom, "b2", NC_DOUBLE, 0, NULL, &cdf_b2);
				nc_def_var(cdfDom, "b3", NC_DOUBLE, 0, NULL, &cdf_b3);
		nc_enddef(cdfRoot);
		if (hasx) {
			nc_put_var_double(cdfDom, cdf_x0, &_x0);
			nc_put_var_double(cdfDom, cdf_x1, &_x1);
			nc_put_var_double(cdfDom, cdf_dx, &_dx);
			nc_put_var_double(cdfDom, cdf_y0, &_y0);
			nc_put_var_double(cdfDom, cdf_y1, &_y1);
			nc_put_var_double(cdfDom, cdf_dy, &_dy);
		};
		if (hasxy) {
			nc_put_var_double(cdfDom, cdf_xy0, &_xy0);
			nc_put_var_double(cdfDom, cdf_xy1, &_xy1);
			nc_put_var_double(cdfDom, cdf_dxy, &_dxy);
		};
		if (hasz) {
			nc_put_var_double(cdfDom, cdf_z0, &_z0);
			nc_put_var_double(cdfDom, cdf_z1, &_z1);
			nc_put_var_double(cdfDom, cdf_dz, &_dz);
		};
		nc_put_var_double(cdfDom, cdf_a11, &a11);
		nc_put_var_double(cdfDom, cdf_a21, &a21);
		nc_put_var_double(cdfDom, cdf_b1, &b1);
		nc_put_var_double(cdfDom, cdf_b2, &b2);
		nc_put_var_double(cdfDom, cdf_b3, &b3);
		nc_put_var_uint(cdfDom, cdf_ixVBasetype, &(dom->ixVBasetype)); // this doesn't work if put in first place
	};

	nc_close(cdfRoot);

	// -- add file to archive and return ref
	refIxVTbl = VecPlnrVMFileRefTbl::VOID;
	refUref = 0;

	dbsplnr->tblplnrmdesign->loadRecByRef(refPlnrMDesign, &dsn);

	if (dsn) {
		if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CAL) {
			refIxVTbl = VecPlnrVMFileRefTbl::CAL;
			Filename = "rast.cdf";

		} else if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CLI) {
			dbsplnr->tblplnrmcalcitem->loadRecByRef(dsn->refUref, &cli);

			refIxVTbl = VecPlnrVMFileRefTbl::CLI;
			Filename = "rast_" + cli->Title + ".cdf";
		};

		refUref = dsn->refUref;
	};

	dpchret->refPlnrMFile = Acv::addfile(dbsplnr, xchg->acvpath, fullpath.str(), refIxVTbl, refUref, "rast", Filename, "nc", "");

	if (dsn) {
		if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CAL) {
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, 0, dsn->refUref, dpchret->refPlnrMFile, VecPlnrVRMCalcMFileIo::IMD);

		} else if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CLI) {
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, dsn->refUref, cli->calRefPlnrMCalc, dpchret->refPlnrMFile, VecPlnrVRMCalcMFileIo::IMD);

			delete cli;
		};

		delete dsn;
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


