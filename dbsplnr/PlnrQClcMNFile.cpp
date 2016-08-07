/**
  * \file PlnrQClcMNFile.cpp
  * Dbs and XML wrapper for table TblPlnrQClcMNFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQClcMNFile.h"

/******************************************************************************
 class PlnrQClcMNFile
 ******************************************************************************/

PlnrQClcMNFile::PlnrQClcMNFile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->stubX1RefPlnrMCalcitem = stubX1RefPlnrMCalcitem;
	this->ixVIo = ixVIo;
	this->srefIxVIo = srefIxVIo;
	this->titIxVIo = titIxVIo;
};

void PlnrQClcMNFile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQClcMNFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "cli", stubX1RefPlnrMCalcitem);
		writeString(wr, "io", srefIxVIo);
		writeString(wr, "io2", titIxVIo);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubX1RefPlnrMCalcitem", stubX1RefPlnrMCalcitem);
		writeString(wr, "srefIxVIo", srefIxVIo);
		writeString(wr, "titIxVIo", titIxVIo);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQClcMNFile
 ******************************************************************************/

ListPlnrQClcMNFile::ListPlnrQClcMNFile() {
};

ListPlnrQClcMNFile::ListPlnrQClcMNFile(
			const ListPlnrQClcMNFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQClcMNFile(*(src.nodes[i]));
};

ListPlnrQClcMNFile::~ListPlnrQClcMNFile() {
	clear();
};

void ListPlnrQClcMNFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQClcMNFile::size() const {
	return(nodes.size());
};

void ListPlnrQClcMNFile::append(
			PlnrQClcMNFile* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQClcMNFile& ListPlnrQClcMNFile::operator=(
			const ListPlnrQClcMNFile& src
		) {
	PlnrQClcMNFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQClcMNFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQClcMNFile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQClcMNFile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQClcMNFile
 ******************************************************************************/

TblPlnrQClcMNFile::TblPlnrQClcMNFile() {
};

TblPlnrQClcMNFile::~TblPlnrQClcMNFile() {
};

bool TblPlnrQClcMNFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNFile** rec
		) {
	return false;
};

ubigint TblPlnrQClcMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	return 0;
};

void TblPlnrQClcMNFile::insertRec(
			PlnrQClcMNFile* rec
		) {
};

ubigint TblPlnrQClcMNFile::insertNewRec(
			PlnrQClcMNFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	ubigint retval = 0;
	PlnrQClcMNFile* _rec = NULL;

	_rec = new PlnrQClcMNFile(0, jref, jnum, mref, stubMref, ref, x1RefPlnrMCalcitem, stubX1RefPlnrMCalcitem, ixVIo, srefIxVIo, titIxVIo);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQClcMNFile::appendNewRecToRst(
			ListPlnrQClcMNFile& rst
			, PlnrQClcMNFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	ubigint retval = 0;
	PlnrQClcMNFile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1RefPlnrMCalcitem, stubX1RefPlnrMCalcitem, ixVIo, srefIxVIo, titIxVIo);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQClcMNFile::insertRst(
			ListPlnrQClcMNFile& rst
		) {
};

void TblPlnrQClcMNFile::updateRec(
			PlnrQClcMNFile* rec
		) {
};

void TblPlnrQClcMNFile::updateRst(
			ListPlnrQClcMNFile& rst
		) {
};

void TblPlnrQClcMNFile::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQClcMNFile::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQClcMNFile::loadRecByQref(
			ubigint qref
			, PlnrQClcMNFile** rec
		) {
	return false;
};

ubigint TblPlnrQClcMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQClcMNFile
 ******************************************************************************/

MyTblPlnrQClcMNFile::MyTblPlnrQClcMNFile() : TblPlnrQClcMNFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQClcMNFile::~MyTblPlnrQClcMNFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQClcMNFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQClcMNFile (jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQClcMNFile SET jref = ?, jnum = ?, mref = ?, ref = ?, x1RefPlnrMCalcitem = ?, ixVIo = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQClcMNFile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQClcMNFile WHERE jref = ?", false);
};

bool MyTblPlnrQClcMNFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQClcMNFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcMNFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQClcMNFile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[5]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[6]) _rec->ixVIo = atol((char*) dbrow[6]); else _rec->ixVIo = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQClcMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQClcMNFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQClcMNFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQClcMNFile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[5]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[6]) rec->ixVIo = atol((char*) dbrow[6]); else rec->ixVIo = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQClcMNFile::insertRec(
			PlnrQClcMNFile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVIo,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNFile / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNFile / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQClcMNFile::insertRst(
			ListPlnrQClcMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQClcMNFile::updateRec(
			PlnrQClcMNFile* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVIo,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNFile / stmtUpdateRec)\n");
};

void MyTblPlnrQClcMNFile::updateRst(
			ListPlnrQClcMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQClcMNFile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNFile / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNFile / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQClcMNFile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQClcMNFile / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQClcMNFile / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQClcMNFile::loadRecByQref(
			ubigint qref
			, PlnrQClcMNFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQClcMNFile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQClcMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQClcMNFile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQClcMNFile
 ******************************************************************************/

PgTblPlnrQClcMNFile::PgTblPlnrQClcMNFile() : TblPlnrQClcMNFile(), PgTable() {
};

PgTblPlnrQClcMNFile::~PgTblPlnrQClcMNFile() {
};

void PgTblPlnrQClcMNFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQClcMNFile_insertRec", "INSERT INTO TblPlnrQClcMNFile (jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNFile_updateRec", "UPDATE TblPlnrQClcMNFile SET jref = $1, jnum = $2, mref = $3, ref = $4, x1RefPlnrMCalcitem = $5, ixVIo = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNFile_removeRecByQref", "DELETE FROM TblPlnrQClcMNFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNFile_removeRstByJref", "DELETE FROM TblPlnrQClcMNFile WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQClcMNFile_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo FROM TblPlnrQClcMNFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQClcMNFile_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo FROM TblPlnrQClcMNFile WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQClcMNFile::loadRec(
			PGresult* res
			, PlnrQClcMNFile** rec
		) {
	char* ptr;

	PlnrQClcMNFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQClcMNFile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "ixvio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVIo = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQClcMNFile::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQClcMNFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "ixvio")
		};

		while (numread < numrow) {
			rec = new PlnrQClcMNFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVIo = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQClcMNFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQClcMNFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcMNFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQClcMNFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQClcMNFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQClcMNFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQClcMNFile::insertRec(
			PlnrQClcMNFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	uint _ixVIo = htonl(rec->ixVIo);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_ixVIo
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClcMNFile_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQClcMNFile::insertRst(
			ListPlnrQClcMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQClcMNFile::updateRec(
			PlnrQClcMNFile* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	uint _ixVIo = htonl(rec->ixVIo);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_ixVIo,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQClcMNFile_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQClcMNFile::updateRst(
			ListPlnrQClcMNFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQClcMNFile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNFile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQClcMNFile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQClcMNFile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQClcMNFile_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQClcMNFile::loadRecByQref(
			ubigint qref
			, PlnrQClcMNFile** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQClcMNFile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQClcMNFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQClcMNFile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQClcMNFile_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

