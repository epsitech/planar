/**
  * \file PnlPlnrDgdDetail.js
  * web client functionality for panel PnlPlnrDgdDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrDgdDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDgdDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrDgdDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDgdDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDgdDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptDsn"));
	initCpt(contcontdoc, "CptLvl", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptLvl"));
	initCpt(contcontdoc, "CptAv1", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptAv1"));
	initCpt(contcontdoc, "CptAv2", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptAv2"));
	initCpt(contcontdoc, "CptAl1", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptAl1"));
	initCpt(contcontdoc, "CptAl2", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptAl2"));
	initCpt(contcontdoc, "CptAgd", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptAgd"));
	initCpt(contcontdoc, "CptD", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptD"));
	initCpt(contcontdoc, "CptDph", retrieveTi(srcdoc, "TagPlnrDgdDetail", "CptDph"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 292; // full cont height

// IP refreshB.vars --- BEGIN

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "ButDsnViewAvail") == "true");

	var TxtLvlAlt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtLvlAlt") == "true");
	var TxfLvlValid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfLvlValid") == "true");

	var TxtAv1Alt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtAv1Alt") == "true");
	var TxfAv1Valid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfAv1Valid") == "true");

	var TxtAv2Alt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtAv2Alt") == "true");
	var TxfAv2Valid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfAv2Valid") == "true");

	var TxtAl1Alt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtAl1Alt") == "true");
	var TxfAl1Valid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfAl1Valid") == "true");

	var TxtAl2Alt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtAl2Alt") == "true");
	var TxfAl2Valid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfAl2Valid") == "true");

	var TxtAgdAlt = (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "TxtAgdAlt") == "true");
	var TxfAgdValid = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "TxfAgdValid") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrDgdDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtDsn"));

	if ( (TxtLvlAlt == !contcontdoc.getElementById("TxfLvl")) || (!TxtLvlAlt == !contcontdoc.getElementById("TxtLvl")) ) {
		mytd = contcontdoc.getElementById("dynLvl");
		clearElem(mytd);

		if (TxtLvlAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfLvl", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtLvl", ""));
	};

	if (TxtLvlAlt) refreshTxf(contcontdoc, "TxfLvl", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfLvl"), true, false, TxfLvlValid);
	else refreshTxt(contcontdoc, "TxtLvl", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtLvl"));

	if ( (TxtAv1Alt == !contcontdoc.getElementById("TxfAv1")) || (!TxtAv1Alt == !contcontdoc.getElementById("TxtAv1")) ) {
		mytd = contcontdoc.getElementById("dynAv1");
		clearElem(mytd);

		if (TxtAv1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv1", ""));
	};

	if (TxtAv1Alt) refreshTxf(contcontdoc, "TxfAv1", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfAv1"), true, false, TxfAv1Valid);
	else refreshTxt(contcontdoc, "TxtAv1", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtAv1"));

	if ( (TxtAv2Alt == !contcontdoc.getElementById("TxfAv2")) || (!TxtAv2Alt == !contcontdoc.getElementById("TxtAv2")) ) {
		mytd = contcontdoc.getElementById("dynAv2");
		clearElem(mytd);

		if (TxtAv2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAv2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAv2", ""));
	};

	if (TxtAv2Alt) refreshTxf(contcontdoc, "TxfAv2", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfAv2"), true, false, TxfAv2Valid);
	else refreshTxt(contcontdoc, "TxtAv2", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtAv2"));

	if ( (TxtAl1Alt == !contcontdoc.getElementById("TxfAl1")) || (!TxtAl1Alt == !contcontdoc.getElementById("TxtAl1")) ) {
		mytd = contcontdoc.getElementById("dynAl1");
		clearElem(mytd);

		if (TxtAl1Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAl1", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAl1", ""));
	};

	if (TxtAl1Alt) refreshTxf(contcontdoc, "TxfAl1", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfAl1"), true, false, TxfAl1Valid);
	else refreshTxt(contcontdoc, "TxtAl1", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtAl1"));

	if ( (TxtAl2Alt == !contcontdoc.getElementById("TxfAl2")) || (!TxtAl2Alt == !contcontdoc.getElementById("TxtAl2")) ) {
		mytd = contcontdoc.getElementById("dynAl2");
		clearElem(mytd);

		if (TxtAl2Alt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAl2", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAl2", ""));
	};

	if (TxtAl2Alt) refreshTxf(contcontdoc, "TxfAl2", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfAl2"), true, false, TxfAl2Valid);
	else refreshTxt(contcontdoc, "TxtAl2", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtAl2"));

	if ( (TxtAgdAlt == !contcontdoc.getElementById("TxfAgd")) || (!TxtAgdAlt == !contcontdoc.getElementById("TxtAgd")) ) {
		mytd = contcontdoc.getElementById("dynAgd");
		clearElem(mytd);

		if (TxtAgdAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAgd", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAgd", ""));
	};

	if (TxtAgdAlt) refreshTxf(contcontdoc, "TxfAgd", "", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfAgd"), true, false, TxfAgdValid);
	else refreshTxt(contcontdoc, "TxtAgd", retrieveCi(srcdoc, "ContInfPlnrDgdDetail", "TxtAgd"));

	refreshTxf(contcontdoc, "TxfD", "s", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfD"), true, false, true);

	refreshTxf(contcontdoc, "TxfDph", "s", retrieveCi(srcdoc, "ContIacPlnrDgdDetail", "TxfDph"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDgdDetail", "srefIxPlnrVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppPlnrDgdDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppPlnrDgdDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDgdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDgdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrDgdDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDgdDetailData", scrJref, "ContIacPlnrDgdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrDgdDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDgdDetailData", scrJref, "ContIacPlnrDgdDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrDgdDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDgdDetailData", scrJref, "ContIacPlnrDgdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "ContIacPlnrDgdDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "ContInfPlnrDgdDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "StatAppPlnrDgdDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "StatShrPlnrDgdDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDgdDetailData", "TagPlnrDgdDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDgdDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrDgdDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDgdDetailData") {
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


