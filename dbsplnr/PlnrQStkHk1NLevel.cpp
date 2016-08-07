/**
  * \file PlnrQStkHk1NLevel.cpp
  * Dbs and XML wrapper for table TblPlnrQStkHk1NLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkHk1NLevel.h"

/******************************************************************************
 class PlnrQStkHk1NLevel
 ******************************************************************************/

PlnrQStkHk1NLevel::PlnrQStkHk1NLevel(
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

void PlnrQStkHk1NLevel::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQStkHk1NLevel";

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
 class ListPlnrQStkHk1NLevel
 ******************************************************************************/

ListPlnrQStkHk1NLevel::ListPlnrQStkHk1NLevel() {
};

ListPlnrQStkHk1NLevel::ListPlnrQStkHk1NLevel(
			const ListPlnrQStkHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLevel(*(src.nodes[i]));
};

ListPlnrQStkHk1NLevel::~ListPlnrQStkHk1NLevel() {
	clear();
};

void ListPlnrQStkHk1NLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQStkHk1NLevel::size() const {
	return(nodes.size());
};

void ListPlnrQStkHk1NLevel::append(
			PlnrQStkHk1NLevel* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQStkHk1NLevel& ListPlnrQStkHk1NLevel::operator=(
			const ListPlnrQStkHk1NLevel& src
		) {
	PlnrQStkHk1NLevel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQStkHk1NLevel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQStkHk1NLevel::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQStkHk1NLevel";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQStkHk1NLevel
 ******************************************************************************/

TblPlnrQStkHk1NLevel::TblPlnrQStkHk1NLevel() {
};

TblPlnrQStkHk1NLevel::~TblPlnrQStkHk1NLevel() {
};

bool TblPlnrQStkHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLevel** rec
		) {
	return false;
};

ubigint TblPlnrQStkHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	return 0;
};

void TblPlnrQStkHk1NLevel::insertRec(
			PlnrQStkHk1NLevel* rec
		) {
};

ubigint TblPlnrQStkHk1NLevel::insertNewRec(
			PlnrQStkHk1NLevel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQStkHk1NLevel* _rec = NULL;

	_rec = new PlnrQStkHk1NLevel(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQStkHk1NLevel::appendNewRecToRst(
			ListPlnrQStkHk1NLevel& rst
			, PlnrQStkHk1NLevel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQStkHk1NLevel* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQStkHk1NLevel::insertRst(
			ListPlnrQStkHk1NLevel& rst
		) {
};

void TblPlnrQStkHk1NLevel::updateRec(
			PlnrQStkHk1NLevel* rec
		) {
};

void TblPlnrQStkHk1NLevel::updateRst(
			ListPlnrQStkHk1NLevel& rst
		) {
};

void TblPlnrQStkHk1NLevel::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQStkHk1NLevel::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQStkHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLevel** rec
		) {
	return false;
};

ubigint TblPlnrQStkHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQStkHk1NLevel
 ******************************************************************************/

MyTblPlnrQStkHk1NLevel::MyTblPlnrQStkHk1NLevel() : TblPlnrQStkHk1NLevel(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQStkHk1NLevel::~MyTblPlnrQStkHk1NLevel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQStkHk1NLevel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQStkHk1NLevel (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQStkHk1NLevel SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQStkHk1NLevel WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQStkHk1NLevel WHERE jref = ?", false);
};

bool MyTblPlnrQStkHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLevel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQStkHk1NLevel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkHk1NLevel / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQStkHk1NLevel();

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

ubigint MyTblPlnrQStkHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQStkHk1NLevel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkHk1NLevel / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQStkHk1NLevel();

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

void MyTblPlnrQStkHk1NLevel::insertRec(
			PlnrQStkHk1NLevel* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLevel / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLevel / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQStkHk1NLevel::insertRst(
			ListPlnrQStkHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQStkHk1NLevel::updateRec(
			PlnrQStkHk1NLevel* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLevel / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLevel / stmtUpdateRec)\n");
};

void MyTblPlnrQStkHk1NLevel::updateRst(
			ListPlnrQStkHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQStkHk1NLevel::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLevel / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLevel / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQStkHk1NLevel::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLevel / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLevel / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQStkHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLevel** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQStkHk1NLevel WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQStkHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQStkHk1NLevel WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQStkHk1NLevel
 ******************************************************************************/

PgTblPlnrQStkHk1NLevel::PgTblPlnrQStkHk1NLevel() : TblPlnrQStkHk1NLevel(), PgTable() {
};

PgTblPlnrQStkHk1NLevel::~PgTblPlnrQStkHk1NLevel() {
};

void PgTblPlnrQStkHk1NLevel::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_insertRec", "INSERT INTO TblPlnrQStkHk1NLevel (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_updateRec", "UPDATE TblPlnrQStkHk1NLevel SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_removeRecByQref", "DELETE FROM TblPlnrQStkHk1NLevel WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_removeRstByJref", "DELETE FROM TblPlnrQStkHk1NLevel WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQStkHk1NLevel WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLevel_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQStkHk1NLevel WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQStkHk1NLevel::loadRec(
			PGresult* res
			, PlnrQStkHk1NLevel** rec
		) {
	char* ptr;

	PlnrQStkHk1NLevel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQStkHk1NLevel();

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

ubigint PgTblPlnrQStkHk1NLevel::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQStkHk1NLevel* rec;

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
			rec = new PlnrQStkHk1NLevel();

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

bool PgTblPlnrQStkHk1NLevel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQStkHk1NLevel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkHk1NLevel::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQStkHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLevel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQStkHk1NLevel::insertRec(
			PlnrQStkHk1NLevel* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLevel_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQStkHk1NLevel::insertRst(
			ListPlnrQStkHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQStkHk1NLevel::updateRec(
			PlnrQStkHk1NLevel* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLevel_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQStkHk1NLevel::updateRst(
			ListPlnrQStkHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQStkHk1NLevel::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLevel_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQStkHk1NLevel::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLevel_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLevel_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQStkHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLevel** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQStkHk1NLevel_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQStkHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLevel& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQStkHk1NLevel_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

