/**
  * \file PlnrWgmodeFd1d.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRWGMODEFD1D_H
#define PLNRWGMODEFD1D_H

#include "PlnrWgmode.h"

using namespace PlnrWgmode;

// IP incl --- INSERT

namespace PlnrWgmodeFd1d {

	DpchRetPlnrWgmodeFd1d* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFd1d* dpchinv);
// IP cust --- IBEGIN
	void calcNolossmat(const vector<double>& n, const double lam, const double dz, const bool te, const bool tm, unsigned int& NTE, vector<double>& ixeffTE, vector<double>& EyTE, vector<double>& HzTE, unsigned int& NTM, vector<double>& ixeffTM, vector<double>& EzTM, vector<double>& HyTM);
	void calcLossmat(const vector<double>& n, const vector<double>& k, const double lam, const double dz, const bool te, const bool tm, unsigned int& NTE, vector<complex<double> >& ixeffTE, vector<complex<double> >& EyTE, vector<complex<double> >& HzTE, unsigned int& NTM, vector<complex<double> >& ixeffTM, vector<complex<double> >& EzTM, vector<complex<double> >& HyTM);
// IP cust --- IEND
};

#endif


