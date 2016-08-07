/**
  * \file PlnrMeep.h
  * Plnr operation pack global code (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMEEP_H
#define PLNRMEEP_H

#include "PlnrMeep_blks.h"

// IP incl --- IBEGIN
#include <meep.hpp>
using namespace meep;
// IP incl --- IEND

namespace PlnrMeep {
// IP cust --- IBEGIN
	// global constants
	const double c0 = 299792458.0;

	const unsigned int ixMatparN = 0;
	const unsigned int ixMatparK = 1;
	const unsigned int ixMatparNo = 2;
	const unsigned int ixMatparNe = 3;
	const unsigned int ixMatparKo = 4;
	const unsigned int ixMatparKe = 5;

	complex<double> epscLrtz(const double epsinf, const vector<double>& omgs, const vector<double>& gams, const vector<double>& sigs, const double lam0);
	complex<double> epscLrtz0(const double epsinf, const double omg0, const double gam0, const double sig0, const double lam0);
	double dReEpscDOmgLrtz0(const double epsinf, const double omg0, const double gam0, const double sig0, const double lam0);
	double imEpscLrtz1(const double imEpsc0, const double omg1, const double gam1, const double sig1, const double lam0);
	double dImEpscDGamLrtz(const double imEpsc0, const double omg1, const double gam1, const double sig1, const double lam0);
	bool zeroReEpscLrtz(const double epsinf, const double omg0, const double gam0, const double sig0, const double lam0, const double reEpscTrg, const double tol, double* omg);
	bool zeroImEpscLrtz(const double imEpsc0, const double omg1, const double gam1, const double sig1, const double lam0, const double imEpscTrg, const double tol, double* gam);

	/**
		* CubrastMeep
		*/
	class CubrastMeep : public Cubrast, public material_function {

	public:
		unsigned int ixDom;

		double a11;
		double a21;

		double b1;
		double b2;
		double b3;

		double xoff;
		double yoff;
		double zoff;

		double lam0;

		bool anisomat;
		bool lossmat;

	public:
		CubrastMeep(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefDomain, const double lam0 = 1.55, const bool anisomat = false, const bool lossmat = false);
		~CubrastMeep();

	public:
		void dsnToMeep(const double xdsn, const double ydsn, const double zdsn, double& x, double& y, double& z);
		double getMaxN();
		double getMaxK();

	public:
		// overloaded methods of MEEP's material_function
		double chi1p1(field_type ft, const vec& r);
		double eps(const vec& r);
		bool has_conductivity(component c) {return(lossmat);};
		double conductivity(component c, const vec& r);
	};

	/**
		* ZcsboxrastMeep
		*/
	class ZcsboxrastMeep : public Cubrast, public material_function {

	public:
		unsigned int ixDom;

		double a11;
		double a21;

		double b1;
		double b2;
		double b3;

		double xyoff;
		double zoff;

		double lam0;

		bool anisomat;
		bool lossmat;

///
		vector<double> dispOmgs;
		vector<double> dispGams;
		vector<double> dispSigs;
		vector<unsigned int> icsDispMats;
///

	public:
		ZcsboxrastMeep(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefDomain, const double lam0 = 1.55, const bool anisomat = false, const bool lossmat = false);
		~ZcsboxrastMeep();

	public:
		void dsnToMeep(const double xdsn, const double ydsn, const double zdsn, double& x, double& y);
		double getMaxN();
		double getMaxK();

	public:
		// overloaded methods of MEEP's material_function
		double chi1p1(field_type ft, const vec& r);
		double eps(const vec& r);
		bool has_conductivity(component c) {return(lossmat);};
		double conductivity(component c, const vec& r);
	};

	/**
		* ZcsboxrastMeep_susc
		*/
	class ZcsboxrastMeep_susc : public material_function {

	public:
		ZcsboxrastMeep* rast;

		double a11, a21;
		double b1, b2, b3;
		double xyoff, zoff;

		double dispSig;
		unsigned int ixDispMat;

bool didDxBx, didDyBy, didDzBz, didOther;

	public:
		ZcsboxrastMeep_susc(ZcsboxrastMeep* rast, unsigned int ixOmgGam);

	public:
		void sigma_row(component c, double sigrow[3], const vec &r);
	};

	/**
		* XyboxrastMeep
		*/
	class XyboxrastMeep : public Xyboxrast, public material_function {

	public:
		unsigned int ixDom;

		double a11;
		double a21;

		double b1;
		double b2;

		double xoff;
		double yoff;

		double lam0;

		bool anisomat;
		bool lossmat;

	public:
		XyboxrastMeep(DbsPlnr* dbsplnr, const string& acvpath, const map<string, string>& env, const ubigint refBasedsn, const ubigint refModdsn, const ubigint refPlnrMFile, const string& srefDomain, const double lam0 = 1.55, const bool anisomat = false, const bool lossmat = false);
		~XyboxrastMeep();

	public:
		void dsnToMeep(const double xdsn, const double ydsn, double& x, double& y);
		double getMaxN();
		double getMaxK();

	public:
		// overloaded methods of MEEP's material_function
		double chi1p1(field_type ft, const vec& r);
		double eps(const vec& r);
		bool has_conductivity(component c) {return(lossmat);};
		double conductivity(component c, const vec& r);
	};
// IP cust --- IEND
};

#endif


