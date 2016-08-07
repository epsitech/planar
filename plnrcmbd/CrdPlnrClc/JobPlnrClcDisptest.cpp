/**
  * \file JobPlnrClcDisptest.cpp
  * job handler for job JobPlnrClcDisptest (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "JobPlnrClcDisptest.h"

// IP blksInclude --- BEGIN
#include "JobPlnrClcDisptest_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class JobPlnrClcDisptest
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
JobPlnrClcDisptest::JobPlnrClcDisptest(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::JOBPLNRCLCDISPTEST, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

// IP constructor.spec1 --- INSERT

// IP constructor.cust2 --- IBEGIN
	Plnr::getRefsDtp(dbsplnr, refsDtp);
// IP constructor.cust2 --- IEND

// IP constructor.spec2 --- INSERT

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

JobPlnrClcDisptest::~JobPlnrClcDisptest() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobPlnrClcDisptest::resetPars() {
	// - device geometry parameters
	mesa = 40.0;
	topmet = true;
	buf = true;
	tBuf = 1.0;
	tBotcont = 0.6;
	NPrd  = 15;
	tPrd = 0.06;
	tTopcont = 0.3;
	grattype = "half";
	gratprd = 4.4/3.0;
	tGrat = 0.3;

	// - material parameters
	matsys = "InP";
	kBotcont = 3.0e-3;
	nDBotcont = 1.5e18;
	kTopcont = 3.0e-3;
	nDTopcont = 1.5e18;
	xAR = 0.33;
	nDAR = 1.5e18;
	kAR = 3.0e-4;
	keAR = 3.0e-2;
	cladmat = "SiO2";
	tClad = 1.0;

	// - calculation parameters
	calctype = "fdtd";
	scantype = "lam";
	scanstart = 0.8*4.4;
	scanstep = 0.1*4.4;
	scanmult = 1.0;
	scanstop = 1.20001*4.4;
	grid = 0.05;
	lam = 4.4;
	anisomat = false;
	lossmat = true;

	// - waveguide mode calculation parameters
	te = true;
	tm = true;

	// - FDTD parameters
	illpos = "bottom";
	deltalam = 0.44;
	tstop = 10000.0;
	corn = true;
	mon = false;
	sshot = true;
	armon = true;
	arsshot = false;
	peeksshot = false;
	aspmon = true;
};
// IP cust --- IEND
// IP spec --- INSERT

// IP changeStage --- BEGIN
// IP changeStage.hdr --- BEGIN
void JobPlnrClcDisptest::changeStage(
			DbsPlnr* dbsplnr
			, uint _ixVSge
		) {
// IP changeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsplnr); break;
			case VecVSge::PRPIDLE: leaveSgePrpidle(dbsplnr); break;
			case VecVSge::PREPARE: leaveSgePrepare(dbsplnr); break;
			case VecVSge::EXPAND1: leaveSgeExpand1(dbsplnr); break;
			case VecVSge::EXPAND2: leaveSgeExpand2(dbsplnr); break;
			case VecVSge::EXPAND3: leaveSgeExpand3(dbsplnr); break;
			case VecVSge::DISCR: leaveSgeDiscr(dbsplnr); break;
			case VecVSge::CALC: leaveSgeCalc(dbsplnr); break;
			case VecVSge::PLOT: leaveSgePlot(dbsplnr); break;
			case VecVSge::DONE: leaveSgeDone(dbsplnr); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP changeStage.refresh --- IEND

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsplnr); break;
			case VecVSge::PRPIDLE: _ixVSge = enterSgePrpidle(dbsplnr); break;
			case VecVSge::PREPARE: _ixVSge = enterSgePrepare(dbsplnr); break;
			case VecVSge::EXPAND1: _ixVSge = enterSgeExpand1(dbsplnr); break;
			case VecVSge::EXPAND2: _ixVSge = enterSgeExpand2(dbsplnr); break;
			case VecVSge::EXPAND3: _ixVSge = enterSgeExpand3(dbsplnr); break;
			case VecVSge::DISCR: _ixVSge = enterSgeDiscr(dbsplnr); break;
			case VecVSge::CALC: _ixVSge = enterSgeCalc(dbsplnr); break;
			case VecVSge::PLOT: _ixVSge = enterSgePlot(dbsplnr); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsplnr); break;
		};
	};
};
// IP changeStage --- END

uint JobPlnrClcDisptest::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
// IP enterSgeIdle --- IEND
	return retval;
};

void JobPlnrClcDisptest::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint JobPlnrClcDisptest::enterSgePrpidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PRPIDLE;
	nextIxVSge = VecVSge::PREPARE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgePrpidle --- INSERT
	return retval;
};

void JobPlnrClcDisptest::leaveSgePrpidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgePrpidle --- INSERT
};

uint JobPlnrClcDisptest::enterSgePrepare(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PREPARE;
	nextIxVSge = VecVSge::EXPAND1;
// IP enterSgePrepare --- IBEGIN
	// -- general assumptions
	// fixed n for InP, InAlAs, InGaAs, Air
	// k=0 for InP, InAlAs, GaAs, AlGaAs, Air, YF3
	// fixed k for MgF2

	// -- parameters
	// - device geometry parameters
	// mesa (mesa size): 40.0, d
	// topmet (has top metallization): yes, b
	// buf (has buffer layer): yes, b
	// tBuf (buffer layer thickness): 1.0, d
	// tBotcont (bottom contact thickness): 0.6, d
	// NPrd (number of periods): 15, i
	// tPrd (period thickness): 0.06, d
	// tTopcont (top contact thickness): 0.3, d
	// grattype (grating type): none vs. _half_ vs. full, s
	// gratprd (grating period): 4.4/3.0, d
	// tGrat (etched grating thickness): 0.3, d
	// tClad (cladding layer thickness between grating and top contact): 1.0, d

	// - material parameters
	// matsys (material system): _InP_ vs. GaAs, s
	// kBotcont (bottom contact extinction coefficient): 3e-3, d
	// nDBotcont (bottom contact doping level): 1.5e18, d
	// kTopcont (top contact extinction coefficient): 3e-3, d
	// nDTopcont (top contact doping level): 1.5e18, d
	// xAR (active region well material content): 0.33, d
	// nDAR (main quantum well doping level): 1.5e18, d
	// kAR (active region absorption coefficient): 3e-4, d
	// keAR (active region extraordinary ray absorption coefficient): 3e-2, d
	// cladmat (cladding material): Air vs. _SiO2_ vs. Au vs. MgF2 vs. YF3, s

	// - calculation parameters
	// calctype (calculation type): wgmode1d vs. wgmode2d vs. fdtd, s
	// scantype (scan type): s
	//  lam: _lam_
	//  geo: mesa, tBuf, tBotcont, NPrd, tTopcont, gratprd, tGrat, grid
	//  mpa: kBotcont, kTopcont, kAR, keAR
	//  mat: cladmat
	// scanstart/step/mult/stop: d
	// grid (main discretization grid): 0.05, d
	// lam (free-space wavelength): 4.4, d
	// lossmat (lossy materials): yes, b
	// anisomat (anisotropic materials): no, b

	// - waveguide mode calculation parameters
	// te (calculate TE modes): yes, b
	// tm (calculate TM modes): yes, b

	// - FDTD parameters
	// illpos (illumination position): top vs. _bottom_, s
	// deltalam (wavelength FWHM): 0.44, d
	// tstop (stop time): 1000.0, d
	// corn (include corners): yes, b
	// mon (entire domain monitor): no, b
	// sshot (entire domain final snapshot): yes, b
	// armon (2D active region monitor): yes, b
	// arsshot (2D active region final snapshot): no, b
	// peeksshot (1D vertical final snapshot): no, b
	// aspmon (asymmetricaly placed point monitor): yes, b

	ostringstream str;
	string s;
	ubigint ref;

	ubigint refPro;

	uint ixWModtype;

	PlnrMDesign* dsn = NULL;

	ListPlnrMStack stks;

	ListPlnrMDevice devs;
	PlnrMDevice* dev = NULL;

	double n, t, w;

	PlnrMCalc* clc = NULL;

	PlnrMCalcitem* cli = NULL;
	ubigint refCli;
	uint clicnt = 1;

	PlnrMDesign* moddsn = NULL;

	ubigint refDomFdtd, refDomExc, refDomActreg, refDomWgmode;

	refPro = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref);

	// --- design
	ixWModtype = 0;
	if (scantype.compare("lam") == 0) ixWModtype |= VecPlnrWMDesignModtype::MVAR;
	if (scantype.compare("mesa") == 0) ixWModtype |= VecPlnrWMDesignModtype::DTO;
	if (scantype.compare("tBuf") == 0) ixWModtype |= VecPlnrWMDesignModtype::SNOLN;
	if (scantype.compare("tBotcont") == 0) ixWModtype |= VecPlnrWMDesignModtype::SNOLN;
	if (scantype.compare("NPrd") == 0) ixWModtype |= VecPlnrWMDesignModtype::SLN;
	if (scantype.compare("tTopcont") == 0) ixWModtype |= VecPlnrWMDesignModtype::SNOLN;
	if (scantype.compare("gratprd") == 0) ixWModtype |= VecPlnrWMDesignModtype::DTO;
	if (scantype.compare("tGrat") == 0) ixWModtype |= VecPlnrWMDesignModtype::SNOLN;
	if (scantype.compare("grid") == 0) ixWModtype |= VecPlnrWMDesignModtype::GRID;
	if (scantype.compare("kBotcont") == 0) ixWModtype |= VecPlnrWMDesignModtype::MVAR;
	if (scantype.compare("kTopcont") == 0) ixWModtype |= VecPlnrWMDesignModtype::MVAR;
	if (scantype.compare("kAR") == 0) ixWModtype |= VecPlnrWMDesignModtype::MVAR;
	if (scantype.compare("keAR") == 0) ixWModtype |= VecPlnrWMDesignModtype::MVAR;
	if (scantype.compare("cladmat") == 0) ixWModtype |= VecPlnrWMDesignModtype::MAT;

	refDsn = dbsplnr->tblplnrmdesign->insertNewRec(&dsn, 0, 0, VecPlnrVMDesignBasetype::TRLYR, VecPlnrVMDesignDim::XYZ, VecPlnrVMDesignRefTbl::CAL, 0, refPro,
				ixWModtype, 0, 0, "QCD photonic simulation", 0, 1, "");

	// --- materials
	ubigint refInP = Plnr::findMat(dbsplnr, "InP");
	ubigint refInAlAs45 = Plnr::findMat(dbsplnr, "InAlAs0.45"); // n = 3.134 (for 1-x)
	ubigint refInGaAs53B = Plnr::findMat(dbsplnr, "InGaAs0.53;InGaAs0.53B"); // n = 3.389 (for x)
	ubigint refInGaAs53C = Plnr::findMat(dbsplnr, "InGaAs0.53;InGaAs0.53C");
	ubigint refInGaAlAsAR = Plnr::findMat(dbsplnr, "InGaAlAsAR");

	ubigint refGaAs = Plnr::findMat(dbsplnr, "GaAs"); // n = 3.3 (for x)
	ubigint refGaAsB = Plnr::findMat(dbsplnr, "GaAs;GaAsB");
	ubigint refGaAsC = Plnr::findMat(dbsplnr, "GaAs;GaAsC");
	ubigint refAlGaAs42 = Plnr::findMat(dbsplnr, "AlGaAs0.42"); // n = 3.115 (for 1-x)
	ubigint refAlGaAsAR = Plnr::findMat(dbsplnr, "AlGaAsAR");

	ubigint refAu = Plnr::findMat(dbsplnr, "Au");

	ubigint refAir = Plnr::findMat(dbsplnr, "Air");
	ubigint refSiO2 = Plnr::findMat(dbsplnr, "SiO2");
	ubigint refMgF2 = Plnr::findMat(dbsplnr, "MgF2");
	ubigint refYF3 = Plnr::findMat(dbsplnr, "YF3");
	ubigint refZnSe = Plnr::findMat(dbsplnr, "ZnSe");

	ubigint refArlow = refSiO2;
	ubigint refSubstr = refInP;
	ubigint refBuf = refInAlAs45;
	ubigint refBotcont = refInGaAs53B;
	ubigint refTopcont = refInGaAs53C;
	ubigint refAR = refInGaAlAsAR;

	if (matsys.compare("GaAs") == 0) {
		refArlow = refYF3;
		refSubstr = refGaAs;
		refBuf = refAlGaAs42;
		refBotcont = refGaAsB;
		refTopcont = refGaAsC;
		refAR = refAlGaAsAR;
	};

	ubigint refClad = refSiO2;
	if (cladmat.compare("Air") == 0) {
		refClad = refAir;
	} else if (cladmat.compare("Au") == 0) {
		refClad = refAu;
	} else if (cladmat.compare("MgF2") == 0) {
		refClad = refMgF2;
	} else if (cladmat.compare("YF3") == 0) {
		refClad = refYF3;
	};

	// -- material modifications in terms of n, k
	if (matsys.compare("InP") == 0) {
		// InP: default is n_5_0 (no mod.)
		// InAlAs45: default is n_5_0 (no mod.) ; used as barrier material (irrelevant here)

		// InGaAs53B: default is n_5_0 (no mod.) ; used as bottom contact material: modify k and nD
		str.str(""); str << kBotcont; s = str.str();
		if (scantype.compare("kBotcont") == 0) s = "envdft(env.mpa, " + s + ")";
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAs53B, refDsn, "phot", "k", 0, s, "");

		str.str(""); str << nDBotcont;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAs53B, refDsn, "elec", "nD", 0, str.str(), "");

		// InGaAs53C: default is n_5_0 (no mod.) ; used as top contact material: modify k and nD
		str.str(""); str << kTopcont; s = str.str();
		if (scantype.compare("kTopcont") == 0) s = "envdft(env.mpa, " + s + ")";
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAs53C, refDsn, "phot", "k", 0, s, "");

		str.str(""); str << nDTopcont;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAs53C, refDsn, "elec", "nD", 0, str.str(), "");

		// InGaAlAsAR: modify n, k, ko, ke, x, nD
		n = xAR*3.389 + (1.0-xAR)*3.134;
		str.str(""); str << n;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "phot", "n", 0, str.str(), "");

		if (anisomat) {
			str.str(""); str << kAR; s = str.str();
			if (scantype.compare("kAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "phot", "ko", 0, s, "");

			str.str(""); str << keAR; s = str.str();
			if (scantype.compare("keAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "phot", "ke", 0, s, "");

		} else {
			str.str(""); str << kAR; s = str.str();
			if (scantype.compare("kAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "phot", "k", 0, s, "");
		};

		str.str(""); str << xAR;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "cryst", "x", 0, str.str(), "");

		str.str(""); str << nDAR;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refInGaAlAsAR, refDsn, "elec", "nD", 0, str.str(), "");

	} else if (matsys.compare("GaAs") == 0) {
		// GaAs: default is n_5_0 (no mod.)
		// AlGaAs42: default is n_5_0 (no mod.) ; used as barrier material (irrelevant here)

		// GaAsB: default is n_5_0 (no mod.) ; used as bottom contact material: modify k and nD
		str.str(""); str << kBotcont; s = str.str();
		if (scantype.compare("kBotcont") == 0) s = "envdft(env.mpa, " + s + ")";
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refGaAsB, refDsn, "phot", "k", 0, s, "");

		str.str(""); str << nDBotcont;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refGaAsB, refDsn, "elec", "nD", 0, str.str(), "");

		// GaAsC: default is n_5_0 (no mod.) ; used as top contact material: modify k and nD
		str.str(""); str << kTopcont; s = str.str();
		if (scantype.compare("kTopcont") == 0) s = "envdft(env.mpa, " + s + ")";
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refGaAsC, refDsn, "phot", "k", 0, s, "");

		str.str(""); str << nDTopcont;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refGaAsC, refDsn, "elec", "nD", 0, str.str(), "");

		// AlGaAsAR: modify n, k, ko, ke, x, nD
		n = xAR*3.3 + (1.0-xAR)*3.115;
		str.str(""); str << n;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "phot", "n", 0, str.str(), "");

		if (anisomat) {
			str.str(""); str << kAR; s = str.str();
			if (scantype.compare("kAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "phot", "ko", 0, s, "");

			str.str(""); str << keAR; s = str.str();
			if (scantype.compare("keAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "phot", "ke", 0, s, "");

		} else {
			str.str(""); str << kAR; s = str.str();
			if (scantype.compare("kAR") == 0) s = "envdft(env.mpa, " + s + ")";
			dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "phot", "k", 0, s, "");
		};

		str.str(""); str << xAR;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "cryst", "x", 0, str.str(), "");

		str.str(""); str << nDAR;
		dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAlGaAsAR, refDsn, "elec", "nD", 0, str.str(), "");
	};

	// Au: default is n_5_0, k_5_0 ; modify to n_tbl, k_tbl
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAu, refDsn, "phot", "n", 0, "n_tbl", "");
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refAu, refDsn, "phot", "k", 0, "k_tbl", "");

	// SiO2: default is n_1_55, 0 ; modify to n_IR_tbl, k_IR_tbl
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refSiO2, refDsn, "phot", "n", 0, "n_IR_tbl", "");
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refSiO2, refDsn, "phot", "k", 0, "k_IR_tbl", "");

	// MgF2: default is n_5_0, 0 ; modify to no_tbl, k_5_0
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refMgF2, refDsn, "phot", "n", 0, "no_tbl", "");
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refMgF2, refDsn, "phot", "k", 0, "k_5_0", "");

	// YF3: default is n_5_0 ; modify to n_tbl
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refYF3, refDsn, "phot", "n", 0, "n_tbl", "");

	// ZnSe: default is n_1_55 ; modify to n_tbl
	dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, refZnSe, refDsn, "phot", "n", 0, "n_tbl", "");

	// --- vertical setup

	// -- fill stack
	ubigint refStkFill = dbsplnr->tblplnrmstack->appendNewRecToRst(stks, NULL, VecPlnrVMStackBasetype::FILL, refDsn, 1, "fill", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::NINF, "", 0.0, VecPlnrVMStackCeilAligntype::PINF, "", 0.0, "", "");

	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkFill, 1, refAir, VecPlnrVMLayerTtype::FFILL, "bothalf", 0, 0, 0, "", "");
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkFill, 2, refClad, VecPlnrVMLayerTtype::CFILL, "tophalf", 0, 0, 0, "", "");

	// -- base stack
	ubigint refStkBase = dbsplnr->tblplnrmstack->appendNewRecToRst(stks, NULL, VecPlnrVMStackBasetype::REG, refDsn, 2, "base", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::VOID, "", 0.0, VecPlnrVMStackCeilAligntype::REL, "fill.zbothalf_tophalf", 0.0, "", "");

	// - double anti-reflection layer with t=lam/4
	// nSiO2=1.3886, nYF3=1.45, t=lam/n/4
	if (refArlow == refSiO2) t = lam/1.3886/4.0;
	else if (refArlow == refYF3) t = lam/1.45/4.0;
	str.str(""); str << t;
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkBase, 1, refArlow, VecPlnrVMLayerTtype::ABS, "arlow", 0, 0, 0, str.str(), "");

	// nZnSe=2.432, t=lam/n/4
	t = lam/2.432/4.0;
	str.str(""); str << t;
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkBase, 2, refZnSe, VecPlnrVMLayerTtype::ABS, "arhigh", 0, 0, 0, str.str(), "");

	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkBase, 3, refSubstr, VecPlnrVMLayerTtype::ABS, "substr", 0, 0, 0, "50", "");

	// -- epi-layers below active region
	ubigint refStkEpibot = dbsplnr->tblplnrmstack->appendNewRecToRst(stks, NULL, VecPlnrVMStackBasetype::REG, refDsn, 3, "epibot", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::REL, "base.zceil", 0.0, VecPlnrVMStackCeilAligntype::SLYR, "", 0.0, "", "");

	if (buf) {
		str.str(""); str << tBuf; s = str.str();
		if (scantype.compare("tBuf") == 0) s = "envdft(env.geo, " + s + ")";
		dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpibot, 1, refBuf, VecPlnrVMLayerTtype::ABS, "buf", 0, 0, 0, s, "");
	};

	str.str(""); str << tBotcont; s = str.str();
	if (scantype.compare("tBotcont") == 0) s = "envdft(env.geo, " + s + ")";
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpibot, 2, refBotcont, VecPlnrVMLayerTtype::ABS, "botcont", 0, 0, 0, s, "");

	// -- active region
	str.str(""); str << NPrd; s = str.str();
	if (scantype.compare("NPrd") == 0) s = "envdft(env.geo, " + s + ")";
	ubigint refStkEpiar = dbsplnr->tblplnrmstack->appendNewRecToRst(stks, NULL, VecPlnrVMStackBasetype::PERTPL, refDsn, 4, "epiar", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::REL, "epibot.zceil", 0.0, VecPlnrVMStackCeilAligntype::SLYR, "", 0.0, "prd", s);

	str.str(""); str << tPrd;
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::TPL, VecPlnrVMLayerHkTbl::STK, refStkEpiar, 1, refAR, VecPlnrVMLayerTtype::ABS, "prd", 0, 0, 0, str.str(), "");

	// -- epi-layers above active region and top metallization
	ubigint refStkEpimettop = dbsplnr->tblplnrmstack->appendNewRecToRst(stks, NULL, VecPlnrVMStackBasetype::REG, refDsn, 5, "epimettop", VecPlnrVMStackModtype::VOID, VecPlnrVMStackFlrAligntype::REL, "epiar.zceil", 0.0, VecPlnrVMStackCeilAligntype::SLYR, "", 0.0, "", "");

	str.str(""); str << tTopcont; s = str.str();
	if (scantype.compare("tTopcont") == 0) s = "envdft(env.geo, " + s + ")";
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpimettop, 1, refTopcont, VecPlnrVMLayerTtype::ABS, "topcontflat", 0, 0, 0, s, "");

	str.str(""); str << tGrat; s = str.str();
	if (scantype.compare("tGrat") == 0) s = "envdft(env.geo, " + s + ")";
	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpimettop, 2, refTopcont, VecPlnrVMLayerTtype::ABS, "topcontgrat", 0, 0, 0, s, "");

	str.str(""); str << tClad;
	ubigint refLyrClad = dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpimettop, 3, refClad, VecPlnrVMLayerTtype::ABS, "clad", 0, 0, 0, str.str(), "");

	dbsplnr->tblplnrmlayer->insertNewRec(NULL, 0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refStkEpimettop, 4, refAu, VecPlnrVMLayerTtype::ABS, "topmet", 0, 0, 0, "1.0", "");

	// --- lateral setup

	// -- substrate wafer
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsn, 1, 0, 0, "sample", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "", 0.0, 0.0, 0.0, "", refsDtp, "wg", devs);
	if (scantype.compare("mesa") == 0) w = scanstop + 30.0; else w = mesa + 30.0;
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "l", w);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "ridgew", w);

	// -- QCD
	dev = Plnr::addDeviceFromTpl(dbsplnr, refDsn, 2, 0, 0, "qcd", VecPlnrVMDeviceAligntype::ABS, "vctr", "", "", "", 0.0, 0.0, 0.0, "", refsDtp, "photdet", devs);

	if (scantype.compare("mesa") == 0) {
		str.str(""); str << "envdft(env.geo, " << (mesa+2.0*2.0) << ")";
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "size", str.str());
	} else {
		Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "size", mesa+2.0*2.0);
	};

	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ext", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "metgrat", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "mis", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "schky", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "hgrat", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "vgrat", true);

	if (scantype.compare("gratprd") == 0) {
		str.str(""); str << "envdft(env.geo, " << gratprd << ")";
		Plnr::changeDpa(dbsplnr, dev->ref, 0, "gratprd", str.str());
	} else {
		Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratprd", gratprd);
	};

	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "gratfill", 0.5);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "mesaclr", 2.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "botw", 2.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sbot", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ebot", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "nbot", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "wbot", false);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "metclr", 2.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmline", false);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "ohmring", true);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "olp", 2.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "sideopn", true);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "opnsize", 2.0);
	Plnr::changeBoolDpa(dbsplnr, dev->ref, 0, "topfill", true);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extsize", 0.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsx", 0.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "extofsy", 0.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpd", 10.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsx", 0.0);
	Plnr::changeDoubleDpa(dbsplnr, dev->ref, 0, "bumpofsy", 0.0);

	// --- vertical vs. lateral
	Plnr::addStksru(dbsplnr, "base", "sample", "all", "", "", stks, devs);

	Plnr::addStksru(dbsplnr, "epibot", "qcd", "mesa", "", "", stks, devs); // entire stack
	Plnr::addStksru(dbsplnr, "epiar", "qcd", "mesa", "", "", stks, devs); // entire stack

	if (grattype.compare("none") == 0) {
		Plnr::addStksru(dbsplnr, "epimettop", "qcd", "mesa", "topcontflat", "topcontgrat", stks, devs);
	} else if (grattype.compare("half") == 0) {
		Plnr::addStksru(dbsplnr, "epimettop", "qcd", "mesa", "topcontflat", "topcontflat", stks, devs);
		Plnr::addStksru(dbsplnr, "epimettop", "qcd", "grat", "topcontgrat", "topcontgrat", stks, devs);
	} else if (grattype.compare("full") == 0) {
		Plnr::addStksru(dbsplnr, "epimettop", "qcd", "grat", "topcontflat", "topcontgrat", stks, devs);
	};

	if (topmet) Plnr::addStksru(dbsplnr, "epimettop", "qcd", "topmet", "topmet", "topmet", stks, devs);

	// --- calculation domains

	// - in-plane domain guides
	// pre-existing: qcd.vctr
	// new:
	//  vasymm (offset from center by lam/8)
	//  vmesal (left mesa limit), vmesar (right mesa limit)
	//  vl (left calc domain limit), vr (right calc domain limit)
	//  lcs (cross-section line guide)

	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LGPAR2, refDsn, 1, "lcs", "", "qcd.vctr", "", "qcd.l1", "", "", "", "");

	str.str(""); str << (-lam/8.0);
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 2, "vasymm", "", "qcd.vctr", "", "lcs", "", "", str.str(), "");

	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLGX, refDsn, 3, "vmesal", "", "", "", "lcs", "qcd.l13", "", "", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLGX, refDsn, 4, "vmesar", "", "", "", "lcs", "qcd.l18", "", "", "");

	if (calctype.compare("fdtd") == 0) {
		if (corn) {
			dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 5, "vl", "", "vmesal", "", "lcs", "", "", "-10.0", "");
			dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 6, "vr", "", "vmesar", "", "lcs", "", "", "10.0", "");
		} else {
			dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 5, "vl", "", "vmesal", "", "lcs", "", "", "2.0", "");
			dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 6, "vr", "", "vmesar", "", "lcs", "", "", "-2.0", "");
		};

	} else {
		// waveguide modes
		dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 5, "vl", "", "vmesal", "", "lcs", "", "", "-3.0", "");
		dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::VTXLG, refDsn, 6, "vr", "", "vmesar", "", "lcs", "", "", "3.0", "");
	};

	// - vertical domain guides
	// new:
	//  zf1, zf1pp, zc1 (floor, excitation and ceiling levels for bottom illumination)
	//  zf2, zc2mm, zc2 (floor, excitation and ceiling levels for top illumination)
	//  zwgf, zwgc (waveguiding region floor and ceiling levels)
	//  zarfpp, zar, zarcmm (active region levels for grid with tPrd vertical spacing)

	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 7, "zf1", "epibot.zflr", "", "", "", "", "", "-12.0", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 8, "zf1pp", "epibot.zflr", "", "", "", "", "", "-7.0", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 9, "zc1", "epimettop.zceil", "", "", "", "", "", "8.0", "");

	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 10, "zf2", "epibot.zflr", "", "", "", "", "", "-8.0", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 11, "zc2mm", "epimettop.ztopcontgrat_clad", "", "", "", "", "", "7.0", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 12, "zc2", "epimettop.ztopcontgrat_clad", "", "", "", "", "", "12.0", "");

	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 13, "zwgf", "epibot.zflr", "", "", "", "", "", "-3.0", "");
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 14, "zwgc", "epimettop.ztopcontgrat_clad", "", "", "", "", "", "3.0", "");

	str.str(""); str << (0.5*tPrd);
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 15, "zarfpp", "epiar.zflr", "", "", "", "", "", str.str(), "");
	str.str(""); str << (-0.49999*tPrd);
	dbsplnr->tblplnrmdomaingd->insertNewRec(NULL, VecPlnrVMDomaingdBasetype::LVL, refDsn, 16, "zarcmm", "epiar.zceil", "", "", "", "", "", str.str(), "");

	// - domains
	str.str(""); str << grid; s = str.str();
	if (scantype.compare("grid") == 0) s = "envdft(env.geo, " + s + ")";

	ubigint refBotbox = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZCSBOX_XYZ, refDsn, 1, "botbox", "zf1", "zc1", "vl", "lcs", "vr", "", "", "", "", "", "", "", s, s);
	ubigint refTopbox = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZCSBOX_XYZ, refDsn, 2, "topbox", "zf2", "zc2", "vl", "lcs", "vr", "", "", "", "", "", "", "", s, s);
	ubigint refCtrbox = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZCSBOX_XYZ, refDsn, 3, "ctrbox", "zwgf", "zwgc", "vl", "lcs", "vr", "", "", "", "", "", "", "", s, s);

	ubigint refBotline = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::XYLINE_XYZ, refDsn, 4, "botline", "zf1pp", "", "vl", "lcs", "vr", "", "", "", "", "", "", "", s, "");
	ubigint refTopline = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::XYLINE_XYZ, refDsn, 5, "topline", "zc2mm", "", "vl", "lcs", "vr", "", "", "", "", "", "", "", s, "");

	ubigint refCtrpeek = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZLINE_XYZ, refDsn, 6, "ctrpeek", "zwgf", "zwgc", "qcd.vctr", "", "", "", "", "", "", "", "", "", "", s);
	ubigint refAspeek = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZLINE_XYZ, refDsn, 7, "aspeek", "zwgf", "zwgc", "vasymm", "", "", "", "", "", "", "", "", "", "", s);

	ubigint refAspoint = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::POINT_XYZ, refDsn, 8, "aspoint", "zarfpp", "", "vasymm", "", "", "", "", "", "", "", "", "", "", "");

	// ctrbox is for 2d wgcalc // zwgf/zwgc + vl(lcs)vr (but, make vl/vr +/- 3µm) ; used for wgmode
	// ctrpeek is for 1d wgcalc // zwgf/zwgc + qcd.vctr ; used for wgmonde

	// arbox is for 2d wgcalc // zarfpp/zarcmm + vmesal(lcs)vmesar
	// arpeek is for 1d wgcalc // zarfpp/zarcmm + vasymm

	// arbox and arpeek have a custom grid
	str.str(""); str << tPrd;

	ubigint refArbox;
	if (corn) {
		refArbox = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZCSBOX_XYZ, refDsn, 9, "arbox", "zarfpp", "zarcmm", "vmesal", "lcs", "vmesar", "", "", "", "", "", "", "", str.str(), str.str());
	} else {
		refArbox = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZCSBOX_XYZ, refDsn, 9, "arbox", "zarfpp", "zarcmm", "vl", "lcs", "vr", "", "", "", "", "", "", "", str.str(), str.str());
	};

	ubigint refArpeek = dbsplnr->tblplnrmdomain->insertNewRec(NULL, VecPlnrVMDomainBasetype::ZLINE_XYZ, refDsn, 10, "arpeek", "zarfpp", "zarcmm", "qcd.vctr", "", "", "", "", "", "", "", "", "", "", str.str());

	// --- calculation (skip template functionality and cpa's for now)
	if (calctype.compare("wgmode1d") == 0) {
		dbsplnr->tblplnrmcalc->insertNewRec(&clc, 0, 0, refPro, VecPlnrVMCalcDim::RSTCUB, 0, 0, refDsn, "QCD 1D waveguide mode simulation", 0, "");
	} else if (calctype.compare("wgmode2d") == 0) {
		dbsplnr->tblplnrmcalc->insertNewRec(&clc, 0, 0, refPro, VecPlnrVMCalcDim::RSTCUB, 0, 0, refDsn, "QCD 2D waveguide mode simulation", 0, "");
	} else {
		// FDTD
		dbsplnr->tblplnrmcalc->insertNewRec(&clc, 0, 0, refPro, VecPlnrVMCalcDim::RSTCUB, 0, 0, refDsn, "QCD FDTD simulation", 0, "");
	};

	refClc = clc->ref;

	dsn->refUref = clc->ref;
	dbsplnr->tblplnrmdesign->updateRec(dsn);

	Plnr::addDoubleCen(dbsplnr, clc->ref, 0, "lam", lam); // this is required for the determination of n,k lateron

	// -- link domains
	if (calctype.compare("wgmode1d") == 0) {
		dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refCtrpeek, "dom");
		dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refArpeek, "eval");

	} else if (calctype.compare("wgmode2d") == 0) {
		dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refCtrbox, "dom");
		dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refArpeek, "eval");
		// dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refArbox, "eval");

	} else {
		// FDTD
		if (illpos.compare("top") == 0) {
			dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refTopbox, "dom");
			dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refTopline, "exc");

			if (mon) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refTopbox, "mon");
			if (sshot) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refTopbox, "sshot");

		} else if (illpos.compare("bottom") == 0) {
			dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refBotbox, "dom");
			dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refBotline, "exc");

			if (mon) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refBotbox, "mon");
			if (sshot) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refBotbox, "sshot");
		};

		if (armon) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refArbox, "mon");
		if (aspmon) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refAspoint, "mon");

		if (arsshot) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refArbox, "sshot");
		if (peeksshot) dbsplnr->tblplnrrmcalcmdomain->insertNewRec(NULL, refClc, refAspeek, "sshot");
	};

	// --- preliminary solution: calculation item generation already here

	// update simulation start time
	clc->start = time(NULL);
	dbsplnr->tblplnrmcalc->updateRec(clc);

	modlam = (scantype.compare("lam") == 0);
	modgeo = ((scantype.compare("mesa") == 0) || (scantype.compare("tBuf") == 0) || (scantype.compare("tBotcont") == 0) || (scantype.compare("NPrd") == 0)
				|| (scantype.compare("tTopcont") == 0) || (scantype.compare("gratprd") == 0) || (scantype.compare("tGrat") == 0) || (scantype.compare("grid") == 0));
	modmpa = ((scantype.compare("kBotcont") == 0) || (scantype.compare("kTopcont") == 0) || (scantype.compare("kAR") == 0)|| (scantype.compare("keAR") == 0));
	modmat = (scantype.compare("cladmat") == 0);

	// generate calculation items and modified designs
	if (modlam || modgeo || modmpa) {
		if (scanmult == 1.0) {
			for (double scan=scanstart;scan<=scanstop;scan+=scanstep) {
				str.str(""); str << scantype << scan;
				refCli = dbsplnr->tblplnrmcalcitem->insertNewRec(NULL, refClc, clicnt++, 0, str.str());
				refsCli.push_back(refCli);

				if (modlam) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "lam", scan);
				else if (modgeo) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "geo", scan);
				else if (modmpa) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "mpa", scan);
			};

		} else {
			for (double scan=scanstart;scan<=scanstop;scan*=scanmult) {
				str.str(""); str << scantype << scan;
				refCli = dbsplnr->tblplnrmcalcitem->insertNewRec(NULL, refClc, clicnt++, 0, str.str());
				refsCli.push_back(refCli);

				if (modlam) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "lam", scan);
				else if (modgeo) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "geo", scan);
				else if (modmpa) Plnr::addDoubleCen(dbsplnr, refClc, refCli, "mpa", scan);
			};
		};

		Plnr::createModdsns(dbsplnr, xchg->acvpath, refClc, 0, refsModdsn);

	} else if (modmat) {
		// Air vs. SiO2 vs. Au vs. MgF2 vs. YF3
		for (unsigned int i=0;i<5;i++) {
			if (i == 0) {
				s = "cladmatAir";
				ref = refAir;
			} else if (i == 1) {
				s = "cladmatSiO2";
				ref = refSiO2;
			} else if (i == 2) {
				s = "cladmatAu";
				ref = refAu;
			} else if (i == 3) {
				s = "cladmatMgF2";
				ref = refMgF2;
			} else if (i == 4) {
				s = "cladmatYF3";
				ref = refYF3;
			};

			refCli = dbsplnr->tblplnrmcalcitem->insertNewRec(&cli, refClc, clicnt++, 0, s);
			refsCli.push_back(refCli);

			moddsn = new PlnrMDesign(*dsn);
			moddsn->ref = 0;

			moddsn->modRefPlnrMDesign = dsn->ref;
			moddsn->drvRefPlnrMDesign = 0;

			moddsn->refIxVTbl = VecPlnrVMDesignRefTbl::CLI;
			moddsn->refUref = refCli;

			dbsplnr->tblplnrmdesign->insertRec(moddsn);
			refsModdsn.push_back(moddsn->ref);

			dbsplnr->tblplnrjmlayermaterial->insertNewRec(NULL, refLyrClad, moddsn->ref, ref);

			cli->refPlnrMDesign = moddsn->ref;
			dbsplnr->tblplnrmcalcitem->updateRec(cli);

			delete cli;
			delete moddsn;
		};
	};

	// --- prepare for expansion
	retval = VecVSge::EXPAND1;

// IP enterSgePrepare --- IEND
	retval = nextIxVSge;
	return retval;
};

void JobPlnrClcDisptest::leaveSgePrepare(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgePrepare --- INSERT
};

uint JobPlnrClcDisptest::enterSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND1;
	nextIxVSge = VecVSge::EXPAND2;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand1 --- IBEGIN
	// expand devices/stacks (modified designs are included)
	vector<DpchInvPlnr*> dpchinvs;

	PlnrExp_blks::getInvs(dbsplnr, refsDtp, refDsn, dpchinvs);

	addInvs(dpchinvs);
// IP enterSgeExpand1 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgeExpand1(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand1 --- INSERT
};

uint JobPlnrClcDisptest::enterSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND2;
	nextIxVSge = VecVSge::EXPAND3;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand2 --- IBEGIN

	// expand base design
	addInv((DpchInvPlnr*) new DpchInvPlnrExpDsn(0, 0, refDsn));

// IP enterSgeExpand2 --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgeExpand2(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand2 --- INSERT
};

uint JobPlnrClcDisptest::enterSgeExpand3(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::EXPAND3;
	nextIxVSge = VecVSge::DISCR;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeExpand3 --- IBEGIN
	// expand modified designs
	vector<DpchInvPlnr*> dpchinvs;

	for (unsigned int i=0;i<refsModdsn.size();i++) dpchinvs.push_back(new DpchInvPlnrExpDsn(0, 0, refsModdsn[i]));

	addInvs(dpchinvs);
// IP enterSgeExpand3 --- IEND
	submitInvs(dbsplnr, VecVSge::DISCR, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgeExpand3(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeExpand3 --- INSERT
};

uint JobPlnrClcDisptest::enterSgeDiscr(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DISCR;
	nextIxVSge = VecVSge::CALC;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeDiscr --- IBEGIN
	// generate design discretizations
	vector<DpchInvPlnr*> dpchinvs;

	if (modlam || modmpa) {
		// discretize base design only
		dpchinvs.push_back(new DpchInvPlnrRastCub(0, 0, refDsn));
	} else if (modgeo || modmat) {
		// discretize all designs
		for (unsigned int i=0;i<refsModdsn.size();i++) dpchinvs.push_back(new DpchInvPlnrRastCub(0, 0, refsModdsn[i]));
	};

	addInvs(dpchinvs);
// IP enterSgeDiscr --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgeDiscr(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeDiscr --- INSERT
};

uint JobPlnrClcDisptest::enterSgeCalc(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::CALC;
	nextIxVSge = VecVSge::PLOT;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeCalc --- IBEGIN
	// launch calculations
	vector<DpchInvPlnr*> dpchinvs;

	DpchInvPlnrWgmodeFd1d* dpchwgmode1d = NULL;
	DpchInvPlnrWgmodeFd2d* dpchwgmode2d = NULL;
	DpchInvPlnrMeepTrf2d* dpchmeep = NULL;

	double dt = 1.0e9 * lam/3.0e8 * 1.0;

	ListPlnrRMCalcMDomain crds;
	PlnrRMCalcMDomain* crd = NULL;

	PlnrMDomain* dom = NULL;

	string srefDom, srefDomExc;

	vector<string> srefsDomEval;
	vector<string> srefsDomMon;
	vector<string> srefsDomSshot;

	ubigint refRastfile;

	// identify domains
	dbsplnr->tblplnrrmcalcmdomain->loadRstBySQL("SELECT * FROM TblPlnrRMCalcMDomain WHERE refPlnrMCalc = " + to_string(refClc), false, crds);
	
	for (unsigned int i=0;i<crds.nodes.size();i++) {
		crd = crds.nodes[i];

		if (dbsplnr->tblplnrmdomain->loadRecByRef(crd->refPlnrMDomain, &dom)) {
			if (calctype.compare("wgmode1d") == 0) {
				if (crd->srefPlnrKCalcdomprp.compare("dom") == 0) srefDom = dom->sref;
				else if (crd->srefPlnrKCalcdomprp.compare("eval") == 0) srefsDomEval.push_back(dom->sref);

			} else if (calctype.compare("wgmode2d") == 0) {
				if (crd->srefPlnrKCalcdomprp.compare("dom") == 0) srefDom = dom->sref;
				else if (crd->srefPlnrKCalcdomprp.compare("eval") == 0) srefsDomEval.push_back(dom->sref);

			} else {
				// FDTD
				if (crd->srefPlnrKCalcdomprp.compare("dom") == 0) srefDom = dom->sref;
				else if (crd->srefPlnrKCalcdomprp.compare("exc") == 0) srefDomExc = dom->sref;
				else if (crd->srefPlnrKCalcdomprp.compare("mon") == 0) srefsDomMon.push_back(dom->sref);
				else if (crd->srefPlnrKCalcdomprp.compare("sshot") == 0) srefsDomSshot.push_back(dom->sref);
			};

			delete dom;
		};
	};

	for (unsigned int i=0;i<refsCli.size();i++) {
		// find rasterizer file (cli file will overwrite cal file if present)
		dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CAL) + " AND refUref = " + to_string(refClc) + " AND osrefKContent = 'rast'", refRastfile);
		dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(refsCli[i]) + " AND osrefKContent = 'rast'", refRastfile);

		if (calctype.compare("wgmode1d") == 0) {
			dpchwgmode1d = new DpchInvPlnrWgmodeFd1d(0, 0,
				/* lossmat */ lossmat,
				/* prefix */ "",
				/* refPlnrMCalc */ refClc,
				/* refPlnrMCalcitem */ refsCli[i],
				/* refRastfile */ refRastfile,
				/* srefDom */ srefDom,
				/* srefsDomEval */ srefsDomEval,
				/* te */ te,
				/* tm */ tm);

			dpchinvs.push_back(dpchwgmode1d);

		} else if (calctype.compare("wgmode2d") == 0) {
			dpchwgmode2d = new DpchInvPlnrWgmodeFd2d(0, 0,
				/* lossmat */ lossmat,
				/* prefix */ "",
				/* refPlnrMCalc */ refClc,
				/* refPlnrMCalcitem */ refsCli[i],
				/* refRastfile */ refRastfile,
				/* srefDom */ srefDom,
				/* srefsDomEval */ srefsDomEval,
				/* te */ te,
				/* tm */ tm);

			dpchinvs.push_back(dpchwgmode2d);

		} else {
			// FDTD
			dpchmeep = new DpchInvPlnrMeepTrf2d(0, 0,
				/* anisomat */ anisomat,
				/* deltalam */ deltalam,
				/* dt */ dt,
				/* lossmat */ lossmat,
				/* prefix */ "",
				/* refPlnrMCalc */ refClc,
				/* refPlnrMCalcitem */ refsCli[i],
				/* refRastfile */ refRastfile,
				/* srefDom */ srefDom,
				/* srefDomExc */ srefDomExc,
				/* srefsDomMon */ srefsDomMon,
				/* srefsDomSshot */ srefsDomSshot,
				/* tm */ false, // tm true would imply TM source
				/* tstop */ tstop);

			dpchinvs.push_back(dpchmeep);
		};
	};

	// --- pass to op processors
	addInvs(dpchinvs);

	orefsCli.clear();
	for (unsigned int i=0;i<dpchinvs.size();i++) orefsCli.push_back(dpchinvs[i]->oref);

	// prepare collection of mode count for wgmode calculations
	if ( (calctype.compare("wgmode1d") == 0) || (calctype.compare("wgmode2d") == 0) ) {
		teNs.resize(refsCli.size());
		tmNs.resize(refsCli.size());
	};
