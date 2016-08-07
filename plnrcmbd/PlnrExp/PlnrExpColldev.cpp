/**
  * \file PlnrExpColldev.cpp
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

#include "PlnrExpColldev.h"

DpchRetPlnr* PlnrExpColldev::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpColldev* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	dbsplnr->begin();

	// TblPlnrDevOMDeviceMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMVertex WHERE refPlnrMDevice = " + to_string(refPlnrMDevice));

	// TblPlnrMVertex-TblPlnrJMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMVertex WHERE refPlnrMVertex IN (SELECT ref FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMVertex-TblPlnrLRMLineguideMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrLRMLineguideMVertex WHERE refPlnrMVertex IN (SELECT ref FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMVertex-TblPlnrLRMArcguideMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrLRMArcguideMVertex WHERE refPlnrMVertex IN (SELECT ref FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMVertex-TblPlnrRMFaceMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMFaceMVertex WHERE refPlnrMVertex IN (SELECT ref FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice));

	// TblPlnrDevOMDeviceMLineguide
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMLineguide WHERE refPlnrMDevice = " + to_string(refPlnrMDevice));

	// TblPlnrMLineguide-TblPlnrDevORMLineguideMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevORMLineguideMVertex WHERE refPlnrMLineguide IN (SELECT ref FROM TblPlnrMLineguide WHERE hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMLineguide
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLineguide WHERE hkIxVTbl = " + to_string(VecPlnrVMLineguideHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice));

	// TblPlnrDevOMDeviceMArcguide
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMArcguide WHERE refPlnrMDevice = " + to_string(refPlnrMDevice));

	// TblPlnrMArcguide-TblPlnrJMArcguideR
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMArcguideR WHERE refPlnrMArcguide IN (SELECT ref FROM TblPlnrMArcguide WHERE hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMArcguide-TblPlnrDevORMArcguideMVertex
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevORMArcguideMVertex WHERE refPlnrMArcguide IN (SELECT ref FROM TblPlnrMArcguide WHERE hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMArcguide
	dbsplnr->executeQuery("DELETE FROM TblPlnrMArcguide WHERE hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice));

	// TblPlnrMStructure-TblPlnrOMStructureMFace
	dbsplnr->executeQuery("DELETE FROM TblPlnrOMStructureMFace WHERE refPlnrMStructure IN (SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrMStructure-TblPlnrMFace
	dbsplnr->executeQuery("DELETE FROM TblPlnrMFace WHERE strRefPlnrMStructure IN (SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(VecPlnrVMStructureHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + ")");

	// TblPlnrJMDeviceModtype
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = " + to_string(refPlnrMDevice));

	dbsplnr->commit();
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


