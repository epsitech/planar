/**
  * \file Plnr.h
  * Plnr global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNR_H
#define PLNR_H

// IP incl --- IBEGIN
#include <netcdf.h>
// IP incl --- IEND

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "VecPlnrVCall.h"
#include "VecPlnrVDpch.h"
#include "VecPlnrVExpstate.h"
#include "VecPlnrVIop.h"
#include "VecPlnrVJob.h"
#include "VecPlnrVMimetype.h"
#include "VecPlnrVQrystate.h"
#include "VecPlnrVReqitmode.h"
#include "VecPlnrVStub.h"
#include "VecPlnrVTag.h"

#include <DbsPlnr.h>

#include <dartcore/Stub.h>

// IP acv --- BEGIN
/**
  * Acv
  */
namespace Acv {
	ubigint addfile(DbsPlnr* dbsplnr, const string& acvpath, const string& path, const uint refIxVTbl, const ubigint refUref, const string& osrefKContent, const string& Filename, const string& srefKMimetype, const string& Comment);
	void alterfile(DbsPlnr* dbsplnr, const string& acvpath, const string& path, const ubigint ref);
	string getfile(DbsPlnr* dbsplnr, const ubigint refPlnrMFile);
};
// IP acv --- END

/**
  * Lop
  */
namespace Lop {
	void apply(const uint ixPlnrVLop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);

	void insert(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
};

/**
  * Oolop
  */
namespace Oolop {
	void apply(const uint ixPlnrVOolop, vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);

