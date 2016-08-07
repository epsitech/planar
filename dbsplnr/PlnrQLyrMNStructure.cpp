/**
  * \file PlnrQLyrMNStructure.cpp
  * Dbs and XML wrapper for table TblPlnrQLyrMNStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQLyrMNStructure.h"

/******************************************************************************
 class PlnrQLyrMNStructure
 ******************************************************************************/

PlnrQLyrMNStructure::PlnrQLyrMNStructure(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
};

void PlnrQLyrMNStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQLyrMNStructure";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
	} else {
		writeString(wr, "stubMref", stubMref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQLyrMNStructure
 ******************************************************************************/

ListPlnrQLyrMNStructure::ListPlnrQLyrMNStructure() {
};

ListPlnrQLyrMNStructure::ListPlnrQLyrMNStructure(
			const ListPlnrQLyrMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQLyrMNStructure(*(src.nodes[i]));
};

ListPlnrQLyrMNStructure::~ListPlnrQLyrMNStructure() {
	clear();
};

void ListPlnrQLyrMNStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQLyrMNStructure::size() const {
	return(nodes.size());
};

void ListPlnrQLyrMNStructure::append(
			PlnrQLyrMNStructure* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQLyrMNStructure& ListPlnrQLyrMNStructure::operator=(
			const ListPlnrQLyrMNStructure& src
		) {
	PlnrQLyrMNStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQLyrMNStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQLyrMNStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQLyrMNStructure";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQLyrMNStructure
 ******************************************************************************/

TblPlnrQLyrMNStructure::TblPlnrQLyrMNStructure() {
};

TblPlnrQLyrMNStructure::~TblPlnrQLyrMNStructure() {
};

bool TblPlnrQLyrMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrMNStructure** rec
		) {
	return false;
};

ubigint TblPlnrQLyrMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	return 0;
};

void TblPlnrQLyrMNStructure::insertRec(
			PlnrQLyrMNStructure* rec
		) {
};

ubigint TblPlnrQLyrMNStructure::insertNewRec(
			PlnrQLyrMNStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	PlnrQLyrMNStructure* _rec = NULL;

	_rec = new PlnrQLyrMNStructure(0, jref, jnum, mref, stubMref, ref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQLyrMNStructure::appendNewRecToRst(
			ListPlnrQLyrMNStructure& rst
			, PlnrQLyrMNStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
		) {
	ubigint retval = 0;
	PlnrQLyrMNStructure* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQLyrMNStructure::insertRst(
			ListPlnrQLyrMNStructure& rst
		) {
};

void TblPlnrQLyrMNStructure::updateRec(
			PlnrQLyrMNStructure* rec
		) {
};

void TblPlnrQLyrMNStructure::updateRst(
			ListPlnrQLyrMNStructure& rst
		) {
};

void TblPlnrQLyrMNStructure::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQLyrMNStructure::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQLyrMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQLyrMNStructure** rec
		) {
	return false;
};

ubigint TblPlnrQLyrMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQLyrMNStructure
 ******************************************************************************/

MyTblPlnrQLyrMNStructure::MyTblPlnrQLyrMNStructure() : TblPlnrQLyrMNStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQLyrMNStructure::~MyTblPlnrQLyrMNStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQLyrMNStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQLyrMNStructure (jref, jnum, mref, ref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQLyrMNStructure SET jref = ?, jnum = ?, mref = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQLyrMNStructure WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQLyrMNStructure WHERE jref = ?", false);
};

bool MyTblPlnrQLyrMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrMNStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQLyrMNStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyrMNStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQLyrMNStructure();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQLyrMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQLyrMNStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQLyrMNStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQLyrMNStructure();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQLyrMNStructure::insertRec(
			PlnrQLyrMNStructure* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrMNStructure / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrMNStructure / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQLyrMNStructure::insertRst(
			ListPlnrQLyrMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQLyrMNStructure::updateRec(
			PlnrQLyrMNStructure* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrMNStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrMNStructure / stmtUpdateRec)\n");
};

void MyTblPlnrQLyrMNStructure::updateRst(
			ListPlnrQLyrMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQLyrMNStructure::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrMNStructure / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrMNStructure / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQLyrMNStructure::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQLyrMNStructure / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQLyrMNStructure / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQLyrMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQLyrMNStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQLyrMNStructure WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQLyrMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQLyrMNStructure WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQLyrMNStructure
 ******************************************************************************/

PgTblPlnrQLyrMNStructure::PgTblPlnrQLyrMNStructure() : TblPlnrQLyrMNStructure(), PgTable() {
};

PgTblPlnrQLyrMNStructure::~PgTblPlnrQLyrMNStructure() {
};

void PgTblPlnrQLyrMNStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_insertRec", "INSERT INTO TblPlnrQLyrMNStructure (jref, jnum, mref, ref) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_updateRec", "UPDATE TblPlnrQLyrMNStructure SET jref = $1, jnum = $2, mref = $3, ref = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_removeRecByQref", "DELETE FROM TblPlnrQLyrMNStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_removeRstByJref", "DELETE FROM TblPlnrQLyrMNStructure WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_loadRecByQref", "SELECT qref, jref, jnum, mref, ref FROM TblPlnrQLyrMNStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQLyrMNStructure_loadRstByJref", "SELECT qref, jref, jnum, mref, ref FROM TblPlnrQLyrMNStructure WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQLyrMNStructure::loadRec(
			PGresult* res
			, PlnrQLyrMNStructure** rec
		) {
	char* ptr;

	PlnrQLyrMNStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQLyrMNStructure();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQLyrMNStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQLyrMNStructure* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQLyrMNStructure();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQLyrMNStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQLyrMNStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyrMNStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQLyrMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQLyrMNStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQLyrMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQLyrMNStructure::insertRec(
			PlnrQLyrMNStructure* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQLyrMNStructure_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQLyrMNStructure::insertRst(
			ListPlnrQLyrMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQLyrMNStructure::updateRec(
			PlnrQLyrMNStructure* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQLyrMNStructure_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQLyrMNStructure::updateRst(
			ListPlnrQLyrMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQLyrMNStructure::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyrMNStructure_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQLyrMNStructure::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQLyrMNStructure_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQLyrMNStructure_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQLyrMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQLyrMNStructure** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQLyrMNStructure_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQLyrMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQLyrMNStructure& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQLyrMNStructure_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

