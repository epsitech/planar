/**
  * \file PnlPlnrStartLogin.js
  * web client functionality for Plnr login panel
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function refresh(srefIxPlnrVLocale) {
	var pup = doc.getElementById("PupLocale");
	var opt;

	clearElem(pup);

	if (srefIxPlnrVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Login");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "English (United States)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "User name");
		setTextContent(doc, doc.getElementById("CptPassword"), "Password");
		setTextContent(doc, doc.getElementById("ButReset"), "Reset");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login");
	};

	pup.value = srefIxPlnrVLocale;
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handlePupLocaleChange() {
	srefIxPlnrVLocale = doc.getElementById("PupLocale").value;
	refresh(srefIxPlnrVLocale);

	// notify card to change cookie
	getCrdwnd().setLocale(srefIxPlnrVLocale);
};

function handleTxfPasswordKey(evt) {
	if (evt.keyCode == 13) {
		handleButLoginClick();
		return false;
	};

	return true;
};

function handleButResetClick() {
	doc.getElementById("TxfUsername").value = "";
	doc.getElementById("TxfPassword").value = "";
};

function handleButLoginClick() {
	var str = serializeDpchAppLogin(doc.getElementById("TxfPassword").value, doc.getElementById("TxfUsername").value, getCrdwnd().getLocale());
	sendReq(str, doc, handleDpchAppLoginReply);
};

function handleDpchAppLoginReply() {
	var dom;

	var accepted, scrJref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		accepted = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:accepted");
		scrJref = retrieveValue(dom, "//plnr:DpchEngPlnrConfirm/plnr:scrJref");

		if (accepted == "true") {
			var str = serializeDpchApp("DpchAppPlnrInit", scrJref);
			sendReq(str, doc, handleDpchAppInitReply);

		} else {
			getCrdwnd().setCont("Fail");
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//plnr:*");
		if (blk) {
			if (blk.nodeName == "DpchEngSessPlnrData") {
				var scrJrefCrdnav = retrieveValue(dom, "//plnr:DpchEngSessPlnrData/plnr:StatShrSessPlnr/plnr:Si[@sref='scrJrefCrdnav']");

				if (scrJrefCrdnav == "") getCrdwnd().setCont("Fail");
				else window.open("/web/CrdPlnrNav/CrdPlnrNav.html?scrJref=" + scrJrefCrdnav, "_parent");
			};
		};
	};
};

function serializeDpchAppLogin(password, username, srefIxPlnrVLocale) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppRootPlnrLogin");

	elem = doc.createElement("password");
	txt = doc.createTextNode(password);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("username");
	txt = doc.createTextNode(username);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("srefIxPlnrVLocale");
	txt = doc.createTextNode(srefIxPlnrVLocale);
	elem.appendChild(txt);
	dpch.appendChild(elem);	

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};


