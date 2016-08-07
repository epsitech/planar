/**
  * \file DlgPlnrNavLoaini.cpp
  * job handler for job DlgPlnrNavLoaini (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "DlgPlnrNavLoaini.h"

// IP blksInclude --- BEGIN
#include "DlgPlnrNavLoaini_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "DlgPlnrNavLoaini_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class DlgPlnrNavLoaini
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
DlgPlnrNavLoaini::DlgPlnrNavLoaini(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::DLGPLNRNAVLOAINI, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixPlnrVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	muteRefresh = false;

	iex = new IexPlnrIni(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbsplnr, moditems);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

DlgPlnrNavLoaini::~DlgPlnrNavLoaini() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* DlgPlnrNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continfppr, &feedFDse, &feedFSge, &statshr, &statshracv, &statshrifi, &statshrimp, &statshrlfi, &statshrppr, items);
	};

	return dpcheng;
};

void DlgPlnrNavLoaini::refreshIfi(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbsplnr);

// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgPlnrNavLoaini::refreshImp(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInfImp oldContinfimp(continfimp);
	StatShrImp oldStatshrimp(statshrimp);

// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbsplnr);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbsplnr);
	statshrimp.ButStoActive = evalImpButStoActive(dbsplnr);

// IP refreshImp --- REND
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
};

void DlgPlnrNavLoaini::refreshAcv(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShrAcv oldStatshracv(statshracv);

// IP refreshAcv --- BEGIN
	// statshracv
	statshracv.UldActive = evalAcvUldActive(dbsplnr);

// IP refreshAcv --- END
	if (statshracv.diff(&oldStatshracv).size() != 0) insert(moditems, DpchEngData::STATSHRACV);
};

void DlgPlnrNavLoaini::refreshPpr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInfPpr oldContinfppr(continfppr);
	StatShrPpr oldStatshrppr(statshrppr);

// IP refreshPpr --- RBEGIN
	// continfppr
	continfppr.TxtPrg = getSquawk(dbsplnr);

	// statshrppr
	statshrppr.ButRunActive = evalPprButRunActive(dbsplnr);
	statshrppr.ButStoActive = evalPprButStoActive(dbsplnr);

// IP refreshPpr --- REND
	if (continfppr.diff(&oldContinfppr).size() != 0) insert(moditems, DpchEngData::CONTINFPPR);
	if (statshrppr.diff(&oldStatshrppr).size() != 0) insert(moditems, DpchEngData::STATSHRPPR);
};

void DlgPlnrNavLoaini::refreshLfi(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);

// IP refreshLfi --- BEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbsplnr);

// IP refreshLfi --- END
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
};

void DlgPlnrNavLoaini::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	ContIac oldContiac(contiac);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.numFSge = ixVSge;

	// contiac
	contiac.numFDse = ixVDit;

	// statshr
	statshr.ButDneActive = evalButDneActive(dbsplnr);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshIfi(dbsplnr, moditems);
	refreshImp(dbsplnr, moditems);
	refreshAcv(dbsplnr, moditems);
	refreshPpr(dbsplnr, moditems);
	refreshLfi(dbsplnr, moditems);
};

// IP changeStage --- BEGIN
// IP dpchchangeStage.hdr --- BEGIN
void DlgPlnrNavLoaini::changeStage(
			DbsPlnr* dbsplnr
			, uint _ixVSge
			, DpchEngPlnr** dpcheng
		) {
// IP dpchchangeStage.hdr --- END
	while (ixVSge != _ixVSge) {
		switch (ixVSge) {
			case VecVSge::IDLE: leaveSgeIdle(dbsplnr); break;
			case VecVSge::PRSIDLE: leaveSgePrsidle(dbsplnr); break;
			case VecVSge::PARSE: leaveSgeParse(dbsplnr); break;
			case VecVSge::ALRPLNRPER: leaveSgeAlrplnrper(dbsplnr); break;
			case VecVSge::PRSDONE: leaveSgePrsdone(dbsplnr); break;
			case VecVSge::IMPIDLE: leaveSgeImpidle(dbsplnr); break;
			case VecVSge::IMPORT: leaveSgeImport(dbsplnr); break;
			case VecVSge::IMPDONE: leaveSgeImpdone(dbsplnr); break;
			case VecVSge::UPKIDLE: leaveSgeUpkidle(dbsplnr); break;
			case VecVSge::UNPACK: leaveSgeUnpack(dbsplnr); break;
			case VecVSge::UPKDONE: leaveSgeUpkdone(dbsplnr); break;
			case VecVSge::POSTPRC: leaveSgePostprc(dbsplnr); break;
			case VecVSge::DONE: leaveSgeDone(dbsplnr); break;
		};

		ixVSge = _ixVSge;
// IP changeStage.refresh --- IBEGIN
		set<uint> moditems;
		refresh(dbsplnr, moditems);
		
		if (dpcheng) {
			if (*dpcheng) delete *dpcheng;
			*dpcheng = getNewDpchEng(moditems);
		} else xchg->submitDpch(getNewDpchEng(moditems));
// IP changeStage.refresh --- IEND

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbsplnr); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbsplnr); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbsplnr); break;
			case VecVSge::ALRPLNRPER: _ixVSge = enterSgeAlrplnrper(dbsplnr); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbsplnr); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbsplnr); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbsplnr); break;
			case VecVSge::IMPDONE: _ixVSge = enterSgeImpdone(dbsplnr); break;
			case VecVSge::UPKIDLE: _ixVSge = enterSgeUpkidle(dbsplnr); break;
			case VecVSge::UNPACK: _ixVSge = enterSgeUnpack(dbsplnr); break;
			case VecVSge::UPKDONE: _ixVSge = enterSgeUpkdone(dbsplnr); break;
			case VecVSge::POSTPRC: _ixVSge = enterSgePostprc(dbsplnr); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbsplnr); break;
		};
	};
};
// IP changeStage --- END

uint DlgPlnrNavLoaini::enterSgeIdle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IDLE;
	nextIxVSge = retval;
// IP enterSgeIdle --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeIdle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeIdle --- INSERT
};

uint DlgPlnrNavLoaini::enterSgePrsidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSge = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgePrsidle --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgePrsidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgePrsidle --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeParse(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PARSE;
	nextIxVSge = retval;
// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	bool success;

	iex->reset();

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	success = false;

	if (ifitxt) success = iex->readTxtFile(infilename);
	else if (ifixml) success = iex->readXMLFile(infilename);

	if (success) {
		retval = VecVSge::PRSDONE;
	} else {
		if (reqCmd) {
			cout << "\tparse error at line " << iex->lineno << endl;
			retval = VecVSge::IDLE;
		} else {
			retval = VecVSge::ALRPLNRPER;
		};
	};
// IP enterSgeParse --- IEND
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeParse(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeParse --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeAlrplnrper(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::ALRPLNRPER;
	nextIxVSge = VecVSge::IDLE;
// IP enterSgeAlrplnrper --- RBEGIN
	xchg->submitDpch(AlrPlnr::prepareAlrPer(jref, ixPlnrVLocale, to_string(iex->lineno), feedFMcbAlert));
// IP enterSgeAlrplnrper --- REND
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeAlrplnrper(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeAlrplnrper --- INSERT
};

uint DlgPlnrNavLoaini::enterSgePrsdone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::PRSDONE;
	nextIxVSge = retval;
// IP enterSgePrsdone --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgePrsdone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgePrsdone --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeImpidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSge = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeImpidle --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeImpidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeImpidle --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeImport(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IMPORT;
	nextIxVSge = VecVSge::IMPDONE;

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgeImport --- IBEGIN
	iex->import(dbsplnr);
// IP enterSgeImport --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeImport(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgeImport --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeImpdone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::IMPDONE;
	nextIxVSge = retval;
// IP enterSgeImpdone --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeImpdone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeImpdone --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeUpkidle(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::UPKIDLE;
	nextIxVSge = VecVSge::UNPACK;

	wrefLast = xchg->addWakeup(jref, "callback", 0);
// IP enterSgeUpkidle --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeUpkidle(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeUpkidle --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeUnpack(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::UNPACK;
	nextIxVSge = VecVSge::UPKDONE;
// IP enterSgeUnpack --- IBEGIN
	ubigint ref;

	DIR* dir = NULL;
	dirent* diritem = NULL;

	string s;

	// collect refs of newly imported files
	dbsplnr->tblplnrqselect->removeRstByJref(jref);
	for (unsigned int ix0=0;ix0<iex->imeimfile.nodes.size();ix0++) dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, 0, 0, iex->imeimfile.nodes[ix0]->ref);

	// handle archive file containing many (or all) files
	s = "mv " + infilename + " " + infilename + ".tgz";
	system(s.c_str());

#ifdef _WIN32
	mkdir(infilename.c_str());
#else
	mkdir(infilename.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// unpack
	s = "tar xzvf " + infilename + ".tgz -C " + infilename;
	system(s.c_str());

	// traverse directory and match each single file to import
	dir = opendir(infilename.c_str());

	if (dir) {
		// traverse directory
		diritem = readdir(dir);
		while (diritem) {

			if (diritem->d_type == DT_REG) {
				// file: try to match
				ref = 0;

				dbsplnr->loadUbigintBySQL("SELECT TblPlnrMFile.ref FROM TblPlnrQSelect, TblPlnrMFile WHERE TblPlnrQSelect.jref = " + to_string(jref)
							+ " AND TblPlnrMFile.ref = TblPlnrQSelect.ref AND TblPlnrMFile.Filename = '" + diritem->d_name + "'", ref);

				if (ref != 0) {
					Acv::alterfile(dbsplnr, xchg->acvpath, infilename + "/" + diritem->d_name, ref);
					if (reqCmd) cout << "updated file '" << diritem->d_name << "'" << endl;
				};

			} else {
				// something else: do nothing
			};

			diritem = readdir(dir);
		};

		closedir(dir);
	};
// IP enterSgeUnpack --- IEND
	retval = nextIxVSge;
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeUnpack(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeUnpack --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeUpkdone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::UPKDONE;
	nextIxVSge = retval;
// IP enterSgeUpkdone --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeUpkdone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeUpkdone --- INSERT
};

uint DlgPlnrNavLoaini::enterSgePostprc(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::POSTPRC;
	nextIxVSge = VecVSge::DONE;

	clearInvs();

	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP enterSgePostprc --- IBEGIN
	vector<DpchInvPlnr*> dpchinvs;

	map<string, ubigint> refsDtp;

	Plnr::getRefsDtp(dbsplnr, refsDtp);
	PlnrExp_blks::getInvs(dbsplnr, refsDtp, 0, dpchinvs);

	addInvs(dpchinvs);
// IP enterSgePostprc --- IEND
	submitInvs(dbsplnr, VecVSge::DONE, retval);
	return retval;
};

void DlgPlnrNavLoaini::leaveSgePostprc(
			DbsPlnr* dbsplnr
		) {
	invalidateWakeups();
// IP leaveSgePostprc --- INSERT
};

uint DlgPlnrNavLoaini::enterSgeDone(
			DbsPlnr* dbsplnr
		) {
	uint retval = VecVSge::DONE;
	nextIxVSge = retval;
// IP enterSgeDone --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::leaveSgeDone(
			DbsPlnr* dbsplnr
		) {
// IP leaveSgeDone --- INSERT
};

string DlgPlnrNavLoaini::getSquawk(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRPLNRPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::IMPDONE) || (ixVSge == VecVSge::UNPACK) || (ixVSge == VecVSge::UPKDONE) || (ixVSge == VecVSge::POSTPRC) ) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRPLNRPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::IMPDONE) retval = "import done";
			else if (ixVSge == VecVSge::UNPACK) retval = "unpacking inizialization files";
			else if (ixVSge == VecVSge::UPKDONE) retval = "initialization files unpacked";
			else if (ixVSge == VecVSge::POSTPRC) retval = "expanding device templates (" + to_string(opNdone) + "/" + to_string(opN) + " operations completed)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
// IP getSquawk --- REND
	return retval;
};

void DlgPlnrNavLoaini::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRINIT) {
			handleDpchAppPlnrInit(dbsplnr, (DpchAppPlnrInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbsplnr, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbsplnr, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoPpr != 0) {
				if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTRUNCLICK) {
					handleDpchAppDoPprButRunClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDoPpr == VecVDoPpr::BUTSTOCLICK) {
					handleDpchAppDoPprButStoClick(dbsplnr, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRALERT) {
			handleDpchAppPlnrAlert(dbsplnr, (DpchAppPlnrAlert*) (req->dpchapp), &(req->dpcheng));

		};
// IP handleRequest.upload --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::UPLOAD) {
		handleUpload(dbsplnr, req->filename);
// IP handleRequest.upload --- END
// IP handleRequest.download --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbsplnr);
// IP handleRequest.download --- END
// IP handleRequest.ret --- BEGIN
	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::RET) {
		opNdone++;

		if (opNdone == opN) {
			clearOps();

			opNdone = 0;
			opN = 0;

			changeStage(dbsplnr, nextIxVSge);
		};
// IP handleRequest.ret --- END
// IP handleRequest.timer --- BEGIN

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::TIMER) {
		handleTimer(dbsplnr, req->sref);
// IP handleRequest.timer --- END
	};
};

void DlgPlnrNavLoaini::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgPlnrNavLoaini::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgPlnrNavLoaini::handleDpchAppDoButDneClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButDneClick --- IBEGIN
	*dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRDLGCLOSE, jref);
// IP handleDpchAppDoButDneClick --- IEND
};

void DlgPlnrNavLoaini::handleDpchAppDoImpButRunClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		if (ixVSge == VecVSge::PRSDONE) {
			changeStage(dbsplnr, VecVSge::IMPIDLE, dpcheng);
		};
	};
// IP handleDpchAppDoImpButRunClick --- END
};

void DlgPlnrNavLoaini::handleDpchAppDoImpButStoClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgPlnrNavLoaini::handleDpchAppDoPprButRunClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoPprButRunClick --- BEGIN
	if (statshrppr.ButRunActive) {
		if (ixVSge == VecVSge::UPKDONE) {
			changeStage(dbsplnr, VecVSge::POSTPRC, dpcheng);
		};
	};
// IP handleDpchAppDoPprButRunClick --- END
};

void DlgPlnrNavLoaini::handleDpchAppDoPprButStoClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoPprButStoClick --- INSERT
};

void DlgPlnrNavLoaini::handleDpchAppPlnrAlert(
			DbsPlnr* dbsplnr
			, DpchAppPlnrAlert* dpchappplnralert
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppPlnrAlert --- INSERT
};

void DlgPlnrNavLoaini::handleUpload(
			DbsPlnr* dbsplnr
			, const string& filename
		) {
// IP handleUpload --- BEGIN
	if (ixVSge == VecVSge::IDLE) {
// IP handleUpload.prsidle --- IBEGIN
		infilename = filename;
// IP handleUpload.prsidle --- IEND
		changeStage(dbsplnr, VecVSge::PRSIDLE);
	} else if (ixVSge == VecVSge::IMPDONE) {
// IP handleUpload.upkidle --- IBEGIN
		infilename = filename;
// IP handleUpload.upkidle --- IEND
		changeStage(dbsplnr, VecVSge::UPKIDLE);
	};
// IP handleUpload --- END
};

string DlgPlnrNavLoaini::handleDownload(
			DbsPlnr* dbsplnr
		) {
	string retval;
// IP handleDownload --- INSERT
	return retval;
};

void DlgPlnrNavLoaini::handleTimer(
			DbsPlnr* dbsplnr
			, const string& sref
		) {
	if (ixVSge == VecVSge::PRSIDLE) {
		changeStage(dbsplnr, nextIxVSge);
	} else if (ixVSge == VecVSge::IMPIDLE) {
		changeStage(dbsplnr, nextIxVSge);
	} else if ((ixVSge == VecVSge::IMPORT) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.import.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsplnr, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
// IP handleTimer.import.mon --- IEND
	} else if (ixVSge == VecVSge::UPKIDLE) {
		changeStage(dbsplnr, nextIxVSge);
	} else if ((ixVSge == VecVSge::POSTPRC) && (sref.compare("mon") == 0)) {
		wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
// IP handleTimer.postprc.mon --- IBEGIN
		set<uint> moditems;
		refresh(dbsplnr, moditems);
		xchg->submitDpch(getNewDpchEng(moditems));
// IP handleTimer.postprc.mon --- IEND
	};
};