	void insertBefore(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void insertAfter(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref1, const ubigint ref2);
	void remove(vector<ubigint>& refsList, vector<ubigint>& refsPool, const ubigint ref);
	void toBefore(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void toAfter(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
	void swap(vector<ubigint>& refsList, const ubigint ref1, const ubigint ref2);
};

/**
  * Tmp
  */
namespace Tmp {
	string newfile(const string& tmppath, const string& ext);
	string newfolder(const string& tmppath);
	string random();
};

// IP cust --- IBEGIN
/**
  * Cdf
  */
namespace Cdf {
	void putBoolVec(const int ncid, const int varid, const vector<bool>& vec);
	void putUintVec(const int ncid, const int varid, const vector<uint>& vec);
	void putUbigintVec(const int ncid, const int varid, const vector<ubigint>& vec);
	void putDoubleVec(const int ncid, const int varid, const vector<double>& vec);

	bool getGroup(const int ncid, const string& path, int& pathid);

	bool getBoolVec(const int ncid, const string& path, const string& varsref, vector<bool>& vec);
	bool getUintVec(const int ncid, const string& path, const string& varsref, vector<uint>& vec);
	bool getUbigintVec(const int ncid, const string& path, const string& varsref, vector<ubigint>& vec);
	bool getDoubleVec(const int ncid, const string& path, const string& varsref, vector<double>& vec);

	bool getDoubleVecSlc(const int ncid, const string& path, const string& varsref, const vector<string>& slcDims, const vector<int>& slcIcs, const unsigned int Ntarget, vector<double>& vec);

	bool getUint(const int ncid, const string& path, const string& varsref, uint& val);
	bool getDouble(const int ncid, const string& path, const string& varsref, double& val);

	bool getDim(const int ncid, const string& path, const string& dimsref, int& dimid, unsigned int& dim);

	bool getAttr(const int ncid, const string& path, const string& varsref, const string& attrsref, string& attr);
};

/**
  * Dotmatrix
  */
namespace Dotmatrix {
	typedef bool dm[35];

	bool dmNull(unsigned int ix);
	bool dmA(const unsigned int ix);
	bool dmB(const unsigned int ix);
	bool dmC(const unsigned int ix);
	bool dmD(const unsigned int ix);
	bool dmE(const unsigned int ix);
	bool dmF(const unsigned int ix);
	bool dmG(const unsigned int ix);
	bool dmH(const unsigned int ix);
	bool dmI(const unsigned int ix);
	bool dmJ(const unsigned int ix);
	bool dmK(const unsigned int ix);
	bool dmL(const unsigned int ix);
	bool dmM(const unsigned int ix);
	bool dmN(const unsigned int ix);
	bool dmO(const unsigned int ix);
	bool dmP(const unsigned int ix);
	bool dmQ(const unsigned int ix);
	bool dmR(const unsigned int ix);
	bool dmS(const unsigned int ix);
	bool dmT(const unsigned int ix);
	bool dmU(const unsigned int ix);
	bool dmV(const unsigned int ix);
	bool dmW(const unsigned int ix);
	bool dmX(const unsigned int ix);
	bool dmY(const unsigned int ix);
	bool dmZ(const unsigned int ix);
	bool dm0(const unsigned int ix);
	bool dm1(const unsigned int ix);
	bool dm2(const unsigned int ix);
	bool dm3(const unsigned int ix);
	bool dm4(const unsigned int ix);
	bool dm5(const unsigned int ix);
	bool dm6(const unsigned int ix);
	bool dm7(const unsigned int ix);
	bool dm8(const unsigned int ix);
	bool dm9(const unsigned int ix);
	bool dmDot(const unsigned int ix);
	bool dmLbrace(const unsigned int ix);
	bool dmRbrace(const unsigned int ix);
	bool dmLsqbra(const unsigned int ix);
	bool dmRsqbra(const unsigned int ix);
	bool dmSmaller(const unsigned int ix);
	bool dmGreater(const unsigned int ix);
	bool dmPlus(const unsigned int ix);
	bool dmMinus(const unsigned int ix);
	bool dmStar(const unsigned int ix);
	bool dmSlash(const unsigned int ix);
	bool dmPercent(const unsigned int ix);
	bool dmComma(const unsigned int ix);
	bool dmEqual(const unsigned int ix);
	bool dmVline(const unsigned int ix);
	bool dmHat(const unsigned int ix);

	bool getDot(const char c, const unsigned int ix);
};

/**
  * Cubrast
  */
class Cubrast {

protected:
	// global constants
	static constexpr double pi = 3.141592653589793238462643383279;

public:
	// - information as in cdf file

	// face information
	vector<double> x0;
	vector<double> x1;
	vector<double> y0;
	vector<double> y1;
	vector<double> pdx;
	vector<double> pdy;
	vector<double> z0;
	vector<double> z1;
	vector<unsigned int> ixEdges0;
	vector<unsigned int> ixEdges1;
	vector<unsigned int> ixLayers0;
	vector<unsigned int> ixLayers1;

	// edge information
	vector<bool> ag;
	vector<double> lx0;
	vector<double> ly0;
	vector<double> ldx;
	vector<double> ldy;
	vector<bool> accw;
	vector<double> ax0;
	vector<double> ay0;
	vector<double> ar;
	vector<double> aphi0;
	vector<double> aphi1;

	// layer information
	vector<double> lyrz0;
	vector<double> lyrz1;
	vector<unsigned int> ixMats;

	// material information
	vector<ubigint> mats;

	// domain information
	vector<string> domSref;
	vector<unsigned int> domDimX;
	vector<unsigned int> domDimY;
	vector<unsigned int> domDimXY;
	vector<unsigned int> domDimZ;
	vector<unsigned int> domIxVBasetype;
	vector<double> domX0;
	vector<double> domX1;
	vector<double> domDx;
	vector<double> domY0;
	vector<double> domY1;
	vector<double> domDy;
	vector<double> domXy0;
	vector<double> domXy1;
	vector<double> domDxy;
	vector<double> domZ0;
	vector<double> domZ1;
	vector<double> domDz;
	vector<double> domA11;
	vector<double> domA21;
	vector<double> domB1;
	vector<double> domB2;
	vector<double> domB3;

	map<string, unsigned int> domics;

public:
	// material parameter cache
	unsigned int matparN;
	vector<double> matpars; // retrieve using matpars[ixMat*matparN + getMatparIx("phot", "n")]

	vector<string> srefMatparCats;
	vector<string> srefMatparProps;
	vector<string> titMatparProps;

	unsigned int ixLastface;

public:
	Cubrast(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasesdn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefsMatparCat, const string& srefsMatparProp);
	~Cubrast();

public:
	inline bool isinFace(const unsigned int ixFace, const double x, const double y, const double z, unsigned int& ixMat);
	unsigned int getIxMat(const double x, const double y, const double z);
	double getMatpar(const double x, const double y, const double z, const unsigned int ixMatpar);

	bool getMatparIx(const string& srefMatparCat, const string& srefMatparProp, unsigned int& ixMatpar);
	bool getDomIx(const string& srefDom, unsigned int& ixDom);

	string matparCdf(const string& tmppath, const string& srefsDomain, const string& srefMatparCat, const string& srefMatparProp);
	int domCdf(const unsigned int ixDom, const int cdfRoot, int& cdfDimX, int& cdfDimY, int& cdfDimXY, int& cdfDimZ);
};

/**
  * Xyboxrast
  */
class Xyboxrast {

protected:
	// global constants
	static constexpr double pi = 3.141592653589793238462643383279;

public:
	// - information as in cdf file

	// face information
	vector<double> x0;
	vector<double> x1;
	vector<double> y0;
	vector<double> y1;
	vector<double> pdx;
	vector<double> pdy;
	vector<unsigned int> ixEdges0;
	vector<unsigned int> ixEdges1;
	vector<unsigned int> ixMats;

	// edge information
	vector<bool> ag;
	vector<double> lx0;
	vector<double> ly0;
	vector<double> ldx;
	vector<double> ldy;
	vector<bool> accw;
	vector<double> ax0;
	vector<double> ay0;
	vector<double> ar;
	vector<double> aphi0;
	vector<double> aphi1;

	// material information
	vector<ubigint> mats;

	// domain information
	vector<string> domSref;
	vector<unsigned int> domIxVBasetype;
	vector<unsigned int> domDimX;
	vector<unsigned int> domDimY;
	vector<unsigned int> domDimXY;
	vector<double> domX0;
	vector<double> domX1;
	vector<double> domDx;
	vector<double> domY0;
	vector<double> domY1;
	vector<double> domDy;
	vector<double> domXy0;
	vector<double> domXy1;
	vector<double> domDxy;
	vector<double> domA11;
	vector<double> domA21;
	vector<double> domB1;
	vector<double> domB2;

public:
	map<string, unsigned int> domics;

	// material parameter cache
	unsigned int matparN;
	vector<double> matpars; // retrieve using matpars[ixMat*matparN + getMatparIx("phot", "n")]

	vector<string> srefMatparCats;
	vector<string> srefMatparProps;
	vector<string> titMatparProps;

	unsigned int ixLastface;

public:
	Xyboxrast(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasesdn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefsMatparCat, const string& srefsMatparProp);
	~Xyboxrast();

public:
	inline bool isinFace(const unsigned int ixFace, const double x, const double y, unsigned int& ixMat);
	unsigned int getIxMat(const double x, const double y);
	double getMatpar(const double x, const double y, const unsigned int ixMatpar);

	bool getMatparIx(const string& srefMatparCat, const string& srefMatparProp, unsigned int& ixMatpar);
	bool getDomIx(const string& srefDom, unsigned int& ixDom);

	string matparCdf(const string& tmppath, const string& srefsDomain, const string& srefMatparCat, const string& srefMatparProp);
	int domCdf(const unsigned int ixDom, const int cdfRoot, int& cdfDimX, int& cdfDimY, int& cdfDimXY);
};

/**
  * Zlinerast
  */
class Zlinerast {

public:
	// - information as in cdf file

	// layer information
	vector<double> lyrz0;
	vector<double> lyrz1;
	vector<unsigned int> ixMats;

	// material information
	vector<ubigint> mats;

	// domain information
	vector<string> domSref;
	vector<unsigned int> domIxVBasetype;
	vector<unsigned int> domDimZ;
	vector<double> domZ0;
	vector<double> domZ1;
	vector<double> domDz;
	vector<double> domB3;

public:
	map<string, unsigned int> domics;

	// material parameter cache
	unsigned int matparN;
	vector<double> matpars; // retrieve using matpars[ixMat*matparN + getMatparIx("phot", "n")]

	vector<string> srefMatparCats;
	vector<string> srefMatparProps;
	vector<string> titMatparProps;

	unsigned int ixLastlayer;

public:
	Zlinerast(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasesdn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefsMatparCat, const string& srefsMatparProp);
	~Zlinerast();

public:
	inline bool isinLayer(const unsigned int ixLayer, const double z, unsigned int& ixMat);
	unsigned int getIxMat(const double z);
	double getMatpar(const double z, const unsigned int ixMatpar);

	bool getMatparIx(const string& srefMatparCat, const string& srefMatparProp, unsigned int& ixMatpar);
	bool getDomIx(const string& srefDom, unsigned int& ixDom);

	string matparCdf(const string& tmppath, const string& srefsDomain, const string& srefMatparCat, const string& srefMatparProp);
	int domCdf(const unsigned int ixDom, const int cdfRoot, int& cdfDimZ);
};

/**
  * Env
  */
namespace Env {
	string extractKey(const string& s);

	bool getBoolVal(const map<string, string>& env, const string& key);
	int getIntVal(const map<string, string>& env, const string& key);
	double getDoubleVal(const map<string, string>& env, const string& key);
	string getStringVal(const map<string, string>& env, const string& key);

	void setBoolVal(map<string, string>& env, const string& key, const bool val);
	void setIntVal(map<string, string>& env, const string& key, const int val);
	void setDoubleVal(map<string, string>& env, const string& key, const double val);
	void setStringVal(map<string, string>& env, const string& key, const string& val);

	void setForCli(DbsPlnr* dbsplnr, map<string, string>& env, const ubigint refPlnrMCalc, const ubigint refPlnrMCalcitem);
	void setForAri(DbsPlnr* dbsplnr, map<string, string>& env, const ubigint refPlnrMArray, const ubigint refPlnrMArrayitem);
};

/**
  * Mpa
	*/
class Mpa {

public:
	vector<ubigint> refsPlnrMFile;
	vector<string> srefsVar;
	vector<vector<double>*> vars;

public:
	Mpa();
	~Mpa();

	bool findVar(const ubigint refPlnrMFile, const string& srefVar, unsigned int& ixVar);
	bool getVar(DbsPlnr* dbsplnr, const string& acvpath, const ubigint refPlnrMFile, const string& srefVar, vector<double>*& var);
	void loadVars(DbsPlnr* dbsplnr, const string& acvpath, const ubigint refPlnrMFile, const vector<string>& srefs);
};

/**
  * Fct
  */
namespace Fct {
	bool parse(const string& expr, const string& fct, vector<string>& args);

	bool venavlDgdTyp(const uint ixVBasetype, const uint dsnDim);
	void venavlDgdTyp(vector<uint>& icsVBasetype, const uint dsnDim);

	bool venavlDomTyp(const uint ixVBasetype, const uint dsnDim);
	void venavlDomTyp(vector<uint>& icsVBasetype, const uint dsnDim);

	bool klkavlMatAparPrp(const PlnrAVKeylistKey* klk, const string& matAparCat);
	void klkavlMatAparPrp(const ListPlnrAVKeylistKey& klks, vector<bool>& avl, const string& matAparCat);

	string evalMatAparVal(DbsPlnr* dbsplnr, const map<string, string>& env, Mpa& mpacache, const string& acvpath, const PlnrAMMaterialPar* mpa, const ubigint refBasesdn, const ubigint refModdsn, const bool forcedft = false);

	string evalDevAparVal(const map<string, string>& env, const PlnrAMDevicePar* dpa, const bool forcedft = false);

	string evalLyrT(const map<string, string>& env, const PlnrMLayer* lyr, const bool forcedft = false);
	string evalLyrMl(const map<string, string>& env, const PlnrMLayer* lyr, const bool forcedft = false);

	string evalStkN(const map<string, string>& env, const PlnrMStack* stk, const bool forcedft = false);

	string evalDgdD(const map<string, string>& env, const PlnrMDomaingd* dgd, const bool forcedft = false);
	string evalDgdDph(const map<string, string>& env, const PlnrMDomaingd* dgd, const bool forcedft = false);

	string evalDomDx(const map<string, string>& env, const PlnrMDomain* dom, const bool forcedft = false);
	string evalDomDy(const map<string, string>& env, const PlnrMDomain* dom, const bool forcedft = false);
	string evalDomDxy(const map<string, string>& env, const PlnrMDomain* dom, const bool forcedft = false);
	string evalDomDz(const map<string, string>& env, const PlnrMDomain* dom, const bool forcedft = false);
};
// IP cust --- IEND

/**
  * Plnr
  */
namespace Plnr {
// IP gbl --- IBEGIN
	constexpr double pi = 3.141592653589793238462643383279;

	double degToRad(const double deg);

	void removeDesign(DbsPlnr* dbsplnr, const ubigint refPlnrMDesign);
	void removeCalc(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc);
	void removeTapeout(DbsPlnr* dbsplnr, const ubigint refPlnrMTapeout);

	void getRefsDtp(DbsPlnr* dbsplnr, map<string, ubigint>& refsDtp);
	PlnrMDevice* addDeviceFromTpl(DbsPlnr* dbsplnr, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const ubigint supRefPlnrMDevice, const uint supNum, const string& sref, const uint ixVAligntype, const string& av1SrefPlnrMVertex, const string& pav1SrefPlnrMVertex, const string& av2SrefPlnrMVertex, const string& pav2SrefPlnrMVertex, const double x, const double y, const double phi, const string& Comment, map<string, ubigint>& refsDtp, const string& srefDtp, ListPlnrMDevice& devs);
	void changeBoolDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const bool Val);
	void changeIntDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const int Val);
	void changeDoubleDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const double Val);
	void changeDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const string& Val);
	void changeDpaReffile(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const ubigint Val);

