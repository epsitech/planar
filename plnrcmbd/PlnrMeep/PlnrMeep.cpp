/**
  * \file PlnrMeep.cpp
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

#include "PlnrMeep.h"

// IP cust --- IBEGIN
complex<double> PlnrMeep::epscLrtz(
			const double epsinf
			, const vector<double>& omgs
			, const vector<double>& gams
			, const vector<double>& sigs
			, const double lam0
		) {
	complex<double> retval;

	retval = epsinf;
	for (unsigned int i=0;i<omgs.size();i++) retval = retval + (sigs[i]*pow(omgs[i],2))/(pow(omgs[i],2)-pow(1.0/lam0,2)-complex<double>(0,1)*(1.0/lam0)*gams[i]);

	return retval;
};

inline complex<double> PlnrMeep::epscLrtz0(
			const double epsinf
			, const double omg0
			, const double gam0
			, const double sig0
			, const double lam0
		) {
	return(epsinf + sig0*pow(omg0,2)/(pow(omg0,2)-pow(1.0/lam0,2)-complex<double>(0,1)*(1.0/lam0)*gam0));
};

inline double PlnrMeep::dReEpscDOmgLrtz0(
			const double epsinf
			, const double omg0
			, const double gam0
			, const double sig0
			, const double lam0
		) {
	double domg = 1.0e-3*omg0;

	complex<double> epscp, epscm;

	epscp = epscLrtz0(epsinf, omg0+0.5*domg, gam0, sig0, lam0);
	epscm = epscLrtz0(epsinf, omg0-0.5*domg, gam0, sig0, lam0);

	return((epscp.real()-epscm.real())/domg);
};

inline double PlnrMeep::imEpscLrtz1(
			const double imEpsc0
			, const double omg1
			, const double gam1
			, const double sig1
			, const double lam0
		) {
	complex<double> resn1;

	resn1 = sig1*pow(omg1,2)/(pow(omg1,2)-pow(1.0/lam0,2)-complex<double>(0,1)*(1.0/lam0)*gam1);

	return(imEpsc0 + resn1.imag());
};

inline double PlnrMeep::dImEpscDGamLrtz(
			const double imEpsc0
			, const double omg1
			, const double gam1
			, const double sig1
			, const double lam0
		) {
	double dgam = 1.0e-3*gam1;

	return((imEpscLrtz1(imEpsc0, omg1, gam1+0.5*dgam, sig1, lam0)-imEpscLrtz1(imEpsc0, omg1, gam1-0.5*dgam, sig1, lam0))/dgam);
};

bool PlnrMeep::zeroReEpscLrtz(
			const double epsinf
			, const double omg0
			, const double gam0
			, const double sig0
			, const double lam0

			, const double reEpscTrg
			, const double tol
			, double* omg
		) {
	// vary omgtest and use Newton method until real part of epsc reaches reEpscTrg
	bool retval = false;

	double omgtest = omg0;
cout << "initial omgtest=" << omgtest << endl;
	complex<double> epsc;
	double reEpsc, reEpscnew, dreEpsc, residual;

	epsc = epscLrtz0(epsinf, omgtest, gam0, sig0, lam0);
	reEpsc = epsc.real();
cout << "initial reEpsc=" << reEpsc << ", reEpscTrg=" << reEpscTrg << endl;
	residual = fabs(reEpsc-reEpscTrg);

	while (residual > tol) {
		// change omgtest using Newton method
		dreEpsc = dReEpscDOmgLrtz0(epsinf, omgtest, gam0, sig0, lam0);
		omgtest = omgtest - (reEpsc-reEpscTrg)/dreEpsc;
cout << "new omgtest=" << omgtest << endl;

		// re-evaluate
		epsc = epscLrtz0(epsinf, omgtest, gam0, sig0, lam0);
		reEpscnew = epsc.real();
		if (fabs(reEpscnew-reEpsc) < 1.0e-6) break;
		reEpsc = reEpscnew;
		
		// require that residual becomes smaller on each iteration
		if (fabs(reEpsc-reEpscTrg) >= residual) break;
		residual = fabs(reEpsc-reEpscTrg);
	};

	if (residual <= tol) {
		// check if omgtest is in range
		if (omgtest > 0.0) {
			*omg = omgtest;
			retval = true;
		};
	};

	return retval;
};

bool PlnrMeep::zeroImEpscLrtz(
			const double imEpsc0
			, const double omg1
			, const double gam1
			, const double sig1
			, const double lam0

			, const double imEpscTrg
			, const double tol
			, double* gam
		) {
	// vary gamtest and use Newton method until imaginary part of epsc reaches imEpscTrg
	bool retval = false;

	double gamtest = gam1;
cout << "initial gamtest=" << gamtest << endl;

	double imEpsc, imEpscnew, dimEpsc, residual;

	imEpsc = imEpscLrtz1(imEpsc0, omg1, gamtest, sig1, lam0);
cout << "initial imEpsc=" << imEpsc << ", imEpscTrg=" << imEpscTrg << endl;
	residual = fabs(imEpsc-imEpscTrg);

	while (residual > tol) {
		// change gamtest using Newton method
		dimEpsc = dImEpscDGamLrtz(imEpsc0, omg1, gamtest, sig1, lam0);
		gamtest = gamtest - (imEpsc-imEpscTrg)/dimEpsc;
cout << "new gamtest=" << gamtest << endl;

		// re-evaluate
		imEpscnew = imEpscLrtz1(imEpsc0, omg1, gamtest, sig1, lam0);
		if (fabs(imEpscnew-imEpsc) < 1.0e-6) break;
		imEpsc = imEpscnew;
		
		// require that residual becomes smaller on each iteration
		if (fabs(imEpsc-imEpscTrg) >= residual) break;
		residual = fabs(imEpsc-imEpscTrg);
	};

	if (residual <= tol) {
		// check if gamtest is in range
		if (gamtest > 0.0) {
			*gam = gamtest;
			retval = true;
		};
	};

	return retval;
};

/******************************************************************************
 class PlnrMeep::CubrastMeep
 ******************************************************************************/

