/**
  * \file IexPlnrIni_blks.cpp
  * import/export handler for database DbsPlnr (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

/******************************************************************************
 class IexPlnrIni::VecVIme
 ******************************************************************************/

uint IexPlnrIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	else if (s == "imeiavkeylistkey1") return IMEIAVKEYLISTKEY1;
	else if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	else if (s == "imeimcalc") return IMEIMCALC;
	else if (s == "imeimdevice") return IMEIMDEVICE;
	else if (s == "imeimfile") return IMEIMFILE;
	else if (s == "imeimmaterial") return IMEIMMATERIAL;
	else if (s == "imeimusergroup") return IMEIMUSERGROUP;
	else if (s == "imeiamdevicepar") return IMEIAMDEVICEPAR;
	else if (s == "imeiammaterialpar") return IMEIAMMATERIALPAR;
	else if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	else if (s == "imeiavkeylistkey2") return IMEIAVKEYLISTKEY2;
	else if (s == "imeiavkeylistkey3") return IMEIAVKEYLISTKEY3;
	else if (s == "imeijavkeylistkey1") return IMEIJAVKEYLISTKEY1;
	else if (s == "imeimstructure") return IMEIMSTRUCTURE;
	else if (s == "imeimuser") return IMEIMUSER;
	else if (s == "imeijavkeylistkey2") return IMEIJAVKEYLISTKEY2;
	else if (s == "imeijavkeylistkey3") return IMEIJAVKEYLISTKEY3;
	else if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	else if (s == "imeimperson") return IMEIMPERSON;
	else if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;

	return(0);
};

string IexPlnrIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	else if (ix == IMEIAVKEYLISTKEY1) return("ImeIAVKeylistKey1");
	else if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	else if (ix == IMEIMCALC) return("ImeIMCalc");
	else if (ix == IMEIMDEVICE) return("ImeIMDevice");
	else if (ix == IMEIMFILE) return("ImeIMFile");
	else if (ix == IMEIMMATERIAL) return("ImeIMMaterial");
	else if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");
	else if (ix == IMEIAMDEVICEPAR) return("ImeIAMDevicePar");
	else if (ix == IMEIAMMATERIALPAR) return("ImeIAMMaterialPar");
	else if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	else if (ix == IMEIAVKEYLISTKEY2) return("ImeIAVKeylistKey2");
	else if (ix == IMEIAVKEYLISTKEY3) return("ImeIAVKeylistKey3");
	else if (ix == IMEIJAVKEYLISTKEY1) return("ImeIJAVKeylistKey1");
	else if (ix == IMEIMSTRUCTURE) return("ImeIMStructure");
	else if (ix == IMEIMUSER) return("ImeIMUser");
	else if (ix == IMEIJAVKEYLISTKEY2) return("ImeIJAVKeylistKey2");
	else if (ix == IMEIJAVKEYLISTKEY3) return("ImeIJAVKeylistKey3");
	else if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	else if (ix == IMEIMPERSON) return("ImeIMPerson");
	else if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");

	return("");
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAVControlPar
 ******************************************************************************/

IexPlnrIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixPlnrVControl
			, const string& Par
			, const string& Val
		) : PlnrAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixPlnrVControl = ixPlnrVControl;
	this->Par = Par;
	this->Val = Val;
};

IexPlnrIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAVControlPar() {
	PlnrAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnravcontrolpar->loadRecByRef(ref, &rec)) {
		ixPlnrVControl = rec->ixPlnrVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixPlnrVControl = VecPlnrVControl::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Par = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxPlnrVControl;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxPlnrVControl", "ctl", srefIxPlnrVControl)) {
			ixPlnrVControl = VecPlnrVControl::getIx(srefIxPlnrVControl);
			ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXPLNRVCONTROL;
		};
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexPlnrIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecPlnrVControl::getSref(ixPlnrVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexPlnrIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxPlnrVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVControl::getSref(ixPlnrVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxPlnrVControl") ix |= SREFIXPLNRVCONTROL;
		else if (ss[i] == "Par") ix |= PAR;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexPlnrIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXPLNRVCONTROL) ss.push_back("srefIxPlnrVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVControlPar
 ******************************************************************************/

IexPlnrIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexPlnrIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexPlnrIni::ImeIAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIAVControlPar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIJAVKeylistKey1
 ******************************************************************************/

IexPlnrIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			const uint x1IxPlnrVLocale
			, const string& Title
			, const string& Comment
		) : PlnrJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIJAVKeylistKey1() {
	PlnrJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrjavkeylistkey->loadRecByRef(ref, &rec)) {
		refPlnrAVKeylistKey = rec->refPlnrAVKeylistKey;
		x1IxPlnrVLocale = rec->x1IxPlnrVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxPlnrVLocale = VecPlnrVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxPlnrVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxPlnrVLocale", "lcl", srefX1IxPlnrVLocale)) {
			x1IxPlnrVLocale = VecPlnrVLocale::getIx(srefX1IxPlnrVLocale);
			ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXPLNRVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;
	};
};

