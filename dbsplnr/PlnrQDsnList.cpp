/**
  * \file PlnrQDsnList.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnList.h"

/******************************************************************************
 class PlnrQDsnList
 ******************************************************************************/

PlnrQDsnList::PlnrQDsnList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixWModtype
			, const string srefsIxWModtype
			, const string titsIxWModtype
			, const ubigint modRefPlnrMDesign
			, const string stubModRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string stubDrvRefPlnrMDesign
			, const usmallint Major
			, const usmallint Sub
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->ixVDim = ixVDim;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->refPlnrMProject = refPlnrMProject;
	this->stubRefPlnrMProject = stubRefPlnrMProject;
	this->ixWModtype = ixWModtype;
	this->srefsIxWModtype = srefsIxWModtype;
	this->titsIxWModtype = titsIxWModtype;
	this->modRefPlnrMDesign = modRefPlnrMDesign;
	this->stubModRefPlnrMDesign = stubModRefPlnrMDesign;
	this->drvRefPlnrMDesign = drvRefPlnrMDesign;
	this->stubDrvRefPlnrMDesign = stubDrvRefPlnrMDesign;
	this->Major = Major;
	this->Sub = Sub;
};

void PlnrQDsnList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "dim", srefIxVDim);
		writeString(wr, "dim2", titIxVDim);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "prj", stubRefPlnrMProject);
		writeString(wr, "mty", srefsIxWModtype);
		writeString(wr, "mty2", titsIxWModtype);
		writeString(wr, "mod", stubModRefPlnrMDesign);
		writeString(wr, "drv", stubDrvRefPlnrMDesign);
		writeUint(wr, "maj", Major);
		writeUint(wr, "sub", Sub);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefIxVDim", srefIxVDim);
		writeString(wr, "titIxVDim", titIxVDim);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "stubRefPlnrMProject", stubRefPlnrMProject);
		writeString(wr, "srefsIxWModtype", srefsIxWModtype);
		writeString(wr, "titsIxWModtype", titsIxWModtype);
		writeString(wr, "stubModRefPlnrMDesign", stubModRefPlnrMDesign);
		writeString(wr, "stubDrvRefPlnrMDesign", stubDrvRefPlnrMDesign);
		writeUint(wr, "Major", Major);
		writeUint(wr, "Sub", Sub);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDsnList
 ******************************************************************************/

ListPlnrQDsnList::ListPlnrQDsnList() {
};

ListPlnrQDsnList::ListPlnrQDsnList(
			const ListPlnrQDsnList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnList(*(src.nodes[i]));
};

ListPlnrQDsnList::~ListPlnrQDsnList() {
	clear();
};

void ListPlnrQDsnList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnList::size() const {
	return(nodes.size());
};

void ListPlnrQDsnList::append(
			PlnrQDsnList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnList& ListPlnrQDsnList::operator=(
			const ListPlnrQDsnList& src
		) {
	PlnrQDsnList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnList
 ******************************************************************************/

TblPlnrQDsnList::TblPlnrQDsnList() {
};

TblPlnrQDsnList::~TblPlnrQDsnList() {
};

bool TblPlnrQDsnList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnList** rec
		) {
	return false;
};

ubigint TblPlnrQDsnList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	return 0;
};

void TblPlnrQDsnList::insertRec(
			PlnrQDsnList* rec
		) {
};