PlnrMeep::CubrastMeep::CubrastMeep(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefDomain
			, const double lam0
			, const bool anisomat
			, const bool lossmat
		) : Cubrast(dbsplnr, acvpath, env, refBasedsn, refModdsn, refPlnrMFile, "phot;phot;phot;phot;phot;phot", "n;k;no;ne;ko;ke"), material_function() {

	unsigned int ixDom =	domics[srefDomain];

	a11 = domA11[ixDom];
	a21 = domA21[ixDom];

	b1 = domB1[ixDom];
	b2 = domB2[ixDom];
	b3 = domB3[ixDom];

	xoff = 0.5*(domX1[ixDom]-domX0[ixDom]);
	yoff = 0.5*(domY1[ixDom]-domY0[ixDom]);
	zoff = 0.5*(domZ1[ixDom]-domZ0[ixDom]);

	this->lam0 = lam0;

	this->anisomat = anisomat;
	this->lossmat = lossmat;

	if (anisomat) {
		// fix cases in which n/k are present but not no/ne/ko/ke
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparN] != 0.0) && (matpars[i*matparN + ixMatparNo] == 0.0) && (matpars[i*matparN + ixMatparNe] == 0.0)) {
				matpars[i*matparN + ixMatparNo] = matpars[i*matparN + ixMatparN];
				matpars[i*matparN + ixMatparNe] = matpars[i*matparN + ixMatparN];
			};
			if ((matpars[i*matparN + ixMatparK] != 0.0) && (matpars[i*matparN + ixMatparKo] == 0.0) && (matpars[i*matparN + ixMatparKe] == 0.0)) {
				matpars[i*matparN + ixMatparKo] = matpars[i*matparN + ixMatparK];
				matpars[i*matparN + ixMatparKe] = matpars[i*matparN + ixMatparK];
			};
		};

	} else {
		// fix cases in which no/ko are present but not n/k
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparNo] != 0.0) && (matpars[i*matparN + ixMatparN] == 0.0)) matpars[i*matparN + ixMatparN] = matpars[i*matparN + ixMatparNo];
			if ((matpars[i*matparN + ixMatparNe] != 0.0) && (matpars[i*matparN + ixMatparK] == 0.0)) matpars[i*matparN + ixMatparK] = matpars[i*matparN + ixMatparNe];
		};
	};
};

