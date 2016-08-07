/**
  * \file PlnrLRMArcguideMVertex.cpp
  * database access for table TblPlnrLRMArcguideMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrLRMArcguideMVertex.h"

/******************************************************************************
 class PlnrLRMArcguideMVertex
 ******************************************************************************/

PlnrLRMArcguideMVertex::PlnrLRMArcguideMVertex(
			const ubigint ref
			, const uint agdIxPlnrVLat
			, const ubigint agdRefPlnrMArcguide
			, const uint agdNum
			, const ubigint refPlnrMVertex
		) {

	this->ref = ref;
	this->agdIxPlnrVLat = agdIxPlnrVLat;
	this->agdRefPlnrMArcguide = agdRefPlnrMArcguide;
	this->agdNum = agdNum;
	this->refPlnrMVertex = refPlnrMVertex;
};

bool PlnrLRMArcguideMVertex::operator==(
			const PlnrLRMArcguideMVertex& comp
		) {
	return false;
};

bool PlnrLRMArcguideMVertex::operator!=(
			const PlnrLRMArcguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrLRMArcguideMVertex
 ******************************************************************************/

ListPlnrLRMArcguideMVertex::ListPlnrLRMArcguideMVertex() {
};

ListPlnrLRMArcguideMVertex::ListPlnrLRMArcguideMVertex(
			const ListPlnrLRMArcguideMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrLRMArcguideMVertex(*(src.nodes[i]));
};

ListPlnrLRMArcguideMVertex::~ListPlnrLRMArcguideMVertex() {
	clear();
};

void ListPlnrLRMArcguideMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrLRMArcguideMVertex::size() const {
	return(nodes.size());
};

void ListPlnrLRMArcguideMVertex::append(
			PlnrLRMArcguideMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrLRMArcguideMVertex* ListPlnrLRMArcguideMVertex::operator[](
			const uint ix
		) {
	PlnrLRMArcguideMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrLRMArcguideMVertex& ListPlnrLRMArcguideMVertex::operator=(
			const ListPlnrLRMArcguideMVertex& src
		) {
	PlnrLRMArcguideMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrLRMArcguideMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrLRMArcguideMVertex::operator==(
			const ListPlnrLRMArcguideMVertex& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListPlnrLRMArcguideMVertex::operator!=(
			const ListPlnrLRMArcguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrLRMArcguideMVertex
 ******************************************************************************/

TblPlnrLRMArcguideMVertex::TblPlnrLRMArcguideMVertex() {
};

TblPlnrLRMArcguideMVertex::~TblPlnrLRMArcguideMVertex() {
};

bool TblPlnrLRMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMArcguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrLRMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	return 0;
};

void TblPlnrLRMArcguideMVertex::insertRec(
			PlnrLRMArcguideMVertex* rec
		) {
};

ubigint TblPlnrLRMArcguideMVertex::insertNewRec(
			PlnrLRMArcguideMVertex** rec
			, const uint agdIxPlnrVLat
			, const ubigint agdRefPlnrMArcguide
			, const uint agdNum
			, const ubigint refPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrLRMArcguideMVertex* _rec = NULL;

	_rec = new PlnrLRMArcguideMVertex(0, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrLRMArcguideMVertex::appendNewRecToRst(
			ListPlnrLRMArcguideMVertex& rst
			, PlnrLRMArcguideMVertex** rec
			, const uint agdIxPlnrVLat
			, const ubigint agdRefPlnrMArcguide
			, const uint agdNum
			, const ubigint refPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrLRMArcguideMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrLRMArcguideMVertex::insertRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrLRMArcguideMVertex::updateRec(
			PlnrLRMArcguideMVertex* rec
		) {
};

void TblPlnrLRMArcguideMVertex::updateRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrLRMArcguideMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrLRMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMArcguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrLRMArcguideMVertex::loadRstByAgd(
			ubigint agdRefPlnrMArcguide
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrLRMArcguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrLRMArcguideMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	ubigint numload = 0;
	PlnrLRMArcguideMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrLRMArcguideMVertex
 ******************************************************************************/

MyTblPlnrLRMArcguideMVertex::MyTblPlnrLRMArcguideMVertex() : TblPlnrLRMArcguideMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrLRMArcguideMVertex::~MyTblPlnrLRMArcguideMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrLRMArcguideMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrLRMArcguideMVertex (agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrLRMArcguideMVertex SET agdIxPlnrVLat = ?, agdRefPlnrMArcguide = ?, agdNum = ?, refPlnrMVertex = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrLRMArcguideMVertex WHERE ref = ?", false);
};

bool MyTblPlnrLRMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMArcguideMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrLRMArcguideMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrLRMArcguideMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrLRMArcguideMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->agdIxPlnrVLat = atol((char*) dbrow[1]); else _rec->agdIxPlnrVLat = 0;
		if (dbrow[2]) _rec->agdRefPlnrMArcguide = atoll((char*) dbrow[2]); else _rec->agdRefPlnrMArcguide = 0;
		if (dbrow[3]) _rec->agdNum = atol((char*) dbrow[3]); else _rec->agdNum = 0;
		if (dbrow[4]) _rec->refPlnrMVertex = atoll((char*) dbrow[4]); else _rec->refPlnrMVertex = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrLRMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrLRMArcguideMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrLRMArcguideMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrLRMArcguideMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->agdIxPlnrVLat = atol((char*) dbrow[1]); else rec->agdIxPlnrVLat = 0;
			if (dbrow[2]) rec->agdRefPlnrMArcguide = atoll((char*) dbrow[2]); else rec->agdRefPlnrMArcguide = 0;
			if (dbrow[3]) rec->agdNum = atol((char*) dbrow[3]); else rec->agdNum = 0;
			if (dbrow[4]) rec->refPlnrMVertex = atoll((char*) dbrow[4]); else rec->refPlnrMVertex = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrLRMArcguideMVertex::insertRec(
			PlnrLRMArcguideMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUint(&rec->agdIxPlnrVLat,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->agdRefPlnrMArcguide,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->agdNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMVertex,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMArcguideMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMArcguideMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrLRMArcguideMVertex::insertRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrLRMArcguideMVertex::updateRec(
			PlnrLRMArcguideMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUint(&rec->agdIxPlnrVLat,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->agdRefPlnrMArcguide,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->agdNum,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMVertex,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMArcguideMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMArcguideMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrLRMArcguideMVertex::updateRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrLRMArcguideMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMArcguideMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMArcguideMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrLRMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMArcguideMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrLRMArcguideMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrLRMArcguideMVertex::loadRstByAgd(
			ubigint agdRefPlnrMArcguide
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex FROM TblPlnrLRMArcguideMVertex WHERE agdRefPlnrMArcguide = " + to_string(agdRefPlnrMArcguide) + " ORDER BY agdNum ASC", append, rst);
};

ubigint MyTblPlnrLRMArcguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex FROM TblPlnrLRMArcguideMVertex WHERE refPlnrMVertex = " + to_string(refPlnrMVertex) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrLRMArcguideMVertex
 ******************************************************************************/

PgTblPlnrLRMArcguideMVertex::PgTblPlnrLRMArcguideMVertex() : TblPlnrLRMArcguideMVertex(), PgTable() {
};

PgTblPlnrLRMArcguideMVertex::~PgTblPlnrLRMArcguideMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrLRMArcguideMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_insertRec", "INSERT INTO TblPlnrLRMArcguideMVertex (agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_updateRec", "UPDATE TblPlnrLRMArcguideMVertex SET agdIxPlnrVLat = $1, agdRefPlnrMArcguide = $2, agdNum = $3, refPlnrMVertex = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_removeRecByRef", "DELETE FROM TblPlnrLRMArcguideMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_loadRecByRef", "SELECT ref, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex FROM TblPlnrLRMArcguideMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_loadRstByAgd", "SELECT ref, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex FROM TblPlnrLRMArcguideMVertex WHERE agdRefPlnrMArcguide = $1 ORDER BY agdNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMArcguideMVertex_loadRstByVtx", "SELECT ref, agdIxPlnrVLat, agdRefPlnrMArcguide, agdNum, refPlnrMVertex FROM TblPlnrLRMArcguideMVertex WHERE refPlnrMVertex = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrLRMArcguideMVertex::loadRec(
			PGresult* res
			, PlnrLRMArcguideMVertex** rec
		) {
	char* ptr;

	PlnrLRMArcguideMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrLRMArcguideMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "agdixplnrvlat"),
			PQfnumber(res, "agdrefplnrmarcguide"),
			PQfnumber(res, "agdnum"),
			PQfnumber(res, "refplnrmvertex")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->agdIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->agdRefPlnrMArcguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->agdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMVertex = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrLRMArcguideMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrLRMArcguideMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "agdixplnrvlat"),
			PQfnumber(res, "agdrefplnrmarcguide"),
			PQfnumber(res, "agdnum"),
			PQfnumber(res, "refplnrmvertex")
		};

		while (numread < numrow) {
			rec = new PlnrLRMArcguideMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->agdIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->agdRefPlnrMArcguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->agdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMVertex = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrLRMArcguideMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrLRMArcguideMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMArcguideMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrLRMArcguideMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMArcguideMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrLRMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMArcguideMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrLRMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrLRMArcguideMVertex::insertRec(
			PlnrLRMArcguideMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	uint _agdIxPlnrVLat = htonl(rec->agdIxPlnrVLat);
	ubigint _agdRefPlnrMArcguide = htonl64(rec->agdRefPlnrMArcguide);
	uint _agdNum = htonl(rec->agdNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);

	const char* vals[] = {
		(char*) &_agdIxPlnrVLat,
		(char*) &_agdRefPlnrMArcguide,
		(char*) &_agdNum,
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrLRMArcguideMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMArcguideMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrLRMArcguideMVertex::insertRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrLRMArcguideMVertex::updateRec(
			PlnrLRMArcguideMVertex* rec
		) {
	PGresult* res;

	uint _agdIxPlnrVLat = htonl(rec->agdIxPlnrVLat);
	ubigint _agdRefPlnrMArcguide = htonl64(rec->agdRefPlnrMArcguide);
	uint _agdNum = htonl(rec->agdNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_agdIxPlnrVLat,
		(char*) &_agdRefPlnrMArcguide,
		(char*) &_agdNum,
		(char*) &_refPlnrMVertex,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrLRMArcguideMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMArcguideMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrLRMArcguideMVertex::updateRst(
			ListPlnrLRMArcguideMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrLRMArcguideMVertex::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrLRMArcguideMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMArcguideMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrLRMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMArcguideMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrLRMArcguideMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrLRMArcguideMVertex::loadRstByAgd(
			ubigint agdRefPlnrMArcguide
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	ubigint _agdRefPlnrMArcguide = htonl64(agdRefPlnrMArcguide);

	const char* vals[] = {
		(char*) &_agdRefPlnrMArcguide
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrLRMArcguideMVertex_loadRstByAgd", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrLRMArcguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMArcguideMVertex& rst
		) {
	ubigint _refPlnrMVertex = htonl64(refPlnrMVertex);

	const char* vals[] = {
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrLRMArcguideMVertex_loadRstByVtx", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

