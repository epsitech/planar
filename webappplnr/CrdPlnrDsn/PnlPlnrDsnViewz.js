/**
  * \file PnlPlnrDsnViewz.js
  * web client functionality for panel PnlPlnrDsnViewz
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Viewz", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Viewz_side").setAttribute("height", "30");
		doc.getElementById("Viewz_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Viewz_side").src = "./PnlPlnrDsnViewz_aside.html";
		doc.getElementById("Viewz_cont").src = "./PnlPlnrDsnViewz_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Viewz_side").src = "./PnlPlnrDsnViewz_bside.html";
		doc.getElementById("Viewz_cont").src = "./PnlPlnrDsnViewz_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Viewz_side").contentDocument;
	contdoc = doc.getElementById("Viewz_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDsnViewz", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Viewz_side").contentDocument;
	contdoc = doc.getElementById("Viewz_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Viewz_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Viewz_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDsnViewz", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 10; // full cont height

// IP refreshB.vars --- BEGIN
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
// IP refreshB --- END

	getRecwnd().changeHeight("Viewz", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Viewz_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Viewz_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Viewz_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewz", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Viewz_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDsnViewzData", "TagPlnrDsnViewz", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDsnViewzData") {
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
			if (blk.nodeName == "DpchEngPlnrDsnViewzData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Viewz");
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

			} else if (blk.nodeName == "DpchEngPlnrDsnViewzData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


