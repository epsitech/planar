/**
  * \file PlnrJMDeviceModtype.cpp
  * database access for table TblPlnrJMDeviceModtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMDeviceModtype.h"

/******************************************************************************
 class PlnrJMDeviceModtype
 ******************************************************************************/

PlnrJMDeviceModtype::PlnrJMDeviceModtype(
			const ubigint ref
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {

	this->ref = ref;
	this->refPlnrMDevice = refPlnrMDevice;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->ixVModtype = ixVModtype;
};

bool PlnrJMDeviceModtype::operator==(
			const PlnrJMDeviceModtype& comp
		) {
	return false;
};

bool PlnrJMDeviceModtype::operator!=(
			const PlnrJMDeviceModtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMDeviceModtype
 ******************************************************************************/

ListPlnrJMDeviceModtype::ListPlnrJMDeviceModtype() {
};

ListPlnrJMDeviceModtype::ListPlnrJMDeviceModtype(
			const ListPlnrJMDeviceModtype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMDeviceModtype(*(src.nodes[i]));
};

ListPlnrJMDeviceModtype::~ListPlnrJMDeviceModtype() {
	clear();
};

void ListPlnrJMDeviceModtype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMDeviceModtype::size() const {
	return(nodes.size());
};

void ListPlnrJMDeviceModtype::append(
			PlnrJMDeviceModtype* rec
		) {
	nodes.push_back(rec);
};

PlnrJMDeviceModtype* ListPlnrJMDeviceModtype::operator[](
			const uint ix
		) {
	PlnrJMDeviceModtype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMDeviceModtype& ListPlnrJMDeviceModtype::operator=(
			const ListPlnrJMDeviceModtype& src
		) {
	PlnrJMDeviceModtype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMDeviceModtype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMDeviceModtype::operator==(
			const ListPlnrJMDeviceModtype& comp
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

bool ListPlnrJMDeviceModtype::operator!=(
			const ListPlnrJMDeviceModtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMDeviceModtype
 ******************************************************************************/

TblPlnrJMDeviceModtype::TblPlnrJMDeviceModtype() {
};

TblPlnrJMDeviceModtype::~TblPlnrJMDeviceModtype() {
};

bool TblPlnrJMDeviceModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDeviceModtype** rec
		) {
	return false;
};

ubigint TblPlnrJMDeviceModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	return 0;
};

void TblPlnrJMDeviceModtype::insertRec(
			PlnrJMDeviceModtype* rec
		) {
};

ubigint TblPlnrJMDeviceModtype::insertNewRec(
			PlnrJMDeviceModtype** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	ubigint retval = 0;
	PlnrJMDeviceModtype* _rec = NULL;

	_rec = new PlnrJMDeviceModtype(0, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMDeviceModtype::appendNewRecToRst(
			ListPlnrJMDeviceModtype& rst
			, PlnrJMDeviceModtype** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	ubigint retval = 0;
	PlnrJMDeviceModtype* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMDeviceModtype::insertRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
};

void TblPlnrJMDeviceModtype::updateRec(
			PlnrJMDeviceModtype* rec
		) {
};

void TblPlnrJMDeviceModtype::updateRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
};

void TblPlnrJMDeviceModtype::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMDeviceModtype::loadRecByRef(
			ubigint ref
			, PlnrJMDeviceModtype** rec
		) {
	return false;
};

bool TblPlnrJMDeviceModtype::loadRecByDevDsn(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, PlnrJMDeviceModtype** rec
		) {
	return false;
};

ubigint TblPlnrJMDeviceModtype::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	return 0;
};

ubigint TblPlnrJMDeviceModtype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	ubigint numload = 0;
	PlnrJMDeviceModtype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMDeviceModtype
 ******************************************************************************/

MyTblPlnrJMDeviceModtype::MyTblPlnrJMDeviceModtype() : TblPlnrJMDeviceModtype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMDeviceModtype::~MyTblPlnrJMDeviceModtype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMDeviceModtype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMDeviceModtype (refPlnrMDevice, x1RefPlnrMDesign, ixVModtype) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMDeviceModtype SET refPlnrMDevice = ?, x1RefPlnrMDesign = ?, ixVModtype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMDeviceModtype WHERE ref = ?", false);
};

bool MyTblPlnrJMDeviceModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDeviceModtype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMDeviceModtype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDeviceModtype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMDeviceModtype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDevice = atoll((char*) dbrow[1]); else _rec->refPlnrMDevice = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->ixVModtype = atol((char*) dbrow[3]); else _rec->ixVModtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMDeviceModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMDeviceModtype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMDeviceModtype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMDeviceModtype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDevice = atoll((char*) dbrow[1]); else rec->refPlnrMDevice = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->ixVModtype = atol((char*) dbrow[3]); else rec->ixVModtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMDeviceModtype::insertRec(
			PlnrJMDeviceModtype* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVModtype,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDeviceModtype / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDeviceModtype / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMDeviceModtype::insertRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMDeviceModtype::updateRec(
			PlnrJMDeviceModtype* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVModtype,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDeviceModtype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDeviceModtype / stmtUpdateRec)\n");
};

void MyTblPlnrJMDeviceModtype::updateRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMDeviceModtype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMDeviceModtype / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMDeviceModtype / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMDeviceModtype::loadRecByRef(
			ubigint ref
			, PlnrJMDeviceModtype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMDeviceModtype WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMDeviceModtype::loadRecByDevDsn(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, PlnrJMDeviceModtype** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMDeviceModtype::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMDeviceModtype
 ******************************************************************************/

PgTblPlnrJMDeviceModtype::PgTblPlnrJMDeviceModtype() : TblPlnrJMDeviceModtype(), PgTable() {
};

PgTblPlnrJMDeviceModtype::~PgTblPlnrJMDeviceModtype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMDeviceModtype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_insertRec", "INSERT INTO TblPlnrJMDeviceModtype (refPlnrMDevice, x1RefPlnrMDesign, ixVModtype) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_updateRec", "UPDATE TblPlnrJMDeviceModtype SET refPlnrMDevice = $1, x1RefPlnrMDesign = $2, ixVModtype = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_removeRecByRef", "DELETE FROM TblPlnrJMDeviceModtype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_loadRecByRef", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMDeviceModtype WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_loadRecByDevDsn", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMDeviceModtype_loadRstByDev", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMDeviceModtype::loadRec(
			PGresult* res
			, PlnrJMDeviceModtype** rec
		) {
	char* ptr;

	PlnrJMDeviceModtype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMDeviceModtype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvmodtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVModtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMDeviceModtype::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMDeviceModtype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvmodtype")
		};

		while (numread < numrow) {
			rec = new PlnrJMDeviceModtype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVModtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMDeviceModtype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMDeviceModtype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDeviceModtype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMDeviceModtype::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDeviceModtype / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMDeviceModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMDeviceModtype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMDeviceModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMDeviceModtype::insertRec(
			PlnrJMDeviceModtype* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVModtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMDeviceModtype_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDeviceModtype_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMDeviceModtype::insertRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMDeviceModtype::updateRec(
			PlnrJMDeviceModtype* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVModtype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMDeviceModtype_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDeviceModtype_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMDeviceModtype::updateRst(
			ListPlnrJMDeviceModtype& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMDeviceModtype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMDeviceModtype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMDeviceModtype_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMDeviceModtype::loadRecByRef(
			ubigint ref
			, PlnrJMDeviceModtype** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMDeviceModtype_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMDeviceModtype::loadRecByDevDsn(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, PlnrJMDeviceModtype** rec
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMDeviceModtype_loadRecByDevDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMDeviceModtype::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrJMDeviceModtype& rst
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMDeviceModtype_loadRstByDev", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