// IP enterSgeCalc --- IEND
	submitInvs(dbsplnr, VecVSge::IDLE, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgeCalc(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeCalc --- INSERT
};

uint JobPlnrClcDisptest::enterSgePlot(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PLOT;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgePlot --- IBEGIN
	// generate design and result plots for each calculation item
	ostringstream str;
	string s;

	PlnrMCalcitem* cli = NULL;

	ubigint refFile;

	vector<string> filenames;

	vector<DpchInvPlnr*> dpchinvs;

	vector<uint> orefs;

	DpchInvPlnrPlotDomdat2dpng* dpch2dpng = NULL;

	string srefDom;

	double altzmaxExy, altzmaxEz;

	string zvar;

	if (calctype.compare("wgmode1d") == 0) {
/*
		// ... n gnuplot
	DpchInvPlnrPlotDomdat1dgnu(const uint oref = 0, const uint jref = 0, const string& alttitle = "", const string& altytitle = "", const ubigint refFile = 0, const string& srefDom = "", const string& xdim = "", const uint yslcDimsN = 0, const uint yslcIcsN = 0, const string& yvar = "");
... returns tgzfile ... but why?
... should return only png

		// ... gnuplot for each mode
*/

	} else if (calctype.compare("wgmode2d") == 0) {
		for (unsigned int i=0;i<refsCli.size();i++) {
			dbsplnr->tblplnrmcalcitem->loadRecByRef(refsCli[i], &cli);

			// - refractive index
			dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(cli->ref)
						+ " AND osrefKContent = 'dgrid' AND Filename = '" + cli->Title + "_n.cdf'", refFile);

			dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dpng(0, 0,
				/* altzmax */ 0.0,
				/* altzmin */ 0.0,
				/* annotColor */ "white",
				/* annotDim */ "",
				/* annotHeight */ 10,
				/* annotPos */ "sw",
				/* annotText */ "n",
				/* ctrzero */ false,
				/* logscale */ false,
				/* refFile */ refFile,
				/* spczlim */ false,
				/* srefDom */ "ctrbox",
				/* xdim */ "dimXY",
				/* ydim */ "dimZ",
				/* zslcDims */ {},
				/* zslcIcs */ {},
				/* zvar */ "n"));
			filenames.push_back(cli->Title + "_n.png");

			// - pngplot for each TM mode
			dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(cli->ref)
						+ " AND osrefKContent = 'dgrid' AND Filename = '" + cli->Title + "_res.cdf'", refFile);

			for (unsigned int j=0;j<tmNs[i];j++) {
				dpch2dpng = new DpchInvPlnrPlotDomdat2dpng(0, 0,
					/* altzmax */ 0.0,
					/* altzmin */ 0.0,
					/* annotColor */ "white",
					/* annotDim */ "",
					/* annotHeight */ 10,
					/* annotPos */ "sw",
					/* annotText */ "|Ez|^2",
					/* ctrzero */ false,
					/* logscale */ false,
					/* refFile */ refFile,
					/* spczlim */ false,
					/* srefDom */ "ctrbox",
					/* xdim */ "dimXY",
					/* ydim */ "dimZ",
					/* zslcDims */ {"dimTM"},
					/* zslcIcs */ {(int) j},
					/* zvar */ "EzTM_sqr");

				dpchinvs.push_back(dpch2dpng);

				str.str(""); str << cli->Title << "_EzTM" << j << "_sqr.png";
				filenames.push_back(str.str());
			};
		};

	} else if (calctype.compare("fdtd") == 0) {
		if (illpos.compare("bottom") == 0) {
			srefDom = "botbox";
			altzmaxExy = 1.5;
			altzmaxEz = 1.5;
//			altzmaxEz = 0.6;

		} else {
			srefDom = "topbox";
			altzmaxExy = 1.5;
			altzmaxEz = 0.015;
		};

		// - design xy
//		dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 1000, refDsn, 0, true, false, true, true, false, 1000));
//		filenames.push_back("dsnxy.xml");

		// - design z
		dpchinvs.push_back(new DpchInvPlnrPlotDsnzsvg(0, 0, false, 1000, refDsn, true, 1000));
		filenames.push_back("dsnz.xml");

		for (unsigned int i=0;i<refsCli.size();i++) {
			dbsplnr->tblplnrmcalcitem->loadRecByRef(refsCli[i], &cli);

			// - design xy
//			dpchinvs.push_back(new DpchInvPlnrPlotDsnxysvg(0, 0, "", "", "", 1000, cli->refPlnrMDesign, 0, true, false, true, true, false, 1000));
//			filenames.push_back(cli->Title + "_dsnxy.xml");

			// - design z
//			dpchinvs.push_back(new DpchInvPlnrPlotDsnzsvg(0, 0, false, 1000, cli->refPlnrMDesign, true, 1000));
//			filenames.push_back(cli->Title + "_dsnz.xml");

			// - refractive index
			if (anisomat) {
				dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(cli->ref)
							+ " AND osrefKContent = 'dgrid' AND Filename = '" + cli->Title + "_no.cdf'", refFile);
				zvar = "no";
			} else {
				dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(cli->ref)
							+ " AND osrefKContent = 'dgrid' AND Filename = '" + cli->Title + "_n.cdf'", refFile);
				zvar = "n";
			};

			dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dpng(0, 0,
				/* altzmax */ 0.0,
				/* altzmin */ 0.0,
				/* annotColor */ "white",
				/* annotDim */ "",
				/* annotHeight */ 10,
				/* annotPos */ "sw",
				/* annotText */ "n",
				/* ctrzero */ false,
				/* logscale */ false,
				/* refFile */ refFile,
				/* spczlim */ false,
				/* srefDom */ srefDom,
				/* xdim */ "dimXY",
				/* ydim */ "dimZ",
				/* zslcDimsN */ {},
				/* zslcIcsN */ {},
				/* zvar */ zvar));
			filenames.push_back(cli->Title + "_n.png");

			// - electric field videos/final snapshots
			dbsplnr->loadUbigintBySQL("SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " + to_string(VecPlnrVMFileRefTbl::CLI) + " AND refUref = " + to_string(cli->ref)
						+ " AND osrefKContent = 'dgrid' AND Filename = '" + cli->Title + "_res.cdf'", refFile);

			if (mon) {
				dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dvid(0, 0,
					/* altzmax */ altzmaxEz,
					/* altzmin */ 0.0,
					/* annotColor */ "white",
					/* annotHeight */ 10,
					/* ctrzero */ false,
					/* frmrate */ 6,
					/* logscale */ false,
					/* refFile */ refFile,
					/* spczlim */ true,
					/* srefDom */ srefDom,
					/* tdim */ "dimT",
					/* xdim */ "dimXY",
					/* ydim */ "dimZ",
					/* zslcDimsN */ {},
					/* zslcIcsN */ {},
					/* zvar */ "Ez_sqr"));
				filenames.push_back(cli->Title + "_Ez_sqr.avi");

				dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dvid(0, 0,
					/* altzmax */ altzmaxExy,
					/* altzmin */ 0.0,
					/* annotColor */ "white",
					/* annotHeight */ 10,
					/* ctrzero */ false,
					/* frmrate */ 6,
					/* logscale */ false,
					/* refFile */ refFile,
					/* spczlim */ true,
					/* srefDom */ srefDom,
					/* tdim */ "dimT",
					/* xdim */ "dimXY",
					/* ydim */ "dimZ",
					/* zslcDimsN */ {},
					/* zslcIcsN */ {},
					/* zvar */ "Exy_sqr"));
				filenames.push_back(cli->Title + "_Exy_sqr.avi");

			};

			if (sshot) {
				dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dpng(0, 0,
					/* altzmax */ altzmaxEz,
					/* altzmin */ 0.0,
					/* annotColor */ "white",
					/* annotDim */ "",
					/* annotHeight */ 10,
					/* annotPos */ "sw",
					/* annotText */ "|Ez|^2",
					/* ctrzero */ false,
					/* logscale */ false,
					/* refFile */ refFile,
					/* spczlim */ true,
					/* srefDom */ srefDom,
					/* xdim */ "dimXY",
					/* ydim */ "dimZ",
					/* zslcDimsN */ {},
					/* zslcIcsN */ {},
					/* zvar */ "Ez_fnl_sqr"));
				filenames.push_back(cli->Title + "_Ez_sqr.png");

				dpchinvs.push_back(new DpchInvPlnrPlotDomdat2dpng(0, 0,
					/* altzmax */ altzmaxExy,
					/* altzmin */ 0.0,
					/* annotColor */ "white",
					/* annotDim */ "",
					/* annotHeight */ 10,
					/* annotPos */ "sw",
					/* annotText */ "|Exy|^2",
					/* ctrzero */ false,
					/* logscale */ false,
					/* refFile */ refFile,
					/* spczlim */ true,
					/* srefDom */ srefDom,
					/* xdim */ "dimXY",
					/* ydim */ "dimZ",
					/* zslcDimsN */ {},
					/* zslcIcsN */ {},
					/* zvar */ "Exy_fnl_sqr"));
				filenames.push_back(cli->Title + "_Exy_sqr.png");
			};

			delete cli;
		};
	};

	// --- pass to op processors
	addInvs(dpchinvs);

	// prepare collection of plot files in folder	with dtp subfolder
	plotfolder = Tmp::newfolder(xchg->tmppath);

	s = xchg->tmppath + "/" + plotfolder;
