/**
  * \file SqkPlnrRast.cpp
  * squawk generation for operation pack PlnrRast (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "SqkPlnrRast.h"

/******************************************************************************
 namespace SqkPlnrRast
 ******************************************************************************/

string SqkPlnrRast::getSquawkCub(
			DbsPlnr* dbsplnr
			, DpchInvPlnrRastCub* dpchinv
		) {
	string retval;
// IP getSquawkCub --- IBEGIN
	retval = "rasterize design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "' as 3D cuboid";
// IP getSquawkCub --- IEND
	return(retval);
};

string SqkPlnrRast::getSquawkXybox(
			DbsPlnr* dbsplnr
			, DpchInvPlnrRastXybox* dpchinv
		) {
	string retval;
// IP getSquawkXybox --- IBEGIN
	retval = "rasterize design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "' as 2D box";
// IP getSquawkXybox --- IEND
	return(retval);
};

string SqkPlnrRast::getSquawkZline(
			DbsPlnr* dbsplnr
			, DpchInvPlnrRastZline* dpchinv
		) {
	string retval;
// IP getSquawkZline --- IBEGIN
	retval = "rasterize design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "' as 1D peek";
// IP getSquawkZline --- IEND
	return(retval);
};


