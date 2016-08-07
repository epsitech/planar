/**
  * \file PlnrMLayer.cpp
  * database access for table TblPlnrMLayer (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMLayer.h"

/******************************************************************************
 class PlnrMLayer
 ******************************************************************************/

PlnrMLayer::PlnrMLayer(
			const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint refPlnrMMaterial
			, const uint ixVTtype
			, const string sref
			, const ubigint flrRefPlnrMLevel
			, const ubigint ctrRefPlnrMLevel
			, const ubigint ceilRefPlnrMLevel
			, const string t
			, const string ML
		) {

	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->ixVBasetype = ixVBasetype;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->hkNum = hkNum;
	this->refPlnrMMaterial = refPlnrMMaterial;
	this->ixVTtype = ixVTtype;
	this->sref = sref;
	this->flrRefPlnrMLevel = flrRefPlnrMLevel;
	this->ctrRefPlnrMLevel = ctrRefPlnrMLevel;
	this->ceilRefPlnrMLevel = ceilRefPlnrMLevel;
	this->t = t;
	this->ML = ML;
};

bool PlnrMLayer::operator==(
			const PlnrMLayer& comp
		) {
	return false;
};

bool PlnrMLayer::operator!=(
			const PlnrMLayer& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMLayer
 ******************************************************************************/

ListPlnrMLayer::ListPlnrMLayer() {
};

ListPlnrMLayer::ListPlnrMLayer(
			const ListPlnrMLayer& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMLayer(*(src.nodes[i]));
};

ListPlnrMLayer::~ListPlnrMLayer() {
	clear();
};

void ListPlnrMLayer::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMLayer::size() const {
	return(nodes.size());
};

void ListPlnrMLayer::append(
			PlnrMLayer* rec
		) {
	nodes.push_back(rec);
};

PlnrMLayer* ListPlnrMLayer::operator[](
			const uint ix
		) {
	PlnrMLayer* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMLayer& ListPlnrMLayer::operator=(
			const ListPlnrMLayer& src
		) {
	PlnrMLayer* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMLayer(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMLayer::operator==(
			const ListPlnrMLayer& comp
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

bool ListPlnrMLayer::operator!=(
			const ListPlnrMLayer& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMLayer
 ******************************************************************************/

TblPlnrMLayer::TblPlnrMLayer() {
};

TblPlnrMLayer::~TblPlnrMLayer() {
};

bool TblPlnrMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrMLayer** rec
		) {
	return false;
};

ubigint TblPlnrMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return 0;
};

void TblPlnrMLayer::insertRec(
			PlnrMLayer* rec
		) {
};

ubigint TblPlnrMLayer::insertNewRec(
			PlnrMLayer** rec
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint refPlnrMMaterial
			, const uint ixVTtype
			, const string sref
			, const ubigint flrRefPlnrMLevel
			, const ubigint ctrRefPlnrMLevel
			, const ubigint ceilRefPlnrMLevel
			, const string t
			, const string ML
		) {
	ubigint retval = 0;
	PlnrMLayer* _rec = NULL;

	_rec = new PlnrMLayer(0, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMLayer::appendNewRecToRst(
			ListPlnrMLayer& rst
			, PlnrMLayer** rec
			, const ubigint x1RefPlnrMDesign
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint refPlnrMMaterial
			, const uint ixVTtype
			, const string sref
			, const ubigint flrRefPlnrMLevel
			, const ubigint ctrRefPlnrMLevel
			, const ubigint ceilRefPlnrMLevel
			, const string t
			, const string ML
		) {
	ubigint retval = 0;
	PlnrMLayer* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMLayer::insertRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
};

void TblPlnrMLayer::updateRec(
			PlnrMLayer* rec
		) {
};

void TblPlnrMLayer::updateRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
};

void TblPlnrMLayer::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMLayer::loadRecByRef(
			ubigint ref
			, PlnrMLayer** rec
		) {
	return false;
};

ubigint TblPlnrMLayer::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	return 0;
};

bool TblPlnrMLayer::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMLayer::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return 0;
};

ubigint TblPlnrMLayer::loadRstByDsnTypHktHku(
			ubigint x1RefPlnrMDesign
			, uint ixVBasetype
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return 0;
};

ubigint TblPlnrMLayer::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return 0;
};

ubigint TblPlnrMLayer::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMLayer& rst
		) {
	ubigint numload = 0;
	PlnrMLayer* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMLayer
 ******************************************************************************/

MyTblPlnrMLayer::MyTblPlnrMLayer() : TblPlnrMLayer(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMLayer::~MyTblPlnrMLayer() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMLayer::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMLayer (x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMLayer SET x1RefPlnrMDesign = ?, ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, hkNum = ?, refPlnrMMaterial = ?, ixVTtype = ?, sref = ?, flrRefPlnrMLevel = ?, ctrRefPlnrMLevel = ?, ceilRefPlnrMLevel = ?, t = ?, ML = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMLayer WHERE ref = ?", false);
};

bool MyTblPlnrMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrMLayer** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMLayer* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLayer / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMLayer();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[2]) _rec->ixVBasetype = atol((char*) dbrow[2]); else _rec->ixVBasetype = 0;
		if (dbrow[3]) _rec->hkIxVTbl = atol((char*) dbrow[3]); else _rec->hkIxVTbl = 0;
		if (dbrow[4]) _rec->hkUref = atoll((char*) dbrow[4]); else _rec->hkUref = 0;
		if (dbrow[5]) _rec->hkNum = atol((char*) dbrow[5]); else _rec->hkNum = 0;
		if (dbrow[6]) _rec->refPlnrMMaterial = atoll((char*) dbrow[6]); else _rec->refPlnrMMaterial = 0;
		if (dbrow[7]) _rec->ixVTtype = atol((char*) dbrow[7]); else _rec->ixVTtype = 0;
		if (dbrow[8]) _rec->sref.assign(dbrow[8], dblengths[8]); else _rec->sref = "";
		if (dbrow[9]) _rec->flrRefPlnrMLevel = atoll((char*) dbrow[9]); else _rec->flrRefPlnrMLevel = 0;
		if (dbrow[10]) _rec->ctrRefPlnrMLevel = atoll((char*) dbrow[10]); else _rec->ctrRefPlnrMLevel = 0;
		if (dbrow[11]) _rec->ceilRefPlnrMLevel = atoll((char*) dbrow[11]); else _rec->ceilRefPlnrMLevel = 0;
		if (dbrow[12]) _rec->t.assign(dbrow[12], dblengths[12]); else _rec->t = "";
		if (dbrow[13]) _rec->ML.assign(dbrow[13], dblengths[13]); else _rec->ML = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLayer& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMLayer* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMLayer / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMLayer();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[1]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[2]) rec->ixVBasetype = atol((char*) dbrow[2]); else rec->ixVBasetype = 0;
			if (dbrow[3]) rec->hkIxVTbl = atol((char*) dbrow[3]); else rec->hkIxVTbl = 0;
			if (dbrow[4]) rec->hkUref = atoll((char*) dbrow[4]); else rec->hkUref = 0;
			if (dbrow[5]) rec->hkNum = atol((char*) dbrow[5]); else rec->hkNum = 0;
			if (dbrow[6]) rec->refPlnrMMaterial = atoll((char*) dbrow[6]); else rec->refPlnrMMaterial = 0;
			if (dbrow[7]) rec->ixVTtype = atol((char*) dbrow[7]); else rec->ixVTtype = 0;
			if (dbrow[8]) rec->sref.assign(dbrow[8], dblengths[8]); else rec->sref = "";
			if (dbrow[9]) rec->flrRefPlnrMLevel = atoll((char*) dbrow[9]); else rec->flrRefPlnrMLevel = 0;
			if (dbrow[10]) rec->ctrRefPlnrMLevel = atoll((char*) dbrow[10]); else rec->ctrRefPlnrMLevel = 0;
			if (dbrow[11]) rec->ceilRefPlnrMLevel = atoll((char*) dbrow[11]); else rec->ceilRefPlnrMLevel = 0;
			if (dbrow[12]) rec->t.assign(dbrow[12], dblengths[12]); else rec->t = "";
			if (dbrow[13]) rec->ML.assign(dbrow[13], dblengths[13]); else rec->ML = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMLayer::insertRec(
			PlnrMLayer* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[7] = rec->sref.length();
	l[11] = rec->t.length();
	l[12] = rec->ML.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->ixVBasetype,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->hkNum,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refPlnrMMaterial,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVTtype,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->sref.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->flrRefPlnrMLevel,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ctrRefPlnrMLevel,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ceilRefPlnrMLevel,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->t.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->ML.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLayer / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLayer / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMLayer::insertRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMLayer::updateRec(
			PlnrMLayer* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[7] = rec->sref.length();
	l[11] = rec->t.length();
	l[12] = rec->ML.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->ixVBasetype,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->hkIxVTbl,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->hkUref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->hkNum,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refPlnrMMaterial,&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVTtype,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->flrRefPlnrMLevel,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->ctrRefPlnrMLevel,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->ceilRefPlnrMLevel,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->t.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->ML.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLayer / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLayer / stmtUpdateRec)\n");
};

void MyTblPlnrMLayer::updateRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMLayer::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMLayer / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMLayer / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMLayer::loadRecByRef(
			ubigint ref
			, PlnrMLayer** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMLayer WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMLayer::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint cnt;
	loadUbigintBySQL("SELECT COUNT(ref) FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", cnt);
	return cnt;
};

bool MyTblPlnrMLayer::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " AND sref = '" + sref + "'", val);
};

