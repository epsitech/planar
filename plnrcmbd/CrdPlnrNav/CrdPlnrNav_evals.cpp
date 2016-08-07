/**
  * \file CrdPlnrNav_evals.cpp
  * job handler for job CrdPlnrNav (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool CrdPlnrNav::evalPnlpreAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()|pre.refPrj()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalPnladminAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsg()|pre.ixUacUsr()|pre.ixUacPrs()|pre.ixUacFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalPnlglobalAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDtp()|pre.ixUacCtp()|pre.ixUacMat()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalPnldesignAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()|pre.ixUacDsn()|pre.ixUacDom()|pre.ixUacDgd()|pre.ixUacDvc()|pre.ixUacSru()|pre.ixUacStk()|pre.ixUacLyr()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalPnlcalcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClc()|pre.ixUacCli()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalPnllayoutAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpo()|pre.ixUacArr()|pre.ixUacAri()|pre.ixUacRtc()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARI, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACRTC, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalMspCrd1Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbsplnr);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdUsgAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdUsrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdPrsAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdFilAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMspCrd2Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdDtpAvail()|MitCrdCtpAvail()|MitCrdMatAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdDtpAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdCtpAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdMatAvail(dbsplnr);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdCtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdMatAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMspCrd3Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdPrjAvail()|MitCrdDsnAvail()|MitCrdDomAvail()|MitCrdDgdAvail()|MitCrdDvcAvail()|MitCrdSruAvail()|MitCrdStkAvail()|MitCrdLyrAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPrjAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdDsnAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdDomAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdDgdAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdDvcAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdSruAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdStkAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdLyrAvail(dbsplnr);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdPrjAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDsnAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDomAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDom()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDomActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDgdAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDgd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDgdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDvcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDvc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdDvcActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdSruAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacSru()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdSruActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdStkAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacStk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdStkActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdLyrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdLyrActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMspCrd4Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdClcAvail()|MitCrdCliAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdClcAvail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMitCrdCliAvail(dbsplnr);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdClcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdClcActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdCliAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCli()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdCliActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMspCrd5Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdTpoAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdTpoAvail(dbsplnr);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitCrdTpoAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpo()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMspApp2Avail(
			DbsPlnr* dbsplnr
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbsplnr);
	args.push_back(a);

	return(args.back());
};

bool CrdPlnrNav::evalMitAppLoiAvail(
			DbsPlnr* dbsplnr
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {ubigint cnt = 0; dbsplnr->loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};


