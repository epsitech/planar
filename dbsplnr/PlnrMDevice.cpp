/**
  * \file PlnrMDevice.cpp
  * database access for table TblPlnrMDevice (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMDevice.h"

/******************************************************************************
 class PlnrMDevice
 ******************************************************************************/

PlnrMDevice::PlnrMDevice(
			const ubigint ref
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const ubigint supRefPlnrMDevice
			, const uint supNum
			, const ubigint tplRefPlnrMDevice
			, const string sref
			, const uint ixVModtype
			, const uint ixVAligntype
			, const string av1SrefPlnrMVertex
			, const string pav1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string pav2SrefPlnrMVertex
			, const double x
			, const double y
			, const double phi
			, const string Comment
		) {

	this->ref = ref;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->dsnNum = dsnNum;
	this->supRefPlnrMDevice = supRefPlnrMDevice;
	this->supNum = supNum;
	this->tplRefPlnrMDevice = tplRefPlnrMDevice;
	this->sref = sref;
	this->ixVModtype = ixVModtype;
	this->ixVAligntype = ixVAligntype;
	this->av1SrefPlnrMVertex = av1SrefPlnrMVertex;
	this->pav1SrefPlnrMVertex = pav1SrefPlnrMVertex;
	this->av2SrefPlnrMVertex = av2SrefPlnrMVertex;
	this->pav2SrefPlnrMVertex = pav2SrefPlnrMVertex;
	this->x = x;
	this->y = y;
	this->phi = phi;
	this->Comment = Comment;
};

bool PlnrMDevice::operator==(
			const PlnrMDevice& comp
		) {
	return false;
};

