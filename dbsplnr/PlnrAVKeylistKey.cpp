/**
  * \file PlnrAVKeylistKey.cpp
  * database access for table TblPlnrAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAVKeylistKey.h"

/******************************************************************************
 class PlnrAVKeylistKey
 ******************************************************************************/

PlnrAVKeylistKey::PlnrAVKeylistKey(
			const ubigint ref
			, const uint klsIxPlnrVKeylist
			, const uint klsNum
			, const uint x1IxPlnrVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxPlnrVKeylist = klsIxPlnrVKeylist;
	this->klsNum = klsNum;
	this->x1IxPlnrVMaintable = x1IxPlnrVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrAVKeylistKey::operator==(
			const PlnrAVKeylistKey& comp
		) {
	return false;
};

bool PlnrAVKeylistKey::operator!=(
			const PlnrAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAVKeylistKey
 ******************************************************************************/

ListPlnrAVKeylistKey::ListPlnrAVKeylistKey() {
};

ListPlnrAVKeylistKey::ListPlnrAVKeylistKey(
			const ListPlnrAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAVKeylistKey(*(src.nodes[i]));
};

ListPlnrAVKeylistKey::~ListPlnrAVKeylistKey() {
	clear();
};

void ListPlnrAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAVKeylistKey::size() const {
	return(nodes.size());
};

void ListPlnrAVKeylistKey::append(
			PlnrAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

PlnrAVKeylistKey* ListPlnrAVKeylistKey::operator[](
			const uint ix
		) {
	PlnrAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAVKeylistKey& ListPlnrAVKeylistKey::operator=(
			const ListPlnrAVKeylistKey& src
		) {
	PlnrAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAVKeylistKey::operator==(
			const ListPlnrAVKeylistKey& comp
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

bool ListPlnrAVKeylistKey::operator!=(
			const ListPlnrAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAVKeylistKey
 ******************************************************************************/

TblPlnrAVKeylistKey::TblPlnrAVKeylistKey() {
};

TblPlnrAVKeylistKey::~TblPlnrAVKeylistKey() {
};

bool TblPlnrAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrAVKeylistKey** rec
		) {
	return false;
};

ubigint TblPlnrAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	return 0;
};

void TblPlnrAVKeylistKey::insertRec(
			PlnrAVKeylistKey* rec
		) {
};

ubigint TblPlnrAVKeylistKey::insertNewRec(
			PlnrAVKeylistKey** rec
			, const uint klsIxPlnrVKeylist
			, const uint klsNum
			, const uint x1IxPlnrVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrAVKeylistKey* _rec = NULL;

	_rec = new PlnrAVKeylistKey(0, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAVKeylistKey::appendNewRecToRst(
			ListPlnrAVKeylistKey& rst
			, PlnrAVKeylistKey** rec
			, const uint klsIxPlnrVKeylist
			, const uint klsNum
			, const uint x1IxPlnrVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAVKeylistKey::insertRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
};

void TblPlnrAVKeylistKey::updateRec(
			PlnrAVKeylistKey* rec
		) {
};

void TblPlnrAVKeylistKey::updateRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
};

void TblPlnrAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrAVKeylistKey** rec
		) {
	return false;
};

bool TblPlnrAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblPlnrAVKeylistKey::loadRefByKlsSrf(
			uint klsIxPlnrVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblPlnrAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrAVKeylistKey::loadRstByKls(
			uint klsIxPlnrVKeylist
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblPlnrAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	return 0;
};

bool TblPlnrAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	ubigint numload = 0;
	PlnrAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAVKeylistKey
 ******************************************************************************/

MyTblPlnrAVKeylistKey::MyTblPlnrAVKeylistKey() : TblPlnrAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAVKeylistKey::~MyTblPlnrAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAVKeylistKey (klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAVKeylistKey SET klsIxPlnrVKeylist = ?, klsNum = ?, x1IxPlnrVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAVKeylistKey WHERE ref = ?", false);
};

bool MyTblPlnrAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxPlnrVKeylist = atol((char*) dbrow[1]); else _rec->klsIxPlnrVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxPlnrVMaintable = atol((char*) dbrow[3]); else _rec->x1IxPlnrVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxPlnrVKeylist = atol((char*) dbrow[1]); else rec->klsIxPlnrVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxPlnrVMaintable = atol((char*) dbrow[3]); else rec->x1IxPlnrVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAVKeylistKey::insertRec(
			PlnrAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxPlnrVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxPlnrVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVKeylistKey / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAVKeylistKey::insertRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAVKeylistKey::updateRec(
			PlnrAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxPlnrVKeylist,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x1IxPlnrVMaintable,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])), 
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblPlnrAVKeylistKey::updateRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(klsIxPlnrVKeylist) + " AND x1IxPlnrVMaintable = " + to_string(x1IxPlnrVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblPlnrAVKeylistKey::loadRefByKlsSrf(
			uint klsIxPlnrVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(klsIxPlnrVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblPlnrAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrAVKeylistKey WHERE x1IxPlnrVMaintable = " + to_string(x1IxPlnrVMaintable) + " AND x1Uref = " + to_string(x1Uref) + "", append, refs);
};

ubigint MyTblPlnrAVKeylistKey::loadRstByKls(
			uint klsIxPlnrVKeylist
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(klsIxPlnrVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblPlnrAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(klsIxPlnrVKeylist) + " AND x1IxPlnrVMaintable = " + to_string(x1IxPlnrVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblPlnrAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrAVKeylistKey WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAVKeylistKey
 ******************************************************************************/

PgTblPlnrAVKeylistKey::PgTblPlnrAVKeylistKey() : TblPlnrAVKeylistKey(), PgTable() {
};

PgTblPlnrAVKeylistKey::~PgTblPlnrAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAVKeylistKey_insertRec", "INSERT INTO TblPlnrAVKeylistKey (klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_updateRec", "UPDATE TblPlnrAVKeylistKey SET klsIxPlnrVKeylist = $1, klsNum = $2, x1IxPlnrVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_removeRecByRef", "DELETE FROM TblPlnrAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRecByRef", "SELECT ref, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = $1 AND x1IxPlnrVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRefsByMtbUrf", "SELECT ref FROM TblPlnrAVKeylistKey WHERE x1IxPlnrVMaintable = $1 AND x1Uref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRstByKls", "SELECT ref, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = $1 ORDER BY klsNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxPlnrVKeylist, klsNum, x1IxPlnrVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = $1 AND x1IxPlnrVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVKeylistKey_loadTitByRef", "SELECT Title FROM TblPlnrAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAVKeylistKey::loadRec(
			PGresult* res
			, PlnrAVKeylistKey** rec
		) {
	char* ptr;

	PlnrAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixplnrvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixplnrvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxPlnrVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxPlnrVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixplnrvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixplnrvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxPlnrVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxPlnrVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAVKeylistKey::insertRec(
			PlnrAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxPlnrVKeylist = htonl(rec->klsIxPlnrVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxPlnrVMaintable = htonl(rec->x1IxPlnrVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxPlnrVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAVKeylistKey_insertRec", 11, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAVKeylistKey::insertRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAVKeylistKey::updateRec(
			PlnrAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxPlnrVKeylist = htonl(rec->klsIxPlnrVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxPlnrVMaintable = htonl(rec->x1IxPlnrVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxPlnrVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAVKeylistKey::updateRst(
			ListPlnrAVKeylistKey& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxPlnrVKeylist = htonl(klsIxPlnrVKeylist);
	uint _x1IxPlnrVMaintable = htonl(x1IxPlnrVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist,
		(char*) &_x1IxPlnrVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadUbigintByStmt("TblPlnrAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblPlnrAVKeylistKey::loadRefByKlsSrf(
			uint klsIxPlnrVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxPlnrVKeylist = htonl(klsIxPlnrVKeylist);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblPlnrAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblPlnrAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _x1IxPlnrVMaintable = htonl(x1IxPlnrVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_x1IxPlnrVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblPlnrAVKeylistKey_loadRefsByMtbUrf", 2, vals, l, f, append, refs);
};

ubigint PgTblPlnrAVKeylistKey::loadRstByKls(
			uint klsIxPlnrVKeylist
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	uint _klsIxPlnrVKeylist = htonl(klsIxPlnrVKeylist);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxPlnrVKeylist
			, uint x1IxPlnrVMaintable
			, ubigint x1Uref
			, const bool append
			, ListPlnrAVKeylistKey& rst
		) {
	uint _klsIxPlnrVKeylist = htonl(klsIxPlnrVKeylist);
	uint _x1IxPlnrVMaintable = htonl(x1IxPlnrVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxPlnrVKeylist,
		(char*) &_x1IxPlnrVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblPlnrAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblPlnrAVKeylistKey::loadTitByRef(
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

	return loadStringByStmt("TblPlnrAVKeylistKey_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

