/**
  * \file PlnrExpColldsn.cpp
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

#include "PlnrExpColldsn.h"

DpchRetPlnr* PlnrExpColldsn::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpColldsn* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;

// IP run --- IBEGIN

	// collapse base design including all modified designs

	vector<ubigint> refsDsn;
	ubigint refDsn;

	refsDsn.push_back(refPlnrMDesign);

	dbsplnr->tblplnrmdesign->loadRefsByMod(refPlnrMDesign, true, refsDsn);

	dbsplnr->begin();

	for (unsigned int i=0;i<refsDsn.size();i++) {
		refDsn = refsDsn[i];

		// - xy part
		// TblPlnrMVertex-TblPlnrRMVertexMVertex
		dbsplnr->executeQuery("DELETE FROM TblPlnrRMVertexMVertex WHERE dsnRefPlnrMVertex IN (SELECT ref FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMVertex
		dbsplnr->executeQuery("DELETE FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// TblPlnrMLineguide-TblPlnrRMLineguideMLineguide
		dbsplnr->executeQuery("DELETE FROM TblPlnrRMLineguideMLineguide WHERE dsnRefPlnrMLineguide IN (SELECT ref FROM TblPlnrMLineguide WHERE hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMLineguide-TblPlnrLRMLineguideMVertex
		dbsplnr->executeQuery("DELETE FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide IN (SELECT ref FROM TblPlnrMLineguide WHERE hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMLineguide
		dbsplnr->executeQuery("DELETE FROM TblPlnrMLineguide WHERE hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// TblPlnrMArcguide-TblPlnrLRMArcguideMVertex
		dbsplnr->executeQuery("DELETE FROM TblPlnrLRMArcguideMVertex WHERE agdRefPlnrMArcguide IN (SELECT ref FROM TblPlnrMArcguide WHERE hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMArcguide
		dbsplnr->executeQuery("DELETE FROM TblPlnrMArcguide WHERE hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// TblPlnrMStructure-TblPlnrMFace-TblPlnrRMFaceMVertex
		dbsplnr->executeQuery("DELETE FROM TblPlnrRMFaceMVertex WHERE fceRefPlnrMFace IN (SELECT TblPlnrMFace.ref FROM TblPlnrMFace, TblPlnrMStructure WHERE TblPlnrMFace.strRefPlnrMStructure = TblPlnrMStructure.ref AND TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMStructure-TblPlnrMFace
		dbsplnr->executeQuery("DELETE FROM TblPlnrMFace WHERE strRefPlnrMStructure IN (SELECT ref FROM TblPlnrMStructure WHERE TblPlnrMStructure.hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMStructure
		dbsplnr->executeQuery("DELETE FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// - z part
		// TblPlnrMLevel-TblPlnrRMLevelMLevel
		dbsplnr->executeQuery("DELETE FROM TblPlnrRMLevelMLevel WHERE dsnRefPlnrMLevel IN (SELECT ref FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(VecPlnrVMLevelHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMLevel
		dbsplnr->executeQuery("DELETE FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(VecPlnrVMLevelHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// TblPlnrMLayer-TblPlnrRMLayerMStructure
		dbsplnr->executeQuery("DELETE FROM TblPlnrRMLayerMStructure WHERE refPlnrMLayer IN (SELECT ref FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN) + " AND hkUref = " + to_string(refDsn) + ")");

		// TblPlnrMLayer
		dbsplnr->executeQuery("DELETE FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::DSN) + " AND hkUref = " + to_string(refDsn));

		// - xy-z
		// TblPlnrMBlock
		dbsplnr->executeQuery("DELETE FROM TblPlnrMBlock WHERE refPlnrMDesign = " + to_string(refDsn));
	};

	dbsplnr->commit();
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


