/**
  * \file PlnrQDsnHk1NLevel.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLevel.h"

/******************************************************************************
 class PlnrQDsnHk1NLevel
 ******************************************************************************/

PlnrQDsnHk1NLevel::PlnrQDsnHk1NLevel(
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

void PlnrQDsnHk1NLevel::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnHk1NLevel";

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
 class ListPlnrQDsnHk1NLevel
 ******************************************************************************/

ListPlnrQDsnHk1NLevel::ListPlnrQDsnHk1NLevel() {
};

ListPlnrQDsnHk1NLevel::ListPlnrQDsnHk1NLevel(
			const ListPlnrQDsnHk1NLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLevel(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLevel::~ListPlnrQDsnHk1NLevel() {
	clear();
};

void ListPlnrQDsnHk1NLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnHk1NLevel::size() const {
	return(nodes.size());
};

void ListPlnrQDsnHk1NLevel::append(
			PlnrQDsnHk1NLevel* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnHk1NLevel& ListPlnrQDsnHk1NLevel::operator=(
			const ListPlnrQDsnHk1NLevel& src
		) {
	PlnrQDsnHk1NLevel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnHk1NLevel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnHk1NLevel::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnHk1NLevel";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnHk1NLevel
 ******************************************************************************/

TblPlnrQDsnHk1NLevel::TblPlnrQDsnHk1NLevel() {
};

TblPlnrQDsnHk1NLevel::~TblPlnrQDsnHk1NLevel() {
};

bool TblPlnrQDsnHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLevel** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	return 0;
};

void TblPlnrQDsnHk1NLevel::insertRec(
			PlnrQDsnHk1NLevel* rec
		) {
};

ubigint TblPlnrQDsnHk1NLevel::insertNewRec(
			PlnrQDsnHk1NLevel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLevel* _rec = NULL;

	_rec = new PlnrQDsnHk1NLevel(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnHk1NLevel::appendNewRecToRst(
			ListPlnrQDsnHk1NLevel& rst
			, PlnrQDsnHk1NLevel** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLevel* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnHk1NLevel::insertRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
};

void TblPlnrQDsnHk1NLevel::updateRec(
			PlnrQDsnHk1NLevel* rec
		) {
};

void TblPlnrQDsnHk1NLevel::updateRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
};

void TblPlnrQDsnHk1NLevel::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnHk1NLevel::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLevel** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnHk1NLevel
 ******************************************************************************/

MyTblPlnrQDsnHk1NLevel::MyTblPlnrQDsnHk1NLevel() : TblPlnrQDsnHk1NLevel(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnHk1NLevel::~MyTblPlnrQDsnHk1NLevel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnHk1NLevel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnHk1NLevel (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnHk1NLevel SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnHk1NLevel WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnHk1NLevel WHERE jref = ?", false);
};

bool MyTblPlnrQDsnHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLevel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnHk1NLevel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLevel / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnHk1NLevel();

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

ubigint MyTblPlnrQDsnHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnHk1NLevel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLevel / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnHk1NLevel();

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

void MyTblPlnrQDsnHk1NLevel::insertRec(
			PlnrQDsnHk1NLevel* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLevel / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLevel / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnHk1NLevel::insertRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLevel::updateRec(
			PlnrQDsnHk1NLevel* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLevel / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLevel / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnHk1NLevel::updateRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLevel::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLevel / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLevel / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnHk1NLevel::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLevel / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLevel / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLevel** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnHk1NLevel WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnHk1NLevel WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnHk1NLevel
 ******************************************************************************/

PgTblPlnrQDsnHk1NLevel::PgTblPlnrQDsnHk1NLevel() : TblPlnrQDsnHk1NLevel(), PgTable() {
};

PgTblPlnrQDsnHk1NLevel::~PgTblPlnrQDsnHk1NLevel() {
};

void PgTblPlnrQDsnHk1NLevel::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_insertRec", "INSERT INTO TblPlnrQDsnHk1NLevel (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_updateRec", "UPDATE TblPlnrQDsnHk1NLevel SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_removeRecByQref", "DELETE FROM TblPlnrQDsnHk1NLevel WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_removeRstByJref", "DELETE FROM TblPlnrQDsnHk1NLevel WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NLevel WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLevel_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NLevel WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnHk1NLevel::loadRec(
			PGresult* res
			, PlnrQDsnHk1NLevel** rec
		) {
	char* ptr;

	PlnrQDsnHk1NLevel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnHk1NLevel();

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

ubigint PgTblPlnrQDsnHk1NLevel::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnHk1NLevel* rec;

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
			rec = new PlnrQDsnHk1NLevel();

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

bool PgTblPlnrQDsnHk1NLevel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnHk1NLevel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLevel::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnHk1NLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLevel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnHk1NLevel::insertRec(
			PlnrQDsnHk1NLevel* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLevel_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLevel::insertRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLevel::updateRec(
			PlnrQDsnHk1NLevel* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLevel_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLevel::updateRst(
			ListPlnrQDsnHk1NLevel& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLevel::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLevel_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLevel::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLevel_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLevel_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnHk1NLevel::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLevel** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnHk1NLevel_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnHk1NLevel::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLevel& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnHk1NLevel_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

