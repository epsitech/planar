/**
  * \file PnlPlnrNavHeadbar_evals.cpp
  * job handler for job PnlPlnrNavHeadbar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavHeadbar::evalMenCrdAvail(
			DbsPlnr* dbsplnr
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()|MspCrd4Avail()|MspCrd5Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMspCrd4Avail(dbsplnr);
	args.push_back(a);
	a = false; a = evalMspCrd5Avail(dbsplnr);
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

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMspCrd1Avail(
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

bool PnlPlnrNavHeadbar::evalMitCrdUsgAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdUsrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdPrsAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdFilAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMspCrd2Avail(
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

bool PnlPlnrNavHeadbar::evalMitCrdDtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdCtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdMatAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMspCrd3Avail(
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

bool PnlPlnrNavHeadbar::evalMitCrdPrjAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdDsnAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdDomAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDom()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdDgdAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDgd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdDvcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDvc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdSruAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacSru()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdStkAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacStk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdLyrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMspCrd4Avail(
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

bool PnlPlnrNavHeadbar::evalMitCrdClcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdCliAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCli()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMspCrd5Avail(
			DbsPlnr* dbsplnr
		) {
	// MitCrdTpoAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdTpoAvail(dbsplnr);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavHeadbar::evalMitCrdTpoAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpo()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) != 0);
	args.push_back(a);

	return(args.back());
};