ubigint TblPlnrQDsnList::insertNewRec(
			PlnrQDsnList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixWModtype
			, const string srefsIxWModtype
			, const string titsIxWModtype
			, const ubigint modRefPlnrMDesign
			, const string stubModRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string stubDrvRefPlnrMDesign
			, const usmallint Major
			, const usmallint Sub
		) {
	ubigint retval = 0;
	PlnrQDsnList* _rec = NULL;

	_rec = new PlnrQDsnList(0, jref, jnum, ref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, ixVDim, srefIxVDim, titIxVDim, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, refPlnrMProject, stubRefPlnrMProject, ixWModtype, srefsIxWModtype, titsIxWModtype, modRefPlnrMDesign, stubModRefPlnrMDesign, drvRefPlnrMDesign, stubDrvRefPlnrMDesign, Major, Sub);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnList::appendNewRecToRst(
			ListPlnrQDsnList& rst
			, PlnrQDsnList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refPlnrMProject
			, const string stubRefPlnrMProject
			, const uint ixWModtype
			, const string srefsIxWModtype
			, const string titsIxWModtype
			, const ubigint modRefPlnrMDesign
			, const string stubModRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string stubDrvRefPlnrMDesign
			, const usmallint Major
			, const usmallint Sub
		) {
	ubigint retval = 0;
	PlnrQDsnList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, ixVDim, srefIxVDim, titIxVDim, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, refPlnrMProject, stubRefPlnrMProject, ixWModtype, srefsIxWModtype, titsIxWModtype, modRefPlnrMDesign, stubModRefPlnrMDesign, drvRefPlnrMDesign, stubDrvRefPlnrMDesign, Major, Sub);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnList::insertRst(
			ListPlnrQDsnList& rst
		) {
};

void TblPlnrQDsnList::updateRec(
			PlnrQDsnList* rec
		) {
};

void TblPlnrQDsnList::updateRst(
			ListPlnrQDsnList& rst
		) {
};

void TblPlnrQDsnList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnList::loadRecByQref(
			ubigint qref
			, PlnrQDsnList** rec
		) {
	return false;
};

ubigint TblPlnrQDsnList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnList
 ******************************************************************************/

MyTblPlnrQDsnList::MyTblPlnrQDsnList() : TblPlnrQDsnList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnList::~MyTblPlnrQDsnList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnList (jref, jnum, ref, Title, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Major, Sub) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnList SET jref = ?, jnum = ?, ref = ?, Title = ?, ixVBasetype = ?, ixVDim = ?, refIxVTbl = ?, refUref = ?, refPlnrMProject = ?, ixWModtype = ?, modRefPlnrMDesign = ?, drvRefPlnrMDesign = ?, Major = ?, Sub = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnList WHERE jref = ?", false);
};

