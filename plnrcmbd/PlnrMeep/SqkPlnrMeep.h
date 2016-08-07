/**
  * \file SqkPlnrMeep.h
  * squawk generation for operation pack PlnrMeep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SQKPLNRMEEP_H
#define SQKPLNRMEEP_H

#include "PlnrMeep_blks.h"

/**
  * SqkPlnrMeep
  */
namespace SqkPlnrMeep {
	string getSquawkTrf2d(DbsPlnr* dbsplnr, DpchInvPlnrMeepTrf2d* dpchinv);
	string getSquawkTrf3d(DbsPlnr* dbsplnr, DpchInvPlnrMeepTrf3d* dpchinv);
};

#endif


