/**
  * \file PlnrLRMLineguideMVertex.cpp
  * database access for table TblPlnrLRMLineguideMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrLRMLineguideMVertex.h"

/******************************************************************************
 class PlnrLRMLineguideMVertex
 ******************************************************************************/

PlnrLRMLineguideMVertex::PlnrLRMLineguideMVertex(
			const ubigint ref
			, const uint lgdIxPlnrVLat
			, const ubigint lgdRefPlnrMLineguide
			, const uint lgdNum
			, const ubigint refPlnrMVertex
		) {

	this->ref = ref;
	this->lgdIxPlnrVLat = lgdIxPlnrVLat;
	this->lgdRefPlnrMLineguide = lgdRefPlnrMLineguide;
	this->lgdNum = lgdNum;
	this->refPlnrMVertex = refPlnrMVertex;
};

bool PlnrLRMLineguideMVertex::operator==(
			const PlnrLRMLineguideMVertex& comp
		) {
	return false;
};

bool PlnrLRMLineguideMVertex::operator!=(
			const PlnrLRMLineguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrLRMLineguideMVertex
 ******************************************************************************/

ListPlnrLRMLineguideMVertex::ListPlnrLRMLineguideMVertex() {
};

ListPlnrLRMLineguideMVertex::ListPlnrLRMLineguideMVertex(
			const ListPlnrLRMLineguideMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrLRMLineguideMVertex(*(src.nodes[i]));
};

ListPlnrLRMLineguideMVertex::~ListPlnrLRMLineguideMVertex() {
	clear();
};

void ListPlnrLRMLineguideMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrLRMLineguideMVertex::size() const {
	return(nodes.size());
};

void ListPlnrLRMLineguideMVertex::append(
			PlnrLRMLineguideMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrLRMLineguideMVertex* ListPlnrLRMLineguideMVertex::operator[](
			const uint ix
		) {
	PlnrLRMLineguideMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrLRMLineguideMVertex& ListPlnrLRMLineguideMVertex::operator=(
			const ListPlnrLRMLineguideMVertex& src
		) {
	PlnrLRMLineguideMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrLRMLineguideMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrLRMLineguideMVertex::operator==(
			const ListPlnrLRMLineguideMVertex& comp
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

bool ListPlnrLRMLineguideMVertex::operator!=(
			const ListPlnrLRMLineguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrLRMLineguideMVertex
 ******************************************************************************/

TblPlnrLRMLineguideMVertex::TblPlnrLRMLineguideMVertex() {
};

TblPlnrLRMLineguideMVertex::~TblPlnrLRMLineguideMVertex() {
};

bool TblPlnrLRMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMLineguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrLRMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	return 0;
};

void TblPlnrLRMLineguideMVertex::insertRec(
			PlnrLRMLineguideMVertex* rec
		) {
};

ubigint TblPlnrLRMLineguideMVertex::insertNewRec(
			PlnrLRMLineguideMVertex** rec
			, const uint lgdIxPlnrVLat
			, const ubigint lgdRefPlnrMLineguide
			, const uint lgdNum
			, const ubigint refPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrLRMLineguideMVertex* _rec = NULL;

	_rec = new PlnrLRMLineguideMVertex(0, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrLRMLineguideMVertex::appendNewRecToRst(
			ListPlnrLRMLineguideMVertex& rst
			, PlnrLRMLineguideMVertex** rec
			, const uint lgdIxPlnrVLat
			, const ubigint lgdRefPlnrMLineguide
			, const uint lgdNum
			, const ubigint refPlnrMVertex
		) {
	ubigint retval = 0;
	PlnrLRMLineguideMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrLRMLineguideMVertex::insertRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrLRMLineguideMVertex::updateRec(
			PlnrLRMLineguideMVertex* rec
		) {
};

void TblPlnrLRMLineguideMVertex::updateRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrLRMLineguideMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrLRMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMLineguideMVertex** rec
		) {
	return false;
};

bool TblPlnrLRMLineguideMVertex::loadRecByLgdVtx(
			ubigint lgdRefPlnrMLineguide
			, ubigint refPlnrMVertex
			, PlnrLRMLineguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrLRMLineguideMVertex::loadRstByLgd(
			ubigint lgdRefPlnrMLineguide
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrLRMLineguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrLRMLineguideMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	ubigint numload = 0;
	PlnrLRMLineguideMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrLRMLineguideMVertex
 ******************************************************************************/

MyTblPlnrLRMLineguideMVertex::MyTblPlnrLRMLineguideMVertex() : TblPlnrLRMLineguideMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrLRMLineguideMVertex::~MyTblPlnrLRMLineguideMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrLRMLineguideMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrLRMLineguideMVertex (lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrLRMLineguideMVertex SET lgdIxPlnrVLat = ?, lgdRefPlnrMLineguide = ?, lgdNum = ?, refPlnrMVertex = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrLRMLineguideMVertex WHERE ref = ?", false);
};

bool MyTblPlnrLRMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMLineguideMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrLRMLineguideMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrLRMLineguideMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrLRMLineguideMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->lgdIxPlnrVLat = atol((char*) dbrow[1]); else _rec->lgdIxPlnrVLat = 0;
		if (dbrow[2]) _rec->lgdRefPlnrMLineguide = atoll((char*) dbrow[2]); else _rec->lgdRefPlnrMLineguide = 0;
		if (dbrow[3]) _rec->lgdNum = atol((char*) dbrow[3]); else _rec->lgdNum = 0;
		if (dbrow[4]) _rec->refPlnrMVertex = atoll((char*) dbrow[4]); else _rec->refPlnrMVertex = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrLRMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrLRMLineguideMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrLRMLineguideMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrLRMLineguideMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->lgdIxPlnrVLat = atol((char*) dbrow[1]); else rec->lgdIxPlnrVLat = 0;
			if (dbrow[2]) rec->lgdRefPlnrMLineguide = atoll((char*) dbrow[2]); else rec->lgdRefPlnrMLineguide = 0;
			if (dbrow[3]) rec->lgdNum = atol((char*) dbrow[3]); else rec->lgdNum = 0;
			if (dbrow[4]) rec->refPlnrMVertex = atoll((char*) dbrow[4]); else rec->refPlnrMVertex = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrLRMLineguideMVertex::insertRec(
			PlnrLRMLineguideMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUint(&rec->lgdIxPlnrVLat,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->lgdRefPlnrMLineguide,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->lgdNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMVertex,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMLineguideMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMLineguideMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrLRMLineguideMVertex::insertRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrLRMLineguideMVertex::updateRec(
			PlnrLRMLineguideMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUint(&rec->lgdIxPlnrVLat,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->lgdRefPlnrMLineguide,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->lgdNum,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMVertex,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMLineguideMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMLineguideMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrLRMLineguideMVertex::updateRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrLRMLineguideMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrLRMLineguideMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrLRMLineguideMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrLRMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMLineguideMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrLRMLineguideMVertex WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrLRMLineguideMVertex::loadRecByLgdVtx(
			ubigint lgdRefPlnrMLineguide
			, ubigint refPlnrMVertex
			, PlnrLRMLineguideMVertex** rec
		) {
	return loadRecBySQL("SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = " + to_string(lgdRefPlnrMLineguide) + " AND refPlnrMVertex = " + to_string(refPlnrMVertex) + "", rec);
};

ubigint MyTblPlnrLRMLineguideMVertex::loadRstByLgd(
			ubigint lgdRefPlnrMLineguide
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = " + to_string(lgdRefPlnrMLineguide) + " ORDER BY lgdNum ASC", append, rst);
};

ubigint MyTblPlnrLRMLineguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE refPlnrMVertex = " + to_string(refPlnrMVertex) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrLRMLineguideMVertex
 ******************************************************************************/

PgTblPlnrLRMLineguideMVertex::PgTblPlnrLRMLineguideMVertex() : TblPlnrLRMLineguideMVertex(), PgTable() {
};

PgTblPlnrLRMLineguideMVertex::~PgTblPlnrLRMLineguideMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrLRMLineguideMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_insertRec", "INSERT INTO TblPlnrLRMLineguideMVertex (lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_updateRec", "UPDATE TblPlnrLRMLineguideMVertex SET lgdIxPlnrVLat = $1, lgdRefPlnrMLineguide = $2, lgdNum = $3, refPlnrMVertex = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_removeRecByRef", "DELETE FROM TblPlnrLRMLineguideMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_loadRecByRef", "SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_loadRecByLgdVtx", "SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = $1 AND refPlnrMVertex = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_loadRstByLgd", "SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE lgdRefPlnrMLineguide = $1 ORDER BY lgdNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrLRMLineguideMVertex_loadRstByVtx", "SELECT ref, lgdIxPlnrVLat, lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex FROM TblPlnrLRMLineguideMVertex WHERE refPlnrMVertex = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrLRMLineguideMVertex::loadRec(
			PGresult* res
			, PlnrLRMLineguideMVertex** rec
		) {
	char* ptr;

	PlnrLRMLineguideMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrLRMLineguideMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "lgdixplnrvlat"),
			PQfnumber(res, "lgdrefplnrmlineguide"),
			PQfnumber(res, "lgdnum"),
			PQfnumber(res, "refplnrmvertex")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->lgdIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->lgdRefPlnrMLineguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->lgdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMVertex = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrLRMLineguideMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrLRMLineguideMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "lgdixplnrvlat"),
			PQfnumber(res, "lgdrefplnrmlineguide"),
			PQfnumber(res, "lgdnum"),
			PQfnumber(res, "refplnrmvertex")
		};

		while (numread < numrow) {
			rec = new PlnrLRMLineguideMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->lgdIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->lgdRefPlnrMLineguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->lgdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMVertex = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrLRMLineguideMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrLRMLineguideMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMLineguideMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrLRMLineguideMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMLineguideMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrLRMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrLRMLineguideMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrLRMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrLRMLineguideMVertex::insertRec(
			PlnrLRMLineguideMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	uint _lgdIxPlnrVLat = htonl(rec->lgdIxPlnrVLat);
	ubigint _lgdRefPlnrMLineguide = htonl64(rec->lgdRefPlnrMLineguide);
	uint _lgdNum = htonl(rec->lgdNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);

	const char* vals[] = {
		(char*) &_lgdIxPlnrVLat,
		(char*) &_lgdRefPlnrMLineguide,
		(char*) &_lgdNum,
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrLRMLineguideMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMLineguideMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrLRMLineguideMVertex::insertRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrLRMLineguideMVertex::updateRec(
			PlnrLRMLineguideMVertex* rec
		) {
	PGresult* res;

	uint _lgdIxPlnrVLat = htonl(rec->lgdIxPlnrVLat);
	ubigint _lgdRefPlnrMLineguide = htonl64(rec->lgdRefPlnrMLineguide);
	uint _lgdNum = htonl(rec->lgdNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_lgdIxPlnrVLat,
		(char*) &_lgdRefPlnrMLineguide,
		(char*) &_lgdNum,
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

	res = PQexecPrepared(dbs, "TblPlnrLRMLineguideMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMLineguideMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrLRMLineguideMVertex::updateRst(
			ListPlnrLRMLineguideMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrLRMLineguideMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrLRMLineguideMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrLRMLineguideMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrLRMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrLRMLineguideMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrLRMLineguideMVertex_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrLRMLineguideMVertex::loadRecByLgdVtx(
			ubigint lgdRefPlnrMLineguide
			, ubigint refPlnrMVertex
			, PlnrLRMLineguideMVertex** rec
		) {
	ubigint _lgdRefPlnrMLineguide = htonl64(lgdRefPlnrMLineguide);
	ubigint _refPlnrMVertex = htonl64(refPlnrMVertex);

	const char* vals[] = {
		(char*) &_lgdRefPlnrMLineguide,
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrLRMLineguideMVertex_loadRecByLgdVtx", 2, vals, l, f, rec);
};

ubigint PgTblPlnrLRMLineguideMVertex::loadRstByLgd(
			ubigint lgdRefPlnrMLineguide
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	ubigint _lgdRefPlnrMLineguide = htonl64(lgdRefPlnrMLineguide);

	const char* vals[] = {
		(char*) &_lgdRefPlnrMLineguide
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrLRMLineguideMVertex_loadRstByLgd", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrLRMLineguideMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrLRMLineguideMVertex& rst
		) {
	ubigint _refPlnrMVertex = htonl64(refPlnrMVertex);

	const char* vals[] = {
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrLRMLineguideMVertex_loadRstByVtx", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

