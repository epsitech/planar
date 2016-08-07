/**
  * \file PnlPlnrTpoDetail.js
  * web client functionality for panel PnlPlnrTpoDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrTpoDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrTpoDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrTpoDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrTpoDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrTpoDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptMaj", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptMaj"));
	initCpt(contcontdoc, "CptSub", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptSub"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "numFPupSte"), true, false);
	initCpt(contcontdoc, "CptFli", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptFli"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagPlnrTpoDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate");

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

	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrPlnrTpoDetail", "ButJEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrTpoDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "TxfTit"), true, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "numFPupTyp");

	refreshTxf(contcontdoc, "TxfMaj", "s", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "TxfMaj"), true, false, true);

	refreshTxf(contcontdoc, "TxfSub", "s", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "TxfSub"), true, false, true);

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "numFPupJ"), true, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "numFPupSte");

	refreshChk(contcontdoc, "ChkFli", (retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "ChkFli") == "true"), true);

	refreshTxf(contcontdoc, "TxfCmt", "t", retrieveCi(srcdoc, "ContIacPlnrTpoDetail", "TxfCmt"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrTpoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrTpoDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacPlnrTpoDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrTpoDetailData", scrJref, "ContIacPlnrTpoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrTpoDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrTpoDetailData", scrJref, "ContIacPlnrTpoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrTpoDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrTpoDetailData", scrJref, "ContIacPlnrTpoDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrTpoDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrTpoDetailData", scrJref, "ContIacPlnrTpoDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "ContIacPlnrTpoDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "StatAppPlnrTpoDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "StatShrPlnrTpoDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrTpoDetailData", "TagPlnrTpoDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrTpoDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrTpoDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrTpoDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

// IP handleDpchAppDoDlgopenReply --- BEGIN
function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};
// IP handleDpchAppDoDlgopenReply --- END


