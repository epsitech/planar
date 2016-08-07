/**
  * \file PlnrHistRMUserUniversal.cpp
  * database access for table TblPlnrHistRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrHistRMUserUniversal.h"

/******************************************************************************
 class PlnrHistRMUserUniversal
 ******************************************************************************/

PlnrHistRMUserUniversal::PlnrHistRMUserUniversal(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVCard
			, const uint ixPlnrVPreset
			, const uint preIxPlnrVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->unvIxPlnrVMaintable = unvIxPlnrVMaintable;
	this->unvUref = unvUref;
	this->ixPlnrVCard = ixPlnrVCard;
	this->ixPlnrVPreset = ixPlnrVPreset;
	this->preIxPlnrVMaintable = preIxPlnrVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool PlnrHistRMUserUniversal::operator==(
			const PlnrHistRMUserUniversal& comp
		) {
	return false;
};

bool PlnrHistRMUserUniversal::operator!=(
			const PlnrHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrHistRMUserUniversal
 ******************************************************************************/

ListPlnrHistRMUserUniversal::ListPlnrHistRMUserUniversal() {
};

ListPlnrHistRMUserUniversal::ListPlnrHistRMUserUniversal(
			const ListPlnrHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrHistRMUserUniversal(*(src.nodes[i]));
};

ListPlnrHistRMUserUniversal::~ListPlnrHistRMUserUniversal() {
	clear();
};

void ListPlnrHistRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListPlnrHistRMUserUniversal::append(
			PlnrHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

PlnrHistRMUserUniversal* ListPlnrHistRMUserUniversal::operator[](
			const uint ix
		) {
	PlnrHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrHistRMUserUniversal& ListPlnrHistRMUserUniversal::operator=(
			const ListPlnrHistRMUserUniversal& src
		) {
	PlnrHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrHistRMUserUniversal::operator==(
			const ListPlnrHistRMUserUniversal& comp
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

bool ListPlnrHistRMUserUniversal::operator!=(
			const ListPlnrHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrHistRMUserUniversal
 ******************************************************************************/

TblPlnrHistRMUserUniversal::TblPlnrHistRMUserUniversal() {
};

TblPlnrHistRMUserUniversal::~TblPlnrHistRMUserUniversal() {
};

bool TblPlnrHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblPlnrHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	return 0;
};

void TblPlnrHistRMUserUniversal::insertRec(
			PlnrHistRMUserUniversal* rec
		) {
};

ubigint TblPlnrHistRMUserUniversal::insertNewRec(
			PlnrHistRMUserUniversal** rec
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVCard
			, const uint ixPlnrVPreset
			, const uint preIxPlnrVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	PlnrHistRMUserUniversal* _rec = NULL;

	_rec = new PlnrHistRMUserUniversal(0, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrHistRMUserUniversal::appendNewRecToRst(
			ListPlnrHistRMUserUniversal& rst
			, PlnrHistRMUserUniversal** rec
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVCard
			, const uint ixPlnrVPreset
			, const uint preIxPlnrVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	PlnrHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrHistRMUserUniversal::insertRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblPlnrHistRMUserUniversal::updateRec(
			PlnrHistRMUserUniversal* rec
		) {
};

void TblPlnrHistRMUserUniversal::updateRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblPlnrHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblPlnrHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refPlnrMUser
			, uint ixPlnrVCard
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblPlnrHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	PlnrHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrHistRMUserUniversal
 ******************************************************************************/

MyTblPlnrHistRMUserUniversal::MyTblPlnrHistRMUserUniversal() : TblPlnrHistRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrHistRMUserUniversal::~MyTblPlnrHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrHistRMUserUniversal (refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrHistRMUserUniversal SET refPlnrMUser = ?, unvIxPlnrVMaintable = ?, unvUref = ?, ixPlnrVCard = ?, ixPlnrVPreset = ?, preIxPlnrVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblPlnrHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrHistRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->unvIxPlnrVMaintable = atol((char*) dbrow[2]); else _rec->unvIxPlnrVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixPlnrVCard = atol((char*) dbrow[4]); else _rec->ixPlnrVCard = 0;
		if (dbrow[5]) _rec->ixPlnrVPreset = atol((char*) dbrow[5]); else _rec->ixPlnrVPreset = 0;
		if (dbrow[6]) _rec->preIxPlnrVMaintable = atol((char*) dbrow[6]); else _rec->preIxPlnrVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrHistRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->unvIxPlnrVMaintable = atol((char*) dbrow[2]); else rec->unvIxPlnrVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixPlnrVCard = atol((char*) dbrow[4]); else rec->ixPlnrVCard = 0;
			if (dbrow[5]) rec->ixPlnrVPreset = atol((char*) dbrow[5]); else rec->ixPlnrVPreset = 0;
			if (dbrow[6]) rec->preIxPlnrVMaintable = atol((char*) dbrow[6]); else rec->preIxPlnrVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrHistRMUserUniversal::insertRec(
			PlnrHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixPlnrVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixPlnrVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxPlnrVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrHistRMUserUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrHistRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrHistRMUserUniversal::insertRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrHistRMUserUniversal::updateRec(
			PlnrHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixPlnrVCard,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixPlnrVPreset,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->preIxPlnrVMaintable,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrHistRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrHistRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblPlnrHistRMUserUniversal::updateRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrHistRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrHistRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refPlnrMUser
			, uint ixPlnrVCard
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start FROM TblPlnrHistRMUserUniversal WHERE refPlnrMUser = " + to_string(refPlnrMUser) + " AND ixPlnrVCard = " + to_string(ixPlnrVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblPlnrHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT unvUref FROM TblPlnrHistRMUserUniversal WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrHistRMUserUniversal
 ******************************************************************************/

PgTblPlnrHistRMUserUniversal::PgTblPlnrHistRMUserUniversal() : TblPlnrHistRMUserUniversal(), PgTable() {
};

PgTblPlnrHistRMUserUniversal::~PgTblPlnrHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrHistRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_insertRec", "INSERT INTO TblPlnrHistRMUserUniversal (refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_updateRec", "UPDATE TblPlnrHistRMUserUniversal SET refPlnrMUser = $1, unvIxPlnrVMaintable = $2, unvUref = $3, ixPlnrVCard = $4, ixPlnrVPreset = $5, preIxPlnrVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_removeRecByRef", "DELETE FROM TblPlnrHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_loadRecByRef", "SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start FROM TblPlnrHistRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, start FROM TblPlnrHistRMUserUniversal WHERE refPlnrMUser = $1 AND ixPlnrVCard = $2 ORDER BY start DESC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblPlnrHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrHistRMUserUniversal::loadRec(
			PGresult* res
			, PlnrHistRMUserUniversal** rec
		) {
	char* ptr;

	PlnrHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvcard"),
			PQfnumber(res, "ixplnrvpreset"),
			PQfnumber(res, "preixplnrvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxPlnrVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixPlnrVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixPlnrVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxPlnrVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvcard"),
			PQfnumber(res, "ixplnrvpreset"),
			PQfnumber(res, "preixplnrvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new PlnrHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxPlnrVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixPlnrVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixPlnrVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxPlnrVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrHistRMUserUniversal::insertRec(
			PlnrHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVCard = htonl(rec->ixPlnrVCard);
	uint _ixPlnrVPreset = htonl(rec->ixPlnrVPreset);
	uint _preIxPlnrVMaintable = htonl(rec->preIxPlnrVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref,
		(char*) &_ixPlnrVCard,
		(char*) &_ixPlnrVPreset,
		(char*) &_preIxPlnrVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrHistRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrHistRMUserUniversal::insertRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrHistRMUserUniversal::updateRec(
			PlnrHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVCard = htonl(rec->ixPlnrVCard);
	uint _ixPlnrVPreset = htonl(rec->ixPlnrVPreset);
	uint _preIxPlnrVMaintable = htonl(rec->preIxPlnrVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref,
		(char*) &_ixPlnrVCard,
		(char*) &_ixPlnrVPreset,
		(char*) &_preIxPlnrVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrHistRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrHistRMUserUniversal::updateRst(
			ListPlnrHistRMUserUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrHistRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrHistRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refPlnrMUser
			, uint ixPlnrVCard
			, const bool append
			, ListPlnrHistRMUserUniversal& rst
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);
	uint _ixPlnrVCard = htonl(ixPlnrVCard);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_ixPlnrVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblPlnrHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblPlnrHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

