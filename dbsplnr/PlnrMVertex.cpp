/**
  * \file PlnrMVertex.cpp
  * database access for table TblPlnrMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMVertex.h"

/******************************************************************************
 class PlnrMVertex
 ******************************************************************************/

PlnrMVertex::PlnrMVertex(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x
			, const double y
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->hkIxPlnrVLat = hkIxPlnrVLat;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->sref = sref;
	this->x = x;
	this->y = y;
};

bool PlnrMVertex::operator==(
			const PlnrMVertex& comp
		) {
	return false;
};

bool PlnrMVertex::operator!=(
			const PlnrMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMVertex
 ******************************************************************************/

ListPlnrMVertex::ListPlnrMVertex() {
};

ListPlnrMVertex::ListPlnrMVertex(
			const ListPlnrMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMVertex(*(src.nodes[i]));
};

ListPlnrMVertex::~ListPlnrMVertex() {
	clear();
};

void ListPlnrMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMVertex::size() const {
	return(nodes.size());
};

void ListPlnrMVertex::append(
			PlnrMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrMVertex* ListPlnrMVertex::operator[](
			const uint ix
		) {
	PlnrMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMVertex& ListPlnrMVertex::operator=(
			const ListPlnrMVertex& src
		) {
	PlnrMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMVertex::operator==(
			const ListPlnrMVertex& comp
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

bool ListPlnrMVertex::operator!=(
			const ListPlnrMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMVertex
 ******************************************************************************/

TblPlnrMVertex::TblPlnrMVertex() {
};

TblPlnrMVertex::~TblPlnrMVertex() {
};

bool TblPlnrMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrMVertex** rec
		) {
	return false;
};

ubigint TblPlnrMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMVertex& rst
		) {
	return 0;
};

void TblPlnrMVertex::insertRec(
			PlnrMVertex* rec
		) {
};

ubigint TblPlnrMVertex::insertNewRec(
			PlnrMVertex** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	PlnrMVertex* _rec = NULL;

	_rec = new PlnrMVertex(0, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMVertex::appendNewRecToRst(
			ListPlnrMVertex& rst
			, PlnrMVertex** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	PlnrMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMVertex::insertRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
};

void TblPlnrMVertex::updateRec(
			PlnrMVertex* rec
		) {
};

void TblPlnrMVertex::updateRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
};

void TblPlnrMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMVertex::loadRecByRef(
			ubigint ref
			, PlnrMVertex** rec
		) {
	return false;
};

ubigint TblPlnrMVertex::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

ubigint TblPlnrMVertex::countByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

bool TblPlnrMVertex::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMVertex** rec
		) {
	return false;
};

ubigint TblPlnrMVertex::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMVertex& rst
		) {
	ubigint numload = 0;
	PlnrMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMVertex
 ******************************************************************************/

MyTblPlnrMVertex::MyTblPlnrMVertex() : TblPlnrMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMVertex::~MyTblPlnrMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMVertex (x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMVertex SET x1RefPlnrMDesign = ?, hkIxPlnrVLat = ?, hkIxVTbl = ?, hkUref = ?, sref = ?, x = ?, y = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMVertex WHERE ref = ?", false);
};

bool MyTblPlnrMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->hkIxPlnrVLat = atol((char*) dbrow[2]); else _rec->hkIxPlnrVLat = 0;
		if (dbrow[3]) _rec->hkIxVTbl = atol((char*) dbrow[3]); else _rec->hkIxVTbl = 0;
		if (dbrow[4]) _rec->hkUref = atoll((char*) dbrow[4]); else _rec->hkUref = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->x = atof((char*) dbrow[6]); else _rec->x = 0.0;
		if (dbrow[7]) _rec->y = atof((char*) dbrow[7]); else _rec->y = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->hkIxPlnrVLat = atol((char*) dbrow[2]); else rec->hkIxPlnrVLat = 0;
			if (dbrow[3]) rec->hkIxVTbl = atol((char*) dbrow[3]); else rec->hkIxVTbl = 0;
			if (dbrow[4]) rec->hkUref = atoll((char*) dbrow[4]); else rec->hkUref = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->x = atof((char*) dbrow[6]); else rec->x = 0.0;
			if (dbrow[7]) rec->y = atof((char*) dbrow[7]); else rec->y = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMVertex::insertRec(
			PlnrMVertex* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxPlnrVLat,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->y,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMVertex::insertRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMVertex::updateRec(
			PlnrMVertex* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->hkIxPlnrVLat,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindDouble(&rec->x,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->y,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrMVertex::updateRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMVertex::loadRecByRef(
			ubigint ref
			, PlnrMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMVertex::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMVertex WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

ubigint MyTblPlnrMVertex::countByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

bool MyTblPlnrMVertex::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMVertex** rec
		) {
	return loadRecBySQL("SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y FROM TblPlnrMVertex WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " AND sref = '" + sref + "'", rec);
};

ubigint MyTblPlnrMVertex::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y FROM TblPlnrMVertex WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMVertex
 ******************************************************************************/

PgTblPlnrMVertex::PgTblPlnrMVertex() : TblPlnrMVertex(), PgTable() {
};

PgTblPlnrMVertex::~PgTblPlnrMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMVertex_insertRec", "INSERT INTO TblPlnrMVertex (x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMVertex_updateRec", "UPDATE TblPlnrMVertex SET x1RefPlnrMDesign = $1, hkIxPlnrVLat = $2, hkIxVTbl = $3, hkUref = $4, sref = $5, x = $6, y = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMVertex_removeRecByRef", "DELETE FROM TblPlnrMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMVertex_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y FROM TblPlnrMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMVertex_countByDsnHktHku", "SELECT COUNT(ref) FROM TblPlnrMVertex WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMVertex_countByHktHku", "SELECT COUNT(ref) FROM TblPlnrMVertex WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMVertex_loadRecByHktHkuSrf", "SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y FROM TblPlnrMVertex WHERE hkIxVTbl = $1 AND hkUref = $2 AND sref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMVertex_loadRstByDsnHktHku", "SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, x, y FROM TblPlnrMVertex WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMVertex::loadRec(
			PGresult* res
			, PlnrMVertex** rec
		) {
	char* ptr;

	PlnrMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "hkixplnrvlat"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->y = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "hkixplnrvlat"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new PlnrMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->y = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMVertex::insertRec(
			PlnrMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_x.c_str(),
		_y.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMVertex_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMVertex::insertRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMVertex::updateRec(
			PlnrMVertex* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_x.c_str(),
		_y.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMVertex_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMVertex::updateRst(
			ListPlnrMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMVertex::loadRecByRef(
			ubigint ref
			, PlnrMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMVertex::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	ubigint cnt;
	loadUbigintByStmt("TblPlnrMVertex_countByDsnHktHku", 3, vals, l, f, cnt);
	return cnt;
};

ubigint PgTblPlnrMVertex::countByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	ubigint cnt;
	loadUbigintByStmt("TblPlnrMVertex_countByHktHku", 2, vals, l, f, cnt);
	return cnt;
};

bool PgTblPlnrMVertex::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMVertex** rec
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadRecByStmt("TblPlnrMVertex_loadRecByHktHkuSrf", 3, vals, l, f, rec);
};

ubigint PgTblPlnrMVertex::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMVertex& rst
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblPlnrMVertex_loadRstByDsnHktHku", 3, vals, l, f, append, rst);
};

// IP pgTbl --- END

