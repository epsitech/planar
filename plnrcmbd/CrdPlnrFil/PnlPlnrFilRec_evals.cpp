/**
  * \file PnlPlnrFilRec_evals.cpp
  * job handler for job PnlPlnrFilRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrFilRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};


