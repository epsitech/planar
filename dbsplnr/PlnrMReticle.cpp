/**
  * \file PlnrMReticle.cpp
  * database access for table TblPlnrMReticle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMReticle.h"

/******************************************************************************
 class PlnrMReticle
 ******************************************************************************/

PlnrMReticle::PlnrMReticle(
			const ubigint ref
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string sref
			, const double x0
			, const double y0
			, const double phi
		) {

	this->ref = ref;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->refPlnrMDesign = refPlnrMDesign;
	this->refPlnrMLayer = refPlnrMLayer;
	this->sref = sref;
	this->x0 = x0;
	this->y0 = y0;
	this->phi = phi;
};

bool PlnrMReticle::operator==(
			const PlnrMReticle& comp
		) {
	return false;
};

bool PlnrMReticle::operator!=(
			const PlnrMReticle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMReticle
 ******************************************************************************/

ListPlnrMReticle::ListPlnrMReticle() {
};

ListPlnrMReticle::ListPlnrMReticle(
			const ListPlnrMReticle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMReticle(*(src.nodes[i]));
};

ListPlnrMReticle::~ListPlnrMReticle() {
	clear();
};

void ListPlnrMReticle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMReticle::size() const {
	return(nodes.size());
};

void ListPlnrMReticle::append(
			PlnrMReticle* rec
		) {
	nodes.push_back(rec);
};

PlnrMReticle* ListPlnrMReticle::operator[](
			const uint ix
		) {
	PlnrMReticle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMReticle& ListPlnrMReticle::operator=(
			const ListPlnrMReticle& src
		) {
	PlnrMReticle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMReticle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMReticle::operator==(
			const ListPlnrMReticle& comp
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

bool ListPlnrMReticle::operator!=(
			const ListPlnrMReticle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMReticle
 ******************************************************************************/

TblPlnrMReticle::TblPlnrMReticle() {
};

TblPlnrMReticle::~TblPlnrMReticle() {
};

bool TblPlnrMReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrMReticle** rec
		) {
	return false;
};

ubigint TblPlnrMReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMReticle& rst
		) {
	return 0;
};

void TblPlnrMReticle::insertRec(
			PlnrMReticle* rec
		) {
};

ubigint TblPlnrMReticle::insertNewRec(
			PlnrMReticle** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string sref
			, const double x0
			, const double y0
			, const double phi
		) {
	ubigint retval = 0;
	PlnrMReticle* _rec = NULL;

	_rec = new PlnrMReticle(0, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMReticle::appendNewRecToRst(
			ListPlnrMReticle& rst
			, PlnrMReticle** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMLayer
			, const string sref
			, const double x0
			, const double y0
			, const double phi
		) {
	ubigint retval = 0;
	PlnrMReticle* _rec = NULL;

	retval = insertNewRec(&_rec, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMReticle::insertRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
};

void TblPlnrMReticle::updateRec(
			PlnrMReticle* rec
		) {
};

void TblPlnrMReticle::updateRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
};

void TblPlnrMReticle::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMReticle::loadRecByRef(
			ubigint ref
			, PlnrMReticle** rec
		) {
	return false;
};

ubigint TblPlnrMReticle::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMReticle& rst
		) {
	return 0;
};

ubigint TblPlnrMReticle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMReticle& rst
		) {
	ubigint numload = 0;
	PlnrMReticle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMReticle
 ******************************************************************************/

MyTblPlnrMReticle::MyTblPlnrMReticle() : TblPlnrMReticle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMReticle::~MyTblPlnrMReticle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMReticle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMReticle (hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMReticle SET hkIxVTbl = ?, hkUref = ?, refPlnrMDesign = ?, refPlnrMLayer = ?, sref = ?, x0 = ?, y0 = ?, phi = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMReticle WHERE ref = ?", false);
};

bool MyTblPlnrMReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrMReticle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMReticle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMReticle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMReticle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->hkIxVTbl = atol((char*) dbrow[1]); else _rec->hkIxVTbl = 0;
		if (dbrow[2]) _rec->hkUref = atoll((char*) dbrow[2]); else _rec->hkUref = 0;
		if (dbrow[3]) _rec->refPlnrMDesign = atoll((char*) dbrow[3]); else _rec->refPlnrMDesign = 0;
		if (dbrow[4]) _rec->refPlnrMLayer = atoll((char*) dbrow[4]); else _rec->refPlnrMLayer = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->x0 = atof((char*) dbrow[6]); else _rec->x0 = 0.0;
		if (dbrow[7]) _rec->y0 = atof((char*) dbrow[7]); else _rec->y0 = 0.0;
		if (dbrow[8]) _rec->phi = atof((char*) dbrow[8]); else _rec->phi = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMReticle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMReticle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMReticle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMReticle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->hkIxVTbl = atol((char*) dbrow[1]); else rec->hkIxVTbl = 0;
			if (dbrow[2]) rec->hkUref = atoll((char*) dbrow[2]); else rec->hkUref = 0;
			if (dbrow[3]) rec->refPlnrMDesign = atoll((char*) dbrow[3]); else rec->refPlnrMDesign = 0;
			if (dbrow[4]) rec->refPlnrMLayer = atoll((char*) dbrow[4]); else rec->refPlnrMLayer = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->x0 = atof((char*) dbrow[6]); else rec->x0 = 0.0;
			if (dbrow[7]) rec->y0 = atof((char*) dbrow[7]); else rec->y0 = 0.0;
			if (dbrow[8]) rec->phi = atof((char*) dbrow[8]); else rec->phi = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMReticle::insertRec(
			PlnrMReticle* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMDesign,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMLayer,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x0,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->y0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->phi,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMReticle / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMReticle / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMReticle::insertRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMReticle::updateRec(
			PlnrMReticle* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMLayer,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindDouble(&rec->x0,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->y0,&(l[6]),&(n[6]),&(e[6])), 
		bindDouble(&rec->phi,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMReticle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMReticle / stmtUpdateRec)\n");
};

void MyTblPlnrMReticle::updateRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMReticle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMReticle / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMReticle / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMReticle::loadRecByRef(
			ubigint ref
			, PlnrMReticle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMReticle WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMReticle::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMReticle& rst
		) {
	return loadRstBySQL("SELECT ref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi FROM TblPlnrMReticle WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY refPlnrMDesign ASC, refPlnrMLayer ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMReticle
 ******************************************************************************/

PgTblPlnrMReticle::PgTblPlnrMReticle() : TblPlnrMReticle(), PgTable() {
};

PgTblPlnrMReticle::~PgTblPlnrMReticle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMReticle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMReticle_insertRec", "INSERT INTO TblPlnrMReticle (hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMReticle_updateRec", "UPDATE TblPlnrMReticle SET hkIxVTbl = $1, hkUref = $2, refPlnrMDesign = $3, refPlnrMLayer = $4, sref = $5, x0 = $6, y0 = $7, phi = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMReticle_removeRecByRef", "DELETE FROM TblPlnrMReticle WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMReticle_loadRecByRef", "SELECT ref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi FROM TblPlnrMReticle WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMReticle_loadRstByHktHku", "SELECT ref, hkIxVTbl, hkUref, refPlnrMDesign, refPlnrMLayer, sref, x0, y0, phi FROM TblPlnrMReticle WHERE hkIxVTbl = $1 AND hkUref = $2 ORDER BY refPlnrMDesign ASC, refPlnrMLayer ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMReticle::loadRec(
			PGresult* res
			, PlnrMReticle** rec
		) {
	char* ptr;

	PlnrMReticle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMReticle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "phi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMLayer = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->y0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->phi = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMReticle::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMReticle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMReticle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "phi")
		};

		while (numread < numrow) {
			rec = new PlnrMReticle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMLayer = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->y0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->phi = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMReticle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMReticle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMReticle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMReticle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMReticle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMReticle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMReticle::loadRecBySQL(
			const string& sqlstr
			, PlnrMReticle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMReticle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMReticle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMReticle::insertRec(
			PlnrMReticle* rec
		) {
	PGresult* res;
	char* ptr;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _phi = to_string(rec->phi);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMLayer,
		rec->sref.c_str(),
		_x0.c_str(),
		_y0.c_str(),
		_phi.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMReticle_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMReticle_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMReticle::insertRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMReticle::updateRec(
			PlnrMReticle* rec
		) {
	PGresult* res;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _phi = to_string(rec->phi);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMLayer,
		rec->sref.c_str(),
		_x0.c_str(),
		_y0.c_str(),
		_phi.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMReticle_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMReticle_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMReticle::updateRst(
			ListPlnrMReticle& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMReticle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMReticle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMReticle_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMReticle::loadRecByRef(
			ubigint ref
			, PlnrMReticle** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMReticle_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMReticle::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMReticle& rst
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

	return loadRstByStmt("TblPlnrMReticle_loadRstByHktHku", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

