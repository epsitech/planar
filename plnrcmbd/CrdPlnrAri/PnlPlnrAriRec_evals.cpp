/**
  * \file PnlPlnrAriRec_evals.cpp
  * job handler for job PnlPlnrAriRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrAriRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refAri()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARI, jref) != 0);
	args.push_back(a);

	return(args.back());
};


