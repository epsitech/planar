/**
  * \file PlnrDevOMDeviceMArcguide.cpp
  * database access for table TblPlnrDevOMDeviceMArcguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrDevOMDeviceMArcguide.h"

/******************************************************************************
 class PlnrDevOMDeviceMArcguide
 ******************************************************************************/

PlnrDevOMDeviceMArcguide::PlnrDevOMDeviceMArcguide(
			const ubigint ref
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {

	this->ref = ref;
	this->refPlnrMDevice = refPlnrMDevice;
	this->x1RefPlnrMDevice = x1RefPlnrMDevice;
	this->ixPlnrVLop = ixPlnrVLop;
	this->pr1RefM = pr1RefM;
};

bool PlnrDevOMDeviceMArcguide::operator==(
			const PlnrDevOMDeviceMArcguide& comp
		) {
	return false;
};

bool PlnrDevOMDeviceMArcguide::operator!=(
			const PlnrDevOMDeviceMArcguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrDevOMDeviceMArcguide
 ******************************************************************************/

ListPlnrDevOMDeviceMArcguide::ListPlnrDevOMDeviceMArcguide() {
};

ListPlnrDevOMDeviceMArcguide::ListPlnrDevOMDeviceMArcguide(
			const ListPlnrDevOMDeviceMArcguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrDevOMDeviceMArcguide(*(src.nodes[i]));
};

ListPlnrDevOMDeviceMArcguide::~ListPlnrDevOMDeviceMArcguide() {
	clear();
};

void ListPlnrDevOMDeviceMArcguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrDevOMDeviceMArcguide::size() const {
	return(nodes.size());
};

void ListPlnrDevOMDeviceMArcguide::append(
			PlnrDevOMDeviceMArcguide* rec
		) {
	nodes.push_back(rec);
};

PlnrDevOMDeviceMArcguide* ListPlnrDevOMDeviceMArcguide::operator[](
			const uint ix
		) {
	PlnrDevOMDeviceMArcguide* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrDevOMDeviceMArcguide& ListPlnrDevOMDeviceMArcguide::operator=(
			const ListPlnrDevOMDeviceMArcguide& src
		) {
	PlnrDevOMDeviceMArcguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrDevOMDeviceMArcguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrDevOMDeviceMArcguide::operator==(
			const ListPlnrDevOMDeviceMArcguide& comp
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

bool ListPlnrDevOMDeviceMArcguide::operator!=(
			const ListPlnrDevOMDeviceMArcguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrDevOMDeviceMArcguide
 ******************************************************************************/

TblPlnrDevOMDeviceMArcguide::TblPlnrDevOMDeviceMArcguide() {
};

TblPlnrDevOMDeviceMArcguide::~TblPlnrDevOMDeviceMArcguide() {
};

bool TblPlnrDevOMDeviceMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMArcguide** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	return 0;
};

void TblPlnrDevOMDeviceMArcguide::insertRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
};

ubigint TblPlnrDevOMDeviceMArcguide::insertNewRec(
			PlnrDevOMDeviceMArcguide** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMArcguide* _rec = NULL;

	_rec = new PlnrDevOMDeviceMArcguide(0, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrDevOMDeviceMArcguide::appendNewRecToRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, PlnrDevOMDeviceMArcguide** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMArcguide* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrDevOMDeviceMArcguide::insertRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMArcguide::updateRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
};

void TblPlnrDevOMDeviceMArcguide::updateRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMArcguide::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrDevOMDeviceMArcguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMArcguide** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMArcguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	return 0;
};

ubigint TblPlnrDevOMDeviceMArcguide::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	ubigint numload = 0;
	PlnrDevOMDeviceMArcguide* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrDevOMDeviceMArcguide
 ******************************************************************************/

MyTblPlnrDevOMDeviceMArcguide::MyTblPlnrDevOMDeviceMArcguide() : TblPlnrDevOMDeviceMArcguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrDevOMDeviceMArcguide::~MyTblPlnrDevOMDeviceMArcguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrDevOMDeviceMArcguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrDevOMDeviceMArcguide (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrDevOMDeviceMArcguide SET refPlnrMDevice = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrDevOMDeviceMArcguide WHERE ref = ?", false);
};

bool MyTblPlnrDevOMDeviceMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMArcguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrDevOMDeviceMArcguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMArcguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrDevOMDeviceMArcguide();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDevice = atoll((char*) dbrow[1]); else _rec->refPlnrMDevice = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDevice = 0;
		if (dbrow[3]) _rec->ixPlnrVLop = atol((char*) dbrow[3]); else _rec->ixPlnrVLop = 0;
		if (dbrow[4]) _rec->pr1RefM = atoll((char*) dbrow[4]); else _rec->pr1RefM = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrDevOMDeviceMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrDevOMDeviceMArcguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMArcguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrDevOMDeviceMArcguide();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDevice = atoll((char*) dbrow[1]); else rec->refPlnrMDevice = 0;
			if (dbrow[2]) rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDevice = 0;
			if (dbrow[3]) rec->ixPlnrVLop = atol((char*) dbrow[3]); else rec->ixPlnrVLop = 0;
			if (dbrow[4]) rec->pr1RefM = atoll((char*) dbrow[4]); else rec->pr1RefM = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrDevOMDeviceMArcguide::insertRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMArcguide / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMArcguide / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrDevOMDeviceMArcguide::insertRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrDevOMDeviceMArcguide::updateRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMArcguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMArcguide / stmtUpdateRec)\n");
};

void MyTblPlnrDevOMDeviceMArcguide::updateRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrDevOMDeviceMArcguide::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMArcguide / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMArcguide / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrDevOMDeviceMArcguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMArcguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrDevOMDeviceMArcguide WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrDevOMDeviceMArcguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMArcguide WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrDevOMDeviceMArcguide
 ******************************************************************************/

PgTblPlnrDevOMDeviceMArcguide::PgTblPlnrDevOMDeviceMArcguide() : TblPlnrDevOMDeviceMArcguide(), PgTable() {
};

PgTblPlnrDevOMDeviceMArcguide::~PgTblPlnrDevOMDeviceMArcguide() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrDevOMDeviceMArcguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMArcguide_insertRec", "INSERT INTO TblPlnrDevOMDeviceMArcguide (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMArcguide_updateRec", "UPDATE TblPlnrDevOMDeviceMArcguide SET refPlnrMDevice = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefM = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMArcguide_removeRecByRef", "DELETE FROM TblPlnrDevOMDeviceMArcguide WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMArcguide_loadRecByRef", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMArcguide WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMArcguide_loadRstByDevDv2", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMArcguide WHERE refPlnrMDevice = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrDevOMDeviceMArcguide::loadRec(
			PGresult* res
			, PlnrDevOMDeviceMArcguide** rec
		) {
	char* ptr;

	PlnrDevOMDeviceMArcguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrDevOMDeviceMArcguide();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1refm")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrVLop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pr1RefM = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrDevOMDeviceMArcguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrDevOMDeviceMArcguide* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1refm")
		};

		while (numread < numrow) {
			rec = new PlnrDevOMDeviceMArcguide();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixPlnrVLop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->pr1RefM = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrDevOMDeviceMArcguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrDevOMDeviceMArcguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMArcguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrDevOMDeviceMArcguide::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMArcguide / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrDevOMDeviceMArcguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMArcguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrDevOMDeviceMArcguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrDevOMDeviceMArcguide::insertRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefM = htonl64(rec->pr1RefM);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDevice,
		(char*) &_ixPlnrVLop,
		(char*) &_pr1RefM
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMArcguide_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMArcguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMArcguide::insertRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrDevOMDeviceMArcguide::updateRec(
			PlnrDevOMDeviceMArcguide* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefM = htonl64(rec->pr1RefM);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDevice,
		(char*) &_ixPlnrVLop,
		(char*) &_pr1RefM,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMArcguide_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMArcguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMArcguide::updateRst(
			ListPlnrDevOMDeviceMArcguide& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrDevOMDeviceMArcguide::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMArcguide_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMArcguide_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrDevOMDeviceMArcguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMArcguide** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrDevOMDeviceMArcguide_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrDevOMDeviceMArcguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMArcguide& rst
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);
	ubigint _x1RefPlnrMDevice = htonl64(x1RefPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrDevOMDeviceMArcguide_loadRstByDevDv2", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

