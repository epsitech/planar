/**
  * \file PlnrMUser.cpp
  * database access for table TblPlnrMUser (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMUser.h"

/******************************************************************************
 class PlnrMUser
 ******************************************************************************/

PlnrMUser::PlnrMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refPlnrMUsergroup
			, const ubigint refPlnrMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string Password
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refPlnrMUsergroup = refPlnrMUsergroup;
	this->refPlnrMPerson = refPlnrMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixPlnrVLocale = ixPlnrVLocale;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
	this->Password = Password;
};

bool PlnrMUser::operator==(
			const PlnrMUser& comp
		) {
	return false;
};

bool PlnrMUser::operator!=(
			const PlnrMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMUser
 ******************************************************************************/

ListPlnrMUser::ListPlnrMUser() {
};

ListPlnrMUser::ListPlnrMUser(
			const ListPlnrMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMUser(*(src.nodes[i]));
};

ListPlnrMUser::~ListPlnrMUser() {
	clear();
};

void ListPlnrMUser::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMUser::size() const {
	return(nodes.size());
};

void ListPlnrMUser::append(
			PlnrMUser* rec
		) {
	nodes.push_back(rec);
};

PlnrMUser* ListPlnrMUser::operator[](
			const uint ix
		) {
	PlnrMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMUser& ListPlnrMUser::operator=(
			const ListPlnrMUser& src
		) {
	PlnrMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMUser::operator==(
			const ListPlnrMUser& comp
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

bool ListPlnrMUser::operator!=(
			const ListPlnrMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMUser
 ******************************************************************************/

TblPlnrMUser::TblPlnrMUser() {
};

TblPlnrMUser::~TblPlnrMUser() {
};

bool TblPlnrMUser::loadRecBySQL(
			const string& sqlstr
			, PlnrMUser** rec
		) {
	return false;
};

ubigint TblPlnrMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUser& rst
		) {
	return 0;
};

void TblPlnrMUser::insertRec(
			PlnrMUser* rec
		) {
};

ubigint TblPlnrMUser::insertNewRec(
			PlnrMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refPlnrMUsergroup
			, const ubigint refPlnrMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string Password
		) {
	ubigint retval = 0;
	PlnrMUser* _rec = NULL;

	_rec = new PlnrMUser(0, grp, own, refRUsergroup, refPlnrMUsergroup, refPlnrMPerson, sref, refJState, ixVState, ixPlnrVLocale, ixPlnrVUserlevel, Password);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMUser::appendNewRecToRst(
			ListPlnrMUser& rst
			, PlnrMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refPlnrMUsergroup
			, const ubigint refPlnrMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixPlnrVLocale
			, const uint ixPlnrVUserlevel
			, const string Password
		) {
	ubigint retval = 0;
	PlnrMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refPlnrMUsergroup, refPlnrMPerson, sref, refJState, ixVState, ixPlnrVLocale, ixPlnrVUserlevel, Password);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMUser::insertRst(
			ListPlnrMUser& rst
			, bool transact
		) {
};

void TblPlnrMUser::updateRec(
			PlnrMUser* rec
		) {
};

void TblPlnrMUser::updateRst(
			ListPlnrMUser& rst
			, bool transact
		) {
};

void TblPlnrMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMUser::loadRecByRef(
			ubigint ref
			, PlnrMUser** rec
		) {
	return false;
};

bool TblPlnrMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	return false;
};

bool TblPlnrMUser::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMUser& rst
		) {
	ubigint numload = 0;
	PlnrMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMUser
 ******************************************************************************/

MyTblPlnrMUser::MyTblPlnrMUser() : TblPlnrMUser(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMUser::~MyTblPlnrMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMUser (grp, own, refRUsergroup, refPlnrMUsergroup, refPlnrMPerson, sref, refJState, ixVState, ixPlnrVLocale, ixPlnrVUserlevel, Password) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMUser SET grp = ?, own = ?, refRUsergroup = ?, refPlnrMUsergroup = ?, refPlnrMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixPlnrVLocale = ?, ixPlnrVUserlevel = ?, Password = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMUser WHERE ref = ?", false);
};

bool MyTblPlnrMUser::loadRecBySQL(
			const string& sqlstr
			, PlnrMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMUser / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refPlnrMUsergroup = atoll((char*) dbrow[4]); else _rec->refPlnrMUsergroup = 0;
		if (dbrow[5]) _rec->refPlnrMPerson = atoll((char*) dbrow[5]); else _rec->refPlnrMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixPlnrVLocale = atol((char*) dbrow[9]); else _rec->ixPlnrVLocale = 0;
		if (dbrow[10]) _rec->ixPlnrVUserlevel = atol((char*) dbrow[10]); else _rec->ixPlnrVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMUser / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refPlnrMUsergroup = atoll((char*) dbrow[4]); else rec->refPlnrMUsergroup = 0;
			if (dbrow[5]) rec->refPlnrMPerson = atoll((char*) dbrow[5]); else rec->refPlnrMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixPlnrVLocale = atol((char*) dbrow[9]); else rec->ixPlnrVLocale = 0;
			if (dbrow[10]) rec->ixPlnrVUserlevel = atol((char*) dbrow[10]); else rec->ixPlnrVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMUser::insertRec(
			PlnrMUser* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refPlnrMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refPlnrMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixPlnrVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixPlnrVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUser / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUser / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMUser::insertRst(
			ListPlnrMUser& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMUser::updateRec(
			PlnrMUser* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refPlnrMUsergroup,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refPlnrMPerson,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->ixPlnrVLocale,&(l[8]),&(n[8]),&(e[8])), 
		bindUint(&rec->ixPlnrVUserlevel,&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUser / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUser / stmtUpdateRec)\n");
};

void MyTblPlnrMUser::updateRst(
			ListPlnrMUser& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUser / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUser / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMUser::loadRecByRef(
			ubigint ref
			, PlnrMUser** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", ref);
};

bool MyTblPlnrMUser::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMUser WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMUser
 ******************************************************************************/

PgTblPlnrMUser::PgTblPlnrMUser() : TblPlnrMUser(), PgTable() {
};

PgTblPlnrMUser::~PgTblPlnrMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMUser::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMUser_insertRec", "INSERT INTO TblPlnrMUser (grp, own, refRUsergroup, refPlnrMUsergroup, refPlnrMPerson, sref, refJState, ixVState, ixPlnrVLocale, ixPlnrVUserlevel, Password) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMUser_updateRec", "UPDATE TblPlnrMUser SET grp = $1, own = $2, refRUsergroup = $3, refPlnrMUsergroup = $4, refPlnrMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixPlnrVLocale = $9, ixPlnrVUserlevel = $10, Password = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMUser_removeRecByRef", "DELETE FROM TblPlnrMUser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refPlnrMUsergroup, refPlnrMPerson, sref, refJState, ixVState, ixPlnrVLocale, ixPlnrVUserlevel, Password FROM TblPlnrMUser WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMUser_loadRefBySrfPwd", "SELECT ref FROM TblPlnrMUser WHERE sref = $1 AND Password = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMUser_loadSrfByRef", "SELECT sref FROM TblPlnrMUser WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMUser::loadRec(
			PGresult* res
			, PlnrMUser** rec
		) {
	char* ptr;

	PlnrMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixplnrvlocale"),
			PQfnumber(res, "ixplnrvuserlevel"),
			PQfnumber(res, "password")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refPlnrMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refPlnrMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixPlnrVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixPlnrVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMUser::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixplnrvlocale"),
			PQfnumber(res, "ixplnrvuserlevel"),
			PQfnumber(res, "password")
		};

		while (numread < numrow) {
			rec = new PlnrMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refPlnrMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refPlnrMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixPlnrVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixPlnrVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUser / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMUser::loadRecBySQL(
			const string& sqlstr
			, PlnrMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMUser::insertRec(
			PlnrMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixPlnrVLocale = htonl(rec->ixPlnrVLocale);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refPlnrMUsergroup,
		(char*) &_refPlnrMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixPlnrVLocale,
		(char*) &_ixPlnrVUserlevel,
		rec->Password.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMUser_insertRec", 11, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUser_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMUser::insertRst(
			ListPlnrMUser& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMUser::updateRec(
			PlnrMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixPlnrVLocale = htonl(rec->ixPlnrVLocale);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refPlnrMUsergroup,
		(char*) &_refPlnrMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixPlnrVLocale,
		(char*) &_ixPlnrVUserlevel,
		rec->Password.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMUser_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUser_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMUser::updateRst(
			ListPlnrMUser& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMUser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUser_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMUser::loadRecByRef(
			ubigint ref
			, PlnrMUser** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMUser::loadRefBySrfPwd(
			string sref
			, string Password
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadUbigintByStmt("TblPlnrMUser_loadRefBySrfPwd", 2, vals, l, f, ref);
};

bool PgTblPlnrMUser::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblPlnrMUser_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

