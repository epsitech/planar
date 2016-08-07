/**
  * \file RootPlnr_blks.cpp
  * job handler for job RootPlnr (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class RootPlnr::DpchAppLogin
 ******************************************************************************/

RootPlnr::DpchAppLogin::DpchAppLogin() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPROOTPLNRLOGIN) {
};

void RootPlnr::DpchAppLogin::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppRootPlnrLogin");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "password", "", password)) add(PASSWORD);
		if (extractStringUclc(docctx, basexpath, "username", "", username)) add(USERNAME);
	} else {
	};
};