void IexPlnrIni::ImeitemIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecPlnrVLocale::getSref(x1IxPlnrVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexPlnrIni::ImeitemIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey1","srefX1IxPlnrVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVLocale::getSref(x1IxPlnrVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIJAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxPlnrVLocale") ix |= SREFX1IXPLNRVLOCALE;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIJAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIJAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXPLNRVLOCALE) ss.push_back("srefX1IxPlnrVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey1
 ******************************************************************************/

IexPlnrIni::ImeIJAVKeylistKey1::ImeIJAVKeylistKey1() {
};

IexPlnrIni::ImeIJAVKeylistKey1::~ImeIJAVKeylistKey1() {
	clear();
};

void IexPlnrIni::ImeIJAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIJAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIJAVKeylistKey1();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIJAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIJAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey1." << StrMod::replaceChar(ImeIJAVKeylistKey1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAVKeylistKey1
 ******************************************************************************/

IexPlnrIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			const uint klsIxPlnrVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
		) : PlnrAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxPlnrVKeylist = klsIxPlnrVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexPlnrIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAVKeylistKey1() {
	PlnrAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnravkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxPlnrVKeylist = rec->klsIxPlnrVKeylist;
		x1IxPlnrVMaintable = rec->x1IxPlnrVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxPlnrVKeylist = VecPlnrVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1)) {
			if (!imeijavkeylistkey1.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxPlnrVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxPlnrVKeylist", "kls", srefKlsIxPlnrVKeylist)) {
			klsIxPlnrVKeylist = VecPlnrVKeylist::getIx(srefKlsIxPlnrVKeylist);
			ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXPLNRVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;
		imeijavkeylistkey1.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << VecPlnrVKeylist::getSref(klsIxPlnrVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey1.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey1","srefKlsIxPlnrVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVKeylist::getSref(klsIxPlnrVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefKlsIxPlnrVKeylist") ix |= SREFKLSIXPLNRVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Avail") ix |= AVAIL;
		else if (ss[i] == "Implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexPlnrIni::ImeIAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXPLNRVKEYLIST) ss.push_back("srefKlsIxPlnrVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey1
 ******************************************************************************/

IexPlnrIni::ImeIAVKeylistKey1::ImeIAVKeylistKey1() {
};

IexPlnrIni::ImeIAVKeylistKey1::~ImeIAVKeylistKey1() {
	clear();
};

void IexPlnrIni::ImeIAVKeylistKey1::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIAVKeylistKey1();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey1." << StrMod::replaceChar(ImeIAVKeylistKey1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey1");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexPlnrIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxPlnrVValuelist
			, const uint x1IxPlnrVLocale
			, const string& Val
		) : PlnrAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxPlnrVValuelist = vlsIxPlnrVValuelist;
	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Val = Val;
};

IexPlnrIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAVValuelistVal() {
	PlnrAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnravvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxPlnrVValuelist = rec->vlsIxPlnrVValuelist;
		x1IxPlnrVLocale = rec->x1IxPlnrVLocale;
		Val = rec->Val;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) vlsIxPlnrVValuelist = VecPlnrVValuelist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) x1IxPlnrVLocale = VecPlnrVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefVlsIxPlnrVValuelist;
	string srefX1IxPlnrVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxPlnrVValuelist", "vls", srefVlsIxPlnrVValuelist)) {
			vlsIxPlnrVValuelist = VecPlnrVValuelist::getIx(srefVlsIxPlnrVValuelist);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXPLNRVVALUELIST;
		};
		if (extractStringUclc(docctx, basexpath, "srefX1IxPlnrVLocale", "lcl", srefX1IxPlnrVLocale)) {
			x1IxPlnrVLocale = VecPlnrVLocale::getIx(srefX1IxPlnrVLocale);
			ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXPLNRVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexPlnrIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecPlnrVValuelist::getSref(vlsIxPlnrVValuelist) << "\t" << VecPlnrVLocale::getSref(x1IxPlnrVLocale) << "\t" << Val << endl;
};

void IexPlnrIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxPlnrVValuelist","srefX1IxPlnrVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVValuelist::getSref(vlsIxPlnrVValuelist));
		writeString(wr, tags[2], VecPlnrVLocale::getSref(x1IxPlnrVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefVlsIxPlnrVValuelist") ix |= SREFVLSIXPLNRVVALUELIST;
		else if (ss[i] == "srefX1IxPlnrVLocale") ix |= SREFX1IXPLNRVLOCALE;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexPlnrIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXPLNRVVALUELIST) ss.push_back("srefVlsIxPlnrVValuelist");
	if (ix & SREFX1IXPLNRVLOCALE) ss.push_back("srefX1IxPlnrVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVValuelistVal
 ******************************************************************************/

IexPlnrIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexPlnrIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexPlnrIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIAVValuelistVal();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIJAVKeylistKey3
 ******************************************************************************/

IexPlnrIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
			const uint x1IxPlnrVLocale
			, const string& Title
			, const string& Comment
		) : PlnrJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIJAVKeylistKey3() {
	PlnrJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrjavkeylistkey->loadRecByRef(ref, &rec)) {
		refPlnrAVKeylistKey = rec->refPlnrAVKeylistKey;
		x1IxPlnrVLocale = rec->x1IxPlnrVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIJAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxPlnrVLocale = VecPlnrVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxPlnrVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxPlnrVLocale", "lcl", srefX1IxPlnrVLocale)) {
			x1IxPlnrVLocale = VecPlnrVLocale::getIx(srefX1IxPlnrVLocale);
			ixWIelValid += ImeIJAVKeylistKey3::VecWIel::SREFX1IXPLNRVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::COMMENT;
	};
};