bool MyTblPlnrQDsnList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->ixVDim = atol((char*) dbrow[6]); else _rec->ixVDim = 0;
		if (dbrow[7]) _rec->refIxVTbl = atol((char*) dbrow[7]); else _rec->refIxVTbl = 0;
		if (dbrow[8]) _rec->refUref = atoll((char*) dbrow[8]); else _rec->refUref = 0;
		if (dbrow[9]) _rec->refPlnrMProject = atoll((char*) dbrow[9]); else _rec->refPlnrMProject = 0;
		if (dbrow[10]) _rec->ixWModtype = atol((char*) dbrow[10]); else _rec->ixWModtype = 0;
		if (dbrow[11]) _rec->modRefPlnrMDesign = atoll((char*) dbrow[11]); else _rec->modRefPlnrMDesign = 0;
		if (dbrow[12]) _rec->drvRefPlnrMDesign = atoll((char*) dbrow[12]); else _rec->drvRefPlnrMDesign = 0;
		if (dbrow[13]) _rec->Major = atoi((char*) dbrow[13]); else _rec->Major = 0;
		if (dbrow[14]) _rec->Sub = atoi((char*) dbrow[14]); else _rec->Sub = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDsnList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->ixVDim = atol((char*) dbrow[6]); else rec->ixVDim = 0;
			if (dbrow[7]) rec->refIxVTbl = atol((char*) dbrow[7]); else rec->refIxVTbl = 0;
			if (dbrow[8]) rec->refUref = atoll((char*) dbrow[8]); else rec->refUref = 0;
			if (dbrow[9]) rec->refPlnrMProject = atoll((char*) dbrow[9]); else rec->refPlnrMProject = 0;
			if (dbrow[10]) rec->ixWModtype = atol((char*) dbrow[10]); else rec->ixWModtype = 0;
			if (dbrow[11]) rec->modRefPlnrMDesign = atoll((char*) dbrow[11]); else rec->modRefPlnrMDesign = 0;
			if (dbrow[12]) rec->drvRefPlnrMDesign = atoll((char*) dbrow[12]); else rec->drvRefPlnrMDesign = 0;
			if (dbrow[13]) rec->Major = atoi((char*) dbrow[13]); else rec->Major = 0;
			if (dbrow[14]) rec->Sub = atoi((char*) dbrow[14]); else rec->Sub = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDsnList::insertRec(
			PlnrQDsnList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVDim,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refPlnrMProject,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWModtype,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->modRefPlnrMDesign,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->drvRefPlnrMDesign,&(l[11]),&(n[11]),&(e[11])),
		bindUsmallint(&rec->Major,&(l[12]),&(n[12]),&(e[12])),
		bindUsmallint(&rec->Sub,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnList::insertRst(
			ListPlnrQDsnList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnList::updateRec(
			PlnrQDsnList* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVDim,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->refIxVTbl,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->refUref,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refPlnrMProject,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->ixWModtype,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->modRefPlnrMDesign,&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->drvRefPlnrMDesign,&(l[11]),&(n[11]),&(e[11])), 
		bindUsmallint(&rec->Major,&(l[12]),&(n[12]),&(e[12])), 
		bindUsmallint(&rec->Sub,&(l[13]),&(n[13]),&(e[13])), 
		bindUbigint(&rec->qref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnList / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnList::updateRst(
			ListPlnrQDsnList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnList::loadRecByQref(
			ubigint qref
			, PlnrQDsnList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnList
 ******************************************************************************/

PgTblPlnrQDsnList::PgTblPlnrQDsnList() : TblPlnrQDsnList(), PgTable() {
};

PgTblPlnrQDsnList::~PgTblPlnrQDsnList() {
};

void PgTblPlnrQDsnList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnList_insertRec", "INSERT INTO TblPlnrQDsnList (jref, jnum, ref, Title, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Major, Sub) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING qref", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnList_updateRec", "UPDATE TblPlnrQDsnList SET jref = $1, jnum = $2, ref = $3, Title = $4, ixVBasetype = $5, ixVDim = $6, refIxVTbl = $7, refUref = $8, refPlnrMProject = $9, ixWModtype = $10, modRefPlnrMDesign = $11, drvRefPlnrMDesign = $12, Major = $13, Sub = $14 WHERE qref = $15", 15, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnList_removeRecByQref", "DELETE FROM TblPlnrQDsnList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnList_removeRstByJref", "DELETE FROM TblPlnrQDsnList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Major, Sub FROM TblPlnrQDsnList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Major, Sub FROM TblPlnrQDsnList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnList::loadRec(
			PGresult* res
			, PlnrQDsnList** rec
		) {
	char* ptr;

	PlnrQDsnList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixwmodtype"),
			PQfnumber(res, "modrefplnrmdesign"),
			PQfnumber(res, "drvrefplnrmdesign"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVDim = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->modRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->drvRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Sub = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDsnList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixwmodtype"),
			PQfnumber(res, "modrefplnrmdesign"),
			PQfnumber(res, "drvrefplnrmdesign"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub")
		};

		while (numread < numrow) {
			rec = new PlnrQDsnList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVDim = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->modRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->drvRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Sub = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDsnList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnList::insertRec(
			PlnrQDsnList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixVDim = htonl(rec->ixVDim);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixWModtype = htonl(rec->ixWModtype);
	ubigint _modRefPlnrMDesign = htonl64(rec->modRefPlnrMDesign);
	ubigint _drvRefPlnrMDesign = htonl64(rec->drvRefPlnrMDesign);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_ixVDim,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refPlnrMProject,
		(char*) &_ixWModtype,
		(char*) &_modRefPlnrMDesign,
		(char*) &_drvRefPlnrMDesign,
		(char*) &_Major,
		(char*) &_Sub
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnList_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnList::insertRst(
			ListPlnrQDsnList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnList::updateRec(
			PlnrQDsnList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixVDim = htonl(rec->ixVDim);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixWModtype = htonl(rec->ixWModtype);
	ubigint _modRefPlnrMDesign = htonl64(rec->modRefPlnrMDesign);
	ubigint _drvRefPlnrMDesign = htonl64(rec->drvRefPlnrMDesign);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_ixVDim,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refPlnrMProject,
		(char*) &_ixWModtype,
		(char*) &_modRefPlnrMDesign,
		(char*) &_drvRefPlnrMDesign,
		(char*) &_Major,
		(char*) &_Sub,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnList_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnList::updateRst(
			ListPlnrQDsnList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnList::loadRecByQref(
			ubigint qref
			, PlnrQDsnList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

