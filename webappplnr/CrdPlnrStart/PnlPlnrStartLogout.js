/**
  * \file PnlPlnrStartLogout.js
  * web client functionality for Plnr logout panel
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

function refresh(srefIxPlnrVLocale) {
	if (srefIxPlnrVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Logout");
		setTextContent(doc, doc.getElementById("CptMessage"), "Your session has been terminated.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login screen");
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


