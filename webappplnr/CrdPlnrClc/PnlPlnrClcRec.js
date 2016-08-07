/**
  * \file PnlPlnrClcRec.js
  * web client functionality for panel PnlPlnrClcRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefDetail");
	scrJrefView = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefView");
	scrJrefAEnv = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefAEnv");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefAPar");
	scrJrefCal1NCalcitem = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefCal1NCalcitem");
	scrJref1NMaterial = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJref1NMaterial");
	scrJrefSup1NCalc = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefSup1NCalc");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefRef1NFile");
	scrJrefMNFile = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefMNFile");
	scrJrefMNDomain = retrieveSi(srcdoc, "StatShrPlnrClcRec", "scrJrefMNDomain");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrClcRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneView", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneAEnv", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneCal1NCalcitem", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdone1NMaterial", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneSup1NCalc", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneMNFile", "false");
	setSi(srcdoc, "StatAppPlnrClcRec", "initdoneMNDomain", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightView = 30;
	heightAEnv = 30;
	heightAPar = 30;
	heightCal1NCalcitem = 30;
	height1NMaterial = 30;
	heightSup1NCalc = 30;
	heightRef1NFile = 30;
	heightMNFile = 30;
	heightMNDomain = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrClcRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneDetail") == "true");
	var initdoneView = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneView") == "true");
	var initdoneAEnv = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneAEnv") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneAPar") == "true");
	var initdoneCal1NCalcitem = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneCal1NCalcitem") == "true");
	var initdone1NMaterial = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdone1NMaterial") == "true");
	var initdoneSup1NCalc = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneSup1NCalc") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneRef1NFile") == "true");
	var initdoneMNFile = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneMNFile") == "true");
	var initdoneMNDomain = (retrieveSi(srcdoc, "StatAppPlnrClcRec", "initdoneMNDomain") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlPlnrClcPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrClcDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneView) {
		lhsdoc.getElementById("View").src = "./PnlPlnrClcView.html?scrJref=" + scrJrefView;
	} else if (!initdoneAEnv) {
		lhsdoc.getElementById("AEnv").src = "./PnlPlnrClcAEnv.html?scrJref=" + scrJrefAEnv;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlPlnrClcAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneCal1NCalcitem) {
		rhsdoc.getElementById("Cal1NCalcitem").src = "./PnlPlnrClcCal1NCalcitem.html?scrJref=" + scrJrefCal1NCalcitem;
	} else if (!initdone1NMaterial) {
		rhsdoc.getElementById("1NMaterial").src = "./PnlPlnrClc1NMaterial.html?scrJref=" + scrJref1NMaterial;
	} else if (!initdoneSup1NCalc) {
		rhsdoc.getElementById("Sup1NCalc").src = "./PnlPlnrClcSup1NCalc.html?scrJref=" + scrJrefSup1NCalc;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlPlnrClcRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNFile) {
		rhsdoc.getElementById("MNFile").src = "./PnlPlnrClcMNFile.html?scrJref=" + scrJrefMNFile;
	} else if (!initdoneMNDomain) {
		rhsdoc.getElementById("MNDomain").src = "./PnlPlnrClcMNDomain.html?scrJref=" + scrJrefMNDomain;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "View") || (short == "AEnv") || (short == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Pre") heightPre = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "View") heightView = height;
		else if (short == "AEnv") heightAEnv = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Cal1NCalcitem") heightCal1NCalcitem = height;
		else if (short == "1NMaterial") height1NMaterial = height;
		else if (short == "Sup1NCalc") heightSup1NCalc = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNFile") heightMNFile = height;
		else if (short == "MNDomain") heightMNDomain = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlPlnrClcRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrClcRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 309);
	doc.getElementById("tdSide").setAttribute("height", "309");
	doc.getElementById("Rec_side").setAttribute("height", "309");
	doc.getElementById("Rec_cont").setAttribute("height", "309");

	doc.getElementById("Rec_side").src = "./PnlPlnrClcRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrClcRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "View") || (pnlshort == "AEnv") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "View") heightView = height;
	else if (pnlshort == "AEnv") heightAEnv = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Cal1NCalcitem") heightCal1NCalcitem = height;
	else if (pnlshort == "1NMaterial") height1NMaterial = height;
	else if (pnlshort == "Sup1NCalc") heightSup1NCalc = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNFile") heightMNFile = height;
	else if (pnlshort == "MNDomain") heightMNDomain = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightView+13 + heightAEnv+13 + heightAPar+13 + 5;
	heightRhs = heightCal1NCalcitem+13 + height1NMaterial+13 + heightSup1NCalc+13 + heightRef1NFile+13 + heightMNFile+13 + heightMNDomain+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrClcRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrClcRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrClcRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrClcRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrClcRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxPlnrVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrClcRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrClcRecData", "ContInfPlnrClcRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrClcRecData", "StatAppPlnrClcRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrClcRecData", "StatShrPlnrClcRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrClcRecData", "TagPlnrClcRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrClcRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

				if (newSrefIxPlnrVExpstate != srefIxPlnrVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxPlnrVExpstate == "mind") {
						minimize();
					} else if (newSrefIxPlnrVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxPlnrVExpstate != "mind") {
			if (_scrJref == scrJrefPre) {
				lhsdoc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefView) {
				lhsdoc.getElementById("View").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAEnv) {
				lhsdoc.getElementById("AEnv").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCal1NCalcitem) {
				rhsdoc.getElementById("Cal1NCalcitem").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NMaterial) {
				rhsdoc.getElementById("1NMaterial").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NCalc) {
				rhsdoc.getElementById("Sup1NCalc").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFile) {
				rhsdoc.getElementById("MNFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNDomain) {
				rhsdoc.getElementById("MNDomain").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrClcRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngPlnrClcRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrClcRec", "srefIxPlnrVExpstate");

					if (newSrefIxPlnrVExpstate != srefIxPlnrVExpstate) {
						updateScrJrefs();

						if (newSrefIxPlnrVExpstate == "mind") {
							minimize();
						} else if (newSrefIxPlnrVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};


