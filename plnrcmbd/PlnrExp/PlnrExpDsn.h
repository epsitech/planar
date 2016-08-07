/**
  * \file PlnrExpDsn.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPDSN_H
#define PLNREXPDSN_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- INSERT

namespace PlnrExpDsn {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpDsn* dpchinv);
// IP cust --- IBEGIN
	void charLgd(DbsPlnr* dbsplnr, const ubigint refPlnrMLineguide, const bool nolrv, ListPlnrLRMLineguideMVertex& lrvs, vector<unsigned int>& lgvtxics, vector<double>& lgvtxlams, double& x0, double& y0, double& dx, double& dy, double& lam1, const ListPlnrMVertex& vtxs, map<ubigint, unsigned int>& dsnvtxics);
	void charAgd(DbsPlnr* dbsplnr, const PlnrMArcguide* ag, const bool noarv, ListPlnrLRMArcguideMVertex& arvs, vector<unsigned int>& agvtxics, vector<double>& agvtxlams, double& x0, double& y0, double& lam1, const ListPlnrMVertex& vtxs, map<ubigint, unsigned int>& dsnvtxics);
// IP cust --- IEND
};

#endif


