/**
  * \file CrdPlnrFil_evals.cpp
  * job handler for job CrdPlnrFil (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool CrdPlnrFil::evalMitCrdDcyActive(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFilIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) & VecPlnrWUiaccess::EXEC);
	args.push_back(a);

	return(args.back());
};


