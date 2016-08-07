/**
  * \file PlnrDevOMDeviceMLineguide.cpp
  * database access for table TblPlnrDevOMDeviceMLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrDevOMDeviceMLineguide.h"

/******************************************************************************
 class PlnrDevOMDeviceMLineguide
 ******************************************************************************/

PlnrDevOMDeviceMLineguide::PlnrDevOMDeviceMLineguide(
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

bool PlnrDevOMDeviceMLineguide::operator==(
			const PlnrDevOMDeviceMLineguide& comp
		) {
	return false;
};

bool PlnrDevOMDeviceMLineguide::operator!=(
			const PlnrDevOMDeviceMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrDevOMDeviceMLineguide
 ******************************************************************************/

ListPlnrDevOMDeviceMLineguide::ListPlnrDevOMDeviceMLineguide() {
};

ListPlnrDevOMDeviceMLineguide::ListPlnrDevOMDeviceMLineguide(
			const ListPlnrDevOMDeviceMLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrDevOMDeviceMLineguide(*(src.nodes[i]));
};

ListPlnrDevOMDeviceMLineguide::~ListPlnrDevOMDeviceMLineguide() {
	clear();
};

void ListPlnrDevOMDeviceMLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrDevOMDeviceMLineguide::size() const {
	return(nodes.size());
};

void ListPlnrDevOMDeviceMLineguide::append(
			PlnrDevOMDeviceMLineguide* rec
		) {
	nodes.push_back(rec);
};

PlnrDevOMDeviceMLineguide* ListPlnrDevOMDeviceMLineguide::operator[](
			const uint ix
		) {
	PlnrDevOMDeviceMLineguide* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrDevOMDeviceMLineguide& ListPlnrDevOMDeviceMLineguide::operator=(
			const ListPlnrDevOMDeviceMLineguide& src
		) {
	PlnrDevOMDeviceMLineguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrDevOMDeviceMLineguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrDevOMDeviceMLineguide::operator==(
			const ListPlnrDevOMDeviceMLineguide& comp
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

bool ListPlnrDevOMDeviceMLineguide::operator!=(
			const ListPlnrDevOMDeviceMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrDevOMDeviceMLineguide
 ******************************************************************************/

TblPlnrDevOMDeviceMLineguide::TblPlnrDevOMDeviceMLineguide() {
};

TblPlnrDevOMDeviceMLineguide::~TblPlnrDevOMDeviceMLineguide() {
};

bool TblPlnrDevOMDeviceMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	return 0;
};

void TblPlnrDevOMDeviceMLineguide::insertRec(
			PlnrDevOMDeviceMLineguide* rec
		) {
};

ubigint TblPlnrDevOMDeviceMLineguide::insertNewRec(
			PlnrDevOMDeviceMLineguide** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMLineguide* _rec = NULL;

	_rec = new PlnrDevOMDeviceMLineguide(0, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrDevOMDeviceMLineguide::appendNewRecToRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, PlnrDevOMDeviceMLineguide** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMLineguide* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrDevOMDeviceMLineguide::insertRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMLineguide::updateRec(
			PlnrDevOMDeviceMLineguide* rec
		) {
};

void TblPlnrDevOMDeviceMLineguide::updateRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMLineguide::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrDevOMDeviceMLineguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMLineguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	return 0;
};

ubigint TblPlnrDevOMDeviceMLineguide::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	ubigint numload = 0;
	PlnrDevOMDeviceMLineguide* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrDevOMDeviceMLineguide
 ******************************************************************************/

MyTblPlnrDevOMDeviceMLineguide::MyTblPlnrDevOMDeviceMLineguide() : TblPlnrDevOMDeviceMLineguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrDevOMDeviceMLineguide::~MyTblPlnrDevOMDeviceMLineguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrDevOMDeviceMLineguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrDevOMDeviceMLineguide (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrDevOMDeviceMLineguide SET refPlnrMDevice = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrDevOMDeviceMLineguide WHERE ref = ?", false);
};

bool MyTblPlnrDevOMDeviceMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMLineguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrDevOMDeviceMLineguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMLineguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrDevOMDeviceMLineguide();

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

ubigint MyTblPlnrDevOMDeviceMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrDevOMDeviceMLineguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMLineguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrDevOMDeviceMLineguide();

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

void MyTblPlnrDevOMDeviceMLineguide::insertRec(
			PlnrDevOMDeviceMLineguide* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMLineguide / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMLineguide / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrDevOMDeviceMLineguide::insertRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrDevOMDeviceMLineguide::updateRec(
			PlnrDevOMDeviceMLineguide* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMLineguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMLineguide / stmtUpdateRec)\n");
};

void MyTblPlnrDevOMDeviceMLineguide::updateRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrDevOMDeviceMLineguide::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMLineguide / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMLineguide / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrDevOMDeviceMLineguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMLineguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrDevOMDeviceMLineguide WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrDevOMDeviceMLineguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMLineguide WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrDevOMDeviceMLineguide
 ******************************************************************************/

PgTblPlnrDevOMDeviceMLineguide::PgTblPlnrDevOMDeviceMLineguide() : TblPlnrDevOMDeviceMLineguide(), PgTable() {
};

PgTblPlnrDevOMDeviceMLineguide::~PgTblPlnrDevOMDeviceMLineguide() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrDevOMDeviceMLineguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMLineguide_insertRec", "INSERT INTO TblPlnrDevOMDeviceMLineguide (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMLineguide_updateRec", "UPDATE TblPlnrDevOMDeviceMLineguide SET refPlnrMDevice = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefM = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMLineguide_removeRecByRef", "DELETE FROM TblPlnrDevOMDeviceMLineguide WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMLineguide_loadRecByRef", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMLineguide WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMLineguide_loadRstByDevDv2", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMLineguide WHERE refPlnrMDevice = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrDevOMDeviceMLineguide::loadRec(
			PGresult* res
			, PlnrDevOMDeviceMLineguide** rec
		) {
	char* ptr;

	PlnrDevOMDeviceMLineguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrDevOMDeviceMLineguide();

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

ubigint PgTblPlnrDevOMDeviceMLineguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrDevOMDeviceMLineguide* rec;

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
			rec = new PlnrDevOMDeviceMLineguide();

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

bool PgTblPlnrDevOMDeviceMLineguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrDevOMDeviceMLineguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMLineguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrDevOMDeviceMLineguide::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMLineguide / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrDevOMDeviceMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMLineguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrDevOMDeviceMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrDevOMDeviceMLineguide::insertRec(
			PlnrDevOMDeviceMLineguide* rec
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMLineguide_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMLineguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMLineguide::insertRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrDevOMDeviceMLineguide::updateRec(
			PlnrDevOMDeviceMLineguide* rec
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMLineguide_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMLineguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMLineguide::updateRst(
			ListPlnrDevOMDeviceMLineguide& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrDevOMDeviceMLineguide::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMLineguide_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMLineguide_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrDevOMDeviceMLineguide::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMLineguide** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrDevOMDeviceMLineguide_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrDevOMDeviceMLineguide::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMLineguide& rst
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

	return loadRstByStmt("TblPlnrDevOMDeviceMLineguide_loadRstByDevDv2", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

