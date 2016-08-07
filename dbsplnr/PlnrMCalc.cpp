/**
  * \file PlnrMCalc.cpp
  * database access for table TblPlnrMCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMCalc.h"

/******************************************************************************
 class PlnrMCalc
 ******************************************************************************/

PlnrMCalc::PlnrMCalc(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrMProject
			, const uint ixVDim
			, const ubigint tplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string Title
			, const uint start
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refPlnrMProject = refPlnrMProject;
	this->ixVDim = ixVDim;
	this->tplRefPlnrMCalc = tplRefPlnrMCalc;
	this->supRefPlnrMCalc = supRefPlnrMCalc;
	this->refPlnrMDesign = refPlnrMDesign;
	this->Title = Title;
	this->start = start;
	this->Comment = Comment;
};

bool PlnrMCalc::operator==(
			const PlnrMCalc& comp
		) {
	return false;
};

bool PlnrMCalc::operator!=(
			const PlnrMCalc& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMCalc
 ******************************************************************************/

ListPlnrMCalc::ListPlnrMCalc() {
};

ListPlnrMCalc::ListPlnrMCalc(
			const ListPlnrMCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMCalc(*(src.nodes[i]));
};

ListPlnrMCalc::~ListPlnrMCalc() {
	clear();
};

void ListPlnrMCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMCalc::size() const {
	return(nodes.size());
};

void ListPlnrMCalc::append(
			PlnrMCalc* rec
		) {
	nodes.push_back(rec);
};

PlnrMCalc* ListPlnrMCalc::operator[](
			const uint ix
		) {
	PlnrMCalc* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMCalc& ListPlnrMCalc::operator=(
			const ListPlnrMCalc& src
		) {
	PlnrMCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMCalc::operator==(
			const ListPlnrMCalc& comp
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

bool ListPlnrMCalc::operator!=(
			const ListPlnrMCalc& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMCalc
 ******************************************************************************/

TblPlnrMCalc::TblPlnrMCalc() {
};

TblPlnrMCalc::~TblPlnrMCalc() {
};

bool TblPlnrMCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalc** rec
		) {
	return false;
};

ubigint TblPlnrMCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalc& rst
		) {
	return 0;
};

void TblPlnrMCalc::insertRec(
			PlnrMCalc* rec
		) {
};

ubigint TblPlnrMCalc::insertNewRec(
			PlnrMCalc** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrMProject
			, const uint ixVDim
			, const ubigint tplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string Title
			, const uint start
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMCalc* _rec = NULL;

	_rec = new PlnrMCalc(0, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMCalc::appendNewRecToRst(
			ListPlnrMCalc& rst
			, PlnrMCalc** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrMProject
			, const uint ixVDim
			, const ubigint tplRefPlnrMCalc
			, const ubigint supRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string Title
			, const uint start
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMCalc* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMCalc::insertRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
};

void TblPlnrMCalc::updateRec(
			PlnrMCalc* rec
		) {
};

void TblPlnrMCalc::updateRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
};

void TblPlnrMCalc::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMCalc::loadRecByRef(
			ubigint ref
			, PlnrMCalc** rec
		) {
	return false;
};

bool TblPlnrMCalc::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblPlnrMCalc::loadRecByTplTit(
			ubigint tplRefPlnrMCalc
			, string Title
			, PlnrMCalc** rec
		) {
	return false;
};

ubigint TblPlnrMCalc::loadRefsBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMCalc::loadRstBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, ListPlnrMCalc& rst
		) {
	return 0;
};

bool TblPlnrMCalc::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return false;
};

bool TblPlnrMCalc::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMCalc::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMCalc& rst
		) {
	ubigint numload = 0;
	PlnrMCalc* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP loadHrefsup --- BEGIN
ubigint TblPlnrMCalc::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrefsup --- END
// IP loadHrefsdown --- BEGIN
ubigint TblPlnrMCalc::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

// IP loadHrefsdown --- END
// IP loadHrstup --- BEGIN
ubigint TblPlnrMCalc::loadHrstup(
			ubigint ref
			, ListPlnrMCalc& rst
		) {
	PlnrMCalc* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefPlnrMCalc;
		if (ref == 0) break;
	};

	return retval;
};

// IP loadHrstup --- END
// IP loadHrstdown --- BEGIN
ubigint TblPlnrMCalc::loadHrstdown(
			ubigint ref
			, const bool append
			, ListPlnrMCalc& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	PlnrMCalc* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};
// IP loadHrstdown --- END

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMCalc
 ******************************************************************************/

MyTblPlnrMCalc::MyTblPlnrMCalc() : TblPlnrMCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMCalc::~MyTblPlnrMCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMCalc (grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMCalc SET grp = ?, own = ?, refPlnrMProject = ?, ixVDim = ?, tplRefPlnrMCalc = ?, supRefPlnrMCalc = ?, refPlnrMDesign = ?, Title = ?, start = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMCalc WHERE ref = ?", false);
};

bool MyTblPlnrMCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMCalc();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refPlnrMProject = atoll((char*) dbrow[3]); else _rec->refPlnrMProject = 0;
		if (dbrow[4]) _rec->ixVDim = atol((char*) dbrow[4]); else _rec->ixVDim = 0;
		if (dbrow[5]) _rec->tplRefPlnrMCalc = atoll((char*) dbrow[5]); else _rec->tplRefPlnrMCalc = 0;
		if (dbrow[6]) _rec->supRefPlnrMCalc = atoll((char*) dbrow[6]); else _rec->supRefPlnrMCalc = 0;
		if (dbrow[7]) _rec->refPlnrMDesign = atoll((char*) dbrow[7]); else _rec->refPlnrMDesign = 0;
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->start = atol((char*) dbrow[9]); else _rec->start = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMCalc();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refPlnrMProject = atoll((char*) dbrow[3]); else rec->refPlnrMProject = 0;
			if (dbrow[4]) rec->ixVDim = atol((char*) dbrow[4]); else rec->ixVDim = 0;
			if (dbrow[5]) rec->tplRefPlnrMCalc = atoll((char*) dbrow[5]); else rec->tplRefPlnrMCalc = 0;
			if (dbrow[6]) rec->supRefPlnrMCalc = atoll((char*) dbrow[6]); else rec->supRefPlnrMCalc = 0;
			if (dbrow[7]) rec->refPlnrMDesign = atoll((char*) dbrow[7]); else rec->refPlnrMDesign = 0;
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->start = atol((char*) dbrow[9]); else rec->start = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMCalc::insertRec(
			PlnrMCalc* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[7] = rec->Title.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMProject,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDim,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->tplRefPlnrMCalc,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefPlnrMCalc,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refPlnrMDesign,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalc / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalc / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMCalc::insertRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMCalc::updateRec(
			PlnrMCalc* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[7] = rec->Title.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMProject,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixVDim,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->tplRefPlnrMCalc,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->supRefPlnrMCalc,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->start,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalc / stmtUpdateRec)\n");
};

void MyTblPlnrMCalc::updateRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMCalc::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalc / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalc / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMCalc::loadRecByRef(
			ubigint ref
			, PlnrMCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMCalc WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMCalc::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMCalc WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblPlnrMCalc::loadRecByTplTit(
			ubigint tplRefPlnrMCalc
			, string Title
			, PlnrMCalc** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment FROM TblPlnrMCalc WHERE tplRefPlnrMCalc = " + to_string(tplRefPlnrMCalc) + " AND Title = '" + Title + "'", rec);
};

ubigint MyTblPlnrMCalc::loadRefsBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMCalc WHERE supRefPlnrMCalc = " + to_string(supRefPlnrMCalc) + "", append, refs);
};

ubigint MyTblPlnrMCalc::loadRstBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, ListPlnrMCalc& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment FROM TblPlnrMCalc WHERE supRefPlnrMCalc = " + to_string(supRefPlnrMCalc) + "", append, rst);
};

