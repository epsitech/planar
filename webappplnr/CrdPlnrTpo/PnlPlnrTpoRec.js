/**
  * \file PnlPlnrTpoRec.js
  * web client functionality for panel PnlPlnrTpoRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "scrJrefDetail");
	scrJrefFloorplan = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "scrJrefFloorplan");
	scrJref1NArray = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "scrJref1NArray");
	scrJrefHk1NReticle = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "scrJrefHk1NReticle");
	scrJrefMNProject = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "scrJrefMNProject");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdoneFloorplan", "false");
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdone1NArray", "false");
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdoneHk1NReticle", "false");
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdoneMNProject", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightFloorplan = 30;
	height1NArray = 30;
	heightHk1NReticle = 30;
	heightMNProject = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrTpoRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneDetail") == "true");
	var initdoneFloorplan = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneFloorplan") == "true");
	var initdone1NArray = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdone1NArray") == "true");
	var initdoneHk1NReticle = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneHk1NReticle") == "true");
	var initdoneMNProject = (retrieveSi(srcdoc, "StatAppPlnrTpoRec", "initdoneMNProject") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrTpoDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneFloorplan) {
		lhsdoc.getElementById("Floorplan").src = "./PnlPlnrTpoFloorplan.html?scrJref=" + scrJrefFloorplan;
	} else if (!initdone1NArray) {
		rhsdoc.getElementById("1NArray").src = "./PnlPlnrTpo1NArray.html?scrJref=" + scrJref1NArray;
	} else if (!initdoneHk1NReticle) {
		rhsdoc.getElementById("Hk1NReticle").src = "./PnlPlnrTpoHk1NReticle.html?scrJref=" + scrJrefHk1NReticle;
	} else if (!initdoneMNProject) {
		rhsdoc.getElementById("MNProject").src = "./PnlPlnrTpoMNProject.html?scrJref=" + scrJrefMNProject;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "Floorplan")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Floorplan") heightFloorplan = height;
		else if (short == "1NArray") height1NArray = height;
		else if (short == "Hk1NReticle") heightHk1NReticle = height;
		else if (short == "MNProject") heightMNProject = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrTpoRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrTpoRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlPlnrTpoRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrTpoRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "Floorplan")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "Floorplan") heightFloorplan = height;
	else if (pnlshort == "1NArray") height1NArray = height;
	else if (pnlshort == "Hk1NReticle") heightHk1NReticle = height;
	else if (pnlshort == "MNProject") heightMNProject = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightFloorplan+13 + 5;
	heightRhs = height1NArray+13 + heightHk1NReticle+13 + heightMNProject+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrTpoRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrTpoRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrTpoRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrTpoRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrTpoRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrTpoRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrTpoRecData", "ContInfPlnrTpoRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrTpoRecData", "StatAppPlnrTpoRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrTpoRecData", "StatShrPlnrTpoRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrTpoRecData", "TagPlnrTpoRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrTpoRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJrefFloorplan) {
				lhsdoc.getElementById("Floorplan").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NArray) {
				rhsdoc.getElementById("1NArray").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NReticle) {
				rhsdoc.getElementById("Hk1NReticle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNProject) {
				rhsdoc.getElementById("MNProject").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrTpoRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrTpoRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrTpoRec", "srefIxPlnrVExpstate");

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


