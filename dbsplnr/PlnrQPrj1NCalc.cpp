/**
  * \file PlnrQPrj1NCalc.cpp
  * Dbs and XML wrapper for table TblPlnrQPrj1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQPrj1NCalc.h"

/******************************************************************************
 class PlnrQPrj1NCalc
 ******************************************************************************/

PlnrQPrj1NCalc::PlnrQPrj1NCalc(
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

void PlnrQPrj1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQPrj1NCalc";

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
 class ListPlnrQPrj1NCalc
 ******************************************************************************/

ListPlnrQPrj1NCalc::ListPlnrQPrj1NCalc() {
};

ListPlnrQPrj1NCalc::ListPlnrQPrj1NCalc(
			const ListPlnrQPrj1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQPrj1NCalc(*(src.nodes[i]));
};

ListPlnrQPrj1NCalc::~ListPlnrQPrj1NCalc() {
	clear();
};

void ListPlnrQPrj1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQPrj1NCalc::size() const {
	return(nodes.size());
};

void ListPlnrQPrj1NCalc::append(
			PlnrQPrj1NCalc* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQPrj1NCalc& ListPlnrQPrj1NCalc::operator=(
			const ListPlnrQPrj1NCalc& src
		) {
	PlnrQPrj1NCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQPrj1NCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQPrj1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQPrj1NCalc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQPrj1NCalc
 ******************************************************************************/

TblPlnrQPrj1NCalc::TblPlnrQPrj1NCalc() {
};

TblPlnrQPrj1NCalc::~TblPlnrQPrj1NCalc() {
};

bool TblPlnrQPrj1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrj1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQPrj1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	return 0;
};

void TblPlnrQPrj1NCalc::insertRec(
			PlnrQPrj1NCalc* rec
		) {
};

ubigint TblPlnrQPrj1NCalc::insertNewRec(
			PlnrQPrj1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQPrj1NCalc* _rec = NULL;

	_rec = new PlnrQPrj1NCalc(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQPrj1NCalc::appendNewRecToRst(
			ListPlnrQPrj1NCalc& rst
			, PlnrQPrj1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQPrj1NCalc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQPrj1NCalc::insertRst(
			ListPlnrQPrj1NCalc& rst
		) {
};

void TblPlnrQPrj1NCalc::updateRec(
			PlnrQPrj1NCalc* rec
		) {
};

void TblPlnrQPrj1NCalc::updateRst(
			ListPlnrQPrj1NCalc& rst
		) {
};

void TblPlnrQPrj1NCalc::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQPrj1NCalc::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQPrj1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQPrj1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQPrj1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQPrj1NCalc
 ******************************************************************************/

MyTblPlnrQPrj1NCalc::MyTblPlnrQPrj1NCalc() : TblPlnrQPrj1NCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQPrj1NCalc::~MyTblPlnrQPrj1NCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQPrj1NCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQPrj1NCalc (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQPrj1NCalc SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQPrj1NCalc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQPrj1NCalc WHERE jref = ?", false);
};

bool MyTblPlnrQPrj1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrj1NCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQPrj1NCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrj1NCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQPrj1NCalc();

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

ubigint MyTblPlnrQPrj1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQPrj1NCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQPrj1NCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQPrj1NCalc();

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

void MyTblPlnrQPrj1NCalc::insertRec(
			PlnrQPrj1NCalc* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrj1NCalc / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrj1NCalc / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQPrj1NCalc::insertRst(
			ListPlnrQPrj1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQPrj1NCalc::updateRec(
			PlnrQPrj1NCalc* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrj1NCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrj1NCalc / stmtUpdateRec)\n");
};

void MyTblPlnrQPrj1NCalc::updateRst(
			ListPlnrQPrj1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQPrj1NCalc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrj1NCalc / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrj1NCalc / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQPrj1NCalc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQPrj1NCalc / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQPrj1NCalc / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQPrj1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQPrj1NCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQPrj1NCalc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQPrj1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQPrj1NCalc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQPrj1NCalc
 ******************************************************************************/

PgTblPlnrQPrj1NCalc::PgTblPlnrQPrj1NCalc() : TblPlnrQPrj1NCalc(), PgTable() {
};

PgTblPlnrQPrj1NCalc::~PgTblPlnrQPrj1NCalc() {
};

void PgTblPlnrQPrj1NCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_insertRec", "INSERT INTO TblPlnrQPrj1NCalc (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_updateRec", "UPDATE TblPlnrQPrj1NCalc SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_removeRecByQref", "DELETE FROM TblPlnrQPrj1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_removeRstByJref", "DELETE FROM TblPlnrQPrj1NCalc WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQPrj1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQPrj1NCalc_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQPrj1NCalc WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQPrj1NCalc::loadRec(
			PGresult* res
			, PlnrQPrj1NCalc** rec
		) {
	char* ptr;

	PlnrQPrj1NCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQPrj1NCalc();

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

ubigint PgTblPlnrQPrj1NCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQPrj1NCalc* rec;

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
			rec = new PlnrQPrj1NCalc();

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

bool PgTblPlnrQPrj1NCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQPrj1NCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrj1NCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQPrj1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQPrj1NCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQPrj1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQPrj1NCalc::insertRec(
			PlnrQPrj1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQPrj1NCalc_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQPrj1NCalc::insertRst(
			ListPlnrQPrj1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQPrj1NCalc::updateRec(
			PlnrQPrj1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQPrj1NCalc_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQPrj1NCalc::updateRst(
			ListPlnrQPrj1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQPrj1NCalc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrj1NCalc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQPrj1NCalc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQPrj1NCalc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQPrj1NCalc_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQPrj1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQPrj1NCalc** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQPrj1NCalc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQPrj1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQPrj1NCalc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQPrj1NCalc_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

