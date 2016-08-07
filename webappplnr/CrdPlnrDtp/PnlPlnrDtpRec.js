/**
  * \file PnlPlnrDtpRec.js
  * web client functionality for panel PnlPlnrDtpRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefDetail");
	scrJrefView = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefView");
	scrJrefKParKey = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefKParKey");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefAPar");
	scrJrefSup1NDevice = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefSup1NDevice");
	scrJrefHk1NStructure = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefHk1NStructure");
	scrJrefTpl1NDevice = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "scrJrefTpl1NDevice");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneView", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneKParKey", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneSup1NDevice", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneHk1NStructure", "false");
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdoneTpl1NDevice", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightView = 30;
	heightKParKey = 30;
	heightAPar = 30;
	heightSup1NDevice = 30;
	heightHk1NStructure = 30;
	heightTpl1NDevice = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrDtpRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneDetail") == "true");
	var initdoneView = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneView") == "true");
	var initdoneKParKey = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneKParKey") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneAPar") == "true");
	var initdoneSup1NDevice = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneSup1NDevice") == "true");
	var initdoneHk1NStructure = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneHk1NStructure") == "true");
	var initdoneTpl1NDevice = (retrieveSi(srcdoc, "StatAppPlnrDtpRec", "initdoneTpl1NDevice") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlPlnrDtpPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrDtpDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneView) {
		lhsdoc.getElementById("View").src = "./PnlPlnrDtpView.html?scrJref=" + scrJrefView;
	} else if (!initdoneKParKey) {
		lhsdoc.getElementById("KParKey").src = "./PnlPlnrDtpKParKey.html?scrJref=" + scrJrefKParKey;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlPlnrDtpAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneSup1NDevice) {
		rhsdoc.getElementById("Sup1NDevice").src = "./PnlPlnrDtpSup1NDevice.html?scrJref=" + scrJrefSup1NDevice;
	} else if (!initdoneHk1NStructure) {
		rhsdoc.getElementById("Hk1NStructure").src = "./PnlPlnrDtpHk1NStructure.html?scrJref=" + scrJrefHk1NStructure;
	} else if (!initdoneTpl1NDevice) {
		rhsdoc.getElementById("Tpl1NDevice").src = "./PnlPlnrDtpTpl1NDevice.html?scrJref=" + scrJrefTpl1NDevice;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "View") || (short == "KParKey") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KParKey") heightKParKey = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Sup1NDevice") heightSup1NDevice = height;
		else if (short == "Hk1NStructure") heightHk1NStructure = height;
		else if (short == "Tpl1NDevice") heightTpl1NDevice = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrDtpRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDtpRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlPlnrDtpRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDtpRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "View") || (pnlshort == "KParKey") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "View") heightView = height;
	else if (pnlshort == "KParKey") heightKParKey = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Sup1NDevice") heightSup1NDevice = height;
	else if (pnlshort == "Hk1NStructure") heightHk1NStructure = height;
	else if (pnlshort == "Tpl1NDevice") heightTpl1NDevice = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightView+13 + heightKParKey+13 + heightAPar+13 + 5;
	heightRhs = heightSup1NDevice+13 + heightHk1NStructure+13 + heightTpl1NDevice+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDtpRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDtpRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrDtpRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDtpRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDtpRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDtpRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDtpRecData", "ContInfPlnrDtpRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDtpRecData", "StatAppPlnrDtpRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDtpRecData", "StatShrPlnrDtpRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDtpRecData", "TagPlnrDtpRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrDtpRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJrefKParKey) {
				lhsdoc.getElementById("KParKey").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NDevice) {
				rhsdoc.getElementById("Sup1NDevice").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NStructure) {
				rhsdoc.getElementById("Hk1NStructure").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTpl1NDevice) {
				rhsdoc.getElementById("Tpl1NDevice").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrDtpRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDtpRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDtpRec", "srefIxPlnrVExpstate");

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


