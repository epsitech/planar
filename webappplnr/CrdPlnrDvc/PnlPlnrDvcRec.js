/**
  * \file PnlPlnrDvcRec.js
  * web client functionality for panel PnlPlnrDvcRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefDetail");
	scrJrefView = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefView");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefAPar");
	scrJrefSup1NDevice = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefSup1NDevice");
	scrJrefHk1NStructure = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefHk1NStructure");
	scrJrefHk1NVertex = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefHk1NVertex");
	scrJrefHk1NLineguide = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefHk1NLineguide");
	scrJrefHk1NArcguide = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "scrJrefHk1NArcguide");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneView", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneSup1NDevice", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NStructure", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NVertex", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NLineguide", "false");
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NArcguide", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightView = 30;
	heightAPar = 30;
	heightSup1NDevice = 30;
	heightHk1NStructure = 30;
	heightHk1NVertex = 30;
	heightHk1NLineguide = 30;
	heightHk1NArcguide = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrDvcRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneDetail") == "true");
	var initdoneView = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneView") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneAPar") == "true");
	var initdoneSup1NDevice = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneSup1NDevice") == "true");
	var initdoneHk1NStructure = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NStructure") == "true");
	var initdoneHk1NVertex = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NVertex") == "true");
	var initdoneHk1NLineguide = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NLineguide") == "true");
	var initdoneHk1NArcguide = (retrieveSi(srcdoc, "StatAppPlnrDvcRec", "initdoneHk1NArcguide") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlPlnrDvcPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrDvcDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneView) {
		lhsdoc.getElementById("View").src = "./PnlPlnrDvcView.html?scrJref=" + scrJrefView;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlPlnrDvcAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneSup1NDevice) {
		rhsdoc.getElementById("Sup1NDevice").src = "./PnlPlnrDvcSup1NDevice.html?scrJref=" + scrJrefSup1NDevice;
	} else if (!initdoneHk1NStructure) {
		rhsdoc.getElementById("Hk1NStructure").src = "./PnlPlnrDvcHk1NStructure.html?scrJref=" + scrJrefHk1NStructure;
	} else if (!initdoneHk1NVertex) {
		rhsdoc.getElementById("Hk1NVertex").src = "./PnlPlnrDvcHk1NVertex.html?scrJref=" + scrJrefHk1NVertex;
	} else if (!initdoneHk1NLineguide) {
		rhsdoc.getElementById("Hk1NLineguide").src = "./PnlPlnrDvcHk1NLineguide.html?scrJref=" + scrJrefHk1NLineguide;
	} else if (!initdoneHk1NArcguide) {
		rhsdoc.getElementById("Hk1NArcguide").src = "./PnlPlnrDvcHk1NArcguide.html?scrJref=" + scrJrefHk1NArcguide;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "View") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "APar") heightAPar = height;
		else if (short == "Sup1NDevice") heightSup1NDevice = height;
		else if (short == "Hk1NStructure") heightHk1NStructure = height;
		else if (short == "Hk1NVertex") heightHk1NVertex = height;
		else if (short == "Hk1NLineguide") heightHk1NLineguide = height;
		else if (short == "Hk1NArcguide") heightHk1NArcguide = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrDvcRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDvcRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlPlnrDvcRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDvcRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "View") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "View") heightView = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Sup1NDevice") heightSup1NDevice = height;
	else if (pnlshort == "Hk1NStructure") heightHk1NStructure = height;
	else if (pnlshort == "Hk1NVertex") heightHk1NVertex = height;
	else if (pnlshort == "Hk1NLineguide") heightHk1NLineguide = height;
	else if (pnlshort == "Hk1NArcguide") heightHk1NArcguide = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightView+13 + heightAPar+13 + 5;
	heightRhs = heightSup1NDevice+13 + heightHk1NStructure+13 + heightHk1NVertex+13 + heightHk1NLineguide+13 + heightHk1NArcguide+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDvcRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDvcRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrDvcRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDvcRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDvcRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDvcRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDvcRecData", "ContInfPlnrDvcRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDvcRecData", "StatAppPlnrDvcRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDvcRecData", "StatShrPlnrDvcRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDvcRecData", "TagPlnrDvcRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrDvcRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NDevice) {
				rhsdoc.getElementById("Sup1NDevice").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NStructure) {
				rhsdoc.getElementById("Hk1NStructure").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVertex) {
				rhsdoc.getElementById("Hk1NVertex").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NLineguide) {
				rhsdoc.getElementById("Hk1NLineguide").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NArcguide) {
				rhsdoc.getElementById("Hk1NArcguide").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrDvcRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDvcRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDvcRec", "srefIxPlnrVExpstate");

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


