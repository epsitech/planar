/**
  * \file CrdPlnrDsn.js
  * web client functionality for card CrdPlnrDsn
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrDsn", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrDsn", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppPlnrDsn", "initdoneHeadbar") == "true");
	var initdoneList = (retrieveSi(srcdoc, "StatAppPlnrDsn", "initdoneList") == "true");
	var initdoneRec = (retrieveSi(srcdoc, "StatAppPlnrDsn", "initdoneRec") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlPlnrDsnHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdoneList) {
		doc.getElementById("List").src = "./PnlPlnrDsnList.html?scrJref=" + scrJrefList;
	} else if (!initdoneRec) {
		doc.getElementById("Rec").src = "./PnlPlnrDsnRec.html?scrJref=" + scrJrefRec;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	height += 10 + parseInt(doc.getElementById("tdList").getAttribute("height")) + 8;
	height += 10 + parseInt(doc.getElementById("tdRec").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppPlnrDsn", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppPlnrDsn", "shortMenu", short);
	setSi(srcdoc, "StatAppPlnrDsn", "widthMenu", "" + (width-3));

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppPlnrDsn", "shortMenu", "");

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

// IP initMenApp --- BEGIN
function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppPlnrDsn", "widthMenu"));
	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagPlnrDsn", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagPlnrDsn", "MrlAppHlp"));
};
// IP initMenApp --- END

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MitCrdGplAvail = (retrieveSi(srcdoc, "StatShrPlnrDsn", "MitCrdGplAvail") == "true");
	MitCrdGplActive = (retrieveSi(srcdoc, "StatShrPlnrDsn", "MitCrdGplActive") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppPlnrDsn", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxCrdDsn"), retrieveCi(srcdoc, "ContInfPlnrDsn", "MtxCrdDsn"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdGpl"), retrieveTi(srcdoc, "TagPlnrDsn", "MitCrdGpl"));
	setMitActive("MitCrdGpl", MitCrdGplActive);

	height -= setMitMspAvail("MitCrdGpl", MitCrdGplAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	srefDlg = sref;
	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divShld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if (false) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	srefDlg = "";
	scrJrefDlg = "";

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divShld"));
	body.removeChild(doc.getElementById("divDlg"));
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfPlnrAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divShld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	scrJrefAlr = "";

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divShld"));
	body.removeChild(doc.getElementById("divAlr"));
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfPlnrAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfPlnrAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divShld = doc.getElementById("divShld");

	if (pnlshort == "List") {
		doc.getElementById("tdList").setAttribute("height", "" + height);
		doc.getElementById("List").setAttribute("height", "" + height);
	} else if (pnlshort == "Rec") {
		doc.getElementById("tdRec").setAttribute("height", "" + height);
		doc.getElementById("Rec").setAttribute("height", "" + height);
	};

	if (divShld) divShld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlggenplt = retrieveSi(srcdoc, "StatShrPlnrDsn", "scrJrefDlggenplt");

	if (scrJrefDlggenplt != "") {
		if (scrJrefDlg != scrJrefDlggenplt) showDlg("DlgPlnrDsnGenplt", scrJrefDlggenplt);
	} else if (scrJrefDlg != "") hideDlg();

	doc.title = retrieveCi(srcdoc, "ContInfPlnrDsn", "MtxCrdDsn") + " - Planar 0.1.22";
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDsnDo", scrJref, "close");
	sendReq(str, doc);
};

function handleMitClick(menshort, ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDsnDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, ctlsref) {
	window.open(retrieveCi(srcdoc, "ContInfPlnrDsn", ctlsref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDsnData", "ContInfPlnrDsn", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDsnData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngPlnrDsnData", "StatAppPlnrDsn", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDsnData", "StatShrPlnrDsn", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDsnData", "TagPlnrDsn", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrDsnData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrPlnrDsn", "scrJrefHeadbar");
				scrJrefList = retrieveSi(srcdoc, "StatShrPlnrDsn", "scrJrefList");
				scrJrefRec = retrieveSi(srcdoc, "StatShrPlnrDsn", "scrJrefRec");

				srefDlg = "";
				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
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

			} else if (blk.nodeName == "DpchEngPlnrAlert") {
				// show alert with new content
				showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));

			} else if (blk.nodeName == "DpchEngPlnrDsnData") {
				mergeDpchEngData(dom);
				refresh();
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

// IP terminate --- BEGIN
	window.open("about:blank", "_self");
// IP terminate --- END
};

function restartNotify() {
	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrDsn", "srefIxPlnrVReqitmode");

	if (srefIxPlnrVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxPlnrVReqitmode = "notify";
		setSi(srcdoc, "StatAppPlnrDsn", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrDsn", "srefIxPlnrVReqitmode");

	if (srefIxPlnrVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppPlnrResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) if (blk.nodeName == "DpchEngPlnrAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrDsn", "srefIxPlnrVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppPlnrDsn", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//plnr:*");

			if (blk) {
				if (blk.nodeName == "DpchEngPlnrAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngPlnrSuspend") {
					// change to "poll" mode
					news = true;

					srefIxPlnrVReqitmode = "poll";
					setSi(srcdoc, "StatAppPlnrDsn", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");

					if (blk.nodeName == "DpchEngPlnrAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
								retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
								retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));

					} else {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngPlnrConfirm") {
								accepted = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngPlnrDsnData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else if (_scrJref == scrJrefDlg) {
							doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, blk.nodeName);

// IP iterateReqit.listrec --- BEGIN
						} else if (_scrJref == scrJrefList) {
							doc.getElementById("List").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else {
							// scrJrefRec or scrJref of one of its sub-panels
							doc.getElementById("Rec").contentWindow.handleDpchEng(dom, blk.nodeName);
// IP iterateReqit.listrec --- END
						};
					};
				};
			};
		};
	};

	if ((srefIxPlnrVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxPlnrVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};


