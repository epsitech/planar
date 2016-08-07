/**
  * \file DlgPlnrDsnGenplt.js
  * web client functionality for dialog DlgPlnrDsnGenplt
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgPlnrDsnGenplt", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgPlnrDsnGenplt", "ButDne"));

	refresh();
};

function refresh() {
// IP refresh.vars --- BEGIN

// IP refresh.vars --- END

// IP refresh --- BEGIN

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

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgPlnrDsnGenpltDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgPlnrDsnGenpltData", "StatAppDlgPlnrDsnGenplt", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgPlnrDsnGenpltData", "TagDlgPlnrDsnGenplt", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgPlnrDsnGenpltData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgPlnrDsnGenpltData") {
		handleDpchEngDlgPlnrDsnGenpltData(dom);
	};
};

function handleDpchEngDlgPlnrDsnGenpltData(dom) {
// IP handleDpchEngDlgPlnrDsnGenpltData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgPlnrDsnGenpltData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngPlnrAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
							retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
							retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgPlnrDsnGenpltData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


