/**
  * \file PlnrMDesign.cpp
  * database access for table TblPlnrMDesign (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMDesign.h"

/******************************************************************************
 class PlnrMDesign
 ******************************************************************************/

PlnrMDesign::PlnrMDesign(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const uint ixVDim
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refPlnrMProject
			, const uint ixWModtype
			, const ubigint modRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixVBasetype = ixVBasetype;
	this->ixVDim = ixVDim;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refPlnrMProject = refPlnrMProject;
	this->ixWModtype = ixWModtype;
	this->modRefPlnrMDesign = modRefPlnrMDesign;
	this->drvRefPlnrMDesign = drvRefPlnrMDesign;
	this->Title = Title;
	this->Major = Major;
	this->Sub = Sub;
	this->Comment = Comment;
};

bool PlnrMDesign::operator==(
			const PlnrMDesign& comp
		) {
	return false;
};

bool PlnrMDesign::operator!=(
			const PlnrMDesign& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMDesign
 ******************************************************************************/

ListPlnrMDesign::ListPlnrMDesign() {
};

ListPlnrMDesign::ListPlnrMDesign(
			const ListPlnrMDesign& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMDesign(*(src.nodes[i]));
};

ListPlnrMDesign::~ListPlnrMDesign() {
	clear();
};

void ListPlnrMDesign::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMDesign::size() const {
	return(nodes.size());
};

void ListPlnrMDesign::append(
			PlnrMDesign* rec
		) {
	nodes.push_back(rec);
};

PlnrMDesign* ListPlnrMDesign::operator[](
			const uint ix
		) {
	PlnrMDesign* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMDesign& ListPlnrMDesign::operator=(
			const ListPlnrMDesign& src
		) {
	PlnrMDesign* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMDesign(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMDesign::operator==(
			const ListPlnrMDesign& comp
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

bool ListPlnrMDesign::operator!=(
			const ListPlnrMDesign& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMDesign
 ******************************************************************************/

TblPlnrMDesign::TblPlnrMDesign() {
};

TblPlnrMDesign::~TblPlnrMDesign() {
};

bool TblPlnrMDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrMDesign** rec
		) {
	return false;
};

ubigint TblPlnrMDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDesign& rst
		) {
	return 0;
};

void TblPlnrMDesign::insertRec(
			PlnrMDesign* rec
		) {
};

ubigint TblPlnrMDesign::insertNewRec(
			PlnrMDesign** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const uint ixVDim
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refPlnrMProject
			, const uint ixWModtype
			, const ubigint modRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMDesign* _rec = NULL;

	_rec = new PlnrMDesign(0, grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMDesign::appendNewRecToRst(
			ListPlnrMDesign& rst
			, PlnrMDesign** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const uint ixVDim
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint refPlnrMProject
			, const uint ixWModtype
			, const ubigint modRefPlnrMDesign
			, const ubigint drvRefPlnrMDesign
			, const string Title
			, const usmallint Major
			, const usmallint Sub
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMDesign* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMDesign::insertRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
};

void TblPlnrMDesign::updateRec(
			PlnrMDesign* rec
		) {
};

void TblPlnrMDesign::updateRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
};

void TblPlnrMDesign::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMDesign::loadRecByRef(
			ubigint ref
			, PlnrMDesign** rec
		) {
	return false;
};

bool TblPlnrMDesign::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, PlnrMDesign** rec
		) {
	return false;
};

ubigint TblPlnrMDesign::loadRefsByMod(
			ubigint modRefPlnrMDesign
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblPlnrMDesign::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMDesign::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMDesign& rst
		) {
	ubigint numload = 0;
	PlnrMDesign* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMDesign
 ******************************************************************************/

MyTblPlnrMDesign::MyTblPlnrMDesign() : TblPlnrMDesign(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMDesign::~MyTblPlnrMDesign() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMDesign::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMDesign (grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMDesign SET grp = ?, own = ?, ixVBasetype = ?, ixVDim = ?, refIxVTbl = ?, refUref = ?, refPlnrMProject = ?, ixWModtype = ?, modRefPlnrMDesign = ?, drvRefPlnrMDesign = ?, Title = ?, Major = ?, Sub = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMDesign WHERE ref = ?", false);
};

bool MyTblPlnrMDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrMDesign** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMDesign* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDesign / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMDesign();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->ixVDim = atol((char*) dbrow[4]); else _rec->ixVDim = 0;
		if (dbrow[5]) _rec->refIxVTbl = atol((char*) dbrow[5]); else _rec->refIxVTbl = 0;
		if (dbrow[6]) _rec->refUref = atoll((char*) dbrow[6]); else _rec->refUref = 0;
		if (dbrow[7]) _rec->refPlnrMProject = atoll((char*) dbrow[7]); else _rec->refPlnrMProject = 0;
		if (dbrow[8]) _rec->ixWModtype = atol((char*) dbrow[8]); else _rec->ixWModtype = 0;
		if (dbrow[9]) _rec->modRefPlnrMDesign = atoll((char*) dbrow[9]); else _rec->modRefPlnrMDesign = 0;
		if (dbrow[10]) _rec->drvRefPlnrMDesign = atoll((char*) dbrow[10]); else _rec->drvRefPlnrMDesign = 0;
		if (dbrow[11]) _rec->Title.assign(dbrow[11], dblengths[11]); else _rec->Title = "";
		if (dbrow[12]) _rec->Major = atoi((char*) dbrow[12]); else _rec->Major = 0;
		if (dbrow[13]) _rec->Sub = atoi((char*) dbrow[13]); else _rec->Sub = 0;
		if (dbrow[14]) _rec->Comment.assign(dbrow[14], dblengths[14]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDesign& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMDesign* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDesign / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMDesign();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->ixVDim = atol((char*) dbrow[4]); else rec->ixVDim = 0;
			if (dbrow[5]) rec->refIxVTbl = atol((char*) dbrow[5]); else rec->refIxVTbl = 0;
			if (dbrow[6]) rec->refUref = atoll((char*) dbrow[6]); else rec->refUref = 0;
			if (dbrow[7]) rec->refPlnrMProject = atoll((char*) dbrow[7]); else rec->refPlnrMProject = 0;
			if (dbrow[8]) rec->ixWModtype = atol((char*) dbrow[8]); else rec->ixWModtype = 0;
			if (dbrow[9]) rec->modRefPlnrMDesign = atoll((char*) dbrow[9]); else rec->modRefPlnrMDesign = 0;
			if (dbrow[10]) rec->drvRefPlnrMDesign = atoll((char*) dbrow[10]); else rec->drvRefPlnrMDesign = 0;
			if (dbrow[11]) rec->Title.assign(dbrow[11], dblengths[11]); else rec->Title = "";
			if (dbrow[12]) rec->Major = atoi((char*) dbrow[12]); else rec->Major = 0;
			if (dbrow[13]) rec->Sub = atoi((char*) dbrow[13]); else rec->Sub = 0;
			if (dbrow[14]) rec->Comment.assign(dbrow[14], dblengths[14]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMDesign::insertRec(
			PlnrMDesign* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[10] = rec->Title.length();
	l[13] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDim,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refPlnrMProject,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixWModtype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->modRefPlnrMDesign,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->drvRefPlnrMDesign,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Title.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->Major,&(l[11]),&(n[11]),&(e[11])),
		bindUsmallint(&rec->Sub,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDesign / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDesign / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMDesign::insertRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMDesign::updateRec(
			PlnrMDesign* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[10] = rec->Title.length();
	l[13] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixVDim,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refPlnrMProject,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixWModtype,&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->modRefPlnrMDesign,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->drvRefPlnrMDesign,&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUsmallint(&rec->Major,&(l[11]),&(n[11]),&(e[11])), 
		bindUsmallint(&rec->Sub,&(l[12]),&(n[12]),&(e[12])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[13]),&(n[13]),&(e[13])), 
		bindUbigint(&rec->ref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDesign / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDesign / stmtUpdateRec)\n");
};

void MyTblPlnrMDesign::updateRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMDesign::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDesign / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDesign / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMDesign::loadRecByRef(
			ubigint ref
			, PlnrMDesign** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMDesign WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMDesign::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, PlnrMDesign** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment FROM TblPlnrMDesign WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", rec);
};

ubigint MyTblPlnrMDesign::loadRefsByMod(
			ubigint modRefPlnrMDesign
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMDesign WHERE modRefPlnrMDesign = " + to_string(modRefPlnrMDesign) + "", append, refs);
};

bool MyTblPlnrMDesign::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrMDesign WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMDesign
 ******************************************************************************/

PgTblPlnrMDesign::PgTblPlnrMDesign() : TblPlnrMDesign(), PgTable() {
};

PgTblPlnrMDesign::~PgTblPlnrMDesign() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMDesign::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMDesign_insertRec", "INSERT INTO TblPlnrMDesign (grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING ref", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDesign_updateRec", "UPDATE TblPlnrMDesign SET grp = $1, own = $2, ixVBasetype = $3, ixVDim = $4, refIxVTbl = $5, refUref = $6, refPlnrMProject = $7, ixWModtype = $8, modRefPlnrMDesign = $9, drvRefPlnrMDesign = $10, Title = $11, Major = $12, Sub = $13, Comment = $14 WHERE ref = $15", 15, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDesign_removeRecByRef", "DELETE FROM TblPlnrMDesign WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMDesign_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment FROM TblPlnrMDesign WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMDesign_loadRecByRetReu", "SELECT ref, grp, own, ixVBasetype, ixVDim, refIxVTbl, refUref, refPlnrMProject, ixWModtype, modRefPlnrMDesign, drvRefPlnrMDesign, Title, Major, Sub, Comment FROM TblPlnrMDesign WHERE refIxVTbl = $1 AND refUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDesign_loadRefsByMod", "SELECT ref FROM TblPlnrMDesign WHERE modRefPlnrMDesign = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDesign_loadTitByRef", "SELECT Title FROM TblPlnrMDesign WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMDesign::loadRec(
			PGresult* res
			, PlnrMDesign** rec
		) {
	char* ptr;

	PlnrMDesign* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMDesign();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixwmodtype"),
			PQfnumber(res, "modrefplnrmdesign"),
			PQfnumber(res, "drvrefplnrmdesign"),
			PQfnumber(res, "title"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVDim = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixWModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->modRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->drvRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[14]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMDesign::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMDesign& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMDesign* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixwmodtype"),
			PQfnumber(res, "modrefplnrmdesign"),
			PQfnumber(res, "drvrefplnrmdesign"),
			PQfnumber(res, "title"),
			PQfnumber(res, "major"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMDesign();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVDim = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixWModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->modRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->drvRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[14]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMDesign::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMDesign** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDesign / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMDesign::loadRecBySQL(
			const string& sqlstr
			, PlnrMDesign** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMDesign::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDesign& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMDesign::insertRec(
			PlnrMDesign* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixVDim = htonl(rec->ixVDim);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixWModtype = htonl(rec->ixWModtype);
	ubigint _modRefPlnrMDesign = htonl64(rec->modRefPlnrMDesign);
	ubigint _drvRefPlnrMDesign = htonl64(rec->drvRefPlnrMDesign);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_ixVDim,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refPlnrMProject,
		(char*) &_ixWModtype,
		(char*) &_modRefPlnrMDesign,
		(char*) &_drvRefPlnrMDesign,
		rec->Title.c_str(),
		(char*) &_Major,
		(char*) &_Sub,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMDesign_insertRec", 14, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDesign_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMDesign::insertRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMDesign::updateRec(
			PlnrMDesign* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _ixVDim = htonl(rec->ixVDim);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixWModtype = htonl(rec->ixWModtype);
	ubigint _modRefPlnrMDesign = htonl64(rec->modRefPlnrMDesign);
	ubigint _drvRefPlnrMDesign = htonl64(rec->drvRefPlnrMDesign);
	usmallint _Major = htons(rec->Major);
	usmallint _Sub = htons(rec->Sub);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_ixVDim,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refPlnrMProject,
		(char*) &_ixWModtype,
		(char*) &_modRefPlnrMDesign,
		(char*) &_drvRefPlnrMDesign,
		rec->Title.c_str(),
		(char*) &_Major,
		(char*) &_Sub,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMDesign_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDesign_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMDesign::updateRst(
			ListPlnrMDesign& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMDesign::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMDesign_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDesign_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMDesign::loadRecByRef(
			ubigint ref
			, PlnrMDesign** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMDesign_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMDesign::loadRecByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, PlnrMDesign** rec
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrMDesign_loadRecByRetReu", 2, vals, l, f, rec);
};

ubigint PgTblPlnrMDesign::loadRefsByMod(
			ubigint modRefPlnrMDesign
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _modRefPlnrMDesign = htonl64(modRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_modRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrMDesign_loadRefsByMod", 1, vals, l, f, append, refs);
};

bool PgTblPlnrMDesign::loadTitByRef(
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

	return loadStringByStmt("TblPlnrMDesign_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

