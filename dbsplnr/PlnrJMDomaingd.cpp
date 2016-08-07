/**
  * \file PlnrJMDomaingd.cpp
  * database access for table TblPlnrJMDomaingd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMDomaingd.h"

/******************************************************************************
 class PlnrJMDomaingd
 ******************************************************************************/

PlnrJMDomaingd::PlnrJMDomaingd(
			const ubigint ref
			, const ubigint refPlnrMDomaingd
			, const ubigint x1RefPlnrMDesign
			, const string d
			, const string dphi
		) {

	this->ref = ref;
	this->refPlnrMDomaingd = refPlnrMDomaingd;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->d = d;
	this->dphi = dphi;
};

bool PlnrJMDomaingd::operator==(
			const PlnrJMDomaingd& comp
		) {
	return false;
};

bool PlnrJMDomaingd::operator!=(
			const PlnrJMDomaingd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMDomaingd
 ******************************************************************************/

ListPlnrJMDomaingd::ListPlnrJMDomaingd() {
};

ListPlnrJMDomaingd::ListPlnrJMDomaingd(
			const ListPlnrJMDomaingd& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMDomaingd(*(src.nodes[i]));
};

ListPlnrJMDomaingd::~ListPlnrJMDomaingd() {
	clear();
};

void ListPlnrJMDomaingd::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMDomaingd::size() const {
	return(nodes.size());
};

void ListPlnrJMDomaingd::append(
			PlnrJMDomaingd* rec
		) {
	nodes.push_back(rec);
};

PlnrJMDomaingd* ListPlnrJMDomaingd::operator[](
			const uint ix
		) {
	PlnrJMDomaingd* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMDomaingd& ListPlnrJMDomaingd::operator=(
			const ListPlnrJMDomaingd& src
		) {
	PlnrJMDomaingd* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMDomaingd(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMDomaingd::operator==(
			const ListPlnrJMDomaingd& comp
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

bool ListPlnrJMDomaingd::operator!=(
			const ListPlnrJMDomaingd& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMDomaingd
 ******************************************************************************/

TblPlnrJMDomaingd::TblPlnrJMDomaingd() {
};

TblPlnrJMDomaingd::~TblPlnrJMDomaingd() {
};

bool TblPlnrJMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomaingd** rec
		) {
	return false;
};

ubigint TblPlnrJMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	return 0;
};

void TblPlnrJMDomaingd::insertRec(
			PlnrJMDomaingd* rec
		) {
};

ubigint TblPlnrJMDomaingd::insertNewRec(
			PlnrJMDomaingd** rec
			, const ubigint refPlnrMDomaingd
			, const ubigint x1RefPlnrMDesign
			, const string d
			, const string dphi
		) {
	ubigint retval = 0;
	PlnrJMDomaingd* _rec = NULL;

	_rec = new PlnrJMDomaingd(0, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMDomaingd::appendNewRecToRst(
			ListPlnrJMDomaingd& rst
			, PlnrJMDomaingd** rec
			, const ubigint refPlnrMDomaingd
			, const ubigint x1RefPlnrMDesign
			, const string d
			, const string dphi
		) {
	ubigint retval = 0;
	PlnrJMDomaingd* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMDomaingd::insertRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
};

void TblPlnrJMDomaingd::updateRec(
			PlnrJMDomaingd* rec
		) {
};

void TblPlnrJMDomaingd::updateRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
};

void TblPlnrJMDomaingd::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrJMDomaingd** rec
		) {
	return false;
};

bool TblPlnrJMDomaingd::loadRecByDgdDsn(
			ubigint refPlnrMDomaingd
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomaingd** rec
		) {
	return false;
};

ubigint TblPlnrJMDomaingd::loadRstByDgd(
			ubigint refPlnrMDomaingd
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	return 0;
};

ubigint TblPlnrJMDomaingd::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	ubigint numload = 0;
	PlnrJMDomaingd* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMDomaingd
 ******************************************************************************/

MyTblPlnrJMDomaingd::MyTblPlnrJMDomaingd() : TblPlnrJMDomaingd(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMDomaingd::~MyTblPlnrJMDomaingd() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMDomaingd::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMDomaingd (refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMDomaingd SET refPlnrMDomaingd = ?, x1RefPlnrMDesign = ?, d = ?, dphi = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMDomaingd WHERE ref = ?", false);
};

bool MyTblPlnrJMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomaingd** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMDomaingd* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDomaingd / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMDomaingd();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDomaingd = atoll((char*) dbrow[1]); else _rec->refPlnrMDomaingd = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->d.assign(dbrow[3], dblengths[3]); else _rec->d = "";
		if (dbrow[4]) _rec->dphi.assign(dbrow[4], dblengths[4]); else _rec->dphi = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMDomaingd* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDomaingd / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMDomaingd();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDomaingd = atoll((char*) dbrow[1]); else rec->refPlnrMDomaingd = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->d.assign(dbrow[3], dblengths[3]); else rec->d = "";
			if (dbrow[4]) rec->dphi.assign(dbrow[4], dblengths[4]); else rec->dphi = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMDomaingd::insertRec(
			PlnrJMDomaingd* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->d.length();
	l[3] = rec->dphi.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDomaingd,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->d.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->dphi.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomaingd / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomaingd / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMDomaingd::insertRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMDomaingd::updateRec(
			PlnrJMDomaingd* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->d.length();
	l[3] = rec->dphi.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDomaingd,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->d.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->dphi.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomaingd / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomaingd / stmtUpdateRec)\n");
};

void MyTblPlnrJMDomaingd::updateRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMDomaingd::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDomaingd / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDomaingd / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrJMDomaingd** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMDomaingd WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMDomaingd::loadRecByDgdDsn(
			ubigint refPlnrMDomaingd
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomaingd** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi FROM TblPlnrJMDomaingd WHERE refPlnrMDomaingd = " + to_string(refPlnrMDomaingd) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMDomaingd::loadRstByDgd(
			ubigint refPlnrMDomaingd
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi FROM TblPlnrJMDomaingd WHERE refPlnrMDomaingd = " + to_string(refPlnrMDomaingd) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMDomaingd
 ******************************************************************************/

PgTblPlnrJMDomaingd::PgTblPlnrJMDomaingd() : TblPlnrJMDomaingd(), PgTable() {
};

PgTblPlnrJMDomaingd::~PgTblPlnrJMDomaingd() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMDomaingd::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMDomaingd_insertRec", "INSERT INTO TblPlnrJMDomaingd (refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomaingd_updateRec", "UPDATE TblPlnrJMDomaingd SET refPlnrMDomaingd = $1, x1RefPlnrMDesign = $2, d = $3, dphi = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomaingd_removeRecByRef", "DELETE FROM TblPlnrJMDomaingd WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMDomaingd_loadRecByRef", "SELECT ref, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi FROM TblPlnrJMDomaingd WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMDomaingd_loadRecByDgdDsn", "SELECT ref, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi FROM TblPlnrJMDomaingd WHERE refPlnrMDomaingd = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDomaingd_loadRstByDgd", "SELECT ref, refPlnrMDomaingd, x1RefPlnrMDesign, d, dphi FROM TblPlnrJMDomaingd WHERE refPlnrMDomaingd = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMDomaingd::loadRec(
			PGresult* res
			, PlnrJMDomaingd** rec
		) {
	char* ptr;

	PlnrJMDomaingd* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMDomaingd();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdomaingd"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "d"),
			PQfnumber(res, "dphi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDomaingd = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->d.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->dphi.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMDomaingd::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMDomaingd* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdomaingd"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "d"),
			PQfnumber(res, "dphi")
		};

		while (numread < numrow) {
			rec = new PlnrJMDomaingd();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDomaingd = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->d.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->dphi.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMDomaingd::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMDomaingd** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomaingd / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMDomaingd::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomaingd / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMDomaingd::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDomaingd** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMDomaingd::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMDomaingd::insertRec(
			PlnrJMDomaingd* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDomaingd = htonl64(rec->refPlnrMDomaingd);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDomaingd,
		(char*) &_x1RefPlnrMDesign,
		rec->d.c_str(),
		rec->dphi.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMDomaingd_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomaingd_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMDomaingd::insertRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMDomaingd::updateRec(
			PlnrJMDomaingd* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDomaingd = htonl64(rec->refPlnrMDomaingd);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDomaingd,
		(char*) &_x1RefPlnrMDesign,
		rec->d.c_str(),
		rec->dphi.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMDomaingd_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomaingd_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMDomaingd::updateRst(
			ListPlnrJMDomaingd& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMDomaingd::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMDomaingd_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDomaingd_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMDomaingd::loadRecByRef(
			ubigint ref
			, PlnrJMDomaingd** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMDomaingd_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMDomaingd::loadRecByDgdDsn(
			ubigint refPlnrMDomaingd
			, ubigint x1RefPlnrMDesign
			, PlnrJMDomaingd** rec
		) {
	ubigint _refPlnrMDomaingd = htonl64(refPlnrMDomaingd);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDomaingd,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMDomaingd_loadRecByDgdDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMDomaingd::loadRstByDgd(
			ubigint refPlnrMDomaingd
			, const bool append
			, ListPlnrJMDomaingd& rst
		) {
	ubigint _refPlnrMDomaingd = htonl64(refPlnrMDomaingd);

	const char* vals[] = {
		(char*) &_refPlnrMDomaingd
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMDomaingd_loadRstByDgd", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

