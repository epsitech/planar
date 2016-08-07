/**
  * \file PnlPlnrTpoRec_evals.cpp
  * job handler for job PnlPlnrTpoRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrTpoRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refTpo()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref) != 0);
	args.push_back(a);

	return(args.back());
};


