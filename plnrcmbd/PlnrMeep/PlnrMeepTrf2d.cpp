/**
  * \file PlnrMeepTrf2d.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrMeepTrf2d.h"

DpchRetPlnr* PlnrMeepTrf2d::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrMeepTrf2d* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	bool anisomat = dpchinv->anisomat;
	double deltalam = dpchinv->deltalam;
	double dt = dpchinv->dt;
	bool lossmat = dpchinv->lossmat;
	string prefix = dpchinv->prefix;
	ubigint refPlnrMCalc = dpchinv->refPlnrMCalc;
	ubigint refPlnrMCalcitem = dpchinv->refPlnrMCalcitem;
	ubigint refRastfile = dpchinv->refRastfile;
	string srefDom = dpchinv->srefDom;
	string srefDomExc = dpchinv->srefDomExc;
	vector<string> srefsDomMon = dpchinv->srefsDomMon;
	vector<string> srefsDomSshot = dpchinv->srefsDomSshot;
	bool tm = dpchinv->tm;
	double tstop = dpchinv->tstop;

// IP run --- IBEGIN
	ostringstream sqlstr;
	ubigint ref;

	ubigint refBasedsn;
	PlnrMCalcitem* cli = NULL;

	map<string, string> env;

	double lam;

	PlnrMDomain* dom = NULL;

	unsigned int ixDom, ixExc;
	
	vector<unsigned int> icsMon;
	unsigned int ixMon;

	vector<unsigned int> icsSshot;
	vector<unsigned int> icsMonSshot;

	bool mon, sshot;

	double x, y, x0, x1, xy0, xy1, y0, y1, z0, z1;

	component meepSrccomp;
	double meepT0, meepDt, meepNextt, meepTstop;
	continuous_src_time meepContSrc(complex<double>(1.0, 0), 0.2, 0.0); // need to pre-initialize with something
	gaussian_src_time meepGaussSrc(1.0, 10.0, 5.0);

	map<unsigned int, vector<complex<double> >*> Exs;
	map<unsigned int, vector<complex<double> >*> Eys;

	vector<complex<double> > _Ex;
	vector<complex<double> > _Ey;

	vector<double> t;

	string tmpfile;

	unsigned int dimT, dimXY, dimZ;

	unsigned int dimlen, varlen;
	string axes;

	int cdfRoot, cdfDoms;
	int cdfDom;
	int cdfDimX, cdfDimY, cdfDimXY, cdfDimZ, cdfDimT;
	int cdfVar;

	int* dims = NULL;

	double* var = NULL;
	
	string s;
	bool found;

	ubigint refMpafile, refResfile;

	sqlstr.str(""); sqlstr << "SELECT refPlnrMDesign FROM TblPlnrMCalc WHERE ref = " << refPlnrMCalc;
	dbsplnr->loadUbigintBySQL(sqlstr.str(), refBasedsn);

	dbsplnr->tblplnrmcalcitem->loadRecByRef(refPlnrMCalcitem, &cli);

	// -- load calculation environment (mainly, lam)
	Env::setForCli(dbsplnr, env, refPlnrMCalc, refPlnrMCalcitem);
	lam = Env::getDoubleVal(env, "lam");

	// -- determine domain type
	sqlstr.str(""); sqlstr << "SELECT TblPlnrMDomain.ref FROM TblPlnrMDomain, TblPlnrMDesign, TblPlnrMCalc WHERE TblPlnrMDomain.dsnRefPlnrMDesign = TblPlnrMDesign.ref"
				<< " AND TblPlnrMDesign.ref = TblPlnrMCalc.refPlnrMDesign AND TblPlnrMCalc.ref = " << refPlnrMCalc << " AND TblPlnrMDomain.sref = '" << srefDom << "'";
	dbsplnr->loadUbigintBySQL(sqlstr.str(), ref);

	if (dbsplnr->tblplnrmdomain->loadRecByRef(ref, &dom)) {
		if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
			// -- obtain n,k
cout << "invoking ZcsboxrastMeep constructor..." << endl;
			ZcsboxrastMeep rast(dbsplnr, xchg->acvpath, env, refBasedsn, cli->refPlnrMDesign, refRastfile, srefDom, lam, anisomat, lossmat);
cout << "ZcsboxrastMeep constructed." << endl;

			// -- retrieve main simulation domain
			rast.getDomIx(srefDom, ixDom);

			// -- retrieve other domains
			rast.getDomIx(srefDomExc, ixExc);

			for (unsigned int i=0;i<srefsDomMon.size();i++) {
				rast.getDomIx(srefsDomMon[i], ixMon);
				icsMon.push_back(ixMon);

				Exs[ixMon] = new vector<complex<double> >;
				Eys[ixMon] = new vector<complex<double> >;
			};

			for (unsigned int i=0;i<srefsDomSshot.size();i++) {
				rast.getDomIx(srefsDomSshot[i], ixMon);
				icsSshot.push_back(ixMon);
			};

			icsMonSshot = icsMon;
			for (unsigned int i=0;i<icsSshot.size();i++) {
				found = false;
				for (unsigned int j=0;j<icsMon.size();j++) {
					if (icsMon[j] == icsSshot[i]) {
						found = true;
						break;
					};
				};
				if (!found) icsMonSshot.push_back(icsSshot[i]);
			};

			// -- output refractive index and absorption coefficient
			if (anisomat) {
				tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "no");
				s = cli->Title + "_no.cdf";
				if (prefix.length() > 0) s = prefix + "_" + s;
				refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
				dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);

				tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "ne");
				s = cli->Title + "_ne.cdf";
				if (prefix.length() > 0) s = prefix + "_" + s;
				refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
				dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);

			} else {
				tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "n");
				s = cli->Title + "_n.cdf";
				if (prefix.length() > 0) s = prefix + "_" + s;
				refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
				dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);
			};

			if (lossmat) {
				if (anisomat) {
					tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "ko");
					s = cli->Title + "_ko.cdf";
					if (prefix.length() > 0) s = prefix + "_" + s;
					refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
					dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);

					tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "ke");
					s = cli->Title + "_ke.cdf";
					if (prefix.length() > 0) s = prefix + "_" + s;
					refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
					dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);

				} else {
					tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "k");
					s = cli->Title + "_k.cdf";
					if (prefix.length() > 0) s = prefix + "_" + s;
					refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
					dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);
				};
			};

			// -- prepare FDTD simulation

			// initialize MEEP
			int argc = 0;
			char** argv = NULL;
			initialize mpi(argc, argv);

			xy0 = rast.domXy0[ixDom]; xy1 = rast.domXy1[ixDom];
			z0 = rast.domZ0[ixDom]; z1 = rast.domZ1[ixDom];

cout << "(xy0,z0)_dsn = (" << xy0 << "," << z0 << ")" << endl;
cout << "(xy1,z1)_dsn = (" << xy1 << "," << z1 << ")" << endl;

			grid_volume meepVol = vol2d(xy1-xy0, z1-z0, 1.0/(rast.domDxy[ixDom]));

			structure meepSru(meepVol, rast, pml(2.0));

///
/*
			vector<lorentzian_susceptibility*> suscs;
			lorentzian_susceptibility* susc = NULL;

			vector<ZcsboxrastMeep_susc*> rastSuscs;
			ZcsboxrastMeep_susc* rastSusc = NULL;
*/
cout << "rast.dispOmgs.size() = " << rast.dispOmgs.size() << endl;

			for (unsigned int i=0;i<rast.dispOmgs.size();i++) {

if (i == 0) {
	rast.dispOmgs[i] = sqrt(40.314);
	rast.dispGams[i] = rast.dispGams[i];
	rast.dispSigs[i] = 1.0;
};


cout << "generating lorentzian_susceptibility with omega0=" << rast.dispOmgs[i] << " and gam=" << rast.dispGams[i] << endl;
/*
				susc = new lorentzian_susceptibility(rast.dispOmgs[i], rast.dispGams[i]);
				suscs.push_back(susc);

				rastSusc = new ZcsboxrastMeep_susc(&rast, i);
				rastSuscs.push_back(rastSusc);

				meepSru.add_susceptibility(*rastSusc, E_stuff, *susc);
*/
ZcsboxrastMeep_susc susc(&rast, i);
				meepSru.add_susceptibility(susc, E_stuff, lorentzian_susceptibility(rast.dispOmgs[i], rast.dispGams[i], (i==0)));
			};
