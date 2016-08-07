/**
  * \file PnlPlnrDgdRec_evals.cpp
  * job handler for job PnlPlnrDgdRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDgdRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDgd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDGD, jref) != 0);
	args.push_back(a);

	return(args.back());
};


