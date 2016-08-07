/**
  * \file PnlPlnrPrjRec_evals.cpp
  * job handler for job PnlPlnrPrjRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrPrjRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


