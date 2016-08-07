/**
  * \file PlnrQDvcHk1NVertex.cpp
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NVertex.h"

/******************************************************************************
 class PlnrQDvcHk1NVertex
 ******************************************************************************/

PlnrQDvcHk1NVertex::PlnrQDvcHk1NVertex(
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

void PlnrQDvcHk1NVertex::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDvcHk1NVertex";

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
 class ListPlnrQDvcHk1NVertex
 ******************************************************************************/

ListPlnrQDvcHk1NVertex::ListPlnrQDvcHk1NVertex() {
};

ListPlnrQDvcHk1NVertex::ListPlnrQDvcHk1NVertex(
			const ListPlnrQDvcHk1NVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NVertex(*(src.nodes[i]));
};

ListPlnrQDvcHk1NVertex::~ListPlnrQDvcHk1NVertex() {
	clear();
};

void ListPlnrQDvcHk1NVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDvcHk1NVertex::size() const {
	return(nodes.size());
};

void ListPlnrQDvcHk1NVertex::append(
			PlnrQDvcHk1NVertex* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDvcHk1NVertex& ListPlnrQDvcHk1NVertex::operator=(
			const ListPlnrQDvcHk1NVertex& src
		) {
	PlnrQDvcHk1NVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDvcHk1NVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDvcHk1NVertex::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDvcHk1NVertex";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDvcHk1NVertex
 ******************************************************************************/

TblPlnrQDvcHk1NVertex::TblPlnrQDvcHk1NVertex() {
};

TblPlnrQDvcHk1NVertex::~TblPlnrQDvcHk1NVertex() {
};

bool TblPlnrQDvcHk1NVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NVertex** rec
		) {
	return false;
};

ubigint TblPlnrQDvcHk1NVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	return 0;
};

void TblPlnrQDvcHk1NVertex::insertRec(
			PlnrQDvcHk1NVertex* rec
		) {
};

ubigint TblPlnrQDvcHk1NVertex::insertNewRec(
			PlnrQDvcHk1NVertex** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDvcHk1NVertex* _rec = NULL;

	_rec = new PlnrQDvcHk1NVertex(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDvcHk1NVertex::appendNewRecToRst(
			ListPlnrQDvcHk1NVertex& rst
			, PlnrQDvcHk1NVertex** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDvcHk1NVertex* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDvcHk1NVertex::insertRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
};

void TblPlnrQDvcHk1NVertex::updateRec(
			PlnrQDvcHk1NVertex* rec
		) {
};

void TblPlnrQDvcHk1NVertex::updateRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
};

void TblPlnrQDvcHk1NVertex::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDvcHk1NVertex::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDvcHk1NVertex::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NVertex** rec
		) {
	return false;
};

ubigint TblPlnrQDvcHk1NVertex::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDvcHk1NVertex
 ******************************************************************************/

MyTblPlnrQDvcHk1NVertex::MyTblPlnrQDvcHk1NVertex() : TblPlnrQDvcHk1NVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDvcHk1NVertex::~MyTblPlnrQDvcHk1NVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDvcHk1NVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDvcHk1NVertex (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDvcHk1NVertex SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDvcHk1NVertex WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDvcHk1NVertex WHERE jref = ?", false);
};

bool MyTblPlnrQDvcHk1NVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDvcHk1NVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcHk1NVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDvcHk1NVertex();

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

ubigint MyTblPlnrQDvcHk1NVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDvcHk1NVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcHk1NVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDvcHk1NVertex();

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

void MyTblPlnrQDvcHk1NVertex::insertRec(
			PlnrQDvcHk1NVertex* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NVertex / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NVertex / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDvcHk1NVertex::insertRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDvcHk1NVertex::updateRec(
			PlnrQDvcHk1NVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NVertex / stmtUpdateRec)\n");
};

void MyTblPlnrQDvcHk1NVertex::updateRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDvcHk1NVertex::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NVertex / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NVertex / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDvcHk1NVertex::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NVertex / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NVertex / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDvcHk1NVertex::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDvcHk1NVertex WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDvcHk1NVertex::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDvcHk1NVertex WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDvcHk1NVertex
 ******************************************************************************/

PgTblPlnrQDvcHk1NVertex::PgTblPlnrQDvcHk1NVertex() : TblPlnrQDvcHk1NVertex(), PgTable() {
};

PgTblPlnrQDvcHk1NVertex::~PgTblPlnrQDvcHk1NVertex() {
};

void PgTblPlnrQDvcHk1NVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_insertRec", "INSERT INTO TblPlnrQDvcHk1NVertex (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_updateRec", "UPDATE TblPlnrQDvcHk1NVertex SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_removeRecByQref", "DELETE FROM TblPlnrQDvcHk1NVertex WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_removeRstByJref", "DELETE FROM TblPlnrQDvcHk1NVertex WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDvcHk1NVertex WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NVertex_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDvcHk1NVertex WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDvcHk1NVertex::loadRec(
			PGresult* res
			, PlnrQDvcHk1NVertex** rec
		) {
	char* ptr;

	PlnrQDvcHk1NVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDvcHk1NVertex();

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

ubigint PgTblPlnrQDvcHk1NVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDvcHk1NVertex* rec;

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
			rec = new PlnrQDvcHk1NVertex();

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

bool PgTblPlnrQDvcHk1NVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDvcHk1NVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcHk1NVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDvcHk1NVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcHk1NVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDvcHk1NVertex::insertRec(
			PlnrQDvcHk1NVertex* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NVertex_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDvcHk1NVertex::insertRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDvcHk1NVertex::updateRec(
			PlnrQDvcHk1NVertex* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NVertex_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDvcHk1NVertex::updateRst(
			ListPlnrQDvcHk1NVertex& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDvcHk1NVertex::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NVertex_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDvcHk1NVertex::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NVertex_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NVertex_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDvcHk1NVertex::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NVertex** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDvcHk1NVertex_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDvcHk1NVertex::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NVertex& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDvcHk1NVertex_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

