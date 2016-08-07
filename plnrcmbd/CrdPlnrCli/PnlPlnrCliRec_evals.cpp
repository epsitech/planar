/**
  * \file PnlPlnrCliRec_evals.cpp
  * job handler for job PnlPlnrCliRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrCliRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refCli()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLI, jref) != 0);
	args.push_back(a);

	return(args.back());
};


