/**
  * \file PlnrMArcguide.cpp
  * database access for table TblPlnrMArcguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMArcguide.h"

/******************************************************************************
 class PlnrMArcguide
 ******************************************************************************/

PlnrMArcguide::PlnrMArcguide(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMArcguide
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const ubigint ctrRefPlnrMVertex
			, const double r
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->devRefPlnrMArcguide = devRefPlnrMArcguide;
	this->hkIxPlnrVLat = hkIxPlnrVLat;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->sref = sref;
	this->ctrRefPlnrMVertex = ctrRefPlnrMVertex;
	this->r = r;
};

bool PlnrMArcguide::operator==(
			const PlnrMArcguide& comp
		) {
	return false;
};

bool PlnrMArcguide::operator!=(
			const PlnrMArcguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMArcguide
 ******************************************************************************/

ListPlnrMArcguide::ListPlnrMArcguide() {
};

ListPlnrMArcguide::ListPlnrMArcguide(
			const ListPlnrMArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMArcguide(*(src.nodes[i]));
};

ListPlnrMArcguide::~ListPlnrMArcguide() {
	clear();
};

void ListPlnrMArcguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMArcguide::size() const {
	return(nodes.size());
};

void ListPlnrMArcguide::append(
			PlnrMArcguide* rec
		) {
	nodes.push_back(rec);
};

PlnrMArcguide* ListPlnrMArcguide::operator[](
			const uint ix
		) {
	PlnrMArcguide* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMArcguide& ListPlnrMArcguide::operator=(
			const ListPlnrMArcguide& src
		) {
	PlnrMArcguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMArcguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMArcguide::operator==(
			const ListPlnrMArcguide& comp
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

bool ListPlnrMArcguide::operator!=(
			const ListPlnrMArcguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMArcguide
 ******************************************************************************/

TblPlnrMArcguide::TblPlnrMArcguide() {
};

TblPlnrMArcguide::~TblPlnrMArcguide() {
};

bool TblPlnrMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMArcguide** rec
		) {
	return false;
};

ubigint TblPlnrMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	return 0;
};

void TblPlnrMArcguide::insertRec(
			PlnrMArcguide* rec
		) {
};

ubigint TblPlnrMArcguide::insertNewRec(
			PlnrMArcguide** rec
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMArcguide
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const ubigint ctrRefPlnrMVertex
			, const double r
		) {
	ubigint retval = 0;
	PlnrMArcguide* _rec = NULL;

	_rec = new PlnrMArcguide(0, x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMArcguide::appendNewRecToRst(
			ListPlnrMArcguide& rst
			, PlnrMArcguide** rec
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMArcguide
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const ubigint ctrRefPlnrMVertex
			, const double r
		) {
	ubigint retval = 0;
	PlnrMArcguide* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMArcguide::insertRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
};

void TblPlnrMArcguide::updateRec(
			PlnrMArcguide* rec
		) {
};

void TblPlnrMArcguide::updateRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
};

void TblPlnrMArcguide::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMArcguide::loadRecByRef(
			ubigint ref
			, PlnrMArcguide** rec
		) {
	return false;
};

ubigint TblPlnrMArcguide::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

ubigint TblPlnrMArcguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	return 0;
};

ubigint TblPlnrMArcguide::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	ubigint numload = 0;
	PlnrMArcguide* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMArcguide
 ******************************************************************************/

MyTblPlnrMArcguide::MyTblPlnrMArcguide() : TblPlnrMArcguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMArcguide::~MyTblPlnrMArcguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMArcguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMArcguide (x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMArcguide SET x1RefPlnrMDesign = ?, devRefPlnrMArcguide = ?, hkIxPlnrVLat = ?, hkIxVTbl = ?, hkUref = ?, sref = ?, ctrRefPlnrMVertex = ?, r = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMArcguide WHERE ref = ?", false);
};

bool MyTblPlnrMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMArcguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMArcguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArcguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMArcguide();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->devRefPlnrMArcguide = atoll((char*) dbrow[2]); else _rec->devRefPlnrMArcguide = 0;
		if (dbrow[3]) _rec->hkIxPlnrVLat = atol((char*) dbrow[3]); else _rec->hkIxPlnrVLat = 0;
		if (dbrow[4]) _rec->hkIxVTbl = atol((char*) dbrow[4]); else _rec->hkIxVTbl = 0;
		if (dbrow[5]) _rec->hkUref = atoll((char*) dbrow[5]); else _rec->hkUref = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->ctrRefPlnrMVertex = atoll((char*) dbrow[7]); else _rec->ctrRefPlnrMVertex = 0;
		if (dbrow[8]) _rec->r = atof((char*) dbrow[8]); else _rec->r = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMArcguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMArcguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMArcguide();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->devRefPlnrMArcguide = atoll((char*) dbrow[2]); else rec->devRefPlnrMArcguide = 0;
			if (dbrow[3]) rec->hkIxPlnrVLat = atol((char*) dbrow[3]); else rec->hkIxPlnrVLat = 0;
			if (dbrow[4]) rec->hkIxVTbl = atol((char*) dbrow[4]); else rec->hkIxVTbl = 0;
			if (dbrow[5]) rec->hkUref = atoll((char*) dbrow[5]); else rec->hkUref = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->ctrRefPlnrMVertex = atoll((char*) dbrow[7]); else rec->ctrRefPlnrMVertex = 0;
			if (dbrow[8]) rec->r = atof((char*) dbrow[8]); else rec->r = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMArcguide::insertRec(
			PlnrMArcguide* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[5] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->devRefPlnrMArcguide,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxPlnrVLat,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->hkUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ctrRefPlnrMVertex,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->r,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArcguide / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArcguide / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMArcguide::insertRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMArcguide::updateRec(
			PlnrMArcguide* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[5] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->devRefPlnrMArcguide,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->hkIxPlnrVLat,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->hkIxVTbl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->hkUref,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ctrRefPlnrMVertex,&(l[6]),&(n[6]),&(e[6])), 
		bindDouble(&rec->r,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArcguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArcguide / stmtUpdateRec)\n");
};

void MyTblPlnrMArcguide::updateRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMArcguide::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMArcguide / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMArcguide / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMArcguide::loadRecByRef(
			ubigint ref
			, PlnrMArcguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMArcguide WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMArcguide::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMArcguide WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

ubigint MyTblPlnrMArcguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r FROM TblPlnrMArcguide WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMArcguide
 ******************************************************************************/

PgTblPlnrMArcguide::PgTblPlnrMArcguide() : TblPlnrMArcguide(), PgTable() {
};

PgTblPlnrMArcguide::~PgTblPlnrMArcguide() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMArcguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMArcguide_insertRec", "INSERT INTO TblPlnrMArcguide (x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArcguide_updateRec", "UPDATE TblPlnrMArcguide SET x1RefPlnrMDesign = $1, devRefPlnrMArcguide = $2, hkIxPlnrVLat = $3, hkIxVTbl = $4, hkUref = $5, sref = $6, ctrRefPlnrMVertex = $7, r = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArcguide_removeRecByRef", "DELETE FROM TblPlnrMArcguide WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMArcguide_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r FROM TblPlnrMArcguide WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMArcguide_countByDsnHktHku", "SELECT COUNT(ref) FROM TblPlnrMArcguide WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMArcguide_loadRstByDsnHktHku", "SELECT ref, x1RefPlnrMDesign, devRefPlnrMArcguide, hkIxPlnrVLat, hkIxVTbl, hkUref, sref, ctrRefPlnrMVertex, r FROM TblPlnrMArcguide WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMArcguide::loadRec(
			PGresult* res
			, PlnrMArcguide** rec
		) {
	char* ptr;

	PlnrMArcguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMArcguide();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "devrefplnrmarcguide"),
			PQfnumber(res, "hkixplnrvlat"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ctrrefplnrmvertex"),
			PQfnumber(res, "r")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->devRefPlnrMArcguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ctrRefPlnrMVertex = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->r = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMArcguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMArcguide* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "devrefplnrmarcguide"),
			PQfnumber(res, "hkixplnrvlat"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ctrrefplnrmvertex"),
			PQfnumber(res, "r")
		};

		while (numread < numrow) {
			rec = new PlnrMArcguide();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->devRefPlnrMArcguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ctrRefPlnrMVertex = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->r = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMArcguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMArcguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArcguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMArcguide::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArcguide / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMArcguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMArcguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMArcguide::insertRec(
			PlnrMArcguide* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _devRefPlnrMArcguide = htonl64(rec->devRefPlnrMArcguide);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _ctrRefPlnrMVertex = htonl64(rec->ctrRefPlnrMVertex);
	string _r = to_string(rec->r);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_devRefPlnrMArcguide,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		(char*) &_ctrRefPlnrMVertex,
		_r.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMArcguide_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArcguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMArcguide::insertRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMArcguide::updateRec(
			PlnrMArcguide* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _devRefPlnrMArcguide = htonl64(rec->devRefPlnrMArcguide);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _ctrRefPlnrMVertex = htonl64(rec->ctrRefPlnrMVertex);
	string _r = to_string(rec->r);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_devRefPlnrMArcguide,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		(char*) &_ctrRefPlnrMVertex,
		_r.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMArcguide_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArcguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMArcguide::updateRst(
			ListPlnrMArcguide& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMArcguide::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMArcguide_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMArcguide_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMArcguide::loadRecByRef(
			ubigint ref
			, PlnrMArcguide** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMArcguide_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMArcguide::countByDsnHktHku(
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
	loadUbigintByStmt("TblPlnrMArcguide_countByDsnHktHku", 3, vals, l, f, cnt);
	return cnt;
};

ubigint PgTblPlnrMArcguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMArcguide& rst
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

	return loadRstByStmt("TblPlnrMArcguide_loadRstByDsnHktHku", 3, vals, l, f, append, rst);
};

// IP pgTbl --- END

