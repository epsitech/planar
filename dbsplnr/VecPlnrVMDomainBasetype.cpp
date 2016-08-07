/**
  * \file VecPlnrVMDomainBasetype.cpp
  * vector VecPlnrVMDomainBasetype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMDomainBasetype.h"

/******************************************************************************
 namespace VecPlnrVMDomainBasetype
 ******************************************************************************/

uint VecPlnrVMDomainBasetype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "cub_xyz") return CUB_XYZ;
	else if (s == "xybox_xyz") return XYBOX_XYZ;
	else if (s == "xybox_xy") return XYBOX_XY;
	else if (s == "zcsbox_xyz") return ZCSBOX_XYZ;
	else if (s == "xyline_xyz") return XYLINE_XYZ;
	else if (s == "xyline_xy") return XYLINE_XY;
	else if (s == "zline_xyz") return ZLINE_XYZ;
	else if (s == "zline_z") return ZLINE_Z;
	else if (s == "point_xyz") return POINT_XYZ;
	else if (s == "point_xy") return POINT_XY;
	else if (s == "point_z") return POINT_Z;

	return(0);
};

string VecPlnrVMDomainBasetype::getSref(
			const uint ix
		) {
	if (ix == CUB_XYZ) return("cub_xyz");
	else if (ix == XYBOX_XYZ) return("xybox_xyz");
	else if (ix == XYBOX_XY) return("xybox_xy");
	else if (ix == ZCSBOX_XYZ) return("zcsbox_xyz");
	else if (ix == XYLINE_XYZ) return("xyline_xyz");
	else if (ix == XYLINE_XY) return("xyline_xy");
	else if (ix == ZLINE_XYZ) return("zline_xyz");
	else if (ix == ZLINE_Z) return("zline_z");
	else if (ix == POINT_XYZ) return("point_xyz");
	else if (ix == POINT_XY) return("point_xy");
	else if (ix == POINT_Z) return("point_z");

	return("");
};

string VecPlnrVMDomainBasetype::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == CUB_XYZ) return("3D cuboid (xyz design)");
		else if (ix == XYBOX_XYZ) return("2D box in xy plane (xyz design, at distinct level)");
		else if (ix == XYBOX_XY) return("2D box (xy design)");
		else if (ix == ZCSBOX_XYZ) return("cross section 2D box (xyz design)");
		else if (ix == XYLINE_XYZ) return("line in xy plane (xyz design, at distinct level)");
		else if (ix == XYLINE_XY) return("line (xy design)");
		else if (ix == ZLINE_XYZ) return("z peek line (xyz design, at distinct vertex)");
		else if (ix == ZLINE_Z) return("z peek (z design)");
		else if (ix == POINT_XYZ) return("point (xyz design, at distinct vertex and level)");
		else if (ix == POINT_XY) return("point/vertex (xy design)");
		else if (ix == POINT_Z) return("point/level (z design)");
	};

	return("");
};

void VecPlnrVMDomainBasetype::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=11;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