bool MyTblPlnrMCalc::loadSupByRef(
			ubigint ref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT supRefPlnrMCalc FROM TblPlnrMCalc WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblPlnrMCalc::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrMCalc WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMCalc
 ******************************************************************************/

PgTblPlnrMCalc::PgTblPlnrMCalc() : TblPlnrMCalc(), PgTable() {
};

PgTblPlnrMCalc::~PgTblPlnrMCalc() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMCalc_insertRec", "INSERT INTO TblPlnrMCalc (grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_updateRec", "UPDATE TblPlnrMCalc SET grp = $1, own = $2, refPlnrMProject = $3, ixVDim = $4, tplRefPlnrMCalc = $5, supRefPlnrMCalc = $6, refPlnrMDesign = $7, Title = $8, start = $9, Comment = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_removeRecByRef", "DELETE FROM TblPlnrMCalc WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMCalc_loadRecByRef", "SELECT ref, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment FROM TblPlnrMCalc WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMCalc_confirmByRef", "SELECT ref FROM TblPlnrMCalc WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_loadRecByTplTit", "SELECT ref, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment FROM TblPlnrMCalc WHERE tplRefPlnrMCalc = $1 AND Title = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_loadRefsBySup", "SELECT ref FROM TblPlnrMCalc WHERE supRefPlnrMCalc = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_loadRstBySup", "SELECT ref, grp, own, refPlnrMProject, ixVDim, tplRefPlnrMCalc, supRefPlnrMCalc, refPlnrMDesign, Title, start, Comment FROM TblPlnrMCalc WHERE supRefPlnrMCalc = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_loadSupByRef", "SELECT supRefPlnrMCalc FROM TblPlnrMCalc WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalc_loadTitByRef", "SELECT Title FROM TblPlnrMCalc WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMCalc::loadRec(
			PGresult* res
			, PlnrMCalc** rec
		) {
	char* ptr;

	PlnrMCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMCalc();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "tplrefplnrmcalc"),
			PQfnumber(res, "suprefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "title"),
			PQfnumber(res, "start"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVDim = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->tplRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMCalc* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "tplrefplnrmcalc"),
			PQfnumber(res, "suprefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "title"),
			PQfnumber(res, "start"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMCalc();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVDim = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->tplRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMCalc::insertRec(
			PlnrMCalc* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _tplRefPlnrMCalc = htonl64(rec->tplRefPlnrMCalc);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refPlnrMProject,
		(char*) &_ixVDim,
		(char*) &_tplRefPlnrMCalc,
		(char*) &_supRefPlnrMCalc,
		(char*) &_refPlnrMDesign,
		rec->Title.c_str(),
		(char*) &_start,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMCalc_insertRec", 10, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMCalc::insertRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMCalc::updateRec(
			PlnrMCalc* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _tplRefPlnrMCalc = htonl64(rec->tplRefPlnrMCalc);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refPlnrMProject,
		(char*) &_ixVDim,
		(char*) &_tplRefPlnrMCalc,
		(char*) &_supRefPlnrMCalc,
		(char*) &_refPlnrMDesign,
		rec->Title.c_str(),
		(char*) &_start,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMCalc_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMCalc::updateRst(
			ListPlnrMCalc& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMCalc::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMCalc_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalc_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMCalc::loadRecByRef(
			ubigint ref
			, PlnrMCalc** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMCalc_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMCalc::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadUbigintByStmt("TblPlnrMCalc_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblPlnrMCalc::loadRecByTplTit(
			ubigint tplRefPlnrMCalc
			, string Title
			, PlnrMCalc** rec
		) {
	ubigint _tplRefPlnrMCalc = htonl64(tplRefPlnrMCalc);

	const char* vals[] = {
		(char*) &_tplRefPlnrMCalc,
		Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblPlnrMCalc_loadRecByTplTit", 2, vals, l, f, rec);
};

ubigint PgTblPlnrMCalc::loadRefsBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefPlnrMCalc = htonl64(supRefPlnrMCalc);

	const char* vals[] = {
		(char*) &_supRefPlnrMCalc
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrMCalc_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrMCalc::loadRstBySup(
			ubigint supRefPlnrMCalc
			, const bool append
			, ListPlnrMCalc& rst
		) {
	ubigint _supRefPlnrMCalc = htonl64(supRefPlnrMCalc);

	const char* vals[] = {
		(char*) &_supRefPlnrMCalc
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMCalc_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblPlnrMCalc::loadSupByRef(
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

	return loadUbigintByStmt("TblPlnrMCalc_loadSupByRef", 1, vals, l, f, val);
};

bool PgTblPlnrMCalc::loadTitByRef(
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

	return loadStringByStmt("TblPlnrMCalc_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

