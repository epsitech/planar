/**
  * \file PnlPlnrDtpRec_evals.cpp
  * job handler for job PnlPlnrDtpRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDtpRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};


