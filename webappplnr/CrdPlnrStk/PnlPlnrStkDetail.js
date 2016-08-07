/**
  * \file PnlPlnrStkDetail.js
  * web client functionality for panel PnlPlnrStkDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrStkDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrStkDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrStkDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrStkDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrStkDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptDsn"));
	initCpt(contcontdoc, "CptMty", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptMty"));
	refreshPup(contcontdoc, srcdoc, "PupMty", "", "FeedFPupMty", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupMty"), true, false);
	initCpt(contcontdoc, "CptFal", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptFal"));
	refreshPup(contcontdoc, srcdoc, "PupFal", "", "FeedFPupFal", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupFal"), true, false);
	initCpt(contcontdoc, "CptFlr", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptFlr"));
	initCpt(contcontdoc, "CptZfl", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptZfl"));
	initCpt(contcontdoc, "CptCal", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptCal"));
	refreshPup(contcontdoc, srcdoc, "PupCal", "", "FeedFPupCal", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupCal"), true, false);
	initCpt(contcontdoc, "CptCil", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptCil"));
	initCpt(contcontdoc, "CptZci", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptZci"));
	initCpt(contcontdoc, "CptN", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptN"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 388; // full cont height

// IP refreshB.vars --- BEGIN

	var ButDsnViewAvail = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "ButDsnViewAvail") == "true");

	var TxtFlrAlt = (retrieveSi(srcdoc, "StatAppPlnrStkDetail", "TxtFlrAlt") == "true");
	var TxfFlrValid = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "TxfFlrValid") == "true");

	var TxtCilAlt = (retrieveSi(srcdoc, "StatAppPlnrStkDetail", "TxtCilAlt") == "true");
	var TxfCilValid = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "TxfCilValid") == "true");

	var LstLyrAlt = (retrieveSi(srcdoc, "StatAppPlnrStkDetail", "LstLyrAlt") == "true");
	var TxfLyrValid = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "TxfLyrValid") == "true");
	var ButLyrViewAvail = !LstLyrAlt && (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "ButLyrViewAvail") == "true");;
	var ButLyrViewActive = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "ButLyrViewActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrStkDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrStkDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtDsn", retrieveCi(srcdoc, "ContInfPlnrStkDetail", "TxtDsn"));

	contcontdoc.getElementById("PupMty").value = retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupMty");

	contcontdoc.getElementById("PupFal").value = retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupFal");

	if ( (TxtFlrAlt == !contcontdoc.getElementById("TxfFlr")) || (!TxtFlrAlt == !contcontdoc.getElementById("TxtFlr")) ) {
		mytd = contcontdoc.getElementById("dynFlr");
		clearElem(mytd);

		if (TxtFlrAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfFlr", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtFlr", ""));
	};

	if (TxtFlrAlt) refreshTxf(contcontdoc, "TxfFlr", "", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfFlr"), true, false, TxfFlrValid);
	else refreshTxt(contcontdoc, "TxtFlr", retrieveCi(srcdoc, "ContInfPlnrStkDetail", "TxtFlr"));

	refreshTxf(contcontdoc, "TxfZfl", "s", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfZfl"), true, false, true);

	contcontdoc.getElementById("PupCal").value = retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFPupCal");

	if ( (TxtCilAlt == !contcontdoc.getElementById("TxfCil")) || (!TxtCilAlt == !contcontdoc.getElementById("TxtCil")) ) {
		mytd = contcontdoc.getElementById("dynCil");
		clearElem(mytd);

		if (TxtCilAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCil", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtCil", ""));
	};

	if (TxtCilAlt) refreshTxf(contcontdoc, "TxfCil", "", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfCil"), true, false, TxfCilValid);
	else refreshTxt(contcontdoc, "TxtCil", retrieveCi(srcdoc, "ContInfPlnrStkDetail", "TxtCil"));

	refreshTxf(contcontdoc, "TxfZci", "s", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfZci"), true, false, true);

	height -= setCtlAvail(contcontdoc, "Lyr2", !LstLyrAlt, 71);
	if ( (LstLyrAlt == !contcontdoc.getElementById("ButLyrExpand")) || (!LstLyrAlt == !contcontdoc.getElementById("ButLyrCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynLyr");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptLyr", retrieveTi(srcdoc, "TagPlnrStkDetail", "CptLyr")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstLyrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLyrExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButLyrCollapse", "icon/collapse"));
	};

	if ( (LstLyrAlt == !contcontdoc.getElementById("TxfLyr")) || (!LstLyrAlt == !contcontdoc.getElementById("LstLyr")) ) {
		mytd = contcontdoc.getElementById("dynLyr");
		clearElem(mytd);

		if (LstLyrAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfLyr", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstLyr", false));
		};

	} else {
		if (!LstLyrAlt) refreshLst(contcontdoc.getElementById("LstLyr").contentWindow.document, srcdoc, false, "FeedFLstLyr",
					parseInt(retrieveSi(srcdoc, "StatAppPlnrStkDetail", "LstLyrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numFLstLyr"))]);
	};

	if (LstLyrAlt) refreshTxf(contcontdoc, "TxfLyr", "", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfLyr"), true, false, TxfLyrValid);

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

	if (ButLyrViewAvail) refreshButicon(contcontdoc, "ButLyrView", "icon/view", ButLyrViewActive, false);

	refreshTxf(contcontdoc, "TxfN", "s", retrieveCi(srcdoc, "ContIacPlnrStkDetail", "TxfN"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrStkDetail", "srefIxPlnrVExpstate");

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrStkDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrStkDetail", basectlsref + "Alt", "false");
	refresh();
};

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppPlnrStkDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppPlnrStkDetail", basectlsref + "Alt", alt);

	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrStkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrStkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrStkDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrStkDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numsF" + ctlsref));

		found = false;

		for (var i=0;i<oldNumsFLst.length;i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j=0;j<oldNumsFLst.length;j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i=0;i<oldNumsFLst.length;i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacPlnrStkDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrStkDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrStkDetailData", scrJref, "ContIacPlnrStkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrStkDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrStkDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrStkDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrStkDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrStkDetailData", scrJref, "ContIacPlnrStkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrStkDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrStkDetailData", scrJref, "ContIacPlnrStkDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrStkDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrStkDetailData", scrJref, "ContIacPlnrStkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "ContIacPlnrStkDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "ContInfPlnrStkDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "FeedFLstLyr", srcdoc)) mask.push("feedFLstLyr");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "FeedFPupCal", srcdoc)) mask.push("feedFPupCal");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "FeedFPupFal", srcdoc)) mask.push("feedFPupFal");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "FeedFPupMty", srcdoc)) mask.push("feedFPupMty");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "StatAppPlnrStkDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "StatShrPlnrStkDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrStkDetailData", "TagPlnrStkDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrStkDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrStkDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrStkDetailData") {
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


