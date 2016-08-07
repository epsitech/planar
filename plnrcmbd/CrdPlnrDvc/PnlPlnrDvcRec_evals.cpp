/**
  * \file PnlPlnrDvcRec_evals.cpp
  * job handler for job PnlPlnrDvcRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDvcRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDvc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref) != 0);
	args.push_back(a);

	return(args.back());
};


