/**
  * \file PnlPlnrNavPre.js
  * web client functionality for panel PnlPlnrNavPre
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtDsnAvail = (retrieveSi(srcdoc, "StatShrPlnrNavPre", "TxtDsnAvail") == "true"); if (TxtDsnAvail) n++;
	var TxtPrjAvail = (retrieveSi(srcdoc, "StatShrPlnrNavPre", "TxtPrjAvail") == "true"); if (TxtPrjAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtDsnAvail) {
		i++;

		line.appendChild(makeImgBut("ButDsnRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagPlnrNavPre", "CptDsn") + ": " + retrieveCi(srcdoc, "ContInfPlnrNavPre", "TxtDsn")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagPlnrNavPre", "CptDsn") + ": " + retrieveCi(srcdoc, "ContInfPlnrNavPre", "TxtDsn") + ",\u00a0\u00a0"));
	};

	if (TxtPrjAvail) {
		i++;

		line.appendChild(makeImgBut("ButPrjRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagPlnrNavPre", "CptPrj") + ": " + retrieveCi(srcdoc, "ContInfPlnrNavPre", "TxtPrj")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagPlnrNavPre", "CptPrj") + ": " + retrieveCi(srcdoc, "ContInfPlnrNavPre", "TxtPrj") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavPreData", "ContInfPlnrNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrNavPreData", "StatShrPlnrNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavPreData", "TagPlnrNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrNavPreData") {
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
			if (blk.nodeName == "DpchEngPlnrNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngPlnrNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