#ifdef _WIN32
	mkdir(s.c_str());
#else
	mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	plots.clear();
	for (unsigned int i=0;i<dpchinvs.size();i++) plots[dpchinvs[i]->oref] = filenames[i];

// IP enterSgePlot --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void JobPlnrClcDisptest::leaveSgePlot(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgePlot --- IBEGIN
	// .tgz result (plot) folder
	string s;
	s = "tar -czvf " + xchg->tmppath + "/" + plotfolder + ".tgz -C " + xchg->tmppath + "/" + plotfolder + " .";

	system(s.c_str());
// IP leaveSgePlot --- IEND
};

uint JobPlnrClcDisptest::enterSgeDone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- IBEGIN
	if (reqCmd) {
		reqCmd->setStateReply();
		reqCmd = NULL;
	};
// IP enterSgeDone --- IEND
	return retval;
};

void JobPlnrClcDisptest::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string JobPlnrClcDisptest::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::PREPARE) || (ixVSge == VecVSge::EXPAND1) || (ixVSge == VecVSge::EXPAND2) || (ixVSge == VecVSge::EXPAND3) || (ixVSge == VecVSge::DISCR) || (ixVSge == VecVSge::CALC) || (ixVSge == VecVSge::PLOT) ) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			if (ixVSge == VecVSge::PREPARE) retval = "preparing calculations";
			else if (ixVSge == VecVSge::EXPAND1) retval = "expanding devices and stacks (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::EXPAND2) retval = "expanding base design";
			else if (ixVSge == VecVSge::EXPAND3) retval = "expanding modified designs (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::DISCR) retval = "generating discretizations (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::CALC) retval = "performing calculations (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
			else if (ixVSge == VecVSge::PLOT) retval = "generating plots (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed, last: " + getOpsqkLast() + ")";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- END
	return retval;
};

