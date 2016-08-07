/**
  * \file PlnrQTpoHk1NReticle.cpp
  * Dbs and XML wrapper for table TblPlnrQTpoHk1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpoHk1NReticle.h"

/******************************************************************************
 class PlnrQTpoHk1NReticle
 ******************************************************************************/

PlnrQTpoHk1NReticle::PlnrQTpoHk1NReticle(
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

void PlnrQTpoHk1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQTpoHk1NReticle";

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
 class ListPlnrQTpoHk1NReticle
 ******************************************************************************/

ListPlnrQTpoHk1NReticle::ListPlnrQTpoHk1NReticle() {
};

ListPlnrQTpoHk1NReticle::ListPlnrQTpoHk1NReticle(
			const ListPlnrQTpoHk1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpoHk1NReticle(*(src.nodes[i]));
};

ListPlnrQTpoHk1NReticle::~ListPlnrQTpoHk1NReticle() {
	clear();
};

void ListPlnrQTpoHk1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQTpoHk1NReticle::size() const {
	return(nodes.size());
};

void ListPlnrQTpoHk1NReticle::append(
			PlnrQTpoHk1NReticle* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQTpoHk1NReticle& ListPlnrQTpoHk1NReticle::operator=(
			const ListPlnrQTpoHk1NReticle& src
		) {
	PlnrQTpoHk1NReticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQTpoHk1NReticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQTpoHk1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQTpoHk1NReticle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQTpoHk1NReticle
 ******************************************************************************/

TblPlnrQTpoHk1NReticle::TblPlnrQTpoHk1NReticle() {
};

TblPlnrQTpoHk1NReticle::~TblPlnrQTpoHk1NReticle() {
};

bool TblPlnrQTpoHk1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoHk1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQTpoHk1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	return 0;
};

void TblPlnrQTpoHk1NReticle::insertRec(
			PlnrQTpoHk1NReticle* rec
		) {
};

ubigint TblPlnrQTpoHk1NReticle::insertNewRec(
			PlnrQTpoHk1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQTpoHk1NReticle* _rec = NULL;

	_rec = new PlnrQTpoHk1NReticle(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQTpoHk1NReticle::appendNewRecToRst(
			ListPlnrQTpoHk1NReticle& rst
			, PlnrQTpoHk1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQTpoHk1NReticle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQTpoHk1NReticle::insertRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
};

void TblPlnrQTpoHk1NReticle::updateRec(
			PlnrQTpoHk1NReticle* rec
		) {
};

void TblPlnrQTpoHk1NReticle::updateRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
};

void TblPlnrQTpoHk1NReticle::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQTpoHk1NReticle::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQTpoHk1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQTpoHk1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQTpoHk1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQTpoHk1NReticle
 ******************************************************************************/

MyTblPlnrQTpoHk1NReticle::MyTblPlnrQTpoHk1NReticle() : TblPlnrQTpoHk1NReticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQTpoHk1NReticle::~MyTblPlnrQTpoHk1NReticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQTpoHk1NReticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQTpoHk1NReticle (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQTpoHk1NReticle SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQTpoHk1NReticle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQTpoHk1NReticle WHERE jref = ?", false);
};

bool MyTblPlnrQTpoHk1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoHk1NReticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQTpoHk1NReticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoHk1NReticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQTpoHk1NReticle();

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

ubigint MyTblPlnrQTpoHk1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQTpoHk1NReticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpoHk1NReticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQTpoHk1NReticle();

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

void MyTblPlnrQTpoHk1NReticle::insertRec(
			PlnrQTpoHk1NReticle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoHk1NReticle / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoHk1NReticle / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQTpoHk1NReticle::insertRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQTpoHk1NReticle::updateRec(
			PlnrQTpoHk1NReticle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoHk1NReticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoHk1NReticle / stmtUpdateRec)\n");
};

void MyTblPlnrQTpoHk1NReticle::updateRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQTpoHk1NReticle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoHk1NReticle / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoHk1NReticle / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQTpoHk1NReticle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpoHk1NReticle / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpoHk1NReticle / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQTpoHk1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQTpoHk1NReticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQTpoHk1NReticle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQTpoHk1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQTpoHk1NReticle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQTpoHk1NReticle
 ******************************************************************************/

PgTblPlnrQTpoHk1NReticle::PgTblPlnrQTpoHk1NReticle() : TblPlnrQTpoHk1NReticle(), PgTable() {
};

PgTblPlnrQTpoHk1NReticle::~PgTblPlnrQTpoHk1NReticle() {
};

void PgTblPlnrQTpoHk1NReticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_insertRec", "INSERT INTO TblPlnrQTpoHk1NReticle (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_updateRec", "UPDATE TblPlnrQTpoHk1NReticle SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_removeRecByQref", "DELETE FROM TblPlnrQTpoHk1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_removeRstByJref", "DELETE FROM TblPlnrQTpoHk1NReticle WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQTpoHk1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpoHk1NReticle_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQTpoHk1NReticle WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQTpoHk1NReticle::loadRec(
			PGresult* res
			, PlnrQTpoHk1NReticle** rec
		) {
	char* ptr;

	PlnrQTpoHk1NReticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQTpoHk1NReticle();

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

ubigint PgTblPlnrQTpoHk1NReticle::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQTpoHk1NReticle* rec;

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
			rec = new PlnrQTpoHk1NReticle();

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

bool PgTblPlnrQTpoHk1NReticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQTpoHk1NReticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoHk1NReticle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQTpoHk1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpoHk1NReticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpoHk1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQTpoHk1NReticle::insertRec(
			PlnrQTpoHk1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoHk1NReticle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQTpoHk1NReticle::insertRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQTpoHk1NReticle::updateRec(
			PlnrQTpoHk1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoHk1NReticle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQTpoHk1NReticle::updateRst(
			ListPlnrQTpoHk1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQTpoHk1NReticle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoHk1NReticle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQTpoHk1NReticle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpoHk1NReticle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpoHk1NReticle_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQTpoHk1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQTpoHk1NReticle** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQTpoHk1NReticle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQTpoHk1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpoHk1NReticle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQTpoHk1NReticle_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

