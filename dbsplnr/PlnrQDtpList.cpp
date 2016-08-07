/**
  * \file PlnrQDtpList.cpp
  * Dbs and XML wrapper for table TblPlnrQDtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDtpList.h"

/******************************************************************************
 class PlnrQDtpList
 ******************************************************************************/

PlnrQDtpList::PlnrQDtpList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const uint ixVAligntype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->supRefPlnrMDevice = supRefPlnrMDevice;
	this->stubSupRefPlnrMDevice = stubSupRefPlnrMDevice;
	this->ixVAligntype = ixVAligntype;
};

void PlnrQDtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDtpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sup", stubSupRefPlnrMDevice);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubSupRefPlnrMDevice", stubSupRefPlnrMDevice);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDtpList
 ******************************************************************************/

ListPlnrQDtpList::ListPlnrQDtpList() {
};

ListPlnrQDtpList::ListPlnrQDtpList(
			const ListPlnrQDtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDtpList(*(src.nodes[i]));
};

ListPlnrQDtpList::~ListPlnrQDtpList() {
	clear();
};

void ListPlnrQDtpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDtpList::size() const {
	return(nodes.size());
};

void ListPlnrQDtpList::append(
			PlnrQDtpList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDtpList& ListPlnrQDtpList::operator=(
			const ListPlnrQDtpList& src
		) {
	PlnrQDtpList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDtpList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDtpList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDtpList
 ******************************************************************************/

TblPlnrQDtpList::TblPlnrQDtpList() {
};

TblPlnrQDtpList::~TblPlnrQDtpList() {
};

bool TblPlnrQDtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpList** rec
		) {
	return false;
};

ubigint TblPlnrQDtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	return 0;
};

void TblPlnrQDtpList::insertRec(
			PlnrQDtpList* rec
		) {
};

ubigint TblPlnrQDtpList::insertNewRec(
			PlnrQDtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const uint ixVAligntype
		) {
	ubigint retval = 0;
	PlnrQDtpList* _rec = NULL;

	_rec = new PlnrQDtpList(0, jref, jnum, ref, sref, supRefPlnrMDevice, stubSupRefPlnrMDevice, ixVAligntype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDtpList::appendNewRecToRst(
			ListPlnrQDtpList& rst
			, PlnrQDtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint supRefPlnrMDevice
			, const string stubSupRefPlnrMDevice
			, const uint ixVAligntype
		) {
	ubigint retval = 0;
	PlnrQDtpList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, supRefPlnrMDevice, stubSupRefPlnrMDevice, ixVAligntype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDtpList::insertRst(
			ListPlnrQDtpList& rst
		) {
};

void TblPlnrQDtpList::updateRec(
			PlnrQDtpList* rec
		) {
};

void TblPlnrQDtpList::updateRst(
			ListPlnrQDtpList& rst
		) {
};

void TblPlnrQDtpList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDtpList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDtpList::loadRecByQref(
			ubigint qref
			, PlnrQDtpList** rec
		) {
	return false;
};

ubigint TblPlnrQDtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDtpList
 ******************************************************************************/

MyTblPlnrQDtpList::MyTblPlnrQDtpList() : TblPlnrQDtpList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDtpList::~MyTblPlnrQDtpList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDtpList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDtpList (jref, jnum, ref, sref, supRefPlnrMDevice, ixVAligntype) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDtpList SET jref = ?, jnum = ?, ref = ?, sref = ?, supRefPlnrMDevice = ?, ixVAligntype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDtpList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDtpList WHERE jref = ?", false);
};

bool MyTblPlnrQDtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDtpList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDtpList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->supRefPlnrMDevice = atoll((char*) dbrow[5]); else _rec->supRefPlnrMDevice = 0;
		if (dbrow[6]) _rec->ixVAligntype = atol((char*) dbrow[6]); else _rec->ixVAligntype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDtpList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDtpList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDtpList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->supRefPlnrMDevice = atoll((char*) dbrow[5]); else rec->supRefPlnrMDevice = 0;
			if (dbrow[6]) rec->ixVAligntype = atol((char*) dbrow[6]); else rec->ixVAligntype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDtpList::insertRec(
			PlnrQDtpList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->supRefPlnrMDevice,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVAligntype,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDtpList::insertRst(
			ListPlnrQDtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDtpList::updateRec(
			PlnrQDtpList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->supRefPlnrMDevice,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVAligntype,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpList / stmtUpdateRec)\n");
};

void MyTblPlnrQDtpList::updateRst(
			ListPlnrQDtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDtpList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDtpList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDtpList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDtpList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDtpList::loadRecByQref(
			ubigint qref
			, PlnrQDtpList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDtpList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDtpList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDtpList
 ******************************************************************************/

PgTblPlnrQDtpList::PgTblPlnrQDtpList() : TblPlnrQDtpList(), PgTable() {
};

PgTblPlnrQDtpList::~PgTblPlnrQDtpList() {
};

void PgTblPlnrQDtpList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDtpList_insertRec", "INSERT INTO TblPlnrQDtpList (jref, jnum, ref, sref, supRefPlnrMDevice, ixVAligntype) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpList_updateRec", "UPDATE TblPlnrQDtpList SET jref = $1, jnum = $2, ref = $3, sref = $4, supRefPlnrMDevice = $5, ixVAligntype = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpList_removeRecByQref", "DELETE FROM TblPlnrQDtpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpList_removeRstByJref", "DELETE FROM TblPlnrQDtpList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDtpList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, supRefPlnrMDevice, ixVAligntype FROM TblPlnrQDtpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDtpList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, supRefPlnrMDevice, ixVAligntype FROM TblPlnrQDtpList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDtpList::loadRec(
			PGresult* res
			, PlnrQDtpList** rec
		) {
	char* ptr;

	PlnrQDtpList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDtpList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "ixvaligntype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->supRefPlnrMDevice = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVAligntype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDtpList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDtpList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "suprefplnrmdevice"),
			PQfnumber(res, "ixvaligntype")
		};

		while (numread < numrow) {
			rec = new PlnrQDtpList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->supRefPlnrMDevice = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVAligntype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDtpList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDtpList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDtpList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDtpList::insertRec(
			PlnrQDtpList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	uint _ixVAligntype = htonl(rec->ixVAligntype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_supRefPlnrMDevice,
		(char*) &_ixVAligntype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDtpList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDtpList::insertRst(
			ListPlnrQDtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDtpList::updateRec(
			PlnrQDtpList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefPlnrMDevice = htonl64(rec->supRefPlnrMDevice);
	uint _ixVAligntype = htonl(rec->ixVAligntype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_supRefPlnrMDevice,
		(char*) &_ixVAligntype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDtpList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDtpList::updateRst(
			ListPlnrQDtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDtpList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDtpList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDtpList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDtpList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDtpList::loadRecByQref(
			ubigint qref
			, PlnrQDtpList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDtpList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDtpList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDtpList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

