/**
  * \file SqkPlnrMeep.cpp
  * squawk generation for operation pack PlnrMeep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "SqkPlnrMeep.h"

/******************************************************************************
 namespace SqkPlnrMeep
 ******************************************************************************/

string SqkPlnrMeep::getSquawkTrf2d(
			DbsPlnr* dbsplnr
			, DpchInvPlnrMeepTrf2d* dpchinv
		) {
	string retval;
// IP getSquawkTrf2d --- IBEGIN
	if (dpchinv->refPlnrMCalcitem == 0) {
		retval = "run MEEP to calculate 2D transfer function for calculation '" + StubPlnr::getStubCalStd(dbsplnr, dpchinv->refPlnrMCalc) + "'";
	} else {
		retval = "run MEEP to calculate 2D transfer function for calculation item '" + StubPlnr::getStubCliStd(dbsplnr, dpchinv->refPlnrMCalcitem) + "'";
	};
// IP getSquawkTrf2d --- IEND
	return(retval);
};

string SqkPlnrMeep::getSquawkTrf3d(
			DbsPlnr* dbsplnr
			, DpchInvPlnrMeepTrf3d* dpchinv
		) {
	string retval;
// IP getSquawkTrf3d --- IBEGIN
	if (dpchinv->refPlnrMCalcitem == 0) {
		retval = "run MEEP to calculate 3D transfer function for calculation '" + StubPlnr::getStubCalStd(dbsplnr, dpchinv->refPlnrMCalc) + "'";
	} else {
		retval = "run MEEP to calculate 3D transfer function for calculation item '" + StubPlnr::getStubCliStd(dbsplnr, dpchinv->refPlnrMCalcitem) + "'";
	};
// IP getSquawkTrf3d --- IEND
	return(retval);
};


