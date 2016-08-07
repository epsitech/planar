/**
  * \file PlnrQLyr1NReticle.cpp
  * Dbs and XML wrapper for table TblPlnrQLyr1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyr1NReticle.h"

/******************************************************************************
 class PlnrQLyr1NReticle
 ******************************************************************************/

PlnrQLyr1NReticle::PlnrQLyr1NReticle(
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

void PlnrQLyr1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQLyr1NReticle";

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
 class ListPlnrQLyr1NReticle
 ******************************************************************************/

ListPlnrQLyr1NReticle::ListPlnrQLyr1NReticle() {
};

ListPlnrQLyr1NReticle::ListPlnrQLyr1NReticle(
			const ListPlnrQLyr1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyr1NReticle(*(src.nodes[i]));
};

ListPlnrQLyr1NReticle::~ListPlnrQLyr1NReticle() {
	clear();
};

void ListPlnrQLyr1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQLyr1NReticle::size() const {
	return(nodes.size());
};

void ListPlnrQLyr1NReticle::append(
			PlnrQLyr1NReticle* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQLyr1NReticle& ListPlnrQLyr1NReticle::operator=(
			const ListPlnrQLyr1NReticle& src
		) {
	PlnrQLyr1NReticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQLyr1NReticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQLyr1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQLyr1NReticle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQLyr1NReticle
 ******************************************************************************/

TblPlnrQLyr1NReticle::TblPlnrQLyr1NReticle() {
};

TblPlnrQLyr1NReticle::~TblPlnrQLyr1NReticle() {
};

bool TblPlnrQLyr1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQLyr1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	return 0;
};

void TblPlnrQLyr1NReticle::insertRec(
			PlnrQLyr1NReticle* rec
		) {
};

ubigint TblPlnrQLyr1NReticle::insertNewRec(
			PlnrQLyr1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQLyr1NReticle* _rec = NULL;

	_rec = new PlnrQLyr1NReticle(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQLyr1NReticle::appendNewRecToRst(
			ListPlnrQLyr1NReticle& rst
			, PlnrQLyr1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQLyr1NReticle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQLyr1NReticle::insertRst(
			ListPlnrQLyr1NReticle& rst
		) {
};

void TblPlnrQLyr1NReticle::updateRec(
			PlnrQLyr1NReticle* rec
		) {
};

void TblPlnrQLyr1NReticle::updateRst(
			ListPlnrQLyr1NReticle& rst
		) {
};

void TblPlnrQLyr1NReticle::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQLyr1NReticle::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQLyr1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQLyr1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQLyr1NReticle
 ******************************************************************************/

MyTblPlnrQLyr1NReticle::MyTblPlnrQLyr1NReticle() : TblPlnrQLyr1NReticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQLyr1NReticle::~MyTblPlnrQLyr1NReticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQLyr1NReticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQLyr1NReticle (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQLyr1NReticle SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQLyr1NReticle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQLyr1NReticle WHERE jref = ?", false);
};

bool MyTblPlnrQLyr1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NReticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQLyr1NReticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyr1NReticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQLyr1NReticle();

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

ubigint MyTblPlnrQLyr1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQLyr1NReticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyr1NReticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQLyr1NReticle();

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

void MyTblPlnrQLyr1NReticle::insertRec(
			PlnrQLyr1NReticle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NReticle / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NReticle / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQLyr1NReticle::insertRst(
			ListPlnrQLyr1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQLyr1NReticle::updateRec(
			PlnrQLyr1NReticle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NReticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NReticle / stmtUpdateRec)\n");
};

void MyTblPlnrQLyr1NReticle::updateRst(
			ListPlnrQLyr1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQLyr1NReticle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NReticle / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NReticle / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQLyr1NReticle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyr1NReticle / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyr1NReticle / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQLyr1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NReticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQLyr1NReticle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQLyr1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQLyr1NReticle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQLyr1NReticle
 ******************************************************************************/

PgTblPlnrQLyr1NReticle::PgTblPlnrQLyr1NReticle() : TblPlnrQLyr1NReticle(), PgTable() {
};

PgTblPlnrQLyr1NReticle::~PgTblPlnrQLyr1NReticle() {
};

void PgTblPlnrQLyr1NReticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_insertRec", "INSERT INTO TblPlnrQLyr1NReticle (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_updateRec", "UPDATE TblPlnrQLyr1NReticle SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_removeRecByQref", "DELETE FROM TblPlnrQLyr1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_removeRstByJref", "DELETE FROM TblPlnrQLyr1NReticle WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQLyr1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyr1NReticle_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQLyr1NReticle WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQLyr1NReticle::loadRec(
			PGresult* res
			, PlnrQLyr1NReticle** rec
		) {
	char* ptr;

	PlnrQLyr1NReticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQLyr1NReticle();

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

ubigint PgTblPlnrQLyr1NReticle::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQLyr1NReticle* rec;

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
			rec = new PlnrQLyr1NReticle();

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

bool PgTblPlnrQLyr1NReticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQLyr1NReticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyr1NReticle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQLyr1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyr1NReticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyr1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQLyr1NReticle::insertRec(
			PlnrQLyr1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NReticle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQLyr1NReticle::insertRst(
			ListPlnrQLyr1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQLyr1NReticle::updateRec(
			PlnrQLyr1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NReticle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQLyr1NReticle::updateRst(
			ListPlnrQLyr1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQLyr1NReticle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NReticle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQLyr1NReticle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyr1NReticle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyr1NReticle_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQLyr1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQLyr1NReticle** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQLyr1NReticle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQLyr1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyr1NReticle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQLyr1NReticle_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

