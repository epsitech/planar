/**
  * \file CrdPlnrTpo_evals.cpp
  * job handler for job CrdPlnrTpo (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool CrdPlnrTpo::evalMspCrd1Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdUcsAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUcsAvail(dbsplnr);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrTpo::evalMitCrdUcsAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpoIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};