void IexPlnrIni::ImeitemIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecPlnrVLocale::getSref(x1IxPlnrVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexPlnrIni::ImeitemIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey3","srefX1IxPlnrVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVLocale::getSref(x1IxPlnrVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIJAVKeylistKey3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxPlnrVLocale") ix |= SREFX1IXPLNRVLOCALE;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIJAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIJAVKeylistKey3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXPLNRVLOCALE) ss.push_back("srefX1IxPlnrVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey3
 ******************************************************************************/

IexPlnrIni::ImeIJAVKeylistKey3::ImeIJAVKeylistKey3() {
};

IexPlnrIni::ImeIJAVKeylistKey3::~ImeIJAVKeylistKey3() {
	clear();
};

void IexPlnrIni::ImeIJAVKeylistKey3::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIJAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIJAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexPlnrIni::ImeitemIJAVKeylistKey3();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIJAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIJAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey3." << StrMod::replaceChar(ImeIJAVKeylistKey3::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey3");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAVKeylistKey3
 ******************************************************************************/

IexPlnrIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
			const uint klsIxPlnrVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
		) : PlnrAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxPlnrVKeylist = klsIxPlnrVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexPlnrIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAVKeylistKey3() {
	PlnrAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnravkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxPlnrVKeylist = rec->klsIxPlnrVKeylist;
		x1IxPlnrVMaintable = rec->x1IxPlnrVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) klsIxPlnrVKeylist = VecPlnrVKeylist::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) sref = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Avail = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Implied = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY3)) {
			if (!imeijavkeylistkey3.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefKlsIxPlnrVKeylist;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxPlnrVKeylist", "kls", srefKlsIxPlnrVKeylist)) {
			klsIxPlnrVKeylist = VecPlnrVKeylist::getIx(srefKlsIxPlnrVKeylist);
			ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREFKLSIXPLNRVKEYLIST;
		};
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::IMPLIED;
		imeijavkeylistkey3.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecPlnrVKeylist::getSref(klsIxPlnrVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey3.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey3","srefKlsIxPlnrVKeylist","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVKeylist::getSref(klsIxPlnrVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		imeijavkeylistkey3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAVKeylistKey3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefKlsIxPlnrVKeylist") ix |= SREFKLSIXPLNRVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Avail") ix |= AVAIL;
		else if (ss[i] == "Implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexPlnrIni::ImeIAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAVKeylistKey3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXPLNRVKEYLIST) ss.push_back("srefKlsIxPlnrVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey3
 ******************************************************************************/

IexPlnrIni::ImeIAVKeylistKey3::ImeIAVKeylistKey3() {
};

IexPlnrIni::ImeIAVKeylistKey3::~ImeIAVKeylistKey3() {
	clear();
};

void IexPlnrIni::ImeIAVKeylistKey3::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIAVKeylistKey3();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey3." << StrMod::replaceChar(ImeIAVKeylistKey3::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey3");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMCalc
 ******************************************************************************/

IexPlnrIni::ImeitemIMCalc::ImeitemIMCalc(
			const uint ixVDim
			, const string& Title
			, const string& Comment
		) : PlnrMCalc() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVDim = ixVDim;
	this->Title = Title;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIMCalc::ImeitemIMCalc(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMCalc() {
	PlnrMCalc* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmcalc->loadRecByRef(ref, &rec)) {
		ixVDim = rec->ixVDim;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMCalc::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVDim = VecPlnrVMCalcDim::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY3)) {
			if (!imeiavkeylistkey3.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMCalc::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVDim;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVDim", "dim", srefIxVDim)) {
			ixVDim = VecPlnrVMCalcDim::getIx(srefIxVDim);
			ixWIelValid += ImeIMCalc::VecWIel::SREFIXVDIM;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMCalc::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCalc::VecWIel::COMMENT;
		imeiavkeylistkey3.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMCalc::writeTxt(
			fstream& outfile
		) {
	outfile << VecPlnrVMCalcDim::getSref(ixVDim) << "\t" << Title << "\t" << Comment << endl;
	imeiavkeylistkey3.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMCalc::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dim","tit","cmt"};
	else tags = {"ImeitemIMCalc","srefIxVDim","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVMCalcDim::getSref(ixVDim));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeiavkeylistkey3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMCalc::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMCalc::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxVDim") ix |= SREFIXVDIM;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIMCalc::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMCalc::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVDIM) ss.push_back("srefIxVDim");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMCalc
 ******************************************************************************/

IexPlnrIni::ImeIMCalc::ImeIMCalc() {
};

IexPlnrIni::ImeIMCalc::~ImeIMCalc() {
	clear();
};

void IexPlnrIni::ImeIMCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMCalc::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMCalc* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIMCalc();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMCalc::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMCalc* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCalc");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCalc", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCalc";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMCalc();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMCalc::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCalc." << StrMod::replaceChar(ImeIMCalc::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMCalc::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCalc");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAMDevicePar
 ******************************************************************************/

IexPlnrIni::ImeitemIAMDevicePar::ImeitemIAMDevicePar(
			const string& x2SrefKKey
			, const ubigint irefRefPlnrMFile
			, const string& Val
		) : PlnrAMDevicePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x2SrefKKey = x2SrefKKey;
	this->irefRefPlnrMFile = irefRefPlnrMFile;
	this->Val = Val;
};

IexPlnrIni::ImeitemIAMDevicePar::ImeitemIAMDevicePar(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAMDevicePar() {
	PlnrAMDevicePar* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnramdevicepar->loadRecByRef(ref, &rec)) {
		refPlnrMDevice = rec->refPlnrMDevice;
		x2SrefKKey = rec->x2SrefKKey;
		refPlnrMFile = rec->refPlnrMFile;
		Val = rec->Val;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAMDevicePar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x2SrefKKey = txtrd.fields[0];
	if (txtrd.fields.size() > 1) irefRefPlnrMFile = atoll(txtrd.fields[1].c_str());
	if (txtrd.fields.size() > 2) Val = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAMDevicePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x2SrefKKey", "key", x2SrefKKey)) ixWIelValid += ImeIAMDevicePar::VecWIel::X2SREFKKEY;
		if (extractUbigintUclc(docctx, basexpath, "irefRefPlnrMFile", "fil", irefRefPlnrMFile)) ixWIelValid += ImeIAMDevicePar::VecWIel::IREFREFPLNRMFILE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMDevicePar::VecWIel::VAL;
	};
};

void IexPlnrIni::ImeitemIAMDevicePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x2SrefKKey << "\t" << irefRefPlnrMFile << "\t" << Val << endl;
};

void IexPlnrIni::ImeitemIAMDevicePar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","fil","val"};
	else tags = {"ImeitemIAMDevicePar","x2SrefKKey","irefRefPlnrMFile","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x2SrefKKey);
		writeUbigint(wr, tags[2], irefRefPlnrMFile);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMDevicePar::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAMDevicePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x2SrefKKey") ix |= X2SREFKKEY;
		else if (ss[i] == "irefRefPlnrMFile") ix |= IREFREFPLNRMFILE;
		else if (ss[i] == "Val") ix |= VAL;
	};

	return(ix);
};

void IexPlnrIni::ImeIAMDevicePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VAL);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAMDevicePar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X2SREFKKEY) ss.push_back("x2SrefKKey");
	if (ix & IREFREFPLNRMFILE) ss.push_back("irefRefPlnrMFile");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMDevicePar
 ******************************************************************************/

