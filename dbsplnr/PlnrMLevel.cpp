/**
  * \file PlnrMLevel.cpp
  * database access for table TblPlnrMLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMLevel.h"

/******************************************************************************
 class PlnrMLevel
 ******************************************************************************/

PlnrMLevel::PlnrMLevel(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double z
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->sref = sref;
	this->z = z;
};

bool PlnrMLevel::operator==(
			const PlnrMLevel& comp
		) {
	return false;
};

bool PlnrMLevel::operator!=(
			const PlnrMLevel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMLevel
 ******************************************************************************/

ListPlnrMLevel::ListPlnrMLevel() {
};

ListPlnrMLevel::ListPlnrMLevel(
			const ListPlnrMLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMLevel(*(src.nodes[i]));
};

ListPlnrMLevel::~ListPlnrMLevel() {
	clear();
};

void ListPlnrMLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMLevel::size() const {
	return(nodes.size());
};

void ListPlnrMLevel::append(
			PlnrMLevel* rec
		) {
	nodes.push_back(rec);
};

PlnrMLevel* ListPlnrMLevel::operator[](
			const uint ix
		) {
	PlnrMLevel* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMLevel& ListPlnrMLevel::operator=(
			const ListPlnrMLevel& src
		) {
	PlnrMLevel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMLevel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMLevel::operator==(
			const ListPlnrMLevel& comp
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

bool ListPlnrMLevel::operator!=(
			const ListPlnrMLevel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMLevel
 ******************************************************************************/

TblPlnrMLevel::TblPlnrMLevel() {
};

TblPlnrMLevel::~TblPlnrMLevel() {
};

bool TblPlnrMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrMLevel** rec
		) {
	return false;
};

ubigint TblPlnrMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLevel& rst
		) {
	return 0;
};

void TblPlnrMLevel::insertRec(
			PlnrMLevel* rec
		) {
};

ubigint TblPlnrMLevel::insertNewRec(
			PlnrMLevel** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double z
		) {
	ubigint retval = 0;
	PlnrMLevel* _rec = NULL;

	_rec = new PlnrMLevel(0, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMLevel::appendNewRecToRst(
			ListPlnrMLevel& rst
			, PlnrMLevel** rec
			, const ubigint x1RefPlnrMDesign
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const double z
		) {
	ubigint retval = 0;
	PlnrMLevel* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMLevel::insertRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
};

void TblPlnrMLevel::updateRec(
			PlnrMLevel* rec
		) {
};

void TblPlnrMLevel::updateRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
};

void TblPlnrMLevel::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMLevel::loadRecByRef(
			ubigint ref
			, PlnrMLevel** rec
		) {
	return false;
};

ubigint TblPlnrMLevel::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

ubigint TblPlnrMLevel::countByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

bool TblPlnrMLevel::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMLevel** rec
		) {
	return false;
};

ubigint TblPlnrMLevel::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLevel& rst
		) {
	return 0;
};

ubigint TblPlnrMLevel::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMLevel& rst
		) {
	ubigint numload = 0;
	PlnrMLevel* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMLevel
 ******************************************************************************/

MyTblPlnrMLevel::MyTblPlnrMLevel() : TblPlnrMLevel(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMLevel::~MyTblPlnrMLevel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMLevel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMLevel (x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMLevel SET x1RefPlnrMDesign = ?, hkIxVTbl = ?, hkUref = ?, sref = ?, z = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMLevel WHERE ref = ?", false);
};

bool MyTblPlnrMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrMLevel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMLevel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLevel / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMLevel();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->hkIxVTbl = atol((char*) dbrow[2]); else _rec->hkIxVTbl = 0;
		if (dbrow[3]) _rec->hkUref = atoll((char*) dbrow[3]); else _rec->hkUref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->z = atof((char*) dbrow[5]); else _rec->z = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLevel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMLevel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLevel / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMLevel();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->hkIxVTbl = atol((char*) dbrow[2]); else rec->hkIxVTbl = 0;
			if (dbrow[3]) rec->hkUref = atoll((char*) dbrow[3]); else rec->hkUref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->z = atof((char*) dbrow[5]); else rec->z = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMLevel::insertRec(
			PlnrMLevel* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->z,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLevel / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLevel / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMLevel::insertRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMLevel::updateRec(
			PlnrMLevel* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindDouble(&rec->z,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLevel / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLevel / stmtUpdateRec)\n");
};

void MyTblPlnrMLevel::updateRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMLevel::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLevel / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLevel / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMLevel::loadRecByRef(
			ubigint ref
			, PlnrMLevel** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMLevel WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMLevel::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMLevel WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

ubigint MyTblPlnrMLevel::countByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

bool MyTblPlnrMLevel::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMLevel** rec
		) {
	return loadRecBySQL("SELECT ref, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z FROM TblPlnrMLevel WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " AND sref = '" + sref + "'", rec);
};

ubigint MyTblPlnrMLevel::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLevel& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z FROM TblPlnrMLevel WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY z ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMLevel
 ******************************************************************************/

PgTblPlnrMLevel::PgTblPlnrMLevel() : TblPlnrMLevel(), PgTable() {
};

PgTblPlnrMLevel::~PgTblPlnrMLevel() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMLevel::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMLevel_insertRec", "INSERT INTO TblPlnrMLevel (x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLevel_updateRec", "UPDATE TblPlnrMLevel SET x1RefPlnrMDesign = $1, hkIxVTbl = $2, hkUref = $3, sref = $4, z = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLevel_removeRecByRef", "DELETE FROM TblPlnrMLevel WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMLevel_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z FROM TblPlnrMLevel WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMLevel_countByDsnHktHku", "SELECT COUNT(ref) FROM TblPlnrMLevel WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLevel_countByHktHku", "SELECT COUNT(ref) FROM TblPlnrMLevel WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLevel_loadRecByHktHkuSrf", "SELECT ref, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z FROM TblPlnrMLevel WHERE hkIxVTbl = $1 AND hkUref = $2 AND sref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLevel_loadRstByDsnHktHku", "SELECT ref, x1RefPlnrMDesign, hkIxVTbl, hkUref, sref, z FROM TblPlnrMLevel WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3 ORDER BY z ASC", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMLevel::loadRec(
			PGresult* res
			, PlnrMLevel** rec
		) {
	char* ptr;

	PlnrMLevel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMLevel();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "z")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->z = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMLevel::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMLevel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMLevel* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "z")
		};

		while (numread < numrow) {
			rec = new PlnrMLevel();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->z = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMLevel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMLevel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLevel / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMLevel::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMLevel& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLevel / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrMLevel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLevel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMLevel::insertRec(
			PlnrMLevel* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _z = to_string(rec->z);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_z.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMLevel_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLevel_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMLevel::insertRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMLevel::updateRec(
			PlnrMLevel* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	string _z = to_string(rec->z);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		_z.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMLevel_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLevel_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMLevel::updateRst(
			ListPlnrMLevel& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMLevel::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMLevel_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLevel_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMLevel::loadRecByRef(
			ubigint ref
			, PlnrMLevel** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMLevel_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMLevel::countByDsnHktHku(
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
	loadUbigintByStmt("TblPlnrMLevel_countByDsnHktHku", 3, vals, l, f, cnt);
	return cnt;
};

ubigint PgTblPlnrMLevel::countByHktHku(
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
	loadUbigintByStmt("TblPlnrMLevel_countByHktHku", 2, vals, l, f, cnt);
	return cnt;
};

bool PgTblPlnrMLevel::loadRecByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, PlnrMLevel** rec
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

	return loadRecByStmt("TblPlnrMLevel_loadRecByHktHkuSrf", 3, vals, l, f, rec);
};

ubigint PgTblPlnrMLevel::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLevel& rst
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

	return loadRstByStmt("TblPlnrMLevel_loadRstByDsnHktHku", 3, vals, l, f, append, rst);
};

// IP pgTbl --- END

