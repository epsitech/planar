/**
  * \file PnlPlnrMatRec.js
  * web client functionality for panel PnlPlnrMatRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrMatRec", "scrJrefDetail");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrPlnrMatRec", "scrJrefAPar");
	scrJref1NLayer = retrieveSi(srcdoc, "StatShrPlnrMatRec", "scrJref1NLayer");
	scrJrefMod1NMaterial = retrieveSi(srcdoc, "StatShrPlnrMatRec", "scrJrefMod1NMaterial");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrPlnrMatRec", "scrJrefRef1NFile");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrMatRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrMatRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppPlnrMatRec", "initdone1NLayer", "false");
	setSi(srcdoc, "StatAppPlnrMatRec", "initdoneMod1NMaterial", "false");
	setSi(srcdoc, "StatAppPlnrMatRec", "initdoneRef1NFile", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAPar = 30;
	height1NLayer = 30;
	heightMod1NMaterial = 30;
	heightRef1NFile = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrMatRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneAPar") == "true");
	var initdone1NLayer = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdone1NLayer") == "true");
	var initdoneMod1NMaterial = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneMod1NMaterial") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppPlnrMatRec", "initdoneRef1NFile") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrMatDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlPlnrMatAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdone1NLayer) {
		rhsdoc.getElementById("1NLayer").src = "./PnlPlnrMat1NLayer.html?scrJref=" + scrJref1NLayer;
	} else if (!initdoneMod1NMaterial) {
		rhsdoc.getElementById("Mod1NMaterial").src = "./PnlPlnrMatMod1NMaterial.html?scrJref=" + scrJrefMod1NMaterial;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlPlnrMatRef1NFile.html?scrJref=" + scrJrefRef1NFile;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "APar") heightAPar = height;
		else if (short == "1NLayer") height1NLayer = height;
		else if (short == "Mod1NMaterial") heightMod1NMaterial = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
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

	doc.getElementById("Rec_side").src = "./PnlPlnrMatRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrMatRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlPlnrMatRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrMatRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "1NLayer") height1NLayer = height;
	else if (pnlshort == "Mod1NMaterial") heightMod1NMaterial = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAPar+13 + 5;
	heightRhs = height1NLayer+13 + heightMod1NMaterial+13 + heightRef1NFile+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrMatRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrMatRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrMatRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrMatRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrMatRec", "TxtRef"));

};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrMatRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrMatRecData", "ContInfPlnrMatRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrMatRecData", "StatAppPlnrMatRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrMatRecData", "StatShrPlnrMatRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrMatRecData", "TagPlnrMatRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrMatRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

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
			} else if (_scrJref == scrJrefAPar) {
				lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NLayer) {
				rhsdoc.getElementById("1NLayer").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMod1NMaterial) {
				rhsdoc.getElementById("Mod1NMaterial").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngPlnrMatRecData") {
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

			} else if (blk.nodeName == "DpchEngPlnrMatRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrMatRec", "srefIxPlnrVExpstate");

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


