/**
  * \file PlnrExpImage.h
  * Plnr operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXPIMAGE_H
#define PLNREXPIMAGE_H

#include "PlnrExp.h"

using namespace PlnrExp;

// IP incl --- IBEGIN
#include <png.h>
// IP incl --- IEND

namespace PlnrExpImage {

	DpchRetPlnr* run(XchgPlnr* xchg, DbsPlnr* dbsplnr, DpchInvPlnrExpImage* dpchinv);
// IP cust --- IBEGIN
	const unsigned int _SRC = 1;
	const unsigned int _PIX = 2;
	const unsigned int _CD = 4;
	const unsigned int _INV = 8;

	void loadPng(DbsPlnr* dbsplnr, const string& acvpath, const ubigint src, const double pix, const double cd, const bool inv, int& rows, int& cols, vector<double>& ps);
	void vtxlgfces(DbsPlnr* dbsplnr, const ubigint x1RefPlnrMDesign, const ubigint refPlnrMDevice, const int rows, const int cols, const vector<double>& ps, const double pix, const double cd, const ubigint refSruAll);
// IP cust --- IEND
};

#endif