ubigint MyTblPlnrMLayer::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY hkNum ASC", append, rst);
};

ubigint MyTblPlnrMLayer::loadRstByDsnTypHktHku(
			ubigint x1RefPlnrMDesign
			, uint ixVBasetype
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND ixVBasetype = " + to_string(ixVBasetype) + " AND hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY hkNum ASC", append, rst);
};

ubigint MyTblPlnrMLayer::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	return loadRstBySQL("SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY hkNum ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMLayer
 ******************************************************************************/

PgTblPlnrMLayer::PgTblPlnrMLayer() : TblPlnrMLayer(), PgTable() {
};

PgTblPlnrMLayer::~PgTblPlnrMLayer() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMLayer::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMLayer_insertRec", "INSERT INTO TblPlnrMLayer (x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_updateRec", "UPDATE TblPlnrMLayer SET x1RefPlnrMDesign = $1, ixVBasetype = $2, hkIxVTbl = $3, hkUref = $4, hkNum = $5, refPlnrMMaterial = $6, ixVTtype = $7, sref = $8, flrRefPlnrMLevel = $9, ctrRefPlnrMLevel = $10, ceilRefPlnrMLevel = $11, t = $12, ML = $13 WHERE ref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_removeRecByRef", "DELETE FROM TblPlnrMLayer WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMLayer_loadRecByRef", "SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMLayer_countByDsnHktHku", "SELECT COUNT(ref) FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_loadRefByHktHkuSrf", "SELECT ref FROM TblPlnrMLayer WHERE hkIxVTbl = $1 AND hkUref = $2 AND sref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_loadRstByDsnHktHku", "SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = $1 AND hkIxVTbl = $2 AND hkUref = $3 ORDER BY hkNum ASC", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_loadRstByDsnTypHktHku", "SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE x1RefPlnrMDesign = $1 AND ixVBasetype = $2 AND hkIxVTbl = $3 AND hkUref = $4 ORDER BY hkNum ASC", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMLayer_loadRstByHktHku", "SELECT ref, x1RefPlnrMDesign, ixVBasetype, hkIxVTbl, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, flrRefPlnrMLevel, ctrRefPlnrMLevel, ceilRefPlnrMLevel, t, ML FROM TblPlnrMLayer WHERE hkIxVTbl = $1 AND hkUref = $2 ORDER BY hkNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMLayer::loadRec(
			PGresult* res
			, PlnrMLayer** rec
		) {
	char* ptr;

	PlnrMLayer* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMLayer();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "ixvttype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "flrrefplnrmlevel"),
			PQfnumber(res, "ctrrefplnrmlevel"),
			PQfnumber(res, "ceilrefplnrmlevel"),
			PQfnumber(res, "t"),
			PQfnumber(res, "ml")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refPlnrMMaterial = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVTtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->flrRefPlnrMLevel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ctrRefPlnrMLevel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ceilRefPlnrMLevel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->t.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->ML.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMLayer::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMLayer& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMLayer* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "refplnrmmaterial"),
			PQfnumber(res, "ixvttype"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "flrrefplnrmlevel"),
			PQfnumber(res, "ctrrefplnrmlevel"),
			PQfnumber(res, "ceilrefplnrmlevel"),
			PQfnumber(res, "t"),
			PQfnumber(res, "ml")
		};

		while (numread < numrow) {
			rec = new PlnrMLayer();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refPlnrMMaterial = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVTtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->flrRefPlnrMLevel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ctrRefPlnrMLevel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ceilRefPlnrMLevel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->t.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->ML.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMLayer::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMLayer** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLayer / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMLayer::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMLayer& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLayer / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMLayer::loadRecBySQL(
			const string& sqlstr
			, PlnrMLayer** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMLayer::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMLayer& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMLayer::insertRec(
			PlnrMLayer* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	uint _ixVTtype = htonl(rec->ixVTtype);
	ubigint _flrRefPlnrMLevel = htonl64(rec->flrRefPlnrMLevel);
	ubigint _ctrRefPlnrMLevel = htonl64(rec->ctrRefPlnrMLevel);
	ubigint _ceilRefPlnrMLevel = htonl64(rec->ceilRefPlnrMLevel);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_refPlnrMMaterial,
		(char*) &_ixVTtype,
		rec->sref.c_str(),
		(char*) &_flrRefPlnrMLevel,
		(char*) &_ctrRefPlnrMLevel,
		(char*) &_ceilRefPlnrMLevel,
		rec->t.c_str(),
		rec->ML.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMLayer_insertRec", 13, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLayer_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMLayer::insertRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMLayer::updateRec(
			PlnrMLayer* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	uint _ixVTtype = htonl(rec->ixVTtype);
	ubigint _flrRefPlnrMLevel = htonl64(rec->flrRefPlnrMLevel);
	ubigint _ctrRefPlnrMLevel = htonl64(rec->ctrRefPlnrMLevel);
	ubigint _ceilRefPlnrMLevel = htonl64(rec->ceilRefPlnrMLevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_refPlnrMMaterial,
		(char*) &_ixVTtype,
		rec->sref.c_str(),
		(char*) &_flrRefPlnrMLevel,
		(char*) &_ctrRefPlnrMLevel,
		(char*) &_ceilRefPlnrMLevel,
		rec->t.c_str(),
		rec->ML.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMLayer_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLayer_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMLayer::updateRst(
			ListPlnrMLayer& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMLayer::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMLayer_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMLayer_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMLayer::loadRecByRef(
			ubigint ref
			, PlnrMLayer** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMLayer_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMLayer::countByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	ubigint cnt;
	loadUbigintByStmt("TblPlnrMLayer_countByDsnHktHku", 3, vals, l, f, cnt);
	return cnt;
};

bool PgTblPlnrMLayer::loadRefByHktHkuSrf(
			uint hkIxVTbl
			, ubigint hkUref
			, string sref
			, ubigint& val
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadUbigintByStmt("TblPlnrMLayer_loadRefByHktHkuSrf", 3, vals, l, f, val);
};

ubigint PgTblPlnrMLayer::loadRstByDsnHktHku(
			ubigint x1RefPlnrMDesign
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblPlnrMLayer_loadRstByDsnHktHku", 3, vals, l, f, append, rst);
};

ubigint PgTblPlnrMLayer::loadRstByDsnTypHktHku(
			ubigint x1RefPlnrMDesign
			, uint ixVBasetype
			, uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);
	uint _ixVBasetype = htonl(ixVBasetype);
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1,1};

	return loadRstByStmt("TblPlnrMLayer_loadRstByDsnTypHktHku", 4, vals, l, f, append, rst);
};

ubigint PgTblPlnrMLayer::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListPlnrMLayer& rst
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrMLayer_loadRstByHktHku", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