///

			fields meepF(&meepSru);

			// TODO: scale source to 1W/m^2
			if (deltalam == 0.0) {
				meepContSrc = continuous_src_time(complex<double>(1.0/lam, 0), 0.2, 0.0);
			} else {
				// s = 5.0 implies that the peak amplitude is reached after 5.0*lam/c0 (this is symmetrical, so the decay takes the same amuont of time)
				meepGaussSrc = gaussian_src_time(1.0/lam, 1.0/deltalam, 5.0);
			};

			if (tm) {
				meepSrccomp = Hx;
			} else {
				meepSrccomp = Hz;
			};

			// as for source, distinguish line from point source
			if (rast.domIxVBasetype[ixExc] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
				x = rast.domA11[ixExc]*rast.domXy0[ixExc] + rast.domB1[ixExc];
				y = rast.domA21[ixExc]*rast.domXy0[ixExc] + rast.domB2[ixExc];
				rast.dsnToMeep(x, y, rast.domB3[ixExc], x0, y0);

				x = rast.domA11[ixExc]*rast.domXy1[ixExc] + rast.domB1[ixExc];
				y = rast.domA21[ixExc]*rast.domXy1[ixExc] + rast.domB2[ixExc];
				rast.dsnToMeep(x, y, rast.domB3[ixExc], x1, y1);

cout << "line source from (x0,y0)_meep = (" << x0 << "," << y0 << ") to (x1,y1)_meep = (" << x1 << "," << y1 << ")" << endl;

				if (deltalam == 0.0) {
//					meepF.add_volume_source(meepSrccomp, meepContSrc, volume(vec(x0, y0), vec(x1, y1)));
				} else {
//					meepF.add_volume_source(meepSrccomp, meepGaussSrc, volume(vec(x0, y0), vec(x1, y1)));
				};

			} else if (rast.domIxVBasetype[ixExc] == VecPlnrVMDomainBasetype::POINT_XYZ) {
				rast.dsnToMeep(rast.domB1[ixExc], rast.domB2[ixExc], rast.domB3[ixExc], x, y);

				if (deltalam == 0.0) {
//					meepF.add_point_source(meepSrccomp, meepContSrc, vec(x, y));
				} else {
//					meepF.add_point_source(meepSrccomp, meepGaussSrc, vec(x, y));
				};
			};

			// -- run FDTD simulation and monitor
			if (deltalam != 0.0) while (meepF.time() < meepF.last_source_time()) meepF.step();

			meepT0 = meepF.time();
			meepTstop = meepF.time() + 1.0e-9 * tstop*c0/lam;
			meepDt = 1.0e-9 * dt*c0/lam;
			meepNextt = meepT0;

			while (meepF.time() < meepTstop) {
				if (meepF.time() >= meepNextt) {
					t.push_back((meepF.time() - meepT0) * 1.0e9 * lam/c0);

					for (unsigned int i=0;i<icsMon.size();i++) {
						ixMon = icsMon[i];
						getMonExEy(meepF, rast, ixMon, true, Exs[ixMon], Eys[ixMon]);
					};

					meepNextt += meepDt;
				};

				meepF.step();
			};

			dimT = t.size();

			// -- write result file

			// create and open cdf file
			tmpfile = Tmp::newfile(xchg->tmppath, "cdf");
			tmpfile = xchg->tmppath + "/" + tmpfile;

			nc_create(tmpfile.c_str(), NC_NETCDF4, &cdfRoot);
			nc_def_grp(cdfRoot, "doms", &cdfDoms);

			// set up cdf file
			nc_enddef(cdfRoot);

			for (unsigned int i=0;i<icsMonSshot.size();i++) {
				ixMon = icsMonSshot[i];

				dimXY = rast.domDimXY[ixMon];
				dimZ = rast.domDimZ[ixMon];

				mon = false;
				for (unsigned int j=0;j<icsMon.size();j++) {
					if (icsMon[j] == ixMon) {
						mon = true;
						break;
					};
				};

				sshot = false;
				for (unsigned int j=0;j<icsSshot.size();j++) {
					if (icsSshot[j] == ixMon) {
						sshot = true;
						break;
					};
				};

				cdfDom = rast.domCdf(ixMon, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);

				if (mon) {
					// store monitoring video
					nc_redef(cdfRoot);
						// time dimension and vector (var)
						nc_def_dim(cdfDom, "dimT", dimT, &cdfDimT);

						dims = new int[1];
						var = new double[dimT];
						dims[0] = cdfDimT;
						nc_def_var(cdfDom, "t", NC_DOUBLE, 1, dims, &cdfVar);
						delete[] dims;

						s = "femtosecond";
						nc_put_att_text(cdfDom, cdfVar, "units", s.length(), s.c_str());
						s = "t [fs]";
						nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
						s = "time";
						nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
					nc_enddef(cdfRoot);

					for (unsigned int j=0;j<dimT;j++) var[j] = t[j];
					nc_put_var_double(cdfDom, cdfVar, var);

					delete[] var;

					for (unsigned int j=0;j<6;j++) {
						nc_redef(cdfRoot);
							// field vectors
							// Ex_re Ex_im Ex_sqr Ey_re Ey_im Ey_sqr

							if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
								dimlen = 3;
								axes = "xy,z,t";
								varlen = dimT * dimXY*dimZ;

								dims = new int[dimlen];
								dims[0] = cdfDimT;
								dims[1] = cdfDimXY;
								dims[2] = cdfDimZ;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
								dimlen = 2;
								axes = "xy,t";
								varlen = dimT * dimXY;

								dims = new int[dimlen];
								dims[0] = cdfDimT;
								dims[1] = cdfDimXY;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
								dimlen = 2;
								axes = "z,t";
								varlen = dimT * dimZ;

								dims = new int[dimlen];
								dims[0] = cdfDimT;
								dims[1] = cdfDimZ;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::POINT_XYZ) {
								dimlen = 1;
								axes = "t";
								varlen = dimT;

								dims = new int[dimlen];
								dims[0] = cdfDimT;
							};

							// define variable
							s = "E";
							if (j < 3) s = s + "xy"; else s = s + "z";

							if ((j%3) == 0) s = s + "_re";
							else if ((j%3) == 1) s = s + "_im";
							else s = s + "_sqr";

							nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, dimlen, dims, &cdfVar);

							delete[] dims;

							// set long name
							s = "E";
							if (j < 3) s = s + "x"; else s = s + "y";
							s = s + "(" + axes + ")";

							if ((j%3) == 0) s = "Re(" + s + ") [V/m]";
							else if ((j%3) == 1) s = "Im(" + s + ") [V/m]";
							else s = "|" + s + "|^2 [V^2/m^2]";

							nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());

							// set title
							s = "electric field, ";
							if (j < 3) s = s + "xy"; else s = s + "z";
							s = s + "-component ";

							if ((j%3) == 0) s = s + "real part";
							else if ((j%3) == 1) s = s + "imaginary part";
							else s = s + "absolute value squared";

							nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
						nc_enddef(cdfRoot);

						var = new double[varlen];

						if (j == 0) {
							for (unsigned int k=0;k<varlen;k++) var[k] = Exs[ixMon]->at(k).real();
						} else if (j == 1) {
							for (unsigned int k=0;k<varlen;k++) var[k] = Exs[ixMon]->at(k).imag();
						} else if (j == 2) {
							for (unsigned int k=0;k<varlen;k++) var[k] = norm(Exs[ixMon]->at(k));
						} else if (j == 3) {
							for (unsigned int k=0;k<varlen;k++) var[k] = Eys[ixMon]->at(k).real();
						} else if (j == 4) {
							for (unsigned int k=0;k<varlen;k++) var[k] = Eys[ixMon]->at(k).imag();
						} else if (j == 5) {
							for (unsigned int k=0;k<varlen;k++) var[k] = norm(Eys[ixMon]->at(k));
						};
						nc_put_var_double(cdfDom, cdfVar, var);

						delete[] var;
					};
				};

				if (sshot) {
					// -- obtain final field snapshot
					getMonExEy(meepF, rast, ixMon, false, &_Ex, &_Ey);

					// -- store final field snapshot
					for (unsigned int j=0;j<6;j++) {
						nc_redef(cdfRoot);
							// field vectors
							// Ex_fnl_re Ex_fnl_im Ex_fnl_sqr Ey_fnl_re Ey_fnl_im Ey_fnl_sqr

							if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
								dimlen = 2;
								axes = "xy,z";
								varlen = dimXY*dimZ;

								dims = new int[dimlen];
								dims[0] = cdfDimXY;
								dims[1] = cdfDimZ;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
								dimlen = 1;
								axes = "xy";
								varlen = dimXY;

								dims = new int[dimlen];
								dims[0] = cdfDimXY;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
								dimlen = 1;
								axes = "z";
								varlen = dimZ;

								dims = new int[dimlen];
								dims[0] = cdfDimZ;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::POINT_XYZ) {
								dimlen = 0;
								varlen = 1;
							};

							// define variable
							s = "E";
							if (j < 3) s = s + "xy"; else s = s + "z";
							s = s + "_fnl";

							if ((j%3) == 0) s = s + "_re";
							else if ((j%3) == 1) s = s + "_im";
							else s = s + "_sqr";

							if (dimlen == 0) {
								nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);
							} else {
								nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, dimlen, dims, &cdfVar);
								delete[] dims;
							};

							// set long name
							s = "E";
							if (j < 3) s = s + "x"; else s = s + "y";
							if (dimlen == 0) {
								s = s + "(tstop)";
							} else {
								s = s + "(" + axes + ",tstop)";
							};

							if ((j%3) == 0) s = "Re(" + s + ") [V/m]";
							else if ((j%3) == 1) s = "Im(" + s + ") [V/m]";
							else s = "|" + s + "|^2 [V^2/m^2]";

							nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());

							// set title
							s = "final electric field, ";
							if (j < 3) s = s + "xy"; else s = s + "z";
							s = s + "-component ";

							if ((j%3) == 0) s = s + "real part";
							else if ((j%3) == 1) s = s + "imaginary part";
							else s = s + "absolute value squared";

							nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
						nc_enddef(cdfRoot);

						var = new double[varlen];

						if (j == 0) {
							for (unsigned int k=0;k<varlen;k++) var[k] = _Ex[k].real();
						} else if (j == 1) {
							for (unsigned int k=0;k<varlen;k++) var[k] = _Ex[k].imag();
						} else if (j == 2) {
							for (unsigned int k=0;k<varlen;k++) var[k] = norm(_Ex[k]);
						} else if (j == 3) {
							for (unsigned int k=0;k<varlen;k++) var[k] = _Ey[k].real();
						} else if (j == 4) {
							for (unsigned int k=0;k<varlen;k++) var[k] = _Ey[k].imag();
						} else if (j == 5) {
							for (unsigned int k=0;k<varlen;k++) var[k] = norm(_Ey[k]);
						};
						nc_put_var_double(cdfDom, cdfVar, var);

						delete[] var;

						// calculate averages of squared fields
						if ((j == 2) || (j == 5)) {
							if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
								// averages over xy
								nc_redef(cdfRoot);
									s = "E";
									if (j == 2) s = s + "xy"; else s = s + "z";
									s = s + "_fnl_sqr_avgxy";

									dims = new int[1];
									dims[0] = cdfDimZ;
									nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
									delete[] dims;
								nc_enddef(cdfRoot);

								var = new double[dimZ];
								for (unsigned int l=0;l<dimZ;l++) var[l] = 0.0;
								if (j == 2) {
									for (unsigned int k=0;k<dimXY;k++) {
										for (unsigned int l=0;l<dimZ;l++) {
											var[l] += norm(_Ex[k*dimZ+l]);
										};
									};
								} else {
									for (unsigned int k=0;k<dimXY;k++) {
										for (unsigned int l=0;l<dimZ;l++) {
											var[l] += norm(_Ey[k*dimZ+l]);
										};
									};
								};
								for (unsigned int l=0;l<dimZ;l++) var[l] /= ((double) dimXY);
								nc_put_var_double(cdfDom, cdfVar, var);
								delete[] var;

								// averages over z
								nc_redef(cdfRoot);
									s = "E";
									if (j == 2) s = s + "xy"; else s = s + "z";
									s = s + "_fnl_sqr_avgz";

									dims = new int[1];
									dims[0] = cdfDimXY;
									nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
									delete[] dims;
								nc_enddef(cdfRoot);

								var = new double[dimXY];
								for (unsigned int k=0;k<dimXY;k++) var[k] = 0.0;
								if (j == 2) {
									for (unsigned int k=0;k<dimXY;k++) {
										for (unsigned int l=0;l<dimZ;l++) {
											var[k] += norm(_Ex[k*dimZ+l]);
										};
									};
								} else {
									for (unsigned int k=0;k<dimXY;k++) {
										for (unsigned int l=0;l<dimZ;l++) {
											var[k] += norm(_Ey[k*dimZ+l]);
										};
									};
								};
								for (unsigned int k=0;k<dimXY;k++) var[k] /= ((double) dimZ);
								nc_put_var_double(cdfDom, cdfVar, var);
								delete[] var;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
								// xy average
								nc_redef(cdfRoot);
									s = "E";
									if (j == 2) s = s + "xy"; else s = s + "z";
									s = s + "_fnl_sqr_avgxy";

									nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);
								nc_enddef(cdfRoot);

								var = new double[1];
								var[0] = 0.0;
								if (j == 2) {
									for (unsigned int k=0;k<dimXY;k++) var[0] += norm(_Ex[k]);
								} else {
									for (unsigned int k=0;k<dimXY;k++) var[0] += norm(_Ey[k]);
								};
								var[0] /= ((double) dimXY);
								nc_put_var_double(cdfDom, cdfVar, var);
								delete[] var;

							} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
								// z average
								nc_redef(cdfRoot);
									s = "E";
									if (j == 2) s = s + "xy"; else s = s + "z";
									s = s + "_fnl_sqr_avgz";

									nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);
								nc_enddef(cdfRoot);

								var = new double[1];
								var[0] = 0.0;
								if (j == 2) {
									for (unsigned int k=0;k<dimZ;k++) var[0] += norm(_Ex[k]);
								} else {
									for (unsigned int k=0;k<dimZ;k++) var[0] += norm(_Ey[k]);
								};
								var[0] /= ((double) dimZ);
								nc_put_var_double(cdfDom, cdfVar, var);
								delete[] var;
							};
						};
					};
				};
			};

			// -- store in archive
			nc_close(cdfRoot);

			s = cli->Title + "_res.cdf";
			if (prefix.length() > 0) s = prefix + "_" + s;
			refResfile = Acv::addfile(dbsplnr, xchg->acvpath, tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refResfile, VecPlnrVRMCalcMFileIo::OUT);

			// -- clean up
			for (unsigned int i=0;i<icsMon.size();i++) {
				ixMon = icsMon[i];

				delete Exs[ixMon];
				delete Eys[ixMon];
			};

