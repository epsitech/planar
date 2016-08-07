/**
  * \file PnlPlnrStkRec_evals.cpp
  * job handler for job PnlPlnrStkRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrStkRec::evalPnlmnstructureAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrStkRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refStk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref) != 0);
	args.push_back(a);

	return(args.back());
};


