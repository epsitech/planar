/**
  * \file PlnrQDsnHk1NStructure.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NStructure.h"

/******************************************************************************
 class PlnrQDsnHk1NStructure
 ******************************************************************************/

PlnrQDsnHk1NStructure::PlnrQDsnHk1NStructure(
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

void PlnrQDsnHk1NStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnHk1NStructure";

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
 class ListPlnrQDsnHk1NStructure
 ******************************************************************************/

ListPlnrQDsnHk1NStructure::ListPlnrQDsnHk1NStructure() {
};

ListPlnrQDsnHk1NStructure::ListPlnrQDsnHk1NStructure(
			const ListPlnrQDsnHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NStructure(*(src.nodes[i]));
};

ListPlnrQDsnHk1NStructure::~ListPlnrQDsnHk1NStructure() {
	clear();
};

void ListPlnrQDsnHk1NStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnHk1NStructure::size() const {
	return(nodes.size());
};

void ListPlnrQDsnHk1NStructure::append(
			PlnrQDsnHk1NStructure* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnHk1NStructure& ListPlnrQDsnHk1NStructure::operator=(
			const ListPlnrQDsnHk1NStructure& src
		) {
	PlnrQDsnHk1NStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnHk1NStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnHk1NStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnHk1NStructure";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnHk1NStructure
 ******************************************************************************/

TblPlnrQDsnHk1NStructure::TblPlnrQDsnHk1NStructure() {
};

TblPlnrQDsnHk1NStructure::~TblPlnrQDsnHk1NStructure() {
};

bool TblPlnrQDsnHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NStructure** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	return 0;
};

void TblPlnrQDsnHk1NStructure::insertRec(
			PlnrQDsnHk1NStructure* rec
		) {
};

ubigint TblPlnrQDsnHk1NStructure::insertNewRec(
			PlnrQDsnHk1NStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NStructure* _rec = NULL;

	_rec = new PlnrQDsnHk1NStructure(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnHk1NStructure::appendNewRecToRst(
			ListPlnrQDsnHk1NStructure& rst
			, PlnrQDsnHk1NStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NStructure* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnHk1NStructure::insertRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
};

void TblPlnrQDsnHk1NStructure::updateRec(
			PlnrQDsnHk1NStructure* rec
		) {
};

void TblPlnrQDsnHk1NStructure::updateRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
};

void TblPlnrQDsnHk1NStructure::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnHk1NStructure::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NStructure** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnHk1NStructure
 ******************************************************************************/

MyTblPlnrQDsnHk1NStructure::MyTblPlnrQDsnHk1NStructure() : TblPlnrQDsnHk1NStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnHk1NStructure::~MyTblPlnrQDsnHk1NStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnHk1NStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnHk1NStructure (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnHk1NStructure SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnHk1NStructure WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnHk1NStructure WHERE jref = ?", false);
};

bool MyTblPlnrQDsnHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnHk1NStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnHk1NStructure();

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

ubigint MyTblPlnrQDsnHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnHk1NStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnHk1NStructure();

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

void MyTblPlnrQDsnHk1NStructure::insertRec(
			PlnrQDsnHk1NStructure* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NStructure / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NStructure / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnHk1NStructure::insertRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NStructure::updateRec(
			PlnrQDsnHk1NStructure* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NStructure / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnHk1NStructure::updateRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NStructure::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NStructure / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NStructure / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnHk1NStructure::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NStructure / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NStructure / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnHk1NStructure WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnHk1NStructure WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnHk1NStructure
 ******************************************************************************/

PgTblPlnrQDsnHk1NStructure::PgTblPlnrQDsnHk1NStructure() : TblPlnrQDsnHk1NStructure(), PgTable() {
};

PgTblPlnrQDsnHk1NStructure::~PgTblPlnrQDsnHk1NStructure() {
};

void PgTblPlnrQDsnHk1NStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_insertRec", "INSERT INTO TblPlnrQDsnHk1NStructure (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_updateRec", "UPDATE TblPlnrQDsnHk1NStructure SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_removeRecByQref", "DELETE FROM TblPlnrQDsnHk1NStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_removeRstByJref", "DELETE FROM TblPlnrQDsnHk1NStructure WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NStructure_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NStructure WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnHk1NStructure::loadRec(
			PGresult* res
			, PlnrQDsnHk1NStructure** rec
		) {
	char* ptr;

	PlnrQDsnHk1NStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnHk1NStructure();

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

ubigint PgTblPlnrQDsnHk1NStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnHk1NStructure* rec;

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
			rec = new PlnrQDsnHk1NStructure();

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

bool PgTblPlnrQDsnHk1NStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnHk1NStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnHk1NStructure::insertRec(
			PlnrQDsnHk1NStructure* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NStructure_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnHk1NStructure::insertRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NStructure::updateRec(
			PlnrQDsnHk1NStructure* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NStructure_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NStructure::updateRst(
			ListPlnrQDsnHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NStructure::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NStructure_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NStructure::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NStructure_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NStructure_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NStructure** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnHk1NStructure_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NStructure& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnHk1NStructure_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