PlnrMeep::CubrastMeep::~CubrastMeep() {
};

void PlnrMeep::CubrastMeep::dsnToMeep(
			const double xdsn
			, const double ydsn
			, const double zdsn
			, double& x
			, double& y
			, double& z
		) {
	x = a11*(xdsn-b1) + a21*(ydsn-b2) + xoff;
	y = -a21*(xdsn-b1) + a11*(ydsn-b2) + yoff;
	z = zdsn-b3 + zoff;
};

double PlnrMeep::CubrastMeep::getMaxN() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparNo] > retval) retval = matpars[i*matparN + ixMatparNo];
			if (matpars[i*matparN + ixMatparNe] > retval) retval = matpars[i*matparN + ixMatparNe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparN] > retval) retval = matpars[i*matparN + ixMatparN];
		};
	};

	return retval;
};

double PlnrMeep::CubrastMeep::getMaxK() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparKo] > retval) retval = matpars[i*matparN + ixMatparKo];
			if (matpars[i*matparN + ixMatparKe] > retval) retval = matpars[i*matparN + ixMatparKe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparK] > retval) retval = matpars[i*matparN + ixMatparK];
		};
	};

	return retval;
};

double PlnrMeep::CubrastMeep::chi1p1(
			field_type ft
			, const vec& r
		) {
	if (ft == E_stuff) return eps(r);
	else return 0.0;
};

double PlnrMeep::CubrastMeep::eps(
			const vec& r
		) {
	double xdsn, ydsn, zdsn;
	double n, k;

	xdsn = a11*(r.x()-xoff) - a21*(r.y()-yoff) + b1;
	ydsn = a21*(r.x()-xoff) + a11*(r.y()-yoff) + b2;
	zdsn = (r.z()-zoff) + b3;

	// anisotropy: to be implemented yet
	if (anisomat) {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparNo);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparKo);
	} else {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparK);
	};

	if (n < 0.0) return(-n*n); else return(n*n-k*k);
};

double PlnrMeep::CubrastMeep::conductivity(
			component c
			, const vec& r
		) {
	if (!lossmat) return 0.0;

	double xdsn, ydsn, zdsn;
	double n, k;

	xdsn = a11*(r.x()-xoff) - a21*(r.y()-yoff) + b1;
	ydsn = a21*(r.x()-xoff) + a11*(r.y()-yoff) + b2;
	zdsn = (r.z()-zoff) + b3;

	if (anisomat) {
		if ((c == Dz) || (c == Bz)) {
			n = getMatpar(xdsn, ydsn, zdsn, ixMatparNe);
			k = getMatpar(xdsn, ydsn, zdsn, ixMatparKe);
		} else {
			n = getMatpar(xdsn, ydsn, zdsn, ixMatparNo);
			k = getMatpar(xdsn, ydsn, zdsn, ixMatparKo);
		};
	} else {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparK);
	};

	return(4.0*pi/lam0 * n*k/(n*n+k*k));
};

/******************************************************************************
 class PlnrMeep::ZcsboxrastMeep
 ******************************************************************************/

