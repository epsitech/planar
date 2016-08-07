/**
  * \file PlnrQCliList.cpp
  * Dbs and XML wrapper for table TblPlnrQCliList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliList.h"

/******************************************************************************
 class PlnrQCliList
 ******************************************************************************/

PlnrQCliList::PlnrQCliList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint calRefPlnrMCalc
			, const string stubCalRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->calRefPlnrMCalc = calRefPlnrMCalc;
	this->stubCalRefPlnrMCalc = stubCalRefPlnrMCalc;
	this->refPlnrMDesign = refPlnrMDesign;
	this->stubRefPlnrMDesign = stubRefPlnrMDesign;
};

void PlnrQCliList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCliList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "cal", stubCalRefPlnrMCalc);
		writeString(wr, "dsn", stubRefPlnrMDesign);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubCalRefPlnrMCalc", stubCalRefPlnrMCalc);
		writeString(wr, "stubRefPlnrMDesign", stubRefPlnrMDesign);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCliList
 ******************************************************************************/

ListPlnrQCliList::ListPlnrQCliList() {
};

ListPlnrQCliList::ListPlnrQCliList(
			const ListPlnrQCliList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliList(*(src.nodes[i]));
};

ListPlnrQCliList::~ListPlnrQCliList() {
	clear();
};

void ListPlnrQCliList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCliList::size() const {
	return(nodes.size());
};

void ListPlnrQCliList::append(
			PlnrQCliList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCliList& ListPlnrQCliList::operator=(
			const ListPlnrQCliList& src
		) {
	PlnrQCliList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCliList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCliList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCliList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCliList
 ******************************************************************************/

TblPlnrQCliList::TblPlnrQCliList() {
};

TblPlnrQCliList::~TblPlnrQCliList() {
};

bool TblPlnrQCliList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliList** rec
		) {
	return false;
};

ubigint TblPlnrQCliList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliList& rst
		) {
	return 0;
};

void TblPlnrQCliList::insertRec(
			PlnrQCliList* rec
		) {
};

ubigint TblPlnrQCliList::insertNewRec(
			PlnrQCliList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint calRefPlnrMCalc
			, const string stubCalRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQCliList* _rec = NULL;

	_rec = new PlnrQCliList(0, jref, jnum, ref, Title, calRefPlnrMCalc, stubCalRefPlnrMCalc, refPlnrMDesign, stubRefPlnrMDesign);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCliList::appendNewRecToRst(
			ListPlnrQCliList& rst
			, PlnrQCliList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint calRefPlnrMCalc
			, const string stubCalRefPlnrMCalc
			, const ubigint refPlnrMDesign
			, const string stubRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQCliList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, calRefPlnrMCalc, stubCalRefPlnrMCalc, refPlnrMDesign, stubRefPlnrMDesign);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCliList::insertRst(
			ListPlnrQCliList& rst
		) {
};

void TblPlnrQCliList::updateRec(
			PlnrQCliList* rec
		) {
};

void TblPlnrQCliList::updateRst(
			ListPlnrQCliList& rst
		) {
};

void TblPlnrQCliList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCliList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCliList::loadRecByQref(
			ubigint qref
			, PlnrQCliList** rec
		) {
	return false;
};

ubigint TblPlnrQCliList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCliList
 ******************************************************************************/

MyTblPlnrQCliList::MyTblPlnrQCliList() : TblPlnrQCliList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCliList::~MyTblPlnrQCliList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCliList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCliList (jref, jnum, ref, Title, calRefPlnrMCalc, refPlnrMDesign) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCliList SET jref = ?, jnum = ?, ref = ?, Title = ?, calRefPlnrMCalc = ?, refPlnrMDesign = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCliList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCliList WHERE jref = ?", false);
};

bool MyTblPlnrQCliList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCliList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCliList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->calRefPlnrMCalc = atoll((char*) dbrow[5]); else _rec->calRefPlnrMCalc = 0;
		if (dbrow[6]) _rec->refPlnrMDesign = atoll((char*) dbrow[6]); else _rec->refPlnrMDesign = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCliList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCliList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCliList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->calRefPlnrMCalc = atoll((char*) dbrow[5]); else rec->calRefPlnrMCalc = 0;
			if (dbrow[6]) rec->refPlnrMDesign = atoll((char*) dbrow[6]); else rec->refPlnrMDesign = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCliList::insertRec(
			PlnrQCliList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->calRefPlnrMCalc,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refPlnrMDesign,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCliList::insertRst(
			ListPlnrQCliList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCliList::updateRec(
			PlnrQCliList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->calRefPlnrMCalc,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliList / stmtUpdateRec)\n");
};

void MyTblPlnrQCliList::updateRst(
			ListPlnrQCliList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCliList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCliList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCliList::loadRecByQref(
			ubigint qref
			, PlnrQCliList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCliList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCliList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCliList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCliList
 ******************************************************************************/

PgTblPlnrQCliList::PgTblPlnrQCliList() : TblPlnrQCliList(), PgTable() {
};

PgTblPlnrQCliList::~PgTblPlnrQCliList() {
};

void PgTblPlnrQCliList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCliList_insertRec", "INSERT INTO TblPlnrQCliList (jref, jnum, ref, Title, calRefPlnrMCalc, refPlnrMDesign) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliList_updateRec", "UPDATE TblPlnrQCliList SET jref = $1, jnum = $2, ref = $3, Title = $4, calRefPlnrMCalc = $5, refPlnrMDesign = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliList_removeRecByQref", "DELETE FROM TblPlnrQCliList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliList_removeRstByJref", "DELETE FROM TblPlnrQCliList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCliList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, calRefPlnrMCalc, refPlnrMDesign FROM TblPlnrQCliList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, calRefPlnrMCalc, refPlnrMDesign FROM TblPlnrQCliList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCliList::loadRec(
			PGresult* res
			, PlnrQCliList** rec
		) {
	char* ptr;

	PlnrQCliList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCliList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "calrefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->calRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refPlnrMDesign = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCliList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCliList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCliList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "calrefplnrmcalc"),
			PQfnumber(res, "refplnrmdesign")
		};

		while (numread < numrow) {
			rec = new PlnrQCliList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->calRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refPlnrMDesign = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCliList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCliList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCliList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCliList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCliList::insertRec(
			PlnrQCliList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _calRefPlnrMCalc = htonl64(rec->calRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_calRefPlnrMCalc,
		(char*) &_refPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCliList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCliList::insertRst(
			ListPlnrQCliList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCliList::updateRec(
			PlnrQCliList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _calRefPlnrMCalc = htonl64(rec->calRefPlnrMCalc);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_calRefPlnrMCalc,
		(char*) &_refPlnrMDesign,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCliList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCliList::updateRst(
			ListPlnrQCliList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCliList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCliList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCliList::loadRecByQref(
			ubigint qref
			, PlnrQCliList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCliList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCliList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCliList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

