/**
  * \file PlnrQAriList.cpp
  * Dbs and XML wrapper for table TblPlnrQAriList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQAriList.h"

/******************************************************************************
 class PlnrQAriList
 ******************************************************************************/

PlnrQAriList::PlnrQAriList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const ubigint refPlnrMArray
			, const string stubRefPlnrMArray
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const double dx
			, const double dy
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->i = i;
	this->j = j;
	this->k = k;
	this->l = l;
	this->m = m;
	this->n = n;
	this->refPlnrMArray = refPlnrMArray;
	this->stubRefPlnrMArray = stubRefPlnrMArray;
	this->refPlnrMDesign = refPlnrMDesign;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
	this->dx = dx;
	this->dy = dy;
};

void PlnrQAriList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQAriList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeUint(wr, "i", i);
		writeUint(wr, "j", j);
		writeUint(wr, "k", k);
		writeUint(wr, "l", l);
		writeUint(wr, "m", m);
		writeUint(wr, "n", n);
		writeString(wr, "arr", stubRefPlnrMArray);
		writeString(wr, "dsn", stubRefPlnrMDesign);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
	} else {
		writeUint(wr, "i", i);
		writeUint(wr, "j", j);
		writeUint(wr, "k", k);
		writeUint(wr, "l", l);
		writeUint(wr, "m", m);
		writeUint(wr, "n", n);
		writeString(wr, "stubRefPlnrMArray", stubRefPlnrMArray);
		writeString(wr, "stubRefPlnrMDesign", stubRefPlnrMDesign);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQAriList
 ******************************************************************************/

ListPlnrQAriList::ListPlnrQAriList() {
};

ListPlnrQAriList::ListPlnrQAriList(
			const ListPlnrQAriList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQAriList(*(src.nodes[i]));
};

ListPlnrQAriList::~ListPlnrQAriList() {
	clear();
};

void ListPlnrQAriList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQAriList::size() const {
	return(nodes.size());
};

void ListPlnrQAriList::append(
			PlnrQAriList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQAriList& ListPlnrQAriList::operator=(
			const ListPlnrQAriList& src
		) {
	PlnrQAriList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQAriList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQAriList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQAriList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQAriList
 ******************************************************************************/

TblPlnrQAriList::TblPlnrQAriList() {
};

TblPlnrQAriList::~TblPlnrQAriList() {
};

bool TblPlnrQAriList::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriList** rec
		) {
	return false;
};

ubigint TblPlnrQAriList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriList& rst
		) {
	return 0;
};

void TblPlnrQAriList::insertRec(
			PlnrQAriList* rec
		) {
};

ubigint TblPlnrQAriList::insertNewRec(
			PlnrQAriList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const ubigint refPlnrMArray
			, const string stubRefPlnrMArray
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const double dx
			, const double dy
		) {
	ubigint retval = 0;
	PlnrQAriList* _rec = NULL;

	_rec = new PlnrQAriList(0, jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, stubRefPlnrMArray, refPlnrMDesign, stubRefPlnrMDesign, dx, dy);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQAriList::appendNewRecToRst(
			ListPlnrQAriList& rst
			, PlnrQAriList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const usmallint i
			, const usmallint j
			, const usmallint k
			, const usmallint l
			, const usmallint m
			, const usmallint n
			, const ubigint refPlnrMArray
			, const string stubRefPlnrMArray
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
			, const double dx
			, const double dy
		) {
	ubigint retval = 0;
	PlnrQAriList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, stubRefPlnrMArray, refPlnrMDesign, stubRefPlnrMDesign, dx, dy);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQAriList::insertRst(
			ListPlnrQAriList& rst
		) {
};

void TblPlnrQAriList::updateRec(
			PlnrQAriList* rec
		) {
};

void TblPlnrQAriList::updateRst(
			ListPlnrQAriList& rst
		) {
};

void TblPlnrQAriList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQAriList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQAriList::loadRecByQref(
			ubigint qref
			, PlnrQAriList** rec
		) {
	return false;
};

ubigint TblPlnrQAriList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQAriList
 ******************************************************************************/

MyTblPlnrQAriList::MyTblPlnrQAriList() : TblPlnrQAriList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQAriList::~MyTblPlnrQAriList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQAriList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQAriList (jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, refPlnrMDesign, dx, dy) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQAriList SET jref = ?, jnum = ?, ref = ?, i = ?, j = ?, k = ?, l = ?, m = ?, n = ?, refPlnrMArray = ?, refPlnrMDesign = ?, dx = ?, dy = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQAriList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQAriList WHERE jref = ?", false);
};

bool MyTblPlnrQAriList::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQAriList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQAriList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQAriList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->i = atoi((char*) dbrow[4]); else _rec->i = 0;
		if (dbrow[5]) _rec->j = atoi((char*) dbrow[5]); else _rec->j = 0;
		if (dbrow[6]) _rec->k = atoi((char*) dbrow[6]); else _rec->k = 0;
		if (dbrow[7]) _rec->l = atoi((char*) dbrow[7]); else _rec->l = 0;
		if (dbrow[8]) _rec->m = atoi((char*) dbrow[8]); else _rec->m = 0;
		if (dbrow[9]) _rec->n = atoi((char*) dbrow[9]); else _rec->n = 0;
		if (dbrow[10]) _rec->refPlnrMArray = atoll((char*) dbrow[10]); else _rec->refPlnrMArray = 0;
		if (dbrow[11]) _rec->refPlnrMDesign = atoll((char*) dbrow[11]); else _rec->refPlnrMDesign = 0;
		if (dbrow[12]) _rec->dx = atof((char*) dbrow[12]); else _rec->dx = 0.0;
		if (dbrow[13]) _rec->dy = atof((char*) dbrow[13]); else _rec->dy = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQAriList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQAriList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQAriList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQAriList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->i = atoi((char*) dbrow[4]); else rec->i = 0;
			if (dbrow[5]) rec->j = atoi((char*) dbrow[5]); else rec->j = 0;
			if (dbrow[6]) rec->k = atoi((char*) dbrow[6]); else rec->k = 0;
			if (dbrow[7]) rec->l = atoi((char*) dbrow[7]); else rec->l = 0;
			if (dbrow[8]) rec->m = atoi((char*) dbrow[8]); else rec->m = 0;
			if (dbrow[9]) rec->n = atoi((char*) dbrow[9]); else rec->n = 0;
			if (dbrow[10]) rec->refPlnrMArray = atoll((char*) dbrow[10]); else rec->refPlnrMArray = 0;
			if (dbrow[11]) rec->refPlnrMDesign = atoll((char*) dbrow[11]); else rec->refPlnrMDesign = 0;
			if (dbrow[12]) rec->dx = atof((char*) dbrow[12]); else rec->dx = 0.0;
			if (dbrow[13]) rec->dy = atof((char*) dbrow[13]); else rec->dy = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQAriList::insertRec(
			PlnrQAriList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->i,&(l[3]),&(n[3]),&(e[3])),
		bindUsmallint(&rec->j,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->k,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->l,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->m,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->n,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refPlnrMArray,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refPlnrMDesign,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->dx,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->dy,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQAriList::insertRst(
			ListPlnrQAriList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQAriList::updateRec(
			PlnrQAriList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUsmallint(&rec->i,&(l[3]),&(n[3]),&(e[3])), 
		bindUsmallint(&rec->j,&(l[4]),&(n[4]),&(e[4])), 
		bindUsmallint(&rec->k,&(l[5]),&(n[5]),&(e[5])), 
		bindUsmallint(&rec->l,&(l[6]),&(n[6]),&(e[6])), 
		bindUsmallint(&rec->m,&(l[7]),&(n[7]),&(e[7])), 
		bindUsmallint(&rec->n,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->refPlnrMArray,&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[10]),&(n[10]),&(e[10])), 
		bindDouble(&rec->dx,&(l[11]),&(n[11]),&(e[11])), 
		bindDouble(&rec->dy,&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriList / stmtUpdateRec)\n");
};

void MyTblPlnrQAriList::updateRst(
			ListPlnrQAriList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQAriList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQAriList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQAriList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQAriList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQAriList::loadRecByQref(
			ubigint qref
			, PlnrQAriList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQAriList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQAriList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQAriList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQAriList
 ******************************************************************************/

PgTblPlnrQAriList::PgTblPlnrQAriList() : TblPlnrQAriList(), PgTable() {
};

PgTblPlnrQAriList::~PgTblPlnrQAriList() {
};

void PgTblPlnrQAriList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQAriList_insertRec", "INSERT INTO TblPlnrQAriList (jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, refPlnrMDesign, dx, dy) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriList_updateRec", "UPDATE TblPlnrQAriList SET jref = $1, jnum = $2, ref = $3, i = $4, j = $5, k = $6, l = $7, m = $8, n = $9, refPlnrMArray = $10, refPlnrMDesign = $11, dx = $12, dy = $13 WHERE qref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriList_removeRecByQref", "DELETE FROM TblPlnrQAriList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriList_removeRstByJref", "DELETE FROM TblPlnrQAriList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQAriList_loadRecByQref", "SELECT qref, jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, refPlnrMDesign, dx, dy FROM TblPlnrQAriList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQAriList_loadRstByJref", "SELECT qref, jref, jnum, ref, i, j, k, l, m, n, refPlnrMArray, refPlnrMDesign, dx, dy FROM TblPlnrQAriList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQAriList::loadRec(
			PGresult* res
			, PlnrQAriList** rec
		) {
	char* ptr;

	PlnrQAriList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQAriList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->i = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->j = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->k = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->l = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->m = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->n = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refPlnrMArray = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->dy = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQAriList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQAriList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQAriList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "i"),
			PQfnumber(res, "j"),
			PQfnumber(res, "k"),
			PQfnumber(res, "l"),
			PQfnumber(res, "m"),
			PQfnumber(res, "n"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy")
		};

		while (numread < numrow) {
			rec = new PlnrQAriList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->i = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->j = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->k = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->l = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->m = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->n = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refPlnrMArray = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->dy = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQAriList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQAriList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQAriList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQAriList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQAriList::loadRecBySQL(
			const string& sqlstr
			, PlnrQAriList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQAriList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQAriList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQAriList::insertRec(
			PlnrQAriList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	usmallint _i = htons(rec->i);
	usmallint _j = htons(rec->j);
	usmallint _k = htons(rec->k);
	usmallint _l = htons(rec->l);
	usmallint _m = htons(rec->m);
	usmallint _n = htons(rec->n);
	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_i,
		(char*) &_j,
		(char*) &_k,
		(char*) &_l,
		(char*) &_m,
		(char*) &_n,
		(char*) &_refPlnrMArray,
		(char*) &_refPlnrMDesign,
		_dx.c_str(),
		_dy.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQAriList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQAriList::insertRst(
			ListPlnrQAriList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQAriList::updateRec(
			PlnrQAriList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	usmallint _i = htons(rec->i);
	usmallint _j = htons(rec->j);
	usmallint _k = htons(rec->k);
	usmallint _l = htons(rec->l);
	usmallint _m = htons(rec->m);
	usmallint _n = htons(rec->n);
	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_i,
		(char*) &_j,
		(char*) &_k,
		(char*) &_l,
		(char*) &_m,
		(char*) &_n,
		(char*) &_refPlnrMArray,
		(char*) &_refPlnrMDesign,
		_dx.c_str(),
		_dy.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQAriList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQAriList::updateRst(
			ListPlnrQAriList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQAriList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQAriList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQAriList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQAriList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQAriList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQAriList::loadRecByQref(
			ubigint qref
			, PlnrQAriList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQAriList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQAriList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQAriList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQAriList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

