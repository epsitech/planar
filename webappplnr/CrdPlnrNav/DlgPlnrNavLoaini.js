/**
  * \file DlgPlnrNavLoaini.js
  * web client functionality for dialog DlgPlnrNavLoaini
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgPlnrNavLoainiIfi", "Uld");
// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiImp", "ButSto"));
// IP initImp --- END

	setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "true");

	refreshImp();
};

function initAcv() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initAcv --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiAcv", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgPlnrNavLoainiAcv", "Uld");
// IP initAcv --- END

	setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "true");

	refreshAcv();
};

function initPpr() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initPpr --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiPpr", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiPpr", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgPlnrNavLoainiPpr", "ButSto"));
// IP initPpr --- END

	setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "true");

	refreshPpr();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgPlnrNavLoainiLfi", "Dld"));
// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgPlnrNavLoaini", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgPlnrNavLoaini", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrNavLoaini", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=5 ; num++) {
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

function refreshIfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiIfi", "UldActive") == "true");

// IP refreshIfi.vars --- END

// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

// IP refreshIfi --- END
};

function refreshImp() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiImp", "ButStoActive") == "true");

// IP refreshImp.vars --- END

// IP refreshImp --- BEGIN
	refreshTxt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgPlnrNavLoainiImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshImp --- END
};

function refreshAcv() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshAcv.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiAcv", "UldActive") == "true");

// IP refreshAcv.vars --- END

// IP refreshAcv --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

// IP refreshAcv --- END
};

function refreshPpr() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshPpr.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiPpr", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiPpr", "ButStoActive") == "true");

// IP refreshPpr.vars --- END

// IP refreshPpr --- BEGIN
	refreshTxt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgPlnrNavLoainiPpr", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

// IP refreshPpr --- END
};

function refreshLfi() {
	if (!contdoc.getElementById("tbl")) return;

// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoainiLfi", "DldActive") == "true");

// IP refreshLfi.vars --- END

// IP refreshLfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgPlnrNavLoaini", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgPlnrNavLoaini", "ButDneActive") == "true");
// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgPlnrNavLoaini" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
		} else if (shortDit == "Acv") {
			refreshAcv();
		} else if (shortDit == "Ppr") {
			refreshPpr();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Acv

// --- specific event handlers for app controls of dialog item Ppr

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgPlnrNavLoainiDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgPlnrNavLoaini", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgPlnrNavLoaini", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgPlnrNavLoaini", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgPlnrNavLoainiData", scrJref, "ContIacDlgPlnrNavLoaini");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "ContIacDlgPlnrNavLoaini", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "ContInfDlgPlnrNavLoaini", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "ContInfDlgPlnrNavLoainiImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "ContInfDlgPlnrNavLoainiPpr", srcdoc)) mask.push("continfppr");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatAppDlgPlnrNavLoaini", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoaini", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoainiAcv", srcdoc)) mask.push("statshracv");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoainiIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoainiImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoainiLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "StatShrDlgPlnrNavLoainiPpr", srcdoc)) mask.push("statshrppr");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoaini", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoainiAcv", srcdoc)) mask.push("tagacv");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoainiIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoainiImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoainiLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgPlnrNavLoainiData", "TagDlgPlnrNavLoainiPpr", srcdoc)) mask.push("tagppr");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgPlnrNavLoainiData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgPlnrNavLoainiData") {
		handleDpchEngDlgPlnrNavLoainiData(dom);
	};
};

function handleDpchEngDlgPlnrNavLoainiData(dom) {
// IP handleDpchEngDlgPlnrNavLoainiData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgPlnrNavLoainiData") {
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

			} else if (blk.nodeName == "DpchEngDlgPlnrNavLoainiData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};