PlnrMeep::ZcsboxrastMeep::ZcsboxrastMeep(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefDomain
			, const double lam0
			, const bool anisomat
			, const bool lossmat
		) : Cubrast(dbsplnr, acvpath, env, refBasedsn, refModdsn, refPlnrMFile, "phot;phot;phot;phot;phot;phot", "n;k;no;ne;ko;ke"), material_function() {

	unsigned int ixDom =	domics[srefDomain];

	a11 = domA11[ixDom];
	a21 = domA21[ixDom];

	b1 = domB1[ixDom];
	b2 = domB2[ixDom];
	b3 = domB3[ixDom];

	xyoff = 0.5*(domXy1[ixDom]-domXy0[ixDom]);
	zoff = 0.5*(domZ1[ixDom]-domZ0[ixDom]);

	this->lam0 = lam0;

	this->anisomat = anisomat;
	this->lossmat = lossmat;

	if (anisomat) {
		// fix cases in which n/k are present but not no/ne/ko/ke
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparN] != 0.0) && (matpars[i*matparN + ixMatparNo] == 0.0) && (matpars[i*matparN + ixMatparNe] == 0.0)) {
				matpars[i*matparN + ixMatparNo] = matpars[i*matparN + ixMatparN];
				matpars[i*matparN + ixMatparNe] = matpars[i*matparN + ixMatparN];
			};
			if ((matpars[i*matparN + ixMatparK] != 0.0) && (matpars[i*matparN + ixMatparKo] == 0.0) && (matpars[i*matparN + ixMatparKe] == 0.0)) {
				matpars[i*matparN + ixMatparKo] = matpars[i*matparN + ixMatparK];
				matpars[i*matparN + ixMatparKe] = matpars[i*matparN + ixMatparK];
			};
		};

	} else {
		// fix cases in which no/ko are present but not n/k
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparNo] != 0.0) && (matpars[i*matparN + ixMatparN] == 0.0)) matpars[i*matparN + ixMatparN] = matpars[i*matparN + ixMatparNo];
			if ((matpars[i*matparN + ixMatparNe] != 0.0) && (matpars[i*matparN + ixMatparK] == 0.0)) matpars[i*matparN + ixMatparK] = matpars[i*matparN + ixMatparNe];
		};
	};

