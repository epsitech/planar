/**
  * \file PlnrQCtpSup1NCalc.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpSup1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpSup1NCalc.h"

/******************************************************************************
 class PlnrQCtpSup1NCalc
 ******************************************************************************/

PlnrQCtpSup1NCalc::PlnrQCtpSup1NCalc(
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

void PlnrQCtpSup1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpSup1NCalc";

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
 class ListPlnrQCtpSup1NCalc
 ******************************************************************************/

ListPlnrQCtpSup1NCalc::ListPlnrQCtpSup1NCalc() {
};

ListPlnrQCtpSup1NCalc::ListPlnrQCtpSup1NCalc(
			const ListPlnrQCtpSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpSup1NCalc(*(src.nodes[i]));
};

ListPlnrQCtpSup1NCalc::~ListPlnrQCtpSup1NCalc() {
	clear();
};

void ListPlnrQCtpSup1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpSup1NCalc::size() const {
	return(nodes.size());
};

void ListPlnrQCtpSup1NCalc::append(
			PlnrQCtpSup1NCalc* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpSup1NCalc& ListPlnrQCtpSup1NCalc::operator=(
			const ListPlnrQCtpSup1NCalc& src
		) {
	PlnrQCtpSup1NCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpSup1NCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpSup1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpSup1NCalc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpSup1NCalc
 ******************************************************************************/

TblPlnrQCtpSup1NCalc::TblPlnrQCtpSup1NCalc() {
};

TblPlnrQCtpSup1NCalc::~TblPlnrQCtpSup1NCalc() {
};

bool TblPlnrQCtpSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpSup1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQCtpSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	return 0;
};

void TblPlnrQCtpSup1NCalc::insertRec(
			PlnrQCtpSup1NCalc* rec
		) {
};

ubigint TblPlnrQCtpSup1NCalc::insertNewRec(
			PlnrQCtpSup1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQCtpSup1NCalc* _rec = NULL;

	_rec = new PlnrQCtpSup1NCalc(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpSup1NCalc::appendNewRecToRst(
			ListPlnrQCtpSup1NCalc& rst
			, PlnrQCtpSup1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQCtpSup1NCalc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpSup1NCalc::insertRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
};

void TblPlnrQCtpSup1NCalc::updateRec(
			PlnrQCtpSup1NCalc* rec
		) {
};

void TblPlnrQCtpSup1NCalc::updateRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
};

void TblPlnrQCtpSup1NCalc::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpSup1NCalc::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQCtpSup1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQCtpSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpSup1NCalc
 ******************************************************************************/

MyTblPlnrQCtpSup1NCalc::MyTblPlnrQCtpSup1NCalc() : TblPlnrQCtpSup1NCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpSup1NCalc::~MyTblPlnrQCtpSup1NCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpSup1NCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpSup1NCalc (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpSup1NCalc SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpSup1NCalc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpSup1NCalc WHERE jref = ?", false);
};

bool MyTblPlnrQCtpSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpSup1NCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpSup1NCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpSup1NCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpSup1NCalc();

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

ubigint MyTblPlnrQCtpSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpSup1NCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpSup1NCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpSup1NCalc();

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

void MyTblPlnrQCtpSup1NCalc::insertRec(
			PlnrQCtpSup1NCalc* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpSup1NCalc / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpSup1NCalc / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpSup1NCalc::insertRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpSup1NCalc::updateRec(
			PlnrQCtpSup1NCalc* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpSup1NCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpSup1NCalc / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpSup1NCalc::updateRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpSup1NCalc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpSup1NCalc / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpSup1NCalc / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpSup1NCalc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpSup1NCalc / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpSup1NCalc / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQCtpSup1NCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpSup1NCalc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpSup1NCalc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpSup1NCalc
 ******************************************************************************/

PgTblPlnrQCtpSup1NCalc::PgTblPlnrQCtpSup1NCalc() : TblPlnrQCtpSup1NCalc(), PgTable() {
};

PgTblPlnrQCtpSup1NCalc::~PgTblPlnrQCtpSup1NCalc() {
};

void PgTblPlnrQCtpSup1NCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_insertRec", "INSERT INTO TblPlnrQCtpSup1NCalc (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_updateRec", "UPDATE TblPlnrQCtpSup1NCalc SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_removeRecByQref", "DELETE FROM TblPlnrQCtpSup1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_removeRstByJref", "DELETE FROM TblPlnrQCtpSup1NCalc WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQCtpSup1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpSup1NCalc_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQCtpSup1NCalc WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpSup1NCalc::loadRec(
			PGresult* res
			, PlnrQCtpSup1NCalc** rec
		) {
	char* ptr;

	PlnrQCtpSup1NCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpSup1NCalc();

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

ubigint PgTblPlnrQCtpSup1NCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpSup1NCalc* rec;

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
			rec = new PlnrQCtpSup1NCalc();

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

bool PgTblPlnrQCtpSup1NCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpSup1NCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpSup1NCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpSup1NCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpSup1NCalc::insertRec(
			PlnrQCtpSup1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpSup1NCalc_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpSup1NCalc::insertRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpSup1NCalc::updateRec(
			PlnrQCtpSup1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpSup1NCalc_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpSup1NCalc::updateRst(
			ListPlnrQCtpSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpSup1NCalc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpSup1NCalc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpSup1NCalc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpSup1NCalc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpSup1NCalc_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQCtpSup1NCalc** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpSup1NCalc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpSup1NCalc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpSup1NCalc_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

