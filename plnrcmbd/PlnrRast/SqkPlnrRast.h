/**
  * \file SqkPlnrRast.h
  * squawk generation for operation pack PlnrRast (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SQKPLNRRAST_H
#define SQKPLNRRAST_H

#include "PlnrRast_blks.h"

/**
  * SqkPlnrRast
  */
namespace SqkPlnrRast {
	string getSquawkCub(DbsPlnr* dbsplnr, DpchInvPlnrRastCub* dpchinv);
	string getSquawkXybox(DbsPlnr* dbsplnr, DpchInvPlnrRastXybox* dpchinv);
	string getSquawkZline(DbsPlnr* dbsplnr, DpchInvPlnrRastZline* dpchinv);
};

#endif


