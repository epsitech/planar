/**
  * \file PnlPlnrSruRec.js
  * web client functionality for panel PnlPlnrSruRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrSruRec", "scrJrefDetail");
	scrJref1NBlock = retrieveSi(srcdoc, "StatShrPlnrSruRec", "scrJref1NBlock");
	scrJrefSru1NFace = retrieveSi(srcdoc, "StatShrPlnrSruRec", "scrJrefSru1NFace");
	scrJrefMNLayer = retrieveSi(srcdoc, "StatShrPlnrSruRec", "scrJrefMNLayer");
	scrJrefMNStack = retrieveSi(srcdoc, "StatShrPlnrSruRec", "scrJrefMNStack");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrSruRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrSruRec", "initdone1NBlock", "false");
	setSi(srcdoc, "StatAppPlnrSruRec", "initdoneSru1NFace", "false");
	setSi(srcdoc, "StatAppPlnrSruRec", "initdoneMNLayer", "false");
	setSi(srcdoc, "StatAppPlnrSruRec", "initdoneMNStack", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NBlock = 30;
	heightSru1NFace = 30;
	heightMNLayer = 30;
	heightMNStack = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrSruRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneDetail") == "true");
	var initdone1NBlock = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdone1NBlock") == "true");
	var initdoneSru1NFace = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneSru1NFace") == "true");
	var initdoneMNLayer = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneMNLayer") == "true");
	var initdoneMNStack = (retrieveSi(srcdoc, "StatAppPlnrSruRec", "initdoneMNStack") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrSruDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NBlock) {
		rhsdoc.getElementById("1NBlock").src = "./PnlPlnrSru1NBlock.html?scrJref=" + scrJref1NBlock;
	} else if (!initdoneSru1NFace) {
		rhsdoc.getElementById("Sru1NFace").src = "./PnlPlnrSruSru1NFace.html?scrJref=" + scrJrefSru1NFace;
	} else if (!initdoneMNLayer) {
		rhsdoc.getElementById("MNLayer").src = "./PnlPlnrSruMNLayer.html?scrJref=" + scrJrefMNLayer;
	} else if (!initdoneMNStack) {
		rhsdoc.getElementById("MNStack").src = "./PnlPlnrSruMNStack.html?scrJref=" + scrJrefMNStack;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "1NBlock") height1NBlock = height;
		else if (short == "Sru1NFace") heightSru1NFace = height;
		else if (short == "MNLayer") heightMNLayer = height;
		else if (short == "MNStack") heightMNStack = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrSruRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrSruRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 223);
	doc.getElementById("tdSide").setAttribute("height", "223");
	doc.getElementById("Rec_side").setAttribute("height", "223");
	doc.getElementById("Rec_cont").setAttribute("height", "223");

	doc.getElementById("Rec_side").src = "./PnlPlnrSruRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrSruRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "1NBlock") height1NBlock = height;
	else if (pnlshort == "Sru1NFace") heightSru1NFace = height;
	else if (pnlshort == "MNLayer") heightMNLayer = height;
	else if (pnlshort == "MNStack") heightMNStack = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NBlock+13 + heightSru1NFace+13 + heightMNLayer+13 + heightMNStack+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrSruRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrSruRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrSruRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrSruRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnl1nblockAvail = (retrieveSi(srcdoc, "StatShrPlnrSruRec", "pnl1nblockAvail") == "true");
	var pnlmnlayerAvail = (retrieveSi(srcdoc, "StatShrPlnrSruRec", "pnlmnlayerAvail") == "true");
	var pnlmnstackAvail = (retrieveSi(srcdoc, "StatShrPlnrSruRec", "pnlmnstackAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrSruRec", "TxtRef"));

	if (setPnlAvail("1NBlock", pnl1nblockAvail)) updh = true;
	if (setPnlAvail("MNLayer", pnlmnlayerAvail)) updh = true;
	if (setPnlAvail("MNStack", pnlmnstackAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrSruRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrSruRecData", "ContInfPlnrSruRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrSruRecData", "StatAppPlnrSruRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrSruRecData", "StatShrPlnrSruRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrSruRecData", "TagPlnrSruRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrSruRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJref1NBlock) {
				rhsdoc.getElementById("1NBlock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSru1NFace) {
				rhsdoc.getElementById("Sru1NFace").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLayer) {
				rhsdoc.getElementById("MNLayer").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNStack) {
				rhsdoc.getElementById("MNStack").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrSruRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrSruRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrSruRec", "srefIxPlnrVExpstate");

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


