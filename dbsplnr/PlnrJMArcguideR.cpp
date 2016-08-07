/**
  * \file PlnrJMArcguideR.cpp
  * database access for table TblPlnrJMArcguideR (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMArcguideR.h"

/******************************************************************************
 class PlnrJMArcguideR
 ******************************************************************************/

PlnrJMArcguideR::PlnrJMArcguideR(
			const ubigint ref
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDesign
			, const double r
		) {

	this->ref = ref;
	this->refPlnrMArcguide = refPlnrMArcguide;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->r = r;
};

bool PlnrJMArcguideR::operator==(
			const PlnrJMArcguideR& comp
		) {
	return false;
};

bool PlnrJMArcguideR::operator!=(
			const PlnrJMArcguideR& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMArcguideR
 ******************************************************************************/

ListPlnrJMArcguideR::ListPlnrJMArcguideR() {
};

ListPlnrJMArcguideR::ListPlnrJMArcguideR(
			const ListPlnrJMArcguideR& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMArcguideR(*(src.nodes[i]));
};

ListPlnrJMArcguideR::~ListPlnrJMArcguideR() {
	clear();
};

void ListPlnrJMArcguideR::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMArcguideR::size() const {
	return(nodes.size());
};

void ListPlnrJMArcguideR::append(
			PlnrJMArcguideR* rec
		) {
	nodes.push_back(rec);
};

PlnrJMArcguideR* ListPlnrJMArcguideR::operator[](
			const uint ix
		) {
	PlnrJMArcguideR* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMArcguideR& ListPlnrJMArcguideR::operator=(
			const ListPlnrJMArcguideR& src
		) {
	PlnrJMArcguideR* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMArcguideR(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMArcguideR::operator==(
			const ListPlnrJMArcguideR& comp
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

bool ListPlnrJMArcguideR::operator!=(
			const ListPlnrJMArcguideR& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMArcguideR
 ******************************************************************************/

TblPlnrJMArcguideR::TblPlnrJMArcguideR() {
};

TblPlnrJMArcguideR::~TblPlnrJMArcguideR() {
};

bool TblPlnrJMArcguideR::loadRecBySQL(
			const string& sqlstr
			, PlnrJMArcguideR** rec
		) {
	return false;
};

ubigint TblPlnrJMArcguideR::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	return 0;
};

void TblPlnrJMArcguideR::insertRec(
			PlnrJMArcguideR* rec
		) {
};

ubigint TblPlnrJMArcguideR::insertNewRec(
			PlnrJMArcguideR** rec
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDesign
			, const double r
		) {
	ubigint retval = 0;
	PlnrJMArcguideR* _rec = NULL;

	_rec = new PlnrJMArcguideR(0, refPlnrMArcguide, x1RefPlnrMDesign, r);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMArcguideR::appendNewRecToRst(
			ListPlnrJMArcguideR& rst
			, PlnrJMArcguideR** rec
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDesign
			, const double r
		) {
	ubigint retval = 0;
	PlnrJMArcguideR* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMArcguide, x1RefPlnrMDesign, r);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMArcguideR::insertRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
};

void TblPlnrJMArcguideR::updateRec(
			PlnrJMArcguideR* rec
		) {
};

void TblPlnrJMArcguideR::updateRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
};

void TblPlnrJMArcguideR::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMArcguideR::loadRecByRef(
			ubigint ref
			, PlnrJMArcguideR** rec
		) {
	return false;
};

bool TblPlnrJMArcguideR::loadRecByAgdDsn(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDesign
			, PlnrJMArcguideR** rec
		) {
	return false;
};

ubigint TblPlnrJMArcguideR::loadRstByAgd(
			ubigint refPlnrMArcguide
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	return 0;
};

ubigint TblPlnrJMArcguideR::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	ubigint numload = 0;
	PlnrJMArcguideR* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMArcguideR
 ******************************************************************************/

MyTblPlnrJMArcguideR::MyTblPlnrJMArcguideR() : TblPlnrJMArcguideR(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMArcguideR::~MyTblPlnrJMArcguideR() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMArcguideR::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMArcguideR (refPlnrMArcguide, x1RefPlnrMDesign, r) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMArcguideR SET refPlnrMArcguide = ?, x1RefPlnrMDesign = ?, r = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMArcguideR WHERE ref = ?", false);
};

bool MyTblPlnrJMArcguideR::loadRecBySQL(
			const string& sqlstr
			, PlnrJMArcguideR** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMArcguideR* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMArcguideR / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMArcguideR();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMArcguide = atoll((char*) dbrow[1]); else _rec->refPlnrMArcguide = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->r = atof((char*) dbrow[3]); else _rec->r = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMArcguideR::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMArcguideR* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMArcguideR / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMArcguideR();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMArcguide = atoll((char*) dbrow[1]); else rec->refPlnrMArcguide = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->r = atof((char*) dbrow[3]); else rec->r = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMArcguideR::insertRec(
			PlnrJMArcguideR* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArcguide,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->r,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMArcguideR / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMArcguideR / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMArcguideR::insertRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMArcguideR::updateRec(
			PlnrJMArcguideR* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArcguide,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindDouble(&rec->r,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMArcguideR / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMArcguideR / stmtUpdateRec)\n");
};

void MyTblPlnrJMArcguideR::updateRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMArcguideR::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMArcguideR / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMArcguideR / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMArcguideR::loadRecByRef(
			ubigint ref
			, PlnrJMArcguideR** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMArcguideR WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMArcguideR::loadRecByAgdDsn(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDesign
			, PlnrJMArcguideR** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMArcguide, x1RefPlnrMDesign, r FROM TblPlnrJMArcguideR WHERE refPlnrMArcguide = " + to_string(refPlnrMArcguide) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMArcguideR::loadRstByAgd(
			ubigint refPlnrMArcguide
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMArcguide, x1RefPlnrMDesign, r FROM TblPlnrJMArcguideR WHERE refPlnrMArcguide = " + to_string(refPlnrMArcguide) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMArcguideR
 ******************************************************************************/

PgTblPlnrJMArcguideR::PgTblPlnrJMArcguideR() : TblPlnrJMArcguideR(), PgTable() {
};

PgTblPlnrJMArcguideR::~PgTblPlnrJMArcguideR() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMArcguideR::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMArcguideR_insertRec", "INSERT INTO TblPlnrJMArcguideR (refPlnrMArcguide, x1RefPlnrMDesign, r) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMArcguideR_updateRec", "UPDATE TblPlnrJMArcguideR SET refPlnrMArcguide = $1, x1RefPlnrMDesign = $2, r = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMArcguideR_removeRecByRef", "DELETE FROM TblPlnrJMArcguideR WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMArcguideR_loadRecByRef", "SELECT ref, refPlnrMArcguide, x1RefPlnrMDesign, r FROM TblPlnrJMArcguideR WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMArcguideR_loadRecByAgdDsn", "SELECT ref, refPlnrMArcguide, x1RefPlnrMDesign, r FROM TblPlnrJMArcguideR WHERE refPlnrMArcguide = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMArcguideR_loadRstByAgd", "SELECT ref, refPlnrMArcguide, x1RefPlnrMDesign, r FROM TblPlnrJMArcguideR WHERE refPlnrMArcguide = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMArcguideR::loadRec(
			PGresult* res
			, PlnrJMArcguideR** rec
		) {
	char* ptr;

	PlnrJMArcguideR* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMArcguideR();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarcguide"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "r")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMArcguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->r = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMArcguideR::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMArcguideR* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarcguide"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "r")
		};

		while (numread < numrow) {
			rec = new PlnrJMArcguideR();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMArcguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->r = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMArcguideR::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMArcguideR** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMArcguideR / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMArcguideR::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMArcguideR / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMArcguideR::loadRecBySQL(
			const string& sqlstr
			, PlnrJMArcguideR** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMArcguideR::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMArcguideR::insertRec(
			PlnrJMArcguideR* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMArcguide = htonl64(rec->refPlnrMArcguide);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _r = to_string(rec->r);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
		(char*) &_x1RefPlnrMDesign,
		_r.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMArcguideR_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMArcguideR_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMArcguideR::insertRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMArcguideR::updateRec(
			PlnrJMArcguideR* rec
		) {
	PGresult* res;

	ubigint _refPlnrMArcguide = htonl64(rec->refPlnrMArcguide);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _r = to_string(rec->r);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
		(char*) &_x1RefPlnrMDesign,
		_r.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMArcguideR_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMArcguideR_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMArcguideR::updateRst(
			ListPlnrJMArcguideR& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMArcguideR::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMArcguideR_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMArcguideR_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMArcguideR::loadRecByRef(
			ubigint ref
			, PlnrJMArcguideR** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMArcguideR_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMArcguideR::loadRecByAgdDsn(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDesign
			, PlnrJMArcguideR** rec
		) {
	ubigint _refPlnrMArcguide = htonl64(refPlnrMArcguide);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMArcguideR_loadRecByAgdDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMArcguideR::loadRstByAgd(
			ubigint refPlnrMArcguide
			, const bool append
			, ListPlnrJMArcguideR& rst
		) {
	ubigint _refPlnrMArcguide = htonl64(refPlnrMArcguide);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMArcguideR_loadRstByAgd", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

