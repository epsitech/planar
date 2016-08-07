/**
  * \file PlnrQStkHk1NLayer.cpp
  * Dbs and XML wrapper for table TblPlnrQStkHk1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkHk1NLayer.h"

/******************************************************************************
 class PlnrQStkHk1NLayer
 ******************************************************************************/

PlnrQStkHk1NLayer::PlnrQStkHk1NLayer(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->hkNum = hkNum;
};

void PlnrQStkHk1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQStkHk1NLayer";

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
 class ListPlnrQStkHk1NLayer
 ******************************************************************************/

ListPlnrQStkHk1NLayer::ListPlnrQStkHk1NLayer() {
};

ListPlnrQStkHk1NLayer::ListPlnrQStkHk1NLayer(
			const ListPlnrQStkHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkHk1NLayer(*(src.nodes[i]));
};

ListPlnrQStkHk1NLayer::~ListPlnrQStkHk1NLayer() {
	clear();
};

void ListPlnrQStkHk1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQStkHk1NLayer::size() const {
	return(nodes.size());
};

void ListPlnrQStkHk1NLayer::append(
			PlnrQStkHk1NLayer* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQStkHk1NLayer& ListPlnrQStkHk1NLayer::operator=(
			const ListPlnrQStkHk1NLayer& src
		) {
	PlnrQStkHk1NLayer* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQStkHk1NLayer(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQStkHk1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQStkHk1NLayer";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQStkHk1NLayer
 ******************************************************************************/

TblPlnrQStkHk1NLayer::TblPlnrQStkHk1NLayer() {
};

TblPlnrQStkHk1NLayer::~TblPlnrQStkHk1NLayer() {
};

bool TblPlnrQStkHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQStkHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	return 0;
};

void TblPlnrQStkHk1NLayer::insertRec(
			PlnrQStkHk1NLayer* rec
		) {
};

ubigint TblPlnrQStkHk1NLayer::insertNewRec(
			PlnrQStkHk1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	PlnrQStkHk1NLayer* _rec = NULL;

	_rec = new PlnrQStkHk1NLayer(0, jref, jnum, ref, stubRef, hkNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQStkHk1NLayer::appendNewRecToRst(
			ListPlnrQStkHk1NLayer& rst
			, PlnrQStkHk1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	PlnrQStkHk1NLayer* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, hkNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQStkHk1NLayer::insertRst(
			ListPlnrQStkHk1NLayer& rst
		) {
};

void TblPlnrQStkHk1NLayer::updateRec(
			PlnrQStkHk1NLayer* rec
		) {
};

void TblPlnrQStkHk1NLayer::updateRst(
			ListPlnrQStkHk1NLayer& rst
		) {
};

void TblPlnrQStkHk1NLayer::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQStkHk1NLayer::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQStkHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQStkHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQStkHk1NLayer
 ******************************************************************************/

MyTblPlnrQStkHk1NLayer::MyTblPlnrQStkHk1NLayer() : TblPlnrQStkHk1NLayer(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQStkHk1NLayer::~MyTblPlnrQStkHk1NLayer() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQStkHk1NLayer::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQStkHk1NLayer (jref, jnum, ref, hkNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQStkHk1NLayer SET jref = ?, jnum = ?, ref = ?, hkNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQStkHk1NLayer WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQStkHk1NLayer WHERE jref = ?", false);
};

bool MyTblPlnrQStkHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLayer** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQStkHk1NLayer* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkHk1NLayer / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQStkHk1NLayer();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->hkNum = atol((char*) dbrow[4]); else _rec->hkNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQStkHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQStkHk1NLayer* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkHk1NLayer / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQStkHk1NLayer();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->hkNum = atol((char*) dbrow[4]); else rec->hkNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQStkHk1NLayer::insertRec(
			PlnrQStkHk1NLayer* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLayer / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLayer / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQStkHk1NLayer::insertRst(
			ListPlnrQStkHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQStkHk1NLayer::updateRec(
			PlnrQStkHk1NLayer* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLayer / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLayer / stmtUpdateRec)\n");
};

void MyTblPlnrQStkHk1NLayer::updateRst(
			ListPlnrQStkHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQStkHk1NLayer::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLayer / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLayer / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQStkHk1NLayer::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkHk1NLayer / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkHk1NLayer / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQStkHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLayer** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQStkHk1NLayer WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQStkHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQStkHk1NLayer WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQStkHk1NLayer
 ******************************************************************************/

PgTblPlnrQStkHk1NLayer::PgTblPlnrQStkHk1NLayer() : TblPlnrQStkHk1NLayer(), PgTable() {
};

PgTblPlnrQStkHk1NLayer::~PgTblPlnrQStkHk1NLayer() {
};

void PgTblPlnrQStkHk1NLayer::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_insertRec", "INSERT INTO TblPlnrQStkHk1NLayer (jref, jnum, ref, hkNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_updateRec", "UPDATE TblPlnrQStkHk1NLayer SET jref = $1, jnum = $2, ref = $3, hkNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_removeRecByQref", "DELETE FROM TblPlnrQStkHk1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_removeRstByJref", "DELETE FROM TblPlnrQStkHk1NLayer WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_loadRecByQref", "SELECT qref, jref, jnum, ref, hkNum FROM TblPlnrQStkHk1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkHk1NLayer_loadRstByJref", "SELECT qref, jref, jnum, ref, hkNum FROM TblPlnrQStkHk1NLayer WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQStkHk1NLayer::loadRec(
			PGresult* res
			, PlnrQStkHk1NLayer** rec
		) {
	char* ptr;

	PlnrQStkHk1NLayer* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQStkHk1NLayer();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "hknum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQStkHk1NLayer::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQStkHk1NLayer* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "hknum")
		};

		while (numread < numrow) {
			rec = new PlnrQStkHk1NLayer();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQStkHk1NLayer::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQStkHk1NLayer** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkHk1NLayer::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQStkHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkHk1NLayer** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQStkHk1NLayer::insertRec(
			PlnrQStkHk1NLayer* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkNum = htonl(rec->hkNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_hkNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLayer_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQStkHk1NLayer::insertRst(
			ListPlnrQStkHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQStkHk1NLayer::updateRec(
			PlnrQStkHk1NLayer* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_hkNum,
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLayer_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQStkHk1NLayer::updateRst(
			ListPlnrQStkHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQStkHk1NLayer::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLayer_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQStkHk1NLayer::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkHk1NLayer_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkHk1NLayer_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQStkHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQStkHk1NLayer** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQStkHk1NLayer_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQStkHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkHk1NLayer& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQStkHk1NLayer_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