	void addBoolDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const bool Val);
	void addIntDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const int Val);
	void addDoubleDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const double Val);
	void addDpa(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const string& Val);
	void addDpaReffile(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint x1RefPlnrMDesign, const string& x2SrefKKey, const ubigint Val);

	PlnrMLayer* addLayer(DbsPlnr* dbsplnr, const uint ixVBasetype, const ubigint hkUref, const uint hkNum, const ubigint refPlnrMMaterial, const uint ixVTtype, const string& sref, const double t, const string& ML, ListPlnrMLayer& lyrs);
	PlnrMLayer* addLayer(DbsPlnr* dbsplnr, const uint ixVBasetype, const ubigint hkUref, const uint hkNum, const ubigint refPlnrMMaterial, const uint ixVTtype, const string& sref, const string& t, const string& ML, ListPlnrMLayer& lyrs);
	void addLyrsru(DbsPlnr* dbsplnr, const ubigint refLyr, const ubigint refDev, const string& srefSru);
	void addLyrsru(DbsPlnr* dbsplnr, const ubigint refLyr, const string& srefDev, const string& srefSru, const ListPlnrMDevice& devs);
	void addLyrsru(DbsPlnr* dbsplnr, const string& srefLyr, const string& srefDev, const string& srefSru, const ListPlnrMLayer& lyrs, const ListPlnrMDevice& devs);
	void addStksru(DbsPlnr* dbsplnr, const string& srefStk, const string& srefDev, const string& srefSru, const string& fromSrefPlnrMLayer, const string& toSrefPlnrMLayer, const ListPlnrMStack& stks, const ListPlnrMDevice& devs);

	PlnrMDomaingd* addDomaingd(DbsPlnr* dbsplnr, const uint ixVBasetype, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string& sref, const string& srefPlnrMLevel, const string& av1SrefPlnrMVertex, const string& avaSrefPlnrMVertex, const string& al1SrefPlnrMLineguide, const string& al2SrefPlnrMLineguide, const string& srefPlnrMArcguide, const string& d, const string& dphi, ListPlnrMDomaingd& dgds);
	PlnrMDomain* addDomain(DbsPlnr* dbsplnr, const uint ixVBasetype, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string& sref, const string& flrSrefPlnrMLevel, const string& ceilSrefPlnrMLevel, const string& vtx1SrefPlnrMVertex, const string& lgd1SrefPlnrMLineguide, const string& vtx2SrefPlnrMVertex, const string& lgd2SrefPlnrMLineguide, const string& vtx3SrefPlnrMVertex, const string& lgd3SrefPlnrMLineguide, const string& vtx4SrefPlnrMVertex, const string& lgd4SrefPlnrMLineguide, ListPlnrMDomain& doms);

	void getDomrast(DbsPlnr* dbsplnr, PlnrMDomain* dom, const ubigint refModdsn, double& dx, double& dy, double& dxy, double& dz);

	PlnrMCalc* calcFromTpl(DbsPlnr* dbsplnr, const ubigint refPlnrMProject, const ubigint refPlnrMDesign, const string& Title, const string& titTpl, const string& Comment);
	void addBoolCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, const bool Val);
	void addIntCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, const int Val);
	void addDoubleCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, const double Val);

	void addDoubleCen(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKKey, const double Val);

	bool loadBoolCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, bool& val);
	bool loadIntCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, int& val);
	bool loadDoubleCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, double& val);
	bool loadStringCpa(DbsPlnr* dbsplnr, const ubigint refPlnrMCalc, const ubigint x1RefPlnrMCalcitem, const string& x2SrefKCat, const string& x3SrefKProp, string& val);

	ubigint findMat(DbsPlnr* dbsplnr, const string& hsref);
	void setMpa(DbsPlnr* dbsplnr, const ubigint refPlnrMMaterial, const ubigint x1RefPlnrMDesign, const string& x2SrefKCat, const string& x3SrefKProp, const string& Val);
	bool findMpa(DbsPlnr* dbsplnr, const ubigint refMat, const ubigint refBasesdn, const ubigint refModdsn, const string& srefCat, const string& srefProp, PlnrAMMaterialPar** mpa);

	void getDeviceExp(DbsPlnr* dbsplnr, const ubigint refPlnrMDevice, const ubigint refBasedsn, const ubigint refModdsn, const vector<ubigint>& refsSubdev, const bool init, ListPlnrMVertex& vtxs, vector<bool>& vtxacts,
				ListPlnrMLineguide& lgs, vector<bool>& lgacts, ListPlnrMArcguide& ags, vector<bool>& agacts, ListPlnrMStructure& srus, vector<unsigned int>& srufceics0, vector<unsigned int>& srufceics1,
				ListPlnrMFace& fces, vector<bool>& fceacts);
	void getLrvExp(DbsPlnr* dbsplnr, const ubigint refPlnrMLineguide, const vector<ubigint>& refsSubdev, const bool init, ListPlnrLRMLineguideMVertex& lrvs, vector<bool>& lrvacts);
	void getArvExp(DbsPlnr* dbsplnr, const ubigint refPlnrMArcguide, const vector<ubigint>& refsSubdev, const bool init, ListPlnrLRMArcguideMVertex& arvs, vector<bool>& arvacts);

	void getStackExp(DbsPlnr* dbsplnr, const ubigint refPlnrMStack, const ubigint refBasedsn, const ubigint refModdsn, const bool init, ListPlnrMLevel& lvls, ListPlnrMLayer& lyrs);

	void createAris(DbsPlnr* dbsplnr, PlnrMArray* arr, ListPlnrMArrayitem& aris);
	void addArrenv(DbsPlnr* dbsplnr, const ubigint refPlnrMArray, const ubigint x1RefPlnrMArrayitem, const string& x2SrefKKey, const double Val);
	void addArrenv(DbsPlnr* dbsplnr, const ubigint refPlnrMArray, const ubigint x1RefPlnrMArrayitem, const string& x2SrefKKey, const string& Val);
	void createArrrtcs(DbsPlnr* dbsplnr, const ubigint refPlnrMArray);
	string getAriSref(PlnrMArray* arr, PlnrMArrayitem* ari);

	void createModdsns(DbsPlnr* dbsplnr, const string& acvpath, const ubigint refPlnrMCalc, const ubigint refPlnrMArray, vector<ubigint>& refsModdsn);

	void cellstopToXyofs(const double rast, const string& cellstop, double& xofs, double& yofs);
	void crefToMn(const string& cref, int& m, int& n);
	void crefToXy(const double rast, const double xofs, const double yofs, const string& cref, double& x, double& y);
	void crefsToXyspan(const double rast, const double xofs, const double yofs, const string& crefSw, const string& crefNe, double& x, double& y, double& xsize, double& ysize);
