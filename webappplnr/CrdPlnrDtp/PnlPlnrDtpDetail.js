/**
  * \file PnlPlnrDtpDetail.js
  * web client functionality for panel PnlPlnrDtpDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrDtpDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDtpDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrDtpDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDtpDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDtpDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptSrf"));
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptDsn"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptSup"));
	initCpt(contcontdoc, "CptTpl", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptTpl"));
	initCpt(contcontdoc, "CptMty", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptMty"));
	refreshPup(contcontdoc, srcdoc, "PupMty", "", "FeedFPupMty", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "numFPupMty"), true, false);
	initCpt(contcontdoc, "CptAty", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptAty"));
	refreshPup(contcontdoc, srcdoc, "PupAty", "", "FeedFPupAty", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "numFPupAty"), true, false);
	initCpt(contcontdoc, "CptAv1", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptAv1"));
	initCpt(contcontdoc, "CptPv1", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptPv1"));
	initCpt(contcontdoc, "CptAv2", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptAv2"));
	initCpt(contcontdoc, "CptPv2", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptPv2"));
	initCpt(contcontdoc, "CptX", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptX"));
	initCpt(contcontdoc, "CptY", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptY"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptPhi"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagPlnrDtpDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 417; // full cont height

// IP refreshB.vars --- BEGIN

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "ButDsnViewAvail") == "true");

	var TxtAv1Alt = (retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "TxtAv1Alt") == "true");
	var TxfAv1Valid = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "TxfAv1Valid") == "true");

	var TxtPv1Alt = (retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "TxtPv1Alt") == "true");
	var TxfPv1Valid = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "TxfPv1Valid") == "true");

	var TxtAv2Alt = (retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "TxtAv2Alt") == "true");
	var TxfAv2Valid = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "TxfAv2Valid") == "true");

	var TxtPv2Alt = (retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "TxtPv2Alt") == "true");
	var TxfPv2Valid = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "TxfPv2Valid") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrDtpDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtSrf"));

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtDsn"));

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtSup"));

	refreshTxt(contcontdoc, "TxtTpl", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtTpl"));

	contcontdoc.getElementById("PupMty").value = retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "numFPupMty");

	contcontdoc.getElementById("PupAty").value = retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "numFPupAty");

	if ( (TxtAv1Alt == !contcontdoc.getElementById("TxfAv1")) || (!TxtAv1Alt == !contcontdoc.getElementById("TxtAv1")) ) {
		mytd = contcontdoc.getElementById("dynAv1");
		clearElem(mytd);

		if (TxtAv1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv1", ""));
	};

	if (TxtAv1Alt) refreshTxf(contcontdoc, "TxfAv1", "", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfAv1"), true, false, TxfAv1Valid);
	else refreshTxt(contcontdoc, "TxtAv1", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtAv1"));

	if ( (TxtPv1Alt == !contcontdoc.getElementById("TxfPv1")) || (!TxtPv1Alt == !contcontdoc.getElementById("TxtPv1")) ) {
		mytd = contcontdoc.getElementById("dynPv1");
		clearElem(mytd);

		if (TxtPv1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPv1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtPv1", ""));
	};

	if (TxtPv1Alt) refreshTxf(contcontdoc, "TxfPv1", "", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfPv1"), true, false, TxfPv1Valid);
	else refreshTxt(contcontdoc, "TxtPv1", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtPv1"));

	if ( (TxtAv2Alt == !contcontdoc.getElementById("TxfAv2")) || (!TxtAv2Alt == !contcontdoc.getElementById("TxtAv2")) ) {
		mytd = contcontdoc.getElementById("dynAv2");
		clearElem(mytd);

		if (TxtAv2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv2", ""));
	};

	if (TxtAv2Alt) refreshTxf(contcontdoc, "TxfAv2", "", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfAv2"), true, false, TxfAv2Valid);
	else refreshTxt(contcontdoc, "TxtAv2", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtAv2"));

	if ( (TxtPv2Alt == !contcontdoc.getElementById("TxfPv2")) || (!TxtPv2Alt == !contcontdoc.getElementById("TxtPv2")) ) {
		mytd = contcontdoc.getElementById("dynPv2");
		clearElem(mytd);

		if (TxtPv2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPv2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtPv2", ""));
	};

	if (TxtPv2Alt) refreshTxf(contcontdoc, "TxfPv2", "", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfPv2"), true, false, TxfPv2Valid);
	else refreshTxt(contcontdoc, "TxtPv2", retrieveCi(srcdoc, "ContInfPlnrDtpDetail", "TxtPv2"));

	refreshTxf(contcontdoc, "TxfX", "s", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfX"), true, false, true);

	refreshTxf(contcontdoc, "TxfY", "s", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfY"), true, false, true);

	refreshTxf(contcontdoc, "TxfPhi", "s", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfPhi"), true, false, true);

	refreshTxf(contcontdoc, "TxfCmt", "t", retrieveCi(srcdoc, "ContIacPlnrDtpDetail", "TxfCmt"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDtpDetail", "srefIxPlnrVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppPlnrDtpDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppPlnrDtpDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDtpDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDtpDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrDtpDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDtpDetailData", scrJref, "ContIacPlnrDtpDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrDtpDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDtpDetailData", scrJref, "ContIacPlnrDtpDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrDtpDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDtpDetailData", scrJref, "ContIacPlnrDtpDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "ContIacPlnrDtpDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "ContInfPlnrDtpDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "FeedFPupAty", srcdoc)) mask.push("feedFPupAty");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "FeedFPupMty", srcdoc)) mask.push("feedFPupMty");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "StatAppPlnrDtpDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "StatShrPlnrDtpDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDtpDetailData", "TagPlnrDtpDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDtpDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrDtpDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDtpDetailData") {
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


