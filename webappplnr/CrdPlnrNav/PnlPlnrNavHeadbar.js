/**
  * \file PnlPlnrNavHeadbar.js
  * web client functionality for panel PnlPlnrNavHeadbar
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// --- view initialization
function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var width = 995;

	var appw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenAppCptwidth"));
	contdoc.getElementById("colMenApp").setAttribute("width", "" + appw);
	width -= appw+1;

// IP init.sesw --- BEGIN
	var sesw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenSesCptwidth"));
	contdoc.getElementById("colMenSes").setAttribute("width", "" + sesw);
	width -= sesw+1;
// IP init.sesw --- END

	var crdw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenCrdCptwidth"));
	contdoc.getElementById("colMenCrd").setAttribute("width", "" + crdw);
	width -= crdw+1;

	contdoc.getElementById("colFill").setAttribute("width", "" + width);

// IP init.MenCrdAvail --- BEGIN
	var MenCrdAvail = (retrieveSi(srcdoc, "StatShrPlnrNavHeadbar", "MenCrdAvail") == "true");
	if (!MenCrdAvail) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");
// IP init.MenCrdAvail --- END

	// captions
	setTextContent(contdoc, contdoc.getElementById("MenApp"), retrieveTi(srcdoc, "TagPlnrNavHeadbar", "MenApp") + "\\u00a0");
// IP init.MenSes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagPlnrNavHeadbar", "MenSes") + "\\u00a0");
// IP init.MenSes --- END
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagPlnrNavHeadbar", "MenCrd") + "\\u00a0");
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
	width = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenAppWidth"));

	getCrdwnd().toggleMenu("App", 3, width, 63);
};

// IP handleMenSesClick --- BEGIN
function handleMenSesClick() {
	var appw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenAppCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenSesWidth"));

	getCrdwnd().toggleMenu("Ses", 3+appw+1, width, 83);
};
// IP handleMenSesClick --- END

// IP handleMenCrdClickCrdnav --- BEGIN
function handleMenCrdClick() {
	var appw, sesw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenAppCptwidth"));
	sesw = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenSesCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfPlnrNavHeadbar", "MenCrdWidth"));

	getCrdwnd().toggleMenu("Crd", 3+appw+1+sesw+1, width, 366);
};
// IP handleMenCrdClickCrdnav --- END

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavHeadbarData", "StatShrPlnrNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavHeadbarData", "StgInfPlnrNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngPlnrNavHeadbarData", "TagPlnrNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};


