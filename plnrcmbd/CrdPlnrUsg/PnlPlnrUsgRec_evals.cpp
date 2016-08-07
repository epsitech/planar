/**
  * \file PnlPlnrUsgRec_evals.cpp
  * job handler for job PnlPlnrUsgRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrUsgRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};


