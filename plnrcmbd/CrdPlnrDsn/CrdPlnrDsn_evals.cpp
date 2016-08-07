/**
  * \file CrdPlnrDsn_evals.cpp
  * job handler for job CrdPlnrDsn (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool CrdPlnrDsn::evalMitCrdGplAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsnIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrDsn::evalMitCrdGplActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