void JobPlnrClcDisptest::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\trun" << endl;
		} else if (req->cmd.compare("run") == 0) {
			req->retain = handleRun(dbsplnr);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
// IP handleRequest.ret --- RBEGIN
	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::RET) {
		if (ixVSge == VecVSge::PLOT) {
			auto it = plots.find(req->dpchret->oref);
			if (it != plots.end()) {
				string s = "mv " + xchg->tmppath + "/";

				if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNXYSVG) {
					s += ((DpchRetPlnrPlotDsnxysvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNZSVG) {
					s += ((DpchRetPlnrPlotDsnzsvg*) (req->dpchret))->svgfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DPNG) {
					s += ((DpchRetPlnrPlotDomdat2dpng*) (req->dpchret))->pngfile;
				} else if (req->dpchret->ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DVID) {
					s += ((DpchRetPlnrPlotDomdat2dvid*) (req->dpchret))->mpgfile;
				};

				s += " " + xchg->tmppath + "/" + plotfolder + "/" + it->second;
				system(s.c_str());
			};
		};

		opNdone++;

		if (opNdone == opN) {
			clearOps();

			opNdone = 0;
			opN = 0;

			changeStage(dbsplnr, nextIxVSge);
		};
// IP handleRequest.ret --- REND
// IP handleRequest.timer --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::TIMER) {
		handleTimer(dbsplnr, req->sref);
// IP handleRequest.timer --- END
	};
};

