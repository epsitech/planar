/**
  * \file PlnrOMStructureMFace.cpp
  * database access for table TblPlnrOMStructureMFace (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrOMStructureMFace.h"

/******************************************************************************
 class PlnrOMStructureMFace
 ******************************************************************************/

PlnrOMStructureMFace::PlnrOMStructureMFace(
			const ubigint ref
			, const ubigint refPlnrMStructure
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {

	this->ref = ref;
	this->refPlnrMStructure = refPlnrMStructure;
	this->x1RefPlnrMDevice = x1RefPlnrMDevice;
	this->ixPlnrVLop = ixPlnrVLop;
	this->pr1RefM = pr1RefM;
};

bool PlnrOMStructureMFace::operator==(
			const PlnrOMStructureMFace& comp
		) {
	return false;
};

bool PlnrOMStructureMFace::operator!=(
			const PlnrOMStructureMFace& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrOMStructureMFace
 ******************************************************************************/

ListPlnrOMStructureMFace::ListPlnrOMStructureMFace() {
};

ListPlnrOMStructureMFace::ListPlnrOMStructureMFace(
			const ListPlnrOMStructureMFace& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrOMStructureMFace(*(src.nodes[i]));
};

ListPlnrOMStructureMFace::~ListPlnrOMStructureMFace() {
	clear();
};

void ListPlnrOMStructureMFace::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrOMStructureMFace::size() const {
	return(nodes.size());
};

void ListPlnrOMStructureMFace::append(
			PlnrOMStructureMFace* rec
		) {
	nodes.push_back(rec);
};

PlnrOMStructureMFace* ListPlnrOMStructureMFace::operator[](
			const uint ix
		) {
	PlnrOMStructureMFace* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrOMStructureMFace& ListPlnrOMStructureMFace::operator=(
			const ListPlnrOMStructureMFace& src
		) {
	PlnrOMStructureMFace* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrOMStructureMFace(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrOMStructureMFace::operator==(
			const ListPlnrOMStructureMFace& comp
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

bool ListPlnrOMStructureMFace::operator!=(
			const ListPlnrOMStructureMFace& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrOMStructureMFace
 ******************************************************************************/

TblPlnrOMStructureMFace::TblPlnrOMStructureMFace() {
};

TblPlnrOMStructureMFace::~TblPlnrOMStructureMFace() {
};

bool TblPlnrOMStructureMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrOMStructureMFace** rec
		) {
	return false;
};

ubigint TblPlnrOMStructureMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	return 0;
};

void TblPlnrOMStructureMFace::insertRec(
			PlnrOMStructureMFace* rec
		) {
};

ubigint TblPlnrOMStructureMFace::insertNewRec(
			PlnrOMStructureMFace** rec
			, const ubigint refPlnrMStructure
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrOMStructureMFace* _rec = NULL;

	_rec = new PlnrOMStructureMFace(0, refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrOMStructureMFace::appendNewRecToRst(
			ListPlnrOMStructureMFace& rst
			, PlnrOMStructureMFace** rec
			, const ubigint refPlnrMStructure
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrOMStructureMFace* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrOMStructureMFace::insertRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
};

void TblPlnrOMStructureMFace::updateRec(
			PlnrOMStructureMFace* rec
		) {
};

void TblPlnrOMStructureMFace::updateRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
};

void TblPlnrOMStructureMFace::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrOMStructureMFace::loadRecByRef(
			ubigint ref
			, PlnrOMStructureMFace** rec
		) {
	return false;
};

ubigint TblPlnrOMStructureMFace::loadRstBySruDev(
			ubigint refPlnrMStructure
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	return 0;
};

ubigint TblPlnrOMStructureMFace::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	ubigint numload = 0;
	PlnrOMStructureMFace* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrOMStructureMFace
 ******************************************************************************/

MyTblPlnrOMStructureMFace::MyTblPlnrOMStructureMFace() : TblPlnrOMStructureMFace(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrOMStructureMFace::~MyTblPlnrOMStructureMFace() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrOMStructureMFace::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrOMStructureMFace (refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrOMStructureMFace SET refPlnrMStructure = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrOMStructureMFace WHERE ref = ?", false);
};

bool MyTblPlnrOMStructureMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrOMStructureMFace** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrOMStructureMFace* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrOMStructureMFace / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrOMStructureMFace();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMStructure = atoll((char*) dbrow[1]); else _rec->refPlnrMStructure = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDevice = 0;
		if (dbrow[3]) _rec->ixPlnrVLop = atol((char*) dbrow[3]); else _rec->ixPlnrVLop = 0;
		if (dbrow[4]) _rec->pr1RefM = atoll((char*) dbrow[4]); else _rec->pr1RefM = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrOMStructureMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrOMStructureMFace* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrOMStructureMFace / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrOMStructureMFace();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMStructure = atoll((char*) dbrow[1]); else rec->refPlnrMStructure = 0;
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

void MyTblPlnrOMStructureMFace::insertRec(
			PlnrOMStructureMFace* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStructure,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrOMStructureMFace / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrOMStructureMFace / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrOMStructureMFace::insertRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrOMStructureMFace::updateRec(
			PlnrOMStructureMFace* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStructure,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrOMStructureMFace / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrOMStructureMFace / stmtUpdateRec)\n");
};

void MyTblPlnrOMStructureMFace::updateRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrOMStructureMFace::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrOMStructureMFace / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrOMStructureMFace / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrOMStructureMFace::loadRecByRef(
			ubigint ref
			, PlnrOMStructureMFace** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrOMStructureMFace WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrOMStructureMFace::loadRstBySruDev(
			ubigint refPlnrMStructure
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrOMStructureMFace WHERE refPlnrMStructure = " + to_string(refPlnrMStructure) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrOMStructureMFace
 ******************************************************************************/

PgTblPlnrOMStructureMFace::PgTblPlnrOMStructureMFace() : TblPlnrOMStructureMFace(), PgTable() {
};

PgTblPlnrOMStructureMFace::~PgTblPlnrOMStructureMFace() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrOMStructureMFace::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrOMStructureMFace_insertRec", "INSERT INTO TblPlnrOMStructureMFace (refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrOMStructureMFace_updateRec", "UPDATE TblPlnrOMStructureMFace SET refPlnrMStructure = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefM = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrOMStructureMFace_removeRecByRef", "DELETE FROM TblPlnrOMStructureMFace WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrOMStructureMFace_loadRecByRef", "SELECT ref, refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrOMStructureMFace WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrOMStructureMFace_loadRstBySruDev", "SELECT ref, refPlnrMStructure, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrOMStructureMFace WHERE refPlnrMStructure = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrOMStructureMFace::loadRec(
			PGresult* res
			, PlnrOMStructureMFace** rec
		) {
	char* ptr;

	PlnrOMStructureMFace* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrOMStructureMFace();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1refm")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMStructure = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrVLop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pr1RefM = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrOMStructureMFace::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrOMStructureMFace* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1refm")
		};

		while (numread < numrow) {
			rec = new PlnrOMStructureMFace();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMStructure = atoll(ptr);
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

bool PgTblPlnrOMStructureMFace::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrOMStructureMFace** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrOMStructureMFace / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrOMStructureMFace::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrOMStructureMFace / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrOMStructureMFace::loadRecBySQL(
			const string& sqlstr
			, PlnrOMStructureMFace** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrOMStructureMFace::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrOMStructureMFace::insertRec(
			PlnrOMStructureMFace* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefM = htonl64(rec->pr1RefM);

	const char* vals[] = {
		(char*) &_refPlnrMStructure,
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

	res = PQexecPrepared(dbs, "TblPlnrOMStructureMFace_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrOMStructureMFace_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrOMStructureMFace::insertRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrOMStructureMFace::updateRec(
			PlnrOMStructureMFace* rec
		) {
	PGresult* res;

	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefM = htonl64(rec->pr1RefM);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMStructure,
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

	res = PQexecPrepared(dbs, "TblPlnrOMStructureMFace_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrOMStructureMFace_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrOMStructureMFace::updateRst(
			ListPlnrOMStructureMFace& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrOMStructureMFace::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrOMStructureMFace_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrOMStructureMFace_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrOMStructureMFace::loadRecByRef(
			ubigint ref
			, PlnrOMStructureMFace** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrOMStructureMFace_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrOMStructureMFace::loadRstBySruDev(
			ubigint refPlnrMStructure
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrOMStructureMFace& rst
		) {
	ubigint _refPlnrMStructure = htonl64(refPlnrMStructure);
	ubigint _x1RefPlnrMDevice = htonl64(x1RefPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMStructure,
		(char*) &_x1RefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrOMStructureMFace_loadRstBySruDev", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

