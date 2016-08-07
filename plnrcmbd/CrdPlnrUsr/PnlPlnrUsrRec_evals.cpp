/**
  * \file PnlPlnrUsrRec_evals.cpp
  * job handler for job PnlPlnrUsrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrUsrRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


