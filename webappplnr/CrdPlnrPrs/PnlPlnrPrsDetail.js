/**
  * \file PnlPlnrPrsDetail.js
  * web client functionality for panel PnlPlnrPrsDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrPrsDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrPrsDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrPrsDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrPrsDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrPrsDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptTit"));
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptFnm"));
	initCpt(contcontdoc, "CptLnm", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptLnm"));
	initCpt(contcontdoc, "CptSex", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptSex"));
	refreshPup(contcontdoc, srcdoc, "PupSex", "", "FeedFPupSex", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numFPupSex"), true, false);
	initCpt(contcontdoc, "CptTel", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptTel"));
	initCpt(contcontdoc, "CptEml", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptEml"));
	initCpt(contcontdoc, "CptSal", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptSal"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 313; // full cont height

// IP refreshB.vars --- BEGIN

	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrPlnrPrsDetail", "ButJEditAvail") == "true");

	var LstDrvAlt = (retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "LstDrvAlt") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrPrsDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "s", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "TxfTit"), true, false, true);

	refreshTxf(contcontdoc, "TxfFnm", "s", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "TxfFnm"), true, false, true);

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

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numFPupJ"), true, false);

	refreshTxt(contcontdoc, "TxtLnm", retrieveCi(srcdoc, "ContInfPlnrPrsDetail", "TxtLnm"));

	height -= setCtlAvail(contcontdoc, "Drv2", !LstDrvAlt, 71);
	if ( (LstDrvAlt == !contcontdoc.getElementById("ButDrvExpand")) || (!LstDrvAlt == !contcontdoc.getElementById("ButDrvCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynDrv");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagPlnrPrsDetail", "CptDrv")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstDrvAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDrvExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButDrvCollapse", "icon/collapse"));
	};

	if ( (LstDrvAlt == !contcontdoc.getElementById("TxtDrv")) || (!LstDrvAlt == !contcontdoc.getElementById("LstDrv")) ) {
		mytd = contcontdoc.getElementById("dynDrv");
		clearElem(mytd);

		if (LstDrvAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtDrv", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstDrv", false));
		};

	} else {
		if (!LstDrvAlt) refreshLst(contcontdoc.getElementById("LstDrv").contentWindow.document, srcdoc, true, "FeedFLstDrv",
					parseInt(retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "LstDrvNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numsFLstDrv")));
	};

	if (LstDrvAlt) refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfPlnrPrsDetail", "TxtDrv"));

	contcontdoc.getElementById("PupSex").value = retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numFPupSex");

	refreshTxf(contcontdoc, "TxfTel", "", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "TxfTel"), true, false, true);

	refreshTxf(contcontdoc, "TxfEml", "", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "TxfEml"), true, false, true);

	refreshTxf(contcontdoc, "TxfSal", "", retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "TxfSal"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrPrsDetail", "srefIxPlnrVExpstate");

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
	setSi(srcdoc, "StatAppPlnrPrsDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrPrsDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrPrsDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrPrsDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacPlnrPrsDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrPrsDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrPrsDetailData", scrJref, "ContIacPlnrPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrPrsDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrPrsDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrPrsDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrPrsDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrPrsDetailData", scrJref, "ContIacPlnrPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrPrsDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrPrsDetailData", scrJref, "ContIacPlnrPrsDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrPrsDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrPrsDetailData", scrJref, "ContIacPlnrPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "ContIacPlnrPrsDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "ContInfPlnrPrsDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "FeedFLstDrv", srcdoc)) mask.push("feedFLstDrv");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "FeedFPupSex", srcdoc)) mask.push("feedFPupSex");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "StatAppPlnrPrsDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "StatShrPlnrPrsDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrPrsDetailData", "TagPlnrPrsDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrPrsDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrPrsDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrPrsDetailData") {
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


