/**
  * \file PlnrQTpo1NArray.cpp
  * Dbs and XML wrapper for table TblPlnrQTpo1NArray (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQTpo1NArray.h"

/******************************************************************************
 class PlnrQTpo1NArray
 ******************************************************************************/

PlnrQTpo1NArray::PlnrQTpo1NArray(
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

void PlnrQTpo1NArray::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQTpo1NArray";

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
 class ListPlnrQTpo1NArray
 ******************************************************************************/

ListPlnrQTpo1NArray::ListPlnrQTpo1NArray() {
};

ListPlnrQTpo1NArray::ListPlnrQTpo1NArray(
			const ListPlnrQTpo1NArray& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQTpo1NArray(*(src.nodes[i]));
};

ListPlnrQTpo1NArray::~ListPlnrQTpo1NArray() {
	clear();
};

void ListPlnrQTpo1NArray::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQTpo1NArray::size() const {
	return(nodes.size());
};

void ListPlnrQTpo1NArray::append(
			PlnrQTpo1NArray* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQTpo1NArray& ListPlnrQTpo1NArray::operator=(
			const ListPlnrQTpo1NArray& src
		) {
	PlnrQTpo1NArray* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQTpo1NArray(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQTpo1NArray::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQTpo1NArray";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQTpo1NArray
 ******************************************************************************/

TblPlnrQTpo1NArray::TblPlnrQTpo1NArray() {
};

TblPlnrQTpo1NArray::~TblPlnrQTpo1NArray() {
};

bool TblPlnrQTpo1NArray::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpo1NArray** rec
		) {
	return false;
};

ubigint TblPlnrQTpo1NArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	return 0;
};

void TblPlnrQTpo1NArray::insertRec(
			PlnrQTpo1NArray* rec
		) {
};

ubigint TblPlnrQTpo1NArray::insertNewRec(
			PlnrQTpo1NArray** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQTpo1NArray* _rec = NULL;

	_rec = new PlnrQTpo1NArray(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQTpo1NArray::appendNewRecToRst(
			ListPlnrQTpo1NArray& rst
			, PlnrQTpo1NArray** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQTpo1NArray* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQTpo1NArray::insertRst(
			ListPlnrQTpo1NArray& rst
		) {
};

void TblPlnrQTpo1NArray::updateRec(
			PlnrQTpo1NArray* rec
		) {
};

void TblPlnrQTpo1NArray::updateRst(
			ListPlnrQTpo1NArray& rst
		) {
};

void TblPlnrQTpo1NArray::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQTpo1NArray::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQTpo1NArray::loadRecByQref(
			ubigint qref
			, PlnrQTpo1NArray** rec
		) {
	return false;
};

ubigint TblPlnrQTpo1NArray::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQTpo1NArray
 ******************************************************************************/

MyTblPlnrQTpo1NArray::MyTblPlnrQTpo1NArray() : TblPlnrQTpo1NArray(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQTpo1NArray::~MyTblPlnrQTpo1NArray() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQTpo1NArray::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQTpo1NArray (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQTpo1NArray SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQTpo1NArray WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQTpo1NArray WHERE jref = ?", false);
};

bool MyTblPlnrQTpo1NArray::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpo1NArray** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQTpo1NArray* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpo1NArray / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQTpo1NArray();

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

ubigint MyTblPlnrQTpo1NArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQTpo1NArray* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQTpo1NArray / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQTpo1NArray();

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

void MyTblPlnrQTpo1NArray::insertRec(
			PlnrQTpo1NArray* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpo1NArray / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpo1NArray / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQTpo1NArray::insertRst(
			ListPlnrQTpo1NArray& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQTpo1NArray::updateRec(
			PlnrQTpo1NArray* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpo1NArray / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpo1NArray / stmtUpdateRec)\n");
};

void MyTblPlnrQTpo1NArray::updateRst(
			ListPlnrQTpo1NArray& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQTpo1NArray::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpo1NArray / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpo1NArray / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQTpo1NArray::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQTpo1NArray / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQTpo1NArray / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQTpo1NArray::loadRecByQref(
			ubigint qref
			, PlnrQTpo1NArray** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQTpo1NArray WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQTpo1NArray::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQTpo1NArray WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQTpo1NArray
 ******************************************************************************/

PgTblPlnrQTpo1NArray::PgTblPlnrQTpo1NArray() : TblPlnrQTpo1NArray(), PgTable() {
};

PgTblPlnrQTpo1NArray::~PgTblPlnrQTpo1NArray() {
};

void PgTblPlnrQTpo1NArray::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQTpo1NArray_insertRec", "INSERT INTO TblPlnrQTpo1NArray (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpo1NArray_updateRec", "UPDATE TblPlnrQTpo1NArray SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpo1NArray_removeRecByQref", "DELETE FROM TblPlnrQTpo1NArray WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpo1NArray_removeRstByJref", "DELETE FROM TblPlnrQTpo1NArray WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQTpo1NArray_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQTpo1NArray WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQTpo1NArray_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQTpo1NArray WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQTpo1NArray::loadRec(
			PGresult* res
			, PlnrQTpo1NArray** rec
		) {
	char* ptr;

	PlnrQTpo1NArray* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQTpo1NArray();

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

ubigint PgTblPlnrQTpo1NArray::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQTpo1NArray* rec;

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
			rec = new PlnrQTpo1NArray();

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

bool PgTblPlnrQTpo1NArray::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQTpo1NArray** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpo1NArray::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQTpo1NArray::loadRecBySQL(
			const string& sqlstr
			, PlnrQTpo1NArray** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQTpo1NArray::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQTpo1NArray::insertRec(
			PlnrQTpo1NArray* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQTpo1NArray_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQTpo1NArray::insertRst(
			ListPlnrQTpo1NArray& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQTpo1NArray::updateRec(
			PlnrQTpo1NArray* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQTpo1NArray_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQTpo1NArray::updateRst(
			ListPlnrQTpo1NArray& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQTpo1NArray::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpo1NArray_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQTpo1NArray::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQTpo1NArray_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQTpo1NArray_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQTpo1NArray::loadRecByQref(
			ubigint qref
			, PlnrQTpo1NArray** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQTpo1NArray_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQTpo1NArray::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQTpo1NArray& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQTpo1NArray_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

