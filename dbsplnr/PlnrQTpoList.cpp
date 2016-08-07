/**
  * \file PlnrQTpoList.cpp
  * Dbs and XML wrapper for table TblPlnrQTpoList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoList.h"

/******************************************************************************
 class PlnrQTpoList
 ******************************************************************************/

PlnrQTpoList::PlnrQTpoList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const usmallint Major
			, const usmallint Sub
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const bool Hflip
			, const string yesnoHflip
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->Major = Major;
	this->Sub = Sub;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->Hflip = Hflip;
	this->yesnoHflip = yesnoHflip;
};

void PlnrQTpoList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQTpoList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeUint(wr, "maj", Major);
		writeUint(wr, "sub", Sub);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "fli", yesnoHflip);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeUint(wr, "Major", Major);
		writeUint(wr, "Sub", Sub);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "yesnoHflip", yesnoHflip);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQTpoList
 ******************************************************************************/

ListPlnrQTpoList::ListPlnrQTpoList() {
};

ListPlnrQTpoList::ListPlnrQTpoList(
			const ListPlnrQTpoList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoList(*(src.nodes[i]));
};

ListPlnrQTpoList::~ListPlnrQTpoList() {
	clear();
};

void ListPlnrQTpoList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQTpoList::size() const {
	return(nodes.size());
};

void ListPlnrQTpoList::append(
			PlnrQTpoList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQTpoList& ListPlnrQTpoList::operator=(
			const ListPlnrQTpoList& src
		) {
	PlnrQTpoList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQTpoList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQTpoList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQTpoList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQTpoList
 ******************************************************************************/

TblPlnrQTpoList::TblPlnrQTpoList() {
};

TblPlnrQTpoList::~TblPlnrQTpoList() {
};

bool TblPlnrQTpoList::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoList** rec
		) {
	return false;
};

ubigint TblPlnrQTpoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	return 0;
};

void TblPlnrQTpoList::insertRec(
			PlnrQTpoList* rec
		) {
};

ubigint TblPlnrQTpoList::insertNewRec(
			PlnrQTpoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const usmallint Major
			, const usmallint Sub
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const bool Hflip
			, const string yesnoHflip
		) {
	ubigint retval = 0;
	PlnrQTpoList* _rec = NULL;

	_rec = new PlnrQTpoList(0, jref, jnum, ref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, Major, Sub, ixVState, srefIxVState, titIxVState, Hflip, yesnoHflip);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQTpoList::appendNewRecToRst(
			ListPlnrQTpoList& rst
			, PlnrQTpoList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const usmallint Major
			, const usmallint Sub
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const bool Hflip
			, const string yesnoHflip
		) {
	ubigint retval = 0;
	PlnrQTpoList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, Major, Sub, ixVState, srefIxVState, titIxVState, Hflip, yesnoHflip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQTpoList::insertRst(
			ListPlnrQTpoList& rst
		) {
};

void TblPlnrQTpoList::updateRec(
			PlnrQTpoList* rec
		) {
};

void TblPlnrQTpoList::updateRst(
			ListPlnrQTpoList& rst
		) {
};

void TblPlnrQTpoList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQTpoList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQTpoList::loadRecByQref(
			ubigint qref
			, PlnrQTpoList** rec
		) {
	return false;
};

ubigint TblPlnrQTpoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQTpoList
 ******************************************************************************/

MyTblPlnrQTpoList::MyTblPlnrQTpoList() : TblPlnrQTpoList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQTpoList::~MyTblPlnrQTpoList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQTpoList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQTpoList (jref, jnum, ref, Title, ixVBasetype, Major, Sub, ixVState, Hflip) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQTpoList SET jref = ?, jnum = ?, ref = ?, Title = ?, ixVBasetype = ?, Major = ?, Sub = ?, ixVState = ?, Hflip = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQTpoList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQTpoList WHERE jref = ?", false);
};

bool MyTblPlnrQTpoList::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQTpoList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQTpoList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->Major = atoi((char*) dbrow[6]); else _rec->Major = 0;
		if (dbrow[7]) _rec->Sub = atoi((char*) dbrow[7]); else _rec->Sub = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->Hflip = (atoi((char*) dbrow[9]) != 0); else _rec->Hflip = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQTpoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQTpoList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQTpoList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->Major = atoi((char*) dbrow[6]); else rec->Major = 0;
			if (dbrow[7]) rec->Sub = atoi((char*) dbrow[7]); else rec->Sub = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->Hflip = (atoi((char*) dbrow[9]) != 0); else rec->Hflip = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQTpoList::insertRec(
			PlnrQTpoList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Title.length();
	tinyint Hflip = rec->Hflip;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Sub,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Hflip,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQTpoList::insertRst(
			ListPlnrQTpoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQTpoList::updateRec(
			PlnrQTpoList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Title.length();
	tinyint Hflip = rec->Hflip;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])), 
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])), 
		bindUsmallint(&rec->Sub,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindTinyint(&Hflip,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoList / stmtUpdateRec)\n");
};

void MyTblPlnrQTpoList::updateRst(
			ListPlnrQTpoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQTpoList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQTpoList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQTpoList::loadRecByQref(
			ubigint qref
			, PlnrQTpoList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQTpoList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQTpoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQTpoList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQTpoList
 ******************************************************************************/

PgTblPlnrQTpoList::PgTblPlnrQTpoList() : TblPlnrQTpoList(), PgTable() {
};

PgTblPlnrQTpoList::~PgTblPlnrQTpoList() {
};

void PgTblPlnrQTpoList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQTpoList_insertRec", "INSERT INTO TblPlnrQTpoList (jref, jnum, ref, Title, ixVBasetype, Major, Sub, ixVState, Hflip) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoList_updateRec", "UPDATE TblPlnrQTpoList SET jref = $1, jnum = $2, ref = $3, Title = $4, ixVBasetype = $5, Major = $6, Sub = $7, ixVState = $8, Hflip = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoList_removeRecByQref", "DELETE FROM TblPlnrQTpoList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoList_removeRstByJref", "DELETE FROM TblPlnrQTpoList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQTpoList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, ixVBasetype, Major, Sub, ixVState, Hflip FROM TblPlnrQTpoList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, ixVBasetype, Major, Sub, ixVState, Hflip FROM TblPlnrQTpoList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQTpoList::loadRec(
			PGresult* res
			, PlnrQTpoList** rec
		) {
	char* ptr;

	PlnrQTpoList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQTpoList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "hflip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Hflip = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQTpoList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQTpoList* rec;

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
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "hflip")
		};

		while (numread < numrow) {
			rec = new PlnrQTpoList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Hflip = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQTpoList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQTpoList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQTpoList::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQTpoList::insertRec(
			PlnrQTpoList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	uint _ixVState = htonl(rec->ixVState);
	smallint _Hflip = htons((smallint) rec->Hflip);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_Major,
		(char*) &_Sub,
		(char*) &_ixVState,
		(char*) &_Hflip
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQTpoList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQTpoList::insertRst(
			ListPlnrQTpoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQTpoList::updateRec(
			PlnrQTpoList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	uint _ixVState = htonl(rec->ixVState);
	smallint _Hflip = htons((smallint) rec->Hflip);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_Major,
		(char*) &_Sub,
		(char*) &_ixVState,
		(char*) &_Hflip,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQTpoList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQTpoList::updateRst(
			ListPlnrQTpoList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQTpoList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQTpoList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQTpoList::loadRecByQref(
			ubigint qref
			, PlnrQTpoList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQTpoList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQTpoList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQTpoList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

