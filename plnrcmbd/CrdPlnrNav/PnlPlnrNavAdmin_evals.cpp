/**
  * \file PnlPlnrNavAdmin_evals.cpp
  * job handler for job PnlPlnrNavAdmin (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavAdmin::evalLstUsgAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalButUsgViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalLstUsrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalButUsrViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalLstPrsAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalButPrsViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalLstFilAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavAdmin::evalButFilViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};


