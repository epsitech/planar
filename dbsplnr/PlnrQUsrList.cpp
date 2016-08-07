/**
  * \file PlnrQUsrList.cpp
  * Dbs and XML wrapper for table TblPlnrQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrList.h"

/******************************************************************************
 class PlnrQUsrList
 ******************************************************************************/

PlnrQUsrList::PlnrQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refPlnrMPerson
			, const string stubRefPlnrMPerson
			, const string sref
			, const ubigint refPlnrMUsergroup
			, const string stubRefPlnrMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixPlnrVLocale
			, const string srefIxPlnrVLocale
			, const string titIxPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refPlnrMPerson = refPlnrMPerson;
	this->stubRefPlnrMPerson = stubRefPlnrMPerson;
	this->sref = sref;
	this->refPlnrMUsergroup = refPlnrMUsergroup;
	this->stubRefPlnrMUsergroup = stubRefPlnrMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixPlnrVLocale = ixPlnrVLocale;
	this->srefIxPlnrVLocale = srefIxPlnrVLocale;
	this->titIxPlnrVLocale = titIxPlnrVLocale;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
	this->srefIxPlnrVUserlevel = srefIxPlnrVUserlevel;
	this->titIxPlnrVUserlevel = titIxPlnrVUserlevel;
};

void PlnrQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prs", stubRefPlnrMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefPlnrMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxPlnrVLocale);
		writeString(wr, "lcl2", titIxPlnrVLocale);
		writeString(wr, "ulv", srefIxPlnrVUserlevel);
		writeString(wr, "ulv2", titIxPlnrVUserlevel);
	} else {
		writeString(wr, "stubRefPlnrMPerson", stubRefPlnrMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefPlnrMUsergroup", stubRefPlnrMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxPlnrVLocale", srefIxPlnrVLocale);
		writeString(wr, "titIxPlnrVLocale", titIxPlnrVLocale);
		writeString(wr, "srefIxPlnrVUserlevel", srefIxPlnrVUserlevel);
		writeString(wr, "titIxPlnrVUserlevel", titIxPlnrVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQUsrList
 ******************************************************************************/

ListPlnrQUsrList::ListPlnrQUsrList() {
};

ListPlnrQUsrList::ListPlnrQUsrList(
			const ListPlnrQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrList(*(src.nodes[i]));
};

ListPlnrQUsrList::~ListPlnrQUsrList() {
	clear();
};

void ListPlnrQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsrList::size() const {
	return(nodes.size());
};

void ListPlnrQUsrList::append(
			PlnrQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsrList& ListPlnrQUsrList::operator=(
			const ListPlnrQUsrList& src
		) {
	PlnrQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsrList
 ******************************************************************************/

TblPlnrQUsrList::TblPlnrQUsrList() {
};

TblPlnrQUsrList::~TblPlnrQUsrList() {
};

bool TblPlnrQUsrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrList** rec
		) {
	return false;
};

ubigint TblPlnrQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	return 0;
};

void TblPlnrQUsrList::insertRec(
			PlnrQUsrList* rec
		) {
};

ubigint TblPlnrQUsrList::insertNewRec(
			PlnrQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refPlnrMPerson
			, const string stubRefPlnrMPerson
			, const string sref
			, const ubigint refPlnrMUsergroup
			, const string stubRefPlnrMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixPlnrVLocale
			, const string srefIxPlnrVLocale
			, const string titIxPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsrList* _rec = NULL;

	_rec = new PlnrQUsrList(0, jref, jnum, ref, refPlnrMPerson, stubRefPlnrMPerson, sref, refPlnrMUsergroup, stubRefPlnrMUsergroup, ixVState, srefIxVState, titIxVState, ixPlnrVLocale, srefIxPlnrVLocale, titIxPlnrVLocale, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsrList::appendNewRecToRst(
			ListPlnrQUsrList& rst
			, PlnrQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refPlnrMPerson
			, const string stubRefPlnrMPerson
			, const string sref
			, const ubigint refPlnrMUsergroup
			, const string stubRefPlnrMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixPlnrVLocale
			, const string srefIxPlnrVLocale
			, const string titIxPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refPlnrMPerson, stubRefPlnrMPerson, sref, refPlnrMUsergroup, stubRefPlnrMUsergroup, ixVState, srefIxVState, titIxVState, ixPlnrVLocale, srefIxPlnrVLocale, titIxPlnrVLocale, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsrList::insertRst(
			ListPlnrQUsrList& rst
		) {
};

void TblPlnrQUsrList::updateRec(
			PlnrQUsrList* rec
		) {
};

void TblPlnrQUsrList::updateRst(
			ListPlnrQUsrList& rst
		) {
};

void TblPlnrQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsrList::loadRecByQref(
			ubigint qref
			, PlnrQUsrList** rec
		) {
	return false;
};

ubigint TblPlnrQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsrList
 ******************************************************************************/

MyTblPlnrQUsrList::MyTblPlnrQUsrList() : TblPlnrQUsrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsrList::~MyTblPlnrQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsrList (jref, jnum, ref, refPlnrMPerson, sref, refPlnrMUsergroup, ixVState, ixPlnrVLocale, ixPlnrVUserlevel) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsrList SET jref = ?, jnum = ?, ref = ?, refPlnrMPerson = ?, sref = ?, refPlnrMUsergroup = ?, ixVState = ?, ixPlnrVLocale = ?, ixPlnrVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsrList WHERE jref = ?", false);
};

bool MyTblPlnrQUsrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refPlnrMPerson = atoll((char*) dbrow[4]); else _rec->refPlnrMPerson = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refPlnrMUsergroup = atoll((char*) dbrow[6]); else _rec->refPlnrMUsergroup = 0;
		if (dbrow[7]) _rec->ixVState = atol((char*) dbrow[7]); else _rec->ixVState = 0;
		if (dbrow[8]) _rec->ixPlnrVLocale = atol((char*) dbrow[8]); else _rec->ixPlnrVLocale = 0;
		if (dbrow[9]) _rec->ixPlnrVUserlevel = atol((char*) dbrow[9]); else _rec->ixPlnrVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refPlnrMPerson = atoll((char*) dbrow[4]); else rec->refPlnrMPerson = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refPlnrMUsergroup = atoll((char*) dbrow[6]); else rec->refPlnrMUsergroup = 0;
			if (dbrow[7]) rec->ixVState = atol((char*) dbrow[7]); else rec->ixVState = 0;
			if (dbrow[8]) rec->ixPlnrVLocale = atol((char*) dbrow[8]); else rec->ixPlnrVLocale = 0;
			if (dbrow[9]) rec->ixPlnrVUserlevel = atol((char*) dbrow[9]); else rec->ixPlnrVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQUsrList::insertRec(
			PlnrQUsrList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refPlnrMUsergroup,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixPlnrVLocale,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixPlnrVUserlevel,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsrList::insertRst(
			ListPlnrQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsrList::updateRec(
			PlnrQUsrList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMPerson,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refPlnrMUsergroup,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixPlnrVLocale,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixPlnrVUserlevel,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrList / stmtUpdateRec)\n");
};

void MyTblPlnrQUsrList::updateRst(
			ListPlnrQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsrList::loadRecByQref(
			ubigint qref
			, PlnrQUsrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsrList
 ******************************************************************************/

PgTblPlnrQUsrList::PgTblPlnrQUsrList() : TblPlnrQUsrList(), PgTable() {
};

PgTblPlnrQUsrList::~PgTblPlnrQUsrList() {
};

void PgTblPlnrQUsrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsrList_insertRec", "INSERT INTO TblPlnrQUsrList (jref, jnum, ref, refPlnrMPerson, sref, refPlnrMUsergroup, ixVState, ixPlnrVLocale, ixPlnrVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrList_updateRec", "UPDATE TblPlnrQUsrList SET jref = $1, jnum = $2, ref = $3, refPlnrMPerson = $4, sref = $5, refPlnrMUsergroup = $6, ixVState = $7, ixPlnrVLocale = $8, ixPlnrVUserlevel = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrList_removeRecByQref", "DELETE FROM TblPlnrQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrList_removeRstByJref", "DELETE FROM TblPlnrQUsrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, refPlnrMPerson, sref, refPlnrMUsergroup, ixVState, ixPlnrVLocale, ixPlnrVUserlevel FROM TblPlnrQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, refPlnrMPerson, sref, refPlnrMUsergroup, ixVState, ixPlnrVLocale, ixPlnrVUserlevel FROM TblPlnrQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsrList::loadRec(
			PGresult* res
			, PlnrQUsrList** rec
		) {
	char* ptr;

	PlnrQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixplnrvlocale"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refPlnrMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixPlnrVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixPlnrVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixplnrvlocale"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		while (numread < numrow) {
			rec = new PlnrQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refPlnrMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixPlnrVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixPlnrVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsrList::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsrList::insertRec(
			PlnrQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixPlnrVLocale = htonl(rec->ixPlnrVLocale);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refPlnrMPerson,
		rec->sref.c_str(),
		(char*) &_refPlnrMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixPlnrVLocale,
		(char*) &_ixPlnrVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsrList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsrList::insertRst(
			ListPlnrQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsrList::updateRec(
			PlnrQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixPlnrVLocale = htonl(rec->ixPlnrVLocale);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refPlnrMPerson,
		rec->sref.c_str(),
		(char*) &_refPlnrMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixPlnrVLocale,
		(char*) &_ixPlnrVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsrList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsrList::updateRst(
			ListPlnrQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsrList::loadRecByQref(
			ubigint qref
			, PlnrQUsrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

