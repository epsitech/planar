/**
  * \file PlnrExp.cpp
  * Plnr operation pack global code (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrExp.h"

// IP cust --- IBEGIN
bool PlnrExp::loadBoolDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, bool& val
		) {
	PlnrAMDevicePar* dpa = NULL;

	string s;

	map<string, string> env; // dummy

	if (dbsplnr->tblplnramdevicepar->loadRecByDevDsnKey(refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, &dpa)) {
		s = StrMod::lc(StrMod::spcex(Fct::evalDevAparVal(env, dpa, true)));
		val = (s.compare("true") == 0);

		delete dpa;
		return true;
	};

	return false;
};

bool PlnrExp::loadIntDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, int& val
		) {
	PlnrAMDevicePar* dpa = NULL;

	string s;

	map<string, string> env; // dummy

	if (dbsplnr->tblplnramdevicepar->loadRecByDevDsnKey(refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, &dpa)) {
		s = Fct::evalDevAparVal(env, dpa, true);
		val = atoi(s.c_str());
	
		delete dpa;
		return true;
	};

	return false;
};

bool PlnrExp::loadDoubleDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, double& val
		) {
	PlnrAMDevicePar* dpa = NULL;

	string s;

	map<string, string> env; // dummy

	if (dbsplnr->tblplnramdevicepar->loadRecByDevDsnKey(refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, &dpa)) {
		s = Fct::evalDevAparVal(env, dpa, true);
		val = atof(s.c_str());

		delete dpa;
		return true;
	};

	return false;
};

bool PlnrExp::loadStringDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, string& val
		) {
	PlnrAMDevicePar* dpa = NULL;

	string s;

	map<string, string> env; // dummy

	if (dbsplnr->tblplnramdevicepar->loadRecByDevDsnKey(refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, &dpa)) {
		s = StrMod::spcex(Fct::evalDevAparVal(env, dpa, true));
		val = s;

		delete dpa;
		return true;
	};

	return false;
};

bool PlnrExp::loadReffileDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, ubigint& val
		) {
	PlnrAMDevicePar* dpa = NULL;

	string s;

	if (dbsplnr->tblplnramdevicepar->loadRecByDevDsnKey(refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, &dpa)) {
		val = dpa->refPlnrMFile;
	
		delete dpa;
		return true;
	};

	return false;
};

void PlnrExp::loadModBoolDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& sref
			, bool& val
		) {
	if (!loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, sref, val)) loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, sref, val);
};

void PlnrExp::loadModIntDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& sref
			, int& val
		) {
	if (!loadIntDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, sref, val)) loadIntDevpar(dbsplnr, refPlnrMDevice, 0, sref, val);
};

void PlnrExp::loadModDoubleDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& sref
			, double& val
		) {
	if (!loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, sref, val)) loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, sref, val);
};

void PlnrExp::loadModStringDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& sref
			, string& val
		) {
	if (!loadStringDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, sref, val)) loadStringDevpar(dbsplnr, refPlnrMDevice, 0, sref, val);
};

void PlnrExp::loadModReffileDevpar(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& sref
			, ubigint& val
		) {
	if (!loadReffileDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, sref, val)) loadReffileDevpar(dbsplnr, refPlnrMDevice, 0, sref, val);
};

void PlnrExp::addDevModtype(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	PlnrJMDeviceModtype* djm = NULL;

	djm = new PlnrJMDeviceModtype(0, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype);
	dbsplnr->tblplnrjmdevicemodtype->insertRec(djm);

	delete djm;
};

PlnrMVertex* PlnrExp::addVertex(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const double x
			, const double y
			, ListPlnrMVertex& vtxs
		) {
	PlnrMVertex* vtx = NULL;

	vtx = new PlnrMVertex(0, x1RefPlnrMDesign, VecPlnrVLat::INI, hkIxVTbl, hkUref, sref, x, y);
	dbsplnr->tblplnrmvertex->insertRec(vtx); vtxs.nodes.push_back(vtx);

	return vtx;
};

void PlnrExp::addVertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const vector<string>& srefs
			, const vector<double>& xs
			, const vector<double>& ys
			, ListPlnrMVertex& vtxs
		) {
	for (unsigned int i=0;i<srefs.size();i++) addVertex(dbsplnr, x1RefPlnrMDesign, hkIxVTbl, hkUref, srefs[i], xs[i], ys[i], vtxs);
};

void PlnrExp::addVertexXYByVsref(
			DbsPlnr* dbsplnr
			, const string& vsref
			, const ubigint x1RefPlnrMDesign
			, const double x
			, const double y
			, const ListPlnrMVertex& vtxs
		) {
	PlnrMVertex* vtx = NULL;

	unsigned int vix;

	for (vix=0;vix<vtxs.nodes.size();vix++) {
		vtx = vtxs.nodes[vix];
		if (vtx->sref.compare(vsref) == 0) break;
	};

	addVertexXYByVix(dbsplnr, vix, x1RefPlnrMDesign, x, y, vtxs);
};

void PlnrExp::addVertexXYByVix(
			DbsPlnr* dbsplnr
			, const unsigned int vix
			, const ubigint x1RefPlnrMDesign
			, const double x
			, const double y
			, const ListPlnrMVertex& vtxs
		) {
	PlnrJMVertex* vtxj = NULL;

	vtxj = new PlnrJMVertex(0, vtxs.nodes[vix]->ref, x1RefPlnrMDesign, x, y);
	dbsplnr->tblplnrjmvertex->insertRec(vtxj);

	delete vtxj;
};

void PlnrExp::addVertexXYs(
			DbsPlnr* dbsplnr
			, const vector<string>& vsrefs
			, const ubigint x1RefPlnrMDesign
			, const vector<double>& xs
			, const vector<double>& ys
			, const ListPlnrMVertex& vtxs
		) {
	for (unsigned int i=0;i<vsrefs.size();i++) addVertexXYByVsref(dbsplnr, vsrefs[i], x1RefPlnrMDesign, xs[i], ys[i], vtxs);
};

void PlnrExp::opaddVertex(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, const double x
			, const double y
			, ListPlnrMVertex& vtxs
		) {
	PlnrMVertex* vtx = NULL;

	PlnrDevOMDeviceMVertex* devvtxo = NULL;

	vtx = addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refSupdev, sref, x, y, vtxs);
	vtx->hkIxPlnrVLat = VecPlnrVLat::DLO;
	dbsplnr->tblplnrmvertex->updateRec(vtx);

	devvtxo = new PlnrDevOMDeviceMVertex(0, refSupdev, refSubdev, VecPlnrVLop::INS, vtx->ref);
	dbsplnr->tblplnrdevomdevicemvertex->insertRec(devvtxo);
	delete devvtxo;
};

void PlnrExp::opsubVertex(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, ListPlnrMVertex& vtxs
		) {
	PlnrMVertex* vtx = NULL;

	PlnrDevOMDeviceMVertex* devvtxo = NULL;

	ListPlnrLRMLineguideMVertex lgdvtxs;
	PlnrLRMLineguideMVertex* lgdvtx = NULL;

	ListPlnrDevORMLineguideMVertex lgdvtxos;
	PlnrDevORMLineguideMVertex* lgdvtxo = NULL;

	ListPlnrLRMArcguideMVertex agdvtxs;
	PlnrLRMArcguideMVertex* agdvtx = NULL;

	ListPlnrDevORMArcguideMVertex agdvtxos;
	PlnrDevORMArcguideMVertex* agdvtxo = NULL;

	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		vtx = vtxs.nodes[i];

		if (vtx->sref.compare(sref) == 0) {
			// operator to remove vertex from device
			devvtxo = new PlnrDevOMDeviceMVertex(0, refSupdev, refSubdev, VecPlnrVLop::RMV, vtx->ref);
			dbsplnr->tblplnrdevomdevicemvertex->insertRec(devvtxo);
			delete devvtxo;

			// operators to remove vertex from device line guides
			dbsplnr->tblplnrlrmlineguidemvertex->loadRstByVtx(vtx->ref, false, lgdvtxs);
			for (unsigned int j=0;j<lgdvtxs.nodes.size();j++) {
				lgdvtx = lgdvtxs.nodes[j];

				lgdvtxo = new PlnrDevORMLineguideMVertex(0, lgdvtx->lgdRefPlnrMLineguide, refSubdev, VecPlnrVLop::RMV, lgdvtx->ref);
				dbsplnr->tblplnrdevormlineguidemvertex->insertRec(lgdvtxo); lgdvtxos.nodes.push_back(lgdvtxo);
			};

			// operators to remove vertex from device arc guides
			dbsplnr->tblplnrlrmarcguidemvertex->loadRstByVtx(vtx->ref, false, agdvtxs);
			for (unsigned int j=0;j<agdvtxs.nodes.size();j++) {
				agdvtx = agdvtxs.nodes[j];

				agdvtxo = new PlnrDevORMArcguideMVertex(0, agdvtx->agdRefPlnrMArcguide, refSubdev, VecPlnrVLop::RMV, agdvtx->ref);
				dbsplnr->tblplnrdevormarcguidemvertex->insertRec(agdvtxo); agdvtxos.nodes.push_back(agdvtxo);
			};

			break;
		};
	};
};

void PlnrExp::addVtxVtx(
			DbsPlnr* dbsplnr
			, const ubigint devRefPlnrMVertex
			, const ubigint dsnRefPlnrMVertex
		) {
	PlnrRMVertexMVertex* vrv = NULL;

	vrv = new PlnrRMVertexMVertex(0, devRefPlnrMVertex, dsnRefPlnrMVertex);
	dbsplnr->tblplnrrmvertexmvertex->insertRec(vrv);

	delete vrv;
};

PlnrMLineguide* PlnrExp::addLineguideByVsrefs(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const vector<string>& vsrefs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;

	string vsref;

	PlnrMVertex* vtx = NULL;

	vector<unsigned int> vics;
	unsigned int vix;

	// for each string entry in vsrefs, find corresponding index in vtxs
	for (unsigned int i=0;i<vsrefs.size();i++) {
		vsref = vsrefs[i];

		for (vix=0;vix<vtxs.nodes.size();vix++) {
			vtx = vtxs.nodes[vix];
			if (vtx->sref.compare(vsref) == 0) break;
		};

		vics.push_back(vix);
	};

	lg = addLineguideByVics(dbsplnr, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, vics, vtxs, lgs);

	return lg;
};

PlnrMLineguide* PlnrExp::addLineguideByVics(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const vector<unsigned int>& vics
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;

	ListPlnrLRMLineguideMVertex lrvs;
	PlnrLRMLineguideMVertex* lrv = NULL;

	lg = new PlnrMLineguide(0, x1RefPlnrMDesign, VecPlnrVLat::INI, hkIxVTbl, hkUref, sref);
	dbsplnr->tblplnrmlineguide->insertRec(lg); lgs.nodes.push_back(lg);

	// vertex line-up
	for (unsigned int i=0;i<vics.size();i++) {
		lrv = new PlnrLRMLineguideMVertex(0, VecPlnrVLat::INI, lg->ref, (i+1), vtxs.nodes[vics[i]]->ref);
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv); lrvs.nodes.push_back(lrv);
	};

	return lg;
};

void PlnrExp::addLineguides(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const vector<string>& srefs
			, const vector<string>& vsrefsstrs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	vector<string> vsrefs;

	for (unsigned int i=0;i<srefs.size();i++) {
		// break down element of vsrefsstrs (comma-separated list) into vector of vertex sref's
		StrMod::stringToVector(vsrefsstrs[i], vsrefs);

		addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, hkIxVTbl, hkUref, srefs[i], vsrefs, vtxs, lgs);
	};
};

void PlnrExp::opaddLineguideByVsrefs(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, const vector<string>& vsrefs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;

	PlnrDevOMDeviceMLineguide* devlgdo = NULL;

	lg = addLineguideByVsrefs(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refSupdev, sref, vsrefs, vtxs, lgs);
	lg->hkIxPlnrVLat = VecPlnrVLat::DLO;
	dbsplnr->tblplnrmlineguide->updateRec(lg);

	devlgdo = new PlnrDevOMDeviceMLineguide(0, refSupdev, refSubdev, VecPlnrVLop::INS, lg->ref);
	dbsplnr->tblplnrdevomdevicemlineguide->insertRec(devlgdo);
	delete devlgdo;
};

void PlnrExp::opsubLineguide(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, const ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;

	PlnrDevOMDeviceMLineguide* devlgdo = NULL;

	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		lg = lgs.nodes[i];

		if (lg->sref.compare(sref) == 0) {
			devlgdo = new PlnrDevOMDeviceMLineguide(0, refSupdev, refSubdev, VecPlnrVLop::RMV, lg->ref);
			dbsplnr->tblplnrdevomdevicemlineguide->insertRec(devlgdo);
			delete devlgdo;

			break;
		};
	};
};

void PlnrExp::opaddLgdVtxAtVsrefNum(
			DbsPlnr* dbsplnr
			, const ubigint refSubdev
			, const string& lsref
			, const string& vsreforig
			, const string& vsrefrepl
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;
	PlnrMVertex* vtx = NULL;

	PlnrLRMLineguideMVertex* lrv = NULL;
	PlnrDevORMLineguideMVertex* lrvo = NULL;

	// find line guide
	ubigint refLgd = 0;
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		lg = lgs.nodes[i];

		if (lg->sref.compare(lsref) == 0) {
			refLgd = lg->ref;
			break;
		};
	};

	// find original vertex
	ubigint refVtxorig = 0;
	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		vtx = vtxs.nodes[i];

		if (vtx->sref.compare(vsreforig) == 0) {
			refVtxorig = vtx->ref;
			break;
		};
	};

	// find replacing vertex
	ubigint refVtxrepl = 0;
	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		vtx = vtxs.nodes[i];

		if (vtx->sref.compare(vsrefrepl) == 0) {
			refVtxrepl = vtx->ref;
			break;
		};
	};

	// add list and operator entries
	dbsplnr->tblplnrlrmlineguidemvertex->loadRecByLgdVtx(refLgd, refVtxorig, &lrv);
	
	lrvo = new PlnrDevORMLineguideMVertex(0, refLgd, refSubdev, VecPlnrVLop::RMV, lrv->ref);
	dbsplnr->tblplnrdevormlineguidemvertex->insertRec(lrvo);
	delete lrvo;
	
	lrv->ref = 0;
	lrv->lgdIxPlnrVLat = VecPlnrVLat::DLO;
	lrv->refPlnrMVertex = refVtxrepl;
	dbsplnr->tblplnrlrmlineguidemvertex->insertRec(lrv);

	lrvo = new PlnrDevORMLineguideMVertex(0, refLgd, refSubdev, VecPlnrVLop::INS, lrv->ref);
	dbsplnr->tblplnrdevormlineguidemvertex->insertRec(lrvo);

	delete lrv;
	delete lrvo;
};

void PlnrExp::opsubLgdVtx(
			DbsPlnr* dbsplnr
			, const ubigint refSubdev
			, const string& lsref
			, const string& vsref
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
		) {
	PlnrMLineguide* lg = NULL;
	PlnrMVertex* vtx = NULL;

	PlnrLRMLineguideMVertex* lrv = NULL;
	PlnrDevORMLineguideMVertex* lrvo = NULL;

	// find line guide
	ubigint refLgd = 0;
	for (unsigned int i=0;i<lgs.nodes.size();i++) {
		lg = lgs.nodes[i];

		if (lg->sref.compare(lsref) == 0) {
			refLgd = lg->ref;
			break;
		};
	};

	// find vertex
	ubigint refVtx = 0;
	for (unsigned int i=0;i<vtxs.nodes.size();i++) {
		vtx = vtxs.nodes[i];

		if (vtx->sref.compare(vsref) == 0) {
			refVtx = vtx->ref;
			break;
		};
	};

	// add operator entry
	dbsplnr->tblplnrlrmlineguidemvertex->loadRecByLgdVtx(refLgd, refVtx, &lrv);

	lrvo = new PlnrDevORMLineguideMVertex(0, refLgd, refSubdev, VecPlnrVLop::RMV, lrv->ref);
	dbsplnr->tblplnrdevormlineguidemvertex->insertRec(lrvo);

	delete lrv;
	delete lrvo;
};

void PlnrExp::addLgdLgd(
			DbsPlnr* dbsplnr
			, const ubigint devRefPlnrMLineguide
			, const ubigint dsnRefPlnrMLineguide
		) {
	PlnrRMLineguideMLineguide* lrl = NULL;

	lrl = new PlnrRMLineguideMLineguide(0, devRefPlnrMLineguide, dsnRefPlnrMLineguide);
	dbsplnr->tblplnrrmlineguidemlineguide->insertRec(lrl);

	delete lrl;
};

PlnrMArcguide* PlnrExp::addArcguideByVsrefs(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const string& cvsref
			, const double r
			, const vector<string>& vsrefs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMArcguide& ags
		) {
	PlnrMArcguide* ag = NULL;

	string vsref;

	PlnrMVertex* vtx = NULL;

	// for center vertex, find index in vtxs
	unsigned int cvix;
	
	for (cvix=0;cvix<vtxs.nodes.size();cvix++) {
		vtx = vtxs.nodes[cvix];
		if (vtx->sref.compare(cvsref) == 0) break;
	};

	// for each string entry in vsrefs, find corresponding index in vtxs
	vector<unsigned int> vics;
	unsigned int vix;

	for (unsigned int i=0;i<vsrefs.size();i++) {
		vsref = vsrefs[i];

		for (vix=0;vix<vtxs.nodes.size();vix++) {
			vtx = vtxs.nodes[vix];
			if (vtx->sref.compare(vsref) == 0) break;
		};

		vics.push_back(vix);
	};

	ag = addArcguideByVics(dbsplnr, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, cvix, r, vics, vtxs, ags);

	return ag;
};

PlnrMArcguide* PlnrExp::addArcguideByVics(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const unsigned int cvix
			, const double r
			, const vector<unsigned int>& vics
			, const ListPlnrMVertex& vtxs
			, ListPlnrMArcguide& ags
		) {
	PlnrMArcguide* ag = NULL;

	ListPlnrLRMArcguideMVertex arvs;
	PlnrLRMArcguideMVertex* arv = NULL;

	ag = new PlnrMArcguide(0, x1RefPlnrMDesign, 0, VecPlnrVLat::INI, hkIxVTbl, hkUref, sref, vtxs.nodes[cvix]->ref, r);
	dbsplnr->tblplnrmarcguide->insertRec(ag); ags.nodes.push_back(ag);

	// vertex line-up
	for (unsigned int i=0;i<vics.size();i++) {
		arv = new PlnrLRMArcguideMVertex(0, VecPlnrVLat::INI, ag->ref, (i+1), vtxs.nodes[vics[i]]->ref);
		dbsplnr->tblplnrlrmarcguidemvertex->insertRec(arv); arvs.nodes.push_back(arv);
	};

	return ag;
};

void PlnrExp::addArcguides(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const vector<string>& srefs
			, const vector<string>& cvsrefs
			, const vector<double>& rs
			, const vector<string>& vsrefsstrs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMArcguide& ags
		) {
	vector<string> vsrefs;

	for (unsigned int i=0;i<srefs.size();i++) {
		// break down element of vsrefsstrs (comma-separated list) into vector of vertex sref's
		StrMod::stringToVector(vsrefsstrs[i], vsrefs);

		addArcguideByVsrefs(dbsplnr, x1RefPlnrMDesign, hkIxVTbl, hkUref, srefs[i], cvsrefs[i], rs[i], vsrefs, vtxs, ags);
	};
};

void PlnrExp::addArcguideRByAsref(
			DbsPlnr* dbsplnr
			, const string& asref
			, const ubigint x1RefPlnrMDesign
			, const double r
			, const ListPlnrMArcguide& ags
		) {
	PlnrMArcguide* ag = NULL;

	unsigned int aix;

	for (aix=0;aix<ags.nodes.size();aix++) {
		ag = ags.nodes[aix];
		if (ag->sref.compare(asref) == 0) break;
	};

	addArcguideRByAix(dbsplnr, aix, x1RefPlnrMDesign, r, ags);
};

void PlnrExp::addArcguideRByAix(
			DbsPlnr* dbsplnr
			, const unsigned int aix
			, const ubigint x1RefPlnrMDesign
			, const double r
			, const ListPlnrMArcguide& ags
		) {
	PlnrJMArcguideR* agj = NULL;

	agj = new PlnrJMArcguideR(0, ags.nodes[aix]->ref, x1RefPlnrMDesign, r);
	dbsplnr->tblplnrjmarcguider->insertRec(agj);

	delete agj;
};

void PlnrExp::addArcguideRs(
			DbsPlnr* dbsplnr
			, const vector<string>& asrefs
			, const ubigint x1RefPlnrMDesign
			, const vector<double>& rs
			, const ListPlnrMArcguide& ags
		) {
	for (unsigned int i=0;i<asrefs.size();i++) addArcguideRByAsref(dbsplnr, asrefs[i], x1RefPlnrMDesign, rs[i], ags);
};

void PlnrExp::opaddArcguideByVsrefs(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, const string& cvsref
			, const double r
			, const vector<string>& vsrefs
			, const ListPlnrMVertex& vtxs
			, ListPlnrMArcguide& ags
		) {
	PlnrMArcguide* ag = NULL;

	PlnrDevOMDeviceMArcguide* devagdo = NULL;

	ag = addArcguideByVsrefs(dbsplnr,	x1RefPlnrMDesign, VecPlnrVMArcguideHkTbl::DEV, refSupdev, sref, cvsref, r, vsrefs, vtxs, ags);
	ag->hkIxPlnrVLat = VecPlnrVLat::DLO;
	dbsplnr->tblplnrmarcguide->updateRec(ag);

	devagdo = new PlnrDevOMDeviceMArcguide(0, refSupdev, refSubdev, VecPlnrVLop::INS, ag->ref);
	dbsplnr->tblplnrdevomdevicemarcguide->insertRec(devagdo);
	delete devagdo;
};

void PlnrExp::opsubArcguide(
			DbsPlnr* dbsplnr
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const string& sref
			, const ListPlnrMArcguide& ags
		) {
	PlnrMArcguide* ag = NULL;

	PlnrDevOMDeviceMArcguide* devagdo = NULL;

	for (unsigned int i=0;i<ags.nodes.size();i++) {
		ag = ags.nodes[i];

		if (ag->sref.compare(sref) == 0) {
			devagdo = new PlnrDevOMDeviceMArcguide(0, refSupdev, refSubdev, VecPlnrVLop::RMV, ag->ref);
			dbsplnr->tblplnrdevomdevicemarcguide->insertRec(devagdo);
			delete devagdo;

			break;
		};
	};
};

PlnrMFace* PlnrExp::addFaceByVgsrefs(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const ubigint strRefPlnrMStructure
			, const string& sref
			, const vector<string>& vsrefs
			, const vector<string>& rtes
			, const vector<string>& gsrefs
			, const vector<string>& dirs
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	PlnrMFace* fce = NULL;

	string vsref;
	string gsref;

	PlnrMVertex* vtx = NULL;
	PlnrMLineguide* lg = NULL;
	PlnrMArcguide* ag = NULL;

	vector<unsigned int> vics;
	unsigned int vix;
	vector<unsigned int> icsRte;
	unsigned int ixRte;
	vector<unsigned int> gics;
	unsigned int gix;
	vector<unsigned int> icsDir;

	// for each string entry in vsrefs, find corresponding index in vtxs, VecPlnrVRMFaceMVertexRteTbl, lgs/ags and VecPlnrVRMFaceMVertexDir
	for (unsigned int i=0;i<vsrefs.size();i++) {
		vsref = vsrefs[i];
		for (vix=0;vix<vtxs.nodes.size();vix++) {
			vtx = vtxs.nodes[vix];
			if (vtx->sref.compare(vsref) == 0) break;
		};
		vics.push_back(vix);

		ixRte = VecPlnrVRMFaceMVertexRteTbl::getIx(rtes[i]);
		icsRte.push_back(ixRte);

		gsref = gsrefs[i];
		gix = 0;
		if (ixRte == VecPlnrVRMFaceMVertexRteTbl::LGD) {
			for (gix=0;gix<lgs.nodes.size();gix++) {
				lg = lgs.nodes[gix];
				if (lg->sref.compare(gsref) == 0) break;
			};
		} else if (ixRte == VecPlnrVRMFaceMVertexRteTbl::AGD) {
			for (gix=0;gix<ags.nodes.size();gix++) {
				ag = ags.nodes[gix];
				if (ag->sref.compare(gsref) == 0) break;
			};
		};
		gics.push_back(gix);

		icsDir.push_back(VecPlnrVRMFaceMVertexDir::getIx(dirs[i]));
	};

	fce = addFaceByVgics(dbsplnr, x1RefPlnrMDesign, strRefPlnrMStructure, sref, vics, icsRte, gics, icsDir, vtxs, lgs, ags, fces);

	return fce;
};

PlnrMFace* PlnrExp::addFaceByVgics(
			DbsPlnr* dbsplnr
			,	const ubigint x1RefPlnrMDesign
			, const ubigint strRefPlnrMStructure
			, const string& sref
			, const vector<unsigned int>& vics
			, const vector<unsigned int>& icsRte
			, const vector<unsigned int>& gics
			, const vector<unsigned int>& icsDir
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	PlnrMFace* fce = NULL;

	ListPlnrRMFaceMVertex frvs;
	PlnrRMFaceMVertex* frv = NULL;

	fce = new PlnrMFace(0, x1RefPlnrMDesign, 0, VecPlnrVLat::INI, strRefPlnrMStructure, sref);
	dbsplnr->tblplnrmface->insertRec(fce); fces.nodes.push_back(fce);

	// vertex line-up
	for (unsigned int i=0;i<vics.size();i++) {
		if (icsRte[i] == VecPlnrVRMFaceMVertexRteTbl::LGD) {
			frv = new PlnrRMFaceMVertex(0, fce->ref, (i+1), vtxs.nodes[vics[i]]->ref, icsRte[i], lgs.nodes[gics[i]]->ref, icsDir[i]);
		} else if (icsRte[i] == VecPlnrVRMFaceMVertexRteTbl::AGD) {
			frv = new PlnrRMFaceMVertex(0, fce->ref, (i+1), vtxs.nodes[vics[i]]->ref, icsRte[i], ags.nodes[gics[i]]->ref, icsDir[i]);
		};
		dbsplnr->tblplnrrmfacemvertex->insertRec(frv); frvs.nodes.push_back(frv);
	};

	return fce;
};

void PlnrExp::addFaces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const vector<ubigint>& strrefs
			, const vector<string>& srefs
			, const vector<string>& vsrefsstrs
			, const vector<string>& rtesstrs
			, const vector<string>& gsrefsstrs
			, const vector<string>& dirsstrs
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	vector<string> vsrefs;
	vector<string> rtes;
	vector<string> gsrefs;
	vector<string> dirs;

	for (unsigned int i=0;i<srefs.size();i++) {
		StrMod::stringToVector(vsrefsstrs[i], vsrefs);
		StrMod::stringToVector(rtesstrs[i], rtes);
		StrMod::stringToVector(gsrefsstrs[i], gsrefs);
		StrMod::stringToVector(dirsstrs[i], dirs);

		addFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, strrefs[i], srefs[i], vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	};
};

void PlnrExp::opaddFaceByVgsrefs(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refSupdev
			, const ubigint refSubdev
			, const ubigint strRefPlnrMStructure
			, const string& sref
			, const vector<string>& vsrefs
			, const vector<string>& rtes
			, const vector<string>& gsrefs
			, const vector<string>& dirs
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, const ListPlnrMArcguide& ags
			, ListPlnrMFace& fces
		) {
	PlnrMFace* fce = NULL;

	PlnrOMStructureMFace* strfceo = NULL;

	fce = addFaceByVgsrefs(dbsplnr, x1RefPlnrMDesign, strRefPlnrMStructure, sref, vsrefs, rtes, gsrefs, dirs, vtxs, lgs, ags, fces);
	fce->sruIxPlnrVLat = VecPlnrVLat::DLO;
	dbsplnr->tblplnrmface->updateRec(fce);

	strfceo = new PlnrOMStructureMFace(0, strRefPlnrMStructure, refSubdev, VecPlnrVLop::INS, fce->ref);
	dbsplnr->tblplnromstructuremface->insertRec(strfceo);
	delete strfceo;
};

void PlnrExp::opsubFace(
			DbsPlnr* dbsplnr
			, const ubigint refSubdev
			, const string& sref
			, const ubigint refSru
			, const ListPlnrMFace& fces
		) {
	PlnrMFace* fce = NULL;

	PlnrOMStructureMFace* strfceo = NULL;

	for (unsigned int i=0;i<fces.nodes.size();i++) {
		fce = fces.nodes[i];

		if (fce->sref.compare(sref) == 0) {
			strfceo = new PlnrOMStructureMFace(0, refSru, refSubdev, VecPlnrVLop::RMV, fce->ref);
			dbsplnr->tblplnromstructuremface->insertRec(strfceo);
			delete strfceo;

			break;
		};
	};
};

unsigned int PlnrExp::loadStackN(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const PlnrMStack* stk
		) {
	PlnrJMStackN* stkj = NULL;

	int retval = 0;
	string s;

	map<string, string> env; // dummy

	s = Fct::evalStkN(env, stk, true);
	retval = atoi(s.c_str());

	if (x1RefPlnrMDesign != 0) {
		if (dbsplnr->tblplnrjmstackn->loadRecByStkDsn(stk->ref, x1RefPlnrMDesign, &stkj)) {
			retval = atoi(stkj->N.c_str());
			delete stkj;
		};
	};

	return ((retval > 0) ? retval : 0);
};

double PlnrExp::loadLayerT(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const PlnrMLayer* lyr
		) {
	PlnrJMLayer* lyrj = NULL;

	double retval = 0.0;
	string s;

	map<string, string> env; // dummy

	s = Fct::evalLyrT(env, lyr, true);
	retval = atof(s.c_str());

	if (x1RefPlnrMDesign != 0) {
		if (dbsplnr->tblplnrjmlayer->loadRecByLyrDsn(lyr->ref, x1RefPlnrMDesign, &lyrj)) {
			retval = atof(lyrj->t.c_str());
			delete lyrj;
		};
	};

	return retval;
};

void PlnrExp::addStkModtype(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	PlnrJMStackModtype* sjm = NULL;

	sjm = new PlnrJMStackModtype(0, refPlnrMStack, x1RefPlnrMDesign, ixVModtype);
	dbsplnr->tblplnrjmstackmodtype->insertRec(sjm);

	delete sjm;
};

PlnrMLevel* PlnrExp::addLevel(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string& sref
			, const double z
			, ListPlnrMLevel& lvls
		) {
	PlnrMLevel* lvl = NULL;

	lvl = new PlnrMLevel(0, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z);
	dbsplnr->tblplnrmlevel->insertRec(lvl); lvls.nodes.push_back(lvl);

	return lvl;
};

void PlnrExp::addLevelZByZsref(
			DbsPlnr* dbsplnr
			, const string& zsref
			, const ubigint x1RefPlnrMDesign
			, const double z
			, const ListPlnrMLevel& lvls
		) {
	PlnrMLevel* lvl = NULL;
	PlnrJMLevelZ* lvlz = NULL;

	for (unsigned int i=0;i<lvls.nodes.size();i++) {
		lvl = lvls.nodes[i];

		if (lvl->sref.compare(zsref) == 0) {
			lvlz = new PlnrJMLevelZ(0, lvl->ref, x1RefPlnrMDesign, z);
			dbsplnr->tblplnrjmlevelz->insertRec(lvlz);
			delete lvlz;

			break;
		};
	};
};

void PlnrExp::addLvlLvl(
			DbsPlnr* dbsplnr
			, const ubigint stkRefPlnrMLevel
			, const ubigint dsnRefPlnrMLevel
		) {
	PlnrRMLevelMLevel* lrl = NULL;

	lrl = new PlnrRMLevelMLevel(0, stkRefPlnrMLevel, dsnRefPlnrMLevel);
	dbsplnr->tblplnrrmlevelmlevel->insertRec(lrl);

	delete lrl;
};

string PlnrExp::intToPnstr(
			const int val
		) {
	ostringstream str;

	if (val < 0) str << "n" << (-val);
	else if (val == 0) str << "0";
	else if (val > 0) str << "p" << val;

	return str.str();
};

string PlnrExp::mnToStr(
			const int m
			, const int n
			, const string& prefix
			, const string& postfix
		) {
	ostringstream str;

	// ex. fmp7_nn1_1
	str << prefix << "m" << intToPnstr(m) << "_n" << intToPnstr(n) << postfix;

	return str.str();
};

double PlnrExp::degToRad(
			const double deg
		) {
	return(pi*deg/180.0);
};
// IP cust --- IEND


