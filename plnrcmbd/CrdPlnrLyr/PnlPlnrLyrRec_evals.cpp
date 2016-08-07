/**
  * \file PnlPlnrLyrRec_evals.cpp
  * job handler for job PnlPlnrLyrRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrLyrRec::evalPnl1nblockAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrLyrRec::evalPnl1nreticleAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.typEq(vrtlyr)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_TYPEQ, jref, VecPlnrVMDesignBasetype::VRTLYR, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrLyrRec::evalPnlmnstructureAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrLyrRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


