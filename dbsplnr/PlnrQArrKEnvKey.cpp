/**
  * \file PlnrQArrKEnvKey.cpp
  * Dbs and XML wrapper for table TblPlnrQArrKEnvKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQArrKEnvKey.h"

/******************************************************************************
 class PlnrQArrKEnvKey
 ******************************************************************************/

PlnrQArrKEnvKey::PlnrQArrKEnvKey(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->klsNum = klsNum;
	this->Fixed = Fixed;
	this->yesnoFixed = yesnoFixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

void PlnrQArrKEnvKey::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQArrKEnvKey";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fix", yesnoFixed);
		writeString(wr, "srf", sref);
		writeString(wr, "avl", Avail);
		writeString(wr, "imp", Implied);
		writeString(wr, "tit", Title);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "yesnoFixed", yesnoFixed);
		writeString(wr, "sref", sref);
		writeString(wr, "Avail", Avail);
		writeString(wr, "Implied", Implied);
		writeString(wr, "Title", Title);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQArrKEnvKey
 ******************************************************************************/

ListPlnrQArrKEnvKey::ListPlnrQArrKEnvKey() {
};

ListPlnrQArrKEnvKey::ListPlnrQArrKEnvKey(
			const ListPlnrQArrKEnvKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQArrKEnvKey(*(src.nodes[i]));
};

ListPlnrQArrKEnvKey::~ListPlnrQArrKEnvKey() {
	clear();
};

void ListPlnrQArrKEnvKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQArrKEnvKey::size() const {
	return(nodes.size());
};

void ListPlnrQArrKEnvKey::append(
			PlnrQArrKEnvKey* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQArrKEnvKey& ListPlnrQArrKEnvKey::operator=(
			const ListPlnrQArrKEnvKey& src
		) {
	PlnrQArrKEnvKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQArrKEnvKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQArrKEnvKey::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQArrKEnvKey";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQArrKEnvKey
 ******************************************************************************/

TblPlnrQArrKEnvKey::TblPlnrQArrKEnvKey() {
};

TblPlnrQArrKEnvKey::~TblPlnrQArrKEnvKey() {
};

bool TblPlnrQArrKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrKEnvKey** rec
		) {
	return false;
};

ubigint TblPlnrQArrKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	return 0;
};

void TblPlnrQArrKEnvKey::insertRec(
			PlnrQArrKEnvKey* rec
		) {
};

ubigint TblPlnrQArrKEnvKey::insertNewRec(
			PlnrQArrKEnvKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQArrKEnvKey* _rec = NULL;

	_rec = new PlnrQArrKEnvKey(0, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQArrKEnvKey::appendNewRecToRst(
			ListPlnrQArrKEnvKey& rst
			, PlnrQArrKEnvKey** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint klsNum
			, const bool Fixed
			, const string yesnoFixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrQArrKEnvKey* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, klsNum, Fixed, yesnoFixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQArrKEnvKey::insertRst(
			ListPlnrQArrKEnvKey& rst
		) {
};

void TblPlnrQArrKEnvKey::updateRec(
			PlnrQArrKEnvKey* rec
		) {
};

void TblPlnrQArrKEnvKey::updateRst(
			ListPlnrQArrKEnvKey& rst
		) {
};

void TblPlnrQArrKEnvKey::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQArrKEnvKey::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQArrKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQArrKEnvKey** rec
		) {
	return false;
};

ubigint TblPlnrQArrKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQArrKEnvKey
 ******************************************************************************/

MyTblPlnrQArrKEnvKey::MyTblPlnrQArrKEnvKey() : TblPlnrQArrKEnvKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQArrKEnvKey::~MyTblPlnrQArrKEnvKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQArrKEnvKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQArrKEnvKey (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQArrKEnvKey SET jref = ?, jnum = ?, ref = ?, klsNum = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQArrKEnvKey WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQArrKEnvKey WHERE jref = ?", false);
};

bool MyTblPlnrQArrKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrKEnvKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQArrKEnvKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrKEnvKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQArrKEnvKey();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->klsNum = atol((char*) dbrow[4]); else _rec->klsNum = 0;
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

ubigint MyTblPlnrQArrKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQArrKEnvKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQArrKEnvKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQArrKEnvKey();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->klsNum = atol((char*) dbrow[4]); else rec->klsNum = 0;
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

void MyTblPlnrQArrKEnvKey::insertRec(
			PlnrQArrKEnvKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrKEnvKey / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrKEnvKey / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQArrKEnvKey::insertRst(
			ListPlnrQArrKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQArrKEnvKey::updateRec(
			PlnrQArrKEnvKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->klsNum,&(l[3]),&(n[3]),&(e[3])), 
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])), 
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrKEnvKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrKEnvKey / stmtUpdateRec)\n");
};

void MyTblPlnrQArrKEnvKey::updateRst(
			ListPlnrQArrKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQArrKEnvKey::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrKEnvKey / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrKEnvKey / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQArrKEnvKey::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQArrKEnvKey / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQArrKEnvKey / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQArrKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQArrKEnvKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQArrKEnvKey WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQArrKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQArrKEnvKey WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQArrKEnvKey
 ******************************************************************************/

PgTblPlnrQArrKEnvKey::PgTblPlnrQArrKEnvKey() : TblPlnrQArrKEnvKey(), PgTable() {
};

PgTblPlnrQArrKEnvKey::~PgTblPlnrQArrKEnvKey() {
};

void PgTblPlnrQArrKEnvKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_insertRec", "INSERT INTO TblPlnrQArrKEnvKey (jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_updateRec", "UPDATE TblPlnrQArrKEnvKey SET jref = $1, jnum = $2, ref = $3, klsNum = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE qref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_removeRecByQref", "DELETE FROM TblPlnrQArrKEnvKey WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_removeRstByJref", "DELETE FROM TblPlnrQArrKEnvKey WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_loadRecByQref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrQArrKEnvKey WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQArrKEnvKey_loadRstByJref", "SELECT qref, jref, jnum, ref, klsNum, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblPlnrQArrKEnvKey WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQArrKEnvKey::loadRec(
			PGresult* res
			, PlnrQArrKEnvKey** rec
		) {
	char* ptr;

	PlnrQArrKEnvKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQArrKEnvKey();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->klsNum = atol(ptr);
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

ubigint PgTblPlnrQArrKEnvKey::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQArrKEnvKey* rec;

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
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrQArrKEnvKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->klsNum = atol(ptr);
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

bool PgTblPlnrQArrKEnvKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQArrKEnvKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrKEnvKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQArrKEnvKey::loadRecBySQL(
			const string& sqlstr
			, PlnrQArrKEnvKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQArrKEnvKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQArrKEnvKey::insertRec(
			PlnrQArrKEnvKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQArrKEnvKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQArrKEnvKey::insertRst(
			ListPlnrQArrKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQArrKEnvKey::updateRec(
			PlnrQArrKEnvKey* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _klsNum = htonl(rec->klsNum);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_klsNum,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrQArrKEnvKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQArrKEnvKey::updateRst(
			ListPlnrQArrKEnvKey& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQArrKEnvKey::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrKEnvKey_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQArrKEnvKey::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQArrKEnvKey_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQArrKEnvKey_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQArrKEnvKey::loadRecByQref(
			ubigint qref
			, PlnrQArrKEnvKey** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQArrKEnvKey_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQArrKEnvKey::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQArrKEnvKey& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQArrKEnvKey_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