IexPlnrIni::ImeIAMDevicePar::ImeIAMDevicePar() {
};

IexPlnrIni::ImeIAMDevicePar::~ImeIAMDevicePar() {
	clear();
};

void IexPlnrIni::ImeIAMDevicePar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAMDevicePar::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAMDevicePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIAMDevicePar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAMDevicePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAMDevicePar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMDevicePar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMDevicePar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMDevicePar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAMDevicePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAMDevicePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMDevicePar." << StrMod::replaceChar(ImeIAMDevicePar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAMDevicePar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMDevicePar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIJAVKeylistKey2
 ******************************************************************************/

IexPlnrIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			const uint x1IxPlnrVLocale
			, const string& Title
			, const string& Comment
		) : PlnrJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIJAVKeylistKey2() {
	PlnrJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrjavkeylistkey->loadRecByRef(ref, &rec)) {
		refPlnrAVKeylistKey = rec->refPlnrAVKeylistKey;
		x1IxPlnrVLocale = rec->x1IxPlnrVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxPlnrVLocale = VecPlnrVLocale::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Comment = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxPlnrVLocale;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxPlnrVLocale", "lcl", srefX1IxPlnrVLocale)) {
			x1IxPlnrVLocale = VecPlnrVLocale::getIx(srefX1IxPlnrVLocale);
			ixWIelValid += ImeIJAVKeylistKey2::VecWIel::SREFX1IXPLNRVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;
	};
};

void IexPlnrIni::ImeitemIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecPlnrVLocale::getSref(x1IxPlnrVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexPlnrIni::ImeitemIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey2","srefX1IxPlnrVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVLocale::getSref(x1IxPlnrVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIJAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxPlnrVLocale") ix |= SREFX1IXPLNRVLOCALE;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIJAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIJAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXPLNRVLOCALE) ss.push_back("srefX1IxPlnrVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIJAVKeylistKey2
 ******************************************************************************/

IexPlnrIni::ImeIJAVKeylistKey2::ImeIJAVKeylistKey2() {
};

IexPlnrIni::ImeIJAVKeylistKey2::~ImeIJAVKeylistKey2() {
	clear();
};

void IexPlnrIni::ImeIJAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIJAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexPlnrIni::ImeitemIJAVKeylistKey2();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIJAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIJAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey2." << StrMod::replaceChar(ImeIJAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAVKeylistKey2
 ******************************************************************************/

IexPlnrIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			const string& sref
			, const string& Avail
			, const string& Implied
		) : PlnrAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
};

IexPlnrIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAVKeylistKey2() {
	PlnrAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnravkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxPlnrVKeylist = rec->klsIxPlnrVKeylist;
		x1IxPlnrVMaintable = rec->x1IxPlnrVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Avail = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Implied = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2)) {
			if (!imeijavkeylistkey2.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::IMPLIED;
		imeijavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Avail << "\t" << Implied << endl;
	imeijavkeylistkey2.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","avl","imp"};
	else tags = {"ImeitemIAVKeylistKey2","sref","Avail","Implied"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Avail);
		writeString(wr, tags[3], Implied);
		imeijavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Avail") ix |= AVAIL;
		else if (ss[i] == "Implied") ix |= IMPLIED;
	};

	return(ix);
};

void IexPlnrIni::ImeIAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IMPLIED);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAVKeylistKey2
 ******************************************************************************/

IexPlnrIni::ImeIAVKeylistKey2::ImeIAVKeylistKey2() {
};

IexPlnrIni::ImeIAVKeylistKey2::~ImeIAVKeylistKey2() {
	clear();
};

