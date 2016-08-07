/**
  * \file PnlPlnrClcRec_evals.cpp
  * job handler for job PnlPlnrClcRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrClcRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};


