/**
  * \file PnlPlnrCtpRec.js
  * web client functionality for panel PnlPlnrCtpRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefDetail");
	scrJrefKEnvKey = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefKEnvKey");
	scrJrefKParCat = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefKParCat");
	scrJrefKParProp = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefKParProp");
	scrJrefKCalcdomprp = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefKCalcdomprp");
	scrJrefKCalcvar = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefKCalcvar");
	scrJrefAEnv = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefAEnv");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefAPar");
	scrJrefSup1NCalc = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefSup1NCalc");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefRef1NFile");
	scrJrefTpl1NCalc = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "scrJrefTpl1NCalc");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKEnvKey", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKParCat", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKParProp", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKCalcdomprp", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKCalcvar", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneAEnv", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneSup1NCalc", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdoneTpl1NCalc", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKEnvKey = 30;
	heightKParCat = 30;
	heightKParProp = 30;
	heightKCalcdomprp = 30;
	heightKCalcvar = 30;
	heightAEnv = 30;
	heightAPar = 30;
	heightSup1NCalc = 30;
	heightRef1NFile = 30;
	heightTpl1NCalc = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrCtpRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneDetail") == "true");
	var initdoneKEnvKey = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKEnvKey") == "true");
	var initdoneKParCat = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKParCat") == "true");
	var initdoneKParProp = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKParProp") == "true");
	var initdoneKCalcdomprp = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKCalcdomprp") == "true");
	var initdoneKCalcvar = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneKCalcvar") == "true");
	var initdoneAEnv = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneAEnv") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneAPar") == "true");
	var initdoneSup1NCalc = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneSup1NCalc") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneRef1NFile") == "true");
	var initdoneTpl1NCalc = (retrieveSi(srcdoc, "StatAppPlnrCtpRec", "initdoneTpl1NCalc") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrCtpDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKEnvKey) {
		lhsdoc.getElementById("KEnvKey").src = "./PnlPlnrCtpKEnvKey.html?scrJref=" + scrJrefKEnvKey;
	} else if (!initdoneKParCat) {
		lhsdoc.getElementById("KParCat").src = "./PnlPlnrCtpKParCat.html?scrJref=" + scrJrefKParCat;
	} else if (!initdoneKParProp) {
		lhsdoc.getElementById("KParProp").src = "./PnlPlnrCtpKParProp.html?scrJref=" + scrJrefKParProp;
	} else if (!initdoneKCalcdomprp) {
		lhsdoc.getElementById("KCalcdomprp").src = "./PnlPlnrCtpKCalcdomprp.html?scrJref=" + scrJrefKCalcdomprp;
	} else if (!initdoneKCalcvar) {
		lhsdoc.getElementById("KCalcvar").src = "./PnlPlnrCtpKCalcvar.html?scrJref=" + scrJrefKCalcvar;
	} else if (!initdoneAEnv) {
		lhsdoc.getElementById("AEnv").src = "./PnlPlnrCtpAEnv.html?scrJref=" + scrJrefAEnv;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlPlnrCtpAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneSup1NCalc) {
		rhsdoc.getElementById("Sup1NCalc").src = "./PnlPlnrCtpSup1NCalc.html?scrJref=" + scrJrefSup1NCalc;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlPlnrCtpRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneTpl1NCalc) {
		rhsdoc.getElementById("Tpl1NCalc").src = "./PnlPlnrCtpTpl1NCalc.html?scrJref=" + scrJrefTpl1NCalc;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KEnvKey") || (short == "KParCat") || (short == "KParProp") || (short == "KCalcdomprp") || (short == "KCalcvar") || (short == "AEnv") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Detail") heightDetail = height;
		else if (short == "KEnvKey") heightKEnvKey = height;
		else if (short == "KParCat") heightKParCat = height;
		else if (short == "KParProp") heightKParProp = height;
		else if (short == "KCalcdomprp") heightKCalcdomprp = height;
		else if (short == "KCalcvar") heightKCalcvar = height;
		else if (short == "AEnv") heightAEnv = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Sup1NCalc") heightSup1NCalc = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "Tpl1NCalc") heightTpl1NCalc = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrCtpRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrCtpRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 395);
	doc.getElementById("tdSide").setAttribute("height", "395");
	doc.getElementById("Rec_side").setAttribute("height", "395");
	doc.getElementById("Rec_cont").setAttribute("height", "395");

	doc.getElementById("Rec_side").src = "./PnlPlnrCtpRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrCtpRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KEnvKey") || (pnlshort == "KParCat") || (pnlshort == "KParProp") || (pnlshort == "KCalcdomprp") || (pnlshort == "KCalcvar") || (pnlshort == "AEnv") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KEnvKey") heightKEnvKey = height;
	else if (pnlshort == "KParCat") heightKParCat = height;
	else if (pnlshort == "KParProp") heightKParProp = height;
	else if (pnlshort == "KCalcdomprp") heightKCalcdomprp = height;
	else if (pnlshort == "KCalcvar") heightKCalcvar = height;
	else if (pnlshort == "AEnv") heightAEnv = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Sup1NCalc") heightSup1NCalc = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "Tpl1NCalc") heightTpl1NCalc = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKEnvKey+13 + heightKParCat+13 + heightKParProp+13 + heightKCalcdomprp+13 + heightKCalcvar+13 + heightAEnv+13 + heightAPar+13 + 5;
	heightRhs = heightSup1NCalc+13 + heightRef1NFile+13 + heightTpl1NCalc+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrCtpRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrCtpRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrCtpRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrCtpRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrCtpRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrCtpRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrCtpRecData", "ContInfPlnrCtpRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrCtpRecData", "StatAppPlnrCtpRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrCtpRecData", "StatShrPlnrCtpRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrCtpRecData", "TagPlnrCtpRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrCtpRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

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
			if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKEnvKey) {
				lhsdoc.getElementById("KEnvKey").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKParCat) {
				lhsdoc.getElementById("KParCat").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKParProp) {
				lhsdoc.getElementById("KParProp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKCalcdomprp) {
				lhsdoc.getElementById("KCalcdomprp").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKCalcvar) {
				lhsdoc.getElementById("KCalcvar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAEnv) {
				lhsdoc.getElementById("AEnv").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NCalc) {
				rhsdoc.getElementById("Sup1NCalc").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTpl1NCalc) {
				rhsdoc.getElementById("Tpl1NCalc").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrCtpRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrCtpRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrCtpRec", "srefIxPlnrVExpstate");

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


