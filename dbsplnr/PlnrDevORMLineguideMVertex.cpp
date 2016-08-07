/**
  * \file PlnrDevORMLineguideMVertex.cpp
  * database access for table TblPlnrDevORMLineguideMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrDevORMLineguideMVertex.h"

/******************************************************************************
 class PlnrDevORMLineguideMVertex
 ******************************************************************************/

PlnrDevORMLineguideMVertex::PlnrDevORMLineguideMVertex(
			const ubigint ref
			, const ubigint refPlnrMLineguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {

	this->ref = ref;
	this->refPlnrMLineguide = refPlnrMLineguide;
	this->x1RefPlnrMDevice = x1RefPlnrMDevice;
	this->ixPlnrVLop = ixPlnrVLop;
	this->pr1RefLR = pr1RefLR;
};

bool PlnrDevORMLineguideMVertex::operator==(
			const PlnrDevORMLineguideMVertex& comp
		) {
	return false;
};

bool PlnrDevORMLineguideMVertex::operator!=(
			const PlnrDevORMLineguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrDevORMLineguideMVertex
 ******************************************************************************/

ListPlnrDevORMLineguideMVertex::ListPlnrDevORMLineguideMVertex() {
};

ListPlnrDevORMLineguideMVertex::ListPlnrDevORMLineguideMVertex(
			const ListPlnrDevORMLineguideMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrDevORMLineguideMVertex(*(src.nodes[i]));
};

ListPlnrDevORMLineguideMVertex::~ListPlnrDevORMLineguideMVertex() {
	clear();
};

void ListPlnrDevORMLineguideMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrDevORMLineguideMVertex::size() const {
	return(nodes.size());
};

void ListPlnrDevORMLineguideMVertex::append(
			PlnrDevORMLineguideMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrDevORMLineguideMVertex* ListPlnrDevORMLineguideMVertex::operator[](
			const uint ix
		) {
	PlnrDevORMLineguideMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrDevORMLineguideMVertex& ListPlnrDevORMLineguideMVertex::operator=(
			const ListPlnrDevORMLineguideMVertex& src
		) {
	PlnrDevORMLineguideMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrDevORMLineguideMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrDevORMLineguideMVertex::operator==(
			const ListPlnrDevORMLineguideMVertex& comp
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

bool ListPlnrDevORMLineguideMVertex::operator!=(
			const ListPlnrDevORMLineguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrDevORMLineguideMVertex
 ******************************************************************************/

TblPlnrDevORMLineguideMVertex::TblPlnrDevORMLineguideMVertex() {
};

TblPlnrDevORMLineguideMVertex::~TblPlnrDevORMLineguideMVertex() {
};

bool TblPlnrDevORMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMLineguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevORMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	return 0;
};

void TblPlnrDevORMLineguideMVertex::insertRec(
			PlnrDevORMLineguideMVertex* rec
		) {
};

ubigint TblPlnrDevORMLineguideMVertex::insertNewRec(
			PlnrDevORMLineguideMVertex** rec
			, const ubigint refPlnrMLineguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {
	ubigint retval = 0;
	PlnrDevORMLineguideMVertex* _rec = NULL;

	_rec = new PlnrDevORMLineguideMVertex(0, refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrDevORMLineguideMVertex::appendNewRecToRst(
			ListPlnrDevORMLineguideMVertex& rst
			, PlnrDevORMLineguideMVertex** rec
			, const ubigint refPlnrMLineguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {
	ubigint retval = 0;
	PlnrDevORMLineguideMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrDevORMLineguideMVertex::insertRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevORMLineguideMVertex::updateRec(
			PlnrDevORMLineguideMVertex* rec
		) {
};

void TblPlnrDevORMLineguideMVertex::updateRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevORMLineguideMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrDevORMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMLineguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevORMLineguideMVertex::loadRstByLgdDev(
			ubigint refPlnrMLineguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrDevORMLineguideMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	ubigint numload = 0;
	PlnrDevORMLineguideMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrDevORMLineguideMVertex
 ******************************************************************************/

MyTblPlnrDevORMLineguideMVertex::MyTblPlnrDevORMLineguideMVertex() : TblPlnrDevORMLineguideMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrDevORMLineguideMVertex::~MyTblPlnrDevORMLineguideMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrDevORMLineguideMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrDevORMLineguideMVertex (refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrDevORMLineguideMVertex SET refPlnrMLineguide = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefLR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrDevORMLineguideMVertex WHERE ref = ?", false);
};

bool MyTblPlnrDevORMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMLineguideMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrDevORMLineguideMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevORMLineguideMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrDevORMLineguideMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMLineguide = atoll((char*) dbrow[1]); else _rec->refPlnrMLineguide = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDevice = 0;
		if (dbrow[3]) _rec->ixPlnrVLop = atol((char*) dbrow[3]); else _rec->ixPlnrVLop = 0;
		if (dbrow[4]) _rec->pr1RefLR = atoll((char*) dbrow[4]); else _rec->pr1RefLR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrDevORMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrDevORMLineguideMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevORMLineguideMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrDevORMLineguideMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMLineguide = atoll((char*) dbrow[1]); else rec->refPlnrMLineguide = 0;
			if (dbrow[2]) rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDevice = 0;
			if (dbrow[3]) rec->ixPlnrVLop = atol((char*) dbrow[3]); else rec->ixPlnrVLop = 0;
			if (dbrow[4]) rec->pr1RefLR = atoll((char*) dbrow[4]); else rec->pr1RefLR = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrDevORMLineguideMVertex::insertRec(
			PlnrDevORMLineguideMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLineguide,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMLineguideMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMLineguideMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrDevORMLineguideMVertex::insertRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrDevORMLineguideMVertex::updateRec(
			PlnrDevORMLineguideMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLineguide,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMLineguideMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMLineguideMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrDevORMLineguideMVertex::updateRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrDevORMLineguideMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMLineguideMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMLineguideMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrDevORMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMLineguideMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrDevORMLineguideMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrDevORMLineguideMVertex::loadRstByLgdDev(
			ubigint refPlnrMLineguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMLineguideMVertex WHERE refPlnrMLineguide = " + to_string(refPlnrMLineguide) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrDevORMLineguideMVertex
 ******************************************************************************/

PgTblPlnrDevORMLineguideMVertex::PgTblPlnrDevORMLineguideMVertex() : TblPlnrDevORMLineguideMVertex(), PgTable() {
};

PgTblPlnrDevORMLineguideMVertex::~PgTblPlnrDevORMLineguideMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrDevORMLineguideMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrDevORMLineguideMVertex_insertRec", "INSERT INTO TblPlnrDevORMLineguideMVertex (refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevORMLineguideMVertex_updateRec", "UPDATE TblPlnrDevORMLineguideMVertex SET refPlnrMLineguide = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefLR = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevORMLineguideMVertex_removeRecByRef", "DELETE FROM TblPlnrDevORMLineguideMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrDevORMLineguideMVertex_loadRecByRef", "SELECT ref, refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMLineguideMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrDevORMLineguideMVertex_loadRstByLgdDev", "SELECT ref, refPlnrMLineguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMLineguideMVertex WHERE refPlnrMLineguide = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrDevORMLineguideMVertex::loadRec(
			PGresult* res
			, PlnrDevORMLineguideMVertex** rec
		) {
	char* ptr;

	PlnrDevORMLineguideMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrDevORMLineguideMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlineguide"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1reflr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMLineguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrVLop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pr1RefLR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrDevORMLineguideMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrDevORMLineguideMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlineguide"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1reflr")
		};

		while (numread < numrow) {
			rec = new PlnrDevORMLineguideMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMLineguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixPlnrVLop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->pr1RefLR = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrDevORMLineguideMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrDevORMLineguideMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMLineguideMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrDevORMLineguideMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMLineguideMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrDevORMLineguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMLineguideMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrDevORMLineguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrDevORMLineguideMVertex::insertRec(
			PlnrDevORMLineguideMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMLineguide = htonl64(rec->refPlnrMLineguide);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);

	const char* vals[] = {
		(char*) &_refPlnrMLineguide,
		(char*) &_x1RefPlnrMDevice,
		(char*) &_ixPlnrVLop,
		(char*) &_pr1RefLR
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrDevORMLineguideMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMLineguideMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrDevORMLineguideMVertex::insertRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrDevORMLineguideMVertex::updateRec(
			PlnrDevORMLineguideMVertex* rec
		) {
	PGresult* res;

	ubigint _refPlnrMLineguide = htonl64(rec->refPlnrMLineguide);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMLineguide,
		(char*) &_x1RefPlnrMDevice,
		(char*) &_ixPlnrVLop,
		(char*) &_pr1RefLR,
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

	res = PQexecPrepared(dbs, "TblPlnrDevORMLineguideMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMLineguideMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrDevORMLineguideMVertex::updateRst(
			ListPlnrDevORMLineguideMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrDevORMLineguideMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrDevORMLineguideMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMLineguideMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrDevORMLineguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMLineguideMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrDevORMLineguideMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrDevORMLineguideMVertex::loadRstByLgdDev(
			ubigint refPlnrMLineguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMLineguideMVertex& rst
		) {
	ubigint _refPlnrMLineguide = htonl64(refPlnrMLineguide);
	ubigint _x1RefPlnrMDevice = htonl64(x1RefPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMLineguide,
		(char*) &_x1RefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrDevORMLineguideMVertex_loadRstByLgdDev", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

