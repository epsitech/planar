/**
  * \file PlnrQDsnHk1NLineguide.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLineguide.h"

/******************************************************************************
 class PlnrQDsnHk1NLineguide
 ******************************************************************************/

PlnrQDsnHk1NLineguide::PlnrQDsnHk1NLineguide(
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

void PlnrQDsnHk1NLineguide::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnHk1NLineguide";

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
 class ListPlnrQDsnHk1NLineguide
 ******************************************************************************/

ListPlnrQDsnHk1NLineguide::ListPlnrQDsnHk1NLineguide() {
};

ListPlnrQDsnHk1NLineguide::ListPlnrQDsnHk1NLineguide(
			const ListPlnrQDsnHk1NLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLineguide(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLineguide::~ListPlnrQDsnHk1NLineguide() {
	clear();
};

void ListPlnrQDsnHk1NLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnHk1NLineguide::size() const {
	return(nodes.size());
};

void ListPlnrQDsnHk1NLineguide::append(
			PlnrQDsnHk1NLineguide* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnHk1NLineguide& ListPlnrQDsnHk1NLineguide::operator=(
			const ListPlnrQDsnHk1NLineguide& src
		) {
	PlnrQDsnHk1NLineguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnHk1NLineguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnHk1NLineguide::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnHk1NLineguide";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnHk1NLineguide
 ******************************************************************************/

TblPlnrQDsnHk1NLineguide::TblPlnrQDsnHk1NLineguide() {
};

TblPlnrQDsnHk1NLineguide::~TblPlnrQDsnHk1NLineguide() {
};

bool TblPlnrQDsnHk1NLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLineguide** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	return 0;
};

void TblPlnrQDsnHk1NLineguide::insertRec(
			PlnrQDsnHk1NLineguide* rec
		) {
};

ubigint TblPlnrQDsnHk1NLineguide::insertNewRec(
			PlnrQDsnHk1NLineguide** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLineguide* _rec = NULL;

	_rec = new PlnrQDsnHk1NLineguide(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnHk1NLineguide::appendNewRecToRst(
			ListPlnrQDsnHk1NLineguide& rst
			, PlnrQDsnHk1NLineguide** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLineguide* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnHk1NLineguide::insertRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
};

void TblPlnrQDsnHk1NLineguide::updateRec(
			PlnrQDsnHk1NLineguide* rec
		) {
};

void TblPlnrQDsnHk1NLineguide::updateRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
};

void TblPlnrQDsnHk1NLineguide::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnHk1NLineguide::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnHk1NLineguide::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLineguide** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLineguide::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnHk1NLineguide
 ******************************************************************************/

MyTblPlnrQDsnHk1NLineguide::MyTblPlnrQDsnHk1NLineguide() : TblPlnrQDsnHk1NLineguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnHk1NLineguide::~MyTblPlnrQDsnHk1NLineguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnHk1NLineguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnHk1NLineguide (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnHk1NLineguide SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnHk1NLineguide WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnHk1NLineguide WHERE jref = ?", false);
};

bool MyTblPlnrQDsnHk1NLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLineguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnHk1NLineguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLineguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnHk1NLineguide();

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

ubigint MyTblPlnrQDsnHk1NLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnHk1NLineguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLineguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnHk1NLineguide();

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

void MyTblPlnrQDsnHk1NLineguide::insertRec(
			PlnrQDsnHk1NLineguide* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLineguide / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLineguide / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnHk1NLineguide::insertRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLineguide::updateRec(
			PlnrQDsnHk1NLineguide* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLineguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLineguide / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnHk1NLineguide::updateRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLineguide::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLineguide / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLineguide / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnHk1NLineguide::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLineguide / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLineguide / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnHk1NLineguide::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLineguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnHk1NLineguide WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnHk1NLineguide::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnHk1NLineguide WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnHk1NLineguide
 ******************************************************************************/

PgTblPlnrQDsnHk1NLineguide::PgTblPlnrQDsnHk1NLineguide() : TblPlnrQDsnHk1NLineguide(), PgTable() {
};

PgTblPlnrQDsnHk1NLineguide::~PgTblPlnrQDsnHk1NLineguide() {
};

void PgTblPlnrQDsnHk1NLineguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_insertRec", "INSERT INTO TblPlnrQDsnHk1NLineguide (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_updateRec", "UPDATE TblPlnrQDsnHk1NLineguide SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_removeRecByQref", "DELETE FROM TblPlnrQDsnHk1NLineguide WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_removeRstByJref", "DELETE FROM TblPlnrQDsnHk1NLineguide WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NLineguide WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLineguide_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnHk1NLineguide WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnHk1NLineguide::loadRec(
			PGresult* res
			, PlnrQDsnHk1NLineguide** rec
		) {
	char* ptr;

	PlnrQDsnHk1NLineguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnHk1NLineguide();

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

ubigint PgTblPlnrQDsnHk1NLineguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnHk1NLineguide* rec;

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
			rec = new PlnrQDsnHk1NLineguide();

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

bool PgTblPlnrQDsnHk1NLineguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnHk1NLineguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLineguide::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnHk1NLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLineguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnHk1NLineguide::insertRec(
			PlnrQDsnHk1NLineguide* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLineguide_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLineguide::insertRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLineguide::updateRec(
			PlnrQDsnHk1NLineguide* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLineguide_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLineguide::updateRst(
			ListPlnrQDsnHk1NLineguide& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLineguide::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLineguide_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLineguide::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLineguide_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLineguide_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnHk1NLineguide::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLineguide** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnHk1NLineguide_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnHk1NLineguide::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLineguide& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnHk1NLineguide_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