///
	PlnrAMMaterialPar* mpa = NULL;

	string dispmod;

	double epsLinf;

	vector<double> omgs;
	vector<double> gams;
	vector<double> sigs;

	complex<double> epsc, epsc0;

	double omg0, gam0, sig0;
	double omg1, gam1, sig1;

	ostringstream str;

	bool success;

	// - set up dispersion models that involve polarizability
	for (unsigned int i=0;i<mats.size();i++) {
		dispmod = "nk";

		if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, "phot", "dispmod", &mpa)) {
			dispmod = mpa->Val;
			delete mpa;
		};

		if (dispmod.compare("nk") != 0) {
			epsLinf = 1.0;

			omgs.resize(0);
			gams.resize(0);
			sigs.resize(0);

			if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, "phot", "epsLinf", &mpa)) {
				epsLinf = atof(mpa->Val.c_str());
				delete mpa;
			};

			for (unsigned int j=0;true;j++) {
				str.str(""); str << "omgL" << j;
				if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, "phot", str.str(), &mpa)) {
					omgs.push_back(atof(mpa->Val.c_str()));
					delete mpa;

					str.str(""); str << "GamL" << j;
					if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, "phot", str.str(), &mpa)) {
						gams.push_back(atof(mpa->Val.c_str()));
						delete mpa;
					} else gams.push_back(omgs[omgs.size()-1]);

					str.str(""); str << "sigL" << j;
					if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, "phot", str.str(), &mpa)) {
						sigs.push_back(atof(mpa->Val.c_str()));
						delete mpa;
					} else sigs.push_back(0.0);

				} else {
					break;
				};
			};

			cout << "material with ref=" << mats[i] << ": found " << omgs.size() << " Lorentzian resonances" << endl;

			// evaluate complex epsilon at lam0
			epsc = epscLrtz(epsLinf, omgs, gams, sigs, lam0);
			cout << "complex epsilon: " << epsc << endl;

			// override classical n and k such that n*n = real(epsc) (important for calls to eps(), chi1p1(), eff_chi1inv_row())
			if (epsc.real() < 0.0) {
				matpars[i*matparN + ixMatparN] = -sqrt(-epsc.real()); matpars[i*matparN + ixMatparNo] = -sqrt(-epsc.real()); matpars[i*matparN + ixMatparNe] = -sqrt(-epsc.real());
			} else {
				matpars[i*matparN + ixMatparN] = sqrt(epsc.real()); matpars[i*matparN + ixMatparNo] = sqrt(epsc.real()); matpars[i*matparN + ixMatparNe] = sqrt(epsc.real());
			};
			matpars[i*matparN + ixMatparK] = 0.0; matpars[i*matparN + ixMatparKo] = 0.0; matpars[i*matparN + ixMatparKe] = 0.0;

			if (dispmod.compare("lrtz") == 0) {
				// model comprising all Lorentz contributions
				for (unsigned int j=0;j<omgs.size();j++) {
					dispOmgs.push_back(omgs[j]);
					dispGams.push_back(gams[j]);
					dispSigs.push_back(sigs[j]);
					icsDispMats.push_back(i);
				};

			} else if (dispmod.compare("lrtzipl") == 0) {
				// model using zeroth Lorentz term (= Drude contribution for metals) and an interpolated term at lam0
/// DEBUG
//				if (omgs.size() == 1) {
				if (omgs.size() >= 1) {
					dispOmgs.push_back(omgs[0]);
					dispGams.push_back(gams[0]);
					dispSigs.push_back(sigs[0]);
					icsDispMats.push_back(i);

				} else if (omgs.size() > 1) {

					// fit with two resonances
					omg0 = omgs[0];
					gam0 = gams[0];
					sig0 = sigs[0];

					omg1 = 1.0/lam0;
					gam1 = omg1/10.0;
					sig1 = 1.0;

					// vary omg0 until real part of epsc matches
					success = zeroReEpscLrtz(epsLinf, omg0, gam0, sig0, lam0, epsc.real(), 1.0e-6, &omg0);
					if (!success) {
						cout << "error fitting real part of epsc" << endl;

					} else {
						// vary gam1 until imaginary part of epsc matches
						epsc0 = epscLrtz0(epsLinf, omg0, gam0, sig0, lam0);
						success = zeroImEpscLrtz(epsc0.imag(), omg1, gam1, sig1, lam0, epsc.imag(), 1.0e-6, &gam1);
						if (!success) {
							cout << "error fitting imaginary part of epsc" << endl;
						} else {
							dispOmgs.push_back(omg0);
							dispGams.push_back(gam0);
							dispSigs.push_back(sig0);
							icsDispMats.push_back(i);

							dispOmgs.push_back(omg1);
							dispGams.push_back(gam1);
							dispSigs.push_back(sig1);
							icsDispMats.push_back(i);
						};
					};
				};
			};
		};
	};
///
};

PlnrMeep::ZcsboxrastMeep::~ZcsboxrastMeep() {
};

void PlnrMeep::ZcsboxrastMeep::dsnToMeep(
			const double xdsn
			, const double ydsn
			, const double zdsn
			, double& x
			, double& y
		) {
	if (a11 != 0.0) x = (xdsn-b1)/a11 + xyoff;
	else x = (ydsn-b2)/a21 + xyoff;

	y = zdsn-b3 + zoff;
};

double PlnrMeep::ZcsboxrastMeep::getMaxN() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparNo] > retval) retval = matpars[i*matparN + ixMatparNo];
			if (matpars[i*matparN + ixMatparNe] > retval) retval = matpars[i*matparN + ixMatparNe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparN] > retval) retval = matpars[i*matparN + ixMatparN];
		};
	};

	return retval;
};

