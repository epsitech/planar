/**
  * \file PnlPlnrRtcDetail.js
  * web client functionality for panel PnlPlnrRtcDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrRtcDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrRtcDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrRtcDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrRtcDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrRtcDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptSrf"));
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacPlnrRtcDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptDsn"));
	initCpt(contcontdoc, "CptLyr", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptLyr"));
	initCpt(contcontdoc, "CptX0", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptX0"));
	initCpt(contcontdoc, "CptY0", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptY0"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagPlnrRtcDetail", "CptPhi"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 192; // full cont height

// IP refreshB.vars --- BEGIN

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrRtcDetail", "ButDsnViewAvail") == "true");

	var ButLyrViewAvail = (retrieveSi(srcdoc, "StatShrPlnrRtcDetail", "ButLyrViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrRtcDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrRtcDetail", "TxtSrf"));

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfPlnrRtcDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacPlnrRtcDetail", "numFPupHkt");

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrRtcDetail", "TxtDsn"));

	if ((ButLyrViewAvail == !contcontdoc.getElementById("ButLyrView"))) {
		mytd = contcontdoc.getElementById("rdynLyr");
		clearElem(mytd);

		first = true;

		if (ButLyrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLyrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtLyr", retrieveCi(srcdoc, "ContInfPlnrRtcDetail", "TxtLyr"));

	refreshTxf(contcontdoc, "TxfX0", "s", retrieveCi(srcdoc, "ContIacPlnrRtcDetail", "TxfX0"), true, false, true);

	refreshTxf(contcontdoc, "TxfY0", "s", retrieveCi(srcdoc, "ContIacPlnrRtcDetail", "TxfY0"), true, false, true);

	refreshTxf(contcontdoc, "TxfPhi", "s", retrieveCi(srcdoc, "ContIacPlnrRtcDetail", "TxfPhi"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrRtcDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrRtcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrRtcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrRtcDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrRtcDetailData", scrJref, "ContIacPlnrRtcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrRtcDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrRtcDetailData", scrJref, "ContIacPlnrRtcDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrRtcDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrRtcDetailData", scrJref, "ContIacPlnrRtcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "ContIacPlnrRtcDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "ContInfPlnrRtcDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "StatAppPlnrRtcDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "StatShrPlnrRtcDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrRtcDetailData", "TagPlnrRtcDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrRtcDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrRtcDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrRtcDetailData") {
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


