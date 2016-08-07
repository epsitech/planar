/**
  * \file PnlPlnrDsnRec.js
  * web client functionality for panel PnlPlnrDsnRec
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDetail");
	scrJrefViewxy = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefViewxy");
	scrJrefViewz = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefViewz");
	scrJrefMod1NDesign = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefMod1NDesign");
	scrJrefDrv1NDesign = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDrv1NDesign");
	scrJrefDsn1NDevice = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDsn1NDevice");
	scrJrefDsn1NStack = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDsn1NStack");
	scrJrefDsn1NDomaingd = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDsn1NDomaingd");
	scrJrefDsn1NDomain = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefDsn1NDomain");
	scrJref1NBlock = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJref1NBlock");
	scrJref1NReticle = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJref1NReticle");
	scrJrefHk1NLevel = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NLevel");
	scrJrefHk1NVertex = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NVertex");
	scrJrefHk1NLineguide = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NLineguide");
	scrJrefHk1NArcguide = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NArcguide");
	scrJrefHk1NLayer = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NLayer");
	scrJrefHk1NStructure = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "scrJrefHk1NStructure");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneViewxy", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneViewz", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneMod1NDesign", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDrv1NDesign", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDevice", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NStack", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDomaingd", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDomain", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdone1NBlock", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdone1NReticle", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLevel", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NVertex", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLineguide", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NArcguide", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLayer", "false");
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NStructure", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightViewxy = 30;
	heightViewz = 30;
	heightMod1NDesign = 30;
	heightDrv1NDesign = 30;
	heightDsn1NDevice = 30;
	heightDsn1NStack = 30;
	heightDsn1NDomaingd = 30;
	heightDsn1NDomain = 30;
	height1NBlock = 30;
	height1NReticle = 30;
	heightHk1NLevel = 30;
	heightHk1NVertex = 30;
	heightHk1NLineguide = 30;
	heightHk1NArcguide = 30;
	heightHk1NLayer = 30;
	heightHk1NStructure = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppPlnrDsnRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDetail") == "true");
	var initdoneViewxy = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneViewxy") == "true");
	var initdoneViewz = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneViewz") == "true");
	var initdoneMod1NDesign = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneMod1NDesign") == "true");
	var initdoneDrv1NDesign = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDrv1NDesign") == "true");
	var initdoneDsn1NDevice = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDevice") == "true");
	var initdoneDsn1NStack = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NStack") == "true");
	var initdoneDsn1NDomaingd = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDomaingd") == "true");
	var initdoneDsn1NDomain = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneDsn1NDomain") == "true");
	var initdone1NBlock = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdone1NBlock") == "true");
	var initdone1NReticle = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdone1NReticle") == "true");
	var initdoneHk1NLevel = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLevel") == "true");
	var initdoneHk1NVertex = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NVertex") == "true");
	var initdoneHk1NLineguide = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLineguide") == "true");
	var initdoneHk1NArcguide = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NArcguide") == "true");
	var initdoneHk1NLayer = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NLayer") == "true");
	var initdoneHk1NStructure = (retrieveSi(srcdoc, "StatAppPlnrDsnRec", "initdoneHk1NStructure") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlPlnrDsnPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlPlnrDsnDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneViewxy) {
		lhsdoc.getElementById("Viewxy").src = "./PnlPlnrDsnViewxy.html?scrJref=" + scrJrefViewxy;
	} else if (!initdoneViewz) {
		lhsdoc.getElementById("Viewz").src = "./PnlPlnrDsnViewz.html?scrJref=" + scrJrefViewz;
	} else if (!initdoneMod1NDesign) {
		rhsdoc.getElementById("Mod1NDesign").src = "./PnlPlnrDsnMod1NDesign.html?scrJref=" + scrJrefMod1NDesign;
	} else if (!initdoneDrv1NDesign) {
		rhsdoc.getElementById("Drv1NDesign").src = "./PnlPlnrDsnDrv1NDesign.html?scrJref=" + scrJrefDrv1NDesign;
	} else if (!initdoneDsn1NDevice) {
		rhsdoc.getElementById("Dsn1NDevice").src = "./PnlPlnrDsnDsn1NDevice.html?scrJref=" + scrJrefDsn1NDevice;
	} else if (!initdoneDsn1NStack) {
		rhsdoc.getElementById("Dsn1NStack").src = "./PnlPlnrDsnDsn1NStack.html?scrJref=" + scrJrefDsn1NStack;
	} else if (!initdoneDsn1NDomaingd) {
		rhsdoc.getElementById("Dsn1NDomaingd").src = "./PnlPlnrDsnDsn1NDomaingd.html?scrJref=" + scrJrefDsn1NDomaingd;
	} else if (!initdoneDsn1NDomain) {
		rhsdoc.getElementById("Dsn1NDomain").src = "./PnlPlnrDsnDsn1NDomain.html?scrJref=" + scrJrefDsn1NDomain;
	} else if (!initdone1NBlock) {
		rhsdoc.getElementById("1NBlock").src = "./PnlPlnrDsn1NBlock.html?scrJref=" + scrJref1NBlock;
	} else if (!initdone1NReticle) {
		rhsdoc.getElementById("1NReticle").src = "./PnlPlnrDsn1NReticle.html?scrJref=" + scrJref1NReticle;
	} else if (!initdoneHk1NLevel) {
		rhsdoc.getElementById("Hk1NLevel").src = "./PnlPlnrDsnHk1NLevel.html?scrJref=" + scrJrefHk1NLevel;
	} else if (!initdoneHk1NVertex) {
		rhsdoc.getElementById("Hk1NVertex").src = "./PnlPlnrDsnHk1NVertex.html?scrJref=" + scrJrefHk1NVertex;
	} else if (!initdoneHk1NLineguide) {
		rhsdoc.getElementById("Hk1NLineguide").src = "./PnlPlnrDsnHk1NLineguide.html?scrJref=" + scrJrefHk1NLineguide;
	} else if (!initdoneHk1NArcguide) {
		rhsdoc.getElementById("Hk1NArcguide").src = "./PnlPlnrDsnHk1NArcguide.html?scrJref=" + scrJrefHk1NArcguide;
	} else if (!initdoneHk1NLayer) {
		rhsdoc.getElementById("Hk1NLayer").src = "./PnlPlnrDsnHk1NLayer.html?scrJref=" + scrJrefHk1NLayer;
	} else if (!initdoneHk1NStructure) {
		rhsdoc.getElementById("Hk1NStructure").src = "./PnlPlnrDsnHk1NStructure.html?scrJref=" + scrJrefHk1NStructure;

	} else {
		refreshB();
	};
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "Viewxy") || (short == "Viewz")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Pre") heightPre = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "Viewxy") heightViewxy = height;
		else if (short == "Viewz") heightViewz = height;
		else if (short == "Mod1NDesign") heightMod1NDesign = height;
		else if (short == "Drv1NDesign") heightDrv1NDesign = height;
		else if (short == "Dsn1NDevice") heightDsn1NDevice = height;
		else if (short == "Dsn1NStack") heightDsn1NStack = height;
		else if (short == "Dsn1NDomaingd") heightDsn1NDomaingd = height;
		else if (short == "Dsn1NDomain") heightDsn1NDomain = height;
		else if (short == "1NBlock") height1NBlock = height;
		else if (short == "1NReticle") height1NReticle = height;
		else if (short == "Hk1NLevel") heightHk1NLevel = height;
		else if (short == "Hk1NVertex") heightHk1NVertex = height;
		else if (short == "Hk1NLineguide") heightHk1NLineguide = height;
		else if (short == "Hk1NArcguide") heightHk1NArcguide = height;
		else if (short == "Hk1NLayer") heightHk1NLayer = height;
		else if (short == "Hk1NStructure") heightHk1NStructure = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlPlnrDsnRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDsnRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 653);
	doc.getElementById("tdSide").setAttribute("height", "653");
	doc.getElementById("Rec_side").setAttribute("height", "653");
	doc.getElementById("Rec_cont").setAttribute("height", "653");

	doc.getElementById("Rec_side").src = "./PnlPlnrDsnRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlPlnrDsnRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "Viewxy") || (pnlshort == "Viewz")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "Viewxy") heightViewxy = height;
	else if (pnlshort == "Viewz") heightViewz = height;
	else if (pnlshort == "Mod1NDesign") heightMod1NDesign = height;
	else if (pnlshort == "Drv1NDesign") heightDrv1NDesign = height;
	else if (pnlshort == "Dsn1NDevice") heightDsn1NDevice = height;
	else if (pnlshort == "Dsn1NStack") heightDsn1NStack = height;
	else if (pnlshort == "Dsn1NDomaingd") heightDsn1NDomaingd = height;
	else if (pnlshort == "Dsn1NDomain") heightDsn1NDomain = height;
	else if (pnlshort == "1NBlock") height1NBlock = height;
	else if (pnlshort == "1NReticle") height1NReticle = height;
	else if (pnlshort == "Hk1NLevel") heightHk1NLevel = height;
	else if (pnlshort == "Hk1NVertex") heightHk1NVertex = height;
	else if (pnlshort == "Hk1NLineguide") heightHk1NLineguide = height;
	else if (pnlshort == "Hk1NArcguide") heightHk1NArcguide = height;
	else if (pnlshort == "Hk1NLayer") heightHk1NLayer = height;
	else if (pnlshort == "Hk1NStructure") heightHk1NStructure = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightViewxy+13 + heightViewz+13 + 5;
	heightRhs = heightMod1NDesign+13 + heightDrv1NDesign+13 + heightDsn1NDevice+13 + heightDsn1NStack+13 + heightDsn1NDomaingd+13 + heightDsn1NDomain+13 + height1NBlock+13 + height1NReticle+13 + heightHk1NLevel+13 + heightHk1NVertex+13 + heightHk1NLineguide+13 + heightHk1NArcguide+13 + heightHk1NLayer+13 + heightHk1NStructure+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDsnRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagPlnrDsnRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		minimize();
	} else if (srefIxPlnrVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDsnRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlviewxyAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlviewxyAvail") == "true");
	var pnlviewzAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlviewzAvail") == "true");
	var pnlmod1ndesignAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlmod1ndesignAvail") == "true");
	var pnldsn1ndeviceAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnldsn1ndeviceAvail") == "true");
	var pnldsn1nstackAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnldsn1nstackAvail") == "true");
	var pnl1nblockAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnl1nblockAvail") == "true");
	var pnl1nreticleAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnl1nreticleAvail") == "true");
	var pnlhk1nlevelAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1nlevelAvail") == "true");
	var pnlhk1nvertexAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1nvertexAvail") == "true");
	var pnlhk1nlineguideAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1nlineguideAvail") == "true");
	var pnlhk1narcguideAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1narcguideAvail") == "true");
	var pnlhk1nlayerAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1nlayerAvail") == "true");
	var pnlhk1nstructureAvail = (retrieveSi(srcdoc, "StatShrPlnrDsnRec", "pnlhk1nstructureAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfPlnrDsnRec", "TxtRef"));

	if (setPnlAvail("Viewxy", pnlviewxyAvail)) updh = true;
	if (setPnlAvail("Viewz", pnlviewzAvail)) updh = true;
	if (setPnlAvail("Mod1NDesign", pnlmod1ndesignAvail)) updh = true;
	if (setPnlAvail("Dsn1NDevice", pnldsn1ndeviceAvail)) updh = true;
	if (setPnlAvail("Dsn1NStack", pnldsn1nstackAvail)) updh = true;
	if (setPnlAvail("1NBlock", pnl1nblockAvail)) updh = true;
	if (setPnlAvail("1NReticle", pnl1nreticleAvail)) updh = true;
	if (setPnlAvail("Hk1NLevel", pnlhk1nlevelAvail)) updh = true;
	if (setPnlAvail("Hk1NVertex", pnlhk1nvertexAvail)) updh = true;
	if (setPnlAvail("Hk1NLineguide", pnlhk1nlineguideAvail)) updh = true;
	if (setPnlAvail("Hk1NArcguide", pnlhk1narcguideAvail)) updh = true;
	if (setPnlAvail("Hk1NLayer", pnlhk1nlayerAvail)) updh = true;
	if (setPnlAvail("Hk1NStructure", pnlhk1nstructureAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

	if (srefIxPlnrVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxPlnrVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppPlnrDsnRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngPlnrDsnRecData", "ContInfPlnrDsnRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngPlnrDsnRecData", "StatAppPlnrDsnRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngPlnrDsnRecData", "StatShrPlnrDsnRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngPlnrDsnRecData", "TagPlnrDsnRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	_scrJref = retrieveValue(dom, "//plnr:*/plnr:scrJref");
	srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngPlnrDsnRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

				if (newSrefIxPlnrVExpstate != srefIxPlnrVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxPlnrVExpstate == "mind") {
						minimize();
					} else if (newSrefIxPlnrVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxPlnrVExpstate != "mind") {
			if (_scrJref == scrJrefPre) {
				lhsdoc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefViewxy) {
				lhsdoc.getElementById("Viewxy").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefViewz) {
				lhsdoc.getElementById("Viewz").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMod1NDesign) {
				rhsdoc.getElementById("Mod1NDesign").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDrv1NDesign) {
				rhsdoc.getElementById("Drv1NDesign").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDsn1NDevice) {
				rhsdoc.getElementById("Dsn1NDevice").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDsn1NStack) {
				rhsdoc.getElementById("Dsn1NStack").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDsn1NDomaingd) {
				rhsdoc.getElementById("Dsn1NDomaingd").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDsn1NDomain) {
				rhsdoc.getElementById("Dsn1NDomain").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NBlock) {
				rhsdoc.getElementById("1NBlock").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NReticle) {
				rhsdoc.getElementById("1NReticle").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NLevel) {
				rhsdoc.getElementById("Hk1NLevel").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVertex) {
				rhsdoc.getElementById("Hk1NVertex").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NLineguide) {
				rhsdoc.getElementById("Hk1NLineguide").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NArcguide) {
				rhsdoc.getElementById("Hk1NArcguide").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NLayer) {
				rhsdoc.getElementById("Hk1NLayer").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NStructure) {
				rhsdoc.getElementById("Hk1NStructure").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngPlnrDsnRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxPlnrVExpstate, newSrefIxPlnrVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//plnr:*");

		if (blk) {
			if (blk.nodeName == "DpchEngPlnrConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngPlnrDsnRecData") {
				srefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxPlnrVExpstate = retrieveSi(srcdoc, "StatShrPlnrDsnRec", "srefIxPlnrVExpstate");

					if (newSrefIxPlnrVExpstate != srefIxPlnrVExpstate) {
						updateScrJrefs();

						if (newSrefIxPlnrVExpstate == "mind") {
							minimize();
						} else if (newSrefIxPlnrVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};


