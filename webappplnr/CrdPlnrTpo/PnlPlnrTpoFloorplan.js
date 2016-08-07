/**
  * \file PnlPlnrTpoFloorplan.js
  * web client functionality for panel PnlPlnrTpoFloorplan
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getRecwnd().changeHeight("Floorplan", 30, updh);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Floorplan_side").setAttribute("height", "30");
		doc.getElementById("Floorplan_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Floorplan_side").src = "./PnlPlnrTpoFloorplan_aside.html";
		doc.getElementById("Floorplan_cont").src = "./PnlPlnrTpoFloorplan_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Floorplan_side").src = "./PnlPlnrTpoFloorplan_bside.html";
		doc.getElementById("Floorplan_cont").src = "./PnlPlnrTpoFloorplan_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Floorplan_side").contentDocument;
	contdoc = doc.getElementById("Floorplan_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrTpoFloorplan", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Floorplan_side").contentDocument;
	contdoc = doc.getElementById("Floorplan_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Floorplan_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Floorplan_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrTpoFloorplan", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate");

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

	getRecwnd().changeHeight("Floorplan", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Floorplan_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Floorplan_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Floorplan_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrTpoFloorplan", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Floorplan_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrTpoFloorplanData", "TagPlnrTpoFloorplan", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrTpoFloorplanData") {
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
			if (blk.nodeName == "DpchEngPlnrTpoFloorplanData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Floorplan");
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

			} else if (blk.nodeName == "DpchEngPlnrTpoFloorplanData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};


