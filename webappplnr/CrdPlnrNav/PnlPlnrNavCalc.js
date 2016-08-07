/**
  * \file PnlPlnrNavCalc.js
  * web client functionality for panel PnlPlnrNavCalc
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getCrdwnd().changeHeight("Calc", 30);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Calc_side").setAttribute("height", "30");
		doc.getElementById("Calc_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Calc_side").src = "./PnlPlnrNavCalc_aside.html";
		doc.getElementById("Calc_cont").src = "./PnlPlnrNavCalc_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Calc_side").src = "./PnlPlnrNavCalc_bside.html";
		doc.getElementById("Calc_cont").src = "./PnlPlnrNavCalc_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Calc_side").contentDocument;
	contdoc = doc.getElementById("Calc_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavCalc", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Calc_side").contentDocument;
	contdoc = doc.getElementById("Calc_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Calc_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Calc_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavCalc", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 202; // full cont height

// IP refreshB.vars --- BEGIN
	var LstClcAlt = (retrieveSi(srcdoc, "StatAppPlnrNavCalc", "LstClcAlt") == "true");
	var LstClcAvail = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "LstClcAvail") == "true");
	var ButClcViewAvail = !LstClcAlt;
	var ButClcViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "ButClcViewActive") == "true");
	var ButClcNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "ButClcNewcrdActive") == "true");

	var LstCliAlt = (retrieveSi(srcdoc, "StatAppPlnrNavCalc", "LstCliAlt") == "true");
	var LstCliAvail = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "LstCliAvail") == "true");
	var ButCliViewAvail = !LstCliAlt;
	var ButCliViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "ButCliViewActive") == "true");
	var ButCliNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavCalc", "ButCliNewcrdActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Clc", LstClcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Clc2", LstClcAvail && !LstClcAlt, 71);
	if (LstClcAvail) {
		if ( (LstClcAlt == !contcontdoc.getElementById("ButClcExpand")) || (!LstClcAlt == !contcontdoc.getElementById("ButClcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynClc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptClc", retrieveTi(srcdoc, "TagPlnrNavCalc", "CptClc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstClcAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButClcExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButClcCollapse", "icon/collapse"));
		};

		if (!LstClcAlt == !contcontdoc.getElementById("LstClc")) {
			mytd = contcontdoc.getElementById("rdynClc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynClc");
			clearElem(mytd);

			if (LstClcAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstClc", true));
			};

		} else {
			if (!LstClcAlt) refreshLst(contcontdoc.getElementById("LstClc").contentWindow.document, srcdoc, false, "FeedFLstClc",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavCalc", "LstClcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numFLstClc"))]);
		};

		if ((ButClcViewAvail == !contcontdoc.getElementById("ButClcView")) || !contcontdoc.getElementById("ButClcNewcrd")) {
			if (LstClcAlt) mytd = contcontdoc.getElementById("dynClc");
			else mytd = contcontdoc.getElementById("rdynClc");
			clearElem(mytd);

			first = true;

			if (ButClcViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButClcView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButClcNewcrd", "icon/newcrd"));
		};

		if (ButClcViewAvail) refreshButicon(contcontdoc, "ButClcView", "icon/view", ButClcViewActive, false);
		refreshButicon(contcontdoc, "ButClcNewcrd", "icon/newcrd", ButClcNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Clc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cli", LstCliAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cli2", LstCliAvail && !LstCliAlt, 71);
	if (LstCliAvail) {
		if ( (LstCliAlt == !contcontdoc.getElementById("ButCliExpand")) || (!LstCliAlt == !contcontdoc.getElementById("ButCliCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCli");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCli", retrieveTi(srcdoc, "TagPlnrNavCalc", "CptCli")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCliAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCliExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCliCollapse", "icon/collapse"));
		};

		if (!LstCliAlt == !contcontdoc.getElementById("LstCli")) {
			mytd = contcontdoc.getElementById("rdynCli");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCli");
			clearElem(mytd);

			if (LstCliAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCli", true));
			};

		} else {
			if (!LstCliAlt) refreshLst(contcontdoc.getElementById("LstCli").contentWindow.document, srcdoc, false, "FeedFLstCli",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavCalc", "LstCliNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numFLstCli"))]);
		};

		if ((ButCliViewAvail == !contcontdoc.getElementById("ButCliView")) || !contcontdoc.getElementById("ButCliNewcrd")) {
			if (LstCliAlt) mytd = contcontdoc.getElementById("dynCli");
			else mytd = contcontdoc.getElementById("rdynCli");
			clearElem(mytd);

			first = true;

			if (ButCliViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCliView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCliNewcrd", "icon/newcrd"));
		};

		if (ButCliViewAvail) refreshButicon(contcontdoc, "ButCliView", "icon/view", ButCliViewActive, false);
		refreshButicon(contcontdoc, "ButCliNewcrd", "icon/newcrd", ButCliNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cli2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Calc", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Calc_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Calc_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Calc_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavCalc", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Calc_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavCalc", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavCalc", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavCalcDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavCalcDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavCalc", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavCalc", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacPlnrNavCalc", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrNavCalc", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrNavCalcData", scrJref, "ContIacPlnrNavCalc");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrNavCalc", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrNavCalc", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavCalc", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "ContIacPlnrNavCalc", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "FeedFLstClc", srcdoc)) mask.push("feedFLstClc");
	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "FeedFLstCli", srcdoc)) mask.push("feedFLstCli");
	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "StatAppPlnrNavCalc", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "StatShrPlnrNavCalc", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavCalcData", "TagPlnrNavCalc", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrNavCalcData") {
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
			if (blk.nodeName == "DpchEngPlnrNavCalcData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Calc");
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

			} else if (blk.nodeName == "DpchEngPlnrNavCalcData") {
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


