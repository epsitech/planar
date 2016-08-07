/**
  * \file PlnrQClcSup1NCalc.cpp
  * Dbs and XML wrapper for table TblPlnrQClcSup1NCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcSup1NCalc.h"

/******************************************************************************
 class PlnrQClcSup1NCalc
 ******************************************************************************/

PlnrQClcSup1NCalc::PlnrQClcSup1NCalc(
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

void PlnrQClcSup1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcSup1NCalc";

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
 class ListPlnrQClcSup1NCalc
 ******************************************************************************/

ListPlnrQClcSup1NCalc::ListPlnrQClcSup1NCalc() {
};

ListPlnrQClcSup1NCalc::ListPlnrQClcSup1NCalc(
			const ListPlnrQClcSup1NCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcSup1NCalc(*(src.nodes[i]));
};

ListPlnrQClcSup1NCalc::~ListPlnrQClcSup1NCalc() {
	clear();
};

void ListPlnrQClcSup1NCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcSup1NCalc::size() const {
	return(nodes.size());
};

void ListPlnrQClcSup1NCalc::append(
			PlnrQClcSup1NCalc* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcSup1NCalc& ListPlnrQClcSup1NCalc::operator=(
			const ListPlnrQClcSup1NCalc& src
		) {
	PlnrQClcSup1NCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcSup1NCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcSup1NCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcSup1NCalc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcSup1NCalc
 ******************************************************************************/

TblPlnrQClcSup1NCalc::TblPlnrQClcSup1NCalc() {
};

TblPlnrQClcSup1NCalc::~TblPlnrQClcSup1NCalc() {
};

bool TblPlnrQClcSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcSup1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQClcSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	return 0;
};

void TblPlnrQClcSup1NCalc::insertRec(
			PlnrQClcSup1NCalc* rec
		) {
};

ubigint TblPlnrQClcSup1NCalc::insertNewRec(
			PlnrQClcSup1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQClcSup1NCalc* _rec = NULL;

	_rec = new PlnrQClcSup1NCalc(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcSup1NCalc::appendNewRecToRst(
			ListPlnrQClcSup1NCalc& rst
			, PlnrQClcSup1NCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQClcSup1NCalc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcSup1NCalc::insertRst(
			ListPlnrQClcSup1NCalc& rst
		) {
};

void TblPlnrQClcSup1NCalc::updateRec(
			PlnrQClcSup1NCalc* rec
		) {
};

void TblPlnrQClcSup1NCalc::updateRst(
			ListPlnrQClcSup1NCalc& rst
		) {
};

void TblPlnrQClcSup1NCalc::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcSup1NCalc::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQClcSup1NCalc** rec
		) {
	return false;
};

ubigint TblPlnrQClcSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcSup1NCalc
 ******************************************************************************/

MyTblPlnrQClcSup1NCalc::MyTblPlnrQClcSup1NCalc() : TblPlnrQClcSup1NCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcSup1NCalc::~MyTblPlnrQClcSup1NCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcSup1NCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcSup1NCalc (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcSup1NCalc SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcSup1NCalc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcSup1NCalc WHERE jref = ?", false);
};

bool MyTblPlnrQClcSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcSup1NCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcSup1NCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcSup1NCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcSup1NCalc();

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

ubigint MyTblPlnrQClcSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcSup1NCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcSup1NCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcSup1NCalc();

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

void MyTblPlnrQClcSup1NCalc::insertRec(
			PlnrQClcSup1NCalc* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcSup1NCalc / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcSup1NCalc / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcSup1NCalc::insertRst(
			ListPlnrQClcSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcSup1NCalc::updateRec(
			PlnrQClcSup1NCalc* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcSup1NCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcSup1NCalc / stmtUpdateRec)\n");
};

void MyTblPlnrQClcSup1NCalc::updateRst(
			ListPlnrQClcSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcSup1NCalc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcSup1NCalc / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcSup1NCalc / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcSup1NCalc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcSup1NCalc / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcSup1NCalc / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQClcSup1NCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcSup1NCalc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcSup1NCalc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcSup1NCalc
 ******************************************************************************/

PgTblPlnrQClcSup1NCalc::PgTblPlnrQClcSup1NCalc() : TblPlnrQClcSup1NCalc(), PgTable() {
};

PgTblPlnrQClcSup1NCalc::~PgTblPlnrQClcSup1NCalc() {
};

void PgTblPlnrQClcSup1NCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_insertRec", "INSERT INTO TblPlnrQClcSup1NCalc (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_updateRec", "UPDATE TblPlnrQClcSup1NCalc SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_removeRecByQref", "DELETE FROM TblPlnrQClcSup1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_removeRstByJref", "DELETE FROM TblPlnrQClcSup1NCalc WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQClcSup1NCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcSup1NCalc_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQClcSup1NCalc WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcSup1NCalc::loadRec(
			PGresult* res
			, PlnrQClcSup1NCalc** rec
		) {
	char* ptr;

	PlnrQClcSup1NCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcSup1NCalc();

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

ubigint PgTblPlnrQClcSup1NCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcSup1NCalc* rec;

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
			rec = new PlnrQClcSup1NCalc();

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

bool PgTblPlnrQClcSup1NCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcSup1NCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcSup1NCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcSup1NCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcSup1NCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcSup1NCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcSup1NCalc::insertRec(
			PlnrQClcSup1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQClcSup1NCalc_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcSup1NCalc::insertRst(
			ListPlnrQClcSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcSup1NCalc::updateRec(
			PlnrQClcSup1NCalc* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQClcSup1NCalc_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcSup1NCalc::updateRst(
			ListPlnrQClcSup1NCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcSup1NCalc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcSup1NCalc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcSup1NCalc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcSup1NCalc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcSup1NCalc_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcSup1NCalc::loadRecByQref(
			ubigint qref
			, PlnrQClcSup1NCalc** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcSup1NCalc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcSup1NCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcSup1NCalc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcSup1NCalc_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

