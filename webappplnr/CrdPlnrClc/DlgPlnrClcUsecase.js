/**
  * \file DlgPlnrClcUsecase.js
  * web client functionality for dialog DlgPlnrClcUsecase
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initPrp() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initPrp --- BEGIN
	initCpt(contdoc, "CptPti", retrieveTi(srcdoc, "TagDlgPlnrClcUsecasePrp", "CptPti"));
	initCpt(contdoc, "CptUcs", retrieveTi(srcdoc, "TagDlgPlnrClcUsecasePrp", "CptUcs"));
	refreshPup(contdoc, srcdoc, "PupUcs", "", "FeedFPrpPupUcs", retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecasePrp", "numFPupUcs"), true, false);
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgPlnrClcUsecasePrp", "ButCre"));
// IP initPrp --- END

	setSi(srcdoc, "StatAppDlgPlnrClcUsecase", "initdone", "true");

	refreshPrp();
};

function initCal() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initCal --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgPlnrClcUsecaseCal", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgPlnrClcUsecaseCal", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgPlnrClcUsecaseCal", "ButSto"));
// IP initCal --- END

	setSi(srcdoc, "StatAppDlgPlnrClcUsecase", "initdone", "true");

	refreshCal();
};

function initRfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initRfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgPlnrClcUsecaseRfi", "Dld"));
// IP initRfi --- END

	setSi(srcdoc, "StatAppDlgPlnrClcUsecase", "initdone", "true");

	refreshRfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgPlnrClcUsecase", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgPlnrClcUsecase", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecase", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=3 ; num++) {
		sref = retrieveValue(srcdoc, "//plnr:FeedFDse/plnr:Fi[@num='" + num + "']/plnr:sref");
		Title = retrieveValue(srcdoc, "//plnr:FeedFDse/plnr:Fi[@num='" + num + "']/plnr:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshPrp() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshPrp.vars --- BEGIN

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgPlnrClcUsecasePrp", "ButCreActive") == "true");

// IP refreshPrp.vars --- END

// IP refreshPrp --- BEGIN
	refreshTxf(contdoc, "TxfPti", "", retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecasePrp", "TxfPti"), true, false, true);

	contdoc.getElementById("PupUcs").value = retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecasePrp", "numFPupUcs");

	refreshBut(contdoc, "ButCre", ButCreActive, false);

// IP refreshPrp --- END
};

function refreshCal() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshCal.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgPlnrClcUsecaseCal", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgPlnrClcUsecaseCal", "ButStoActive") == "true");

// IP refreshCal.vars --- END

// IP refreshCal --- BEGIN
	refreshTxt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgPlnrClcUsecaseCal", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshCal --- END
};

function refreshRfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshRfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgPlnrClcUsecaseRfi", "DldActive") == "true");

// IP refreshRfi.vars --- END

// IP refreshRfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

// IP refreshRfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecase", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgPlnrClcUsecase", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgPlnrClcUsecase" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Prp") {
			refreshPrp();
		} else if (shortDit == "Cal") {
			refreshCal();
		} else if (shortDit == "Rfi") {
			refreshRfi();
		};
	};

// IP refresh --- BEGIN
	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- specific event handlers for app controls of dialog item Prp

// --- specific event handlers for app controls of dialog item Cal

// --- specific event handlers for app controls of dialog item Rfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgPlnrClcUsecaseDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrClcUsecase", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgPlnrClcUsecase", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgPlnrClcUsecase", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrClcUsecaseData", scrJref, "ContIacDlgPlnrClcUsecase");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgPlnrClcUsecase" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrClcUsecaseData", scrJref, "ContIacDlgPlnrClcUsecase" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgPlnrClcUsecase" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrClcUsecaseData", scrJref, "ContIacDlgPlnrClcUsecase" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgPlnrClcUsecase" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrClcUsecaseData", scrJref, "ContIacDlgPlnrClcUsecase" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "ContIacDlgPlnrClcUsecase", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "ContIacDlgPlnrClcUsecasePrp", srcdoc)) mask.push("contiacprp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "ContInfDlgPlnrClcUsecase", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "ContInfDlgPlnrClcUsecaseCal", srcdoc)) mask.push("continfcal");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "FeedFPrpPupUcs", srcdoc)) mask.push("feedFPrpPupUcs");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "StatAppDlgPlnrClcUsecase", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "StatShrDlgPlnrClcUsecase", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "StatShrDlgPlnrClcUsecaseCal", srcdoc)) mask.push("statshrcal");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "StatShrDlgPlnrClcUsecasePrp", srcdoc)) mask.push("statshrprp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "StatShrDlgPlnrClcUsecaseRfi", srcdoc)) mask.push("statshrrfi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "TagDlgPlnrClcUsecase", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "TagDlgPlnrClcUsecaseCal", srcdoc)) mask.push("tagcal");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "TagDlgPlnrClcUsecasePrp", srcdoc)) mask.push("tagprp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrClcUsecaseData", "TagDlgPlnrClcUsecaseRfi", srcdoc)) mask.push("tagrfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgPlnrClcUsecaseData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgPlnrClcUsecaseData") {
		handleDpchEngDlgPlnrClcUsecaseData(dom);
	};
};

function handleDpchEngDlgPlnrClcUsecaseData(dom) {
// IP handleDpchEngDlgPlnrClcUsecaseData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgPlnrClcUsecaseData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngPlnrAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
							retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
							retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgPlnrClcUsecaseData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


