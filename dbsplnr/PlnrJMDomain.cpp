/**
  * \file PlnrJMDomain.cpp
  * database access for table TblPlnrJMDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMDomain.h"

/******************************************************************************
 class PlnrJMDomain
 ******************************************************************************/

PlnrJMDomain::PlnrJMDomain(
			const ubigint ref
			, const ubigint refPlnrMDomain
			, const ubigint x1RefPlnrMDesign
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {

	this->ref = ref;
	this->refPlnrMDomain = refPlnrMDomain;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->dx = dx;
	this->dy = dy;
	this->dxy = dxy;
	this->dz = dz;
};

bool PlnrJMDomain::operator==(
			const PlnrJMDomain& comp
		) {
	return false;
};

bool PlnrJMDomain::operator!=(
			const PlnrJMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMDomain
 ******************************************************************************/

ListPlnrJMDomain::ListPlnrJMDomain() {
};

ListPlnrJMDomain::ListPlnrJMDomain(
			const ListPlnrJMDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMDomain(*(src.nodes[i]));
};

ListPlnrJMDomain::~ListPlnrJMDomain() {
	clear();
};

void ListPlnrJMDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMDomain::size() const {
	return(nodes.size());
};

void ListPlnrJMDomain::append(
			PlnrJMDomain* rec
		) {
	nodes.push_back(rec);
};

PlnrJMDomain* ListPlnrJMDomain::operator[](
			const uint ix
		) {
	PlnrJMDomain* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMDomain& ListPlnrJMDomain::operator=(
			const ListPlnrJMDomain& src
		) {
	PlnrJMDomain* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMDomain(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMDomain::operator==(
			const ListPlnrJMDomain& comp
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

bool ListPlnrJMDomain::operator!=(
			const ListPlnrJMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMDomain
 ******************************************************************************/

TblPlnrJMDomain::TblPlnrJMDomain() {
};

TblPlnrJMDomain::~TblPlnrJMDomain() {
};

bool TblPlnrJMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomain** rec
		) {
	return false;
};

ubigint TblPlnrJMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	return 0;
};

void TblPlnrJMDomain::insertRec(
			PlnrJMDomain* rec
		) {
};

ubigint TblPlnrJMDomain::insertNewRec(
			PlnrJMDomain** rec
			, const ubigint refPlnrMDomain
			, const ubigint x1RefPlnrMDesign
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {
	ubigint retval = 0;
	PlnrJMDomain* _rec = NULL;

	_rec = new PlnrJMDomain(0, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMDomain::appendNewRecToRst(
			ListPlnrJMDomain& rst
			, PlnrJMDomain** rec
			, const ubigint refPlnrMDomain
			, const ubigint x1RefPlnrMDesign
			, const string dx
			, const string dy
			, const string dxy
			, const string dz
		) {
	ubigint retval = 0;
	PlnrJMDomain* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMDomain::insertRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
};

void TblPlnrJMDomain::updateRec(
			PlnrJMDomain* rec
		) {
};

void TblPlnrJMDomain::updateRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
};

void TblPlnrJMDomain::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMDomain::loadRecByRef(
			ubigint ref
			, PlnrJMDomain** rec
		) {
	return false;
};

bool TblPlnrJMDomain::loadRecByDomDsn(
			ubigint refPlnrMDomain
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomain** rec
		) {
	return false;
};

ubigint TblPlnrJMDomain::loadRstByDom(
			ubigint refPlnrMDomain
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	return 0;
};

ubigint TblPlnrJMDomain::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	ubigint numload = 0;
	PlnrJMDomain* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMDomain
 ******************************************************************************/

MyTblPlnrJMDomain::MyTblPlnrJMDomain() : TblPlnrJMDomain(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMDomain::~MyTblPlnrJMDomain() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMDomain::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMDomain (refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMDomain SET refPlnrMDomain = ?, x1RefPlnrMDesign = ?, dx = ?, dy = ?, dxy = ?, dz = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMDomain WHERE ref = ?", false);
};

bool MyTblPlnrJMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomain** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMDomain* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDomain / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMDomain();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDomain = atoll((char*) dbrow[1]); else _rec->refPlnrMDomain = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->dx.assign(dbrow[3], dblengths[3]); else _rec->dx = "";
		if (dbrow[4]) _rec->dy.assign(dbrow[4], dblengths[4]); else _rec->dy = "";
		if (dbrow[5]) _rec->dxy.assign(dbrow[5], dblengths[5]); else _rec->dxy = "";
		if (dbrow[6]) _rec->dz.assign(dbrow[6], dblengths[6]); else _rec->dz = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMDomain* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDomain / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMDomain();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDomain = atoll((char*) dbrow[1]); else rec->refPlnrMDomain = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->dx.assign(dbrow[3], dblengths[3]); else rec->dx = "";
			if (dbrow[4]) rec->dy.assign(dbrow[4], dblengths[4]); else rec->dy = "";
			if (dbrow[5]) rec->dxy.assign(dbrow[5], dblengths[5]); else rec->dxy = "";
			if (dbrow[6]) rec->dz.assign(dbrow[6], dblengths[6]); else rec->dz = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMDomain::insertRec(
			PlnrJMDomain* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->dx.length();
	l[3] = rec->dy.length();
	l[4] = rec->dxy.length();
	l[5] = rec->dz.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDomain,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->dx.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->dy.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->dxy.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->dz.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomain / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomain / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMDomain::insertRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMDomain::updateRec(
			PlnrJMDomain* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->dx.length();
	l[3] = rec->dy.length();
	l[4] = rec->dxy.length();
	l[5] = rec->dz.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDomain,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->dx.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->dy.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->dxy.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->dz.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomain / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomain / stmtUpdateRec)\n");
};

void MyTblPlnrJMDomain::updateRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMDomain::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomain / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomain / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMDomain::loadRecByRef(
			ubigint ref
			, PlnrJMDomain** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMDomain WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMDomain::loadRecByDomDsn(
			ubigint refPlnrMDomain
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomain** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz FROM TblPlnrJMDomain WHERE refPlnrMDomain = " + to_string(refPlnrMDomain) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMDomain::loadRstByDom(
			ubigint refPlnrMDomain
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz FROM TblPlnrJMDomain WHERE refPlnrMDomain = " + to_string(refPlnrMDomain) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMDomain
 ******************************************************************************/

PgTblPlnrJMDomain::PgTblPlnrJMDomain() : TblPlnrJMDomain(), PgTable() {
};

PgTblPlnrJMDomain::~PgTblPlnrJMDomain() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMDomain::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMDomain_insertRec", "INSERT INTO TblPlnrJMDomain (refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomain_updateRec", "UPDATE TblPlnrJMDomain SET refPlnrMDomain = $1, x1RefPlnrMDesign = $2, dx = $3, dy = $4, dxy = $5, dz = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomain_removeRecByRef", "DELETE FROM TblPlnrJMDomain WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMDomain_loadRecByRef", "SELECT ref, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz FROM TblPlnrJMDomain WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMDomain_loadRecByDomDsn", "SELECT ref, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz FROM TblPlnrJMDomain WHERE refPlnrMDomain = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomain_loadRstByDom", "SELECT ref, refPlnrMDomain, x1RefPlnrMDesign, dx, dy, dxy, dz FROM TblPlnrJMDomain WHERE refPlnrMDomain = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMDomain::loadRec(
			PGresult* res
			, PlnrJMDomain** rec
		) {
	char* ptr;

	PlnrJMDomain* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMDomain();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdomain"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dxy"),
			PQfnumber(res, "dz")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDomain = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dx.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->dy.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->dxy.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->dz.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMDomain::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMDomain* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdomain"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dxy"),
			PQfnumber(res, "dz")
		};

		while (numread < numrow) {
			rec = new PlnrJMDomain();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDomain = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dx.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->dy.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->dxy.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->dz.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMDomain::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMDomain** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomain / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMDomain::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomain / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomain** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMDomain::insertRec(
			PlnrJMDomain* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDomain = htonl64(rec->refPlnrMDomain);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDomain,
		(char*) &_x1RefPlnrMDesign,
		rec->dx.c_str(),
		rec->dy.c_str(),
		rec->dxy.c_str(),
		rec->dz.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMDomain_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomain_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMDomain::insertRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMDomain::updateRec(
			PlnrJMDomain* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDomain = htonl64(rec->refPlnrMDomain);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDomain,
		(char*) &_x1RefPlnrMDesign,
		rec->dx.c_str(),
		rec->dy.c_str(),
		rec->dxy.c_str(),
		rec->dz.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMDomain_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomain_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMDomain::updateRst(
			ListPlnrJMDomain& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMDomain::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMDomain_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomain_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMDomain::loadRecByRef(
			ubigint ref
			, PlnrJMDomain** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMDomain_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMDomain::loadRecByDomDsn(
			ubigint refPlnrMDomain
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomain** rec
		) {
	ubigint _refPlnrMDomain = htonl64(refPlnrMDomain);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDomain,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMDomain_loadRecByDomDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMDomain::loadRstByDom(
			ubigint refPlnrMDomain
			, const bool append
			, ListPlnrJMDomain& rst
		) {
	ubigint _refPlnrMDomain = htonl64(refPlnrMDomain);

	const char* vals[] = {
		(char*) &_refPlnrMDomain
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMDomain_loadRstByDom", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