void IexPlnrIni::ImeIAVKeylistKey2::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIAVKeylistKey2();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey2." << StrMod::replaceChar(ImeIAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey2");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMStructure
 ******************************************************************************/

IexPlnrIni::ImeitemIMStructure::ImeitemIMStructure(
			const string& sref
		) : PlnrMStructure() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexPlnrIni::ImeitemIMStructure::ImeitemIMStructure(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMStructure() {
	PlnrMStructure* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmstructure->loadRecByRef(ref, &rec)) {
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		sref = rec->sref;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMStructure::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMStructure::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMStructure::VecWIel::SREF;
	};
};

void IexPlnrIni::ImeitemIMStructure::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << endl;
};

void IexPlnrIni::ImeitemIMStructure::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMStructure","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMStructure::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMStructure::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexPlnrIni::ImeIMStructure::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREF);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMStructure::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMStructure
 ******************************************************************************/

IexPlnrIni::ImeIMStructure::ImeIMStructure() {
};

IexPlnrIni::ImeIMStructure::~ImeIMStructure() {
	clear();
};

void IexPlnrIni::ImeIMStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMStructure::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMStructure* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIMStructure();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMStructure::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMStructure* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMStructure");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMStructure", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMStructure";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMStructure();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMStructure::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMStructure." << StrMod::replaceChar(ImeIMStructure::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMStructure::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMStructure");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMDevice
 ******************************************************************************/

IexPlnrIni::ImeitemIMDevice::ImeitemIMDevice(
			const ubigint iref
			, const ubigint irefSupRefPlnrMDevice
			, const string& sref
			, const string& Comment
		) : PlnrMDevice() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->irefSupRefPlnrMDevice = irefSupRefPlnrMDevice;
	this->sref = sref;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIMDevice::ImeitemIMDevice(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMDevice() {
	PlnrMDevice* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmdevice->loadRecByRef(ref, &rec)) {
		supRefPlnrMDevice = rec->supRefPlnrMDevice;
		sref = rec->sref;
		ixVAligntype = rec->ixVAligntype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMDevice::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) irefSupRefPlnrMDevice = atoll(txtrd.fields[1].c_str());
	if (txtrd.fields.size() > 2) sref = txtrd.fields[2];
	if (txtrd.fields.size() > 3) Comment = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMDEVICEPAR)) {
			if (!imeiamdevicepar.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2)) {
			if (!imeiavkeylistkey2.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSTRUCTURE)) {
			if (!imeimstructure.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMDevice::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMDevice::VecWIel::IREF;
		if (extractUbigintUclc(docctx, basexpath, "irefSupRefPlnrMDevice", "sup", irefSupRefPlnrMDevice)) ixWIelValid += ImeIMDevice::VecWIel::IREFSUPREFPLNRMDEVICE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMDevice::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMDevice::VecWIel::COMMENT;
		imeiamdevicepar.readXML(docctx, basexpath);
		imeiavkeylistkey2.readXML(docctx, basexpath);
		imeimstructure.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMDevice::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << irefSupRefPlnrMDevice << "\t" << sref << "\t" << Comment << endl;
	imeiamdevicepar.writeTxt(outfile);
	imeiavkeylistkey2.writeTxt(outfile);
	imeimstructure.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMDevice::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","sup","srf","cmt"};
	else tags = {"ImeitemIMDevice","iref","irefSupRefPlnrMDevice","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeUbigint(wr, tags[2], irefSupRefPlnrMDevice);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Comment);
		imeiamdevicepar.writeXML(wr, shorttags);
		imeiavkeylistkey2.writeXML(wr, shorttags);
		imeimstructure.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMDevice::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMDevice::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "irefSupRefPlnrMDevice") ix |= IREFSUPREFPLNRMDEVICE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIMDevice::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMDevice::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & IREFSUPREFPLNRMDEVICE) ss.push_back("irefSupRefPlnrMDevice");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMDevice
 ******************************************************************************/

IexPlnrIni::ImeIMDevice::ImeIMDevice() {
};

IexPlnrIni::ImeIMDevice::~ImeIMDevice() {
	clear();
};

void IexPlnrIni::ImeIMDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMDevice::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMDevice* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIMDevice();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMDevice::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMDevice* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMDevice");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMDevice", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMDevice";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMDevice();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMDevice::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMDevice." << StrMod::replaceChar(ImeIMDevice::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMDevice::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMDevice");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMFile
 ******************************************************************************/

IexPlnrIni::ImeitemIMFile::ImeitemIMFile(
			const ubigint iref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : PlnrMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIMFile::ImeitemIMFile(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMFile() {
	PlnrMFile* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMFile::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) osrefKContent = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Filename = txtrd.fields[2];
	if (txtrd.fields.size() > 3) srefKMimetype = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMFile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMFile::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile::VecWIel::COMMENT;
	};
};

void IexPlnrIni::ImeitemIMFile::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexPlnrIni::ImeitemIMFile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile","iref","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], osrefKContent);
		writeString(wr, tags[3], Filename);
		writeString(wr, tags[4], srefKMimetype);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMFile::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMFile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "osrefKContent") ix |= OSREFKCONTENT;
		else if (ss[i] == "Filename") ix |= FILENAME;
		else if (ss[i] == "srefKMimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIMFile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMFile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMFile
 ******************************************************************************/

IexPlnrIni::ImeIMFile::ImeIMFile() {
};

IexPlnrIni::ImeIMFile::~ImeIMFile() {
	clear();
};

void IexPlnrIni::ImeIMFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMFile::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMFile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIMFile();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMFile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMFile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMFile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile." << StrMod::replaceChar(ImeIMFile::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMFile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAMMaterialPar
 ******************************************************************************/

IexPlnrIni::ImeitemIAMMaterialPar::ImeitemIAMMaterialPar(
			const string& x2SrefKCat
			, const string& x3SrefKProp
			, const ubigint irefRefPlnrMFile
			, const string& Val
			, const string& Comment
		) : PlnrAMMaterialPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x2SrefKCat = x2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->irefRefPlnrMFile = irefRefPlnrMFile;
	this->Val = Val;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIAMMaterialPar::ImeitemIAMMaterialPar(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAMMaterialPar() {
	PlnrAMMaterialPar* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrammaterialpar->loadRecByRef(ref, &rec)) {
		refPlnrMMaterial = rec->refPlnrMMaterial;
		x2SrefKCat = rec->x2SrefKCat;
		x3SrefKProp = rec->x3SrefKProp;
		refPlnrMFile = rec->refPlnrMFile;
		Val = rec->Val;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAMMaterialPar::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x2SrefKCat = txtrd.fields[0];
	if (txtrd.fields.size() > 1) x3SrefKProp = txtrd.fields[1];
	if (txtrd.fields.size() > 2) irefRefPlnrMFile = atoll(txtrd.fields[2].c_str());
	if (txtrd.fields.size() > 3) Val = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Comment = txtrd.fields[4];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAMMaterialPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "x2SrefKCat", "cat", x2SrefKCat)) ixWIelValid += ImeIAMMaterialPar::VecWIel::X2SREFKCAT;
		if (extractStringUclc(docctx, basexpath, "x3SrefKProp", "prp", x3SrefKProp)) ixWIelValid += ImeIAMMaterialPar::VecWIel::X3SREFKPROP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefPlnrMFile", "fil", irefRefPlnrMFile)) ixWIelValid += ImeIAMMaterialPar::VecWIel::IREFREFPLNRMFILE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMMaterialPar::VecWIel::VAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMMaterialPar::VecWIel::COMMENT;
	};
};

