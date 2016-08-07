/**
  * \file PnlPlnrStartFail.js
  * web client functionality for Plnr login failure panel
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function refresh(srefIxPlnrVLocale) {
	if (srefIxPlnrVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Error");
		setTextContent(doc, doc.getElementById("CptMessage"), "Login failed.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Back");
	};
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handleButLoginClick() {
	getCrdwnd().setCont("Login");
};


