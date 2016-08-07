/**
  * \file DlgPlnrTpoUsecase.js
  * web client functionality for dialog DlgPlnrTpoUsecase
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initPrp() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initPrp --- BEGIN
	initCpt(contdoc, "CptPti", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecasePrp", "CptPti"));
	initCpt(contdoc, "CptUcs", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecasePrp", "CptUcs"));
	refreshPup(contdoc, srcdoc, "PupUcs", "", "FeedFPrpPupUcs", retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecasePrp", "numFPupUcs"), true, false);
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecasePrp", "ButCre"));
// IP initPrp --- END

	setSi(srcdoc, "StatAppDlgPlnrTpoUsecase", "initdone", "true");

	refreshPrp();
};

function initGen() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initGen --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecaseGen", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecaseGen", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgPlnrTpoUsecaseGen", "ButSto"));
// IP initGen --- END

	setSi(srcdoc, "StatAppDlgPlnrTpoUsecase", "initdone", "true");

	refreshGen();
};

function initCfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initCfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgPlnrTpoUsecaseCfi", "Dld"));
// IP initCfi --- END

	setSi(srcdoc, "StatAppDlgPlnrTpoUsecase", "initdone", "true");

	refreshCfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgPlnrTpoUsecase", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgPlnrTpoUsecase", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecase", "numFDse"));

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

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgPlnrTpoUsecasePrp", "ButCreActive") == "true");

// IP refreshPrp.vars --- END

// IP refreshPrp --- BEGIN
	refreshTxf(contdoc, "TxfPti", "", retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecasePrp", "TxfPti"), true, false, true);

	contdoc.getElementById("PupUcs").value = retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecasePrp", "numFPupUcs");

	refreshBut(contdoc, "ButCre", ButCreActive, false);

// IP refreshPrp --- END
};

function refreshGen() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshGen.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgPlnrTpoUsecaseGen", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgPlnrTpoUsecaseGen", "ButStoActive") == "true");

// IP refreshGen.vars --- END

// IP refreshGen --- BEGIN
	refreshTxt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgPlnrTpoUsecaseGen", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshGen --- END
};

function refreshCfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshCfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgPlnrTpoUsecaseCfi", "DldActive") == "true");

// IP refreshCfi.vars --- END

// IP refreshCfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

// IP refreshCfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecase", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgPlnrTpoUsecase", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgPlnrTpoUsecase" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Prp") {
			refreshPrp();
		} else if (shortDit == "Gen") {
			refreshGen();
		} else if (shortDit == "Cfi") {
			refreshCfi();
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

// --- specific event handlers for app controls of dialog item Gen

// --- specific event handlers for app controls of dialog item Cfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgPlnrTpoUsecaseDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrTpoUsecase", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgPlnrTpoUsecase", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgPlnrTpoUsecase", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrTpoUsecaseData", scrJref, "ContIacDlgPlnrTpoUsecase");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgPlnrTpoUsecase" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrTpoUsecaseData", scrJref, "ContIacDlgPlnrTpoUsecase" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgPlnrTpoUsecase" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrTpoUsecaseData", scrJref, "ContIacDlgPlnrTpoUsecase" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgPlnrTpoUsecase" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrTpoUsecaseData", scrJref, "ContIacDlgPlnrTpoUsecase" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "ContIacDlgPlnrTpoUsecase", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "ContIacDlgPlnrTpoUsecasePrp", srcdoc)) mask.push("contiacprp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "ContInfDlgPlnrTpoUsecase", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "ContInfDlgPlnrTpoUsecaseGen", srcdoc)) mask.push("continfgen");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "FeedFPrpPupUcs", srcdoc)) mask.push("feedFPrpPupUcs");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "StatAppDlgPlnrTpoUsecase", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "StatShrDlgPlnrTpoUsecase", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "StatShrDlgPlnrTpoUsecaseCfi", srcdoc)) mask.push("statshrcfi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "StatShrDlgPlnrTpoUsecaseGen", srcdoc)) mask.push("statshrgen");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "StatShrDlgPlnrTpoUsecasePrp", srcdoc)) mask.push("statshrprp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "TagDlgPlnrTpoUsecase", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "TagDlgPlnrTpoUsecaseCfi", srcdoc)) mask.push("tagcfi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "TagDlgPlnrTpoUsecaseGen", srcdoc)) mask.push("taggen");
	if (updateSrcblock(dom, "DpchEngDlgPlnrTpoUsecaseData", "TagDlgPlnrTpoUsecasePrp", srcdoc)) mask.push("tagprp");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgPlnrTpoUsecaseData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgPlnrTpoUsecaseData") {
		handleDpchEngDlgPlnrTpoUsecaseData(dom);
	};
};

function handleDpchEngDlgPlnrTpoUsecaseData(dom) {
// IP handleDpchEngDlgPlnrTpoUsecaseData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgPlnrTpoUsecaseData") {
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

			} else if (blk.nodeName == "DpchEngDlgPlnrTpoUsecaseData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


