/**
  * \file PnlPlnrDomRec_evals.cpp
  * job handler for job PnlPlnrDomRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDomRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDom()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDOM, jref) != 0);
	args.push_back(a);

	return(args.back());
};