///
/*
			for (unsigned int i=0;i<suscs.size();i++) delete suscs[i];
			suscs.resize(0);

			for (unsigned int i=0;i<rastSuscs.size();i++) delete rastSuscs[i];
			rastSuscs.resize(0);
*/
///

		} else {
			// TODO: XYBOX_XY, XYBOX_XYZ
		};

		delete dom;
	};

	delete cli;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrMeepTrf2d::getMonExEy(
			const fields& meepF
			, ZcsboxrastMeep& rast
			, const unsigned int ixMon
			, const bool append
			, vector<complex<double> >* _Ex
			, vector<complex<double> >* _Ey
		) {
	unsigned int dimXY, dimZ;
	unsigned int ix;
	double x, y, z, x0, y0, dxy, dz;

	if (!append) {
		_Ex->resize(0);
		_Ey->resize(0);
	};

	ix = _Ex->size();

	dimXY = rast.domDimXY[ixMon];
	dimZ = rast.domDimZ[ixMon];

	dxy = rast.domDxy[ixMon];
	dz = rast.domDz[ixMon];

	if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
		_Ex->resize(ix + dimXY*dimZ);
		_Ey->resize(ix + dimXY*dimZ);

		for (unsigned int k=0;k<dimXY;k++) {
			x = rast.domA11[ixMon]*(rast.domXy0[ixMon]+((double)k)*dxy) + rast.domB1[ixMon];
			y = rast.domA21[ixMon]*(rast.domXy0[ixMon]+((double)k)*dxy) + rast.domB2[ixMon];

			for (unsigned int l=0;l<dimZ;l++) {
				z = rast.domZ0[ixMon]+((double)l)*dz + rast.domB3[ixMon];

				rast.dsnToMeep(x, y, z, x0, y0);

				_Ex->at(ix) = meepF.get_field(Ex, vec(x0, y0));
				_Ey->at(ix) = meepF.get_field(Ey, vec(x0, y0));

				ix++;
			};
		};

	} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
		_Ex->resize(ix + dimXY);
		_Ey->resize(ix + dimXY);

		for (unsigned int k=0;k<dimXY;k++) {
			x = rast.domA11[ixMon]*(rast.domXy0[ixMon]+((double)k)*dxy) + rast.domB1[ixMon];
			y = rast.domA21[ixMon]*(rast.domXy0[ixMon]+((double)k)*dxy) + rast.domB2[ixMon];

			rast.dsnToMeep(x, y, rast.domB3[ixMon], x0, y0);

			_Ex->at(ix) = meepF.get_field(Ex, vec(x0, y0));
			_Ey->at(ix) = meepF.get_field(Ey, vec(x0, y0));

			ix++;
		};

	} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
		_Ex->resize(ix + dimZ);
		_Ey->resize(ix + dimZ);

		for (unsigned int l=0;l<dimZ;l++) {
			z = rast.domZ0[ixMon]+((double)l)*dz + rast.domB3[ixMon];

			rast.dsnToMeep(rast.domB1[ixMon], rast.domB2[ixMon], z, x0, y0);

			_Ex->at(ix) = meepF.get_field(Ex, vec(x0, y0));
			_Ey->at(ix) = meepF.get_field(Ey, vec(x0, y0));

			ix++;
		};

	} else if (rast.domIxVBasetype[ixMon] == VecPlnrVMDomainBasetype::POINT_XYZ) {
		_Ex->resize(ix + 1);
		_Ey->resize(ix + 1);

		rast.dsnToMeep(rast.domB1[ixMon], rast.domB2[ixMon], rast.domB3[ixMon], x0, y0);

		_Ex->at(ix) = meepF.get_field(Ex, vec(x0, y0));
		_Ey->at(ix) = meepF.get_field(Ey, vec(x0, y0));
	};
};
// IP cust --- IEND