double PlnrMeep::ZcsboxrastMeep::getMaxK() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparKo] > retval) retval = matpars[i*matparN + ixMatparKo];
			if (matpars[i*matparN + ixMatparKe] > retval) retval = matpars[i*matparN + ixMatparKe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparK] > retval) retval = matpars[i*matparN + ixMatparK];
		};
	};

	return retval;
};

double PlnrMeep::ZcsboxrastMeep::chi1p1(
			field_type ft
			, const vec& r
		) {
	if (ft == E_stuff) return eps(r);
	else return 0.0;
};

double PlnrMeep::ZcsboxrastMeep::eps(
			const vec& r
		) {
	double xdsn, ydsn, zdsn;
	double n, k;

	xdsn = a11*(r.x()-xyoff) + b1;
	ydsn = a21*(r.x()-xyoff) + b2;
	zdsn = (r.y()-zoff) + b3;

	// anisotropy: to be implemented yet
	if (anisomat) {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparNo);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparKo);
	} else {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparK);
	};

	// previously:
	// return(n*n);

	return(n*n-k*k);
};

double PlnrMeep::ZcsboxrastMeep::conductivity(
			component c
			, const vec& r
		) {
	if (!lossmat) return 0.0;

	double xdsn, ydsn, zdsn;
	double n, k;

	xdsn = a11*(r.x()-xyoff) + b1;
	ydsn = a21*(r.x()-xyoff) + b2;
	zdsn = (r.y()-zoff) + b3;

	if (anisomat) {
		if ((c == Dy) || (c == By)) {
			n = getMatpar(xdsn, ydsn, zdsn, ixMatparNe);
			k = getMatpar(xdsn, ydsn, zdsn, ixMatparKe);
		} else {
			n = getMatpar(xdsn, ydsn, zdsn, ixMatparNo);
			k = getMatpar(xdsn, ydsn, zdsn, ixMatparKo);
		};
	} else {
		n = getMatpar(xdsn, ydsn, zdsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, zdsn, ixMatparK);
	};

	// previously:
	// return(4.0*pi/lam0 * n*k/(n*n+k*k));

	// http://ab-initio.mit.edu/wiki/index.php/Materials_in_Meep
	// sig = omega * Im(eps)/Re(eps)
	return(2.0*pi/lam0 * (2.0*n*k)/(n*n-k*k));
};

/*
void PlnrMeep::ZcsboxrastMeep::eff_chi1inv_row(
			component c
			, double chi1inv_row[3]
			, const volume &v
			, double tol
			, int maxeval
		) {
if (!didChi1inv) {
	cout << "now in eff_chi1inv_row() of main" << endl;
	didChi1inv = true;
};
	// initialize with default
	chi1inv_row[0] = 0.0;
	chi1inv_row[1] = 0.0;
	chi1inv_row[2] = 0.0;

	if (component_direction(c) == X) {
		chi1inv_row[0] = 1.0;
	} else if (component_direction(c) == Y) {
		chi1inv_row[1] = 1.0;
	} else if (component_direction(c) == Z) {
		chi1inv_row[2] = 1.0;
	};
};
*/

/******************************************************************************
 class PlnrMeep::ZcsboxrastMeep_susc
 ******************************************************************************/

PlnrMeep::ZcsboxrastMeep_susc::ZcsboxrastMeep_susc(
			ZcsboxrastMeep* rast
			, unsigned int ixOmgGam
		) {
	this->rast = rast;

	// copy linear transform parameters to increase speed of sigma_row()
	a11 = rast->a11;
	a21 = rast->a21;

	b1 = rast->b1;
	b2 = rast->b2;
	b3 = rast->b3;

	xyoff = rast->xyoff;
	zoff = rast->zoff;

	dispSig = rast->dispSigs[ixOmgGam];
	ixDispMat = rast->icsDispMats[ixOmgGam];

cout << "dispSig = " << dispSig << ", ixDispMat = " << ixDispMat << endl;

didDxBx = false; didDyBy = false; didDzBz = false; didOther = false;
};

