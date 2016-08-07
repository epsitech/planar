/**
  * \file PlnrQDsn1NReticle.cpp
  * Dbs and XML wrapper for table TblPlnrQDsn1NReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsn1NReticle.h"

/******************************************************************************
 class PlnrQDsn1NReticle
 ******************************************************************************/

PlnrQDsn1NReticle::PlnrQDsn1NReticle(
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

void PlnrQDsn1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsn1NReticle";

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
 class ListPlnrQDsn1NReticle
 ******************************************************************************/

ListPlnrQDsn1NReticle::ListPlnrQDsn1NReticle() {
};

ListPlnrQDsn1NReticle::ListPlnrQDsn1NReticle(
			const ListPlnrQDsn1NReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsn1NReticle(*(src.nodes[i]));
};

ListPlnrQDsn1NReticle::~ListPlnrQDsn1NReticle() {
	clear();
};

void ListPlnrQDsn1NReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsn1NReticle::size() const {
	return(nodes.size());
};

void ListPlnrQDsn1NReticle::append(
			PlnrQDsn1NReticle* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsn1NReticle& ListPlnrQDsn1NReticle::operator=(
			const ListPlnrQDsn1NReticle& src
		) {
	PlnrQDsn1NReticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsn1NReticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsn1NReticle::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsn1NReticle";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsn1NReticle
 ******************************************************************************/

TblPlnrQDsn1NReticle::TblPlnrQDsn1NReticle() {
};

TblPlnrQDsn1NReticle::~TblPlnrQDsn1NReticle() {
};

bool TblPlnrQDsn1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsn1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQDsn1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	return 0;
};

void TblPlnrQDsn1NReticle::insertRec(
			PlnrQDsn1NReticle* rec
		) {
};

ubigint TblPlnrQDsn1NReticle::insertNewRec(
			PlnrQDsn1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsn1NReticle* _rec = NULL;

	_rec = new PlnrQDsn1NReticle(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsn1NReticle::appendNewRecToRst(
			ListPlnrQDsn1NReticle& rst
			, PlnrQDsn1NReticle** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsn1NReticle* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsn1NReticle::insertRst(
			ListPlnrQDsn1NReticle& rst
		) {
};

void TblPlnrQDsn1NReticle::updateRec(
			PlnrQDsn1NReticle* rec
		) {
};

void TblPlnrQDsn1NReticle::updateRst(
			ListPlnrQDsn1NReticle& rst
		) {
};

void TblPlnrQDsn1NReticle::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsn1NReticle::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsn1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQDsn1NReticle** rec
		) {
	return false;
};

ubigint TblPlnrQDsn1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsn1NReticle
 ******************************************************************************/

MyTblPlnrQDsn1NReticle::MyTblPlnrQDsn1NReticle() : TblPlnrQDsn1NReticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsn1NReticle::~MyTblPlnrQDsn1NReticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsn1NReticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsn1NReticle (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsn1NReticle SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsn1NReticle WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsn1NReticle WHERE jref = ?", false);
};

bool MyTblPlnrQDsn1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsn1NReticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsn1NReticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsn1NReticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsn1NReticle();

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

ubigint MyTblPlnrQDsn1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsn1NReticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsn1NReticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsn1NReticle();

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

void MyTblPlnrQDsn1NReticle::insertRec(
			PlnrQDsn1NReticle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsn1NReticle / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsn1NReticle / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsn1NReticle::insertRst(
			ListPlnrQDsn1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsn1NReticle::updateRec(
			PlnrQDsn1NReticle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsn1NReticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsn1NReticle / stmtUpdateRec)\n");
};

void MyTblPlnrQDsn1NReticle::updateRst(
			ListPlnrQDsn1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsn1NReticle::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsn1NReticle / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsn1NReticle / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsn1NReticle::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsn1NReticle / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsn1NReticle / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsn1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQDsn1NReticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsn1NReticle WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsn1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsn1NReticle WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsn1NReticle
 ******************************************************************************/

PgTblPlnrQDsn1NReticle::PgTblPlnrQDsn1NReticle() : TblPlnrQDsn1NReticle(), PgTable() {
};

PgTblPlnrQDsn1NReticle::~PgTblPlnrQDsn1NReticle() {
};

void PgTblPlnrQDsn1NReticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_insertRec", "INSERT INTO TblPlnrQDsn1NReticle (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_updateRec", "UPDATE TblPlnrQDsn1NReticle SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_removeRecByQref", "DELETE FROM TblPlnrQDsn1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_removeRstByJref", "DELETE FROM TblPlnrQDsn1NReticle WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsn1NReticle WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsn1NReticle_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsn1NReticle WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsn1NReticle::loadRec(
			PGresult* res
			, PlnrQDsn1NReticle** rec
		) {
	char* ptr;

	PlnrQDsn1NReticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsn1NReticle();

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

ubigint PgTblPlnrQDsn1NReticle::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsn1NReticle* rec;

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
			rec = new PlnrQDsn1NReticle();

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

bool PgTblPlnrQDsn1NReticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsn1NReticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsn1NReticle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsn1NReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsn1NReticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsn1NReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsn1NReticle::insertRec(
			PlnrQDsn1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsn1NReticle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsn1NReticle::insertRst(
			ListPlnrQDsn1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsn1NReticle::updateRec(
			PlnrQDsn1NReticle* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsn1NReticle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsn1NReticle::updateRst(
			ListPlnrQDsn1NReticle& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsn1NReticle::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsn1NReticle_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsn1NReticle::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsn1NReticle_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsn1NReticle_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsn1NReticle::loadRecByQref(
			ubigint qref
			, PlnrQDsn1NReticle** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsn1NReticle_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsn1NReticle::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsn1NReticle& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsn1NReticle_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

