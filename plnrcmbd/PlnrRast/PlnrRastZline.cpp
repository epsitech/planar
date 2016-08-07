/**
  * \file PlnrRastZline.cpp
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

#include "PlnrRastZline.h"

DpchRetPlnrRastZline* PlnrRastZline::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrRastZline* dpchinv
		) {
	DpchRetPlnrRastZline* dpchret = new DpchRetPlnrRastZline();

	ubigint refPlnrMDesign = dpchinv->refPlnrMDesign;

// IP run --- IBEGIN
	string cdfpath;
	ostringstream fullpath;

	int res;

	ostringstream sqlstr;

	PlnrMDesign* dsn = NULL;

	ubigint refBasedsn;
	ubigint refModdsn;

	uint refIxVTbl;
	ubigint refUref, refCal;

	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;

	bool hasz;
	double dx, dy, dxy, dz;

	ListPlnrMLevel lvls;
	map<ubigint, unsigned int> lvlics;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;
	map<ubigint, unsigned int> lyrics;

	ubigint refMat;

	vector<double> lyrzmins;
	vector<double> lyrzmaxs;
	vector<bool> lyracts;

	PlnrMLevel* flrlvl = NULL;
	PlnrMLevel* ceillvl = NULL;

	double zmin, zmax;

	// variables for cdf file (general)
	int cdfRoot;
	int cdfDim;

	int cdfLayers;
	vector<double> lyrz0; int cdfLyrz0;
	vector<double> lyrz1; int cdfLyrz1;
	vector<unsigned int> ixMats; int cdfIxMats;

	vector<ubigint> mats; int cdfMats;
	map<ubigint, unsigned int> matics;

	// variables for cdf file (domain-specific)
	int cdfDoms;
	int cdfDom;
	unsigned int dimZ;
	int cdf_ixVBasetype;
	double _z0; int cdf_z0;
	double _z1; int cdf_z1;
	double _dz; int cdf_dz;
	double b3; int cdf_b3;

	// generate file in temp folder and open
	cdfpath = Tmp::newfile(xchg->tmppath, "cdf");

	fullpath.str(""); fullpath << xchg->tmppath << "/" << cdfpath;
	res = nc_create(fullpath.str().c_str(), NC_NETCDF4, &cdfRoot);

	// -- find base / modified design
	sqlstr.str(""); sqlstr << "SELECT modRefPlnrMDesign FROM TblPlnrMDesign WHERE ref = " << refPlnrMDesign;
	dbsplnr->loadUbigintBySQL(sqlstr.str(), refBasedsn);

	if (refBasedsn == 0) {
		refBasedsn = refPlnrMDesign;
		refModdsn = 0;
	} else {
		refModdsn = refPlnrMDesign;
	};

	// -- load domains
	dbsplnr->tblplnrmdomain->loadRstByDsn(refBasedsn, false, doms);

	// -- load design levels
	if (dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::DSN, refModdsn, false, lvls) == 0)
		dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::DSN, refBasedsn, false, lvls);
	for (unsigned int j=0;j<lvls.nodes.size();j++) lvlics[lvls.nodes[j]->ref] = j;

	// -- load design layers and find their z limits
	if (dbsplnr->tblplnrmlayer->loadRstByHktHku(VecPlnrVMLayerHkTbl::DSN, refModdsn, false, lyrs) == 0)
		dbsplnr->tblplnrmlayer->loadRstByHktHku(VecPlnrVMLayerHkTbl::DSN, refBasedsn, false, lyrs);

	lyrzmins.resize(lyrs.nodes.size());
	lyrzmaxs.resize(lyrs.nodes.size());
	lyracts.resize(lyrs.nodes.size());

	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		lyr = lyrs.nodes[j];

		lyrics[lyr->ref] = j;

		lyrzmins[j] = lvls.nodes[lvlics[lyr->flrRefPlnrMLevel]]->z;
		lyrzmaxs[j] = lvls.nodes[lvlics[lyr->ceilRefPlnrMLevel]]->z;
	};

	// -- set up inventory of materials used
	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		lyr = lyrs.nodes[j];

		refMat = lyr->refPlnrMMaterial;
		if (refModdsn != 0) {
			sqlstr.str(""); sqlstr << "SELECT refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE x0RefPlnrMLayer = " << lyr->ref
						<< " AND x1RefPlnrMDesign = " << refModdsn;
			dbsplnr->loadUbigintBySQL(sqlstr.str(), refMat);
		};

		if (matics.find(refMat) == matics.end()) {
			matics[refMat] = mats.size();
			mats.push_back(refMat);
		};
	};

	// -- traverse domains to determine z range (design coordinates)
	zmin = 1.0e6; zmax = -1.0e6;

	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		flrlvl = NULL;
		ceillvl = NULL;

		// - find boundary levels
		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->flrSrefPlnrMLevel, &flrlvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->flrSrefPlnrMLevel, &flrlvl);

		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->ceilSrefPlnrMLevel, &ceillvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->ceilSrefPlnrMLevel, &ceillvl);

		// - adapt range
		if (flrlvl) {
			if (flrlvl->z < zmin) zmin = flrlvl->z;
			if (flrlvl->z > zmax) zmax = flrlvl->z;
		};
		if (ceillvl) {
			if (ceillvl->z < zmin) zmin = ceillvl->z;
			if (ceillvl->z > zmax) zmax = ceillvl->z;
		};

		if (flrlvl) delete flrlvl;
		if (ceillvl) delete ceillvl;
	};

	// -- determine layers overlapping with range
	for (unsigned int j=0;j<lyrs.nodes.size();j++) lyracts[j] = ((lyrzmins[j] < zmax) && (lyrzmaxs[j] > zmin));

	// -- write layers
	for (unsigned int j=0;j<lyrs.nodes.size();j++) {
		if (lyracts[j]) {
			lyr = lyrs.nodes[j];

			lyrz0.push_back(lyrzmins[j]);
			lyrz1.push_back(lyrzmaxs[j]);
			ixMats.push_back(matics[lyr->refPlnrMMaterial]);
		};
	};

	// -- write general variables to cdf file, definitions first
	nc_redef(cdfRoot);
		nc_def_dim(cdfRoot, "dimLayers", lyrz0.size(), &cdfDim);
		nc_def_grp(cdfRoot, "layers", &cdfLayers);
			nc_def_var(cdfLayers, "z0", NC_DOUBLE, 1, &cdfDim, &cdfLyrz0);
			nc_def_var(cdfLayers, "z1", NC_DOUBLE, 1, &cdfDim, &cdfLyrz1);
			nc_def_var(cdfLayers, "ixMats", NC_UINT, 1, &cdfDim, &cdfIxMats);
		nc_def_dim(cdfRoot, "dimMats", mats.size(), &cdfDim);
		nc_def_var(cdfRoot, "mats", NC_UINT64, 1, &cdfDim, &cdfMats);
		nc_def_grp(cdfRoot, "doms", &cdfDoms);
	nc_enddef(cdfRoot);

	Cdf::putDoubleVec(cdfLayers, cdfLyrz0, lyrz0);
	Cdf::putDoubleVec(cdfLayers, cdfLyrz1, lyrz1);
	Cdf::putUintVec(cdfLayers, cdfIxMats, ixMats);

	Cdf::putUbigintVec(cdfRoot, cdfMats, mats);

	// -- traverse domains to determine individual coordinate transforms
	for (unsigned int i=0;i<doms.nodes.size();i++) {
		dom = doms.nodes[i];

		hasz = (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z);

		Plnr::getDomrast(dbsplnr, dom, refModdsn, dx, dy, dxy, dz);

		flrlvl = NULL;
		ceillvl = NULL;

		// find boundary levels
		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->flrSrefPlnrMLevel, &flrlvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->flrSrefPlnrMLevel, &flrlvl);

		if (!dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refModdsn, dom->ceilSrefPlnrMLevel, &ceillvl))
			dbsplnr->tblplnrmlevel->loadRecByHktHkuSrf(VecPlnrVMLevelHkTbl::DSN, refBasedsn, dom->ceilSrefPlnrMLevel, &ceillvl);

		// determine coordinate transform, from domain-centered coordinates to design coordinates
		if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) {
			// dz relevant discretization parameter, dx/dy/dxy not used
			_z0 = -0.5*(ceillvl->z - flrlvl->z);
			_z1 = -_z0;
			_dz = (_z1-_z0) / ceil((_z1-_z0) / dz);

			b3 = 0.5*(ceillvl->z + flrlvl->z);

			dimZ = lround(fabs((_z1-_z0) / _dz)) + 1;

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::POINT_Z) {
			b3 = flrlvl->z;
		};

		if (flrlvl) delete flrlvl;
		if (ceillvl) delete ceillvl;

		// - write domain-specific variables to cdf file, definitions first
		nc_redef(cdfRoot);
			nc_def_grp(cdfDoms, dom->sref.c_str(), &cdfDom);
				if (hasz) nc_def_dim(cdfDom, "dimZ", dimZ, &cdfDim);
				nc_def_var(cdfDom, "ixVBasetype", NC_UINT, 0, NULL, &cdf_ixVBasetype);
				if (hasz) {
					nc_def_var(cdfDom, "z0", NC_DOUBLE, 0, NULL, &cdf_z0);
					nc_def_var(cdfDom, "z1", NC_DOUBLE, 0, NULL, &cdf_z1);
					nc_def_var(cdfDom, "dz", NC_DOUBLE, 0, NULL, &cdf_dz);
				};
				nc_def_var(cdfDom, "b3", NC_DOUBLE, 0, NULL, &cdf_b3);
		nc_enddef(cdfRoot);
		if (hasz) {
			nc_put_var_double(cdfDom, cdf_z0, &_z0);
			nc_put_var_double(cdfDom, cdf_z1, &_z1);
			nc_put_var_double(cdfDom, cdf_dz, &_dz);
		};
		nc_put_var_double(cdfDom, cdf_b3, &b3);
		nc_put_var_uint(cdfDom, cdf_ixVBasetype, &(dom->ixVBasetype));
	};

	nc_close(cdfRoot);

	// -- add file to archive and return ref
	refIxVTbl = VecPlnrVMFileRefTbl::VOID;
	refUref = 0;

	dbsplnr->tblplnrmdesign->loadRecByRef(refPlnrMDesign, &dsn);

	if (dsn) {
		if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CAL) {
			refIxVTbl = VecPlnrVMFileRefTbl::CAL;
		} else if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CLI) {
			refIxVTbl = VecPlnrVMFileRefTbl::CLI;
		};

		refUref = dsn->refUref;
	};

	dpchret->refPlnrMFile = Acv::addfile(dbsplnr, xchg->acvpath, fullpath.str(), refIxVTbl, refUref, "rast", "rast.cdf", "nc", "");

	if (dsn) {
		if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CAL) {
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, 0, dsn->refUref, dpchret->refPlnrMFile, VecPlnrVRMCalcMFileIo::IMD);

		} else if (dsn->refIxVTbl == VecPlnrVMDesignRefTbl::CLI) {
			sqlstr.str(""); sqlstr << "SELECT calRefPlnrMCalc FROM TblPlnrMCalcitem WHERE ref = " << dsn->refUref;
			dbsplnr->loadUbigintBySQL(sqlstr.str(), refCal);

			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, dsn->refUref, refCal, dpchret->refPlnrMFile, VecPlnrVRMCalcMFileIo::IMD);
		};

		delete dsn;
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