void PlnrMeep::ZcsboxrastMeep_susc::sigma_row(
			component c
			, double sigrow[3]
			, const vec &r
		) {
	double xdsn, ydsn, zdsn;

	// initialize with default
	sigrow[0] = 0.0;
	sigrow[1] = 0.0;
	sigrow[2] = 0.0;

	// check if within material with associated polarizability
	xdsn = a11*(r.x()-xyoff) + b1;
	ydsn = a21*(r.x()-xyoff) + b2;
	zdsn = (r.y()-zoff) + b3;

	if (rast->getIxMat(xdsn, ydsn, zdsn) == ixDispMat) {
		if (component_direction(c) == X) {
			sigrow[0] = dispSig;
if (!didDxBx) {
	cout << "DxBx: " << c << endl;
	didDxBx = true;
};
		} else if (component_direction(c) == Y) {
			sigrow[1] = dispSig;
if (!didDyBy) {
	cout << "DyBy: " << c << endl;
	didDyBy = true;
};
		} else if (component_direction(c) == Z) {
			sigrow[2] = dispSig;
if (!didDzBz) {
	cout << "DzBz: " << c << endl;
	didDzBz = true;
};
		};

/*
		// isotropic
		if (c == Ex) {
			sigrow[0] = dispSig;
if (!didDxBx) {
	cout << "DxBx: " << c << endl;
	didDxBx = true;
};
		} else if (c == Ey) {
			sigrow[1] = dispSig;
if (!didDyBy) {
	cout << "DyBy: " << c << endl;
	didDyBy = true;
};
		} else if (c == Ez) {
			sigrow[2] = dispSig;
if (!didDzBz) {
	cout << "DzBz: " << c << endl;
	didDzBz = true;
};
		} else {
if (!didOther) {
	cout << "other component: " << c << endl;
	didOther = true;
};
		};
*/
	};
};
///

/******************************************************************************
 class PlnrMeep::XyboxrastMeep
 ******************************************************************************/

PlnrMeep::XyboxrastMeep::XyboxrastMeep(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefDomain
			, const double lam0
			, const bool anisomat
			, const bool lossmat
		) : Xyboxrast(dbsplnr, acvpath, env, refBasedsn, refModdsn, refPlnrMFile, "phot;phot;phot;phot;phot;phot", "n;k;no;ne;ko;ke"), material_function() {

	unsigned int ixDom =	domics[srefDomain];

	a11 = domA11[ixDom];
	a21 = domA21[ixDom];

	b1 = domB1[ixDom];
	b2 = domB2[ixDom];

	xoff = 0.5*(domX1[ixDom]-domX0[ixDom]);
	yoff = 0.5*(domY1[ixDom]-domY0[ixDom]);

	this->lam0 = lam0;

	this->anisomat = anisomat;
	this->lossmat = lossmat;

	if (anisomat) {
		// fix cases in which n/k are present but not no/ne/ko/ke
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparN] != 0.0) && (matpars[i*matparN + ixMatparNo] == 0.0) && (matpars[i*matparN + ixMatparNe] == 0.0)) {
				matpars[i*matparN + ixMatparNo] = matpars[i*matparN + ixMatparN];
				matpars[i*matparN + ixMatparNe] = matpars[i*matparN + ixMatparN];
			};
			if ((matpars[i*matparN + ixMatparK] != 0.0) && (matpars[i*matparN + ixMatparKo] == 0.0) && (matpars[i*matparN + ixMatparKe] == 0.0)) {
				matpars[i*matparN + ixMatparKo] = matpars[i*matparN + ixMatparK];
				matpars[i*matparN + ixMatparKe] = matpars[i*matparN + ixMatparK];
			};
		};

	} else {
		// fix cases in which no/ko are present but not n/k
		for (unsigned int i=0;i<mats.size();i++) {
			if ((matpars[i*matparN + ixMatparNo] != 0.0) && (matpars[i*matparN + ixMatparN] == 0.0)) matpars[i*matparN + ixMatparN] = matpars[i*matparN + ixMatparNo];
			if ((matpars[i*matparN + ixMatparNe] != 0.0) && (matpars[i*matparN + ixMatparK] == 0.0)) matpars[i*matparN + ixMatparK] = matpars[i*matparN + ixMatparNe];
		};
	};
};

