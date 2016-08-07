/**
  * \file PlnrQDsnHk1NLayer.cpp
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDsnHk1NLayer.h"

/******************************************************************************
 class PlnrQDsnHk1NLayer
 ******************************************************************************/

PlnrQDsnHk1NLayer::PlnrQDsnHk1NLayer(
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

void PlnrQDsnHk1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDsnHk1NLayer";

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
 class ListPlnrQDsnHk1NLayer
 ******************************************************************************/

ListPlnrQDsnHk1NLayer::ListPlnrQDsnHk1NLayer() {
};

ListPlnrQDsnHk1NLayer::ListPlnrQDsnHk1NLayer(
			const ListPlnrQDsnHk1NLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDsnHk1NLayer(*(src.nodes[i]));
};

ListPlnrQDsnHk1NLayer::~ListPlnrQDsnHk1NLayer() {
	clear();
};

void ListPlnrQDsnHk1NLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDsnHk1NLayer::size() const {
	return(nodes.size());
};

void ListPlnrQDsnHk1NLayer::append(
			PlnrQDsnHk1NLayer* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDsnHk1NLayer& ListPlnrQDsnHk1NLayer::operator=(
			const ListPlnrQDsnHk1NLayer& src
		) {
	PlnrQDsnHk1NLayer* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDsnHk1NLayer(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDsnHk1NLayer::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDsnHk1NLayer";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDsnHk1NLayer
 ******************************************************************************/

TblPlnrQDsnHk1NLayer::TblPlnrQDsnHk1NLayer() {
};

TblPlnrQDsnHk1NLayer::~TblPlnrQDsnHk1NLayer() {
};

bool TblPlnrQDsnHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	return 0;
};

void TblPlnrQDsnHk1NLayer::insertRec(
			PlnrQDsnHk1NLayer* rec
		) {
};

ubigint TblPlnrQDsnHk1NLayer::insertNewRec(
			PlnrQDsnHk1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLayer* _rec = NULL;

	_rec = new PlnrQDsnHk1NLayer(0, jref, jnum, ref, stubRef, hkNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDsnHk1NLayer::appendNewRecToRst(
			ListPlnrQDsnHk1NLayer& rst
			, PlnrQDsnHk1NLayer** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint hkNum
		) {
	ubigint retval = 0;
	PlnrQDsnHk1NLayer* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, hkNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDsnHk1NLayer::insertRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
};

void TblPlnrQDsnHk1NLayer::updateRec(
			PlnrQDsnHk1NLayer* rec
		) {
};

void TblPlnrQDsnHk1NLayer::updateRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
};

void TblPlnrQDsnHk1NLayer::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDsnHk1NLayer::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDsnHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLayer** rec
		) {
	return false;
};

ubigint TblPlnrQDsnHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDsnHk1NLayer
 ******************************************************************************/

MyTblPlnrQDsnHk1NLayer::MyTblPlnrQDsnHk1NLayer() : TblPlnrQDsnHk1NLayer(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDsnHk1NLayer::~MyTblPlnrQDsnHk1NLayer() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDsnHk1NLayer::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDsnHk1NLayer (jref, jnum, ref, hkNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDsnHk1NLayer SET jref = ?, jnum = ?, ref = ?, hkNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDsnHk1NLayer WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDsnHk1NLayer WHERE jref = ?", false);
};

bool MyTblPlnrQDsnHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLayer** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDsnHk1NLayer* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLayer / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDsnHk1NLayer();

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

ubigint MyTblPlnrQDsnHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDsnHk1NLayer* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDsnHk1NLayer / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDsnHk1NLayer();

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

void MyTblPlnrQDsnHk1NLayer::insertRec(
			PlnrQDsnHk1NLayer* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLayer / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLayer / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDsnHk1NLayer::insertRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLayer::updateRec(
			PlnrQDsnHk1NLayer* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLayer / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLayer / stmtUpdateRec)\n");
};

void MyTblPlnrQDsnHk1NLayer::updateRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDsnHk1NLayer::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLayer / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLayer / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDsnHk1NLayer::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDsnHk1NLayer / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDsnHk1NLayer / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDsnHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLayer** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDsnHk1NLayer WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDsnHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDsnHk1NLayer WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDsnHk1NLayer
 ******************************************************************************/

PgTblPlnrQDsnHk1NLayer::PgTblPlnrQDsnHk1NLayer() : TblPlnrQDsnHk1NLayer(), PgTable() {
};

PgTblPlnrQDsnHk1NLayer::~PgTblPlnrQDsnHk1NLayer() {
};

void PgTblPlnrQDsnHk1NLayer::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_insertRec", "INSERT INTO TblPlnrQDsnHk1NLayer (jref, jnum, ref, hkNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_updateRec", "UPDATE TblPlnrQDsnHk1NLayer SET jref = $1, jnum = $2, ref = $3, hkNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_removeRecByQref", "DELETE FROM TblPlnrQDsnHk1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_removeRstByJref", "DELETE FROM TblPlnrQDsnHk1NLayer WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_loadRecByQref", "SELECT qref, jref, jnum, ref, hkNum FROM TblPlnrQDsnHk1NLayer WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDsnHk1NLayer_loadRstByJref", "SELECT qref, jref, jnum, ref, hkNum FROM TblPlnrQDsnHk1NLayer WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDsnHk1NLayer::loadRec(
			PGresult* res
			, PlnrQDsnHk1NLayer** rec
		) {
	char* ptr;

	PlnrQDsnHk1NLayer* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDsnHk1NLayer();

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

ubigint PgTblPlnrQDsnHk1NLayer::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDsnHk1NLayer* rec;

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
			rec = new PlnrQDsnHk1NLayer();

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

bool PgTblPlnrQDsnHk1NLayer::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDsnHk1NLayer** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLayer::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDsnHk1NLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrQDsnHk1NLayer** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDsnHk1NLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDsnHk1NLayer::insertRec(
			PlnrQDsnHk1NLayer* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLayer_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLayer::insertRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLayer::updateRec(
			PlnrQDsnHk1NLayer* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLayer_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLayer::updateRst(
			ListPlnrQDsnHk1NLayer& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDsnHk1NLayer::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLayer_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDsnHk1NLayer::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDsnHk1NLayer_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDsnHk1NLayer_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDsnHk1NLayer::loadRecByQref(
			ubigint qref
			, PlnrQDsnHk1NLayer** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDsnHk1NLayer_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDsnHk1NLayer::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDsnHk1NLayer& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDsnHk1NLayer_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

