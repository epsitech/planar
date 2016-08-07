/**
  * \file SqkPlnrWgmode.h
  * squawk generation for operation pack PlnrWgmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SQKPLNRWGMODE_H
#define SQKPLNRWGMODE_H

#include "PlnrWgmode_blks.h"

/**
  * SqkPlnrWgmode
  */
namespace SqkPlnrWgmode {
	string getSquawkFd1d(DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFd1d* dpchinv);
	string getSquawkFd2d(DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFd2d* dpchinv);
	string getSquawkFem1d(DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFem1d* dpchinv);
	string getSquawkFem2d(DbsPlnr* dbsplnr, DpchInvPlnrWgmodeFem2d* dpchinv);
};

#endif


