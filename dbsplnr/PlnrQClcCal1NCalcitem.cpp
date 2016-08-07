/**
  * \file PlnrQClcCal1NCalcitem.cpp
  * Dbs and XML wrapper for table TblPlnrQClcCal1NCalcitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcCal1NCalcitem.h"

/******************************************************************************
 class PlnrQClcCal1NCalcitem
 ******************************************************************************/

PlnrQClcCal1NCalcitem::PlnrQClcCal1NCalcitem(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint calNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->calNum = calNum;
};

void PlnrQClcCal1NCalcitem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcCal1NCalcitem";

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
 class ListPlnrQClcCal1NCalcitem
 ******************************************************************************/

ListPlnrQClcCal1NCalcitem::ListPlnrQClcCal1NCalcitem() {
};

ListPlnrQClcCal1NCalcitem::ListPlnrQClcCal1NCalcitem(
			const ListPlnrQClcCal1NCalcitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcCal1NCalcitem(*(src.nodes[i]));
};

ListPlnrQClcCal1NCalcitem::~ListPlnrQClcCal1NCalcitem() {
	clear();
};

void ListPlnrQClcCal1NCalcitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcCal1NCalcitem::size() const {
	return(nodes.size());
};

void ListPlnrQClcCal1NCalcitem::append(
			PlnrQClcCal1NCalcitem* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcCal1NCalcitem& ListPlnrQClcCal1NCalcitem::operator=(
			const ListPlnrQClcCal1NCalcitem& src
		) {
	PlnrQClcCal1NCalcitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcCal1NCalcitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcCal1NCalcitem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcCal1NCalcitem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcCal1NCalcitem
 ******************************************************************************/

TblPlnrQClcCal1NCalcitem::TblPlnrQClcCal1NCalcitem() {
};

TblPlnrQClcCal1NCalcitem::~TblPlnrQClcCal1NCalcitem() {
};

bool TblPlnrQClcCal1NCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcCal1NCalcitem** rec
		) {
	return false;
};

ubigint TblPlnrQClcCal1NCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	return 0;
};

void TblPlnrQClcCal1NCalcitem::insertRec(
			PlnrQClcCal1NCalcitem* rec
		) {
};

ubigint TblPlnrQClcCal1NCalcitem::insertNewRec(
			PlnrQClcCal1NCalcitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint calNum
		) {
	ubigint retval = 0;
	PlnrQClcCal1NCalcitem* _rec = NULL;

	_rec = new PlnrQClcCal1NCalcitem(0, jref, jnum, ref, stubRef, calNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcCal1NCalcitem::appendNewRecToRst(
			ListPlnrQClcCal1NCalcitem& rst
			, PlnrQClcCal1NCalcitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint calNum
		) {
	ubigint retval = 0;
	PlnrQClcCal1NCalcitem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, calNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcCal1NCalcitem::insertRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
};

void TblPlnrQClcCal1NCalcitem::updateRec(
			PlnrQClcCal1NCalcitem* rec
		) {
};

void TblPlnrQClcCal1NCalcitem::updateRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
};

void TblPlnrQClcCal1NCalcitem::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcCal1NCalcitem::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcCal1NCalcitem::loadRecByQref(
			ubigint qref
			, PlnrQClcCal1NCalcitem** rec
		) {
	return false;
};

ubigint TblPlnrQClcCal1NCalcitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcCal1NCalcitem
 ******************************************************************************/

MyTblPlnrQClcCal1NCalcitem::MyTblPlnrQClcCal1NCalcitem() : TblPlnrQClcCal1NCalcitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcCal1NCalcitem::~MyTblPlnrQClcCal1NCalcitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcCal1NCalcitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcCal1NCalcitem (jref, jnum, ref, calNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcCal1NCalcitem SET jref = ?, jnum = ?, ref = ?, calNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcCal1NCalcitem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcCal1NCalcitem WHERE jref = ?", false);
};

bool MyTblPlnrQClcCal1NCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcCal1NCalcitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcCal1NCalcitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcCal1NCalcitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcCal1NCalcitem();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->calNum = atol((char*) dbrow[4]); else _rec->calNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQClcCal1NCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcCal1NCalcitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcCal1NCalcitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcCal1NCalcitem();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->calNum = atol((char*) dbrow[4]); else rec->calNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQClcCal1NCalcitem::insertRec(
			PlnrQClcCal1NCalcitem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->calNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcCal1NCalcitem / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcCal1NCalcitem / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcCal1NCalcitem::insertRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcCal1NCalcitem::updateRec(
			PlnrQClcCal1NCalcitem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->calNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcCal1NCalcitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcCal1NCalcitem / stmtUpdateRec)\n");
};

void MyTblPlnrQClcCal1NCalcitem::updateRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcCal1NCalcitem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcCal1NCalcitem / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcCal1NCalcitem / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcCal1NCalcitem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcCal1NCalcitem / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcCal1NCalcitem / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcCal1NCalcitem::loadRecByQref(
			ubigint qref
			, PlnrQClcCal1NCalcitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcCal1NCalcitem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcCal1NCalcitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcCal1NCalcitem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcCal1NCalcitem
 ******************************************************************************/

PgTblPlnrQClcCal1NCalcitem::PgTblPlnrQClcCal1NCalcitem() : TblPlnrQClcCal1NCalcitem(), PgTable() {
};

PgTblPlnrQClcCal1NCalcitem::~PgTblPlnrQClcCal1NCalcitem() {
};

void PgTblPlnrQClcCal1NCalcitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_insertRec", "INSERT INTO TblPlnrQClcCal1NCalcitem (jref, jnum, ref, calNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_updateRec", "UPDATE TblPlnrQClcCal1NCalcitem SET jref = $1, jnum = $2, ref = $3, calNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_removeRecByQref", "DELETE FROM TblPlnrQClcCal1NCalcitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_removeRstByJref", "DELETE FROM TblPlnrQClcCal1NCalcitem WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_loadRecByQref", "SELECT qref, jref, jnum, ref, calNum FROM TblPlnrQClcCal1NCalcitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcCal1NCalcitem_loadRstByJref", "SELECT qref, jref, jnum, ref, calNum FROM TblPlnrQClcCal1NCalcitem WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcCal1NCalcitem::loadRec(
			PGresult* res
			, PlnrQClcCal1NCalcitem** rec
		) {
	char* ptr;

	PlnrQClcCal1NCalcitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcCal1NCalcitem();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "calnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->calNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQClcCal1NCalcitem::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcCal1NCalcitem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "calnum")
		};

		while (numread < numrow) {
			rec = new PlnrQClcCal1NCalcitem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->calNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQClcCal1NCalcitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcCal1NCalcitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcCal1NCalcitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcCal1NCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcCal1NCalcitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcCal1NCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcCal1NCalcitem::insertRec(
			PlnrQClcCal1NCalcitem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _calNum = htonl(rec->calNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_calNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClcCal1NCalcitem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcCal1NCalcitem::insertRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcCal1NCalcitem::updateRec(
			PlnrQClcCal1NCalcitem* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _calNum = htonl(rec->calNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_calNum,
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

	res = PQexecPrepared(dbs, "TblPlnrQClcCal1NCalcitem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcCal1NCalcitem::updateRst(
			ListPlnrQClcCal1NCalcitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcCal1NCalcitem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcCal1NCalcitem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcCal1NCalcitem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcCal1NCalcitem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcCal1NCalcitem_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcCal1NCalcitem::loadRecByQref(
			ubigint qref
			, PlnrQClcCal1NCalcitem** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcCal1NCalcitem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcCal1NCalcitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcCal1NCalcitem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcCal1NCalcitem_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

