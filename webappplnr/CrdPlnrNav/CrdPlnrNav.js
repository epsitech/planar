/**
  * \file CrdPlnrNav.js
  * web client functionality for card CrdPlnrNav
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneHeadbar") == "true");
	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdonePre") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneAdmin") == "true");
	var initdoneGlobal = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneGlobal") == "true");
	var initdoneDesign = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneDesign") == "true");
	var initdoneCalc = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneCalc") == "true");
	var initdoneLayout = (retrieveSi(srcdoc, "StatAppPlnrNav", "initdoneLayout") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlPlnrNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdonePre) {
		doc.getElementById("Pre").src = "./PnlPlnrNavPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlPlnrNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneGlobal) {
		doc.getElementById("Global").src = "./PnlPlnrNavGlobal.html?scrJref=" + scrJrefGlobal;
	} else if (!initdoneDesign) {
		doc.getElementById("Design").src = "./PnlPlnrNavDesign.html?scrJref=" + scrJrefDesign;
	} else if (!initdoneCalc) {
		doc.getElementById("Calc").src = "./PnlPlnrNavCalc.html?scrJref=" + scrJrefCalc;
	} else if (!initdoneLayout) {
		doc.getElementById("Layout").src = "./PnlPlnrNavLayout.html?scrJref=" + scrJrefLayout;
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

	if (doc.getElementById("trPre").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdPre").getAttribute("height"));
	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trGlobal").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdGlobal").getAttribute("height")) + 8;
	if (doc.getElementById("trDesign").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdDesign").getAttribute("height")) + 8;
	if (doc.getElementById("trCalc").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdCalc").getAttribute("height")) + 8;
	if (doc.getElementById("trLayout").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdLayout").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppPlnrNav", "shortMenu");

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

	setSi(srcdoc, "StatAppPlnrNav", "shortMenu", short);
	setSi(srcdoc, "StatAppPlnrNav", "widthMenu", "" + (width-3));

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

	setSi(srcdoc, "StatAppPlnrNav", "shortMenu", "");

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

// IP initMenAppCrdnav --- BEGIN
function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	var MspApp2Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspApp2Avail") == "true");
	var MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppPlnrNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagPlnrNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagPlnrNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagPlnrNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};
// IP initMenAppCrdnav --- END

// IP initMenSes --- BEGIN
function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppPlnrNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfPlnrNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfPlnrNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfPlnrNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagPlnrNav", "MitSesTrm"));
};
// IP initMenSes --- END

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdPrsAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdFilAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspCrd2Avail") == "true");
	MitCrdDtpAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDtpAvail") == "true");
	MitCrdCtpAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdCtpAvail") == "true");
	MitCrdMatAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdMatAvail") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspCrd3Avail") == "true");
	MitCrdPrjAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdPrjAvail") == "true");
	MitCrdDsnAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDsnAvail") == "true");
	MitCrdDomAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDomAvail") == "true");
	MitCrdDomActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDomActive") == "true");
	MitCrdDgdAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDgdAvail") == "true");
	MitCrdDgdActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDgdActive") == "true");
	MitCrdDvcAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDvcAvail") == "true");
	MitCrdDvcActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdDvcActive") == "true");
	MitCrdSruAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdSruAvail") == "true");
	MitCrdSruActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdSruActive") == "true");
	MitCrdStkAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdStkAvail") == "true");
	MitCrdStkActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdStkActive") == "true");
	MitCrdLyrAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdLyrAvail") == "true");
	MitCrdLyrActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdLyrActive") == "true");
	MspCrd4Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspCrd4Avail") == "true");
	MitCrdClcAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdClcAvail") == "true");
	MitCrdClcActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdClcActive") == "true");
	MitCrdCliAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdCliAvail") == "true");
	MitCrdCliActive = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdCliActive") == "true");
	MspCrd5Avail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MspCrd5Avail") == "true");
	MitCrdTpoAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "MitCrdTpoAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppPlnrNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdFil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdDtp"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdDtp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdCtp"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdCtp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMat"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdMat"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrj"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdPrj"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdDsn"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdDsn"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdDom"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdDom"));
	setMitActive("MitCrdDom", MitCrdDomActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdDgd"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdDgd"));
	setMitActive("MitCrdDgd", MitCrdDgdActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdDvc"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdDvc"));
	setMitActive("MitCrdDvc", MitCrdDvcActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdSru"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdSru"));
	setMitActive("MitCrdSru", MitCrdSruActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdStk"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdStk"));
	setMitActive("MitCrdStk", MitCrdStkActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdLyr"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdLyr"));
	setMitActive("MitCrdLyr", MitCrdLyrActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdClc"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdClc"));
	setMitActive("MitCrdClc", MitCrdClcActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCli"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdCli"));
	setMitActive("MitCrdCli", MitCrdCliActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdTpo"), retrieveTi(srcdoc, "TagPlnrNav", "MitCrdTpo"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdDtp", MitCrdDtpAvail, 20);
	height -= setMitMspAvail("MitCrdCtp", MitCrdCtpAvail, 20);
	height -= setMitMspAvail("MitCrdMat", MitCrdMatAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdPrj", MitCrdPrjAvail, 20);
	height -= setMitMspAvail("MitCrdDsn", MitCrdDsnAvail, 20);
	height -= setMitMspAvail("MitCrdDom", MitCrdDomAvail, 20);
	height -= setMitMspAvail("MitCrdDgd", MitCrdDgdAvail, 20);
	height -= setMitMspAvail("MitCrdDvc", MitCrdDvcAvail, 20);
	height -= setMitMspAvail("MitCrdSru", MitCrdSruAvail, 20);
	height -= setMitMspAvail("MitCrdStk", MitCrdStkAvail, 20);
	height -= setMitMspAvail("MitCrdLyr", MitCrdLyrAvail, 20);
	height -= setMitMspAvail("MspCrd4", MspCrd4Avail, 1);
	height -= setMitMspAvail("MitCrdClc", MitCrdClcAvail, 20);
	height -= setMitMspAvail("MitCrdCli", MitCrdCliAvail, 20);
	height -= setMitMspAvail("MspCrd5", MspCrd5Avail, 1);
	height -= setMitMspAvail("MitCrdTpo", MitCrdTpoAvail, 20);

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
	if ((sref == "DlgPlnrNavLoaini")) myif.setAttribute("height", "585");
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

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Global") {
		doc.getElementById("tdGlobal").setAttribute("height", "" + height);
		doc.getElementById("Global").setAttribute("height", "" + height);
	} else if (pnlshort == "Design") {
		doc.getElementById("tdDesign").setAttribute("height", "" + height);
		doc.getElementById("Design").setAttribute("height", "" + height);
	} else if (pnlshort == "Calc") {
		doc.getElementById("tdCalc").setAttribute("height", "" + height);
		doc.getElementById("Calc").setAttribute("height", "" + height);
	} else if (pnlshort == "Layout") {
		doc.getElementById("tdLayout").setAttribute("height", "" + height);
		doc.getElementById("Layout").setAttribute("height", "" + height);
	};

	if (divShld) divShld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefDlgloaini");
	var pnlpreAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnlpreAvail") == "true");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnladminAvail") == "true");
	var pnlglobalAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnlglobalAvail") == "true");
	var pnldesignAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnldesignAvail") == "true");
	var pnlcalcAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnlcalcAvail") == "true");
	var pnllayoutAvail = (retrieveSi(srcdoc, "StatShrPlnrNav", "pnllayoutAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgPlnrNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Pre", pnlpreAvail);
	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Global", pnlglobalAvail);
	setPnlAvail("Design", pnldesignAvail);
	setPnlAvail("Calc", pnlcalcAvail);
	setPnlAvail("Layout", pnllayoutAvail);
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavDo", scrJref, "close");
	sendReq(str, doc);
};

function handleMitClick(menshort, ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, ctlsref) {
	window.open(retrieveCi(srcdoc, "ContInfPlnrNav", ctlsref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavData", "ContInfPlnrNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngPlnrNavData", "StatAppPlnrNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrNavData", "StatShrPlnrNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavData", "TagPlnrNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefHeadbar");
				scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefPre");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefAdmin");
				scrJrefGlobal = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefGlobal");
				scrJrefDesign = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefDesign");
				scrJrefCalc = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefCalc");
				scrJrefLayout = retrieveSi(srcdoc, "StatShrPlnrNav", "scrJrefLayout");

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

			} else if (blk.nodeName == "DpchEngPlnrNavData") {
				mergeDpchEngData(dom);
				refresh();
			};

			restartNotify();
		};
	};
};

// IP handleDpchAppDoCrdopenReply --- BEGIN
function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				accepted = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:accepted");
				_scrJref = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:scrJref");
				sref = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngPlnrAlert") {
				showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};
// IP handleDpchAppDoCrdopenReply --- END

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

// IP terminateCrdnav --- BEGIN
	window.open("../CrdPlnrStart/CrdPlnrStart.html?do=Logout", "_self");
// IP terminateCrdnav --- END
};

function restartNotify() {
	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrNav", "srefIxPlnrVReqitmode");

	if (srefIxPlnrVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxPlnrVReqitmode = "notify";
		setSi(srcdoc, "StatAppPlnrNav", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrNav", "srefIxPlnrVReqitmode");

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

	var srefIxPlnrVReqitmode = retrieveSi(srcdoc, "StatAppPlnrNav", "srefIxPlnrVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppPlnrNav", "latency"));

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
					setSi(srcdoc, "StatAppPlnrNav", "srefIxPlnrVReqitmode", srefIxPlnrVReqitmode);

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

							} else if (blk.nodeName == "DpchEngPlnrNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else if (_scrJref == scrJrefDlg) {
							doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else if (_scrJref == scrJrefPre) {
							doc.getElementById("Pre").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefAdmin) {
							doc.getElementById("Admin").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefGlobal) {
							doc.getElementById("Global").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefDesign) {
							doc.getElementById("Design").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefCalc) {
							doc.getElementById("Calc").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefLayout) {
							doc.getElementById("Layout").contentWindow.handleDpchEng(dom, blk.nodeName);

// IP iterateReqit.invalid --- BEGIN
						} else {
							// alert("got a '" + blk.nodeName + "' from job with scrJref " + _scrJref);
// IP iterateReqit.invalid --- END
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