bool JobPlnrClcDisptest::handleRun(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
// IP handleRun --- IBEGIN
	// --- set calculation parameters here

	// - default QCD
//	resetPars();

	// -- simple FDTD videos, scan grating period (5x)

	// - NG8X5, InP-based, 8.5µm for ICARUS
	// device geometry parameters
	mesa = 75.0; topmet = false; buf = false; tBuf = 0.0; tBotcont = 0.8; NPrd  = 35; tPrd = 0.0515;
	tTopcont = 0.8; grattype = "half"; gratprd = 8.5/3.18; tGrat = 0.8;
	// material parameters
	matsys = "InP"; kBotcont = 3e-4; nDBotcont = 1.5e17; kTopcont = 1e-3; nDTopcont = 5e17;
	xAR = 0.25; nDAR = 1.5e17; kAR = 3e-5; keAR = 3e-3; cladmat = "Au"; tClad = 1.0;
	// calculation parameters
	calctype = "fdtd"; scantype = "lam";
	scanstart = 1.0*8.5; scanstep = 0.01*8.5; scanmult = 1.0; scanstop = 1.00001 * 1.0*8.5;
	grid = 0.1; lam = 8.5; anisomat = true; lossmat = true;
	// waveguide mode calculation parameters
	te = true; tm = true;
	// FDTD parameters
	illpos = "bottom"; deltalam = 0.0; tstop = 2000.0; corn = false; mon = true; sshot = true;
	armon = false; arsshot = true; peeksshot = true; aspmon = false;

/*
	// - EV1456, GaAs-based, 5.8µm for cocaine spectroscopy
	// device geometry parameters
	mesa = 75.0; topmet = false; buf = false; tBuf = 0.0; tBotcont = 0.5; NPrd  = 50; tPrd = 0.0455;
	tTopcont = 0.1; grattype = "half"; gratprd = 9.5/3.3; tGrat = 0.1;
	// material parameters
	matsys = "GaAs"; kCont = 3.0e-3; nDCont = 1.0e18; xAR = 0.25; nDAR = 1.0e18; kAR = 3.0e-4;
	cladmat = "Air"; tClad = 1.0;
	// calculation parameters
	calctype = "fdtd"; scantype = "lam";
	scanstart = 1.0 * 5.8; scanstep = 0.01 * 5.8; scanmult = 1.0; scanstop = 1.00001 * 5.8;
	grid = 0.06; lam = 5.8; lossmat = true;
	// waveguide mode calculation parameters
	te = true; tm = true;
	// FDTD parameters
	illpos = "top"; deltalam = 0.0; tstop = 4000.0; corn = false; mon = true; sshot = true;
	armon = false; arsshot = true; peeksshot = true; aspmon = false;
*/

	changeStage(dbsplnr, VecVSge::PRPIDLE);
// IP handleRun --- IEND
	return retval;
};

void JobPlnrClcDisptest::handleTimer(
			DbsPlnr* dbsplnr
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRPIDLE) {
		changeStage(dbsplnr, nextIxVSge);
	} else if ((ixVSge == VecVSge::EXPAND1) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.expand1.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.expand1.mon --- IEND
	} else if ((ixVSge == VecVSge::EXPAND2) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.expand2.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.expand2.mon --- IEND
	} else if ((ixVSge == VecVSge::EXPAND3) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.expand3.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.expand3.mon --- IEND
	} else if ((ixVSge == VecVSge::DISCR) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.discr.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.discr.mon --- IEND
	} else if ((ixVSge == VecVSge::CALC) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.calc.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.calc.mon --- IEND
	} else if ((ixVSge == VecVSge::PLOT) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.plot.mon --- IBEGIN
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTATCHG, jref);
// IP handleTimer.plot.mon --- IEND
	};
};


