/**
  * \file PlnrdOpengcli.h
  * operation engine client for Plnr daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDOPENGCLI_H
#define PLNRDOPENGCLI_H

#include "Plnrd.h"

/**
  * PlnrdOpengcli
  */
namespace PlnrdOpengcli {
	void* run(void* arg);
	void cleanup(void* arg);
};

/**
  * PlnrdOpengcli_argsub
  */
struct PlnrdOpengcli_argsub {
	XchgPlnrd* xchg;
	NodePlnr* node;
	DpchInvPlnr* inv;
};

/**
  * PlnrdOpengcli_sub
  */
namespace PlnrdOpengcli_sub {
	void* run(void* _arg);

	uint CurlPostrecv(void* data, uint size, uint blocksize, void* _ret);

	uint readDpchRet(XchgPlnrd* xchg, ReqPlnr* req);
	void writeDpchInv(XchgPlnrd* xchg, ReqPlnr* req);
};

#endif


