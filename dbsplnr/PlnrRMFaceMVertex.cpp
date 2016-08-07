/**
  * \file PlnrRMFaceMVertex.cpp
  * database access for table TblPlnrRMFaceMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMFaceMVertex.h"

/******************************************************************************
 class PlnrRMFaceMVertex
 ******************************************************************************/

PlnrRMFaceMVertex::PlnrRMFaceMVertex(
			const ubigint ref
			, const ubigint fceRefPlnrMFace
			, const uint fceNum
			, const ubigint refPlnrMVertex
			, const uint rteIxVTbl
			, const ubigint rteUref
			, const uint ixVDir
		) {

	this->ref = ref;
	this->fceRefPlnrMFace = fceRefPlnrMFace;
	this->fceNum = fceNum;
	this->refPlnrMVertex = refPlnrMVertex;
	this->rteIxVTbl = rteIxVTbl;
	this->rteUref = rteUref;
	this->ixVDir = ixVDir;
};

bool PlnrRMFaceMVertex::operator==(
			const PlnrRMFaceMVertex& comp
		) {
	return false;
};

bool PlnrRMFaceMVertex::operator!=(
			const PlnrRMFaceMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMFaceMVertex
 ******************************************************************************/

ListPlnrRMFaceMVertex::ListPlnrRMFaceMVertex() {
};

ListPlnrRMFaceMVertex::ListPlnrRMFaceMVertex(
			const ListPlnrRMFaceMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMFaceMVertex(*(src.nodes[i]));
};

ListPlnrRMFaceMVertex::~ListPlnrRMFaceMVertex() {
	clear();
};

void ListPlnrRMFaceMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMFaceMVertex::size() const {
	return(nodes.size());
};

void ListPlnrRMFaceMVertex::append(
			PlnrRMFaceMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrRMFaceMVertex* ListPlnrRMFaceMVertex::operator[](
			const uint ix
		) {
	PlnrRMFaceMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMFaceMVertex& ListPlnrRMFaceMVertex::operator=(
			const ListPlnrRMFaceMVertex& src
		) {
	PlnrRMFaceMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMFaceMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMFaceMVertex::operator==(
			const ListPlnrRMFaceMVertex& comp
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

bool ListPlnrRMFaceMVertex::operator!=(
			const ListPlnrRMFaceMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMFaceMVertex
 ******************************************************************************/

TblPlnrRMFaceMVertex::TblPlnrRMFaceMVertex() {
};

TblPlnrRMFaceMVertex::~TblPlnrRMFaceMVertex() {
};

bool TblPlnrRMFaceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMFaceMVertex** rec
		) {
	return false;
};

ubigint TblPlnrRMFaceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	return 0;
};

void TblPlnrRMFaceMVertex::insertRec(
			PlnrRMFaceMVertex* rec
		) {
};

ubigint TblPlnrRMFaceMVertex::insertNewRec(
			PlnrRMFaceMVertex** rec
			, const ubigint fceRefPlnrMFace
			, const uint fceNum
			, const ubigint refPlnrMVertex
			, const uint rteIxVTbl
			, const ubigint rteUref
			, const uint ixVDir
		) {
	ubigint retval = 0;
	PlnrRMFaceMVertex* _rec = NULL;

	_rec = new PlnrRMFaceMVertex(0, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMFaceMVertex::appendNewRecToRst(
			ListPlnrRMFaceMVertex& rst
			, PlnrRMFaceMVertex** rec
			, const ubigint fceRefPlnrMFace
			, const uint fceNum
			, const ubigint refPlnrMVertex
			, const uint rteIxVTbl
			, const ubigint rteUref
			, const uint ixVDir
		) {
	ubigint retval = 0;
	PlnrRMFaceMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMFaceMVertex::insertRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
};

void TblPlnrRMFaceMVertex::updateRec(
			PlnrRMFaceMVertex* rec
		) {
};

void TblPlnrRMFaceMVertex::updateRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
};

void TblPlnrRMFaceMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMFaceMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMFaceMVertex** rec
		) {
	return false;
};

ubigint TblPlnrRMFaceMVertex::loadRstByFce(
			ubigint fceRefPlnrMFace
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrRMFaceMVertex::loadRstByRttRtu(
			uint rteIxVTbl
			, ubigint rteUref
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrRMFaceMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	ubigint numload = 0;
	PlnrRMFaceMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMFaceMVertex
 ******************************************************************************/

MyTblPlnrRMFaceMVertex::MyTblPlnrRMFaceMVertex() : TblPlnrRMFaceMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMFaceMVertex::~MyTblPlnrRMFaceMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMFaceMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMFaceMVertex (fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMFaceMVertex SET fceRefPlnrMFace = ?, fceNum = ?, refPlnrMVertex = ?, rteIxVTbl = ?, rteUref = ?, ixVDir = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMFaceMVertex WHERE ref = ?", false);
};

bool MyTblPlnrRMFaceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMFaceMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMFaceMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMFaceMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMFaceMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->fceRefPlnrMFace = atoll((char*) dbrow[1]); else _rec->fceRefPlnrMFace = 0;
		if (dbrow[2]) _rec->fceNum = atol((char*) dbrow[2]); else _rec->fceNum = 0;
		if (dbrow[3]) _rec->refPlnrMVertex = atoll((char*) dbrow[3]); else _rec->refPlnrMVertex = 0;
		if (dbrow[4]) _rec->rteIxVTbl = atol((char*) dbrow[4]); else _rec->rteIxVTbl = 0;
		if (dbrow[5]) _rec->rteUref = atoll((char*) dbrow[5]); else _rec->rteUref = 0;
		if (dbrow[6]) _rec->ixVDir = atol((char*) dbrow[6]); else _rec->ixVDir = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMFaceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMFaceMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMFaceMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMFaceMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->fceRefPlnrMFace = atoll((char*) dbrow[1]); else rec->fceRefPlnrMFace = 0;
			if (dbrow[2]) rec->fceNum = atol((char*) dbrow[2]); else rec->fceNum = 0;
			if (dbrow[3]) rec->refPlnrMVertex = atoll((char*) dbrow[3]); else rec->refPlnrMVertex = 0;
			if (dbrow[4]) rec->rteIxVTbl = atol((char*) dbrow[4]); else rec->rteIxVTbl = 0;
			if (dbrow[5]) rec->rteUref = atoll((char*) dbrow[5]); else rec->rteUref = 0;
			if (dbrow[6]) rec->ixVDir = atol((char*) dbrow[6]); else rec->ixVDir = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMFaceMVertex::insertRec(
			PlnrRMFaceMVertex* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fceRefPlnrMFace,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->fceNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMVertex,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->rteIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->rteUref,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVDir,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMFaceMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMFaceMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMFaceMVertex::insertRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMFaceMVertex::updateRec(
			PlnrRMFaceMVertex* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fceRefPlnrMFace,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->fceNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMVertex,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->rteIxVTbl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->rteUref,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVDir,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMFaceMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMFaceMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrRMFaceMVertex::updateRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMFaceMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMFaceMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMFaceMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMFaceMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMFaceMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMFaceMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrRMFaceMVertex::loadRstByFce(
			ubigint fceRefPlnrMFace
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir FROM TblPlnrRMFaceMVertex WHERE fceRefPlnrMFace = " + to_string(fceRefPlnrMFace) + " ORDER BY fceNum ASC", append, rst);
};

ubigint MyTblPlnrRMFaceMVertex::loadRstByRttRtu(
			uint rteIxVTbl
			, ubigint rteUref
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir FROM TblPlnrRMFaceMVertex WHERE rteIxVTbl = " + to_string(rteIxVTbl) + " AND rteUref = " + to_string(rteUref) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMFaceMVertex
 ******************************************************************************/

PgTblPlnrRMFaceMVertex::PgTblPlnrRMFaceMVertex() : TblPlnrRMFaceMVertex(), PgTable() {
};

PgTblPlnrRMFaceMVertex::~PgTblPlnrRMFaceMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMFaceMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_insertRec", "INSERT INTO TblPlnrRMFaceMVertex (fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_updateRec", "UPDATE TblPlnrRMFaceMVertex SET fceRefPlnrMFace = $1, fceNum = $2, refPlnrMVertex = $3, rteIxVTbl = $4, rteUref = $5, ixVDir = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_removeRecByRef", "DELETE FROM TblPlnrRMFaceMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_loadRecByRef", "SELECT ref, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir FROM TblPlnrRMFaceMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_loadRstByFce", "SELECT ref, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir FROM TblPlnrRMFaceMVertex WHERE fceRefPlnrMFace = $1 ORDER BY fceNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMFaceMVertex_loadRstByRttRtu", "SELECT ref, fceRefPlnrMFace, fceNum, refPlnrMVertex, rteIxVTbl, rteUref, ixVDir FROM TblPlnrRMFaceMVertex WHERE rteIxVTbl = $1 AND rteUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrRMFaceMVertex::loadRec(
			PGresult* res
			, PlnrRMFaceMVertex** rec
		) {
	char* ptr;

	PlnrRMFaceMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMFaceMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fcerefplnrmface"),
			PQfnumber(res, "fcenum"),
			PQfnumber(res, "refplnrmvertex"),
			PQfnumber(res, "rteixvtbl"),
			PQfnumber(res, "rteuref"),
			PQfnumber(res, "ixvdir")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->fceRefPlnrMFace = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fceNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMVertex = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->rteIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->rteUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVDir = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMFaceMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMFaceMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fcerefplnrmface"),
			PQfnumber(res, "fcenum"),
			PQfnumber(res, "refplnrmvertex"),
			PQfnumber(res, "rteixvtbl"),
			PQfnumber(res, "rteuref"),
			PQfnumber(res, "ixvdir")
		};

		while (numread < numrow) {
			rec = new PlnrRMFaceMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->fceRefPlnrMFace = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fceNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMVertex = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->rteIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->rteUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVDir = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMFaceMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMFaceMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMFaceMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrRMFaceMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMFaceMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrRMFaceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrRMFaceMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMFaceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMFaceMVertex::insertRec(
			PlnrRMFaceMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _fceRefPlnrMFace = htonl64(rec->fceRefPlnrMFace);
	uint _fceNum = htonl(rec->fceNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	uint _rteIxVTbl = htonl(rec->rteIxVTbl);
	ubigint _rteUref = htonl64(rec->rteUref);
	uint _ixVDir = htonl(rec->ixVDir);

	const char* vals[] = {
		(char*) &_fceRefPlnrMFace,
		(char*) &_fceNum,
		(char*) &_refPlnrMVertex,
		(char*) &_rteIxVTbl,
		(char*) &_rteUref,
		(char*) &_ixVDir
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMFaceMVertex_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMFaceMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMFaceMVertex::insertRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMFaceMVertex::updateRec(
			PlnrRMFaceMVertex* rec
		) {
	PGresult* res;

	ubigint _fceRefPlnrMFace = htonl64(rec->fceRefPlnrMFace);
	uint _fceNum = htonl(rec->fceNum);
	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	uint _rteIxVTbl = htonl(rec->rteIxVTbl);
	ubigint _rteUref = htonl64(rec->rteUref);
	uint _ixVDir = htonl(rec->ixVDir);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_fceRefPlnrMFace,
		(char*) &_fceNum,
		(char*) &_refPlnrMVertex,
		(char*) &_rteIxVTbl,
		(char*) &_rteUref,
		(char*) &_ixVDir,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMFaceMVertex_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMFaceMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMFaceMVertex::updateRst(
			ListPlnrRMFaceMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMFaceMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMFaceMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMFaceMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMFaceMVertex::loadRecByRef(
			ubigint ref
			, PlnrRMFaceMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMFaceMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrRMFaceMVertex::loadRstByFce(
			ubigint fceRefPlnrMFace
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	ubigint _fceRefPlnrMFace = htonl64(fceRefPlnrMFace);

	const char* vals[] = {
		(char*) &_fceRefPlnrMFace
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrRMFaceMVertex_loadRstByFce", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrRMFaceMVertex::loadRstByRttRtu(
			uint rteIxVTbl
			, ubigint rteUref
			, const bool append
			, ListPlnrRMFaceMVertex& rst
		) {
	uint _rteIxVTbl = htonl(rteIxVTbl);
	ubigint _rteUref = htonl64(rteUref);

	const char* vals[] = {
		(char*) &_rteIxVTbl,
		(char*) &_rteUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrRMFaceMVertex_loadRstByRttRtu", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

