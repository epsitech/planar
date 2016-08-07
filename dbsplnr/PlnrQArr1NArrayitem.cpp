/**
  * \file PlnrQArr1NArrayitem.cpp
  * Dbs and XML wrapper for table TblPlnrQArr1NArrayitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArr1NArrayitem.h"

/******************************************************************************
 class PlnrQArr1NArrayitem
 ******************************************************************************/

PlnrQArr1NArrayitem::PlnrQArr1NArrayitem(
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

void PlnrQArr1NArrayitem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQArr1NArrayitem";

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
 class ListPlnrQArr1NArrayitem
 ******************************************************************************/

ListPlnrQArr1NArrayitem::ListPlnrQArr1NArrayitem() {
};

ListPlnrQArr1NArrayitem::ListPlnrQArr1NArrayitem(
			const ListPlnrQArr1NArrayitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArr1NArrayitem(*(src.nodes[i]));
};

ListPlnrQArr1NArrayitem::~ListPlnrQArr1NArrayitem() {
	clear();
};

void ListPlnrQArr1NArrayitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQArr1NArrayitem::size() const {
	return(nodes.size());
};

void ListPlnrQArr1NArrayitem::append(
			PlnrQArr1NArrayitem* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQArr1NArrayitem& ListPlnrQArr1NArrayitem::operator=(
			const ListPlnrQArr1NArrayitem& src
		) {
	PlnrQArr1NArrayitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQArr1NArrayitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQArr1NArrayitem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQArr1NArrayitem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQArr1NArrayitem
 ******************************************************************************/

TblPlnrQArr1NArrayitem::TblPlnrQArr1NArrayitem() {
};

TblPlnrQArr1NArrayitem::~TblPlnrQArr1NArrayitem() {
};

bool TblPlnrQArr1NArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQArr1NArrayitem** rec
		) {
	return false;
};

ubigint TblPlnrQArr1NArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	return 0;
};

void TblPlnrQArr1NArrayitem::insertRec(
			PlnrQArr1NArrayitem* rec
		) {
};

ubigint TblPlnrQArr1NArrayitem::insertNewRec(
			PlnrQArr1NArrayitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQArr1NArrayitem* _rec = NULL;

	_rec = new PlnrQArr1NArrayitem(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQArr1NArrayitem::appendNewRecToRst(
			ListPlnrQArr1NArrayitem& rst
			, PlnrQArr1NArrayitem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQArr1NArrayitem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQArr1NArrayitem::insertRst(
			ListPlnrQArr1NArrayitem& rst
		) {
};

void TblPlnrQArr1NArrayitem::updateRec(
			PlnrQArr1NArrayitem* rec
		) {
};

void TblPlnrQArr1NArrayitem::updateRst(
			ListPlnrQArr1NArrayitem& rst
		) {
};

void TblPlnrQArr1NArrayitem::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQArr1NArrayitem::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQArr1NArrayitem::loadRecByQref(
			ubigint qref
			, PlnrQArr1NArrayitem** rec
		) {
	return false;
};

ubigint TblPlnrQArr1NArrayitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQArr1NArrayitem
 ******************************************************************************/

MyTblPlnrQArr1NArrayitem::MyTblPlnrQArr1NArrayitem() : TblPlnrQArr1NArrayitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQArr1NArrayitem::~MyTblPlnrQArr1NArrayitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQArr1NArrayitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQArr1NArrayitem (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQArr1NArrayitem SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQArr1NArrayitem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQArr1NArrayitem WHERE jref = ?", false);
};

bool MyTblPlnrQArr1NArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQArr1NArrayitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQArr1NArrayitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArr1NArrayitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQArr1NArrayitem();

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

ubigint MyTblPlnrQArr1NArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQArr1NArrayitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArr1NArrayitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQArr1NArrayitem();

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

void MyTblPlnrQArr1NArrayitem::insertRec(
			PlnrQArr1NArrayitem* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArr1NArrayitem / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArr1NArrayitem / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQArr1NArrayitem::insertRst(
			ListPlnrQArr1NArrayitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQArr1NArrayitem::updateRec(
			PlnrQArr1NArrayitem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArr1NArrayitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArr1NArrayitem / stmtUpdateRec)\n");
};

void MyTblPlnrQArr1NArrayitem::updateRst(
			ListPlnrQArr1NArrayitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQArr1NArrayitem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArr1NArrayitem / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArr1NArrayitem / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQArr1NArrayitem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArr1NArrayitem / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArr1NArrayitem / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQArr1NArrayitem::loadRecByQref(
			ubigint qref
			, PlnrQArr1NArrayitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQArr1NArrayitem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQArr1NArrayitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQArr1NArrayitem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQArr1NArrayitem
 ******************************************************************************/

PgTblPlnrQArr1NArrayitem::PgTblPlnrQArr1NArrayitem() : TblPlnrQArr1NArrayitem(), PgTable() {
};

PgTblPlnrQArr1NArrayitem::~PgTblPlnrQArr1NArrayitem() {
};

void PgTblPlnrQArr1NArrayitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_insertRec", "INSERT INTO TblPlnrQArr1NArrayitem (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_updateRec", "UPDATE TblPlnrQArr1NArrayitem SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_removeRecByQref", "DELETE FROM TblPlnrQArr1NArrayitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_removeRstByJref", "DELETE FROM TblPlnrQArr1NArrayitem WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQArr1NArrayitem WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArr1NArrayitem_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQArr1NArrayitem WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQArr1NArrayitem::loadRec(
			PGresult* res
			, PlnrQArr1NArrayitem** rec
		) {
	char* ptr;

	PlnrQArr1NArrayitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQArr1NArrayitem();

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

ubigint PgTblPlnrQArr1NArrayitem::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQArr1NArrayitem* rec;

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
			rec = new PlnrQArr1NArrayitem();

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

bool PgTblPlnrQArr1NArrayitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQArr1NArrayitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArr1NArrayitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQArr1NArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrQArr1NArrayitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArr1NArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQArr1NArrayitem::insertRec(
			PlnrQArr1NArrayitem* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQArr1NArrayitem_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQArr1NArrayitem::insertRst(
			ListPlnrQArr1NArrayitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQArr1NArrayitem::updateRec(
			PlnrQArr1NArrayitem* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQArr1NArrayitem_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQArr1NArrayitem::updateRst(
			ListPlnrQArr1NArrayitem& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQArr1NArrayitem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArr1NArrayitem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQArr1NArrayitem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArr1NArrayitem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArr1NArrayitem_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQArr1NArrayitem::loadRecByQref(
			ubigint qref
			, PlnrQArr1NArrayitem** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQArr1NArrayitem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQArr1NArrayitem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArr1NArrayitem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQArr1NArrayitem_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

