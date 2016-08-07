/**
  * \file PlnrQMatAPar.cpp
  * Dbs and XML wrapper for table TblPlnrQMatAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQMatAPar.h"

/******************************************************************************
 class PlnrQMatAPar
 ******************************************************************************/

PlnrQMatAPar::PlnrQMatAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->stubX1RefPlnrMDesign = stubX1RefPlnrMDesign;
	this->x2SrefKCat = x2SrefKCat;
	this->titX2SrefKCat = titX2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->titX3SrefKProp = titX3SrefKProp;
	this->refPlnrMFile = refPlnrMFile;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
	this->Comment = Comment;
};

void PlnrQMatAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQMatAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "dsn", stubX1RefPlnrMDesign);
		writeString(wr, "cat", x2SrefKCat);
		writeString(wr, "cat2", titX2SrefKCat);
		writeString(wr, "prp", x3SrefKProp);
		writeString(wr, "prp2", titX3SrefKProp);
		writeString(wr, "fil", stubRefPlnrMFile);
		writeString(wr, "val", Val);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "stubX1RefPlnrMDesign", stubX1RefPlnrMDesign);
		writeString(wr, "x2SrefKCat", x2SrefKCat);
		writeString(wr, "titX2SrefKCat", titX2SrefKCat);
		writeString(wr, "x3SrefKProp", x3SrefKProp);
		writeString(wr, "titX3SrefKProp", titX3SrefKProp);
		writeString(wr, "stubRefPlnrMFile", stubRefPlnrMFile);
		writeString(wr, "Val", Val);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQMatAPar
 ******************************************************************************/

ListPlnrQMatAPar::ListPlnrQMatAPar() {
};

ListPlnrQMatAPar::ListPlnrQMatAPar(
			const ListPlnrQMatAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQMatAPar(*(src.nodes[i]));
};

ListPlnrQMatAPar::~ListPlnrQMatAPar() {
	clear();
};

void ListPlnrQMatAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQMatAPar::size() const {
	return(nodes.size());
};

void ListPlnrQMatAPar::append(
			PlnrQMatAPar* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQMatAPar& ListPlnrQMatAPar::operator=(
			const ListPlnrQMatAPar& src
		) {
	PlnrQMatAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQMatAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQMatAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQMatAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQMatAPar
 ******************************************************************************/

TblPlnrQMatAPar::TblPlnrQMatAPar() {
};

TblPlnrQMatAPar::~TblPlnrQMatAPar() {
};

bool TblPlnrQMatAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatAPar** rec
		) {
	return false;
};

ubigint TblPlnrQMatAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	return 0;
};

void TblPlnrQMatAPar::insertRec(
			PlnrQMatAPar* rec
		) {
};

