/**
  * \file PnlPlnrUsrDetail.js
  * web client functionality for panel PnlPlnrUsrDetail
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Detail", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Detail_side").setAttribute("height", "30");
		doc.getElementById("Detail_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Detail_side").src = "./PnlPlnrUsrDetail_aside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrUsrDetail_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Detail_side").src = "./PnlPlnrUsrDetail_bside.html";
		doc.getElementById("Detail_cont").src = "./PnlPlnrUsrDetail_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrUsrDetail", "Cpt"));

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
	initCpt(contcontdoc, "CptPrs", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptPrs"));
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUsg", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptUsg"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupSte"), true, false);
	initCpt(contcontdoc, "CptLcl", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptLcl"));
	refreshPup(contcontdoc, srcdoc, "PupLcl", "", "FeedFPupLcl", retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupLcl"), true, false);
	initCpt(contcontdoc, "CptUlv", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptUlv"));
	refreshPup(contcontdoc, srcdoc, "PupUlv", "", "FeedFPupUlv", retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupUlv"), true, false);
	initCpt(contcontdoc, "CptPwd", retrieveTi(srcdoc, "TagPlnrUsrDetail", "CptPwd"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 217; // full cont height

// IP refreshB.vars --- BEGIN
	var ButPrsViewAvail = (retrieveSi(srcdoc, "StatShrPlnrUsrDetail", "ButPrsViewAvail") == "true");

	var ButUsgViewAvail = (retrieveSi(srcdoc, "StatShrPlnrUsrDetail", "ButUsgViewAvail") == "true");

	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrPlnrUsrDetail", "ButJEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrPlnrUsrDetail", "ButSaveActive") == "true");
	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	if ((ButPrsViewAvail == !contcontdoc.getElementById("ButPrsView"))) {
		mytd = contcontdoc.getElementById("rdynPrs");
		clearElem(mytd);

		first = true;

		if (ButPrsViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrsView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrs", retrieveCi(srcdoc, "ContInfPlnrUsrDetail", "TxtPrs"));

	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfPlnrUsrDetail", "TxtSrf"));

	if ((ButUsgViewAvail == !contcontdoc.getElementById("ButUsgView"))) {
		mytd = contcontdoc.getElementById("rdynUsg");
		clearElem(mytd);

		first = true;

		if (ButUsgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUsgView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUsg", retrieveCi(srcdoc, "ContInfPlnrUsrDetail", "TxtUsg"));

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

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupJ"), true, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupSte");

	contcontdoc.getElementById("PupLcl").value = retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupLcl");

	contcontdoc.getElementById("PupUlv").value = retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "numFPupUlv");

	refreshTxf(contcontdoc, "TxfPwd", "s", retrieveCi(srcdoc, "ContIacPlnrUsrDetail", "TxfPwd"), true, false, true);

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
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrUsrDetail", "srefIxPlnrVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrUsrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacPlnrUsrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrUsrDetailData", scrJref, "ContIacPlnrUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacPlnrUsrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppPlnrUsrDetailData", scrJref, "ContIacPlnrUsrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacPlnrUsrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrUsrDetailData", scrJref, "ContIacPlnrUsrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "ContIacPlnrUsrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "ContInfPlnrUsrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "FeedFPupLcl", srcdoc)) mask.push("feedFPupLcl");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "FeedFPupUlv", srcdoc)) mask.push("feedFPupUlv");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "StatAppPlnrUsrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "StatShrPlnrUsrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrUsrDetailData", "TagPlnrUsrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrUsrDetailData") {
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
			if (blk.nodeName == "DpchEngPlnrUsrDetailData") {
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

			} else if (blk.nodeName == "DpchEngPlnrUsrDetailData") {
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


