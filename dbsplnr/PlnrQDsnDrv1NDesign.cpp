/**
  * \file PlnrQDsnDrv1NDesign.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnDrv1NDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDrv1NDesign.h"

/******************************************************************************
 class PlnrQDsnDrv1NDesign
 ******************************************************************************/

PlnrQDsnDrv1NDesign::PlnrQDsnDrv1NDesign(
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

void PlnrQDsnDrv1NDesign::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnDrv1NDesign";

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
 class ListPlnrQDsnDrv1NDesign
 ******************************************************************************/

ListPlnrQDsnDrv1NDesign::ListPlnrQDsnDrv1NDesign() {
};

ListPlnrQDsnDrv1NDesign::ListPlnrQDsnDrv1NDesign(
			const ListPlnrQDsnDrv1NDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDrv1NDesign(*(src.nodes[i]));
};

ListPlnrQDsnDrv1NDesign::~ListPlnrQDsnDrv1NDesign() {
	clear();
};

void ListPlnrQDsnDrv1NDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnDrv1NDesign::size() const {
	return(nodes.size());
};

void ListPlnrQDsnDrv1NDesign::append(
			PlnrQDsnDrv1NDesign* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnDrv1NDesign& ListPlnrQDsnDrv1NDesign::operator=(
			const ListPlnrQDsnDrv1NDesign& src
		) {
	PlnrQDsnDrv1NDesign* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnDrv1NDesign(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnDrv1NDesign::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnDrv1NDesign";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnDrv1NDesign
 ******************************************************************************/

TblPlnrQDsnDrv1NDesign::TblPlnrQDsnDrv1NDesign() {
};

TblPlnrQDsnDrv1NDesign::~TblPlnrQDsnDrv1NDesign() {
};

bool TblPlnrQDsnDrv1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDrv1NDesign** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDrv1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	return 0;
};

void TblPlnrQDsnDrv1NDesign::insertRec(
			PlnrQDsnDrv1NDesign* rec
		) {
};

ubigint TblPlnrQDsnDrv1NDesign::insertNewRec(
			PlnrQDsnDrv1NDesign** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnDrv1NDesign* _rec = NULL;

	_rec = new PlnrQDsnDrv1NDesign(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnDrv1NDesign::appendNewRecToRst(
			ListPlnrQDsnDrv1NDesign& rst
			, PlnrQDsnDrv1NDesign** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQDsnDrv1NDesign* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnDrv1NDesign::insertRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
};

void TblPlnrQDsnDrv1NDesign::updateRec(
			PlnrQDsnDrv1NDesign* rec
		) {
};

void TblPlnrQDsnDrv1NDesign::updateRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
};

void TblPlnrQDsnDrv1NDesign::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnDrv1NDesign::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnDrv1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnDrv1NDesign** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDrv1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnDrv1NDesign
 ******************************************************************************/

MyTblPlnrQDsnDrv1NDesign::MyTblPlnrQDsnDrv1NDesign() : TblPlnrQDsnDrv1NDesign(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnDrv1NDesign::~MyTblPlnrQDsnDrv1NDesign() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnDrv1NDesign::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnDrv1NDesign (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnDrv1NDesign SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnDrv1NDesign WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnDrv1NDesign WHERE jref = ?", false);
};

bool MyTblPlnrQDsnDrv1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDrv1NDesign** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnDrv1NDesign* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDrv1NDesign / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnDrv1NDesign();

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

ubigint MyTblPlnrQDsnDrv1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnDrv1NDesign* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDrv1NDesign / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnDrv1NDesign();

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

void MyTblPlnrQDsnDrv1NDesign::insertRec(
			PlnrQDsnDrv1NDesign* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDrv1NDesign / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDrv1NDesign / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnDrv1NDesign::insertRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDrv1NDesign::updateRec(
			PlnrQDsnDrv1NDesign* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDrv1NDesign / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDrv1NDesign / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnDrv1NDesign::updateRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDrv1NDesign::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDrv1NDesign / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDrv1NDesign / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnDrv1NDesign::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDrv1NDesign / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDrv1NDesign / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnDrv1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnDrv1NDesign** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnDrv1NDesign WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnDrv1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnDrv1NDesign WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnDrv1NDesign
 ******************************************************************************/

PgTblPlnrQDsnDrv1NDesign::PgTblPlnrQDsnDrv1NDesign() : TblPlnrQDsnDrv1NDesign(), PgTable() {
};

PgTblPlnrQDsnDrv1NDesign::~PgTblPlnrQDsnDrv1NDesign() {
};

void PgTblPlnrQDsnDrv1NDesign::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_insertRec", "INSERT INTO TblPlnrQDsnDrv1NDesign (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_updateRec", "UPDATE TblPlnrQDsnDrv1NDesign SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_removeRecByQref", "DELETE FROM TblPlnrQDsnDrv1NDesign WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_removeRstByJref", "DELETE FROM TblPlnrQDsnDrv1NDesign WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnDrv1NDesign WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDrv1NDesign_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQDsnDrv1NDesign WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnDrv1NDesign::loadRec(
			PGresult* res
			, PlnrQDsnDrv1NDesign** rec
		) {
	char* ptr;

	PlnrQDsnDrv1NDesign* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnDrv1NDesign();

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

ubigint PgTblPlnrQDsnDrv1NDesign::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnDrv1NDesign* rec;

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
			rec = new PlnrQDsnDrv1NDesign();

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

bool PgTblPlnrQDsnDrv1NDesign::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnDrv1NDesign** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDrv1NDesign::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnDrv1NDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDrv1NDesign** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDrv1NDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnDrv1NDesign::insertRec(
			PlnrQDsnDrv1NDesign* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDrv1NDesign_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnDrv1NDesign::insertRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDrv1NDesign::updateRec(
			PlnrQDsnDrv1NDesign* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDrv1NDesign_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDrv1NDesign::updateRst(
			ListPlnrQDsnDrv1NDesign& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDrv1NDesign::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDrv1NDesign_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDrv1NDesign::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDrv1NDesign_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDrv1NDesign_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnDrv1NDesign::loadRecByQref(
			ubigint qref
			, PlnrQDsnDrv1NDesign** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnDrv1NDesign_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnDrv1NDesign::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDrv1NDesign& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnDrv1NDesign_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

