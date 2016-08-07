/**
  * \file PlnrdJobprc.h
  * job processor for Plnr daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRDJOBPRC_H
#define PLNRDJOBPRC_H

/**
  * PlnrdJobprc
  */
namespace PlnrdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgPlnrd* xchg, DbsPlnr* dbsplnr, ReqPlnr* req);
};

#endif


