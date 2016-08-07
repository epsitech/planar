/**
  * \file PlnrAMDevicePar.cpp
  * database access for table TblPlnrAMDevicePar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMDevicePar.h"

/******************************************************************************
 class PlnrAMDevicePar
 ******************************************************************************/

PlnrAMDevicePar::PlnrAMDevicePar(
			const ubigint ref
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKKey
			, const ubigint refPlnrMFile
			, const string Val
		) {

	this->ref = ref;
	this->refPlnrMDevice = refPlnrMDevice;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->x2SrefKKey = x2SrefKKey;
	this->refPlnrMFile = refPlnrMFile;
	this->Val = Val;
};

bool PlnrAMDevicePar::operator==(
			const PlnrAMDevicePar& comp
		) {
	return false;
};

bool PlnrAMDevicePar::operator!=(
			const PlnrAMDevicePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMDevicePar
 ******************************************************************************/

ListPlnrAMDevicePar::ListPlnrAMDevicePar() {
};

ListPlnrAMDevicePar::ListPlnrAMDevicePar(
			const ListPlnrAMDevicePar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMDevicePar(*(src.nodes[i]));
};

ListPlnrAMDevicePar::~ListPlnrAMDevicePar() {
	clear();
};

void ListPlnrAMDevicePar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMDevicePar::size() const {
	return(nodes.size());
};

void ListPlnrAMDevicePar::append(
			PlnrAMDevicePar* rec
		) {
	nodes.push_back(rec);
};

PlnrAMDevicePar* ListPlnrAMDevicePar::operator[](
			const uint ix
		) {
	PlnrAMDevicePar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMDevicePar& ListPlnrAMDevicePar::operator=(
			const ListPlnrAMDevicePar& src
		) {
	PlnrAMDevicePar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMDevicePar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMDevicePar::operator==(
			const ListPlnrAMDevicePar& comp
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

bool ListPlnrAMDevicePar::operator!=(
			const ListPlnrAMDevicePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMDevicePar
 ******************************************************************************/

TblPlnrAMDevicePar::TblPlnrAMDevicePar() {
};

TblPlnrAMDevicePar::~TblPlnrAMDevicePar() {
};

bool TblPlnrAMDevicePar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMDevicePar** rec
		) {
	return false;
};

ubigint TblPlnrAMDevicePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	return 0;
};

void TblPlnrAMDevicePar::insertRec(
			PlnrAMDevicePar* rec
		) {
};

ubigint TblPlnrAMDevicePar::insertNewRec(
			PlnrAMDevicePar** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKKey
			, const ubigint refPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMDevicePar* _rec = NULL;

	_rec = new PlnrAMDevicePar(0, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMDevicePar::appendNewRecToRst(
			ListPlnrAMDevicePar& rst
			, PlnrAMDevicePar** rec
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string x2SrefKKey
			, const ubigint refPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMDevicePar* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMDevicePar::insertRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
};

void TblPlnrAMDevicePar::updateRec(
			PlnrAMDevicePar* rec
		) {
};

void TblPlnrAMDevicePar::updateRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
};

void TblPlnrAMDevicePar::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMDevicePar::loadRecByRef(
			ubigint ref
			, PlnrAMDevicePar** rec
		) {
	return false;
};

bool TblPlnrAMDevicePar::confirmByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
		) {
	return false;
};

bool TblPlnrAMDevicePar::loadRecByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
			, PlnrAMDevicePar** rec
		) {
	return false;
};

ubigint TblPlnrAMDevicePar::loadRefsByDev(
			ubigint refPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrAMDevicePar::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	return 0;
};

ubigint TblPlnrAMDevicePar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	ubigint numload = 0;
	PlnrAMDevicePar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMDevicePar
 ******************************************************************************/

MyTblPlnrAMDevicePar::MyTblPlnrAMDevicePar() : TblPlnrAMDevicePar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMDevicePar::~MyTblPlnrAMDevicePar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMDevicePar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMDevicePar (refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMDevicePar SET refPlnrMDevice = ?, x1RefPlnrMDesign = ?, x2SrefKKey = ?, refPlnrMFile = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMDevicePar WHERE ref = ?", false);
};

bool MyTblPlnrAMDevicePar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMDevicePar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMDevicePar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMDevicePar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMDevicePar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDevice = atoll((char*) dbrow[1]); else _rec->refPlnrMDevice = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKKey = "";
		if (dbrow[4]) _rec->refPlnrMFile = atoll((char*) dbrow[4]); else _rec->refPlnrMFile = 0;
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMDevicePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMDevicePar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMDevicePar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMDevicePar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDevice = atoll((char*) dbrow[1]); else rec->refPlnrMDevice = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else rec->x2SrefKKey = "";
			if (dbrow[4]) rec->refPlnrMFile = atoll((char*) dbrow[4]); else rec->refPlnrMFile = 0;
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMDevicePar::insertRec(
			PlnrAMDevicePar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMFile,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMDevicePar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMDevicePar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMDevicePar::insertRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMDevicePar::updateRec(
			PlnrAMDevicePar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->x2SrefKKey.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDevice,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMFile,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMDevicePar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMDevicePar / stmtUpdateRec)\n");
};

void MyTblPlnrAMDevicePar::updateRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMDevicePar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMDevicePar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMDevicePar / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMDevicePar::loadRecByRef(
			ubigint ref
			, PlnrAMDevicePar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMDevicePar WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrAMDevicePar::confirmByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND x2SrefKKey = '" + x2SrefKKey + "'", val);
};

bool MyTblPlnrAMDevicePar::loadRecByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
			, PlnrAMDevicePar** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND x2SrefKKey = '" + x2SrefKKey + "'", rec);
};

ubigint MyTblPlnrAMDevicePar::loadRefsByDev(
			ubigint refPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + "", append, refs);
};

