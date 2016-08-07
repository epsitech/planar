/**
  * \file PlnrMPerson.cpp
  * database access for table TblPlnrMPerson (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMPerson.h"

/******************************************************************************
 class PlnrMPerson
 ******************************************************************************/

PlnrMPerson::PlnrMPerson(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixWDerivate = ixWDerivate;
	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->refJLastname = refJLastname;
	this->Lastname = Lastname;
	this->telRefADetail = telRefADetail;
	this->Tel = Tel;
	this->emlRefADetail = emlRefADetail;
	this->Eml = Eml;
	this->Salutation = Salutation;
};

bool PlnrMPerson::operator==(
			const PlnrMPerson& comp
		) {
	return false;
};

bool PlnrMPerson::operator!=(
			const PlnrMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMPerson
 ******************************************************************************/

ListPlnrMPerson::ListPlnrMPerson() {
};

ListPlnrMPerson::ListPlnrMPerson(
			const ListPlnrMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMPerson(*(src.nodes[i]));
};

ListPlnrMPerson::~ListPlnrMPerson() {
	clear();
};

void ListPlnrMPerson::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMPerson::size() const {
	return(nodes.size());
};

void ListPlnrMPerson::append(
			PlnrMPerson* rec
		) {
	nodes.push_back(rec);
};

PlnrMPerson* ListPlnrMPerson::operator[](
			const uint ix
		) {
	PlnrMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMPerson& ListPlnrMPerson::operator=(
			const ListPlnrMPerson& src
		) {
	PlnrMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMPerson::operator==(
			const ListPlnrMPerson& comp
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

bool ListPlnrMPerson::operator!=(
			const ListPlnrMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMPerson
 ******************************************************************************/

TblPlnrMPerson::TblPlnrMPerson() {
};

TblPlnrMPerson::~TblPlnrMPerson() {
};

bool TblPlnrMPerson::loadRecBySQL(
			const string& sqlstr
			, PlnrMPerson** rec
		) {
	return false;
};

ubigint TblPlnrMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMPerson& rst
		) {
	return 0;
};

void TblPlnrMPerson::insertRec(
			PlnrMPerson* rec
		) {
};

ubigint TblPlnrMPerson::insertNewRec(
			PlnrMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {
	ubigint retval = 0;
	PlnrMPerson* _rec = NULL;

	_rec = new PlnrMPerson(0, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMPerson::appendNewRecToRst(
			ListPlnrMPerson& rst
			, PlnrMPerson** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixWDerivate
			, const uint ixVSex
			, const string Title
			, const string Firstname
			, const ubigint refJLastname
			, const string Lastname
			, const ubigint telRefADetail
			, const string Tel
			, const ubigint emlRefADetail
			, const string Eml
			, const string Salutation
		) {
	ubigint retval = 0;
	PlnrMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMPerson::insertRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
};

void TblPlnrMPerson::updateRec(
			PlnrMPerson* rec
		) {
};

void TblPlnrMPerson::updateRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
};

void TblPlnrMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMPerson::loadRecByRef(
			ubigint ref
			, PlnrMPerson** rec
		) {
	return false;
};

ubigint TblPlnrMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMPerson& rst
		) {
	ubigint numload = 0;
	PlnrMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMPerson
 ******************************************************************************/

MyTblPlnrMPerson::MyTblPlnrMPerson() : TblPlnrMPerson(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMPerson::~MyTblPlnrMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMPerson SET grp = ?, own = ?, ixWDerivate = ?, ixVSex = ?, Title = ?, Firstname = ?, refJLastname = ?, Lastname = ?, telRefADetail = ?, Tel = ?, emlRefADetail = ?, Eml = ?, Salutation = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMPerson WHERE ref = ?", false);
};

bool MyTblPlnrMPerson::loadRecBySQL(
			const string& sqlstr
			, PlnrMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMPerson / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixWDerivate = atol((char*) dbrow[3]); else _rec->ixWDerivate = 0;
		if (dbrow[4]) _rec->ixVSex = atol((char*) dbrow[4]); else _rec->ixVSex = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Firstname.assign(dbrow[6], dblengths[6]); else _rec->Firstname = "";
		if (dbrow[7]) _rec->refJLastname = atoll((char*) dbrow[7]); else _rec->refJLastname = 0;
		if (dbrow[8]) _rec->Lastname.assign(dbrow[8], dblengths[8]); else _rec->Lastname = "";
		if (dbrow[9]) _rec->telRefADetail = atoll((char*) dbrow[9]); else _rec->telRefADetail = 0;
		if (dbrow[10]) _rec->Tel.assign(dbrow[10], dblengths[10]); else _rec->Tel = "";
		if (dbrow[11]) _rec->emlRefADetail = atoll((char*) dbrow[11]); else _rec->emlRefADetail = 0;
		if (dbrow[12]) _rec->Eml.assign(dbrow[12], dblengths[12]); else _rec->Eml = "";
		if (dbrow[13]) _rec->Salutation.assign(dbrow[13], dblengths[13]); else _rec->Salutation = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMPerson / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixWDerivate = atol((char*) dbrow[3]); else rec->ixWDerivate = 0;
			if (dbrow[4]) rec->ixVSex = atol((char*) dbrow[4]); else rec->ixVSex = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Firstname.assign(dbrow[6], dblengths[6]); else rec->Firstname = "";
			if (dbrow[7]) rec->refJLastname = atoll((char*) dbrow[7]); else rec->refJLastname = 0;
			if (dbrow[8]) rec->Lastname.assign(dbrow[8], dblengths[8]); else rec->Lastname = "";
			if (dbrow[9]) rec->telRefADetail = atoll((char*) dbrow[9]); else rec->telRefADetail = 0;
			if (dbrow[10]) rec->Tel.assign(dbrow[10], dblengths[10]); else rec->Tel = "";
			if (dbrow[11]) rec->emlRefADetail = atoll((char*) dbrow[11]); else rec->emlRefADetail = 0;
			if (dbrow[12]) rec->Eml.assign(dbrow[12], dblengths[12]); else rec->Eml = "";
			if (dbrow[13]) rec->Salutation.assign(dbrow[13], dblengths[13]); else rec->Salutation = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMPerson::insertRec(
			PlnrMPerson* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->Tel.length();
	l[11] = rec->Eml.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Tel.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Eml.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMPerson / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMPerson / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMPerson::insertRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMPerson::updateRec(
			PlnrMPerson* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[4] = rec->Title.length();
	l[5] = rec->Firstname.length();
	l[7] = rec->Lastname.length();
	l[9] = rec->Tel.length();
	l[11] = rec->Eml.length();
	l[12] = rec->Salutation.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixWDerivate,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixVSex,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Firstname.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->refJLastname,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindUbigint(&rec->telRefADetail,&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->Tel.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUbigint(&rec->emlRefADetail,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->Eml.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindCstring((char*) (rec->Salutation.c_str()),&(l[12]),&(n[12]),&(e[12])), 
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMPerson / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMPerson / stmtUpdateRec)\n");
};

void MyTblPlnrMPerson::updateRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMPerson / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMPerson / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMPerson::loadRecByRef(
			ubigint ref
			, PlnrMPerson** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMPerson WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMPerson
 ******************************************************************************/

PgTblPlnrMPerson::PgTblPlnrMPerson() : TblPlnrMPerson(), PgTable() {
};

PgTblPlnrMPerson::~PgTblPlnrMPerson() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMPerson::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMPerson_insertRec", "INSERT INTO TblPlnrMPerson (grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMPerson_updateRec", "UPDATE TblPlnrMPerson SET grp = $1, own = $2, ixWDerivate = $3, ixVSex = $4, Title = $5, Firstname = $6, refJLastname = $7, Lastname = $8, telRefADetail = $9, Tel = $10, emlRefADetail = $11, Eml = $12, Salutation = $13 WHERE ref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMPerson_removeRecByRef", "DELETE FROM TblPlnrMPerson WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMPerson_loadRecByRef", "SELECT ref, grp, own, ixWDerivate, ixVSex, Title, Firstname, refJLastname, Lastname, telRefADetail, Tel, emlRefADetail, Eml, Salutation FROM TblPlnrMPerson WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrMPerson::loadRec(
			PGresult* res
			, PlnrMPerson** rec
		) {
	char* ptr;

	PlnrMPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMPerson();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml"),
			PQfnumber(res, "salutation")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixWDerivate = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVSex = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Firstname.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJLastname = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->telRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Tel.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->emlRefADetail = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Eml.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Salutation.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMPerson::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMPerson* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixwderivate"),
			PQfnumber(res, "ixvsex"),
			PQfnumber(res, "title"),
			PQfnumber(res, "firstname"),
			PQfnumber(res, "refjlastname"),
			PQfnumber(res, "lastname"),
			PQfnumber(res, "telrefadetail"),
			PQfnumber(res, "tel"),
			PQfnumber(res, "emlrefadetail"),
			PQfnumber(res, "eml"),
			PQfnumber(res, "salutation")
		};

		while (numread < numrow) {
			rec = new PlnrMPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixWDerivate = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVSex = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Firstname.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJLastname = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->telRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Tel.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->emlRefADetail = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Eml.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Salutation.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMPerson / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMPerson::loadRecBySQL(
			const string& sqlstr
			, PlnrMPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMPerson::insertRec(
			PlnrMPerson* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str(),
		rec->Salutation.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMPerson_insertRec", 13, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMPerson_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMPerson::insertRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMPerson::updateRec(
			PlnrMPerson* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixWDerivate = htonl(rec->ixWDerivate);
	uint _ixVSex = htonl(rec->ixVSex);
	ubigint _refJLastname = htonl64(rec->refJLastname);
	ubigint _telRefADetail = htonl64(rec->telRefADetail);
	ubigint _emlRefADetail = htonl64(rec->emlRefADetail);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixWDerivate,
		(char*) &_ixVSex,
		rec->Title.c_str(),
		rec->Firstname.c_str(),
		(char*) &_refJLastname,
		rec->Lastname.c_str(),
		(char*) &_telRefADetail,
		rec->Tel.c_str(),
		(char*) &_emlRefADetail,
		rec->Eml.c_str(),
		rec->Salutation.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMPerson_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMPerson_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMPerson::updateRst(
			ListPlnrMPerson& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMPerson::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMPerson_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMPerson_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMPerson::loadRecByRef(
			ubigint ref
			, PlnrMPerson** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMPerson_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END
