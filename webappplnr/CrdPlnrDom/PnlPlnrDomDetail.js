/**
  * \file PnlPlnrDomDetail.js
  * web client functionality for panel PnlPlnrDomDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrDomDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDomDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrDomDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDomDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDomDetail", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
// IP initB.ftrdoc --- BEGIN
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;
// IP initB.ftrdoc --- END

// IP initB --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptDsn"));
	initCpt(contcontdoc, "CptFlr", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptFlr"));
	initCpt(contcontdoc, "CptCei", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptCei"));
	initCpt(contcontdoc, "CptVx1", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptVx1"));
	initCpt(contcontdoc, "CptLg1", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptLg1"));
	initCpt(contcontdoc, "CptVx2", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptVx2"));
	initCpt(contcontdoc, "CptLg2", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptLg2"));
	initCpt(contcontdoc, "CptVx3", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptVx3"));
	initCpt(contcontdoc, "CptLg3", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptLg3"));
	initCpt(contcontdoc, "CptVx4", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptVx4"));
	initCpt(contcontdoc, "CptLg4", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptLg4"));
	initCpt(contcontdoc, "CptDx", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptDx"));
	initCpt(contcontdoc, "CptDy", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptDy"));
	initCpt(contcontdoc, "CptDxy", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptDxy"));
	initCpt(contcontdoc, "CptDz", retrieveTi(srcdoc, "TagPlnrDomDetail", "CptDz"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 442; // full cont height

// IP refreshB.vars --- BEGIN

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "ButDsnViewAvail") == "true");

	var TxtFlrAlt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtFlrAlt") == "true");
	var TxfFlrValid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfFlrValid") == "true");

	var TxtCeiAlt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtCeiAlt") == "true");
	var TxfCeiValid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfCeiValid") == "true");

	var TxtVx1Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtVx1Alt") == "true");
	var TxfVx1Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfVx1Valid") == "true");

	var TxtLg1Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtLg1Alt") == "true");
	var TxfLg1Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfLg1Valid") == "true");

	var TxtVx2Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtVx2Alt") == "true");
	var TxfVx2Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfVx2Valid") == "true");

	var TxtLg2Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtLg2Alt") == "true");
	var TxfLg2Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfLg2Valid") == "true");

	var TxtVx3Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtVx3Alt") == "true");
	var TxfVx3Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfVx3Valid") == "true");

	var TxtLg3Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtLg3Alt") == "true");
	var TxfLg3Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfLg3Valid") == "true");

	var TxtVx4Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtVx4Alt") == "true");
	var TxfVx4Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfVx4Valid") == "true");

	var TxtLg4Alt = (retrieveSi(srcdoc, "StatAppPlnrDomDetail", "TxtLg4Alt") == "true");
	var TxfLg4Valid = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "TxfLg4Valid") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrDomDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrDomDetail", "numFPupTyp");

	if ((ButDsnViewAvail == !contcontdoc.getElementById("ButDsnView"))) {
		mytd = contcontdoc.getElementById("rdynDsn");
		clearElem(mytd);

		first = true;

		if (ButDsnViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDsnView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtDsn"));

	if ( (TxtFlrAlt == !contcontdoc.getElementById("TxfFlr")) || (!TxtFlrAlt == !contcontdoc.getElementById("TxtFlr")) ) {
		mytd = contcontdoc.getElementById("dynFlr");
		clearElem(mytd);

		if (TxtFlrAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfFlr", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtFlr", ""));
	};

	if (TxtFlrAlt) refreshTxf(contcontdoc, "TxfFlr", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfFlr"), true, false, TxfFlrValid);
	else refreshTxt(contcontdoc, "TxtFlr", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtFlr"));

	if ( (TxtCeiAlt == !contcontdoc.getElementById("TxfCei")) || (!TxtCeiAlt == !contcontdoc.getElementById("TxtCei")) ) {
		mytd = contcontdoc.getElementById("dynCei");
		clearElem(mytd);

		if (TxtCeiAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCei", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtCei", ""));
	};

	if (TxtCeiAlt) refreshTxf(contcontdoc, "TxfCei", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfCei"), true, false, TxfCeiValid);
	else refreshTxt(contcontdoc, "TxtCei", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtCei"));

	if ( (TxtVx1Alt == !contcontdoc.getElementById("TxfVx1")) || (!TxtVx1Alt == !contcontdoc.getElementById("TxtVx1")) ) {
		mytd = contcontdoc.getElementById("dynVx1");
		clearElem(mytd);

		if (TxtVx1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVx1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtVx1", ""));
	};

	if (TxtVx1Alt) refreshTxf(contcontdoc, "TxfVx1", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfVx1"), true, false, TxfVx1Valid);
	else refreshTxt(contcontdoc, "TxtVx1", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtVx1"));

	if ( (TxtLg1Alt == !contcontdoc.getElementById("TxfLg1")) || (!TxtLg1Alt == !contcontdoc.getElementById("TxtLg1")) ) {
		mytd = contcontdoc.getElementById("dynLg1");
		clearElem(mytd);

		if (TxtLg1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLg1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtLg1", ""));
	};

	if (TxtLg1Alt) refreshTxf(contcontdoc, "TxfLg1", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfLg1"), true, false, TxfLg1Valid);
	else refreshTxt(contcontdoc, "TxtLg1", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtLg1"));

	if ( (TxtVx2Alt == !contcontdoc.getElementById("TxfVx2")) || (!TxtVx2Alt == !contcontdoc.getElementById("TxtVx2")) ) {
		mytd = contcontdoc.getElementById("dynVx2");
		clearElem(mytd);

		if (TxtVx2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVx2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtVx2", ""));
	};

	if (TxtVx2Alt) refreshTxf(contcontdoc, "TxfVx2", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfVx2"), true, false, TxfVx2Valid);
	else refreshTxt(contcontdoc, "TxtVx2", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtVx2"));

	if ( (TxtLg2Alt == !contcontdoc.getElementById("TxfLg2")) || (!TxtLg2Alt == !contcontdoc.getElementById("TxtLg2")) ) {
		mytd = contcontdoc.getElementById("dynLg2");
		clearElem(mytd);

		if (TxtLg2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLg2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtLg2", ""));
	};

	if (TxtLg2Alt) refreshTxf(contcontdoc, "TxfLg2", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfLg2"), true, false, TxfLg2Valid);
	else refreshTxt(contcontdoc, "TxtLg2", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtLg2"));

	if ( (TxtVx3Alt == !contcontdoc.getElementById("TxfVx3")) || (!TxtVx3Alt == !contcontdoc.getElementById("TxtVx3")) ) {
		mytd = contcontdoc.getElementById("dynVx3");
		clearElem(mytd);

		if (TxtVx3Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVx3", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtVx3", ""));
	};

	if (TxtVx3Alt) refreshTxf(contcontdoc, "TxfVx3", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfVx3"), true, false, TxfVx3Valid);
	else refreshTxt(contcontdoc, "TxtVx3", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtVx3"));

	if ( (TxtLg3Alt == !contcontdoc.getElementById("TxfLg3")) || (!TxtLg3Alt == !contcontdoc.getElementById("TxtLg3")) ) {
		mytd = contcontdoc.getElementById("dynLg3");
		clearElem(mytd);

		if (TxtLg3Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLg3", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtLg3", ""));
	};

	if (TxtLg3Alt) refreshTxf(contcontdoc, "TxfLg3", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfLg3"), true, false, TxfLg3Valid);
	else refreshTxt(contcontdoc, "TxtLg3", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtLg3"));

	if ( (TxtVx4Alt == !contcontdoc.getElementById("TxfVx4")) || (!TxtVx4Alt == !contcontdoc.getElementById("TxtVx4")) ) {
		mytd = contcontdoc.getElementById("dynVx4");
		clearElem(mytd);

		if (TxtVx4Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVx4", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtVx4", ""));
	};

	if (TxtVx4Alt) refreshTxf(contcontdoc, "TxfVx4", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfVx4"), true, false, TxfVx4Valid);
	else refreshTxt(contcontdoc, "TxtVx4", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtVx4"));

	if ( (TxtLg4Alt == !contcontdoc.getElementById("TxfLg4")) || (!TxtLg4Alt == !contcontdoc.getElementById("TxtLg4")) ) {
		mytd = contcontdoc.getElementById("dynLg4");
		clearElem(mytd);

		if (TxtLg4Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLg4", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtLg4", ""));
	};

	if (TxtLg4Alt) refreshTxf(contcontdoc, "TxfLg4", "", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfLg4"), true, false, TxfLg4Valid);
	else refreshTxt(contcontdoc, "TxtLg4", retrieveCi(srcdoc, "ContInfPlnrDomDetail", "TxtLg4"));

	refreshTxf(contcontdoc, "TxfDx", "s", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfDx"), true, false, true);

	refreshTxf(contcontdoc, "TxfDy", "s", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfDy"), true, false, true);

	refreshTxf(contcontdoc, "TxfDxy", "s", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfDxy"), true, false, true);

	refreshTxf(contcontdoc, "TxfDz", "s", retrieveCi(srcdoc, "ContIacPlnrDomDetail", "TxfDz"), true, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
// IP refreshB --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDomDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		refreshA();
	} else if (srefIxPlnrVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppPlnrDomDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppPlnrDomDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDomDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDomDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrDomDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDomDetailData", scrJref, "ContIacPlnrDomDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrDomDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDomDetailData", scrJref, "ContIacPlnrDomDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrDomDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDomDetailData", scrJref, "ContIacPlnrDomDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "ContIacPlnrDomDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "ContInfPlnrDomDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "StatAppPlnrDomDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "StatShrPlnrDomDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDomDetailData", "TagPlnrDomDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDomDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrDomDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngPlnrDomDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

// IP handleDpchAppDoCrdopenReply --- BEGIN
function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				accepted = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:accepted");
				_scrJref = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:scrJref");
				sref = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngPlnrAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));
			};
		};
	};
};
// IP handleDpchAppDoCrdopenReply --- END


