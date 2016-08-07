/**
  * \file DlgPlnrNavLoaini_evals.cpp
  * job handler for job DlgPlnrNavLoaini (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool DlgPlnrNavLoaini::evalIfiUldActive(
			DbsPlnr* dbsplnr
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalImpButRunActive(
			DbsPlnr* dbsplnr
		) {
	// sge(prsdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::PRSDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalImpButStoActive(
			DbsPlnr* dbsplnr
		) {
	// sge(impidle|import)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IMPIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::IMPORT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalAcvUldActive(
			DbsPlnr* dbsplnr
		) {
	// sge(impdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IMPDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalPprButRunActive(
			DbsPlnr* dbsplnr
		) {
	// sge(upkdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalPprButStoActive(
			DbsPlnr* dbsplnr
		) {
	// sge(postprc)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::POSTPRC);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalLfiDldActive(
			DbsPlnr* dbsplnr
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrNavLoaini::evalButDneActive(
			DbsPlnr* dbsplnr
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};


