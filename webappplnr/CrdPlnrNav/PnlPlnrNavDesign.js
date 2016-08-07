/**
  * \file PnlPlnrNavDesign.js
  * web client functionality for panel PnlPlnrNavDesign
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "mind") {
		setSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate", "mind");

		// change container heights
		getCrdwnd().changeHeight("Design", 30);
		doc.getElementById("tdSide").setAttribute("height", "30");
		doc.getElementById("Design_side").setAttribute("height", "30");
		doc.getElementById("Design_cont").setAttribute("height", "30");

		// change content
		doc.getElementById("Design_side").src = "./PnlPlnrNavDesign_aside.html";
		doc.getElementById("Design_cont").src = "./PnlPlnrNavDesign_a.html";
	};
};

function regularize() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate != "regd") {
		setSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate", "regd");

		// change content (container heights in refreshB)
		doc.getElementById("Design_side").src = "./PnlPlnrNavDesign_bside.html";
		doc.getElementById("Design_cont").src = "./PnlPlnrNavDesign_b.html";
	};
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Design_side").contentDocument;
	contdoc = doc.getElementById("Design_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavDesign", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Design_side").contentDocument;
	contdoc = doc.getElementById("Design_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Design_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Design_cont").contentDocument;

// IP initB --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagPlnrNavDesign", "Cpt"));
// IP initB --- END

	refreshB();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		initA();
	} else if (srefIxPlnrVExpstate == "regd") {
		initB();
	};
};

function refreshA() {
};

function refreshB() {
	var height = 778; // full cont height

// IP refreshB.vars --- BEGIN
	var LstPrjAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstPrjAlt") == "true");
	var LstPrjAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstPrjAvail") == "true");
	var ButPrjViewAvail = !LstPrjAlt;
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButPrjViewActive") == "true");

	var LstDsnAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDsnAlt") == "true");
	var LstDsnAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstDsnAvail") == "true");
	var ButDsnViewAvail = !LstDsnAlt;
	var ButDsnViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDsnViewActive") == "true");

	var LstDomAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDomAlt") == "true");
	var LstDomAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstDomAvail") == "true");
	var ButDomViewAvail = !LstDomAlt;
	var ButDomViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDomViewActive") == "true");
	var ButDomNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDomNewcrdActive") == "true");

	var LstDgdAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDgdAlt") == "true");
	var LstDgdAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstDgdAvail") == "true");
	var ButDgdViewAvail = !LstDgdAlt;
	var ButDgdViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDgdViewActive") == "true");
	var ButDgdNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDgdNewcrdActive") == "true");

	var LstDvcAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDvcAlt") == "true");
	var LstDvcAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstDvcAvail") == "true");
	var ButDvcViewAvail = !LstDvcAlt;
	var ButDvcViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDvcViewActive") == "true");
	var ButDvcNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButDvcNewcrdActive") == "true");

	var LstSruAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstSruAlt") == "true");
	var LstSruAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstSruAvail") == "true");
	var ButSruViewAvail = !LstSruAlt;
	var ButSruViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButSruViewActive") == "true");
	var ButSruNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButSruNewcrdActive") == "true");

	var LstStkAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstStkAlt") == "true");
	var LstStkAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstStkAvail") == "true");
	var ButStkViewAvail = !LstStkAlt;
	var ButStkViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButStkViewActive") == "true");
	var ButStkNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButStkNewcrdActive") == "true");

	var LstLyrAlt = (retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstLyrAlt") == "true");
	var LstLyrAvail = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "LstLyrAvail") == "true");
	var ButLyrViewAvail = !LstLyrAlt;
	var ButLyrViewActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButLyrViewActive") == "true");
	var ButLyrNewcrdActive = (retrieveSi(srcdoc, "StatShrPlnrNavDesign", "ButLyrNewcrdActive") == "true");

	var mytd, first;
// IP refreshB.vars --- END

// IP refreshB --- BEGIN
	height -= setCtlAvail(contcontdoc, "Prj", LstPrjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prj2", LstPrjAvail && !LstPrjAlt, 71);
	if (LstPrjAvail) {
		if ( (LstPrjAlt == !contcontdoc.getElementById("ButPrjExpand")) || (!LstPrjAlt == !contcontdoc.getElementById("ButPrjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptPrj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrjCollapse", "icon/collapse"));
		};

		if (!LstPrjAlt == !contcontdoc.getElementById("LstPrj")) {
			mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrj");
			clearElem(mytd);

			if (LstPrjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrj", true));
			};

		} else {
			if (!LstPrjAlt) refreshLst(contcontdoc.getElementById("LstPrj").contentWindow.document, srcdoc, false, "FeedFLstPrj",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstPrjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstPrj"))]);
		};

		if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView")) || !contcontdoc.getElementById("ButPrjNewcrd")) {
			if (LstPrjAlt) mytd = contcontdoc.getElementById("dynPrj");
			else mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);

			first = true;

			if (ButPrjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjNewcrd", "icon/newcrd"));
		};

		if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	} else setCtlAvail(contcontdoc, "Prj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dsn", LstDsnAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dsn2", LstDsnAvail && !LstDsnAlt, 71);
	if (LstDsnAvail) {
		if ( (LstDsnAlt == !contcontdoc.getElementById("ButDsnExpand")) || (!LstDsnAlt == !contcontdoc.getElementById("ButDsnCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDsn");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDsn", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptDsn")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDsnAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDsnExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDsnCollapse", "icon/collapse"));
		};

		if (!LstDsnAlt == !contcontdoc.getElementById("LstDsn")) {
			mytd = contcontdoc.getElementById("rdynDsn");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDsn");
			clearElem(mytd);

			if (LstDsnAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDsn", true));
			};

		} else {
			if (!LstDsnAlt) refreshLst(contcontdoc.getElementById("LstDsn").contentWindow.document, srcdoc, false, "FeedFLstDsn",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDsnNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstDsn"))]);
		};

		if ((ButDsnViewAvail == !contcontdoc.getElementById("ButDsnView")) || !contcontdoc.getElementById("ButDsnNewcrd")) {
			if (LstDsnAlt) mytd = contcontdoc.getElementById("dynDsn");
			else mytd = contcontdoc.getElementById("rdynDsn");
			clearElem(mytd);

			first = true;

			if (ButDsnViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDsnView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDsnNewcrd", "icon/newcrd"));
		};

		if (ButDsnViewAvail) refreshButicon(contcontdoc, "ButDsnView", "icon/view", ButDsnViewActive, false);

	} else setCtlAvail(contcontdoc, "Dsn2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dom", LstDomAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dom2", LstDomAvail && !LstDomAlt, 71);
	if (LstDomAvail) {
		if ( (LstDomAlt == !contcontdoc.getElementById("ButDomExpand")) || (!LstDomAlt == !contcontdoc.getElementById("ButDomCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDom");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDom", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptDom")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDomAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDomExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDomCollapse", "icon/collapse"));
		};

		if (!LstDomAlt == !contcontdoc.getElementById("LstDom")) {
			mytd = contcontdoc.getElementById("rdynDom");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDom");
			clearElem(mytd);

			if (LstDomAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDom", true));
			};

		} else {
			if (!LstDomAlt) refreshLst(contcontdoc.getElementById("LstDom").contentWindow.document, srcdoc, false, "FeedFLstDom",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDomNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstDom"))]);
		};

		if ((ButDomViewAvail == !contcontdoc.getElementById("ButDomView")) || !contcontdoc.getElementById("ButDomNewcrd")) {
			if (LstDomAlt) mytd = contcontdoc.getElementById("dynDom");
			else mytd = contcontdoc.getElementById("rdynDom");
			clearElem(mytd);

			first = true;

			if (ButDomViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDomView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDomNewcrd", "icon/newcrd"));
		};

		if (ButDomViewAvail) refreshButicon(contcontdoc, "ButDomView", "icon/view", ButDomViewActive, false);
		refreshButicon(contcontdoc, "ButDomNewcrd", "icon/newcrd", ButDomNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Dom2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dgd", LstDgdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dgd2", LstDgdAvail && !LstDgdAlt, 71);
	if (LstDgdAvail) {
		if ( (LstDgdAlt == !contcontdoc.getElementById("ButDgdExpand")) || (!LstDgdAlt == !contcontdoc.getElementById("ButDgdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDgd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDgd", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptDgd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDgdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDgdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDgdCollapse", "icon/collapse"));
		};

		if (!LstDgdAlt == !contcontdoc.getElementById("LstDgd")) {
			mytd = contcontdoc.getElementById("rdynDgd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDgd");
			clearElem(mytd);

			if (LstDgdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDgd", true));
			};

		} else {
			if (!LstDgdAlt) refreshLst(contcontdoc.getElementById("LstDgd").contentWindow.document, srcdoc, false, "FeedFLstDgd",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDgdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstDgd"))]);
		};

		if ((ButDgdViewAvail == !contcontdoc.getElementById("ButDgdView")) || !contcontdoc.getElementById("ButDgdNewcrd")) {
			if (LstDgdAlt) mytd = contcontdoc.getElementById("dynDgd");
			else mytd = contcontdoc.getElementById("rdynDgd");
			clearElem(mytd);

			first = true;

			if (ButDgdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDgdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDgdNewcrd", "icon/newcrd"));
		};

		if (ButDgdViewAvail) refreshButicon(contcontdoc, "ButDgdView", "icon/view", ButDgdViewActive, false);
		refreshButicon(contcontdoc, "ButDgdNewcrd", "icon/newcrd", ButDgdNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Dgd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Dvc", LstDvcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Dvc2", LstDvcAvail && !LstDvcAlt, 71);
	if (LstDvcAvail) {
		if ( (LstDvcAlt == !contcontdoc.getElementById("ButDvcExpand")) || (!LstDvcAlt == !contcontdoc.getElementById("ButDvcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynDvc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptDvc", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptDvc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstDvcAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDvcExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButDvcCollapse", "icon/collapse"));
		};

		if (!LstDvcAlt == !contcontdoc.getElementById("LstDvc")) {
			mytd = contcontdoc.getElementById("rdynDvc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynDvc");
			clearElem(mytd);

			if (LstDvcAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstDvc", true));
			};

		} else {
			if (!LstDvcAlt) refreshLst(contcontdoc.getElementById("LstDvc").contentWindow.document, srcdoc, false, "FeedFLstDvc",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstDvcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstDvc"))]);
		};

		if ((ButDvcViewAvail == !contcontdoc.getElementById("ButDvcView")) || !contcontdoc.getElementById("ButDvcNewcrd")) {
			if (LstDvcAlt) mytd = contcontdoc.getElementById("dynDvc");
			else mytd = contcontdoc.getElementById("rdynDvc");
			clearElem(mytd);

			first = true;

			if (ButDvcViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButDvcView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDvcNewcrd", "icon/newcrd"));
		};

		if (ButDvcViewAvail) refreshButicon(contcontdoc, "ButDvcView", "icon/view", ButDvcViewActive, false);
		refreshButicon(contcontdoc, "ButDvcNewcrd", "icon/newcrd", ButDvcNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Dvc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sru", LstSruAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sru2", LstSruAvail && !LstSruAlt, 71);
	if (LstSruAvail) {
		if ( (LstSruAlt == !contcontdoc.getElementById("ButSruExpand")) || (!LstSruAlt == !contcontdoc.getElementById("ButSruCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSru");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSru", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptSru")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSruAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSruExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSruCollapse", "icon/collapse"));
		};

		if (!LstSruAlt == !contcontdoc.getElementById("LstSru")) {
			mytd = contcontdoc.getElementById("rdynSru");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSru");
			clearElem(mytd);

			if (LstSruAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSru", true));
			};

		} else {
			if (!LstSruAlt) refreshLst(contcontdoc.getElementById("LstSru").contentWindow.document, srcdoc, false, "FeedFLstSru",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstSruNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstSru"))]);
		};

		if ((ButSruViewAvail == !contcontdoc.getElementById("ButSruView")) || !contcontdoc.getElementById("ButSruNewcrd")) {
			if (LstSruAlt) mytd = contcontdoc.getElementById("dynSru");
			else mytd = contcontdoc.getElementById("rdynSru");
			clearElem(mytd);

			first = true;

			if (ButSruViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSruView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSruNewcrd", "icon/newcrd"));
		};

		if (ButSruViewAvail) refreshButicon(contcontdoc, "ButSruView", "icon/view", ButSruViewActive, false);
		refreshButicon(contcontdoc, "ButSruNewcrd", "icon/newcrd", ButSruNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sru2", false, 0);

	height -= setCtlAvail(contcontdoc, "Stk", LstStkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Stk2", LstStkAvail && !LstStkAlt, 71);
	if (LstStkAvail) {
		if ( (LstStkAlt == !contcontdoc.getElementById("ButStkExpand")) || (!LstStkAlt == !contcontdoc.getElementById("ButStkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynStk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptStk", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptStk")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstStkAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButStkExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButStkCollapse", "icon/collapse"));
		};

		if (!LstStkAlt == !contcontdoc.getElementById("LstStk")) {
			mytd = contcontdoc.getElementById("rdynStk");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynStk");
			clearElem(mytd);

			if (LstStkAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstStk", true));
			};

		} else {
			if (!LstStkAlt) refreshLst(contcontdoc.getElementById("LstStk").contentWindow.document, srcdoc, false, "FeedFLstStk",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstStkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstStk"))]);
		};

		if ((ButStkViewAvail == !contcontdoc.getElementById("ButStkView")) || !contcontdoc.getElementById("ButStkNewcrd")) {
			if (LstStkAlt) mytd = contcontdoc.getElementById("dynStk");
			else mytd = contcontdoc.getElementById("rdynStk");
			clearElem(mytd);

			first = true;

			if (ButStkViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButStkView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButStkNewcrd", "icon/newcrd"));
		};

		if (ButStkViewAvail) refreshButicon(contcontdoc, "ButStkView", "icon/view", ButStkViewActive, false);
		refreshButicon(contcontdoc, "ButStkNewcrd", "icon/newcrd", ButStkNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Stk2", false, 0);

	height -= setCtlAvail(contcontdoc, "Lyr", LstLyrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Lyr2", LstLyrAvail && !LstLyrAlt, 71);
	if (LstLyrAvail) {
		if ( (LstLyrAlt == !contcontdoc.getElementById("ButLyrExpand")) || (!LstLyrAlt == !contcontdoc.getElementById("ButLyrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLyr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLyr", retrieveTi(srcdoc, "TagPlnrNavDesign", "CptLyr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLyrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLyrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLyrCollapse", "icon/collapse"));
		};

		if (!LstLyrAlt == !contcontdoc.getElementById("LstLyr")) {
			mytd = contcontdoc.getElementById("rdynLyr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLyr");
			clearElem(mytd);

			if (LstLyrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLyr", true));
			};

		} else {
			if (!LstLyrAlt) refreshLst(contcontdoc.getElementById("LstLyr").contentWindow.document, srcdoc, false, "FeedFLstLyr",
						parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", "LstLyrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numFLstLyr"))]);
		};

		if ((ButLyrViewAvail == !contcontdoc.getElementById("ButLyrView")) || !contcontdoc.getElementById("ButLyrNewcrd")) {
			if (LstLyrAlt) mytd = contcontdoc.getElementById("dynLyr");
			else mytd = contcontdoc.getElementById("rdynLyr");
			clearElem(mytd);

			first = true;

			if (ButLyrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLyrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLyrNewcrd", "icon/newcrd"));
		};

		if (ButLyrViewAvail) refreshButicon(contcontdoc, "ButLyrView", "icon/view", ButLyrViewActive, false);
		refreshButicon(contcontdoc, "ButLyrNewcrd", "icon/newcrd", ButLyrNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Lyr2", false, 0);

// IP refreshB --- END

	getCrdwnd().changeHeight("Design", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Design_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Design_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Design_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatAppPlnrNavDesign", "srefIxPlnrVExpstate");

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
	srcdoc = doc.getElementById("Design_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavDesign", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppPlnrNavDesign", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavDesignDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrNavDesignDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numsF" + ctlsref));

		found = false;

		for (var i=0;i<oldNumsFLst.length;i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j=0;j<oldNumsFLst.length;j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i=0;i<oldNumsFLst.length;i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacPlnrNavDesign", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacPlnrNavDesign", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppPlnrNavDesignData", scrJref, "ContIacPlnrNavDesign");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppPlnrNavDesign", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppPlnrNavDesign", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacPlnrNavDesign", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "ContIacPlnrNavDesign", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstDgd", srcdoc)) mask.push("feedFLstDgd");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstDom", srcdoc)) mask.push("feedFLstDom");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstDsn", srcdoc)) mask.push("feedFLstDsn");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstDvc", srcdoc)) mask.push("feedFLstDvc");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstLyr", srcdoc)) mask.push("feedFLstLyr");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstPrj", srcdoc)) mask.push("feedFLstPrj");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstSru", srcdoc)) mask.push("feedFLstSru");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "FeedFLstStk", srcdoc)) mask.push("feedFLstStk");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "StatAppPlnrNavDesign", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "StatShrPlnrNavDesign", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrNavDesignData", "TagPlnrNavDesign", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngPlnrNavDesignData") {
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
			if (blk.nodeName == "DpchEngPlnrNavDesignData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Design");
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

			} else if (blk.nodeName == "DpchEngPlnrNavDesignData") {
				mergeDpchEngData(dom);
				refresh();
			};
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
				getCrdwnd().showAlr(retrieveValue(dom, "//plnr:DpchEngPlnrAlert/plnr:scrJref"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:ContInfPlnrAlert"),
						retrieveBlock(dom, "//plnr:DpchEngPlnrAlert/plnr:FeedFMcbAlert"));
			};
		};
	};
};
// IP handleDpchAppDoCrdopenReply --- END


