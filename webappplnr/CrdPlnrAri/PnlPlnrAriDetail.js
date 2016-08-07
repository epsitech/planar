/**
  * \file PnlPlnrAriDetail.js
  * web client functionality for panel PnlPlnrAriDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrAriDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrAriDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrAriDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrAriDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrAriDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptI", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptI"));
	initCpt(contcontdoc, "CptJ", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptJ"));
	initCpt(contcontdoc, "CptK", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptK"));
	initCpt(contcontdoc, "CptL", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptL"));
	initCpt(contcontdoc, "CptM", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptM"));
	initCpt(contcontdoc, "CptN", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptN"));
	initCpt(contcontdoc, "CptArr", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptArr"));
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptDsn"));
	initCpt(contcontdoc, "CptDx", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptDx"));
	initCpt(contcontdoc, "CptDy", retrieveTi(srcdoc, "TagPlnrAriDetail", "CptDy"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 267; // full cont height

// IP refreshB.vars --- BEGIN

	var ButArrViewAvail = (retrieveSi(srcdoc, "StatShrPlnrAriDetail", "ButArrViewAvail") == "true");

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrAriDetail", "ButDsnViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrAriDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfI", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfI"), true, false, true);

	refreshTxf(contcontdoc, "TxfJ", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfJ"), true, false, true);

	refreshTxf(contcontdoc, "TxfK", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfK"), true, false, true);

	refreshTxf(contcontdoc, "TxfL", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfL"), true, false, true);

	refreshTxf(contcontdoc, "TxfM", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfM"), true, false, true);

	refreshTxf(contcontdoc, "TxfN", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfN"), true, false, true);

	if ((ButArrViewAvail == !contcontdoc.getElementById("ButArrView"))) {
		mytd = contcontdoc.getElementById("rdynArr");
		clearElem(mytd);

		first = true;

		if (ButArrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButArrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtArr", retrieveCi(srcdoc, "ContInfPlnrAriDetail", "TxtArr"));

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrAriDetail", "TxtDsn"));

	refreshTxf(contcontdoc, "TxfDx", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfDx"), true, false, true);

	refreshTxf(contcontdoc, "TxfDy", "s", retrieveCi(srcdoc, "ContIacPlnrAriDetail", "TxfDy"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrAriDetail", "srefIxPlnrVExpstate");

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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrAriDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrAriDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrAriDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrAriDetailData", scrJref, "ContIacPlnrAriDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrAriDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrAriDetailData", scrJref, "ContIacPlnrAriDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrAriDetailData", "ContIacPlnrAriDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrAriDetailData", "ContInfPlnrAriDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrAriDetailData", "StatAppPlnrAriDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrAriDetailData", "StatShrPlnrAriDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrAriDetailData", "TagPlnrAriDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrAriDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrAriDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrAriDetailData") {
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


