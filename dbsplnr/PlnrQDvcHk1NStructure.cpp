/**
  * \file PlnrQDvcHk1NStructure.cpp
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcHk1NStructure.h"

/******************************************************************************
 class PlnrQDvcHk1NStructure
 ******************************************************************************/

PlnrQDvcHk1NStructure::PlnrQDvcHk1NStructure(
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

void PlnrQDvcHk1NStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDvcHk1NStructure";

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
 class ListPlnrQDvcHk1NStructure
 ******************************************************************************/

ListPlnrQDvcHk1NStructure::ListPlnrQDvcHk1NStructure() {
};

ListPlnrQDvcHk1NStructure::ListPlnrQDvcHk1NStructure(
			const ListPlnrQDvcHk1NStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcHk1NStructure(*(src.nodes[i]));
};

ListPlnrQDvcHk1NStructure::~ListPlnrQDvcHk1NStructure() {
	clear();
};

void ListPlnrQDvcHk1NStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDvcHk1NStructure::size() const {
	return(nodes.size());
};

void ListPlnrQDvcHk1NStructure::append(
			PlnrQDvcHk1NStructure* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDvcHk1NStructure& ListPlnrQDvcHk1NStructure::operator=(
			const ListPlnrQDvcHk1NStructure& src
		) {
	PlnrQDvcHk1NStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDvcHk1NStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDvcHk1NStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDvcHk1NStructure";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDvcHk1NStructure
 ******************************************************************************/

TblPlnrQDvcHk1NStructure::TblPlnrQDvcHk1NStructure() {
};

TblPlnrQDvcHk1NStructure::~TblPlnrQDvcHk1NStructure() {
};

bool TblPlnrQDvcHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NStructure** rec
		) {
	return false;
};

ubigint TblPlnrQDvcHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	return 0;
};

void TblPlnrQDvcHk1NStructure::insertRec(
			PlnrQDvcHk1NStructure* rec
		) {
};

ubigint TblPlnrQDvcHk1NStructure::insertNewRec(
			PlnrQDvcHk1NStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDvcHk1NStructure* _rec = NULL;

	_rec = new PlnrQDvcHk1NStructure(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDvcHk1NStructure::appendNewRecToRst(
			ListPlnrQDvcHk1NStructure& rst
			, PlnrQDvcHk1NStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDvcHk1NStructure* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDvcHk1NStructure::insertRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
};

void TblPlnrQDvcHk1NStructure::updateRec(
			PlnrQDvcHk1NStructure* rec
		) {
};

void TblPlnrQDvcHk1NStructure::updateRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
};

void TblPlnrQDvcHk1NStructure::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDvcHk1NStructure::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDvcHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NStructure** rec
		) {
	return false;
};

ubigint TblPlnrQDvcHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDvcHk1NStructure
 ******************************************************************************/

MyTblPlnrQDvcHk1NStructure::MyTblPlnrQDvcHk1NStructure() : TblPlnrQDvcHk1NStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDvcHk1NStructure::~MyTblPlnrQDvcHk1NStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDvcHk1NStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDvcHk1NStructure (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDvcHk1NStructure SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDvcHk1NStructure WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDvcHk1NStructure WHERE jref = ?", false);
};

bool MyTblPlnrQDvcHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDvcHk1NStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcHk1NStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDvcHk1NStructure();

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

ubigint MyTblPlnrQDvcHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDvcHk1NStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcHk1NStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDvcHk1NStructure();

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

void MyTblPlnrQDvcHk1NStructure::insertRec(
			PlnrQDvcHk1NStructure* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NStructure / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NStructure / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDvcHk1NStructure::insertRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDvcHk1NStructure::updateRec(
			PlnrQDvcHk1NStructure* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NStructure / stmtUpdateRec)\n");
};

void MyTblPlnrQDvcHk1NStructure::updateRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDvcHk1NStructure::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NStructure / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NStructure / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDvcHk1NStructure::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcHk1NStructure / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcHk1NStructure / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDvcHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDvcHk1NStructure WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDvcHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDvcHk1NStructure WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDvcHk1NStructure
 ******************************************************************************/

PgTblPlnrQDvcHk1NStructure::PgTblPlnrQDvcHk1NStructure() : TblPlnrQDvcHk1NStructure(), PgTable() {
};

PgTblPlnrQDvcHk1NStructure::~PgTblPlnrQDvcHk1NStructure() {
};

void PgTblPlnrQDvcHk1NStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_insertRec", "INSERT INTO TblPlnrQDvcHk1NStructure (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_updateRec", "UPDATE TblPlnrQDvcHk1NStructure SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_removeRecByQref", "DELETE FROM TblPlnrQDvcHk1NStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_removeRstByJref", "DELETE FROM TblPlnrQDvcHk1NStructure WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDvcHk1NStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcHk1NStructure_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDvcHk1NStructure WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDvcHk1NStructure::loadRec(
			PGresult* res
			, PlnrQDvcHk1NStructure** rec
		) {
	char* ptr;

	PlnrQDvcHk1NStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDvcHk1NStructure();

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

ubigint PgTblPlnrQDvcHk1NStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDvcHk1NStructure* rec;

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
			rec = new PlnrQDvcHk1NStructure();

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

bool PgTblPlnrQDvcHk1NStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDvcHk1NStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcHk1NStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDvcHk1NStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcHk1NStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcHk1NStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDvcHk1NStructure::insertRec(
			PlnrQDvcHk1NStructure* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NStructure_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDvcHk1NStructure::insertRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDvcHk1NStructure::updateRec(
			PlnrQDvcHk1NStructure* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NStructure_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDvcHk1NStructure::updateRst(
			ListPlnrQDvcHk1NStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDvcHk1NStructure::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NStructure_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDvcHk1NStructure::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDvcHk1NStructure_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcHk1NStructure_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDvcHk1NStructure::loadRecByQref(
			ubigint qref
			, PlnrQDvcHk1NStructure** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDvcHk1NStructure_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDvcHk1NStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcHk1NStructure& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDvcHk1NStructure_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

