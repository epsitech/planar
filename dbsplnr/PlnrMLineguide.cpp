/**
  * \file PlnrMLineguide.cpp
  * database access for table TblPlnrMLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMLineguide.h"

/******************************************************************************
 class PlnrMLineguide
 ******************************************************************************/

PlnrMLineguide::PlnrMLineguide(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->hkIxPlnrVLat = hkIxPlnrVLat;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->sref = sref;
};

bool PlnrMLineguide::operator==(
			const PlnrMLineguide& comp
		) {
	return false;
};

bool PlnrMLineguide::operator!=(
			const PlnrMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMLineguide
 ******************************************************************************/

ListPlnrMLineguide::ListPlnrMLineguide() {
};

ListPlnrMLineguide::ListPlnrMLineguide(
			const ListPlnrMLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMLineguide(*(src.nodes[i]));
};

ListPlnrMLineguide::~ListPlnrMLineguide() {
	clear();
};

void ListPlnrMLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMLineguide::size() const {
	return(nodes.size());
};

void ListPlnrMLineguide::append(
			PlnrMLineguide* rec
		) {
	nodes.push_back(rec);
};

PlnrMLineguide* ListPlnrMLineguide::operator[](
			const uint ix
		) {
	PlnrMLineguide* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMLineguide& ListPlnrMLineguide::operator=(
			const ListPlnrMLineguide& src
		) {
	PlnrMLineguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMLineguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMLineguide::operator==(
			const ListPlnrMLineguide& comp
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

bool ListPlnrMLineguide::operator!=(
			const ListPlnrMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMLineguide
 ******************************************************************************/

TblPlnrMLineguide::TblPlnrMLineguide() {
};

TblPlnrMLineguide::~TblPlnrMLineguide() {
};

bool TblPlnrMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	return 0;
};

void TblPlnrMLineguide::insertRec(
			PlnrMLineguide* rec
		) {
};

ubigint TblPlnrMLineguide::insertNewRec(
			PlnrMLineguide** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
		) {
	ubigint retval = 0;
	PlnrMLineguide* _rec = NULL;

	_rec = new PlnrMLineguide(0, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMLineguide::appendNewRecToRst(
			ListPlnrMLineguide& rst
			, PlnrMLineguide** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxPlnrVLat
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
		) {
	ubigint retval = 0;
	PlnrMLineguide* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMLineguide::insertRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
};

void TblPlnrMLineguide::updateRec(
			PlnrMLineguide* rec
		) {
};

void TblPlnrMLineguide::updateRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
};

void TblPlnrMLineguide::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMLineguide::loadRecByRef(
			ubigint ref
			, PlnrMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrMLineguide::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

ubigint TblPlnrMLineguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	return 0;
};

ubigint TblPlnrMLineguide::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	ubigint numload = 0;
	PlnrMLineguide* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMLineguide
 ******************************************************************************/

MyTblPlnrMLineguide::MyTblPlnrMLineguide() : TblPlnrMLineguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMLineguide::~MyTblPlnrMLineguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMLineguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMLineguide (x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMLineguide SET x1RefPlnrMDesign = ?, hkIxPlnrVLat = ?, hkIxVTbl = ?, hkUref = ?, sref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMLineguide WHERE ref = ?", false);
};

bool MyTblPlnrMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMLineguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMLineguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLineguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMLineguide();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->hkIxPlnrVLat = atol((char*) dbrow[2]); else _rec->hkIxPlnrVLat = 0;
		if (dbrow[3]) _rec->hkIxVTbl = atol((char*) dbrow[3]); else _rec->hkIxVTbl = 0;
		if (dbrow[4]) _rec->hkUref = atoll((char*) dbrow[4]); else _rec->hkUref = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMLineguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLineguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMLineguide();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->hkIxPlnrVLat = atol((char*) dbrow[2]); else rec->hkIxPlnrVLat = 0;
			if (dbrow[3]) rec->hkIxVTbl = atol((char*) dbrow[3]); else rec->hkIxVTbl = 0;
			if (dbrow[4]) rec->hkUref = atoll((char*) dbrow[4]); else rec->hkUref = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMLineguide::insertRec(
			PlnrMLineguide* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxPlnrVLat,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLineguide / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLineguide / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMLineguide::insertRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMLineguide::updateRec(
			PlnrMLineguide* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->hkIxPlnrVLat,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLineguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLineguide / stmtUpdateRec)\n");
};

void MyTblPlnrMLineguide::updateRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMLineguide::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLineguide / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLineguide / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMLineguide::loadRecByRef(
			ubigint ref
			, PlnrMLineguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMLineguide WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMLineguide::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMLineguide WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

ubigint MyTblPlnrMLineguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref FROM TblPlnrMLineguide WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMLineguide
 ******************************************************************************/

PgTblPlnrMLineguide::PgTblPlnrMLineguide() : TblPlnrMLineguide(), PgTable() {
};

PgTblPlnrMLineguide::~PgTblPlnrMLineguide() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMLineguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMLineguide_insertRec", "INSERT INTO TblPlnrMLineguide (x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLineguide_updateRec", "UPDATE TblPlnrMLineguide SET x1RefPlnrMDesign = $1, hkIxPlnrVLat = $2, hkIxVTbl = $3, hkUref = $4, sref = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLineguide_removeRecByRef", "DELETE FROM TblPlnrMLineguide WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMLineguide_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref FROM TblPlnrMLineguide WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMLineguide_countByDsnHktHku", "SELECT COUNT(ref) FROM TblPlnrMLineguide WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLineguide_loadRstByDsnHktHku", "SELECT ref, x1RefPlnrMDesign, hkIxPlnrVLat, hkIxVTbl, hkUref, sref FROM TblPlnrMLineguide WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMLineguide::loadRec(
			PGresult* res
			, PlnrMLineguide** rec
		) {
	char* ptr;

	PlnrMLineguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMLineguide();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "hkixplnrvlat"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMLineguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMLineguide* rec;

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
			PQfnumber(res, "sref")
		};

		while (numread < numrow) {
			rec = new PlnrMLineguide();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMLineguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMLineguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLineguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMLineguide::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLineguide / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrMLineguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLineguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMLineguide::insertRec(
			PlnrMLineguide* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMLineguide_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLineguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMLineguide::insertRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMLineguide::updateRec(
			PlnrMLineguide* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxPlnrVLat = htonl(rec->hkIxPlnrVLat);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxPlnrVLat,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMLineguide_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLineguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMLineguide::updateRst(
			ListPlnrMLineguide& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMLineguide::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMLineguide_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLineguide_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMLineguide::loadRecByRef(
			ubigint ref
			, PlnrMLineguide** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMLineguide_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMLineguide::countByDsnHktHku(
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
	loadUbigintByStmt("TblPlnrMLineguide_countByDsnHktHku", 3, vals, l, f, cnt);
	return cnt;
};

ubigint PgTblPlnrMLineguide::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLineguide& rst
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

	return loadRstByStmt("TblPlnrMLineguide_loadRstByDsnHktHku", 3, vals, l, f, append, rst);
};

// IP pgTbl --- END

