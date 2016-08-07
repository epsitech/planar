/**
  * \file PnlPlnrPrsRec_evals.cpp
  * job handler for job PnlPlnrPrsRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrPrsRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};


