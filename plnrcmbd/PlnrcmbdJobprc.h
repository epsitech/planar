/**
  * \file PlnrcmbdJobprc.h
  * job processor for Plnr combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRCMBDJOBPRC_H
#define PLNRCMBDJOBPRC_H

/**
  * PlnrcmbdJobprc
  */
namespace PlnrcmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgPlnrcmbd* xchg, DbsPlnr* dbsplnr, ReqPlnr* req);
};

#endif