PlnrMeep::XyboxrastMeep::~XyboxrastMeep() {
};

void PlnrMeep::XyboxrastMeep::dsnToMeep(
			const double xdsn
			, const double ydsn
			, double& x
			, double& y
		) {
	x = a11*(xdsn-b1) + a21*(ydsn-b2) + xoff;
	y = -a21*(xdsn-b1) + a11*(ydsn-b2) + yoff;
};

double PlnrMeep::XyboxrastMeep::getMaxN() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparNo] > retval) retval = matpars[i*matparN + ixMatparNo];
			if (matpars[i*matparN + ixMatparNe] > retval) retval = matpars[i*matparN + ixMatparNe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparN] > retval) retval = matpars[i*matparN + ixMatparN];
		};
	};

	return retval;
};

double PlnrMeep::XyboxrastMeep::getMaxK() {
	double retval = 0.0;

	if (anisomat) {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparKo] > retval) retval = matpars[i*matparN + ixMatparKo];
			if (matpars[i*matparN + ixMatparKe] > retval) retval = matpars[i*matparN + ixMatparKe];
		};
	} else {
		for (unsigned int i=0;i<mats.size();i++) {
			if (matpars[i*matparN + ixMatparK] > retval) retval = matpars[i*matparN + ixMatparK];
		};
	};

	return retval;
};

double PlnrMeep::XyboxrastMeep::chi1p1(
			field_type ft
			, const vec& r
		) {
	if (ft == E_stuff) return eps(r);
	else return 0.0;
};

double PlnrMeep::XyboxrastMeep::eps(
			const vec& r
		) {
	double xdsn, ydsn;
	double n, k;

	xdsn = a11*(r.x()-xoff) - a21*(r.y()-yoff) + b1;
	ydsn = a21*(r.x()-xoff) + a11*(r.y()-yoff) + b2;

	// anisotropy: to be implemented yet
	if (anisomat) {
		n = getMatpar(xdsn, ydsn, ixMatparNo);
		k = getMatpar(xdsn, ydsn, ixMatparKo);
	} else {
		n = getMatpar(xdsn, ydsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, ixMatparK);
	};

	return(n*n-k*k);
};

double PlnrMeep::XyboxrastMeep::conductivity(
			component c
			, const vec& r
		) {
	if (!lossmat) return 0.0;

	double xdsn, ydsn;
	double n, k;

	xdsn = a11*(r.x()-xoff) - a21*(r.y()-yoff) + b1;
	ydsn = a21*(r.x()-xoff) + a11*(r.y()-yoff) + b2;

	if (anisomat) {
		if ((c == Dz) || (c == Bz)) {
			n = getMatpar(xdsn, ydsn, ixMatparNe);
			k = getMatpar(xdsn, ydsn, ixMatparKe);
		} else {
			n = getMatpar(xdsn, ydsn, ixMatparNo);
			k = getMatpar(xdsn, ydsn, ixMatparKo);
		};
	} else {
		n = getMatpar(xdsn, ydsn, ixMatparN);
		k = getMatpar(xdsn, ydsn, ixMatparK);
	};

	return(4.0*pi/lam0 * n*k/(n*n+k*k));
};
// IP cust --- IEND


