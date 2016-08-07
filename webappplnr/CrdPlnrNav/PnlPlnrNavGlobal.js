/**
  * \file PnlPlnrNavGlobal.js
  * web client functionality for panel PnlPlnrNavGlobal
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getCrdwnd().changeHeight("Global", 30);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Global_side").setAttribute("height", "30");
		doc.getElementById("Global_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Global_side").src = "./PnlPlnrNavGlobal_aside.html";
		doc.getElementById("Global_cont").src = "./PnlPlnrNavGlobal_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Global_side").src = "./PnlPlnrNavGlobal_bside.html";
		doc.getElementById("Global_cont").src = "./PnlPlnrNavGlobal_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavGlobal", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Global_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Global_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavGlobal", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 298; // full cont height

// IP refreshB.vars --- BEGIN
	var LstDtpAlt = (retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstDtpAlt") == "true");
	var LstDtpAvail = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "LstDtpAvail") == "true");
	var ButDtpViewAvail = !LstDtpAlt;
	var ButDtpViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "ButDtpViewActive") == "true");

	var LstCtpAlt = (retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstCtpAlt") == "true");
	var LstCtpAvail = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "LstCtpAvail") == "true");
	var ButCtpViewAvail = !LstCtpAlt;
	var ButCtpViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "ButCtpViewActive") == "true");

	var LstMatAlt = (retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstMatAlt") == "true");
	var LstMatAvail = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "LstMatAvail") == "true");
	var ButMatViewAvail = !LstMatAlt;
	var ButMatViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavGlobal", "ButMatViewActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Dtp", LstDtpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dtp2", LstDtpAvail && !LstDtpAlt, 71);
	if (LstDtpAvail) {
		if ( (LstDtpAlt == !contcontdoc.getElementById("ButDtpExpand")) || (!LstDtpAlt == !contcontdoc.getElementById("ButDtpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDtp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDtp", retrieveTi(srcdoc, "TagPlnrNavGlobal", "CptDtp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDtpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDtpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDtpCollapse", "icon/collapse"));
		};

		if (!LstDtpAlt == !contcontdoc.getElementById("LstDtp")) {
			mytd = contcontdoc.getElementById("rdynDtp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDtp");
			clearElem(mytd);

			if (LstDtpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDtp", true));
			};

		} else {
			if (!LstDtpAlt) refreshLst(contcontdoc.getElementById("LstDtp").contentWindow.document, srcdoc, false, "FeedFLstDtp",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstDtpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numFLstDtp"))]);
		};

		if ((ButDtpViewAvail == !contcontdoc.getElementById("ButDtpView")) || !contcontdoc.getElementById("ButDtpNewcrd")) {
			if (LstDtpAlt) mytd = contcontdoc.getElementById("dynDtp");
			else mytd = contcontdoc.getElementById("rdynDtp");
			clearElem(mytd);

			first = true;

			if (ButDtpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDtpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDtpNewcrd", "icon/newcrd"));
		};

		if (ButDtpViewAvail) refreshButicon(contcontdoc, "ButDtpView", "icon/view", ButDtpViewActive, false);

	} else setCtlAvail(contcontdoc, "Dtp2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ctp", LstCtpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ctp2", LstCtpAvail && !LstCtpAlt, 71);
	if (LstCtpAvail) {
		if ( (LstCtpAlt == !contcontdoc.getElementById("ButCtpExpand")) || (!LstCtpAlt == !contcontdoc.getElementById("ButCtpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCtp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCtp", retrieveTi(srcdoc, "TagPlnrNavGlobal", "CptCtp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCtpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCtpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCtpCollapse", "icon/collapse"));
		};

		if (!LstCtpAlt == !contcontdoc.getElementById("LstCtp")) {
			mytd = contcontdoc.getElementById("rdynCtp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCtp");
			clearElem(mytd);

			if (LstCtpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCtp", true));
			};

		} else {
			if (!LstCtpAlt) refreshLst(contcontdoc.getElementById("LstCtp").contentWindow.document, srcdoc, false, "FeedFLstCtp",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstCtpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numFLstCtp"))]);
		};

		if ((ButCtpViewAvail == !contcontdoc.getElementById("ButCtpView")) || !contcontdoc.getElementById("ButCtpNewcrd")) {
			if (LstCtpAlt) mytd = contcontdoc.getElementById("dynCtp");
			else mytd = contcontdoc.getElementById("rdynCtp");
			clearElem(mytd);

			first = true;

			if (ButCtpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCtpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCtpNewcrd", "icon/newcrd"));
		};

		if (ButCtpViewAvail) refreshButicon(contcontdoc, "ButCtpView", "icon/view", ButCtpViewActive, false);

	} else setCtlAvail(contcontdoc, "Ctp2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mat", LstMatAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mat2", LstMatAvail && !LstMatAlt, 71);
	if (LstMatAvail) {
		if ( (LstMatAlt == !contcontdoc.getElementById("ButMatExpand")) || (!LstMatAlt == !contcontdoc.getElementById("ButMatCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMat");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMat", retrieveTi(srcdoc, "TagPlnrNavGlobal", "CptMat")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMatAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMatExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMatCollapse", "icon/collapse"));
		};

		if (!LstMatAlt == !contcontdoc.getElementById("LstMat")) {
			mytd = contcontdoc.getElementById("rdynMat");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMat");
			clearElem(mytd);

			if (LstMatAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMat", true));
			};

		} else {
			if (!LstMatAlt) refreshLst(contcontdoc.getElementById("LstMat").contentWindow.document, srcdoc, false, "FeedFLstMat",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "LstMatNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numFLstMat"))]);
		};

		if ((ButMatViewAvail == !contcontdoc.getElementById("ButMatView")) || !contcontdoc.getElementById("ButMatNewcrd")) {
			if (LstMatAlt) mytd = contcontdoc.getElementById("dynMat");
			else mytd = contcontdoc.getElementById("rdynMat");
			clearElem(mytd);

			first = true;

			if (ButMatViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMatView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMatNewcrd", "icon/newcrd"));
		};

		if (ButMatViewAvail) refreshButicon(contcontdoc, "ButMatView", "icon/view", ButMatViewActive, false);

	} else setCtlAvail(contcontdoc, "Mat2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Global", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Global_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavGlobal", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Global_src").contentDocument;

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
	setSi(srcdoc, "StatAppPlnrNavGlobal", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavGlobal", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacPlnrNavGlobal", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrNavGlobal", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrNavGlobalData", scrJref, "ContIacPlnrNavGlobal");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrNavGlobal", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrNavGlobal", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavGlobal", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "ContIacPlnrNavGlobal", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "FeedFLstCtp", srcdoc)) mask.push("feedFLstCtp");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "FeedFLstDtp", srcdoc)) mask.push("feedFLstDtp");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "FeedFLstMat", srcdoc)) mask.push("feedFLstMat");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "StatAppPlnrNavGlobal", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "StatShrPlnrNavGlobal", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavGlobalData", "TagPlnrNavGlobal", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrNavGlobalData") {
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
			if (blk.nodeName == "DpchEngPlnrNavGlobalData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Global");
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

			} else if (blk.nodeName == "DpchEngPlnrNavGlobalData") {
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


