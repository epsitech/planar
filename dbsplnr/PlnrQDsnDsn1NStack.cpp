/**
  * \file PlnrQDsnDsn1NStack.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnDsn1NStack.h"

/******************************************************************************
 class PlnrQDsnDsn1NStack
 ******************************************************************************/

PlnrQDsnDsn1NStack::PlnrQDsnDsn1NStack(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->dsnNum = dsnNum;
};

void PlnrQDsnDsn1NStack::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnDsn1NStack";

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
 class ListPlnrQDsnDsn1NStack
 ******************************************************************************/

ListPlnrQDsnDsn1NStack::ListPlnrQDsnDsn1NStack() {
};

ListPlnrQDsnDsn1NStack::ListPlnrQDsnDsn1NStack(
			const ListPlnrQDsnDsn1NStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnDsn1NStack(*(src.nodes[i]));
};

ListPlnrQDsnDsn1NStack::~ListPlnrQDsnDsn1NStack() {
	clear();
};

void ListPlnrQDsnDsn1NStack::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnDsn1NStack::size() const {
	return(nodes.size());
};

void ListPlnrQDsnDsn1NStack::append(
			PlnrQDsnDsn1NStack* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnDsn1NStack& ListPlnrQDsnDsn1NStack::operator=(
			const ListPlnrQDsnDsn1NStack& src
		) {
	PlnrQDsnDsn1NStack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnDsn1NStack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnDsn1NStack::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnDsn1NStack";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnDsn1NStack
 ******************************************************************************/

TblPlnrQDsnDsn1NStack::TblPlnrQDsnDsn1NStack() {
};

TblPlnrQDsnDsn1NStack::~TblPlnrQDsnDsn1NStack() {
};

bool TblPlnrQDsnDsn1NStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NStack** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	return 0;
};

void TblPlnrQDsnDsn1NStack::insertRec(
			PlnrQDsnDsn1NStack* rec
		) {
};

ubigint TblPlnrQDsnDsn1NStack::insertNewRec(
			PlnrQDsnDsn1NStack** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NStack* _rec = NULL;

	_rec = new PlnrQDsnDsn1NStack(0, jref, jnum, ref, stubRef, dsnNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnDsn1NStack::appendNewRecToRst(
			ListPlnrQDsnDsn1NStack& rst
			, PlnrQDsnDsn1NStack** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint dsnNum
		) {
	ubigint retval = 0;
	PlnrQDsnDsn1NStack* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, dsnNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnDsn1NStack::insertRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
};

void TblPlnrQDsnDsn1NStack::updateRec(
			PlnrQDsnDsn1NStack* rec
		) {
};

void TblPlnrQDsnDsn1NStack::updateRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
};

void TblPlnrQDsnDsn1NStack::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnDsn1NStack::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnDsn1NStack::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NStack** rec
		) {
	return false;
};

ubigint TblPlnrQDsnDsn1NStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnDsn1NStack
 ******************************************************************************/

MyTblPlnrQDsnDsn1NStack::MyTblPlnrQDsnDsn1NStack() : TblPlnrQDsnDsn1NStack(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnDsn1NStack::~MyTblPlnrQDsnDsn1NStack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnDsn1NStack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnDsn1NStack (jref, jnum, ref, dsnNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnDsn1NStack SET jref = ?, jnum = ?, ref = ?, dsnNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnDsn1NStack WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnDsn1NStack WHERE jref = ?", false);
};

bool MyTblPlnrQDsnDsn1NStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NStack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnDsn1NStack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NStack / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnDsn1NStack();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->dsnNum = atol((char*) dbrow[4]); else _rec->dsnNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDsnDsn1NStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnDsn1NStack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnDsn1NStack / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnDsn1NStack();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->dsnNum = atol((char*) dbrow[4]); else rec->dsnNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDsnDsn1NStack::insertRec(
			PlnrQDsnDsn1NStack* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NStack / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NStack / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnDsn1NStack::insertRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NStack::updateRec(
			PlnrQDsnDsn1NStack* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->dsnNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NStack / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NStack / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnDsn1NStack::updateRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnDsn1NStack::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NStack / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NStack / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnDsn1NStack::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnDsn1NStack / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnDsn1NStack / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnDsn1NStack::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NStack** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnDsn1NStack WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnDsn1NStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnDsn1NStack WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnDsn1NStack
 ******************************************************************************/

PgTblPlnrQDsnDsn1NStack::PgTblPlnrQDsnDsn1NStack() : TblPlnrQDsnDsn1NStack(), PgTable() {
};

PgTblPlnrQDsnDsn1NStack::~PgTblPlnrQDsnDsn1NStack() {
};

void PgTblPlnrQDsnDsn1NStack::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_insertRec", "INSERT INTO TblPlnrQDsnDsn1NStack (jref, jnum, ref, dsnNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_updateRec", "UPDATE TblPlnrQDsnDsn1NStack SET jref = $1, jnum = $2, ref = $3, dsnNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_removeRecByQref", "DELETE FROM TblPlnrQDsnDsn1NStack WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_removeRstByJref", "DELETE FROM TblPlnrQDsnDsn1NStack WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_loadRecByQref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NStack WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnDsn1NStack_loadRstByJref", "SELECT qref, jref, jnum, ref, dsnNum FROM TblPlnrQDsnDsn1NStack WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnDsn1NStack::loadRec(
			PGresult* res
			, PlnrQDsnDsn1NStack** rec
		) {
	char* ptr;

	PlnrQDsnDsn1NStack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnDsn1NStack();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->dsnNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDsnDsn1NStack::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnDsn1NStack* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnnum")
		};

		while (numread < numrow) {
			rec = new PlnrQDsnDsn1NStack();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->dsnNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDsnDsn1NStack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnDsn1NStack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NStack::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnDsn1NStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnDsn1NStack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnDsn1NStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnDsn1NStack::insertRec(
			PlnrQDsnDsn1NStack* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NStack_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NStack::insertRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NStack::updateRec(
			PlnrQDsnDsn1NStack* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_dsnNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NStack_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NStack::updateRst(
			ListPlnrQDsnDsn1NStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnDsn1NStack::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NStack_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnDsn1NStack::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnDsn1NStack_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnDsn1NStack_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnDsn1NStack::loadRecByQref(
			ubigint qref
			, PlnrQDsnDsn1NStack** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnDsn1NStack_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnDsn1NStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnDsn1NStack& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnDsn1NStack_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

