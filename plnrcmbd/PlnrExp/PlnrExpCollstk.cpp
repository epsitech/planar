/**
  * \file PlnrExpCollstk.cpp
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

#include "PlnrExpCollstk.h"

DpchRetPlnr* PlnrExpCollstk::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpCollstk* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMStack = dpchinv->refPlnrMStack;

// IP run --- IBEGIN
	dbsplnr->begin();

	// TblPlnrMLevel-TblPlnrJMLevelZ
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMLevelZ WHERE refPlnrMLevel IN (SELECT ref FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(VecPlnrVMLevelHkTbl::STK) + " AND hkUref = " + to_string(refPlnrMStack) + ")");

	// TblPlnrMLevel
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(VecPlnrVMLevelHkTbl::STK) + " AND hkUref = " + to_string(refPlnrMStack));

	// - clear reg layers out of pertpl stack
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLayer WHERE ixVBasetype = " + to_string(VecPlnrVMLayerBasetype::REG) + " AND hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK)
				+ " AND hkUref IN (SELECT ref FROM TblPlnrMStack WHERE ref = " + to_string(refPlnrMStack) + " AND ixVBasetype = " + to_string(VecPlnrVMStackBasetype::PERTPL) + ")");

	// - clear level references out of remaining layers
	dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET flrRefPlnrMLevel = 0, ctrRefPlnrMLevel = 0, ceilRefPlnrMLevel = 0 WHERE hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK) + " AND hkUref = " + to_string(refPlnrMStack));

	// TblPlnrJMStackModtype
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMStackModtype WHERE refPlnrMStack = " + to_string(refPlnrMStack));

	// - reset calculated thicknesses of ffill and cfill layers
	dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET t = '0.0', ML = '0' WHERE ixVTtype = " + to_string(VecPlnrVMLayerTtype::FFILL) + " AND hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK) + " AND hkUref = " + to_string(refPlnrMStack));
	dbsplnr->executeQuery("UPDATE TblPlnrMLayer SET t = '0.0', ML = '0' WHERE ixVTtype = " + to_string(VecPlnrVMLayerTtype::CFILL) + " AND hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK) + " AND hkUref = " + to_string(refPlnrMStack));

	dbsplnr->commit();
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


