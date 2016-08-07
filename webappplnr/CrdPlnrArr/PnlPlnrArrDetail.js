/**
  * \file PnlPlnrArrDetail.js
  * web client functionality for panel PnlPlnrArrDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrArrDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrArrDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrArrDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrArrDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrArrDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTpo", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptTpo"));
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDsn"));
	initCpt(contcontdoc, "CptI", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptI"));
	initCpt(contcontdoc, "CptJ", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptJ"));
	initCpt(contcontdoc, "CptDi", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDi"));
	initCpt(contcontdoc, "CptDj", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDj"));
	initCpt(contcontdoc, "CptK", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptK"));
	initCpt(contcontdoc, "CptL", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptL"));
	initCpt(contcontdoc, "CptDk", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDk"));
	initCpt(contcontdoc, "CptDl", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDl"));
	initCpt(contcontdoc, "CptM", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptM"));
	initCpt(contcontdoc, "CptN", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptN"));
	initCpt(contcontdoc, "CptDm", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDm"));
	initCpt(contcontdoc, "CptDn", retrieveTi(srcdoc, "TagPlnrArrDetail", "CptDn"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 392; // full cont height

// IP refreshB.vars --- BEGIN

	var ButTpoViewAvail = (retrieveSi(srcdoc, "StatShrPlnrArrDetail", "ButTpoViewAvail") == "true");

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrArrDetail", "ButDsnViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrArrDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrArrDetail", "TxtSrf"));

	if ((ButTpoViewAvail == !contcontdoc.getElementById("ButTpoView"))) {
		mytd = contcontdoc.getElementById("rdynTpo");
		clearElem(mytd);

		first = true;

		if (ButTpoViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTpoView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTpo", retrieveCi(srcdoc, "ContInfPlnrArrDetail", "TxtTpo"));

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrArrDetail", "TxtDsn"));

	refreshTxf(contcontdoc, "TxfI", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfI"), true, false, true);

	refreshTxf(contcontdoc, "TxfJ", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfJ"), true, false, true);

	refreshTxf(contcontdoc, "TxfDi", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDi"), true, false, true);

	refreshTxf(contcontdoc, "TxfDj", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDj"), true, false, true);

	refreshTxf(contcontdoc, "TxfK", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfK"), true, false, true);

	refreshTxf(contcontdoc, "TxfL", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfL"), true, false, true);

	refreshTxf(contcontdoc, "TxfDk", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDk"), true, false, true);

	refreshTxf(contcontdoc, "TxfDl", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDl"), true, false, true);

	refreshTxf(contcontdoc, "TxfM", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfM"), true, false, true);

	refreshTxf(contcontdoc, "TxfN", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfN"), true, false, true);

	refreshTxf(contcontdoc, "TxfDm", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDm"), true, false, true);

	refreshTxf(contcontdoc, "TxfDn", "s", retrieveCi(srcdoc, "ContIacPlnrArrDetail", "TxfDn"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrArrDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrArrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrArrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrArrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrArrDetailData", scrJref, "ContIacPlnrArrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrArrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrArrDetailData", scrJref, "ContIacPlnrArrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrArrDetailData", "ContIacPlnrArrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrArrDetailData", "ContInfPlnrArrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrArrDetailData", "StatAppPlnrArrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrArrDetailData", "StatShrPlnrArrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrArrDetailData", "TagPlnrArrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrArrDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrArrDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrArrDetailData") {
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


