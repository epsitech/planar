/**
  * \file RootPlnr.cpp
  * app access code for job RootPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "RootPlnr.h"

/******************************************************************************
 class RootPlnr::DpchAppLogin
 ******************************************************************************/

RootPlnr::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& password
			, const string& username
			, const set<uint>& mask
		) : DpchAppPlnr(VecPlnrVDpch::DPCHAPPROOTPLNRLOGIN, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, PASSWORD, USERNAME};
	else this->mask = mask;

	this->password = password;
	this->username = username;
};

void RootPlnr::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootPlnrLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(USERNAME)) writeString(wr, "username", username);
	xmlTextWriterEndElement(wr);
};

