/**
  * \file DlgPlnrTpoUsecase_evals.cpp
  * job handler for job DlgPlnrTpoUsecase (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool DlgPlnrTpoUsecase::evalPrpButCreActive(
			DbsPlnr* dbsplnr
		) {
	// sge(idle)&valid()

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = valid;
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool DlgPlnrTpoUsecase::evalGenButRunActive(
			DbsPlnr* dbsplnr
		) {
	// sge(credone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrTpoUsecase::evalGenButStoActive(
			DbsPlnr* dbsplnr
		) {
	// sge(run)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::RUN);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrTpoUsecase::evalCfiDldActive(
			DbsPlnr* dbsplnr
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgPlnrTpoUsecase::evalButDneActive(
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


