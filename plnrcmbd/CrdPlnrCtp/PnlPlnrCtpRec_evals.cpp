/**
  * \file PnlPlnrCtpRec_evals.cpp
  * job handler for job PnlPlnrCtpRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrCtpRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


