/**
  * \file PlnrMStructure.cpp
  * database access for table TblPlnrMStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMStructure.h"

/******************************************************************************
 class PlnrMStructure
 ******************************************************************************/

PlnrMStructure::PlnrMStructure(
			const ubigint ref
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x0
			, const double x1
			, const double y0
			, const double y1
		) {

	this->ref = ref;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->sref = sref;
	this->x0 = x0;
	this->x1 = x1;
	this->y0 = y0;
	this->y1 = y1;
};

bool PlnrMStructure::operator==(
			const PlnrMStructure& comp
		) {
	return false;
};

bool PlnrMStructure::operator!=(
			const PlnrMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMStructure
 ******************************************************************************/

ListPlnrMStructure::ListPlnrMStructure() {
};

ListPlnrMStructure::ListPlnrMStructure(
			const ListPlnrMStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMStructure(*(src.nodes[i]));
};

ListPlnrMStructure::~ListPlnrMStructure() {
	clear();
};

void ListPlnrMStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMStructure::size() const {
	return(nodes.size());
};

void ListPlnrMStructure::append(
			PlnrMStructure* rec
		) {
	nodes.push_back(rec);
};

PlnrMStructure* ListPlnrMStructure::operator[](
			const uint ix
		) {
	PlnrMStructure* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMStructure& ListPlnrMStructure::operator=(
			const ListPlnrMStructure& src
		) {
	PlnrMStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMStructure::operator==(
			const ListPlnrMStructure& comp
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

bool ListPlnrMStructure::operator!=(
			const ListPlnrMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMStructure
 ******************************************************************************/

TblPlnrMStructure::TblPlnrMStructure() {
};

TblPlnrMStructure::~TblPlnrMStructure() {
};

bool TblPlnrMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrMStructure** rec
		) {
	return false;
};

ubigint TblPlnrMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStructure& rst
		) {
	return 0;
};

void TblPlnrMStructure::insertRec(
			PlnrMStructure* rec
		) {
};

ubigint TblPlnrMStructure::insertNewRec(
			PlnrMStructure** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x0
			, const double x1
			, const double y0
			, const double y1
		) {
	ubigint retval = 0;
	PlnrMStructure* _rec = NULL;

	_rec = new PlnrMStructure(0, hkIxVTbl, hkUref, sref, x0, x1, y0, y1);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMStructure::appendNewRecToRst(
			ListPlnrMStructure& rst
			, PlnrMStructure** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double x0
			, const double x1
			, const double y0
			, const double y1
		) {
	ubigint retval = 0;
	PlnrMStructure* _rec = NULL;

	retval = insertNewRec(&_rec, hkIxVTbl, hkUref, sref, x0, x1, y0, y1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMStructure::insertRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
};

void TblPlnrMStructure::updateRec(
			PlnrMStructure* rec
		) {
};

void TblPlnrMStructure::updateRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
};

void TblPlnrMStructure::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMStructure::loadRecByRef(
			ubigint ref
			, PlnrMStructure** rec
		) {
	return false;
};

bool TblPlnrMStructure::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMStructure::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMStructure::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMStructure& rst
		) {
	return 0;
};

bool TblPlnrMStructure::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMStructure::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMStructure& rst
		) {
	ubigint numload = 0;
	PlnrMStructure* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMStructure
 ******************************************************************************/

MyTblPlnrMStructure::MyTblPlnrMStructure() : TblPlnrMStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMStructure::~MyTblPlnrMStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMStructure (hkIxVTbl, hkUref, sref, x0, x1, y0, y1) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMStructure SET hkIxVTbl = ?, hkUref = ?, sref = ?, x0 = ?, x1 = ?, y0 = ?, y1 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMStructure WHERE ref = ?", false);
};

bool MyTblPlnrMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrMStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMStructure();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->hkIxVTbl = atol((char*) dbrow[1]); else _rec->hkIxVTbl = 0;
		if (dbrow[2]) _rec->hkUref = atoll((char*) dbrow[2]); else _rec->hkUref = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->x0 = atof((char*) dbrow[4]); else _rec->x0 = 0.0;
		if (dbrow[5]) _rec->x1 = atof((char*) dbrow[5]); else _rec->x1 = 0.0;
		if (dbrow[6]) _rec->y0 = atof((char*) dbrow[6]); else _rec->y0 = 0.0;
		if (dbrow[7]) _rec->y1 = atof((char*) dbrow[7]); else _rec->y1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMStructure();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->hkIxVTbl = atol((char*) dbrow[1]); else rec->hkIxVTbl = 0;
			if (dbrow[2]) rec->hkUref = atoll((char*) dbrow[2]); else rec->hkUref = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->x0 = atof((char*) dbrow[4]); else rec->x0 = 0.0;
			if (dbrow[5]) rec->x1 = atof((char*) dbrow[5]); else rec->x1 = 0.0;
			if (dbrow[6]) rec->y0 = atof((char*) dbrow[6]); else rec->y0 = 0.0;
			if (dbrow[7]) rec->y1 = atof((char*) dbrow[7]); else rec->y1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMStructure::insertRec(
			PlnrMStructure* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x0,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->y0,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->y1,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStructure / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStructure / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMStructure::insertRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMStructure::updateRec(
			PlnrMStructure* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindDouble(&rec->x0,&(l[3]),&(n[3]),&(e[3])), 
		bindDouble(&rec->x1,&(l[4]),&(n[4]),&(e[4])), 
		bindDouble(&rec->y0,&(l[5]),&(n[5]),&(e[5])), 
		bindDouble(&rec->y1,&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStructure / stmtUpdateRec)\n");
};

void MyTblPlnrMStructure::updateRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMStructure::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMStructure / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMStructure / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMStructure::loadRecByRef(
			ubigint ref
			, PlnrMStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMStructure WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMStructure::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " AND sref = '" + sref + "'", val);
};

ubigint MyTblPlnrMStructure::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

ubigint MyTblPlnrMStructure::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMStructure& rst
		) {
	return loadRstBySQL("SELECT ref, hkIxVTbl, hkUref, sref, x0, x1, y0, y1 FROM TblPlnrMStructure WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, rst);
};

bool MyTblPlnrMStructure::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMStructure WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMStructure
 ******************************************************************************/

PgTblPlnrMStructure::PgTblPlnrMStructure() : TblPlnrMStructure(), PgTable() {
};

PgTblPlnrMStructure::~PgTblPlnrMStructure() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMStructure_insertRec", "INSERT INTO TblPlnrMStructure (hkIxVTbl, hkUref, sref, x0, x1, y0, y1) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStructure_updateRec", "UPDATE TblPlnrMStructure SET hkIxVTbl = $1, hkUref = $2, sref = $3, x0 = $4, x1 = $5, y0 = $6, y1 = $7 WHERE ref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStructure_removeRecByRef", "DELETE FROM TblPlnrMStructure WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMStructure_loadRecByRef", "SELECT ref, hkIxVTbl, hkUref, sref, x0, x1, y0, y1 FROM TblPlnrMStructure WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMStructure_loadRefByHktHkuSrf", "SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = $1 AND hkUref = $2 AND sref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStructure_loadRefsByHktHku", "SELECT ref FROM TblPlnrMStructure WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStructure_loadRstByHktHku", "SELECT ref, hkIxVTbl, hkUref, sref, x0, x1, y0, y1 FROM TblPlnrMStructure WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMStructure_loadSrfByRef", "SELECT sref FROM TblPlnrMStructure WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMStructure::loadRec(
			PGresult* res
			, PlnrMStructure** rec
		) {
	char* ptr;

	PlnrMStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMStructure();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "x1"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "y1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->y0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->y1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMStructure* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "x1"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "y1")
		};

		while (numread < numrow) {
			rec = new PlnrMStructure();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->y0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->y1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrMStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMStructure::insertRec(
			PlnrMStructure* rec
		) {
	PGresult* res;
	char* ptr;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _x0 = to_string(rec->x0);
	string _x1 = to_string(rec->x1);
	string _y0 = to_string(rec->y0);
	string _y1 = to_string(rec->y1);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_x0.c_str(),
		_x1.c_str(),
		_y0.c_str(),
		_y1.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMStructure_insertRec", 7, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMStructure::insertRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMStructure::updateRec(
			PlnrMStructure* rec
		) {
	PGresult* res;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _x0 = to_string(rec->x0);
	string _x1 = to_string(rec->x1);
	string _y0 = to_string(rec->y0);
	string _y1 = to_string(rec->y1);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_x0.c_str(),
		_x1.c_str(),
		_y0.c_str(),
		_y1.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMStructure_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMStructure::updateRst(
			ListPlnrMStructure& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMStructure::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMStructure_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMStructure_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMStructure::loadRecByRef(
			ubigint ref
			, PlnrMStructure** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMStructure_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMStructure::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
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

	return loadUbigintByStmt("TblPlnrMStructure_loadRefByHktHkuSrf", 3, vals, l, f, val);
};

ubigint PgTblPlnrMStructure::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
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

	return loadRefsByStmt("TblPlnrMStructure_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

ubigint PgTblPlnrMStructure::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMStructure& rst
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

	return loadRstByStmt("TblPlnrMStructure_loadRstByHktHku", 2, vals, l, f, append, rst);
};

bool PgTblPlnrMStructure::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblPlnrMStructure_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

