/**
  * \file PlnrExp.h
  * Plnr operation pack global code (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXP_H
#define PLNREXP_H

#include "PlnrExp_blks.h"

// IP incl --- INSERT

namespace PlnrExp {
// IP cust --- IBEGIN
	// global constants
	constexpr double pi = 3.141592653589793238462643383279;

	bool loadBoolDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, bool& val);
	bool loadIntDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, int& val);
	bool loadDoubleDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, double& val);
	bool loadStringDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, string& val);
	bool loadReffileDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, ubigint& val);

	void loadModBoolDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& sref, bool& val);
	void loadModIntDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& sref, int& val);
	void loadModDoubleDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& sref, double& val);
	void loadModStringDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& sref, string& val);
	void loadModReffileDevpar(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& sref, ubigint& val);

	void addDevModtype(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const uint ixVModtype);

	PlnrMVertex* addVertex(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const double x, const double y, ListPlnrMVertex& vtxs);
	void addVertices(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const vector<string>& srefs, const vector<double>& xs, const vector<double>& ys, ListPlnrMVertex& vtxs);

	void addVertexXYByVsref(DbsPlnr* dbsplnr, const string& vsref, const ubigint x1RefPlnrMDesign, const double x, const double y, const ListPlnrMVertex& vtxs);
	void addVertexXYByVix(DbsPlnr* dbsplnr, const unsigned int vix, const ubigint x1RefPlnrMDesign, const double x, const double y, const ListPlnrMVertex& vtxs);
	void addVertexXYs(DbsPlnr* dbsplnr, const vector<string>& vsrefs, const ubigint x1RefPlnrMDesign, const vector<double>& xs, const vector<double>& ys, const ListPlnrMVertex& vtxs);

	void opaddVertex(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const string& sref, const double x, const double y, ListPlnrMVertex& vtxs);
	void opsubVertex(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const string& sref, ListPlnrMVertex& vtxs);

	void addVtxVtx(DbsPlnr* dbsplnr, const ubigint devRefPlnrMVertex, const ubigint dsnRefPlnrMVertex);

	PlnrMLineguide* addLineguideByVsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const vector<string>& vsrefs, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	PlnrMLineguide* addLineguideByVics(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const vector<unsigned int>& vics, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void addLineguides(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const vector<string>& srefs, const vector<string>& vsrefsstrs, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);

	void opaddLineguideByVsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const string& sref, const vector<string>& vsrefs, const ListPlnrMVertex& vtxs, ListPlnrMLineguide& lgs);
	void opsubLineguide(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const string& sref, const ListPlnrMLineguide& lgs);

	void opaddLgdVtxAtVsrefNum(DbsPlnr* dbsplnr, const ubigint refSubdev, const string& lsref, const string& vsreforig, const string& vsrefrepl, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs);
	void opsubLgdVtx(DbsPlnr* dbsplnr, const ubigint refSubdev, const string& lsref, const string& vsref, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs);

	void addLgdLgd(DbsPlnr* dbsplnr, const ubigint devRefPlnrMLineguide, const ubigint dsnRefPlnrMLineguide);

	PlnrMArcguide* addArcguideByVsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const string& cvsref, const double r, const vector<string>& vsrefs, const ListPlnrMVertex& vtxs, ListPlnrMArcguide& ags);
	PlnrMArcguide* addArcguideByVics(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const unsigned int cvix, const double r, const vector<unsigned int>& vics, const ListPlnrMVertex& vtxs, ListPlnrMArcguide& ags);
	void addArcguides(DbsPlnr* dbsplnr,	const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const vector<string>& srefs, const vector<string>& cvsrefs, const vector<double>& rs, const vector<string>& vsrefsstrs, const ListPlnrMVertex& vtxs, ListPlnrMArcguide& ags);

	void addArcguideRByAsref(DbsPlnr* dbsplnr, const string& asref, const ubigint x1RefPlnrMDesign, const double r, const ListPlnrMArcguide& ags);
	void addArcguideRByAix(DbsPlnr* dbsplnr, const unsigned int aix, const ubigint x1RefPlnrMDesign, const double r, const ListPlnrMArcguide& ags);
	void addArcguideRs(DbsPlnr* dbsplnr, const vector<string>& asrefs, const ubigint x1RefPlnrMDesign, const vector<double>& rs, const ListPlnrMArcguide& ags);

	void opaddArcguideByVsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const string& sref, const string& cvsref, const double r, const vector<string>& vsrefs, const ListPlnrMVertex& vtxs, ListPlnrMArcguide& ags);
	void opsubArcguide(DbsPlnr* dbsplnr, const ubigint refSupdev, const ubigint refSubdev, const string& sref, const ListPlnrMArcguide& ags);

	PlnrMFace* addFaceByVgsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint strRefPlnrMStructure, const string& sref, const vector<string>& vsrefs, const vector<string>& rtes, const vector<string>& gsrefs, const vector<string>& dirs, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
	PlnrMFace* addFaceByVgics(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint strRefPlnrMStructure, const string& sref, const vector<unsigned int>& vics, const vector<unsigned int>& icsRte, const vector<unsigned int>& gics, const vector<unsigned int>& icsDir, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
	void addFaces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const vector<ubigint>& strrefs, const vector<string>& srefs, const vector<string>& vsrefsstrs, const vector<string>& rtesstrs, const vector<string>& gsrefsstrs, const vector<string>& dirsstrs, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);

	void opaddFaceByVgsrefs(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refSupdev, const ubigint refSubdev, const ubigint strRefPlnrMStructure, const string& sref, const vector<string>& vsrefs, const vector<string>& rtes, const vector<string>& gsrefs, const vector<string>& dirs, const ListPlnrMVertex& vtxs, const ListPlnrMLineguide& lgs, const ListPlnrMArcguide& ags, ListPlnrMFace& fces);
	void opsubFace(DbsPlnr* dbsplnr, const ubigint refSubdev, const string& sref, const ubigint refSru, const ListPlnrMFace& fces);

	unsigned int loadStackN(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const PlnrMStack* stk);
	double loadLayerT(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const PlnrMLayer* lyr);

	void addStkModtype(DbsPlnr* dbsplnr, const ubigint refPlnrMStack, const ubigint x1RefPlnrMDesign, const uint ixVModtype);

	PlnrMLevel* addLevel(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const uint hkIxVTbl, const ubigint hkUref, const string& sref, const double z, ListPlnrMLevel& lvls);

	void addLevelZByZsref(DbsPlnr* dbsplnr, const string& zsref, const ubigint x1RefPlnrMDesign, const double z, const ListPlnrMLevel& lvls);

	void addLvlLvl(DbsPlnr* dbsplnr, const ubigint stkRefPlnrMLevel, const ubigint dsnRefPlnrMLevel);

	string intToPnstr(const int val);
	string mnToStr(const int m, const int n, const string& prefix, const string& postfix);
	double degToRad(const double deg);
// IP cust --- IEND
};

#endif