void IexPlnrIni::ImeitemIAMMaterialPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x2SrefKCat << "\t" << x3SrefKProp << "\t" << irefRefPlnrMFile << "\t" << Val << "\t" << Comment << endl;
};

void IexPlnrIni::ImeitemIAMMaterialPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cat","prp","fil","val","cmt"};
	else tags = {"ImeitemIAMMaterialPar","x2SrefKCat","x3SrefKProp","irefRefPlnrMFile","Val","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x2SrefKCat);
		writeString(wr, tags[2], x3SrefKProp);
		writeUbigint(wr, tags[3], irefRefPlnrMFile);
		writeString(wr, tags[4], Val);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMMaterialPar::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAMMaterialPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "x2SrefKCat") ix |= X2SREFKCAT;
		else if (ss[i] == "x3SrefKProp") ix |= X3SREFKPROP;
		else if (ss[i] == "irefRefPlnrMFile") ix |= IREFREFPLNRMFILE;
		else if (ss[i] == "Val") ix |= VAL;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIAMMaterialPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAMMaterialPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X2SREFKCAT) ss.push_back("x2SrefKCat");
	if (ix & X3SREFKPROP) ss.push_back("x3SrefKProp");
	if (ix & IREFREFPLNRMFILE) ss.push_back("irefRefPlnrMFile");
	if (ix & VAL) ss.push_back("Val");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMMaterialPar
 ******************************************************************************/

IexPlnrIni::ImeIAMMaterialPar::ImeIAMMaterialPar() {
};

IexPlnrIni::ImeIAMMaterialPar::~ImeIAMMaterialPar() {
	clear();
};

void IexPlnrIni::ImeIAMMaterialPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAMMaterialPar::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAMMaterialPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIAMMaterialPar();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAMMaterialPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAMMaterialPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMaterialPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMaterialPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMaterialPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAMMaterialPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAMMaterialPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMMaterialPar." << StrMod::replaceChar(ImeIAMMaterialPar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAMMaterialPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMaterialPar");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMMaterial
 ******************************************************************************/

IexPlnrIni::ImeitemIMMaterial::ImeitemIMMaterial(
			const ubigint iref
			, const uint ixVBasetype
			, const ubigint irefModRefPlnrMMaterial
			, const string& sref
			, const string& Title
		) : PlnrMMaterial() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->ixVBasetype = ixVBasetype;
	this->irefModRefPlnrMMaterial = irefModRefPlnrMMaterial;
	this->sref = sref;
	this->Title = Title;
};

