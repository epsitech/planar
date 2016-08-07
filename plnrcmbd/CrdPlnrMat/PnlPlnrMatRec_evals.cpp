/**
  * \file PnlPlnrMatRec_evals.cpp
  * job handler for job PnlPlnrMatRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrMatRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};


