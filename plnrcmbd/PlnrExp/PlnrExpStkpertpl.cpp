/**
  * \file PlnrExpStkpertpl.cpp
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

#include "PlnrExpStkpertpl.h"

DpchRetPlnr* PlnrExpStkpertpl::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpStkpertpl* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMStack = dpchinv->refPlnrMStack;

// IP run --- IBEGIN
	// possibly modified: t, ML (entries in TblPlnrJMLayer), N (entries in TblPlnrJMStackN)
	// layer thickness types: abs, mat (ignore for now)

	PlnrMStack* stk = NULL;

	ListPlnrMLayer tpllyrs;
	PlnrMLayer* tpllyr = NULL;

	vector<string> srefsTpllyr;
	string srefTpllyr;
	vector<unsigned int> icsTpllyrs;

	ListPlnrMLayer lyrs, lyrs2;
	ListPlnrMLevel lvls, lvls2;

	vector<ubigint> refsDsnto;
	vector<ubigint> refsDsnnoto;
	ubigint x1RefPlnrMDesign;

	// - load stack and template layers
	dbsplnr->tblplnrmstack->loadRecByRef(refPlnrMStack, &stk);
	dbsplnr->tblplnrmlayer->loadRstByDsnHktHku(0, VecPlnrVMLayerHkTbl::STK, refPlnrMStack, false, tpllyrs);

	// - determine period sequence
	StrMod::stringToVector(stk->srefsPlnrMLayer, srefsTpllyr);
	for (unsigned int i=0;i<srefsTpllyr.size();i++) {
		srefTpllyr = srefsTpllyr[i];

		for (unsigned int j=0;j<tpllyrs.nodes.size();j++) {
			tpllyr = tpllyrs.nodes[j];

			if (tpllyr->sref.compare(srefTpllyr) == 0) {
				icsTpllyrs.push_back(j);
				break;
			};
		};
	};

	// - expand baseline
	dbsplnr->begin();
	levels(dbsplnr, 0, stk, tpllyrs, icsTpllyrs, false, lyrs, lvls);
	dbsplnr->commit();

	// - expand for modified designs; priority for topology-changing modifications
	dbsplnr->loadRefsBySQL("SELECT DISTINCT TblPlnrJMStackN.x1RefPlnrMDesign FROM TblPlnrJMStackN WHERE refPlnrMStack = " + to_string(refPlnrMStack), false, refsDsnto);

	dbsplnr->loadRefsBySQL("SELECT DISTINCT TblPlnrJMLayer.x1RefPlnrMDesign FROM TblPlnrJMLayer, TblPlnrMLayer WHERE TblPlnrJMLayer.refPlnrMLayer = TblPlnrMLayer.ref AND TblPlnrMLayer.hkIxVTbl = "
				+ to_string(VecPlnrVMLayerHkTbl::STK) + " AND TblPlnrMLayer.hkUref = " + to_string(refPlnrMStack), false, refsDsnnoto);

	for (unsigned int i=0;i<refsDsnnoto.size();i++) {
		for (unsigned int j=0;j<refsDsnto.size();j++) {
			if (refsDsnnoto[i] == refsDsnto[j]) {
				refsDsnnoto[i] = 0;
				break;
			};
		};
	};

	for (unsigned int i=0;i<refsDsnto.size();i++) {
		x1RefPlnrMDesign = refsDsnto[i];

		dbsplnr->begin();

		addStkModtype(dbsplnr, refPlnrMStack, x1RefPlnrMDesign, VecPlnrVMStackModtype::LYR);
		levels(dbsplnr, x1RefPlnrMDesign, stk, tpllyrs, icsTpllyrs, false, lyrs2, lvls2);

		dbsplnr->commit();

		lyrs2.clear();
		lvls2.clear();
	};

	for (unsigned int i=0;i<refsDsnnoto.size();i++) {
		x1RefPlnrMDesign = refsDsnnoto[i];

		if (x1RefPlnrMDesign != 0) {
			dbsplnr->begin();

			addStkModtype(dbsplnr, refPlnrMStack, x1RefPlnrMDesign, VecPlnrVMStackModtype::NOLN);
			levels(dbsplnr, x1RefPlnrMDesign, stk, tpllyrs, icsTpllyrs, true, lyrs, lvls);

			dbsplnr->commit();
		};
	};

	delete stk;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpStkpertpl::levels(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const PlnrMStack* stk
			, const ListPlnrMLayer& tpllyrs
			, const vector<unsigned int>& icsTpllyrs
			, const bool zonly
			, ListPlnrMLayer& lyrs
			, ListPlnrMLevel& lvls
		) {
	ostringstream str, str2;
	str2.setf(ios::scientific);

	PlnrMLayer* tpllyr= NULL;

	PlnrMLayer* lyr = NULL;
	PlnrMLayer* prevlyr = NULL;

	PlnrMLevel* lvl = NULL;

	unsigned int N;
	double z, t;

	z = 0.0;

	N = loadStackN(dbsplnr, x1RefPlnrMDesign, stk);

	for (unsigned int i=0;i<N;i++) {
		for (unsigned int j=0;j<icsTpllyrs.size();j++) {
			tpllyr = tpllyrs.nodes[icsTpllyrs[j]];
			t = loadLayerT(dbsplnr, x1RefPlnrMDesign, tpllyr);

			// - layer
			str.str(""); str << "prd" << i << tpllyr->sref << j;
			str2.str(""); str2 << t;

			if (zonly) {
				// find layer in lyrs
				for (unsigned int k=0;k<lyrs.nodes.size();k++) {
					lyr = lyrs.nodes[k];

					if (lyr->sref.compare(str.str()) == 0) {
						if (! ((i == 0) && (j == 0))) prevlyr = lyrs.nodes[k-1];
						break;
					};
				};

			} else {
				// create layer 
				lyr = new PlnrMLayer(*tpllyr);
				lyr->ref = 0;
				lyr->x1RefPlnrMDesign = x1RefPlnrMDesign;
				lyr->ixVBasetype = VecPlnrVMLayerBasetype::REG;
				lyr->hkNum = (i*icsTpllyrs.size()) + j + 1;
				lyr->sref = str.str();
				lyr->t = str2.str();
				dbsplnr->tblplnrmlayer->insertRec(lyr); lyrs.nodes.push_back(lyr);

				if (! ((i == 0) && (j == 0))) prevlyr = lyrs.nodes[lyrs.nodes.size()-2];
			};

			// floor/interface level
			str.str("");
			if ((i == 0) && (j == 0)) {
				str << "zflr";
			} else {
				str << "z" << prevlyr->sref << "_" << lyr->sref;
			};

			if (zonly) {
				addLevelZByZsref(dbsplnr, str.str(), x1RefPlnrMDesign, z, lvls);

			} else {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, stk->ref, str.str(), z, lvls);

				if (!((i == 0) && (j == 0))) lyrs.nodes[lyrs.nodes.size()-2]->ceilRefPlnrMLevel = lvl->ref;
				lyr->flrRefPlnrMLevel = lvl->ref;
			};

			z += 0.5*t;

			// center level
			str.str(""); str << "z" << lyr->sref;

			if (zonly) {
				addLevelZByZsref(dbsplnr, str.str(), x1RefPlnrMDesign, z, lvls);

			} else {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, stk->ref, str.str(), z, lvls);
				lyr->ctrRefPlnrMLevel = lvl->ref;
			};

			z += 0.5*t;

			// ceiling level
			if ((i == (N-1)) && (j == (icsTpllyrs.size()-1))) {
				if (zonly) {
					addLevelZByZsref(dbsplnr, "zceil", x1RefPlnrMDesign, z, lvls);

				} else {
					lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, stk->ref, "zceil", z, lvls);
					lyr->ceilRefPlnrMLevel = lvl->ref;
				};
			};
		};
	};

	// update layers to make changes in flr/ctr/ceil levels effective
	if (!zonly) for (unsigned int i=0;i<lyrs.nodes.size();i++) dbsplnr->tblplnrmlayer->updateRec(lyrs.nodes[i]);
};
// IP cust --- IEND


