/**
  * \file PlnrQUsr1NSession.cpp
  * Dbs and XML wrapper for table TblPlnrQUsr1NSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsr1NSession.h"

/******************************************************************************
 class PlnrQUsr1NSession
 ******************************************************************************/

PlnrQUsr1NSession::PlnrQUsr1NSession(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void PlnrQUsr1NSession::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsr1NSession";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQUsr1NSession
 ******************************************************************************/

ListPlnrQUsr1NSession::ListPlnrQUsr1NSession() {
};

ListPlnrQUsr1NSession::ListPlnrQUsr1NSession(
			const ListPlnrQUsr1NSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsr1NSession(*(src.nodes[i]));
};

ListPlnrQUsr1NSession::~ListPlnrQUsr1NSession() {
	clear();
};

void ListPlnrQUsr1NSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsr1NSession::size() const {
	return(nodes.size());
};

void ListPlnrQUsr1NSession::append(
			PlnrQUsr1NSession* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsr1NSession& ListPlnrQUsr1NSession::operator=(
			const ListPlnrQUsr1NSession& src
		) {
	PlnrQUsr1NSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsr1NSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsr1NSession::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsr1NSession";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsr1NSession
 ******************************************************************************/

TblPlnrQUsr1NSession::TblPlnrQUsr1NSession() {
};

TblPlnrQUsr1NSession::~TblPlnrQUsr1NSession() {
};

bool TblPlnrQUsr1NSession::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsr1NSession** rec
		) {
	return false;
};

ubigint TblPlnrQUsr1NSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	return 0;
};

void TblPlnrQUsr1NSession::insertRec(
			PlnrQUsr1NSession* rec
		) {
};

ubigint TblPlnrQUsr1NSession::insertNewRec(
			PlnrQUsr1NSession** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQUsr1NSession* _rec = NULL;

	_rec = new PlnrQUsr1NSession(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsr1NSession::appendNewRecToRst(
			ListPlnrQUsr1NSession& rst
			, PlnrQUsr1NSession** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQUsr1NSession* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsr1NSession::insertRst(
			ListPlnrQUsr1NSession& rst
		) {
};

void TblPlnrQUsr1NSession::updateRec(
			PlnrQUsr1NSession* rec
		) {
};

void TblPlnrQUsr1NSession::updateRst(
			ListPlnrQUsr1NSession& rst
		) {
};

void TblPlnrQUsr1NSession::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsr1NSession::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsr1NSession::loadRecByQref(
			ubigint qref
			, PlnrQUsr1NSession** rec
		) {
	return false;
};

ubigint TblPlnrQUsr1NSession::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsr1NSession
 ******************************************************************************/

MyTblPlnrQUsr1NSession::MyTblPlnrQUsr1NSession() : TblPlnrQUsr1NSession(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsr1NSession::~MyTblPlnrQUsr1NSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsr1NSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsr1NSession (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsr1NSession SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsr1NSession WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsr1NSession WHERE jref = ?", false);
};

bool MyTblPlnrQUsr1NSession::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsr1NSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsr1NSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsr1NSession / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsr1NSession();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQUsr1NSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsr1NSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsr1NSession / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsr1NSession();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQUsr1NSession::insertRec(
			PlnrQUsr1NSession* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsr1NSession / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsr1NSession / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsr1NSession::insertRst(
			ListPlnrQUsr1NSession& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsr1NSession::updateRec(
			PlnrQUsr1NSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsr1NSession / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsr1NSession / stmtUpdateRec)\n");
};

void MyTblPlnrQUsr1NSession::updateRst(
			ListPlnrQUsr1NSession& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsr1NSession::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsr1NSession / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsr1NSession / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsr1NSession::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsr1NSession / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsr1NSession / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsr1NSession::loadRecByQref(
			ubigint qref
			, PlnrQUsr1NSession** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsr1NSession WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsr1NSession::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsr1NSession WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsr1NSession
 ******************************************************************************/

PgTblPlnrQUsr1NSession::PgTblPlnrQUsr1NSession() : TblPlnrQUsr1NSession(), PgTable() {
};

PgTblPlnrQUsr1NSession::~PgTblPlnrQUsr1NSession() {
};

void PgTblPlnrQUsr1NSession::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsr1NSession_insertRec", "INSERT INTO TblPlnrQUsr1NSession (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsr1NSession_updateRec", "UPDATE TblPlnrQUsr1NSession SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsr1NSession_removeRecByQref", "DELETE FROM TblPlnrQUsr1NSession WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsr1NSession_removeRstByJref", "DELETE FROM TblPlnrQUsr1NSession WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsr1NSession_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQUsr1NSession WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsr1NSession_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQUsr1NSession WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsr1NSession::loadRec(
			PGresult* res
			, PlnrQUsr1NSession** rec
		) {
	char* ptr;

	PlnrQUsr1NSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsr1NSession();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQUsr1NSession::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsr1NSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQUsr1NSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQUsr1NSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsr1NSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsr1NSession::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsr1NSession::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsr1NSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsr1NSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsr1NSession::insertRec(
			PlnrQUsr1NSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsr1NSession_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsr1NSession::insertRst(
			ListPlnrQUsr1NSession& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsr1NSession::updateRec(
			PlnrQUsr1NSession* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsr1NSession_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsr1NSession::updateRst(
			ListPlnrQUsr1NSession& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsr1NSession::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsr1NSession_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsr1NSession::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsr1NSession_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsr1NSession_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsr1NSession::loadRecByQref(
			ubigint qref
			, PlnrQUsr1NSession** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsr1NSession_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsr1NSession::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsr1NSession& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsr1NSession_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

