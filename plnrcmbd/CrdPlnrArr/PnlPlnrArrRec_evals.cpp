/**
  * \file PnlPlnrArrRec_evals.cpp
  * job handler for job PnlPlnrArrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrArrRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refArr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFARR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


