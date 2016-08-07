/**
  * \file PlnrMFace.cpp
  * database access for table TblPlnrMFace (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMFace.h"

/******************************************************************************
 class PlnrMFace
 ******************************************************************************/

PlnrMFace::PlnrMFace(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMFace
			, const uint sruIxPlnrVLat
			, const ubigint sruRefPlnrMStructure
			, const string sref
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->devRefPlnrMFace = devRefPlnrMFace;
	this->sruIxPlnrVLat = sruIxPlnrVLat;
	this->sruRefPlnrMStructure = sruRefPlnrMStructure;
	this->sref = sref;
};

bool PlnrMFace::operator==(
			const PlnrMFace& comp
		) {
	return false;
};

bool PlnrMFace::operator!=(
			const PlnrMFace& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMFace
 ******************************************************************************/

ListPlnrMFace::ListPlnrMFace() {
};

ListPlnrMFace::ListPlnrMFace(
			const ListPlnrMFace& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMFace(*(src.nodes[i]));
};

ListPlnrMFace::~ListPlnrMFace() {
	clear();
};

void ListPlnrMFace::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMFace::size() const {
	return(nodes.size());
};

void ListPlnrMFace::append(
			PlnrMFace* rec
		) {
	nodes.push_back(rec);
};

PlnrMFace* ListPlnrMFace::operator[](
			const uint ix
		) {
	PlnrMFace* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMFace& ListPlnrMFace::operator=(
			const ListPlnrMFace& src
		) {
	PlnrMFace* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMFace(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMFace::operator==(
			const ListPlnrMFace& comp
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

bool ListPlnrMFace::operator!=(
			const ListPlnrMFace& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMFace
 ******************************************************************************/

TblPlnrMFace::TblPlnrMFace() {
};

TblPlnrMFace::~TblPlnrMFace() {
};

bool TblPlnrMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrMFace** rec
		) {
	return false;
};

ubigint TblPlnrMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFace& rst
		) {
	return 0;
};

void TblPlnrMFace::insertRec(
			PlnrMFace* rec
		) {
};

ubigint TblPlnrMFace::insertNewRec(
			PlnrMFace** rec
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMFace
			, const uint sruIxPlnrVLat
			, const ubigint sruRefPlnrMStructure
			, const string sref
		) {
	ubigint retval = 0;
	PlnrMFace* _rec = NULL;

	_rec = new PlnrMFace(0, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMFace::appendNewRecToRst(
			ListPlnrMFace& rst
			, PlnrMFace** rec
			, const ubigint x1RefPlnrMDesign
			, const ubigint devRefPlnrMFace
			, const uint sruIxPlnrVLat
			, const ubigint sruRefPlnrMStructure
			, const string sref
		) {
	ubigint retval = 0;
	PlnrMFace* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMFace::insertRst(
			ListPlnrMFace& rst
			, bool transact
		) {
};

void TblPlnrMFace::updateRec(
			PlnrMFace* rec
		) {
};

void TblPlnrMFace::updateRst(
			ListPlnrMFace& rst
			, bool transact
		) {
};

void TblPlnrMFace::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMFace::loadRecByRef(
			ubigint ref
			, PlnrMFace** rec
		) {
	return false;
};

ubigint TblPlnrMFace::countByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
		) {
	return 0;
};

ubigint TblPlnrMFace::loadRstByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	return 0;
};

ubigint TblPlnrMFace::loadRstBySru(
			ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	return 0;
};

ubigint TblPlnrMFace::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMFace& rst
		) {
	ubigint numload = 0;
	PlnrMFace* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMFace
 ******************************************************************************/

MyTblPlnrMFace::MyTblPlnrMFace() : TblPlnrMFace(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMFace::~MyTblPlnrMFace() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMFace::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMFace (x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMFace SET x1RefPlnrMDesign = ?, devRefPlnrMFace = ?, sruIxPlnrVLat = ?, sruRefPlnrMStructure = ?, sref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMFace WHERE ref = ?", false);
};

bool MyTblPlnrMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrMFace** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMFace* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMFace / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMFace();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->devRefPlnrMFace = atoll((char*) dbrow[2]); else _rec->devRefPlnrMFace = 0;
		if (dbrow[3]) _rec->sruIxPlnrVLat = atol((char*) dbrow[3]); else _rec->sruIxPlnrVLat = 0;
		if (dbrow[4]) _rec->sruRefPlnrMStructure = atoll((char*) dbrow[4]); else _rec->sruRefPlnrMStructure = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFace& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMFace* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMFace / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMFace();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->devRefPlnrMFace = atoll((char*) dbrow[2]); else rec->devRefPlnrMFace = 0;
			if (dbrow[3]) rec->sruIxPlnrVLat = atol((char*) dbrow[3]); else rec->sruIxPlnrVLat = 0;
			if (dbrow[4]) rec->sruRefPlnrMStructure = atoll((char*) dbrow[4]); else rec->sruRefPlnrMStructure = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMFace::insertRec(
			PlnrMFace* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->devRefPlnrMFace,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->sruIxPlnrVLat,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->sruRefPlnrMStructure,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFace / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFace / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMFace::insertRst(
			ListPlnrMFace& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMFace::updateRec(
			PlnrMFace* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->devRefPlnrMFace,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->sruIxPlnrVLat,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->sruRefPlnrMStructure,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFace / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFace / stmtUpdateRec)\n");
};

void MyTblPlnrMFace::updateRst(
			ListPlnrMFace& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMFace::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFace / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFace / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMFace::loadRecByRef(
			ubigint ref
			, PlnrMFace** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMFace WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMFace::countByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMFace WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND sruRefPlnrMStructure = " + to_string(sruRefPlnrMStructure) + "", cnt);
	return cnt;
};

ubigint MyTblPlnrMFace::loadRstByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref FROM TblPlnrMFace WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND sruRefPlnrMStructure = " + to_string(sruRefPlnrMStructure) + "", append, rst);
};

ubigint MyTblPlnrMFace::loadRstBySru(
			ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref FROM TblPlnrMFace WHERE sruRefPlnrMStructure = " + to_string(sruRefPlnrMStructure) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMFace
 ******************************************************************************/

PgTblPlnrMFace::PgTblPlnrMFace() : TblPlnrMFace(), PgTable() {
};

PgTblPlnrMFace::~PgTblPlnrMFace() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMFace::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMFace_insertRec", "INSERT INTO TblPlnrMFace (x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFace_updateRec", "UPDATE TblPlnrMFace SET x1RefPlnrMDesign = $1, devRefPlnrMFace = $2, sruIxPlnrVLat = $3, sruRefPlnrMStructure = $4, sref = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFace_removeRecByRef", "DELETE FROM TblPlnrMFace WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMFace_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref FROM TblPlnrMFace WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMFace_countByDsnSru", "SELECT COUNT(ref) FROM TblPlnrMFace WHERE x1RefPlnrMDesign = $1 AND sruRefPlnrMStructure = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFace_loadRstByDsnSru", "SELECT ref, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref FROM TblPlnrMFace WHERE x1RefPlnrMDesign = $1 AND sruRefPlnrMStructure = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFace_loadRstBySru", "SELECT ref, x1RefPlnrMDesign, devRefPlnrMFace, sruIxPlnrVLat, sruRefPlnrMStructure, sref FROM TblPlnrMFace WHERE sruRefPlnrMStructure = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMFace::loadRec(
			PGresult* res
			, PlnrMFace** rec
		) {
	char* ptr;

	PlnrMFace* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMFace();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "devrefplnrmface"),
			PQfnumber(res, "sruixplnrvlat"),
			PQfnumber(res, "srurefplnrmstructure"),
			PQfnumber(res, "sref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->devRefPlnrMFace = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sruIxPlnrVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sruRefPlnrMStructure = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMFace::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMFace& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMFace* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "devrefplnrmface"),
			PQfnumber(res, "sruixplnrvlat"),
			PQfnumber(res, "srurefplnrmstructure"),
			PQfnumber(res, "sref")
		};

		while (numread < numrow) {
			rec = new PlnrMFace();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->devRefPlnrMFace = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sruIxPlnrVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sruRefPlnrMStructure = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMFace::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMFace** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFace / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMFace::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMFace& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFace / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrMFace** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFace& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMFace::insertRec(
			PlnrMFace* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _devRefPlnrMFace = htonl64(rec->devRefPlnrMFace);
	uint _sruIxPlnrVLat = htonl(rec->sruIxPlnrVLat);
	ubigint _sruRefPlnrMStructure = htonl64(rec->sruRefPlnrMStructure);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_devRefPlnrMFace,
		(char*) &_sruIxPlnrVLat,
		(char*) &_sruRefPlnrMStructure,
		rec->sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMFace_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFace_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMFace::insertRst(
			ListPlnrMFace& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMFace::updateRec(
			PlnrMFace* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _devRefPlnrMFace = htonl64(rec->devRefPlnrMFace);
	uint _sruIxPlnrVLat = htonl(rec->sruIxPlnrVLat);
	ubigint _sruRefPlnrMStructure = htonl64(rec->sruRefPlnrMStructure);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_devRefPlnrMFace,
		(char*) &_sruIxPlnrVLat,
		(char*) &_sruRefPlnrMStructure,
		rec->sref.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMFace_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFace_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMFace::updateRst(
			ListPlnrMFace& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMFace::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMFace_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFace_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMFace::loadRecByRef(
			ubigint ref
			, PlnrMFace** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMFace_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMFace::countByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	ubigint _sruRefPlnrMStructure = htonl64(sruRefPlnrMStructure);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_sruRefPlnrMStructure
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	ubigint cnt;
	loadUbigintByStmt("TblPlnrMFace_countByDsnSru", 2, vals, l, f, cnt);
	return cnt;
};

ubigint PgTblPlnrMFace::loadRstByDsnSru(
			ubigint x1RefPlnrMDesign
			, ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	ubigint _sruRefPlnrMStructure = htonl64(sruRefPlnrMStructure);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_sruRefPlnrMStructure
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrMFace_loadRstByDsnSru", 2, vals, l, f, append, rst);
};

ubigint PgTblPlnrMFace::loadRstBySru(
			ubigint sruRefPlnrMStructure
			, const bool append
			, ListPlnrMFace& rst
		) {
	ubigint _sruRefPlnrMStructure = htonl64(sruRefPlnrMStructure);

	const char* vals[] = {
		(char*) &_sruRefPlnrMStructure
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMFace_loadRstBySru", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

