/**
  * \file PlnrDevOMDeviceMVertex.cpp
  * database access for table TblPlnrDevOMDeviceMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrDevOMDeviceMVertex.h"

/******************************************************************************
 class PlnrDevOMDeviceMVertex
 ******************************************************************************/

PlnrDevOMDeviceMVertex::PlnrDevOMDeviceMVertex(
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

bool PlnrDevOMDeviceMVertex::operator==(
			const PlnrDevOMDeviceMVertex& comp
		) {
	return false;
};

bool PlnrDevOMDeviceMVertex::operator!=(
			const PlnrDevOMDeviceMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrDevOMDeviceMVertex
 ******************************************************************************/

ListPlnrDevOMDeviceMVertex::ListPlnrDevOMDeviceMVertex() {
};

ListPlnrDevOMDeviceMVertex::ListPlnrDevOMDeviceMVertex(
			const ListPlnrDevOMDeviceMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrDevOMDeviceMVertex(*(src.nodes[i]));
};

ListPlnrDevOMDeviceMVertex::~ListPlnrDevOMDeviceMVertex() {
	clear();
};

void ListPlnrDevOMDeviceMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrDevOMDeviceMVertex::size() const {
	return(nodes.size());
};

void ListPlnrDevOMDeviceMVertex::append(
			PlnrDevOMDeviceMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrDevOMDeviceMVertex* ListPlnrDevOMDeviceMVertex::operator[](
			const uint ix
		) {
	PlnrDevOMDeviceMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrDevOMDeviceMVertex& ListPlnrDevOMDeviceMVertex::operator=(
			const ListPlnrDevOMDeviceMVertex& src
		) {
	PlnrDevOMDeviceMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrDevOMDeviceMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrDevOMDeviceMVertex::operator==(
			const ListPlnrDevOMDeviceMVertex& comp
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

bool ListPlnrDevOMDeviceMVertex::operator!=(
			const ListPlnrDevOMDeviceMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrDevOMDeviceMVertex
 ******************************************************************************/

TblPlnrDevOMDeviceMVertex::TblPlnrDevOMDeviceMVertex() {
};

TblPlnrDevOMDeviceMVertex::~TblPlnrDevOMDeviceMVertex() {
};

bool TblPlnrDevOMDeviceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	return 0;
};

void TblPlnrDevOMDeviceMVertex::insertRec(
			PlnrDevOMDeviceMVertex* rec
		) {
};

ubigint TblPlnrDevOMDeviceMVertex::insertNewRec(
			PlnrDevOMDeviceMVertex** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMVertex* _rec = NULL;

	_rec = new PlnrDevOMDeviceMVertex(0, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrDevOMDeviceMVertex::appendNewRecToRst(
			ListPlnrDevOMDeviceMVertex& rst
			, PlnrDevOMDeviceMVertex** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefM
		) {
	ubigint retval = 0;
	PlnrDevOMDeviceMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrDevOMDeviceMVertex::insertRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMVertex::updateRec(
			PlnrDevOMDeviceMVertex* rec
		) {
};

void TblPlnrDevOMDeviceMVertex::updateRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevOMDeviceMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrDevOMDeviceMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevOMDeviceMVertex::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrDevOMDeviceMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	ubigint numload = 0;
	PlnrDevOMDeviceMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrDevOMDeviceMVertex
 ******************************************************************************/

MyTblPlnrDevOMDeviceMVertex::MyTblPlnrDevOMDeviceMVertex() : TblPlnrDevOMDeviceMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrDevOMDeviceMVertex::~MyTblPlnrDevOMDeviceMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrDevOMDeviceMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrDevOMDeviceMVertex (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrDevOMDeviceMVertex SET refPlnrMDevice = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefM = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrDevOMDeviceMVertex WHERE ref = ?", false);
};

bool MyTblPlnrDevOMDeviceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrDevOMDeviceMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrDevOMDeviceMVertex();

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

ubigint MyTblPlnrDevOMDeviceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrDevOMDeviceMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevOMDeviceMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrDevOMDeviceMVertex();

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

void MyTblPlnrDevOMDeviceMVertex::insertRec(
			PlnrDevOMDeviceMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrDevOMDeviceMVertex::insertRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrDevOMDeviceMVertex::updateRec(
			PlnrDevOMDeviceMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefM,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrDevOMDeviceMVertex::updateRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrDevOMDeviceMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevOMDeviceMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevOMDeviceMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrDevOMDeviceMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrDevOMDeviceMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrDevOMDeviceMVertex::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMVertex WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrDevOMDeviceMVertex
 ******************************************************************************/

PgTblPlnrDevOMDeviceMVertex::PgTblPlnrDevOMDeviceMVertex() : TblPlnrDevOMDeviceMVertex(), PgTable() {
};

PgTblPlnrDevOMDeviceMVertex::~PgTblPlnrDevOMDeviceMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrDevOMDeviceMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMVertex_insertRec", "INSERT INTO TblPlnrDevOMDeviceMVertex (refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMVertex_updateRec", "UPDATE TblPlnrDevOMDeviceMVertex SET refPlnrMDevice = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefM = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMVertex_removeRecByRef", "DELETE FROM TblPlnrDevOMDeviceMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrDevOMDeviceMVertex_loadRecByRef", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrDevOMDeviceMVertex_loadRstByDevDv2", "SELECT ref, refPlnrMDevice, x1RefPlnrMDevice, ixPlnrVLop, pr1RefM FROM TblPlnrDevOMDeviceMVertex WHERE refPlnrMDevice = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrDevOMDeviceMVertex::loadRec(
			PGresult* res
			, PlnrDevOMDeviceMVertex** rec
		) {
	char* ptr;

	PlnrDevOMDeviceMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrDevOMDeviceMVertex();

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

ubigint PgTblPlnrDevOMDeviceMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrDevOMDeviceMVertex* rec;

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
			rec = new PlnrDevOMDeviceMVertex();

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

bool PgTblPlnrDevOMDeviceMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrDevOMDeviceMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrDevOMDeviceMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrDevOMDeviceMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevOMDeviceMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrDevOMDeviceMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrDevOMDeviceMVertex::insertRec(
			PlnrDevOMDeviceMVertex* rec
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMVertex::insertRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrDevOMDeviceMVertex::updateRec(
			PlnrDevOMDeviceMVertex* rec
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrDevOMDeviceMVertex::updateRst(
			ListPlnrDevOMDeviceMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrDevOMDeviceMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrDevOMDeviceMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevOMDeviceMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrDevOMDeviceMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevOMDeviceMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrDevOMDeviceMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrDevOMDeviceMVertex::loadRstByDevDv2(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevOMDeviceMVertex& rst
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

	return loadRstByStmt("TblPlnrDevOMDeviceMVertex_loadRstByDevDv2", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

