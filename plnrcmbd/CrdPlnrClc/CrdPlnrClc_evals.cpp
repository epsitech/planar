/**
  * \file CrdPlnrClc_evals.cpp
  * job handler for job CrdPlnrClc (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool CrdPlnrClc::evalMspCrd1Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdUcsAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUcsAvail(dbsplnr);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrClc::evalMitCrdUcsAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClcIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrClc::evalMitCrdGpvAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClcIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrClc::evalMitCrdGpvActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrClc::evalMitCrdEtxAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClcIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrClc::evalMitCrdEtxActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};