// IP gbl --- IEND
};

/**
  * StubPlnr
  */
namespace StubPlnr {
	string getStub(DbsPlnr* dbsplnr, const uint ixPlnrVStub, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);

	string getStubAgdStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubAriStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubArrStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubBlkStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubCalStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubClcStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubCliStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubCtpStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDevShort(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDevStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDgdStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDomShort(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDomStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDsnStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDtpStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubDvcStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFceStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFilShort(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubFilStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubGrp(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubLgdStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubLvlStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubLyrStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubMatStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubOwn(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrjStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubPrsStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubRtcStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesMenu(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSesStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubSruStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubStkShort(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubStkStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubTpoStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsgStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubUsrStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
	string getStubVtxStd(DbsPlnr* dbsplnr, const ubigint ref, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const uint ixVNonetype = Stub::VecVNonetype::DASH, Stcch* stcch = NULL, stref_t* strefSub = NULL, const bool refresh = false);
};

/**
  * PlnrException
  */
struct PlnrException {
	string err;

	PlnrException(string err) {
		this->err = err;
	};
};

/**
	* ContInfPlnrAlert
	*/
class ContInfPlnrAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;

public:
	ContInfPlnrAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;

public:
	static bool all(const set<uint>& items);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> compare(const ContInfPlnrAlert* comp);
};

/**
  * DpchPlnr
  */
class DpchPlnr : public Block {

public:
	DpchPlnr(const uint ixPlnrVDpch = 0);
	virtual ~DpchPlnr();

public:
	uint ixPlnrVDpch;
};

/**
  * DpchInvPlnr
  */
class DpchInvPlnr : public DpchPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALL = 3;

public:
	DpchInvPlnr(const uint ixPlnrVDpch = VecPlnrVDpch::DPCHINVPLNR, const ubigint oref = 0, const ubigint jref = 0, const set<uint>& mask = {ALL});
	virtual ~DpchInvPlnr();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnr
  */
class DpchRetPlnr : public DpchPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint ALL = 4;

public:
	DpchRetPlnr(const uint ixPlnrVDpch = VecPlnrVDpch::DPCHRETPLNR, const string& scrOref = "", const string& scrJref = "", const bool success = false, const set<uint>& mask = {ALL});
	virtual ~DpchRetPlnr();

public:
	string scrOref;
	ubigint oref;
	string scrJref;
	ubigint jref;
	bool success;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	virtual void writeXML(xmlTextWriter* wr);
};

#endif


