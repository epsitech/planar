/**
  * \file PnlPlnrDsnDetail.js
  * web client functionality for panel PnlPlnrDsnDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrDsnDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDsnDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrDsnDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrDsnDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDsnDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupTyp"), true, false);
	initCpt(contcontdoc, "CptDim", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptDim"));
	refreshPup(contcontdoc, srcdoc, "PupDim", "", "FeedFPupDim", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupDim"), true, false);
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptPrj"));
	initCpt(contcontdoc, "CptMod", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptMod"));
	initCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptDrv"));
	initCpt(contcontdoc, "CptMaj", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptMaj"));
	initCpt(contcontdoc, "CptSub", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptSub"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptCmt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 413; // full cont height

// IP refreshB.vars --- BEGIN

	var ButPrjViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnDetail", "ButPrjViewAvail") == "true");

	var LstMtyAlt = (retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "LstMtyAlt") == "true");

	var ButModViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnDetail", "ButModViewAvail") == "true");

	var ButDrvViewAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnDetail", "ButDrvViewAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrDsnDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "TxfTit"), true, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupTyp");

	contcontdoc.getElementById("PupDim").value = retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupDim");

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfPlnrDsnDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numFPupRet");

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

	refreshTxt(contcontdoc, "TxtPrj", retrieveCi(srcdoc, "ContInfPlnrDsnDetail", "TxtPrj"));

	height -= setCtlAvail(contcontdoc, "Mty2", !LstMtyAlt, 71);
	if ( (LstMtyAlt == !contcontdoc.getElementById("ButMtyExpand")) || (!LstMtyAlt == !contcontdoc.getElementById("ButMtyCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynMty");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptMty", retrieveTi(srcdoc, "TagPlnrDsnDetail", "CptMty")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstMtyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMtyExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButMtyCollapse", "icon/collapse"));
	};

	if ( (LstMtyAlt == !contcontdoc.getElementById("TxtMty")) || (!LstMtyAlt == !contcontdoc.getElementById("LstMty")) ) {
		mytd = contcontdoc.getElementById("dynMty");
		clearElem(mytd);

		if (LstMtyAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtMty", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstMty", false));
		};

	} else {
		if (!LstMtyAlt) refreshLst(contcontdoc.getElementById("LstMty").contentWindow.document, srcdoc, true, "FeedFLstMty",
					parseInt(retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "LstMtyNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numsFLstMty")));
	};

	if (LstMtyAlt) refreshTxt(contcontdoc, "TxtMty", retrieveCi(srcdoc, "ContInfPlnrDsnDetail", "TxtMty"));

	if ((ButModViewAvail == !contcontdoc.getElementById("ButModView"))) {
		mytd = contcontdoc.getElementById("rdynMod");
		clearElem(mytd);

		first = true;

		if (ButModViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButModView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMod", retrieveCi(srcdoc, "ContInfPlnrDsnDetail", "TxtMod"));

	if ((ButDrvViewAvail == !contcontdoc.getElementById("ButDrvView"))) {
		mytd = contcontdoc.getElementById("rdynDrv");
		clearElem(mytd);

		first = true;

		if (ButDrvViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDrvView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfPlnrDsnDetail", "TxtDrv"));

	refreshTxf(contcontdoc, "TxfMaj", "s", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "TxfMaj"), true, false, true);

	refreshTxf(contcontdoc, "TxfSub", "s", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "TxfSub"), true, false, true);

	refreshTxf(contcontdoc, "TxfCmt", "t", retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "TxfCmt"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnDetail", "srefIxPlnrVExpstate");

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
	setSi(srcdoc, "StatAppPlnrDsnDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrDsnDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDsnDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDsnDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrDsnDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrDsnDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacPlnrDsnDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrDsnDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDsnDetailData", scrJref, "ContIacPlnrDsnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrDsnDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrDsnDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrDsnDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrDsnDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDsnDetailData", scrJref, "ContIacPlnrDsnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrDsnDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDsnDetailData", scrJref, "ContIacPlnrDsnDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrDsnDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrDsnDetailData", scrJref, "ContIacPlnrDsnDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "ContIacPlnrDsnDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "ContInfPlnrDsnDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "FeedFLstMty", srcdoc)) mask.push("feedFLstMty");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "FeedFPupDim", srcdoc)) mask.push("feedFPupDim");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "StatAppPlnrDsnDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "StatShrPlnrDsnDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDsnDetailData", "TagPlnrDsnDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDsnDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrDsnDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrDsnDetailData") {
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


