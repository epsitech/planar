/**
  * \file PnlPlnrFilDetail_evals.cpp
  * job handler for job PnlPlnrFilDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrFilDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFilIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButCluViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButCluClusterAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFilIncl(edit) & fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);
	a = false; xchg->triggerRefToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRFIL_CLUEQ, jref, 0, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButCluUnclusterAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFilIncl(edit) & !fil.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);
	a = false; xchg->triggerRefToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRFIL_CLUEQ, jref, 0, a);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButCntEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecPlnrVPreset::PREPLNRADM, jref));
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrFilDetail::evalButMimEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getBoolvalPreset(VecPlnrVPreset::PREPLNRADM, jref));
	args.push_back(a);

	return(args.back());
};


