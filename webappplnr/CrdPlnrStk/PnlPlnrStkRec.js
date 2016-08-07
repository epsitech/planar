/**
  * \file PnlPlnrStkRec.js
  * web client functionality for panel PnlPlnrStkRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefDetail");
	scrJrefView = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefView");
	scrJrefHk1NLevel = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefHk1NLevel");
	scrJrefHk1NLayer = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefHk1NLayer");
	scrJrefMNStructure = retrieveSi(srcdoc, "StatShrPlnrStkRec", "scrJrefMNStructure");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrStkRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppPlnrStkRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrStkRec", "initdoneView", "false");
	setSi(srcdoc, "StatAppPlnrStkRec", "initdoneHk1NLevel", "false");
	setSi(srcdoc, "StatAppPlnrStkRec", "initdoneHk1NLayer", "false");
	setSi(srcdoc, "StatAppPlnrStkRec", "initdoneMNStructure", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightView = 30;
	heightHk1NLevel = 30;
	heightHk1NLayer = 30;
	heightMNStructure = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrStkRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneDetail") == "true");
	var initdoneView = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneView") == "true");
	var initdoneHk1NLevel = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneHk1NLevel") == "true");
	var initdoneHk1NLayer = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneHk1NLayer") == "true");
	var initdoneMNStructure = (retrieveSi(srcdoc, "StatAppPlnrStkRec", "initdoneMNStructure") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlPlnrStkPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrStkDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneView) {
		lhsdoc.getElementById("View").src = "./PnlPlnrStkView.html?scrJref=" + scrJrefView;
	} else if (!initdoneHk1NLevel) {
		rhsdoc.getElementById("Hk1NLevel").src = "./PnlPlnrStkHk1NLevel.html?scrJref=" + scrJrefHk1NLevel;
	} else if (!initdoneHk1NLayer) {
		rhsdoc.getElementById("Hk1NLayer").src = "./PnlPlnrStkHk1NLayer.html?scrJref=" + scrJrefHk1NLayer;
	} else if (!initdoneMNStructure) {
		rhsdoc.getElementById("MNStructure").src = "./PnlPlnrStkMNStructure.html?scrJref=" + scrJrefMNStructure;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "View")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Hk1NLevel") heightHk1NLevel = height;
		else if (short == "Hk1NLayer") heightHk1NLayer = height;
		else if (short == "MNStructure") heightMNStructure = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrStkRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrStkRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlPlnrStkRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrStkRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "View")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "View") heightView = height;
	else if (pnlshort == "Hk1NLevel") heightHk1NLevel = height;
	else if (pnlshort == "Hk1NLayer") heightHk1NLayer = height;
	else if (pnlshort == "MNStructure") heightMNStructure = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightView+13 + 5;
	heightRhs = heightHk1NLevel+13 + heightHk1NLayer+13 + heightMNStructure+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrStkRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrStkRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrStkRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrStkRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlmnstructureAvail = (retrieveSi(srcdoc, "StatShrPlnrStkRec", "pnlmnstructureAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrStkRec", "TxtRef"));

	if (setPnlAvail("MNStructure", pnlmnstructureAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrStkRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrStkRecData", "ContInfPlnrStkRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrStkRecData", "StatAppPlnrStkRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrStkRecData", "StatShrPlnrStkRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrStkRecData", "TagPlnrStkRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrStkRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJrefHk1NLevel) {
				rhsdoc.getElementById("Hk1NLevel").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NLayer) {
				rhsdoc.getElementById("Hk1NLayer").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNStructure) {
				rhsdoc.getElementById("MNStructure").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrStkRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrStkRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrStkRec", "srefIxPlnrVExpstate");

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


