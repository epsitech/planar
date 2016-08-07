/**
  * \file PnlPlnrDgdHeadbar.js
  * web client functionality for panel PnlPlnrDgdHeadbar
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// --- view initialization
function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var width = 995;

	var appw = parseInt(retrieveSi(srcdoc, "StgInfPlnrDgdHeadbar", "MenAppCptwidth"));
	contdoc.getElementById("colMenApp").setAttribute("width", "" + appw);
	width -= appw+1;

	var crdw = parseInt(retrieveSi(srcdoc, "StgInfPlnrDgdHeadbar", "MenCrdCptwidth"));
	contdoc.getElementById("colMenCrd").setAttribute("width", "" + crdw);
	width -= crdw+1;

	contdoc.getElementById("colFill").setAttribute("width", "" + width);

	// captions
	setTextContent(contdoc, contdoc.getElementById("MenApp"), retrieveTi(srcdoc, "TagPlnrDgdHeadbar", "MenApp") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagPlnrDgdHeadbar", "MenCrd") + "\\u00a0");
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	var width;
	width = parseInt(retrieveSi(srcdoc, "StgInfPlnrDgdHeadbar", "MenAppWidth"));

	getCrdwnd().toggleMenu("App", 3, width, 42);
};

// IP handleMenCrdClick --- BEGIN
function handleMenCrdClick() {
	var appw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfPlnrDgdHeadbar", "MenAppCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfPlnrDgdHeadbar", "MenCrdWidth"));

	getCrdwnd().toggleMenu("Crd", 3+appw+1, width, 22);
};
// IP handleMenCrdClick --- END

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDgdHeadbarData", "StgInfPlnrDgdHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngPlnrDgdHeadbarData", "TagPlnrDgdHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrDgdHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};