IexPlnrIni::ImeitemIMMaterial::ImeitemIMMaterial(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMMaterial() {
	PlnrMMaterial* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmmaterial->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		modRefPlnrMMaterial = rec->modRefPlnrMMaterial;
		sref = rec->sref;
		Title = rec->Title;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMMaterial::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) ixVBasetype = VecPlnrVMMaterialBasetype::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) irefModRefPlnrMMaterial = atoll(txtrd.fields[2].c_str());
	if (txtrd.fields.size() > 3) sref = txtrd.fields[3];
	if (txtrd.fields.size() > 4) Title = txtrd.fields[4];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMATERIALPAR)) {
			if (!imeiammaterialpar.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMMaterial::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVBasetype;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMMaterial::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) {
			ixVBasetype = VecPlnrVMMaterialBasetype::getIx(srefIxVBasetype);
			ixWIelValid += ImeIMMaterial::VecWIel::SREFIXVBASETYPE;
		};
		if (extractUbigintUclc(docctx, basexpath, "irefModRefPlnrMMaterial", "sup", irefModRefPlnrMMaterial)) ixWIelValid += ImeIMMaterial::VecWIel::IREFMODREFPLNRMMATERIAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMMaterial::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMMaterial::VecWIel::TITLE;
		imeiammaterialpar.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMMaterial::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << VecPlnrVMMaterialBasetype::getSref(ixVBasetype) << "\t" << irefModRefPlnrMMaterial << "\t" << sref << "\t" << Title << endl;
	imeiammaterialpar.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMMaterial::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","typ","sup","srf","tit"};
	else tags = {"ImeitemIMMaterial","iref","srefIxVBasetype","irefModRefPlnrMMaterial","sref","Title"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], VecPlnrVMMaterialBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[3], irefModRefPlnrMMaterial);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Title);
		imeiammaterialpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMMaterial::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMMaterial::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefIxVBasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefModRefPlnrMMaterial") ix |= IREFMODREFPLNRMMATERIAL;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Title") ix |= TITLE;
	};

	return(ix);
};

void IexPlnrIni::ImeIMMaterial::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*TITLE);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMMaterial::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFMODREFPLNRMMATERIAL) ss.push_back("irefModRefPlnrMMaterial");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMMaterial
 ******************************************************************************/

IexPlnrIni::ImeIMMaterial::ImeIMMaterial() {
};

IexPlnrIni::ImeIMMaterial::~ImeIMMaterial() {
	clear();
};

void IexPlnrIni::ImeIMMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMMaterial::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMMaterial* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIMMaterial();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMMaterial::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMMaterial* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMMaterial");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMMaterial", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMMaterial";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMMaterial();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMMaterial::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMMaterial." << StrMod::replaceChar(ImeIMMaterial::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMMaterial::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMMaterial");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexPlnrIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) : PlnrAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxPlnrVCard = x1IxPlnrVCard;
	this->ixPlnrWUiaccess = ixPlnrWUiaccess;
};

IexPlnrIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIAMUsergroupAccess() {
	PlnrAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnramusergroupaccess->loadRecByRef(ref, &rec)) {
		refPlnrMUsergroup = rec->refPlnrMUsergroup;
		x1IxPlnrVCard = rec->x1IxPlnrVCard;
		ixPlnrWUiaccess = rec->ixPlnrWUiaccess;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) x1IxPlnrVCard = VecPlnrVCard::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) ixPlnrWUiaccess = VecPlnrWUiaccess::getIx(txtrd.fields[1]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefX1IxPlnrVCard;
	string srefsIxPlnrWUiaccess;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxPlnrVCard", "crd", srefX1IxPlnrVCard)) {
			x1IxPlnrVCard = VecPlnrVCard::getIx(srefX1IxPlnrVCard);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXPLNRVCARD;
		};
		if (extractStringUclc(docctx, basexpath, "srefsIxPlnrWUiaccess", "uac", srefsIxPlnrWUiaccess)) {
			ixPlnrWUiaccess = VecPlnrWUiaccess::getIx(srefsIxPlnrWUiaccess);
			ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXPLNRWUIACCESS;
		};
	};
};

void IexPlnrIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecPlnrVCard::getSref(x1IxPlnrVCard) << "\t" << VecPlnrWUiaccess::getSrefs(ixPlnrWUiaccess) << endl;
};

void IexPlnrIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","crd","uac"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxPlnrVCard","srefsIxPlnrWUiaccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVCard::getSref(x1IxPlnrVCard));
		writeString(wr, tags[2], VecPlnrWUiaccess::getSrefs(ixPlnrWUiaccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefX1IxPlnrVCard") ix |= SREFX1IXPLNRVCARD;
		else if (ss[i] == "srefsIxPlnrWUiaccess") ix |= SREFSIXPLNRWUIACCESS;
	};

	return(ix);
};

void IexPlnrIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFSIXPLNRWUIACCESS);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXPLNRVCARD) ss.push_back("srefX1IxPlnrVCard");
	if (ix & SREFSIXPLNRWUIACCESS) ss.push_back("srefsIxPlnrWUiaccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexPlnrIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexPlnrIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexPlnrIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIAMUsergroupAccess();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIJMUserState
 ******************************************************************************/

IexPlnrIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : PlnrJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexPlnrIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIJMUserState() {
	PlnrJMUserState* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrjmuserstate->loadRecByRef(ref, &rec)) {
		refPlnrMUser = rec->refPlnrMUser;
		ixVState = rec->ixVState;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVState = VecPlnrVMUserState::getIx(txtrd.fields[0]);

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVState;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) {
			ixVState = VecPlnrVMUserState::getIx(srefIxVState);
			ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
		};
	};
};

void IexPlnrIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecPlnrVMUserState::getSref(ixVState) << endl;
};

void IexPlnrIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxVState") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexPlnrIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFIXVSTATE);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIJMUserState
 ******************************************************************************/

IexPlnrIni::ImeIJMUserState::ImeIJMUserState() {
};

IexPlnrIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexPlnrIni::ImeIJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexPlnrIni::ImeitemIJMUserState();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexPlnrIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : PlnrJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexPlnrIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIJMPersonLastname() {
	PlnrJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrjmpersonlastname->loadRecByRef(ref, &rec)) {
		refPlnrMPerson = rec->refPlnrMPerson;
		Lastname = rec->Lastname;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) Lastname = txtrd.fields[0];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexPlnrIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexPlnrIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "Lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexPlnrIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*LASTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIJMPersonLastname
 ******************************************************************************/

IexPlnrIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexPlnrIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexPlnrIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 3)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 3)) {
			ii = new IexPlnrIni::ImeitemIJMPersonLastname();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMPerson
 ******************************************************************************/

IexPlnrIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
		) : PlnrMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
};

IexPlnrIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMPerson() {
	PlnrMPerson* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixVSex = VecPlnrVMPersonSex::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) Title = txtrd.fields[1];
	if (txtrd.fields.size() > 2) Firstname = txtrd.fields[2];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
			if (!imeijmpersonlastname.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxVSex;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) {
			ixVSex = VecPlnrVMPersonSex::getIx(srefIxVSex);
			ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		};
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecPlnrVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecPlnrVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefIxVSex") ix |= SREFIXVSEX;
		else if (ss[i] == "Title") ix |= TITLE;
		else if (ss[i] == "Firstname") ix |= FIRSTNAME;
	};

	return(ix);
};

void IexPlnrIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*FIRSTNAME);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMPerson
 ******************************************************************************/

IexPlnrIni::ImeIMPerson::ImeIMPerson() {
};

IexPlnrIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexPlnrIni::ImeIMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 2)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 2)) {
			ii = new IexPlnrIni::ImeitemIMPerson();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMUser
 ******************************************************************************/

IexPlnrIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string& Password
		) : PlnrMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixPlnrVLocale = ixPlnrVLocale;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
	this->Password = Password;
};

IexPlnrIni::ImeitemIMUser::ImeitemIMUser(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMUser() {
	PlnrMUser* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refPlnrMPerson = rec->refPlnrMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixPlnrVLocale = rec->ixPlnrVLocale;
		ixPlnrVUserlevel = rec->ixPlnrVUserlevel;
		Password = rec->Password;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) ixPlnrVLocale = VecPlnrVLocale::getIx(txtrd.fields[1]);
	if (txtrd.fields.size() > 2) ixPlnrVUserlevel = VecPlnrVUserlevel::getIx(txtrd.fields[2]);
	if (txtrd.fields.size() > 3) Password = txtrd.fields[3];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
			if (!imeijmuserstate.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
			if (!imeimperson.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxPlnrVLocale;
	string srefIxPlnrVUserlevel;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxPlnrVLocale", "lcl", srefIxPlnrVLocale)) {
			ixPlnrVLocale = VecPlnrVLocale::getIx(srefIxPlnrVLocale);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXPLNRVLOCALE;
		};
		if (extractStringUclc(docctx, basexpath, "srefIxPlnrVUserlevel", "ulv", srefIxPlnrVUserlevel)) {
			ixPlnrVUserlevel = VecPlnrVUserlevel::getIx(srefIxPlnrVUserlevel);
			ixWIelValid += ImeIMUser::VecWIel::SREFIXPLNRVUSERLEVEL;
		};
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecPlnrVLocale::getSref(ixPlnrVLocale) << "\t" << VecPlnrVUserlevel::getSref(ixPlnrVUserlevel) << "\t" << Password << endl;
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","lcl","ulv","pwd"};
	else tags = {"ImeitemIMUser","sref","srefIxPlnrVLocale","srefIxPlnrVUserlevel","Password"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecPlnrVLocale::getSref(ixPlnrVLocale));
		writeString(wr, tags[3], VecPlnrVUserlevel::getSref(ixPlnrVUserlevel));
		writeString(wr, tags[4], Password);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefIxPlnrVLocale") ix |= SREFIXPLNRVLOCALE;
		else if (ss[i] == "srefIxPlnrVUserlevel") ix |= SREFIXPLNRVUSERLEVEL;
		else if (ss[i] == "Password") ix |= PASSWORD;
	};

	return(ix);
};

void IexPlnrIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*PASSWORD);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXPLNRVLOCALE) ss.push_back("srefIxPlnrVLocale");
	if (ix & SREFIXPLNRVUSERLEVEL) ss.push_back("srefIxPlnrVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMUser
 ******************************************************************************/

IexPlnrIni::ImeIMUser::ImeIMUser() {
};

IexPlnrIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexPlnrIni::ImeIMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexPlnrIni::ImeitemIMUser();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexPlnrIni::ImeitemIMUsergroup
 ******************************************************************************/

IexPlnrIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : PlnrMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexPlnrIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsPlnr* dbsplnr
			, const ubigint ref
		) : ImeitemIMUsergroup() {
	PlnrMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbsplnr->tblplnrmusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

bool IexPlnrIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) sref = txtrd.fields[0];
	if (txtrd.fields.size() > 1) Comment = txtrd.fields[1];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
			if (!imeiamusergroupaccess.readTxt(txtrd)) return false;

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
			if (!imeimuser.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexPlnrIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexPlnrIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexPlnrIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexPlnrIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "Comment") ix |= COMMENT;
	};

	return(ix);
};

void IexPlnrIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*COMMENT);i*=2) if (ix & i) ics.insert(i);
};

string IexPlnrIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexPlnrIni::ImeIMUsergroup
 ******************************************************************************/

IexPlnrIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexPlnrIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexPlnrIni::ImeIMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexPlnrIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexPlnrIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexPlnrIni::ImeitemIMUsergroup();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexPlnrIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexPlnrIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexPlnrIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexPlnrIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexPlnrIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};


