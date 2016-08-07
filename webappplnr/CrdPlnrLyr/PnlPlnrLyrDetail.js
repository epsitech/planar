/**
  * \file PnlPlnrLyrDetail.js
  * web client functionality for panel PnlPlnrLyrDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrLyrDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrLyrDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrLyrDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrLyrDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrLyrDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptMat", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptMat"));
	initCpt(contcontdoc, "CptTty", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptTty"));
	refreshPup(contcontdoc, srcdoc, "PupTty", "", "FeedFPupTty", retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupTty"), true, false);
	initCpt(contcontdoc, "CptFlr", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptFlr"));
	initCpt(contcontdoc, "CptCtr", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptCtr"));
	initCpt(contcontdoc, "CptCei", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptCei"));
	initCpt(contcontdoc, "CptT", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptT"));
	initCpt(contcontdoc, "CptMl", retrieveTi(srcdoc, "TagPlnrLyrDetail", "CptMl"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate");

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

	var ButMatViewAvail = (retrieveSi(srcdoc, "StatShrPlnrLyrDetail", "ButMatViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrLyrDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupTyp");

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupHkt");

	if ((ButMatViewAvail == !contcontdoc.getElementById("ButMatView"))) {
		mytd = contcontdoc.getElementById("rdynMat");
		clearElem(mytd);

		first = true;

		if (ButMatViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMatView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMat", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtMat"));

	contcontdoc.getElementById("PupTty").value = retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "numFPupTty");

	refreshTxt(contcontdoc, "TxtFlr", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtFlr"));

	refreshTxt(contcontdoc, "TxtCtr", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtCtr"));

	refreshTxt(contcontdoc, "TxtCei", retrieveCi(srcdoc, "ContInfPlnrLyrDetail", "TxtCei"));

	refreshTxf(contcontdoc, "TxfT", "s", retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "TxfT"), true, false, true);

	refreshTxf(contcontdoc, "TxfMl", "s", retrieveCi(srcdoc, "ContIacPlnrLyrDetail", "TxfMl"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrLyrDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrLyrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrLyrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrLyrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrLyrDetailData", scrJref, "ContIacPlnrLyrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrLyrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrLyrDetailData", scrJref, "ContIacPlnrLyrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrLyrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrLyrDetailData", scrJref, "ContIacPlnrLyrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "ContIacPlnrLyrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "ContInfPlnrLyrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "FeedFPupTty", srcdoc)) mask.push("feedFPupTty");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "StatAppPlnrLyrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "StatShrPlnrLyrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrLyrDetailData", "TagPlnrLyrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrLyrDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrLyrDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrLyrDetailData") {
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


