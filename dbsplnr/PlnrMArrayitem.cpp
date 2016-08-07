/**
  * \file PlnrMArrayitem.cpp
  * database access for table TblPlnrMArrayitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMArrayitem.h"

/******************************************************************************
 class PlnrMArrayitem
 ******************************************************************************/

PlnrMArrayitem::PlnrMArrayitem(
			const ubigint ref
			, const ubigint refPlnrMArray
			, const ubigint refPlnrMDesign
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const double dx
			, const double dy
		) {

	this->ref = ref;
	this->refPlnrMArray = refPlnrMArray;
	this->refPlnrMDesign = refPlnrMDesign;
	this->i = i;
	this->j = j;
	this->k = k;
	this->l = l;
	this->m = m;
	this->n = n;
	this->dx = dx;
	this->dy = dy;
};

bool PlnrMArrayitem::operator==(
			const PlnrMArrayitem& comp
		) {
	return false;
};

bool PlnrMArrayitem::operator!=(
			const PlnrMArrayitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMArrayitem
 ******************************************************************************/

ListPlnrMArrayitem::ListPlnrMArrayitem() {
};

ListPlnrMArrayitem::ListPlnrMArrayitem(
			const ListPlnrMArrayitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMArrayitem(*(src.nodes[i]));
};

ListPlnrMArrayitem::~ListPlnrMArrayitem() {
	clear();
};

void ListPlnrMArrayitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMArrayitem::size() const {
	return(nodes.size());
};

void ListPlnrMArrayitem::append(
			PlnrMArrayitem* rec
		) {
	nodes.push_back(rec);
};

PlnrMArrayitem* ListPlnrMArrayitem::operator[](
			const uint ix
		) {
	PlnrMArrayitem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMArrayitem& ListPlnrMArrayitem::operator=(
			const ListPlnrMArrayitem& src
		) {
	PlnrMArrayitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMArrayitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMArrayitem::operator==(
			const ListPlnrMArrayitem& comp
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

bool ListPlnrMArrayitem::operator!=(
			const ListPlnrMArrayitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMArrayitem
 ******************************************************************************/

TblPlnrMArrayitem::TblPlnrMArrayitem() {
};

TblPlnrMArrayitem::~TblPlnrMArrayitem() {
};

bool TblPlnrMArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMArrayitem** rec
		) {
	return false;
};

ubigint TblPlnrMArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	return 0;
};

void TblPlnrMArrayitem::insertRec(
			PlnrMArrayitem* rec
		) {
};

ubigint TblPlnrMArrayitem::insertNewRec(
			PlnrMArrayitem** rec
			, const ubigint refPlnrMArray
			, const ubigint refPlnrMDesign
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const double dx
			, const double dy
		) {
	ubigint retval = 0;
	PlnrMArrayitem* _rec = NULL;

	_rec = new PlnrMArrayitem(0, refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMArrayitem::appendNewRecToRst(
			ListPlnrMArrayitem& rst
			, PlnrMArrayitem** rec
			, const ubigint refPlnrMArray
			, const ubigint refPlnrMDesign
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const double dx
			, const double dy
		) {
	ubigint retval = 0;
	PlnrMArrayitem* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMArrayitem::insertRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
};

void TblPlnrMArrayitem::updateRec(
			PlnrMArrayitem* rec
		) {
};

void TblPlnrMArrayitem::updateRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
};

void TblPlnrMArrayitem::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMArrayitem::loadRecByRef(
			ubigint ref
			, PlnrMArrayitem** rec
		) {
	return false;
};

ubigint TblPlnrMArrayitem::loadRstByArr(
			ubigint refPlnrMArray
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	return 0;
};

ubigint TblPlnrMArrayitem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	ubigint numload = 0;
	PlnrMArrayitem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMArrayitem
 ******************************************************************************/

MyTblPlnrMArrayitem::MyTblPlnrMArrayitem() : TblPlnrMArrayitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMArrayitem::~MyTblPlnrMArrayitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMArrayitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMArrayitem (refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMArrayitem SET refPlnrMArray = ?, refPlnrMDesign = ?, i = ?, j = ?, k = ?, l = ?, m = ?, n = ?, dx = ?, dy = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMArrayitem WHERE ref = ?", false);
};

bool MyTblPlnrMArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMArrayitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMArrayitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArrayitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMArrayitem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMArray = atoll((char*) dbrow[1]); else _rec->refPlnrMArray = 0;
		if (dbrow[2]) _rec->refPlnrMDesign = atoll((char*) dbrow[2]); else _rec->refPlnrMDesign = 0;
		if (dbrow[3]) _rec->i = atoi((char*) dbrow[3]); else _rec->i = 0;
		if (dbrow[4]) _rec->j = atoi((char*) dbrow[4]); else _rec->j = 0;
		if (dbrow[5]) _rec->k = atoi((char*) dbrow[5]); else _rec->k = 0;
		if (dbrow[6]) _rec->l = atoi((char*) dbrow[6]); else _rec->l = 0;
		if (dbrow[7]) _rec->m = atoi((char*) dbrow[7]); else _rec->m = 0;
		if (dbrow[8]) _rec->n = atoi((char*) dbrow[8]); else _rec->n = 0;
		if (dbrow[9]) _rec->dx = atof((char*) dbrow[9]); else _rec->dx = 0.0;
		if (dbrow[10]) _rec->dy = atof((char*) dbrow[10]); else _rec->dy = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMArrayitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArrayitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMArrayitem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMArray = atoll((char*) dbrow[1]); else rec->refPlnrMArray = 0;
			if (dbrow[2]) rec->refPlnrMDesign = atoll((char*) dbrow[2]); else rec->refPlnrMDesign = 0;
			if (dbrow[3]) rec->i = atoi((char*) dbrow[3]); else rec->i = 0;
			if (dbrow[4]) rec->j = atoi((char*) dbrow[4]); else rec->j = 0;
			if (dbrow[5]) rec->k = atoi((char*) dbrow[5]); else rec->k = 0;
			if (dbrow[6]) rec->l = atoi((char*) dbrow[6]); else rec->l = 0;
			if (dbrow[7]) rec->m = atoi((char*) dbrow[7]); else rec->m = 0;
			if (dbrow[8]) rec->n = atoi((char*) dbrow[8]); else rec->n = 0;
			if (dbrow[9]) rec->dx = atof((char*) dbrow[9]); else rec->dx = 0.0;
			if (dbrow[10]) rec->dy = atof((char*) dbrow[10]); else rec->dy = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMArrayitem::insertRec(
			PlnrMArrayitem* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArray,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->i,&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->j,&(l[3]),&(n[3]),&(e[3])),
		bindUsmallint(&rec->k,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->l,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->m,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->n,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->dx,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->dy,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArrayitem / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArrayitem / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMArrayitem::insertRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMArrayitem::updateRec(
			PlnrMArrayitem* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArray,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUsmallint(&rec->i,&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->j,&(l[3]),&(n[3]),&(e[3])), 
		bindUsmallint(&rec->k,&(l[4]),&(n[4]),&(e[4])), 
		bindUsmallint(&rec->l,&(l[5]),&(n[5]),&(e[5])), 
		bindUsmallint(&rec->m,&(l[6]),&(n[6]),&(e[6])), 
		bindUsmallint(&rec->n,&(l[7]),&(n[7]),&(e[7])), 
		bindDouble(&rec->dx,&(l[8]),&(n[8]),&(e[8])), 
		bindDouble(&rec->dy,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArrayitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArrayitem / stmtUpdateRec)\n");
};

void MyTblPlnrMArrayitem::updateRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMArrayitem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArrayitem / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArrayitem / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMArrayitem::loadRecByRef(
			ubigint ref
			, PlnrMArrayitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMArrayitem WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMArrayitem::loadRstByArr(
			ubigint refPlnrMArray
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy FROM TblPlnrMArrayitem WHERE refPlnrMArray = " + to_string(refPlnrMArray) + " ORDER BY i ASC, j ASC, k ASC, l ASC, m ASC, n ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMArrayitem
 ******************************************************************************/

PgTblPlnrMArrayitem::PgTblPlnrMArrayitem() : TblPlnrMArrayitem(), PgTable() {
};

PgTblPlnrMArrayitem::~PgTblPlnrMArrayitem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMArrayitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMArrayitem_insertRec", "INSERT INTO TblPlnrMArrayitem (refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArrayitem_updateRec", "UPDATE TblPlnrMArrayitem SET refPlnrMArray = $1, refPlnrMDesign = $2, i = $3, j = $4, k = $5, l = $6, m = $7, n = $8, dx = $9, dy = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArrayitem_removeRecByRef", "DELETE FROM TblPlnrMArrayitem WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMArrayitem_loadRecByRef", "SELECT ref, refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy FROM TblPlnrMArrayitem WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMArrayitem_loadRstByArr", "SELECT ref, refPlnrMArray, refPlnrMDesign, i, j, k, l, m, n, dx, dy FROM TblPlnrMArrayitem WHERE refPlnrMArray = $1 ORDER BY i ASC, j ASC, k ASC, l ASC, m ASC, n ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMArrayitem::loadRec(
			PGresult* res
			, PlnrMArrayitem** rec
		) {
	char* ptr;

	PlnrMArrayitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMArrayitem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMArray = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->i = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->j = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->k = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->l = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->m = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->n = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->dy = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMArrayitem::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMArrayitem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy")
		};

		while (numread < numrow) {
			rec = new PlnrMArrayitem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMArray = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->i = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->j = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->k = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->l = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->m = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->n = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->dy = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMArrayitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMArrayitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArrayitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMArrayitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArrayitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMArrayitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMArrayitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMArrayitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMArrayitem::insertRec(
			PlnrMArrayitem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _i = htons(rec->i);
	usmallint _j = htons(rec->j);
	usmallint _k = htons(rec->k);
	usmallint _l = htons(rec->l);
	usmallint _m = htons(rec->m);
	usmallint _n = htons(rec->n);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);

	const char* vals[] = {
		(char*) &_refPlnrMArray,
		(char*) &_refPlnrMDesign,
		(char*) &_i,
		(char*) &_j,
		(char*) &_k,
		(char*) &_l,
		(char*) &_m,
		(char*) &_n,
		_dx.c_str(),
		_dy.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMArrayitem_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArrayitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMArrayitem::insertRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMArrayitem::updateRec(
			PlnrMArrayitem* rec
		) {
	PGresult* res;

	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	usmallint _i = htons(rec->i);
	usmallint _j = htons(rec->j);
	usmallint _k = htons(rec->k);
	usmallint _l = htons(rec->l);
	usmallint _m = htons(rec->m);
	usmallint _n = htons(rec->n);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMArray,
		(char*) &_refPlnrMDesign,
		(char*) &_i,
		(char*) &_j,
		(char*) &_k,
		(char*) &_l,
		(char*) &_m,
		(char*) &_n,
		_dx.c_str(),
		_dy.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMArrayitem_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArrayitem_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMArrayitem::updateRst(
			ListPlnrMArrayitem& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMArrayitem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMArrayitem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArrayitem_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMArrayitem::loadRecByRef(
			ubigint ref
			, PlnrMArrayitem** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMArrayitem_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMArrayitem::loadRstByArr(
			ubigint refPlnrMArray
			, const bool append
			, ListPlnrMArrayitem& rst
		) {
	ubigint _refPlnrMArray = htonl64(refPlnrMArray);

	const char* vals[] = {
		(char*) &_refPlnrMArray
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMArrayitem_loadRstByArr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