bool PlnrMDevice::operator!=(
			const PlnrMDevice& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMDevice
 ******************************************************************************/

ListPlnrMDevice::ListPlnrMDevice() {
};

ListPlnrMDevice::ListPlnrMDevice(
			const ListPlnrMDevice& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMDevice(*(src.nodes[i]));
};

ListPlnrMDevice::~ListPlnrMDevice() {
	clear();
};

void ListPlnrMDevice::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMDevice::size() const {
	return(nodes.size());
};

void ListPlnrMDevice::append(
			PlnrMDevice* rec
		) {
	nodes.push_back(rec);
};

PlnrMDevice* ListPlnrMDevice::operator[](
			const uint ix
		) {
	PlnrMDevice* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMDevice& ListPlnrMDevice::operator=(
			const ListPlnrMDevice& src
		) {
	PlnrMDevice* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMDevice(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMDevice::operator==(
			const ListPlnrMDevice& comp
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

bool ListPlnrMDevice::operator!=(
			const ListPlnrMDevice& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMDevice
 ******************************************************************************/

TblPlnrMDevice::TblPlnrMDevice() {
};

TblPlnrMDevice::~TblPlnrMDevice() {
};

bool TblPlnrMDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrMDevice** rec
		) {
	return false;
};

ubigint TblPlnrMDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDevice& rst
		) {
	return 0;
};

void TblPlnrMDevice::insertRec(
			PlnrMDevice* rec
		) {
};

ubigint TblPlnrMDevice::insertNewRec(
			PlnrMDevice** rec
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const ubigint supRefPlnrMDevice
			, const uint supNum
			, const ubigint tplRefPlnrMDevice
			, const string sref
			, const uint ixVModtype
			, const uint ixVAligntype
			, const string av1SrefPlnrMVertex
			, const string pav1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string pav2SrefPlnrMVertex
			, const double x
			, const double y
			, const double phi
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMDevice* _rec = NULL;

	_rec = new PlnrMDevice(0, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMDevice::appendNewRecToRst(
			ListPlnrMDevice& rst
			, PlnrMDevice** rec
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const ubigint supRefPlnrMDevice
			, const uint supNum
			, const ubigint tplRefPlnrMDevice
			, const string sref
			, const uint ixVModtype
			, const uint ixVAligntype
			, const string av1SrefPlnrMVertex
			, const string pav1SrefPlnrMVertex
			, const string av2SrefPlnrMVertex
			, const string pav2SrefPlnrMVertex
			, const double x
			, const double y
			, const double phi
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMDevice* _rec = NULL;

	retval = insertNewRec(&_rec, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMDevice::insertRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
};

void TblPlnrMDevice::updateRec(
			PlnrMDevice* rec
		) {
};

void TblPlnrMDevice::updateRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
};

void TblPlnrMDevice::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMDevice::loadRecByRef(
			ubigint ref
			, PlnrMDevice** rec
		) {
	return false;
};

bool TblPlnrMDevice::loadRefByTplSrf(
			ubigint tplRefPlnrMDevice
			, string sref
			, ubigint& val
		) {
	return false;
};

ubigint TblPlnrMDevice::loadRefsBySup(
			ubigint supRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMDevice::loadRefsBySupTpl(
			ubigint supRefPlnrMDevice
			, ubigint tplRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMDevice::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDevice& rst
		) {
	return 0;
};

ubigint TblPlnrMDevice::loadRstByDsnSup(
			ubigint dsnRefPlnrMDesign
			, ubigint supRefPlnrMDevice
			, const bool append
			, ListPlnrMDevice& rst
		) {
	return 0;
};

bool TblPlnrMDevice::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMDevice::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMDevice& rst
		) {
	ubigint numload = 0;
	PlnrMDevice* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMDevice
 ******************************************************************************/

MyTblPlnrMDevice::MyTblPlnrMDevice() : TblPlnrMDevice(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMDevice::~MyTblPlnrMDevice() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMDevice::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMDevice (dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMDevice SET dsnRefPlnrMDesign = ?, dsnNum = ?, supRefPlnrMDevice = ?, supNum = ?, tplRefPlnrMDevice = ?, sref = ?, ixVModtype = ?, ixVAligntype = ?, av1SrefPlnrMVertex = ?, pav1SrefPlnrMVertex = ?, av2SrefPlnrMVertex = ?, pav2SrefPlnrMVertex = ?, x = ?, y = ?, phi = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMDevice WHERE ref = ?", false);
};

bool MyTblPlnrMDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrMDevice** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMDevice* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDevice / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMDevice();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[1]); else _rec->dsnRefPlnrMDesign = 0;
		if (dbrow[2]) _rec->dsnNum = atol((char*) dbrow[2]); else _rec->dsnNum = 0;
		if (dbrow[3]) _rec->supRefPlnrMDevice = atoll((char*) dbrow[3]); else _rec->supRefPlnrMDevice = 0;
		if (dbrow[4]) _rec->supNum = atol((char*) dbrow[4]); else _rec->supNum = 0;
		if (dbrow[5]) _rec->tplRefPlnrMDevice = atoll((char*) dbrow[5]); else _rec->tplRefPlnrMDevice = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->ixVModtype = atol((char*) dbrow[7]); else _rec->ixVModtype = 0;
		if (dbrow[8]) _rec->ixVAligntype = atol((char*) dbrow[8]); else _rec->ixVAligntype = 0;
		if (dbrow[9]) _rec->av1SrefPlnrMVertex.assign(dbrow[9], dblengths[9]); else _rec->av1SrefPlnrMVertex = "";
		if (dbrow[10]) _rec->pav1SrefPlnrMVertex.assign(dbrow[10], dblengths[10]); else _rec->pav1SrefPlnrMVertex = "";
		if (dbrow[11]) _rec->av2SrefPlnrMVertex.assign(dbrow[11], dblengths[11]); else _rec->av2SrefPlnrMVertex = "";
		if (dbrow[12]) _rec->pav2SrefPlnrMVertex.assign(dbrow[12], dblengths[12]); else _rec->pav2SrefPlnrMVertex = "";
		if (dbrow[13]) _rec->x = atof((char*) dbrow[13]); else _rec->x = 0.0;
		if (dbrow[14]) _rec->y = atof((char*) dbrow[14]); else _rec->y = 0.0;
		if (dbrow[15]) _rec->phi = atof((char*) dbrow[15]); else _rec->phi = 0.0;
		if (dbrow[16]) _rec->Comment.assign(dbrow[16], dblengths[16]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDevice& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMDevice* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMDevice / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMDevice();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[1]); else rec->dsnRefPlnrMDesign = 0;
			if (dbrow[2]) rec->dsnNum = atol((char*) dbrow[2]); else rec->dsnNum = 0;
			if (dbrow[3]) rec->supRefPlnrMDevice = atoll((char*) dbrow[3]); else rec->supRefPlnrMDevice = 0;
			if (dbrow[4]) rec->supNum = atol((char*) dbrow[4]); else rec->supNum = 0;
			if (dbrow[5]) rec->tplRefPlnrMDevice = atoll((char*) dbrow[5]); else rec->tplRefPlnrMDevice = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->ixVModtype = atol((char*) dbrow[7]); else rec->ixVModtype = 0;
			if (dbrow[8]) rec->ixVAligntype = atol((char*) dbrow[8]); else rec->ixVAligntype = 0;
			if (dbrow[9]) rec->av1SrefPlnrMVertex.assign(dbrow[9], dblengths[9]); else rec->av1SrefPlnrMVertex = "";
			if (dbrow[10]) rec->pav1SrefPlnrMVertex.assign(dbrow[10], dblengths[10]); else rec->pav1SrefPlnrMVertex = "";
			if (dbrow[11]) rec->av2SrefPlnrMVertex.assign(dbrow[11], dblengths[11]); else rec->av2SrefPlnrMVertex = "";
			if (dbrow[12]) rec->pav2SrefPlnrMVertex.assign(dbrow[12], dblengths[12]); else rec->pav2SrefPlnrMVertex = "";
			if (dbrow[13]) rec->x = atof((char*) dbrow[13]); else rec->x = 0.0;
			if (dbrow[14]) rec->y = atof((char*) dbrow[14]); else rec->y = 0.0;
			if (dbrow[15]) rec->phi = atof((char*) dbrow[15]); else rec->phi = 0.0;
			if (dbrow[16]) rec->Comment.assign(dbrow[16], dblengths[16]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMDevice::insertRec(
			PlnrMDevice* rec
		) {
	unsigned long l[16]; my_bool n[16]; my_bool e[16];

	l[5] = rec->sref.length();
	l[8] = rec->av1SrefPlnrMVertex.length();
	l[9] = rec->pav1SrefPlnrMVertex.length();
	l[10] = rec->av2SrefPlnrMVertex.length();
	l[11] = rec->pav2SrefPlnrMVertex.length();
	l[15] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->dsnNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->supRefPlnrMDevice,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->tplRefPlnrMDevice,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVModtype,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVAligntype,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->av1SrefPlnrMVertex.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->pav1SrefPlnrMVertex.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->av2SrefPlnrMVertex.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->pav2SrefPlnrMVertex.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->x,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->y,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->phi,&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[15]),&(n[15]),&(e[15]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDevice / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDevice / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMDevice::insertRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMDevice::updateRec(
			PlnrMDevice* rec
		) {
	unsigned long l[17]; my_bool n[17]; my_bool e[17];

	l[5] = rec->sref.length();
	l[8] = rec->av1SrefPlnrMVertex.length();
	l[9] = rec->pav1SrefPlnrMVertex.length();
	l[10] = rec->av2SrefPlnrMVertex.length();
	l[11] = rec->pav2SrefPlnrMVertex.length();
	l[15] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->dsnNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->supRefPlnrMDevice,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->tplRefPlnrMDevice,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->ixVModtype,&(l[6]),&(n[6]),&(e[6])), 
		bindUint(&rec->ixVAligntype,&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->av1SrefPlnrMVertex.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->pav1SrefPlnrMVertex.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->av2SrefPlnrMVertex.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->pav2SrefPlnrMVertex.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindDouble(&rec->x,&(l[12]),&(n[12]),&(e[12])), 
		bindDouble(&rec->y,&(l[13]),&(n[13]),&(e[13])), 
		bindDouble(&rec->phi,&(l[14]),&(n[14]),&(e[14])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[15]),&(n[15]),&(e[15])), 
		bindUbigint(&rec->ref,&(l[16]),&(n[16]),&(e[16]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDevice / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDevice / stmtUpdateRec)\n");
};

void MyTblPlnrMDevice::updateRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMDevice::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMDevice / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMDevice / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMDevice::loadRecByRef(
			ubigint ref
			, PlnrMDevice** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMDevice WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMDevice::loadRefByTplSrf(
			ubigint tplRefPlnrMDevice
			, string sref
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMDevice WHERE tplRefPlnrMDevice = " + to_string(tplRefPlnrMDevice) + " AND sref = '" + sref + "'", val);
};

ubigint MyTblPlnrMDevice::loadRefsBySup(
			ubigint supRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(supRefPlnrMDevice) + " ORDER BY supNum ASC, dsnNum ASC", append, refs);
};

ubigint MyTblPlnrMDevice::loadRefsBySupTpl(
			ubigint supRefPlnrMDevice
			, ubigint tplRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = " + to_string(supRefPlnrMDevice) + " AND tplRefPlnrMDevice = " + to_string(tplRefPlnrMDevice) + " ORDER BY supNum ASC, dsnNum ASC", append, refs);
};

ubigint MyTblPlnrMDevice::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDevice& rst
		) {
	return loadRstBySQL("SELECT ref, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment FROM TblPlnrMDevice WHERE dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " ORDER BY dsnNum ASC", append, rst);
};

ubigint MyTblPlnrMDevice::loadRstByDsnSup(
			ubigint dsnRefPlnrMDesign
			, ubigint supRefPlnrMDevice
			, const bool append
			, ListPlnrMDevice& rst
		) {
	return loadRstBySQL("SELECT ref, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment FROM TblPlnrMDevice WHERE dsnRefPlnrMDesign = " + to_string(dsnRefPlnrMDesign) + " AND supRefPlnrMDevice = " + to_string(supRefPlnrMDevice) + " ORDER BY supNum ASC, dsnNum ASC", append, rst);
};

bool MyTblPlnrMDevice::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMDevice WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMDevice
 ******************************************************************************/

PgTblPlnrMDevice::PgTblPlnrMDevice() : TblPlnrMDevice(), PgTable() {
};

PgTblPlnrMDevice::~PgTblPlnrMDevice() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMDevice::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMDevice_insertRec", "INSERT INTO TblPlnrMDevice (dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16) RETURNING ref", 16, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_updateRec", "UPDATE TblPlnrMDevice SET dsnRefPlnrMDesign = $1, dsnNum = $2, supRefPlnrMDevice = $3, supNum = $4, tplRefPlnrMDevice = $5, sref = $6, ixVModtype = $7, ixVAligntype = $8, av1SrefPlnrMVertex = $9, pav1SrefPlnrMVertex = $10, av2SrefPlnrMVertex = $11, pav2SrefPlnrMVertex = $12, x = $13, y = $14, phi = $15, Comment = $16 WHERE ref = $17", 17, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_removeRecByRef", "DELETE FROM TblPlnrMDevice WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMDevice_loadRecByRef", "SELECT ref, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment FROM TblPlnrMDevice WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMDevice_loadRefByTplSrf", "SELECT ref FROM TblPlnrMDevice WHERE tplRefPlnrMDevice = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_loadRefsBySup", "SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = $1 ORDER BY supNum ASC, dsnNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_loadRefsBySupTpl", "SELECT ref FROM TblPlnrMDevice WHERE supRefPlnrMDevice = $1 AND tplRefPlnrMDevice = $2 ORDER BY supNum ASC, dsnNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_loadRstByDsn", "SELECT ref, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment FROM TblPlnrMDevice WHERE dsnRefPlnrMDesign = $1 ORDER BY dsnNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_loadRstByDsnSup", "SELECT ref, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, tplRefPlnrMDevice, sref, ixVModtype, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment FROM TblPlnrMDevice WHERE dsnRefPlnrMDesign = $1 AND supRefPlnrMDevice = $2 ORDER BY supNum ASC, dsnNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMDevice_loadSrfByRef", "SELECT sref FROM TblPlnrMDevice WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMDevice::loadRec(
			PGresult* res
			, PlnrMDevice** rec
		) {
	char* ptr;

	PlnrMDevice* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMDevice();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "tplrefplnrmdevice"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvaligntype"),
			PQfnumber(res, "av1srefplnrmvertex"),
			PQfnumber(res, "pav1srefplnrmvertex"),
			PQfnumber(res, "av2srefplnrmvertex"),
			PQfnumber(res, "pav2srefplnrmvertex"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y"),
			PQfnumber(res, "phi"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->dsnRefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supRefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->tplRefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVModtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVAligntype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->av1SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->pav1SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->av2SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->pav2SrefPlnrMVertex.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->y = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->phi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[16]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMDevice::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMDevice& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMDevice* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dsnrefplnrmdesign"),
			PQfnumber(res, "dsnnum"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "tplrefplnrmdevice"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvmodtype"),
			PQfnumber(res, "ixvaligntype"),
			PQfnumber(res, "av1srefplnrmvertex"),
			PQfnumber(res, "pav1srefplnrmvertex"),
			PQfnumber(res, "av2srefplnrmvertex"),
			PQfnumber(res, "pav2srefplnrmvertex"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y"),
			PQfnumber(res, "phi"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMDevice();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->dsnRefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supRefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->tplRefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVModtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVAligntype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->av1SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->pav1SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->av2SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->pav2SrefPlnrMVertex.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->y = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->phi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[16]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMDevice::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMDevice** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDevice / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMDevice::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMDevice& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDevice / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMDevice::loadRecBySQL(
			const string& sqlstr
			, PlnrMDevice** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMDevice::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMDevice& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMDevice::insertRec(
			PlnrMDevice* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	uint _supNum = htonl(rec->supNum);
	ubigint _tplRefPlnrMDevice = htonl64(rec->tplRefPlnrMDevice);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVAligntype = htonl(rec->ixVAligntype);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	string _phi = to_string(rec->phi);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		(char*) &_supRefPlnrMDevice,
		(char*) &_supNum,
		(char*) &_tplRefPlnrMDevice,
		rec->sref.c_str(),
		(char*) &_ixVModtype,
		(char*) &_ixVAligntype,
		rec->av1SrefPlnrMVertex.c_str(),
		rec->pav1SrefPlnrMVertex.c_str(),
		rec->av2SrefPlnrMVertex.c_str(),
		rec->pav2SrefPlnrMVertex.c_str(),
		_x.c_str(),
		_y.c_str(),
		_phi.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMDevice_insertRec", 16, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDevice_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMDevice::insertRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMDevice::updateRec(
			PlnrMDevice* rec
		) {
	PGresult* res;

	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	uint _dsnNum = htonl(rec->dsnNum);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	uint _supNum = htonl(rec->supNum);
	ubigint _tplRefPlnrMDevice = htonl64(rec->tplRefPlnrMDevice);
	uint _ixVModtype = htonl(rec->ixVModtype);
	uint _ixVAligntype = htonl(rec->ixVAligntype);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	string _phi = to_string(rec->phi);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_dsnNum,
		(char*) &_supRefPlnrMDevice,
		(char*) &_supNum,
		(char*) &_tplRefPlnrMDevice,
		rec->sref.c_str(),
		(char*) &_ixVModtype,
		(char*) &_ixVAligntype,
		rec->av1SrefPlnrMVertex.c_str(),
		rec->pav1SrefPlnrMVertex.c_str(),
		rec->av2SrefPlnrMVertex.c_str(),
		rec->pav2SrefPlnrMVertex.c_str(),
		_x.c_str(),
		_y.c_str(),
		_phi.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMDevice_updateRec", 17, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDevice_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMDevice::updateRst(
			ListPlnrMDevice& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMDevice::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMDevice_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMDevice_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMDevice::loadRecByRef(
			ubigint ref
			, PlnrMDevice** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMDevice_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMDevice::loadRefByTplSrf(
			ubigint tplRefPlnrMDevice
			, string sref
			, ubigint& val
		) {
	ubigint _tplRefPlnrMDevice = htonl64(tplRefPlnrMDevice);

	const char* vals[] = {
		(char*) &_tplRefPlnrMDevice,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadUbigintByStmt("TblPlnrMDevice_loadRefByTplSrf", 2, vals, l, f, val);
};

ubigint PgTblPlnrMDevice::loadRefsBySup(
			ubigint supRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefPlnrMDevice = htonl64(supRefPlnrMDevice);

	const char* vals[] = {
		(char*) &_supRefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrMDevice_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrMDevice::loadRefsBySupTpl(
			ubigint supRefPlnrMDevice
			, ubigint tplRefPlnrMDevice
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefPlnrMDevice = htonl64(supRefPlnrMDevice);
	ubigint _tplRefPlnrMDevice = htonl64(tplRefPlnrMDevice);

	const char* vals[] = {
		(char*) &_supRefPlnrMDevice,
		(char*) &_tplRefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblPlnrMDevice_loadRefsBySupTpl", 2, vals, l, f, append, refs);
};

ubigint PgTblPlnrMDevice::loadRstByDsn(
			ubigint dsnRefPlnrMDesign
			, const bool append
			, ListPlnrMDevice& rst
		) {
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMDevice_loadRstByDsn", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrMDevice::loadRstByDsnSup(
			ubigint dsnRefPlnrMDesign
			, ubigint supRefPlnrMDevice
			, const bool append
			, ListPlnrMDevice& rst
		) {
	ubigint _dsnRefPlnrMDesign = htonl64(dsnRefPlnrMDesign);
	ubigint _supRefPlnrMDevice = htonl64(supRefPlnrMDevice);

	const char* vals[] = {
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_supRefPlnrMDevice
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrMDevice_loadRstByDsnSup", 2, vals, l, f, append, rst);
};

bool PgTblPlnrMDevice::loadSrfByRef(
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

	return loadStringByStmt("TblPlnrMDevice_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

