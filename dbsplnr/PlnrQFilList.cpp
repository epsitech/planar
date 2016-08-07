/**
  * \file PlnrQFilList.cpp
  * Dbs and XML wrapper for table TblPlnrQFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQFilList.h"

/******************************************************************************
 class PlnrQFilList
 ******************************************************************************/

PlnrQFilList::PlnrQFilList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const uint Size
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Filename = Filename;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

void PlnrQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fnm", Filename);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "cnt", osrefKContent);
		writeString(wr, "cnt2", titOsrefKContent);
		writeString(wr, "mim", srefKMimetype);
		writeString(wr, "mim2", titSrefKMimetype);
		writeUint(wr, "siz", Size);
	} else {
		writeString(wr, "Filename", Filename);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "osrefKContent", osrefKContent);
		writeString(wr, "titOsrefKContent", titOsrefKContent);
		writeString(wr, "srefKMimetype", srefKMimetype);
		writeString(wr, "titSrefKMimetype", titSrefKMimetype);
		writeUint(wr, "Size", Size);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQFilList
 ******************************************************************************/

ListPlnrQFilList::ListPlnrQFilList() {
};

ListPlnrQFilList::ListPlnrQFilList(
			const ListPlnrQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilList(*(src.nodes[i]));
};

ListPlnrQFilList::~ListPlnrQFilList() {
	clear();
};

void ListPlnrQFilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQFilList::size() const {
	return(nodes.size());
};

void ListPlnrQFilList::append(
			PlnrQFilList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQFilList& ListPlnrQFilList::operator=(
			const ListPlnrQFilList& src
		) {
	PlnrQFilList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQFilList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQFilList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQFilList
 ******************************************************************************/

TblPlnrQFilList::TblPlnrQFilList() {
};

TblPlnrQFilList::~TblPlnrQFilList() {
};

bool TblPlnrQFilList::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilList** rec
		) {
	return false;
};

ubigint TblPlnrQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilList& rst
		) {
	return 0;
};

void TblPlnrQFilList::insertRec(
			PlnrQFilList* rec
		) {
};

ubigint TblPlnrQFilList::insertNewRec(
			PlnrQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const uint Size
		) {
	ubigint retval = 0;
	PlnrQFilList* _rec = NULL;

	_rec = new PlnrQFilList(0, jref, jnum, ref, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQFilList::appendNewRecToRst(
			ListPlnrQFilList& rst
			, PlnrQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const uint Size
		) {
	ubigint retval = 0;
	PlnrQFilList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQFilList::insertRst(
			ListPlnrQFilList& rst
		) {
};

void TblPlnrQFilList::updateRec(
			PlnrQFilList* rec
		) {
};

void TblPlnrQFilList::updateRst(
			ListPlnrQFilList& rst
		) {
};

void TblPlnrQFilList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQFilList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQFilList::loadRecByQref(
			ubigint qref
			, PlnrQFilList** rec
		) {
	return false;
};

ubigint TblPlnrQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQFilList
 ******************************************************************************/

MyTblPlnrQFilList::MyTblPlnrQFilList() : TblPlnrQFilList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQFilList::~MyTblPlnrQFilList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQFilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQFilList (jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQFilList SET jref = ?, jnum = ?, ref = ?, Filename = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, srefKMimetype = ?, Size = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQFilList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQFilList WHERE jref = ?", false);
};

bool MyTblPlnrQFilList::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQFilList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQFilList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQFilList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Filename.assign(dbrow[4], dblengths[4]); else _rec->Filename = "";
		if (dbrow[5]) _rec->refIxVTbl = atol((char*) dbrow[5]); else _rec->refIxVTbl = 0;
		if (dbrow[6]) _rec->refUref = atoll((char*) dbrow[6]); else _rec->refUref = 0;
		if (dbrow[7]) _rec->osrefKContent.assign(dbrow[7], dblengths[7]); else _rec->osrefKContent = "";
		if (dbrow[8]) _rec->srefKMimetype.assign(dbrow[8], dblengths[8]); else _rec->srefKMimetype = "";
		if (dbrow[9]) _rec->Size = atol((char*) dbrow[9]); else _rec->Size = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQFilList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQFilList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQFilList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Filename.assign(dbrow[4], dblengths[4]); else rec->Filename = "";
			if (dbrow[5]) rec->refIxVTbl = atol((char*) dbrow[5]); else rec->refIxVTbl = 0;
			if (dbrow[6]) rec->refUref = atoll((char*) dbrow[6]); else rec->refUref = 0;
			if (dbrow[7]) rec->osrefKContent.assign(dbrow[7], dblengths[7]); else rec->osrefKContent = "";
			if (dbrow[8]) rec->srefKMimetype.assign(dbrow[8], dblengths[8]); else rec->srefKMimetype = "";
			if (dbrow[9]) rec->Size = atol((char*) dbrow[9]); else rec->Size = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQFilList::insertRec(
			PlnrQFilList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Filename.length();
	l[6] = rec->osrefKContent.length();
	l[7] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->Size,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQFilList::insertRst(
			ListPlnrQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQFilList::updateRec(
			PlnrQFilList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Filename.length();
	l[6] = rec->osrefKContent.length();
	l[7] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Filename.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUint(&rec->Size,&(l[8]),&(n[8]),&(e[8])), 
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilList / stmtUpdateRec)\n");
};

void MyTblPlnrQFilList::updateRst(
			ListPlnrQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQFilList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQFilList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQFilList::loadRecByQref(
			ubigint qref
			, PlnrQFilList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQFilList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQFilList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQFilList
 ******************************************************************************/

PgTblPlnrQFilList::PgTblPlnrQFilList() : TblPlnrQFilList(), PgTable() {
};

PgTblPlnrQFilList::~PgTblPlnrQFilList() {
};

void PgTblPlnrQFilList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQFilList_insertRec", "INSERT INTO TblPlnrQFilList (jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilList_updateRec", "UPDATE TblPlnrQFilList SET jref = $1, jnum = $2, ref = $3, Filename = $4, refIxVTbl = $5, refUref = $6, osrefKContent = $7, srefKMimetype = $8, Size = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilList_removeRecByQref", "DELETE FROM TblPlnrQFilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilList_removeRstByJref", "DELETE FROM TblPlnrQFilList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQFilList_loadRecByQref", "SELECT qref, jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblPlnrQFilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilList_loadRstByJref", "SELECT qref, jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblPlnrQFilList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQFilList::loadRec(
			PGresult* res
			, PlnrQFilList** rec
		) {
	char* ptr;

	PlnrQFilList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQFilList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->osrefKContent.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKMimetype.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Size = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQFilList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQFilList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQFilList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size")
		};

		while (numread < numrow) {
			rec = new PlnrQFilList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->osrefKContent.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKMimetype.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Size = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQFilList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQFilList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQFilList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQFilList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQFilList::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQFilList::insertRec(
			PlnrQFilList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Size = htonl(rec->Size);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Filename.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQFilList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQFilList::insertRst(
			ListPlnrQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQFilList::updateRec(
			PlnrQFilList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Size = htonl(rec->Size);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Filename.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQFilList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQFilList::updateRst(
			ListPlnrQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQFilList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQFilList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQFilList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQFilList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQFilList::loadRecByQref(
			ubigint qref
			, PlnrQFilList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQFilList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQFilList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

