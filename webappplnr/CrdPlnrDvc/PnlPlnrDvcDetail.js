/**
  * \file PnlPlnrDvcDetail.js
  * web client functionality for panel PnlPlnrDvcDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrDvcDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDvcDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrDvcDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDvcDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDvcDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptSrf"));
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptDsn"));
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptSup"));
	initCpt(contcontdoc, "CptTpl", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptTpl"));
	initCpt(contcontdoc, "CptMty", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptMty"));
	refreshPup(contcontdoc, srcdoc, "PupMty", "", "FeedFPupMty", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "numFPupMty"), true, false);
	initCpt(contcontdoc, "CptAty", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptAty"));
	refreshPup(contcontdoc, srcdoc, "PupAty", "", "FeedFPupAty", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "numFPupAty"), true, false);
	initCpt(contcontdoc, "CptAv1", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptAv1"));
	initCpt(contcontdoc, "CptPv1", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptPv1"));
	initCpt(contcontdoc, "CptAv2", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptAv2"));
	initCpt(contcontdoc, "CptPv2", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptPv2"));
	initCpt(contcontdoc, "CptX", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptX"));
	initCpt(contcontdoc, "CptY", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptY"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptPhi"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagPlnrDvcDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate");

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

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "ButDsnViewAvail") == "true");

	var TxtAv1Alt = (retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "TxtAv1Alt") == "true");
	var TxfAv1Valid = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "TxfAv1Valid") == "true");

	var TxtPv1Alt = (retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "TxtPv1Alt") == "true");
	var TxfPv1Valid = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "TxfPv1Valid") == "true");

	var TxtAv2Alt = (retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "TxtAv2Alt") == "true");
	var TxfAv2Valid = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "TxfAv2Valid") == "true");

	var TxtPv2Alt = (retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "TxtPv2Alt") == "true");
	var TxfPv2Valid = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "TxfPv2Valid") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrDvcDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtSrf"));

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtDsn"));

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtSup"));

	refreshTxt(contcontdoc, "TxtTpl", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtTpl"));

	contcontdoc.getElementById("PupMty").value = retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "numFPupMty");

	contcontdoc.getElementById("PupAty").value = retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "numFPupAty");

	if ( (TxtAv1Alt == !contcontdoc.getElementById("TxfAv1")) || (!TxtAv1Alt == !contcontdoc.getElementById("TxtAv1")) ) {
		mytd = contcontdoc.getElementById("dynAv1");
		clearElem(mytd);

		if (TxtAv1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv1", ""));
	};

	if (TxtAv1Alt) refreshTxf(contcontdoc, "TxfAv1", "", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfAv1"), true, false, TxfAv1Valid);
	else refreshTxt(contcontdoc, "TxtAv1", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtAv1"));

	if ( (TxtPv1Alt == !contcontdoc.getElementById("TxfPv1")) || (!TxtPv1Alt == !contcontdoc.getElementById("TxtPv1")) ) {
		mytd = contcontdoc.getElementById("dynPv1");
		clearElem(mytd);

		if (TxtPv1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPv1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtPv1", ""));
	};

	if (TxtPv1Alt) refreshTxf(contcontdoc, "TxfPv1", "", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfPv1"), true, false, TxfPv1Valid);
	else refreshTxt(contcontdoc, "TxtPv1", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtPv1"));

	if ( (TxtAv2Alt == !contcontdoc.getElementById("TxfAv2")) || (!TxtAv2Alt == !contcontdoc.getElementById("TxtAv2")) ) {
		mytd = contcontdoc.getElementById("dynAv2");
		clearElem(mytd);

		if (TxtAv2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv2", ""));
	};

	if (TxtAv2Alt) refreshTxf(contcontdoc, "TxfAv2", "", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfAv2"), true, false, TxfAv2Valid);
	else refreshTxt(contcontdoc, "TxtAv2", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtAv2"));

	if ( (TxtPv2Alt == !contcontdoc.getElementById("TxfPv2")) || (!TxtPv2Alt == !contcontdoc.getElementById("TxtPv2")) ) {
		mytd = contcontdoc.getElementById("dynPv2");
		clearElem(mytd);

		if (TxtPv2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPv2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtPv2", ""));
	};

	if (TxtPv2Alt) refreshTxf(contcontdoc, "TxfPv2", "", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfPv2"), true, false, TxfPv2Valid);
	else refreshTxt(contcontdoc, "TxtPv2", retrieveCi(srcdoc, "ContInfPlnrDvcDetail", "TxtPv2"));

	refreshTxf(contcontdoc, "TxfX", "s", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfX"), true, false, true);

	refreshTxf(contcontdoc, "TxfY", "s", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfY"), true, false, true);

	refreshTxf(contcontdoc, "TxfPhi", "s", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfPhi"), true, false, true);

	refreshTxf(contcontdoc, "TxfCmt", "t", retrieveCi(srcdoc, "ContIacPlnrDvcDetail", "TxfCmt"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDvcDetail", "srefIxPlnrVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppPlnrDvcDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppPlnrDvcDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDvcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDvcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrDvcDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDvcDetailData", scrJref, "ContIacPlnrDvcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrDvcDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDvcDetailData", scrJref, "ContIacPlnrDvcDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrDvcDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDvcDetailData", scrJref, "ContIacPlnrDvcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "ContIacPlnrDvcDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "ContInfPlnrDvcDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "FeedFPupAty", srcdoc)) mask.push("feedFPupAty");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "FeedFPupMty", srcdoc)) mask.push("feedFPupMty");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "StatAppPlnrDvcDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "StatShrPlnrDvcDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDvcDetailData", "TagPlnrDvcDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDvcDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrDvcDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDvcDetailData") {
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


