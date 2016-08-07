/**
  * \file PlnrExpStkregfill.cpp
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

#include "PlnrExpStkregfill.h"

DpchRetPlnr* PlnrExpStkregfill::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpStkregfill* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMStack = dpchinv->refPlnrMStack;

// IP run --- IBEGIN
	// possibly modified: t, ML (entries in TblPlnrJMLayer)
	// layer thickness types: abs, mat (ignore for now), ffill for first layer, cfill for last layer

	ListPlnrMLayer lyrs;
	ListPlnrMLevel lvls;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	// - expand baseline
	dbsplnr->tblplnrmlayer->loadRstByDsnHktHku(0, VecPlnrVMLayerHkTbl::STK, refPlnrMStack, false, lyrs);

	dbsplnr->begin();
	levels(dbsplnr, 0, refPlnrMStack, lyrs, lvls);
	dbsplnr->commit();

	// - expand for modified designs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT TblPlnrJMLayer.x1RefPlnrMDesign FROM TblPlnrJMLayer, TblPlnrMLayer WHERE TblPlnrJMLayer.refPlnrMLayer = TblPlnrMLayer.ref AND TblPlnrMLayer.hkIxVTbl = "
				+ to_string(VecPlnrVMLayerHkTbl::STK) + " AND TblPlnrMLayer.hkUref = " + to_string(refPlnrMStack), false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		dbsplnr->begin();

		addStkModtype(dbsplnr, refPlnrMStack, x1RefPlnrMDesign, VecPlnrVMStackModtype::NOLN);
		levels(dbsplnr, x1RefPlnrMDesign, refPlnrMStack, lyrs, lvls);

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpStkregfill::levels(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMStack
			, ListPlnrMLayer& lyrs
			, ListPlnrMLevel& lvls
		) {
	ostringstream str;

	PlnrMLayer* lyr = NULL;
	PlnrMLevel* lvl = NULL;

	double z, t;

	for (unsigned int i=0;i<lyrs.nodes.size();i++) {
		lyr = lyrs.nodes[i];

		// first layer determines initial z
		if (i == 0) {
			if (lyr->ixVTtype == VecPlnrVMLayerTtype::FFILL) z = -1.0e6;
			else z = 0.0;
		};

		// thickness according to type
		if ((i == 0) && (lyr->ixVTtype == VecPlnrVMLayerTtype::FFILL)) {
			t = 1.0e6;
		} else if ((i == (lyrs.nodes.size()-1)) && (lyr->ixVTtype == VecPlnrVMLayerTtype::CFILL)) {
			t = 1.0e6;
		} else {
			t = loadLayerT(dbsplnr, x1RefPlnrMDesign, lyr);
		};

		// floor/interface level
		if (i == 0) {
			// first layer
			if (x1RefPlnrMDesign == 0) {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, "zflr", z, lvls);
				lyr->flrRefPlnrMLevel = lvl->ref;
			} else {
				addLevelZByZsref(dbsplnr, "zflr", x1RefPlnrMDesign, z, lvls);
			};

		} else {
			// interior/last layer
			str.str(""); str << "z" << lyrs.nodes[i-1]->sref << "_" << lyr->sref;
			if (x1RefPlnrMDesign == 0) {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, str.str(), z, lvls);
				lyrs.nodes[i-1]->ceilRefPlnrMLevel = lvl->ref;
				lyr->flrRefPlnrMLevel = lvl->ref;
			} else {
				addLevelZByZsref(dbsplnr, str.str(), x1RefPlnrMDesign, z, lvls);
			};
		};
		z += 0.5*t;

		// center level
		if ((i == 0) && (lyr->ixVTtype == VecPlnrVMLayerTtype::FFILL)) {
			z += 0.5*t;
		} else if ((i == (lyrs.nodes.size()-1)) && (lyr->ixVTtype == VecPlnrVMLayerTtype::CFILL)) {
			z = 1.0e6;

		} else {
			str.str(""); str << "z" << lyr->sref;
			if (x1RefPlnrMDesign == 0) {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, str.str(), z, lvls);
				lyr->ctrRefPlnrMLevel = lvl->ref;
			} else {
				addLevelZByZsref(dbsplnr, str.str(), x1RefPlnrMDesign, z, lvls);
			};
			z += 0.5*t;
		};

		// ceiling level (last layer only)
		if (i == (lyrs.nodes.size()-1)) {
			if (x1RefPlnrMDesign == 0) {
				lvl = addLevel(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, "zceil", z, lvls);
				lyr->ceilRefPlnrMLevel = lvl->ref;
			} else {
				addLevelZByZsref(dbsplnr, "zceil", x1RefPlnrMDesign, z, lvls);
			};
		};
	};

	// update all layers to adjust level ref's
	if (x1RefPlnrMDesign == 0) for (unsigned int i=0;i<lyrs.nodes.size();i++) dbsplnr->tblplnrmlayer->updateRec(lyrs.nodes[i]);
};
// IP cust --- IEND


