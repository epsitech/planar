/**
  * \file PlnrDevORMArcguideMVertex.cpp
  * database access for table TblPlnrDevORMArcguideMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrDevORMArcguideMVertex.h"

/******************************************************************************
 class PlnrDevORMArcguideMVertex
 ******************************************************************************/

PlnrDevORMArcguideMVertex::PlnrDevORMArcguideMVertex(
			const ubigint ref
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {

	this->ref = ref;
	this->refPlnrMArcguide = refPlnrMArcguide;
	this->x1RefPlnrMDevice = x1RefPlnrMDevice;
	this->ixPlnrVLop = ixPlnrVLop;
	this->pr1RefLR = pr1RefLR;
};

bool PlnrDevORMArcguideMVertex::operator==(
			const PlnrDevORMArcguideMVertex& comp
		) {
	return false;
};

bool PlnrDevORMArcguideMVertex::operator!=(
			const PlnrDevORMArcguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrDevORMArcguideMVertex
 ******************************************************************************/

ListPlnrDevORMArcguideMVertex::ListPlnrDevORMArcguideMVertex() {
};

ListPlnrDevORMArcguideMVertex::ListPlnrDevORMArcguideMVertex(
			const ListPlnrDevORMArcguideMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrDevORMArcguideMVertex(*(src.nodes[i]));
};

ListPlnrDevORMArcguideMVertex::~ListPlnrDevORMArcguideMVertex() {
	clear();
};

void ListPlnrDevORMArcguideMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrDevORMArcguideMVertex::size() const {
	return(nodes.size());
};

void ListPlnrDevORMArcguideMVertex::append(
			PlnrDevORMArcguideMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrDevORMArcguideMVertex* ListPlnrDevORMArcguideMVertex::operator[](
			const uint ix
		) {
	PlnrDevORMArcguideMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrDevORMArcguideMVertex& ListPlnrDevORMArcguideMVertex::operator=(
			const ListPlnrDevORMArcguideMVertex& src
		) {
	PlnrDevORMArcguideMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrDevORMArcguideMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrDevORMArcguideMVertex::operator==(
			const ListPlnrDevORMArcguideMVertex& comp
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

bool ListPlnrDevORMArcguideMVertex::operator!=(
			const ListPlnrDevORMArcguideMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrDevORMArcguideMVertex
 ******************************************************************************/

TblPlnrDevORMArcguideMVertex::TblPlnrDevORMArcguideMVertex() {
};

TblPlnrDevORMArcguideMVertex::~TblPlnrDevORMArcguideMVertex() {
};

bool TblPlnrDevORMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMArcguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevORMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	return 0;
};

void TblPlnrDevORMArcguideMVertex::insertRec(
			PlnrDevORMArcguideMVertex* rec
		) {
};

ubigint TblPlnrDevORMArcguideMVertex::insertNewRec(
			PlnrDevORMArcguideMVertex** rec
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {
	ubigint retval = 0;
	PlnrDevORMArcguideMVertex* _rec = NULL;

	_rec = new PlnrDevORMArcguideMVertex(0, refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrDevORMArcguideMVertex::appendNewRecToRst(
			ListPlnrDevORMArcguideMVertex& rst
			, PlnrDevORMArcguideMVertex** rec
			, const ubigint refPlnrMArcguide
			, const ubigint x1RefPlnrMDevice
			, const uint ixPlnrVLop
			, const ubigint pr1RefLR
		) {
	ubigint retval = 0;
	PlnrDevORMArcguideMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrDevORMArcguideMVertex::insertRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevORMArcguideMVertex::updateRec(
			PlnrDevORMArcguideMVertex* rec
		) {
};

void TblPlnrDevORMArcguideMVertex::updateRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
};

void TblPlnrDevORMArcguideMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrDevORMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMArcguideMVertex** rec
		) {
	return false;
};

ubigint TblPlnrDevORMArcguideMVertex::loadRstByAgdDev(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrDevORMArcguideMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	ubigint numload = 0;
	PlnrDevORMArcguideMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrDevORMArcguideMVertex
 ******************************************************************************/

MyTblPlnrDevORMArcguideMVertex::MyTblPlnrDevORMArcguideMVertex() : TblPlnrDevORMArcguideMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrDevORMArcguideMVertex::~MyTblPlnrDevORMArcguideMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrDevORMArcguideMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrDevORMArcguideMVertex (refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrDevORMArcguideMVertex SET refPlnrMArcguide = ?, x1RefPlnrMDevice = ?, ixPlnrVLop = ?, pr1RefLR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrDevORMArcguideMVertex WHERE ref = ?", false);
};

bool MyTblPlnrDevORMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMArcguideMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrDevORMArcguideMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevORMArcguideMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrDevORMArcguideMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMArcguide = atoll((char*) dbrow[1]); else _rec->refPlnrMArcguide = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDevice = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDevice = 0;
		if (dbrow[3]) _rec->ixPlnrVLop = atol((char*) dbrow[3]); else _rec->ixPlnrVLop = 0;
		if (dbrow[4]) _rec->pr1RefLR = atoll((char*) dbrow[4]); else _rec->pr1RefLR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrDevORMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrDevORMArcguideMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrDevORMArcguideMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrDevORMArcguideMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMArcguide = atoll((char*) dbrow[1]); else rec->refPlnrMArcguide = 0;
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

void MyTblPlnrDevORMArcguideMVertex::insertRec(
			PlnrDevORMArcguideMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArcguide,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMArcguideMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMArcguideMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrDevORMArcguideMVertex::insertRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrDevORMArcguideMVertex::updateRec(
			PlnrDevORMArcguideMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArcguide,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDevice,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVLop,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMArcguideMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMArcguideMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrDevORMArcguideMVertex::updateRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrDevORMArcguideMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrDevORMArcguideMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrDevORMArcguideMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrDevORMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMArcguideMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrDevORMArcguideMVertex WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrDevORMArcguideMVertex::loadRstByAgdDev(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMArcguideMVertex WHERE refPlnrMArcguide = " + to_string(refPlnrMArcguide) + " AND x1RefPlnrMDevice = " + to_string(x1RefPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrDevORMArcguideMVertex
 ******************************************************************************/

PgTblPlnrDevORMArcguideMVertex::PgTblPlnrDevORMArcguideMVertex() : TblPlnrDevORMArcguideMVertex(), PgTable() {
};

PgTblPlnrDevORMArcguideMVertex::~PgTblPlnrDevORMArcguideMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrDevORMArcguideMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrDevORMArcguideMVertex_insertRec", "INSERT INTO TblPlnrDevORMArcguideMVertex (refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevORMArcguideMVertex_updateRec", "UPDATE TblPlnrDevORMArcguideMVertex SET refPlnrMArcguide = $1, x1RefPlnrMDevice = $2, ixPlnrVLop = $3, pr1RefLR = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrDevORMArcguideMVertex_removeRecByRef", "DELETE FROM TblPlnrDevORMArcguideMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrDevORMArcguideMVertex_loadRecByRef", "SELECT ref, refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMArcguideMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrDevORMArcguideMVertex_loadRstByAgdDev", "SELECT ref, refPlnrMArcguide, x1RefPlnrMDevice, ixPlnrVLop, pr1RefLR FROM TblPlnrDevORMArcguideMVertex WHERE refPlnrMArcguide = $1 AND x1RefPlnrMDevice = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrDevORMArcguideMVertex::loadRec(
			PGresult* res
			, PlnrDevORMArcguideMVertex** rec
		) {
	char* ptr;

	PlnrDevORMArcguideMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrDevORMArcguideMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarcguide"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1reflr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMArcguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrVLop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pr1RefLR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrDevORMArcguideMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrDevORMArcguideMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarcguide"),
			PQfnumber(res, "x1refplnrmdevice"),
			PQfnumber(res, "ixplnrvlop"),
			PQfnumber(res, "pr1reflr")
		};

		while (numread < numrow) {
			rec = new PlnrDevORMArcguideMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMArcguide = atoll(ptr);
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

bool PgTblPlnrDevORMArcguideMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrDevORMArcguideMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMArcguideMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrDevORMArcguideMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMArcguideMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrDevORMArcguideMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrDevORMArcguideMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrDevORMArcguideMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrDevORMArcguideMVertex::insertRec(
			PlnrDevORMArcguideMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMArcguide = htonl64(rec->refPlnrMArcguide);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
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

	res = PQexecPrepared(dbs, "TblPlnrDevORMArcguideMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMArcguideMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrDevORMArcguideMVertex::insertRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrDevORMArcguideMVertex::updateRec(
			PlnrDevORMArcguideMVertex* rec
		) {
	PGresult* res;

	ubigint _refPlnrMArcguide = htonl64(rec->refPlnrMArcguide);
	ubigint _x1RefPlnrMDevice = htonl64(rec->x1RefPlnrMDevice);
	uint _ixPlnrVLop = htonl(rec->ixPlnrVLop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
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

	res = PQexecPrepared(dbs, "TblPlnrDevORMArcguideMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMArcguideMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrDevORMArcguideMVertex::updateRst(
			ListPlnrDevORMArcguideMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrDevORMArcguideMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrDevORMArcguideMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrDevORMArcguideMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrDevORMArcguideMVertex::loadRecByRef(
			ubigint ref
			, PlnrDevORMArcguideMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrDevORMArcguideMVertex_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrDevORMArcguideMVertex::loadRstByAgdDev(
			ubigint refPlnrMArcguide
			, ubigint x1RefPlnrMDevice
			, const bool append
			, ListPlnrDevORMArcguideMVertex& rst
		) {
	ubigint _refPlnrMArcguide = htonl64(refPlnrMArcguide);
	ubigint _x1RefPlnrMDevice = htonl64(x1RefPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMArcguide,
		(char*) &_x1RefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrDevORMArcguideMVertex_loadRstByAgdDev", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

