/**
  * \file PlnrMTapeout.cpp
  * database access for table TblPlnrMTapeout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMTapeout.h"

/******************************************************************************
 class PlnrMTapeout
 ******************************************************************************/

PlnrMTapeout::PlnrMTapeout(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const bool Hflip
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixVBasetype = ixVBasetype;
	this->Title = Title;
	this->Major = Major;
	this->Sub = Sub;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Hflip = Hflip;
	this->Comment = Comment;
};

bool PlnrMTapeout::operator==(
			const PlnrMTapeout& comp
		) {
	return false;
};

bool PlnrMTapeout::operator!=(
			const PlnrMTapeout& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMTapeout
 ******************************************************************************/

ListPlnrMTapeout::ListPlnrMTapeout() {
};

ListPlnrMTapeout::ListPlnrMTapeout(
			const ListPlnrMTapeout& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMTapeout(*(src.nodes[i]));
};

ListPlnrMTapeout::~ListPlnrMTapeout() {
	clear();
};

void ListPlnrMTapeout::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMTapeout::size() const {
	return(nodes.size());
};

void ListPlnrMTapeout::append(
			PlnrMTapeout* rec
		) {
	nodes.push_back(rec);
};

PlnrMTapeout* ListPlnrMTapeout::operator[](
			const uint ix
		) {
	PlnrMTapeout* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMTapeout& ListPlnrMTapeout::operator=(
			const ListPlnrMTapeout& src
		) {
	PlnrMTapeout* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMTapeout(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMTapeout::operator==(
			const ListPlnrMTapeout& comp
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

bool ListPlnrMTapeout::operator!=(
			const ListPlnrMTapeout& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMTapeout
 ******************************************************************************/

TblPlnrMTapeout::TblPlnrMTapeout() {
};

TblPlnrMTapeout::~TblPlnrMTapeout() {
};

bool TblPlnrMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrMTapeout** rec
		) {
	return false;
};

ubigint TblPlnrMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMTapeout& rst
		) {
	return 0;
};

void TblPlnrMTapeout::insertRec(
			PlnrMTapeout* rec
		) {
};

ubigint TblPlnrMTapeout::insertNewRec(
			PlnrMTapeout** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const bool Hflip
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMTapeout* _rec = NULL;

	_rec = new PlnrMTapeout(0, grp, own, ixVBasetype, Title, Major, Sub, refJState, ixVState, Hflip, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMTapeout::appendNewRecToRst(
			ListPlnrMTapeout& rst
			, PlnrMTapeout** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const bool Hflip
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMTapeout* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, Title, Major, Sub, refJState, ixVState, Hflip, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMTapeout::insertRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
};

void TblPlnrMTapeout::updateRec(
			PlnrMTapeout* rec
		) {
};

void TblPlnrMTapeout::updateRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
};

void TblPlnrMTapeout::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMTapeout::loadRecByRef(
			ubigint ref
			, PlnrMTapeout** rec
		) {
	return false;
};

bool TblPlnrMTapeout::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMTapeout::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMTapeout& rst
		) {
	ubigint numload = 0;
	PlnrMTapeout* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMTapeout
 ******************************************************************************/

MyTblPlnrMTapeout::MyTblPlnrMTapeout() : TblPlnrMTapeout(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMTapeout::~MyTblPlnrMTapeout() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMTapeout::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMTapeout (grp, own, ixVBasetype, Title, Major, Sub, refJState, ixVState, Hflip, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMTapeout SET grp = ?, own = ?, ixVBasetype = ?, Title = ?, Major = ?, Sub = ?, refJState = ?, ixVState = ?, Hflip = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMTapeout WHERE ref = ?", false);
};

bool MyTblPlnrMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrMTapeout** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMTapeout* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMTapeout / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMTapeout();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->Major = atoi((char*) dbrow[5]); else _rec->Major = 0;
		if (dbrow[6]) _rec->Sub = atoi((char*) dbrow[6]); else _rec->Sub = 0;
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->Hflip = (atoi((char*) dbrow[9]) != 0); else _rec->Hflip = false;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMTapeout& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMTapeout* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMTapeout / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMTapeout();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->Major = atoi((char*) dbrow[5]); else rec->Major = 0;
			if (dbrow[6]) rec->Sub = atoi((char*) dbrow[6]); else rec->Sub = 0;
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->Hflip = (atoi((char*) dbrow[9]) != 0); else rec->Hflip = false;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMTapeout::insertRec(
			PlnrMTapeout* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Title.length();
	tinyint Hflip = rec->Hflip;
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUsmallint(&rec->Major,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Sub,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Hflip,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMTapeout / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMTapeout / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMTapeout::insertRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMTapeout::updateRec(
			PlnrMTapeout* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->Title.length();
	tinyint Hflip = rec->Hflip;
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUsmallint(&rec->Major,&(l[4]),&(n[4]),&(e[4])), 
		bindUsmallint(&rec->Sub,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])), 
		bindTinyint(&Hflip,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMTapeout / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMTapeout / stmtUpdateRec)\n");
};

void MyTblPlnrMTapeout::updateRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMTapeout::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMTapeout / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMTapeout / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMTapeout::loadRecByRef(
			ubigint ref
			, PlnrMTapeout** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMTapeout WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMTapeout::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrMTapeout WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMTapeout
 ******************************************************************************/

PgTblPlnrMTapeout::PgTblPlnrMTapeout() : TblPlnrMTapeout(), PgTable() {
};

PgTblPlnrMTapeout::~PgTblPlnrMTapeout() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMTapeout::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMTapeout_insertRec", "INSERT INTO TblPlnrMTapeout (grp, own, ixVBasetype, Title, Major, Sub, refJState, ixVState, Hflip, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMTapeout_updateRec", "UPDATE TblPlnrMTapeout SET grp = $1, own = $2, ixVBasetype = $3, Title = $4, Major = $5, Sub = $6, refJState = $7, ixVState = $8, Hflip = $9, Comment = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMTapeout_removeRecByRef", "DELETE FROM TblPlnrMTapeout WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMTapeout_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, Title, Major, Sub, refJState, ixVState, Hflip, Comment FROM TblPlnrMTapeout WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMTapeout_loadTitByRef", "SELECT Title FROM TblPlnrMTapeout WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMTapeout::loadRec(
			PGresult* res
			, PlnrMTapeout** rec
		) {
	char* ptr;

	PlnrMTapeout* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMTapeout();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "title"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "hflip"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Hflip = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMTapeout::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMTapeout& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMTapeout* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "title"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "hflip"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMTapeout();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Hflip = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMTapeout::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMTapeout** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMTapeout / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrMTapeout** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMTapeout& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMTapeout::insertRec(
			PlnrMTapeout* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	smallint _Hflip = htons((smallint) rec->Hflip);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		rec->Title.c_str(),
		(char*) &_Major,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_Hflip,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMTapeout_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMTapeout_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMTapeout::insertRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMTapeout::updateRec(
			PlnrMTapeout* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	smallint _Hflip = htons((smallint) rec->Hflip);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		rec->Title.c_str(),
		(char*) &_Major,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_Hflip,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMTapeout_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMTapeout_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMTapeout::updateRst(
			ListPlnrMTapeout& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMTapeout::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMTapeout_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMTapeout_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMTapeout::loadRecByRef(
			ubigint ref
			, PlnrMTapeout** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMTapeout_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMTapeout::loadTitByRef(
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

	return loadStringByStmt("TblPlnrMTapeout_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

