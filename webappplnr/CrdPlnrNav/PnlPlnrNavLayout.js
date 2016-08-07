/**
  * \file PnlPlnrNavLayout.js
  * web client functionality for panel PnlPlnrNavLayout
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getCrdwnd().changeHeight("Layout", 30);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Layout_side").setAttribute("height", "30");
		doc.getElementById("Layout_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Layout_side").src = "./PnlPlnrNavLayout_aside.html";
		doc.getElementById("Layout_cont").src = "./PnlPlnrNavLayout_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Layout_side").src = "./PnlPlnrNavLayout_bside.html";
		doc.getElementById("Layout_cont").src = "./PnlPlnrNavLayout_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Layout_side").contentDocument;
	contdoc = doc.getElementById("Layout_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavLayout", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Layout_side").contentDocument;
	contdoc = doc.getElementById("Layout_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Layout_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Layout_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavLayout", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 394; // full cont height

// IP refreshB.vars --- BEGIN
	var LstTpoAlt = (retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstTpoAlt") == "true");
	var LstTpoAvail = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "LstTpoAvail") == "true");
	var ButTpoViewAvail = !LstTpoAlt;
	var ButTpoViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "ButTpoViewActive") == "true");

	var LstArrAlt = (retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstArrAlt") == "true");
	var LstArrAvail = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "LstArrAvail") == "true");
	var ButArrViewAvail = !LstArrAlt;
	var ButArrViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "ButArrViewActive") == "true");

	var LstAriAlt = (retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstAriAlt") == "true");
	var LstAriAvail = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "LstAriAvail") == "true");
	var ButAriViewAvail = !LstAriAlt;
	var ButAriViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "ButAriViewActive") == "true");

	var LstRtcAlt = (retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstRtcAlt") == "true");
	var LstRtcAvail = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "LstRtcAvail") == "true");
	var ButRtcViewAvail = !LstRtcAlt;
	var ButRtcViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavLayout", "ButRtcViewActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Tpo", LstTpoAvail, 96);
	height -= setCtlAvail(contcontdoc, "Tpo2", LstTpoAvail && !LstTpoAlt, 71);
	if (LstTpoAvail) {
		if ( (LstTpoAlt == !contcontdoc.getElementById("ButTpoExpand")) || (!LstTpoAlt == !contcontdoc.getElementById("ButTpoCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTpo");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTpo", retrieveTi(srcdoc, "TagPlnrNavLayout", "CptTpo")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTpoAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTpoExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTpoCollapse", "icon/collapse"));
		};

		if (!LstTpoAlt == !contcontdoc.getElementById("LstTpo")) {
			mytd = contcontdoc.getElementById("rdynTpo");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTpo");
			clearElem(mytd);

			if (LstTpoAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTpo", true));
			};

		} else {
			if (!LstTpoAlt) refreshLst(contcontdoc.getElementById("LstTpo").contentWindow.document, srcdoc, false, "FeedFLstTpo",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstTpoNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numFLstTpo"))]);
		};

		if ((ButTpoViewAvail == !contcontdoc.getElementById("ButTpoView")) || !contcontdoc.getElementById("ButTpoNewcrd")) {
			if (LstTpoAlt) mytd = contcontdoc.getElementById("dynTpo");
			else mytd = contcontdoc.getElementById("rdynTpo");
			clearElem(mytd);

			first = true;

			if (ButTpoViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTpoView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTpoNewcrd", "icon/newcrd"));
		};

		if (ButTpoViewAvail) refreshButicon(contcontdoc, "ButTpoView", "icon/view", ButTpoViewActive, false);

	} else setCtlAvail(contcontdoc, "Tpo2", false, 0);

	height -= setCtlAvail(contcontdoc, "Arr", LstArrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Arr2", LstArrAvail && !LstArrAlt, 71);
	if (LstArrAvail) {
		if ( (LstArrAlt == !contcontdoc.getElementById("ButArrExpand")) || (!LstArrAlt == !contcontdoc.getElementById("ButArrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynArr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptArr", retrieveTi(srcdoc, "TagPlnrNavLayout", "CptArr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstArrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButArrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButArrCollapse", "icon/collapse"));
		};

		if (!LstArrAlt == !contcontdoc.getElementById("LstArr")) {
			mytd = contcontdoc.getElementById("rdynArr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynArr");
			clearElem(mytd);

			if (LstArrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstArr", true));
			};

		} else {
			if (!LstArrAlt) refreshLst(contcontdoc.getElementById("LstArr").contentWindow.document, srcdoc, false, "FeedFLstArr",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstArrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numFLstArr"))]);
		};

		if ((ButArrViewAvail == !contcontdoc.getElementById("ButArrView"))) {
			if (LstArrAlt) mytd = contcontdoc.getElementById("dynArr");
			else mytd = contcontdoc.getElementById("rdynArr");
			clearElem(mytd);

			first = true;

			if (ButArrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButArrView", "icon/view"));
			};
		};

		if (ButArrViewAvail) refreshButicon(contcontdoc, "ButArrView", "icon/view", ButArrViewActive, false);

	} else setCtlAvail(contcontdoc, "Arr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ari", LstAriAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ari2", LstAriAvail && !LstAriAlt, 71);
	if (LstAriAvail) {
		if ( (LstAriAlt == !contcontdoc.getElementById("ButAriExpand")) || (!LstAriAlt == !contcontdoc.getElementById("ButAriCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynAri");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptAri", retrieveTi(srcdoc, "TagPlnrNavLayout", "CptAri")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstAriAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButAriExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButAriCollapse", "icon/collapse"));
		};

		if (!LstAriAlt == !contcontdoc.getElementById("LstAri")) {
			mytd = contcontdoc.getElementById("rdynAri");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynAri");
			clearElem(mytd);

			if (LstAriAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstAri", true));
			};

		} else {
			if (!LstAriAlt) refreshLst(contcontdoc.getElementById("LstAri").contentWindow.document, srcdoc, false, "FeedFLstAri",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstAriNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numFLstAri"))]);
		};

		if ((ButAriViewAvail == !contcontdoc.getElementById("ButAriView"))) {
			if (LstAriAlt) mytd = contcontdoc.getElementById("dynAri");
			else mytd = contcontdoc.getElementById("rdynAri");
			clearElem(mytd);

			first = true;

			if (ButAriViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButAriView", "icon/view"));
			};
		};

		if (ButAriViewAvail) refreshButicon(contcontdoc, "ButAriView", "icon/view", ButAriViewActive, false);

	} else setCtlAvail(contcontdoc, "Ari2", false, 0);

	height -= setCtlAvail(contcontdoc, "Rtc", LstRtcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Rtc2", LstRtcAvail && !LstRtcAlt, 71);
	if (LstRtcAvail) {
		if ( (LstRtcAlt == !contcontdoc.getElementById("ButRtcExpand")) || (!LstRtcAlt == !contcontdoc.getElementById("ButRtcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRtc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRtc", retrieveTi(srcdoc, "TagPlnrNavLayout", "CptRtc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRtcAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRtcExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRtcCollapse", "icon/collapse"));
		};

		if (!LstRtcAlt == !contcontdoc.getElementById("LstRtc")) {
			mytd = contcontdoc.getElementById("rdynRtc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRtc");
			clearElem(mytd);

			if (LstRtcAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRtc", true));
			};

		} else {
			if (!LstRtcAlt) refreshLst(contcontdoc.getElementById("LstRtc").contentWindow.document, srcdoc, false, "FeedFLstRtc",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", "LstRtcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numFLstRtc"))]);
		};

		if ((ButRtcViewAvail == !contcontdoc.getElementById("ButRtcView"))) {
			if (LstRtcAlt) mytd = contcontdoc.getElementById("dynRtc");
			else mytd = contcontdoc.getElementById("rdynRtc");
			clearElem(mytd);

			first = true;

			if (ButRtcViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRtcView", "icon/view"));
			};
		};

		if (ButRtcViewAvail) refreshButicon(contcontdoc, "ButRtcView", "icon/view", ButRtcViewActive, false);

	} else setCtlAvail(contcontdoc, "Rtc2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Layout", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Layout_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Layout_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Layout_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavLayout", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Layout_src").contentDocument;

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
	setSi(srcdoc, "StatAppPlnrNavLayout", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavLayout", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavLayoutDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavLayoutDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacPlnrNavLayout", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrNavLayout", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrNavLayoutData", scrJref, "ContIacPlnrNavLayout");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrNavLayout", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrNavLayout", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavLayout", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "ContIacPlnrNavLayout", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "FeedFLstAri", srcdoc)) mask.push("feedFLstAri");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "FeedFLstArr", srcdoc)) mask.push("feedFLstArr");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "FeedFLstRtc", srcdoc)) mask.push("feedFLstRtc");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "FeedFLstTpo", srcdoc)) mask.push("feedFLstTpo");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "StatAppPlnrNavLayout", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "StatShrPlnrNavLayout", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavLayoutData", "TagPlnrNavLayout", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrNavLayoutData") {
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
			if (blk.nodeName == "DpchEngPlnrNavLayoutData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Layout");
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

			} else if (blk.nodeName == "DpchEngPlnrNavLayoutData") {
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


