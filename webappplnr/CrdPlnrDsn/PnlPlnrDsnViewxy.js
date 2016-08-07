/**
  * \file PnlPlnrDsnViewxy.js
  * web client functionality for panel PnlPlnrDsnViewxy
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Viewxy", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Viewxy_side").setAttribute("height", "30");
		doc.getElementById("Viewxy_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Viewxy_side").src = "./PnlPlnrDsnViewxy_aside.html";
		doc.getElementById("Viewxy_cont").src = "./PnlPlnrDsnViewxy_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Viewxy_side").src = "./PnlPlnrDsnViewxy_bside.html";
		doc.getElementById("Viewxy_cont").src = "./PnlPlnrDsnViewxy_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Viewxy_side").contentDocument;
	contdoc = doc.getElementById("Viewxy_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDsnViewxy", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Viewxy_side").contentDocument;
	contdoc = doc.getElementById("Viewxy_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Viewxy_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Viewxy_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrDsnViewxy", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate");

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

	getRecwnd().changeHeight("Viewxy", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Viewxy_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Viewxy_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Viewxy_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrDsnViewxy", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Viewxy_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDsnViewxyData", "TagPlnrDsnViewxy", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrDsnViewxyData") {
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
			if (blk.nodeName == "DpchEngPlnrDsnViewxyData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Viewxy");
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

			} else if (blk.nodeName == "DpchEngPlnrDsnViewxyData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


