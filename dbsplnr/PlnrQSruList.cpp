/**
  * \file PlnrQSruList.cpp
  * Dbs and XML wrapper for table TblPlnrQSruList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruList.h"

/******************************************************************************
 class PlnrQSruList
 ******************************************************************************/

PlnrQSruList::PlnrQSruList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
};

void PlnrQSruList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQSruList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQSruList
 ******************************************************************************/

ListPlnrQSruList::ListPlnrQSruList() {
};

ListPlnrQSruList::ListPlnrQSruList(
			const ListPlnrQSruList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruList(*(src.nodes[i]));
};

ListPlnrQSruList::~ListPlnrQSruList() {
	clear();
};

void ListPlnrQSruList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQSruList::size() const {
	return(nodes.size());
};

void ListPlnrQSruList::append(
			PlnrQSruList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQSruList& ListPlnrQSruList::operator=(
			const ListPlnrQSruList& src
		) {
	PlnrQSruList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQSruList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQSruList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQSruList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQSruList
 ******************************************************************************/

TblPlnrQSruList::TblPlnrQSruList() {
};

TblPlnrQSruList::~TblPlnrQSruList() {
};

bool TblPlnrQSruList::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruList** rec
		) {
	return false;
};

ubigint TblPlnrQSruList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruList& rst
		) {
	return 0;
};

void TblPlnrQSruList::insertRec(
			PlnrQSruList* rec
		) {
};

ubigint TblPlnrQSruList::insertNewRec(
			PlnrQSruList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
		) {
	ubigint retval = 0;
	PlnrQSruList* _rec = NULL;

	_rec = new PlnrQSruList(0, jref, jnum, ref, sref, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQSruList::appendNewRecToRst(
			ListPlnrQSruList& rst
			, PlnrQSruList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
		) {
	ubigint retval = 0;
	PlnrQSruList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQSruList::insertRst(
			ListPlnrQSruList& rst
		) {
};

void TblPlnrQSruList::updateRec(
			PlnrQSruList* rec
		) {
};

void TblPlnrQSruList::updateRst(
			ListPlnrQSruList& rst
		) {
};

void TblPlnrQSruList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQSruList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQSruList::loadRecByQref(
			ubigint qref
			, PlnrQSruList** rec
		) {
	return false;
};

ubigint TblPlnrQSruList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQSruList
 ******************************************************************************/

MyTblPlnrQSruList::MyTblPlnrQSruList() : TblPlnrQSruList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQSruList::~MyTblPlnrQSruList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQSruList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQSruList (jref, jnum, ref, sref, hkIxVTbl, hkUref) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQSruList SET jref = ?, jnum = ?, ref = ?, sref = ?, hkIxVTbl = ?, hkUref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQSruList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQSruList WHERE jref = ?", false);
};

bool MyTblPlnrQSruList::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQSruList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQSruList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQSruList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->hkIxVTbl = atol((char*) dbrow[5]); else _rec->hkIxVTbl = 0;
		if (dbrow[6]) _rec->hkUref = atoll((char*) dbrow[6]); else _rec->hkUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQSruList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQSruList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQSruList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQSruList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->hkIxVTbl = atol((char*) dbrow[5]); else rec->hkIxVTbl = 0;
			if (dbrow[6]) rec->hkUref = atoll((char*) dbrow[6]); else rec->hkUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQSruList::insertRec(
			PlnrQSruList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->hkIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->hkUref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQSruList::insertRst(
			ListPlnrQSruList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQSruList::updateRec(
			PlnrQSruList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->hkIxVTbl,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->hkUref,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruList / stmtUpdateRec)\n");
};

void MyTblPlnrQSruList::updateRst(
			ListPlnrQSruList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQSruList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQSruList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQSruList::loadRecByQref(
			ubigint qref
			, PlnrQSruList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQSruList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQSruList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQSruList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQSruList
 ******************************************************************************/

PgTblPlnrQSruList::PgTblPlnrQSruList() : TblPlnrQSruList(), PgTable() {
};

PgTblPlnrQSruList::~PgTblPlnrQSruList() {
};

void PgTblPlnrQSruList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQSruList_insertRec", "INSERT INTO TblPlnrQSruList (jref, jnum, ref, sref, hkIxVTbl, hkUref) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruList_updateRec", "UPDATE TblPlnrQSruList SET jref = $1, jnum = $2, ref = $3, sref = $4, hkIxVTbl = $5, hkUref = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruList_removeRecByQref", "DELETE FROM TblPlnrQSruList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruList_removeRstByJref", "DELETE FROM TblPlnrQSruList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQSruList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, hkIxVTbl, hkUref FROM TblPlnrQSruList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, hkIxVTbl, hkUref FROM TblPlnrQSruList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQSruList::loadRec(
			PGresult* res
			, PlnrQSruList** rec
		) {
	char* ptr;

	PlnrQSruList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQSruList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->hkUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQSruList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQSruList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQSruList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref")
		};

		while (numread < numrow) {
			rec = new PlnrQSruList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->hkUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQSruList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQSruList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQSruList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQSruList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQSruList::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQSruList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQSruList::insertRec(
			PlnrQSruList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQSruList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQSruList::insertRst(
			ListPlnrQSruList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQSruList::updateRec(
			PlnrQSruList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQSruList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQSruList::updateRst(
			ListPlnrQSruList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQSruList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQSruList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQSruList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQSruList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQSruList::loadRecByQref(
			ubigint qref
			, PlnrQSruList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQSruList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQSruList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQSruList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

