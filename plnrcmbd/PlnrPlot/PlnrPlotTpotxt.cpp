/**
  * \file PlnrPlotTpotxt.cpp
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

#include "PlnrPlotTpotxt.h"

DpchRetPlnrPlotTpotxt* PlnrPlotTpotxt::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrPlotTpotxt* dpchinv
		) {
	DpchRetPlnrPlotTpotxt* dpchret = new DpchRetPlnrPlotTpotxt();

	bool fmtcif = dpchinv->fmtcif;
	bool fmtraith = dpchinv->fmtraith;
	double rast = dpchinv->rast;
	ubigint refPlnrMTapeout = dpchinv->refPlnrMTapeout;

// IP run --- IBEGIN
	ostringstream sqlstr;
	ostringstream str;

	string outfolder;
	string outpath;

	fstream outfile;

	PlnrMTapeout* tpo = NULL;

	ListPlnrMReticle rtcs;
	PlnrMReticle* rtc = NULL;

	vector<ubigint> refsDsn;
	ubigint refPlnrMDesign;

	vector<ubigint> refsLyr;
	ubigint refPlnrMLayer;

	map<ubigint, unsigned int> blkfce2ix0s; // indices to fce2 for each blk
	map<ubigint, unsigned int> blkfce2ix1s;
	unsigned int blkfce2ix0, blkfce2ix1;

	// fce2 actually is non-existent, it is implemented as an index counter
	unsigned int fce2cnt = 0;

	vector<unsigned int> fce2xyix0s; // indices to xs, ys for each fce2
	vector<unsigned int> fce2xyix1s;
	unsigned int fce2xyix0, fce2xyix1;

	vector<double> xs; // polygon vertex coordinates
	vector<double> ys;

	ListPlnrMVertex vtxs;
	PlnrMVertex* vtx = NULL;
	PlnrMVertex* vtx2 = NULL;
	PlnrMVertex* vtx3 = NULL;
	map<ubigint, unsigned int> vtxics;

	ListPlnrMArcguide ags;
	PlnrMArcguide* ag = NULL;
	map<ubigint, unsigned int> agics;

	vector<unsigned int> agarvix0s; // indices to arvs for each ag
	vector<unsigned int> agarvix1s;
	unsigned int agarvix0, agarvix1;

	ListPlnrLRMArcguideMVertex arvs;
	PlnrLRMArcguideMVertex* arv = NULL;
	unsigned int arvix0, arvix1;

	vector<unsigned int> arvarvxsix0s; // indices to arvxs, arvys for each arv
	vector<unsigned int> arvarvxsix1s;
	unsigned int arvarvxsix0, arvarvxsix1;

	vector<double> arvxs;
	vector<double> arvys;

	ListPlnrMBlock blks;
	PlnrMBlock* blk = NULL;
	unsigned int blkcnt;

	ListPlnrMFace fces;
	PlnrMFace* fce = NULL;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	double dphimax, dphi;
	unsigned int N;

	double a11, a22, b1, b2;
	double x, y;

	string flipstr;

	dbsplnr->tblplnrmtapeout->loadRecByRef(refPlnrMTapeout, &tpo);

	// --- prepare polygons exactly once for each block used
	sqlstr.str(""); sqlstr << "SELECT DISTINCT refPlnrMDesign FROM TblPlnrMReticle WHERE hkIxVTbl = " << VecPlnrVMReticleHkTbl::TPO << " AND hkUref = " << refPlnrMTapeout;
	dbsplnr->loadRefsBySQL(sqlstr.str(), false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		refPlnrMDesign = refsDsn[i];

		// -- prepare design primitives
		dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, false, vtxs);
		vtxics.clear();
		for (unsigned int j=0;j<vtxs.nodes.size();j++) vtxics[vtxs.nodes[j]->ref] = j;

		dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DSN, refPlnrMDesign, false, ags);
		agics.clear();
		for (unsigned int j=0;j<ags.nodes.size();j++) agics[ags.nodes[j]->ref] = j;

		// rasterize arc guides
		agarvix0s.resize(0);
		agarvix1s.resize(0);

		arvs.clear();

		arvarvxsix0s.resize(0);
		arvarvxsix1s.resize(0);

		arvxs.resize(0);
		arvys.resize(0);

		for (unsigned int j=0;j<ags.nodes.size();j++) {
			ag = ags.nodes[j];
			vtx = vtxs.nodes[vtxics[ag->ctrRefPlnrMVertex]];
			dphimax = rast/ag->r;

			agarvix0 = arvs.nodes.size();
			agarvix0s.push_back(agarvix0);

			dbsplnr->tblplnrlrmarcguidemvertex->loadRstByAgd(ag->ref, true, arvs);

			agarvix1 = arvs.nodes.size();
			agarvix1s.push_back(agarvix1);

			// for each arc segment, check whether it exceeds the minimum angular length
			for (unsigned int k=agarvix0;k<agarvix1;k++) {
				arv = arvs.nodes[k];

				arvarvxsix0s.push_back(arvxs.size());

				vtx2 = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
				if (k == (agarvix1-1)) vtx3 = vtxs.nodes[vtxics[arvs.nodes[agarvix0]->refPlnrMVertex]];
				else vtx3 = vtxs.nodes[vtxics[arvs.nodes[k+1]->refPlnrMVertex]];

				// determine angle between consecutive vertices on arcguide
				dphi = ((vtx3->x-vtx->x)*(vtx2->x-vtx->x) + (vtx3->y-vtx->y)*(vtx2->y-vtx->y)) / pow(ag->r, 2);
				if (dphi > 1.0) dphi = 1.0;
				if (dphi < -1.0) dphi = -1.0;
				dphi = acos(dphi);

				if (dphi > dphimax) {
					// add extra vertices
					N = lround(ceil(dphi/dphimax));
					dphi = dphi / ((double) N);

					for (unsigned int l=1;l<N;l++) {
						arvxs.push_back(vtx->x + ag->r*cos(atan2(vtx2->y-vtx->y, vtx2->x-vtx->x) + ((double) l)*dphi));
						arvys.push_back(vtx->y + ag->r*sin(atan2(vtx2->y-vtx->y, vtx2->x-vtx->x) + ((double) l)*dphi));
					};
				};

				arvarvxsix1s.push_back(arvxs.size());
			};
		};

		// -- determine faces to be polygonized via reticle layer -> block
		sqlstr.str(""); sqlstr << "SELECT DISTINCT refPlnrMLayer FROM TblPlnrMReticle WHERE hkIxVTbl = " << VecPlnrVMReticleHkTbl::TPO << " AND hkUref = " << refPlnrMTapeout
					<< " AND refPlnrMDesign = " << refPlnrMDesign;
		dbsplnr->loadRefsBySQL(sqlstr.str(), false, refsLyr);

		for (unsigned int j=0;j<refsLyr.size();j++) {
			refPlnrMLayer = refsLyr[j];

			dbsplnr->tblplnrmblock->loadRstByDsnLyr(refPlnrMDesign, refPlnrMLayer, false, blks);
			for (unsigned int o=0;o<blks.nodes.size();o++) {
				blk = blks.nodes[o];

				blkfce2ix0s[blk->ref] = fce2cnt;

				dbsplnr->tblplnrmface->loadRstByDsnSru(0, blk->refPlnrMStructure, false, fces);
				for (unsigned int k=0;k<fces.nodes.size();k++) {
					fce = fces.nodes[k];

					fce2xyix0s.push_back(xs.size());

					dbsplnr->tblplnrrmfacemvertex->loadRstByFce(fce->ref, false, frvs);
					for (unsigned int l=0;l<frvs.nodes.size();l++) {
						frv = frvs.nodes[l];
						vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];

						if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
							// simple treatment for lineguide segments
							xs.push_back(vtx->x);
							ys.push_back(vtx->y);

						} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
							// special treatment for arc segments
							ag = ags.nodes[agics[frv->rteUref]];

							agarvix0 = agarvix0s[agics[frv->rteUref]];
							agarvix1 = agarvix1s[agics[frv->rteUref]];

							// find begin/end arv's
							for (unsigned int m=agarvix0;m<agarvix1;m++) {
								arv = arvs.nodes[m];

								if (arv->refPlnrMVertex == vtx->ref) arvix0 = m;
								if (l == (frvs.nodes.size()-1)) {
									if (arv->refPlnrMVertex == frvs.nodes[0]->refPlnrMVertex) arvix1 = m;
								} else {
									if (arv->refPlnrMVertex == frvs.nodes[l+1]->refPlnrMVertex) arvix1 = m;
								};
							};

							// add intermediate vertices
							if (frv->ixVDir == VecPlnrVRMFaceMVertexDir::FWD) {
								// forward
								for (unsigned int m=arvix0;m!=arvix1;) {
									arv = arvs.nodes[m];

									vtx = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
									
									xs.push_back(vtx->x);
									ys.push_back(vtx->y);

									// include all extra vertices up to the next vertex
									arvarvxsix0 = arvarvxsix0s[m];
									arvarvxsix1 = arvarvxsix1s[m];
									for (unsigned int n=arvarvxsix0;n<arvarvxsix1;n++) {
										xs.push_back(arvxs[n]);
										ys.push_back(arvys[n]);
									};

									m++;
									if (m >= agarvix1) m = agarvix0;
								};

							} else {
								// backward
								for (unsigned int m=arvix0;m!=arvix1;) {
									arv = arvs.nodes[m];

									vtx = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
									xs.push_back(vtx->x);
									ys.push_back(vtx->y);

									if (m != 0) { // unsigned int precaution
										m--;
										if (m < agarvix0) m = agarvix1-1;
									} else {
										m = agarvix1-1;
									};

									// include all extra vertices up to the next vertex
									arvarvxsix0 = arvarvxsix0s[m];
									arvarvxsix1 = arvarvxsix1s[m];

									if (arvarvxsix1 > arvarvxsix0) { // unsigned int precaution
										for (unsigned int n=(arvarvxsix1-1);n>=arvarvxsix0;n--) {
											xs.push_back(arvxs[n]);
											ys.push_back(arvys[n]);
											
											if (n == 0) break; // unsigned int precaution
										};
									};
								};
							};
						};
					};

					fce2xyix1s.push_back(xs.size());
					fce2cnt++;
				};

				blkfce2ix1s[blk->ref] = fce2cnt;
			};
		};
	};

	// --- generate output depending on file format and tapeout type
	if (fmtcif && (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::PLN)) {
		outpath = Tmp::newfile(xchg->tmppath, "cif");

		str.str(""); str << xchg->tmppath << "/" << outpath;
		outfile.open(str.str().c_str(), ios::out);

		// -- each block as subroutine, only basic linear transform
		a11 = 1000.0;
		a22 = 1000.0;
		b1 = 0.0;
		b2 = 0.0;

		sqlstr.str(""); sqlstr << "SELECT DISTINCT refPlnrMDesign FROM TblPlnrMReticle WHERE hkIxVTbl = " << VecPlnrVMReticleHkTbl::TPO << " AND hkUref = " << refPlnrMTapeout;
		dbsplnr->loadRefsBySQL(sqlstr.str(), false, refsDsn);

		for (unsigned int i=0;i<refsDsn.size();i++) {
			refPlnrMDesign = refsDsn[i];

			sqlstr.str(""); sqlstr << "SELECT DISTINCT refPlnrMLayer FROM TblPlnrMReticle WHERE hkIxVTbl = " << VecPlnrVMReticleHkTbl::TPO << " AND hkUref = " << refPlnrMTapeout
						<< " AND refPlnrMDesign = " << refPlnrMDesign;
			dbsplnr->loadRefsBySQL(sqlstr.str(), false, refsLyr);

			for (unsigned int j=0;j<refsLyr.size();j++) {
				refPlnrMLayer = refsLyr[j];

				dbsplnr->tblplnrmblock->loadRstByDsnLyr(refPlnrMDesign, refPlnrMLayer, false, blks);
				for (unsigned int o=0;o<blks.nodes.size();o++) {
					blk = blks.nodes[o];

					blkfce2ix0 = blkfce2ix0s[blk->ref];
					blkfce2ix1 = blkfce2ix1s[blk->ref];

					outfile << "DS " << blk->ref << " 1 10;" << endl;
					outfile << "L A000;" << endl;

					// - each face as a previously defined polygon
					for (unsigned int blkfce2ix=blkfce2ix0 ; blkfce2ix<blkfce2ix1 ; blkfce2ix++) {
						fce2xyix0 = fce2xyix0s[blkfce2ix];
						fce2xyix1 = fce2xyix1s[blkfce2ix];

						outfile << "P";

						for (unsigned int fce2xyix=fce2xyix0 ; fce2xyix<fce2xyix1 ; fce2xyix++) {
							x = a11*xs[fce2xyix] + b1;
							y = a22*ys[fce2xyix] + b2;
							outfile << " " << lround(x) << "," << lround(y);
						};

						outfile << ";" << endl;
					};

					outfile << "DF;" << endl;
				};
			};
		};

		// -- recall subroutines according to reticle data (including translation and rotation)
		if (tpo->Hflip) flipstr = " MX;";
		else flipstr = ";";

		outfile << "DS 0 1 10;" << endl;
		dbsplnr->tblplnrmreticle->loadRstByHktHku(VecPlnrVMReticleHkTbl::TPO, refPlnrMTapeout, false, rtcs);

		for (unsigned int i=0;i<rtcs.nodes.size();i++) {
			rtc = rtcs.nodes[i];

			a11 = 1000.0;
			a22 = 1000.0;
			b1 = a11*rtc->x0;
			b2 = a22*rtc->y0;

			// recall structures (blocks) one by one
			dbsplnr->tblplnrmblock->loadRstByDsnLyr(rtc->refPlnrMDesign, rtc->refPlnrMLayer, false, blks);
			for (unsigned int j=0;j<blks.nodes.size();j++) {
				blk = blks.nodes[j];

				outfile << "C " << blk->ref << " R " << lround(cos(degToRad(rtc->phi))) << " " << lround(sin(degToRad(rtc->phi))) << " T " << lround(b1) << " " << lround(b2) << flipstr << endl;
			};
		};

		outfile << "DF;" << endl;

		// invocation of all; mirroring of x coordinate doesn't work with LayoutEditor
		outfile << "C 0;" << endl;
		outfile << "END;" << endl;

		outfile.close();

		dpchret->ciffile = outpath;
	} else {
		// ...
	};

/*
	dbsplnr->tblplnrmtapeout->loadRecByRef(refPlnrMTapeout, &tpo);
	dbsplnr->tblplnrmreticle->loadRstByHktHku(VecPlnrVMReticleHkTbl::TPO, refPlnrMTapeout, false, rtcs);

	if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::PLN) {
		// generate and open file in temp folder
		if (fmtcif) outpath = Tmp::newfile(xchg->tmppath, "cif");
		else if (fmtraith) outpath = Tmp::newfile(xchg->tmppath, "asc");

		str.str(""); str << xchg->tmppath << "/" << outpath;

		outfile.open(str.str().c_str(), ios::out);

	} else if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::BTCH) {
		// generate folder in temp folder
		outfolder = Tmp::newfolder(xchg->tmppath);
	};

	// traverse reticles
	refPlnrMDesign = 0;
	blkcnt = 1;
	for (unsigned int i=0;i<rtcs.nodes.size();i++) {
		rtc = rtcs.nodes[i];

		if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::BTCH) {
			// generate and open file
			if (fmtcif) {
				str.str(""); str << xchg->tmppath << "/" << outfolder << "/" << rtc->sref << ".cif";
			} else if (fmtraith) {
				str.str(""); str << xchg->tmppath << "/" << outfolder << "/" << rtc->sref << ".asc";
			};

			outfile.open(str.str().c_str(), ios::out);

			blkcnt = 1;
		};

		// linear transform
		if (fmtcif) {
			a11 = 1000.0;
			a22 = 1000.0;
		} else if (fmtraith) {
			a11 = 1.0;
			a22 = 1.0;
		};
		if (tpo->Hflip) a11 *= -1.0;

		b1 = a11*rtc->x0;
		b2 = a22*rtc->y0;

		if (rtc->refPlnrMDesign != refPlnrMDesign) {
			// different design
			refPlnrMDesign = rtc->refPlnrMDesign;

			// prepare design primitives
			dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DSN, refPlnrMDesign, false, vtxs);
			vtxics.clear();
			for (unsigned int j=0;j<vtxs.nodes.size();j++) vtxics[vtxs.nodes[j]->ref] = j;

			dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DSN, refPlnrMDesign, false, ags);
			agics.clear();
			for (unsigned int j=0;j<ags.nodes.size();j++) agics[ags.nodes[j]->ref] = j;

			// rasterize arc guides
			agarvix0s.resize(0);
			agarvix1s.resize(0);

			arvs.clear();

			arvarvxsix0s.resize(0);
			arvarvxsix1s.resize(0);

			arvxs.resize(0);
			arvys.resize(0);

			for (unsigned int j=0;j<ags.nodes.size();j++) {
				ag = ags.nodes[j];
				vtx = vtxs.nodes[vtxics[ag->ctrRefPlnrMVertex]];
				dphimax = rast/ag->r;

				agarvix0 = arvs.nodes.size();
				agarvix0s.push_back(agarvix0);

				dbsplnr->tblplnrlrmarcguidemvertex->loadRstByAgd(ag->ref, true, arvs);

				agarvix1 = arvs.nodes.size();
				agarvix1s.push_back(agarvix1);

				// for each arc segment, check whether it exceeds the minimum angular length
				for (unsigned int k=agarvix0;k<agarvix1;k++) {
					arv = arvs.nodes[k];

					arvarvxsix0s.push_back(arvxs.size());

					vtx2 = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
					if (k == (agarvix1-1)) vtx3 = vtxs.nodes[vtxics[arvs.nodes[agarvix0]->refPlnrMVertex]];
					else vtx3 = vtxs.nodes[vtxics[arvs.nodes[k+1]->refPlnrMVertex]];

					// determine angle between consecutive vertices on arcguide
					dphi = ((vtx3->x-vtx->x)*(vtx2->x-vtx->x) + (vtx3->y-vtx->y)*(vtx2->y-vtx->y)) / pow(ag->r, 2);
					if (dphi > 1.0) dphi = 1.0;
					if (dphi < -1.0) dphi = -1.0;
					dphi = acos(dphi);

					if (dphi > dphimax) {
						// add extra vertices
						N = lround(ceil(dphi/dphimax));
						dphi = dphi / ((double) N);

						for (unsigned int l=1;l<N;l++) {
							arvxs.push_back(vtx->x + ag->r*cos(atan2(vtx2->y-vtx->y, vtx2->x-vtx->x) + ((double) l)*dphi));
							arvys.push_back(vtx->y + ag->r*sin(atan2(vtx2->y-vtx->y, vtx2->x-vtx->x) + ((double) l)*dphi));
						};
					};

					arvarvxsix1s.push_back(arvxs.size());
				};
			};
		};

		// write structures (blocks) one by one
		dbsplnr->tblplnrmblock->loadRstByDsnLyr(refPlnrMDesign, rtc->refPlnrMLayer, false, blks);
		for (unsigned int j=0;j<blks.nodes.size();j++) {
			blk = blks.nodes[j];

			if (fmtcif) {
				outfile << "DS " << blkcnt << " 1 10;" << endl;
				outfile << "L A000;" << endl;
			};

			dbsplnr->tblplnrmface->loadRstByDsnSru(0, blk->refPlnrMStructure, false, fces);
			for (unsigned int k=0;k<fces.nodes.size();k++) {
				fce = fces.nodes[k];

				if (fmtcif) outfile << "P";

				if (fmtraith) {
					outfile << "1 100 ";
					if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::PLN) {
						outfile << i << endl;
					} else if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::BTCH) {
						outfile << "0" << endl;
					};
				};

				dbsplnr->tblplnrrmfacemvertex->loadRstByFce(fce->ref, false, frvs);
				for (unsigned int l=0;l<frvs.nodes.size();l++) {
					frv = frvs.nodes[l];
					vtx = vtxs.nodes[vtxics[frv->refPlnrMVertex]];

					if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::LGD) {
						// simple treatment for lineguide segments
						x = a11*vtx->x + b1;
						y = a22*vtx->y + b2;
						if (fmtcif) outfile << " " << lround(x) << "," << lround(y);
						else if (fmtraith) outfile << x << " " << y << endl;

					} else if (frv->rteIxVTbl == VecPlnrVRMFaceMVertexRteTbl::AGD) {
						// special treatment for arc segments
						ag = ags.nodes[agics[frv->rteUref]];

						agarvix0 = agarvix0s[agics[frv->rteUref]];
						agarvix1 = agarvix1s[agics[frv->rteUref]];

						// find begin/end arv's
						for (unsigned int m=agarvix0;m<agarvix1;m++) {
							arv = arvs.nodes[m];

							if (arv->refPlnrMVertex == vtx->ref) arvix0 = m;
							if (l == (frvs.nodes.size()-1)) {
								if (arv->refPlnrMVertex == frvs.nodes[0]->refPlnrMVertex) arvix1 = m;
							} else {
								if (arv->refPlnrMVertex == frvs.nodes[l+1]->refPlnrMVertex) arvix1 = m;
							};
						};

						// add intermediate vertices
						if (frv->ixVDir == VecPlnrVRMFaceMVertexDir::FWD) {
							// forward
							for (unsigned int m=arvix0;m!=arvix1;) {
								arv = arvs.nodes[m];

								vtx = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
								x = a11*vtx->x + b1;
								y = a22*vtx->y + b2;
								if (fmtcif) outfile << " " << lround(x) << "," << lround(y);
								else if (fmtraith) outfile << x << " " << y << endl;

								// include all extra vertices up to the next vertex
								arvarvxsix0 = arvarvxsix0s[m];
								arvarvxsix1 = arvarvxsix1s[m];
								for (unsigned int n=arvarvxsix0;n<arvarvxsix1;n++) {
									x = a11*arvxs[n] + b1;
									y = a22*arvys[n] + b2;
									if (fmtcif) outfile << " " << lround(x) << "," << lround(y);
									else if (fmtraith) outfile << x << " " << y << endl;
								};

								m++;
								if (m >= agarvix1) m = agarvix0;
							};

						} else {
							// backward
							for (unsigned int m=arvix0;m!=arvix1;) {
								arv = arvs.nodes[m];

								vtx = vtxs.nodes[vtxics[arv->refPlnrMVertex]];
								x = a11*vtx->x + b1;
								y = a22*vtx->y + b2;
								if (fmtcif) outfile << " " << lround(x) << "," << lround(y);
								else if (fmtraith) outfile << x << " " << y << endl;

								if (m != 0) { // unsigned int precaution
									m--;
									if (m < agarvix0) m = agarvix1-1;
								} else {
									m = agarvix1-1;
								};

								// include all extra vertices up to the next vertex
								arvarvxsix0 = arvarvxsix0s[m];
								arvarvxsix1 = arvarvxsix1s[m];

								if (arvarvxsix1 > arvarvxsix0) { // unsigned int precaution
									for (unsigned int n=(arvarvxsix1-1);n>=arvarvxsix0;n--) {
										x = a11*arvxs[n] + b1;
										y = a22*arvys[n] + b2;
										if (fmtcif) outfile << " " << lround(x) << "," << lround(y);
										else if (fmtraith) outfile << x << " " << y << endl;
										
										if (n == 0) break; // unsigned int precaution
									};
								};
							};
						};
					};
				};
				if (fmtcif) outfile << ";" << endl;
				else if (fmtraith) outfile << "#" << endl;
			};
			if (fmtcif) outfile << "DF;" << endl;

			blkcnt++;
		};

		if (fmtcif && (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::BTCH)) {
			// re-call each structure of the layer
			outfile << "DS " << (blks.nodes.size()+1) << ";" << endl;
			for (unsigned int j=0;j<blks.nodes.size();j++) outfile << "C " << (j+1) << ";" << endl;
			outfile << "DF;" << endl;
			outfile << "C " << (blks.nodes.size()+1) << ";" << endl;
			outfile << "END;" << endl;
		};

		if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::BTCH) outfile.close();
	};

	if (fmtcif && (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::PLN)) {
		// re-call each structure of the entire mask
		outfile << "DS " << blkcnt << ";" << endl;
		for (unsigned int i=1;i<blkcnt;i++) outfile << "C " << i << ";" << endl;
		outfile << "DF;" << endl;
		outfile << "C " << blkcnt << ";" << endl;
		outfile << "END;" << endl;
	};

	if (tpo->ixVBasetype == VecPlnrVMTapeoutBasetype::PLN) {
		outfile.close();

		if (fmtcif) dpchret->ciffile = outpath;
		else dpchret->ascfile = outpath;

	} else {
		// tar-gzip folder
		str.str(""); str << "tar -czvf " << xchg->tmppath << "/" << outfolder << ".tgz -C " << xchg->tmppath << " " << outfolder << "/";
		system(str.str().c_str());

		str.str(""); str << outfolder << ".tgz";
		dpchret->tgzfile = str.str();
	};
*/

	delete tpo;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


