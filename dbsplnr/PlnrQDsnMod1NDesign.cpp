/**
  * \file PlnrQDsnMod1NDesign.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnMod1NDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnMod1NDesign.h"

/******************************************************************************
 class PlnrQDsnMod1NDesign
 ******************************************************************************/

PlnrQDsnMod1NDesign::PlnrQDsnMod1NDesign(
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

void PlnrQDsnMod1NDesign::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnMod1NDesign";

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
 class ListPlnrQDsnMod1NDesign
 ******************************************************************************/

ListPlnrQDsnMod1NDesign::ListPlnrQDsnMod1NDesign() {
};

ListPlnrQDsnMod1NDesign::ListPlnrQDsnMod1NDesign(
			const ListPlnrQDsnMod1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnMod1NDesign(*(src.nodes[i]));
};

ListPlnrQDsnMod1NDesign::~ListPlnrQDsnMod1NDesign() {
	clear();
};

void ListPlnrQDsnMod1NDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnMod1NDesign::size() const {
	return(nodes.size());
};

void ListPlnrQDsnMod1NDesign::append(
			PlnrQDsnMod1NDesign* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnMod1NDesign& ListPlnrQDsnMod1NDesign::operator=(
			const ListPlnrQDsnMod1NDesign& src
		) {
	PlnrQDsnMod1NDesign* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnMod1NDesign(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnMod1NDesign::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnMod1NDesign";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnMod1NDesign
 ******************************************************************************/

TblPlnrQDsnMod1NDesign::TblPlnrQDsnMod1NDesign() {
};

TblPlnrQDsnMod1NDesign::~TblPlnrQDsnMod1NDesign() {
};

bool TblPlnrQDsnMod1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnMod1NDesign** rec
		) {
	return false;
};

ubigint TblPlnrQDsnMod1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	return 0;
};

void TblPlnrQDsnMod1NDesign::insertRec(
			PlnrQDsnMod1NDesign* rec
		) {
};

ubigint TblPlnrQDsnMod1NDesign::insertNewRec(
			PlnrQDsnMod1NDesign** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnMod1NDesign* _rec = NULL;

	_rec = new PlnrQDsnMod1NDesign(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnMod1NDesign::appendNewRecToRst(
			ListPlnrQDsnMod1NDesign& rst
			, PlnrQDsnMod1NDesign** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnMod1NDesign* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnMod1NDesign::insertRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
};

void TblPlnrQDsnMod1NDesign::updateRec(
			PlnrQDsnMod1NDesign* rec
		) {
};

void TblPlnrQDsnMod1NDesign::updateRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
};

void TblPlnrQDsnMod1NDesign::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnMod1NDesign::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnMod1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnMod1NDesign** rec
		) {
	return false;
};

ubigint TblPlnrQDsnMod1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnMod1NDesign
 ******************************************************************************/

MyTblPlnrQDsnMod1NDesign::MyTblPlnrQDsnMod1NDesign() : TblPlnrQDsnMod1NDesign(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnMod1NDesign::~MyTblPlnrQDsnMod1NDesign() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnMod1NDesign::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnMod1NDesign (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnMod1NDesign SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnMod1NDesign WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnMod1NDesign WHERE jref = ?", false);
};

bool MyTblPlnrQDsnMod1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnMod1NDesign** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnMod1NDesign* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnMod1NDesign / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnMod1NDesign();

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

ubigint MyTblPlnrQDsnMod1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnMod1NDesign* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnMod1NDesign / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnMod1NDesign();

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

void MyTblPlnrQDsnMod1NDesign::insertRec(
			PlnrQDsnMod1NDesign* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnMod1NDesign / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnMod1NDesign / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnMod1NDesign::insertRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnMod1NDesign::updateRec(
			PlnrQDsnMod1NDesign* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnMod1NDesign / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnMod1NDesign / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnMod1NDesign::updateRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnMod1NDesign::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnMod1NDesign / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnMod1NDesign / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnMod1NDesign::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnMod1NDesign / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnMod1NDesign / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnMod1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnMod1NDesign** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnMod1NDesign WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnMod1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnMod1NDesign WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnMod1NDesign
 ******************************************************************************/

PgTblPlnrQDsnMod1NDesign::PgTblPlnrQDsnMod1NDesign() : TblPlnrQDsnMod1NDesign(), PgTable() {
};

PgTblPlnrQDsnMod1NDesign::~PgTblPlnrQDsnMod1NDesign() {
};

void PgTblPlnrQDsnMod1NDesign::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_insertRec", "INSERT INTO TblPlnrQDsnMod1NDesign (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_updateRec", "UPDATE TblPlnrQDsnMod1NDesign SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_removeRecByQref", "DELETE FROM TblPlnrQDsnMod1NDesign WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_removeRstByJref", "DELETE FROM TblPlnrQDsnMod1NDesign WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnMod1NDesign WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnMod1NDesign_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnMod1NDesign WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnMod1NDesign::loadRec(
			PGresult* res
			, PlnrQDsnMod1NDesign** rec
		) {
	char* ptr;

	PlnrQDsnMod1NDesign* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnMod1NDesign();

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

ubigint PgTblPlnrQDsnMod1NDesign::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnMod1NDesign* rec;

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
			rec = new PlnrQDsnMod1NDesign();

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

bool PgTblPlnrQDsnMod1NDesign::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnMod1NDesign** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnMod1NDesign::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnMod1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnMod1NDesign** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnMod1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnMod1NDesign::insertRec(
			PlnrQDsnMod1NDesign* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnMod1NDesign_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnMod1NDesign::insertRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnMod1NDesign::updateRec(
			PlnrQDsnMod1NDesign* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnMod1NDesign_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnMod1NDesign::updateRst(
			ListPlnrQDsnMod1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnMod1NDesign::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnMod1NDesign_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnMod1NDesign::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnMod1NDesign_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnMod1NDesign_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnMod1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnMod1NDesign** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnMod1NDesign_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnMod1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnMod1NDesign& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnMod1NDesign_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