ubigint MyTblPlnrAMDevicePar::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMDevicePar
 ******************************************************************************/

PgTblPlnrAMDevicePar::PgTblPlnrAMDevicePar() : TblPlnrAMDevicePar(), PgTable() {
};

PgTblPlnrAMDevicePar::~PgTblPlnrAMDevicePar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMDevicePar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMDevicePar_insertRec", "INSERT INTO TblPlnrAMDevicePar (refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_updateRec", "UPDATE TblPlnrAMDevicePar SET refPlnrMDevice = $1, x1RefPlnrMDesign = $2, x2SrefKKey = $3, refPlnrMFile = $4, Val = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_removeRecByRef", "DELETE FROM TblPlnrAMDevicePar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMDevicePar_loadRecByRef", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrAMDevicePar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_confirmByDevDsnKey", "SELECT ref FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = $1 AND x1RefPlnrMDesign = $2 AND x2SrefKKey = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_loadRecByDevDsnKey", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = $1 AND x1RefPlnrMDesign = $2 AND x2SrefKKey = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_loadRefsByDev", "SELECT ref FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMDevicePar_loadRstByDev", "SELECT ref, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMDevicePar::loadRec(
			PGresult* res
			, PlnrAMDevicePar** rec
		) {
	char* ptr;

	PlnrAMDevicePar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMDevicePar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMDevicePar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMDevicePar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdevice"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAMDevicePar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMDevicePar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMDevicePar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMDevicePar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrAMDevicePar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMDevicePar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrAMDevicePar::loadRecBySQL(
			const string& sqlstr
			, PlnrAMDevicePar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMDevicePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMDevicePar::insertRec(
			PlnrAMDevicePar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrAMDevicePar_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMDevicePar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMDevicePar::insertRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMDevicePar::updateRec(
			PlnrAMDevicePar* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDevice = htonl64(rec->refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMDevicePar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMDevicePar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMDevicePar::updateRst(
			ListPlnrAMDevicePar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMDevicePar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMDevicePar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMDevicePar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMDevicePar::loadRecByRef(
			ubigint ref
			, PlnrAMDevicePar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMDevicePar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrAMDevicePar::confirmByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		x2SrefKKey.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadUbigintByStmt("TblPlnrAMDevicePar_confirmByDevDsnKey", 1, vals, l, f, _refPlnrMDevice);
};

bool PgTblPlnrAMDevicePar::loadRecByDevDsnKey(
			ubigint refPlnrMDevice
			, ubigint x1RefPlnrMDesign
			, string x2SrefKKey
			, PlnrAMDevicePar** rec
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDevice,
		(char*) &_x1RefPlnrMDesign,
		x2SrefKKey.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadRecByStmt("TblPlnrAMDevicePar_loadRecByDevDsnKey", 3, vals, l, f, rec);
};

ubigint PgTblPlnrAMDevicePar::loadRefsByDev(
			ubigint refPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrAMDevicePar_loadRefsByDev", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrAMDevicePar::loadRstByDev(
			ubigint refPlnrMDevice
			, const bool append
			, ListPlnrAMDevicePar& rst
		) {
	ubigint _refPlnrMDevice = htonl64(refPlnrMDevice);

	const char* vals[] = {
		(char*) &_refPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrAMDevicePar_loadRstByDev", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

