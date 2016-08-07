/**
  * \file PnlPlnrClcDetail.js
  * web client functionality for panel PnlPlnrClcDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrClcDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrClcDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrClcDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrClcDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrClcDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptTit"));
	initCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptPrj"));
	initCpt(contcontdoc, "CptDim", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptDim"));
	refreshPup(contcontdoc, srcdoc, "PupDim", "", "FeedFPupDim", retrieveCi(srcdoc, "ContIacPlnrClcDetail", "numFPupDim"), true, false);
	initCpt(contcontdoc, "CptTpl", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptTpl"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptSup"));
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptDsn"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptSta"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagPlnrClcDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate");

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

	var ButPrjViewAvail = (retrieveSi(srcdoc, "StatShrPlnrClcDetail", "ButPrjViewAvail") == "true");

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrClcDetail", "ButDsnViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrClcDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacPlnrClcDetail", "TxfTit"), true, false, true);

	if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView"))) {
		mytd = contcontdoc.getElementById("rdynPrj");
		clearElem(mytd);

		first = true;

		if (ButPrjViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrj", retrieveCi(srcdoc, "ContInfPlnrClcDetail", "TxtPrj"));

	contcontdoc.getElementById("PupDim").value = retrieveCi(srcdoc, "ContIacPlnrClcDetail", "numFPupDim");

	refreshTxt(contcontdoc, "TxtTpl", retrieveCi(srcdoc, "ContInfPlnrClcDetail", "TxtTpl"));

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfPlnrClcDetail", "TxtSup"));

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrClcDetail", "TxtDsn"));

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacPlnrClcDetail", "TxfSta"), true, false, true);

	refreshTxf(contcontdoc, "TxfCmt", "t", retrieveCi(srcdoc, "ContIacPlnrClcDetail", "TxfCmt"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrClcDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrClcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrClcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrClcDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrClcDetailData", scrJref, "ContIacPlnrClcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrClcDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrClcDetailData", scrJref, "ContIacPlnrClcDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrClcDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrClcDetailData", scrJref, "ContIacPlnrClcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "ContIacPlnrClcDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "ContInfPlnrClcDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "FeedFPupDim", srcdoc)) mask.push("feedFPupDim");
	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "StatAppPlnrClcDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "StatShrPlnrClcDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrClcDetailData", "TagPlnrClcDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrClcDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrClcDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrClcDetailData") {
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


