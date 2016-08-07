/**
  * \file PlnrQCtpKEnvKey.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpKEnvKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpKEnvKey.h"

/******************************************************************************
 class PlnrQCtpKEnvKey
 ******************************************************************************/

PlnrQCtpKEnvKey::PlnrQCtpKEnvKey(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->klsNum = klsNum;
	this->sref = sref;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

void PlnrQCtpKEnvKey::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpKEnvKey";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCtpKEnvKey
 ******************************************************************************/

ListPlnrQCtpKEnvKey::ListPlnrQCtpKEnvKey() {
};

ListPlnrQCtpKEnvKey::ListPlnrQCtpKEnvKey(
			const ListPlnrQCtpKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpKEnvKey(*(src.nodes[i]));
};

ListPlnrQCtpKEnvKey::~ListPlnrQCtpKEnvKey() {
	clear();
};

void ListPlnrQCtpKEnvKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpKEnvKey::size() const {
	return(nodes.size());
};

void ListPlnrQCtpKEnvKey::append(
			PlnrQCtpKEnvKey* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpKEnvKey& ListPlnrQCtpKEnvKey::operator=(
			const ListPlnrQCtpKEnvKey& src
		) {
	PlnrQCtpKEnvKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpKEnvKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpKEnvKey::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpKEnvKey";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpKEnvKey
 ******************************************************************************/

TblPlnrQCtpKEnvKey::TblPlnrQCtpKEnvKey() {
};

TblPlnrQCtpKEnvKey::~TblPlnrQCtpKEnvKey() {
};

bool TblPlnrQCtpKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKEnvKey** rec
		) {
	return false;
};

ubigint TblPlnrQCtpKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	return 0;
};

void TblPlnrQCtpKEnvKey::insertRec(
			PlnrQCtpKEnvKey* rec
		) {
};

ubigint TblPlnrQCtpKEnvKey::insertNewRec(
			PlnrQCtpKEnvKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQCtpKEnvKey* _rec = NULL;

	_rec = new PlnrQCtpKEnvKey(0, jref, jnum, ref, klsNum, sref, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpKEnvKey::appendNewRecToRst(
			ListPlnrQCtpKEnvKey& rst
			, PlnrQCtpKEnvKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const string sref
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQCtpKEnvKey* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, klsNum, sref, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpKEnvKey::insertRst(
			ListPlnrQCtpKEnvKey& rst
		) {
};

void TblPlnrQCtpKEnvKey::updateRec(
			PlnrQCtpKEnvKey* rec
		) {
};

void TblPlnrQCtpKEnvKey::updateRst(
			ListPlnrQCtpKEnvKey& rst
		) {
};

void TblPlnrQCtpKEnvKey::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpKEnvKey::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQCtpKEnvKey** rec
		) {
	return false;
};

ubigint TblPlnrQCtpKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpKEnvKey
 ******************************************************************************/

MyTblPlnrQCtpKEnvKey::MyTblPlnrQCtpKEnvKey() : TblPlnrQCtpKEnvKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpKEnvKey::~MyTblPlnrQCtpKEnvKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpKEnvKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpKEnvKey (jref, jnum, ref, klsNum, sref, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpKEnvKey SET jref = ?, jnum = ?, ref = ?, klsNum = ?, sref = ?, refJ = ?, Title = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpKEnvKey WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpKEnvKey WHERE jref = ?", false);
};

bool MyTblPlnrQCtpKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKEnvKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpKEnvKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpKEnvKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpKEnvKey();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->klsNum = atol((char*) dbrow[4]); else _rec->klsNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refJ = atoll((char*) dbrow[6]); else _rec->refJ = 0;
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCtpKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpKEnvKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpKEnvKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpKEnvKey();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->klsNum = atol((char*) dbrow[4]); else rec->klsNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refJ = atoll((char*) dbrow[6]); else rec->refJ = 0;
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCtpKEnvKey::insertRec(
			PlnrQCtpKEnvKey* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKEnvKey / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKEnvKey / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpKEnvKey::insertRst(
			ListPlnrQCtpKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpKEnvKey::updateRec(
			PlnrQCtpKEnvKey* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[6] = rec->Title.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKEnvKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKEnvKey / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpKEnvKey::updateRst(
			ListPlnrQCtpKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpKEnvKey::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKEnvKey / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKEnvKey / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpKEnvKey::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpKEnvKey / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpKEnvKey / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQCtpKEnvKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpKEnvKey WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpKEnvKey WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpKEnvKey
 ******************************************************************************/

PgTblPlnrQCtpKEnvKey::PgTblPlnrQCtpKEnvKey() : TblPlnrQCtpKEnvKey(), PgTable() {
};

PgTblPlnrQCtpKEnvKey::~PgTblPlnrQCtpKEnvKey() {
};

void PgTblPlnrQCtpKEnvKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_insertRec", "INSERT INTO TblPlnrQCtpKEnvKey (jref, jnum, ref, klsNum, sref, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_updateRec", "UPDATE TblPlnrQCtpKEnvKey SET jref = $1, jnum = $2, ref = $3, klsNum = $4, sref = $5, refJ = $6, Title = $7, Comment = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_removeRecByQref", "DELETE FROM TblPlnrQCtpKEnvKey WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_removeRstByJref", "DELETE FROM TblPlnrQCtpKEnvKey WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_loadRecByQref", "SELECT qref, jref, jnum, ref, klsNum, sref, refJ, Title, Comment FROM TblPlnrQCtpKEnvKey WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpKEnvKey_loadRstByJref", "SELECT qref, jref, jnum, ref, klsNum, sref, refJ, Title, Comment FROM TblPlnrQCtpKEnvKey WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpKEnvKey::loadRec(
			PGresult* res
			, PlnrQCtpKEnvKey** rec
		) {
	char* ptr;

	PlnrQCtpKEnvKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpKEnvKey();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCtpKEnvKey::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpKEnvKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrQCtpKEnvKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCtpKEnvKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpKEnvKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpKEnvKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpKEnvKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpKEnvKey::insertRec(
			PlnrQCtpKEnvKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		rec->sref.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQCtpKEnvKey_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpKEnvKey::insertRst(
			ListPlnrQCtpKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpKEnvKey::updateRec(
			PlnrQCtpKEnvKey* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		rec->sref.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCtpKEnvKey_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpKEnvKey::updateRst(
			ListPlnrQCtpKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpKEnvKey::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpKEnvKey_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpKEnvKey::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpKEnvKey_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpKEnvKey_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQCtpKEnvKey** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpKEnvKey_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpKEnvKey& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpKEnvKey_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