ubigint TblPlnrQMatAPar::insertNewRec(
			PlnrQMatAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQMatAPar* _rec = NULL;

	_rec = new PlnrQMatAPar(0, jref, jnum, ref, x1RefPlnrMDesign, stubX1RefPlnrMDesign, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, refPlnrMFile, stubRefPlnrMFile, Val, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQMatAPar::appendNewRecToRst(
			ListPlnrQMatAPar& rst
			, PlnrQMatAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQMatAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMDesign, stubX1RefPlnrMDesign, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, refPlnrMFile, stubRefPlnrMFile, Val, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQMatAPar::insertRst(
			ListPlnrQMatAPar& rst
		) {
};

void TblPlnrQMatAPar::updateRec(
			PlnrQMatAPar* rec
		) {
};

void TblPlnrQMatAPar::updateRst(
			ListPlnrQMatAPar& rst
		) {
};

void TblPlnrQMatAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQMatAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQMatAPar::loadRecByQref(
			ubigint qref
			, PlnrQMatAPar** rec
		) {
	return false;
};

ubigint TblPlnrQMatAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQMatAPar
 ******************************************************************************/

MyTblPlnrQMatAPar::MyTblPlnrQMatAPar() : TblPlnrQMatAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQMatAPar::~MyTblPlnrQMatAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQMatAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQMatAPar (jref, jnum, ref, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQMatAPar SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMDesign = ?, x2SrefKCat = ?, x3SrefKProp = ?, refPlnrMFile = ?, Val = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQMatAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQMatAPar WHERE jref = ?", false);
};

bool MyTblPlnrQMatAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQMatAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQMatAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[4]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[5]) _rec->x2SrefKCat.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKCat = "";
		if (dbrow[6]) _rec->x3SrefKProp.assign(dbrow[6], dblengths[6]); else _rec->x3SrefKProp = "";
		if (dbrow[7]) _rec->refPlnrMFile = atoll((char*) dbrow[7]); else _rec->refPlnrMFile = 0;
		if (dbrow[8]) _rec->Val.assign(dbrow[8], dblengths[8]); else _rec->Val = "";
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQMatAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQMatAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQMatAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQMatAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[4]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[5]) rec->x2SrefKCat.assign(dbrow[5], dblengths[5]); else rec->x2SrefKCat = "";
			if (dbrow[6]) rec->x3SrefKProp.assign(dbrow[6], dblengths[6]); else rec->x3SrefKProp = "";
			if (dbrow[7]) rec->refPlnrMFile = atoll((char*) dbrow[7]); else rec->refPlnrMFile = 0;
			if (dbrow[8]) rec->Val.assign(dbrow[8], dblengths[8]); else rec->Val = "";
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQMatAPar::insertRec(
			PlnrQMatAPar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->x2SrefKCat.length();
	l[5] = rec->x3SrefKProp.length();
	l[7] = rec->Val.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refPlnrMFile,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Val.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQMatAPar::insertRst(
			ListPlnrQMatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQMatAPar::updateRec(
			PlnrQMatAPar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->x2SrefKCat.length();
	l[5] = rec->x3SrefKProp.length();
	l[7] = rec->Val.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refPlnrMFile,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatAPar / stmtUpdateRec)\n");
};

void MyTblPlnrQMatAPar::updateRst(
			ListPlnrQMatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQMatAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatAPar / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQMatAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQMatAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQMatAPar / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQMatAPar::loadRecByQref(
			ubigint qref
			, PlnrQMatAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQMatAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQMatAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQMatAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQMatAPar
 ******************************************************************************/

PgTblPlnrQMatAPar::PgTblPlnrQMatAPar() : TblPlnrQMatAPar(), PgTable() {
};

PgTblPlnrQMatAPar::~PgTblPlnrQMatAPar() {
};

void PgTblPlnrQMatAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQMatAPar_insertRec", "INSERT INTO TblPlnrQMatAPar (jref, jnum, ref, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatAPar_updateRec", "UPDATE TblPlnrQMatAPar SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMDesign = $4, x2SrefKCat = $5, x3SrefKProp = $6, refPlnrMFile = $7, Val = $8, Comment = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatAPar_removeRecByQref", "DELETE FROM TblPlnrQMatAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatAPar_removeRstByJref", "DELETE FROM TblPlnrQMatAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQMatAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment FROM TblPlnrQMatAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQMatAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, refPlnrMFile, Val, Comment FROM TblPlnrQMatAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQMatAPar::loadRec(
			PGresult* res
			, PlnrQMatAPar** rec
		) {
	char* ptr;

	PlnrQMatAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQMatAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKCat.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x3SrefKProp.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQMatAPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQMatAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrQMatAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKCat.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x3SrefKProp.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQMatAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQMatAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQMatAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQMatAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQMatAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQMatAPar::insertRec(
			PlnrQMatAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQMatAPar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQMatAPar::insertRst(
			ListPlnrQMatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQMatAPar::updateRec(
			PlnrQMatAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQMatAPar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQMatAPar::updateRst(
			ListPlnrQMatAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQMatAPar::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQMatAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQMatAPar::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQMatAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQMatAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQMatAPar::loadRecByQref(
			ubigint qref
			, PlnrQMatAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQMatAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQMatAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQMatAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQMatAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

