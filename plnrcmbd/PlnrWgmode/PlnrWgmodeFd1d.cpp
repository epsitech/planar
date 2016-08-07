/**
  * \file PlnrWgmodeFd1d.cpp
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

#include "PlnrWgmodeFd1d.h"

DpchRetPlnrWgmodeFd1d* PlnrWgmodeFd1d::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrWgmodeFd1d* dpchinv
		) {
	DpchRetPlnrWgmodeFd1d* dpchret = new DpchRetPlnrWgmodeFd1d();

	bool lossmat = dpchinv->lossmat;
	string prefix = dpchinv->prefix;
	ubigint refPlnrMCalc = dpchinv->refPlnrMCalc;
	ubigint refPlnrMCalcitem = dpchinv->refPlnrMCalcitem;
	ubigint refRastfile = dpchinv->refRastfile;
	string srefDom = dpchinv->srefDom;
	vector<string> srefsDomEval = dpchinv->srefsDomEval;
	bool te = dpchinv->te;
	bool tm = dpchinv->tm;

// IP run --- IBEGIN
	ostringstream sqlstr;
	ubigint ref;

	ubigint refBasedsn;
	PlnrMCalcitem* cli = NULL;

	double lam;
	double dz;

	unsigned int ixDom;

	double x, y, z;
	vector<double> n;
	vector<double> k;

	map<string, string> env;

	Cubrast* cubrast = NULL;
	Xyboxrast* xyboxrast = NULL;
	Zlinerast* zlinerast = NULL;

	PlnrMDomain* dom = NULL;

	string trvaxis, gdaxis;

	string tmpfile;

	unsigned int NTE;

	vector<double> ixeffTE;
	vector<double> EyTE;
	vector<double> HzTE;
	vector<complex<double> > cIxeffTE;
	vector<complex<double> > cEyTE;
	vector<complex<double> > cHzTE;

	unsigned int NTM;

	vector<double> ixeffTM;
	vector<double> EzTM;
	vector<double> HyTM;
	vector<complex<double> > cIxeffTM;
	vector<complex<double> > cEzTM;
	vector<complex<double> > cHyTM;

	unsigned int dimGeo;

	int cdfRoot, cdfDoms;
	int cdfDom;
	int cdfDimX, cdfDimY, cdfDimXY, cdfDimZ, cdfDimGeo;
	int cdfDimTE, cdfDimTM;
	int cdfVar, cdfVar2, cdfVar3;

	int* dims = NULL;

	double* var;
	double* var2;
	double* var3;

	string s, s2, s3;

	ubigint refResfile;

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
		if ((dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY)) {
			// xyline: propagation in yx direction, z invariance; TE has Eyx, TM has Exy
			trvaxis = "yx";
			gdaxis = "xy";
		} else if ((dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z)) {
			// zline: propagation in x direction, y invariance; TE has Ey, TM has Ez
			trvaxis = "y";
			gdaxis = "z";
		};

		// -- obtain n,k
		if ((dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ)) {
			cubrast = new Cubrast(dbsplnr, xchg->acvpath, env, refBasedsn, cli->refPlnrMDesign, refRastfile, "phot;phot", "n;k");

			cubrast->getDomIx(srefDom, ixDom);

			if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
				dz = cubrast->domDxy[ixDom];

				n.resize(cubrast->domDimXY[ixDom]);
				k.resize(cubrast->domDimXY[ixDom]);

				z = cubrast->domB3[ixDom];
				for (unsigned int i=0;i<cubrast->domDimXY[ixDom];i++) {
					x = cubrast->domA11[ixDom]*(cubrast->domXy0[ixDom]+((double) i)*cubrast->domDxy[ixDom])+cubrast->domB1[ixDom];
					y = cubrast->domA21[ixDom]*(cubrast->domXy0[ixDom]+((double) i)*cubrast->domDxy[ixDom])+cubrast->domB2[ixDom];

					n[i] = cubrast->getMatpar(x, y, z, 0);
					k[i] = cubrast->getMatpar(x, y, z, 1);
				};

			} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
				dz = cubrast->domDz[ixDom];

				n.resize(cubrast->domDimZ[ixDom]);
				k.resize(cubrast->domDimZ[ixDom]);

				x = cubrast->domB1[ixDom];
				y = cubrast->domB2[ixDom];
				for (unsigned int i=0;i<cubrast->domDimZ[ixDom];i++) {
					z = cubrast->domZ0[ixDom]+((double) i)*cubrast->domDz[ixDom]+cubrast->domB3[ixDom];

					n[i] = cubrast->getMatpar(x, y, z, 0);
					k[i] = cubrast->getMatpar(x, y, z, 1);
				};
			};

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY) {
			xyboxrast = new Xyboxrast(dbsplnr, xchg->acvpath, env, refBasedsn, cli->refPlnrMDesign, refRastfile, "phot;phot", "n;k");

			xyboxrast->getDomIx(srefDom, ixDom);

			dz = xyboxrast->domDxy[ixDom];

			n.resize(xyboxrast->domDimXY[ixDom]);
			k.resize(xyboxrast->domDimXY[ixDom]);

			for (unsigned int i=0;i<xyboxrast->domDimXY[ixDom];i++) {
				x = xyboxrast->domA11[ixDom]*(xyboxrast->domXy0[ixDom]+((double) i)*xyboxrast->domDxy[ixDom])+xyboxrast->domB1[ixDom];
				y = xyboxrast->domA21[ixDom]*(xyboxrast->domXy0[ixDom]+((double) i)*xyboxrast->domDxy[ixDom])+xyboxrast->domB2[ixDom];

				n[i] = xyboxrast->getMatpar(x, y, 0);
				k[i] = xyboxrast->getMatpar(x, y, 1);
			};

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) {
			zlinerast = new Zlinerast(dbsplnr, xchg->acvpath, env, refBasedsn, cli->refPlnrMDesign, refRastfile, "phot;phot", "n;k");

			zlinerast->getDomIx(srefDom, ixDom);

			dz = zlinerast->domDz[ixDom];

			n.resize(zlinerast->domDimZ[ixDom]);
			k.resize(zlinerast->domDimZ[ixDom]);

			for (unsigned int i=0;i<zlinerast->domDimZ[ixDom];i++) {
				z = zlinerast->domZ0[ixDom]+((double) i)*zlinerast->domDz[ixDom]+zlinerast->domB3[ixDom];

				n[i] = zlinerast->getMatpar(z, 0);
				k[i] = zlinerast->getMatpar(z, 1);
			};
		};

		// -- perform calculation
		if (lossmat) {
			calcLossmat(n, k, lam, dz, te, tm, NTE, cIxeffTE, cEyTE, cHzTE, NTM, cIxeffTM, cEzTM, cHyTM);
		} else {
			calcNolossmat(n, lam, dz, te, tm, NTE, ixeffTE, EyTE, HzTE, NTM, ixeffTM, EzTM, HyTM);
		};

		// -- write result file

		// dimensions dimTE, dimTM
		// index variables neffTE, keffTE, neffTM, keffTM (dimTE / dimTM)
		// mode pattern variables for TE: EyTE_re, EyTE_im, Ey_sqr, HzTE_re, HzTE_im (dimTE x dimZ[dimXY])
		// mode pattern variables for TM: EzTM_re, EzTM_im, Ez_sqr, HyTM_re, HyTM_im (dimTM x dimZ[dimXY])
		// zline: propagation in y direction, x invariance; TE has Ey, TM has Ez
		// xyline: propagation in yx direction, z invariance; TE has Eyx, TM has Exy

		// create and open cdf file
		tmpfile = Tmp::newfile(xchg->tmppath, "cdf");
		tmpfile = xchg->tmppath + "/" + tmpfile;

		nc_create(tmpfile.c_str(), NC_NETCDF4, &cdfRoot);
		nc_def_grp(cdfRoot, "doms", &cdfDoms);

		// set up cdf file
		nc_enddef(cdfRoot);

		if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
			cdfDom = cubrast->domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimGeo, cdfDimZ);
			dimGeo = cubrast->domDimXY[ixDom];

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
			cdfDom = cubrast->domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimGeo);
			dimGeo = cubrast->domDimZ[ixDom];

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY) {
			cdfDom = xyboxrast->domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimGeo);
			dimGeo = xyboxrast->domDimXY[ixDom];

		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) {
			cdfDom = zlinerast->domCdf(ixDom, cdfDoms, cdfDimGeo);
			dimGeo = zlinerast->domDimZ[ixDom];
		};

		// add TE and TM domains
		nc_redef(cdfRoot);
			if (te && (NTE > 0)) nc_def_dim(cdfDom, "dimTE", NTE, &cdfDimTE);
			if (tm && (NTM > 0)) nc_def_dim(cdfDom, "dimTM", NTM, &cdfDimTM);
		nc_enddef(cdfRoot);

		for (unsigned int j=0;j<4;j++) {
			// j == 0: TE, re
			// j == 1: TE, im
			// j == 2: TM, re
			// j == 3: TM, im

			if ( ((j < 2) && te && (NTE > 0)) || ((j >= 2) && tm && (NTM > 0)) ) {
				if ( ((j%2) == 0) || (((j%2) == 1) && lossmat) ) {

					// variables with dimension dimTE/dimTM
					nc_redef(cdfRoot);

					dims = new int[1];
					if (j < 2) {
						var = new double[NTE];
						dims[0] = cdfDimTE;
					} else {
						var = new double[NTM];
						dims[0] = cdfDimTM;
					};

					if ((j%2) == 0) s = "neff"; else s = "keff";
					if (j < 2) s = s + "TE"; else s = s + "TM";

					nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 1, dims, &cdfVar);

					if (j < 2) s = "TE mode "; else s = "TM mode ";
					if ((j%2) == 0) s = s + "propagation index"; else s = s + "extinction coefficient";

					nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());

					nc_enddef(cdfRoot);

					if (j == 0) {
						if (lossmat) {
							for (unsigned int i=0;i<NTE;i++) var[i] = cIxeffTE[i].real();
						} else {
							for (unsigned int i=0;i<NTE;i++) var[i] = ixeffTE[i];
						};
					} else if (j == 1) {
						for (unsigned int i=0;i<NTE;i++) var[i] = cIxeffTE[i].imag();
					} else if (j == 2) {
						if (lossmat) {
							for (unsigned int i=0;i<NTM;i++) var[i] = cIxeffTM[i].real();
						} else {
							for (unsigned int i=0;i<NTM;i++) var[i] = ixeffTM[i];
						};
					} else {
						for (unsigned int i=0;i<NTM;i++) var[i] = cIxeffTM[i].imag();
					};

					nc_put_var_double(cdfDom, cdfVar, var);

					delete[] var;
					delete[] dims;

					// variables with dimension dimTE/dimTM x dimZ/dimXY

					// j == 0: EyTE_re, EyTE_sqr, HzTE_re
					// j == 1: EyTE_im, HzTE_im
					// j == 2: EzTM_re, EzTM_sqr, HyTM_re
					// j == 3: EzTM_im, HyTM_im

					nc_redef(cdfRoot);

					dims = new int[2];
					if (j < 2) {
						var = new double[NTE*dimGeo];
						var2 = new double[NTE*dimGeo];
						if (j == 0) var3 = new double[NTE*dimGeo];

						dims[0] = cdfDimTE;

					} else {
						var = new double[NTM*dimGeo];
						var2 = new double[NTM*dimGeo];
						if (j == 2) var3 = new double[NTM*dimGeo];

						dims[0] = cdfDimTM;
					};
					dims[1] = cdfDimGeo;

					// define variables
					if (j == 0) {
						s = "E" + trvaxis + "TE"; if (lossmat) s = s + "_re";
						s2 = "E" + trvaxis + "TE_sqr";
						s3 = "H" + gdaxis + "TE"; if (lossmat) s3 = s3 + "_re";
					} else if (j == 1) {
						s = "E" + trvaxis + "TE_im";
						s2 = "H" + gdaxis + "TE_im";
					} else if (j == 2) {
						s = "E" + gdaxis + "TM"; if (lossmat) s = s + "_re";
						s2 = "E" + gdaxis + "TM_sqr";
						s3 = "H" + trvaxis + "TM"; if (lossmat) s3 = s3 + "_re";
					} else if (j == 3) {
						s = "E" + gdaxis + "TM_im";
						s2 = "H" + trvaxis + "TM_im";
					};

					nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 2, dims, &cdfVar);
					nc_def_var(cdfDom, s2.c_str(), NC_DOUBLE, 2, dims, &cdfVar2);
					if ((j%2) == 0) nc_def_var(cdfDom, s3.c_str(), NC_DOUBLE, 2, dims, &cdfVar3);

					// set long names
					if (j == 0) {
						s = "E" + trvaxis + "TE(" + gdaxis + ")"; if (lossmat) s = "Re(" + s + ")"; s = s + " [V/m]";
						s2 = "|E" + trvaxis + "TE(" + gdaxis + ")|^2 [V^2/m^2]";
						s3 = "H" + gdaxis + "TE(" + gdaxis + ")"; if (lossmat) s3 = "Re(" + s3 + ")"; s3 = s3 + " [A/m]";
					} else if (j == 1) {
						s = "Im(E" + trvaxis + "TE(" + gdaxis + ")) [V/m]";
						s2 = "Im(H" + gdaxis + "TE(" + gdaxis + ")) [A/m]";
					} else if (j == 2) {
						s = "E" + gdaxis + "TM(" + gdaxis + ")"; if (lossmat) s = "Re(" + s + ")"; s = s + " [V/m]";
						s2 = "|E" + gdaxis + "TM(" + gdaxis + ")|^2 [V^2/m^2]";
						s3 = "H" + trvaxis + "TM(" + gdaxis + ")"; if (lossmat) s3 = "Re(" + s3 + ")"; s3 = s3 + " [A/m]";
					} else if (j == 3) {
						s = "Im(E" + gdaxis + "TM(" + gdaxis + ")) [V/m]";
						s2 = "Im(H" + trvaxis + "TM(" + gdaxis + ")) [A/m]";
					};

					nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
					nc_put_att_text(cdfDom, cdfVar2, "long_name", s2.length(), s2.c_str());
					if ((j%2) == 0) nc_put_att_text(cdfDom, cdfVar3, "long_name", s3.length(), s3.c_str());

					// set titles
					if (j == 0) {
						s = "TE mode electric field pattern, " + trvaxis + "-component"; if (lossmat) s = s + " real part";
						s2 = "TE mode electric field pattern absolute value squared, " + trvaxis + "-component";
						s3 = "TE mode magnetic field pattern, " + gdaxis + "-component"; if (lossmat) s3 = s3 + " real part";
					} else if (j == 1) {
						s = "TE mode electric field pattern, " + trvaxis + "-component imaginary part";
						s2 = "TE mode magnetic field pattern, " + gdaxis + "-component imaginary part";
					} else if (j == 2) {
						s = "TM mode electric field pattern, " + gdaxis + "-component"; if (lossmat) s = s + " real part";
						s2 = "TM mode electric field pattern absolute value squared, " + gdaxis + "-component";
						s3 = "TM mode magnetic field pattern, " + trvaxis + "-component"; if (lossmat) s3 = s3 + " real part";
					} else if (j == 3) {
						s = "TM mode electric field pattern, " + gdaxis + "-component imaginary part";
						s2 = "TM mode magnetic field pattern, " + trvaxis + "-component imaginary part";
					};

					nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
					nc_put_att_text(cdfDom, cdfVar2, "title", s2.length(), s2.c_str());
					if ((j%2) == 0) nc_put_att_text(cdfDom, cdfVar3, "title", s3.length(), s3.c_str());

					nc_enddef(cdfRoot);

					// assemble variables
					if (j == 0) {
						if (lossmat) {
							for (unsigned int i=0;i<NTE;i++) {
								for (unsigned int k=0;k<dimGeo;k++) {
									var[i*dimGeo+k] = cEyTE[i*dimGeo+k].real();
									var2[i*dimGeo+k] = norm(cEyTE[i*dimGeo+k]);
									var3[i*dimGeo+k] = cHzTE[i*dimGeo+k].real();
								};
							};
						} else {
							for (unsigned int i=0;i<NTE;i++) {
								for (unsigned int k=0;k<dimGeo;k++) {
									var[i*dimGeo+k] = EyTE[i*dimGeo+k];
									var2[i*dimGeo+k] = pow(EyTE[i*dimGeo+k], 2);
									var3[i*dimGeo+k] = HzTE[i*dimGeo+k];
								};
							};
						};
					} else if (j == 1) {
						for (unsigned int i=0;i<NTE;i++) {
							for (unsigned int k=0;k<dimGeo;k++) {
								var[i*dimGeo+k] = cEyTE[i*dimGeo+k].imag();
								var2[i*dimGeo+k] = cHzTE[i*dimGeo+k].imag();
							};
						};
					} else if (j == 2) {
						if (lossmat) {
							for (unsigned int i=0;i<NTM;i++) {
								for (unsigned int k=0;k<dimGeo;k++) {
									var[i*dimGeo+k] = cEzTM[i*dimGeo+k].real();
									var2[i*dimGeo+k] = norm(cEzTM[i*dimGeo+k]);
									var3[i*dimGeo+k] = cHyTM[i*dimGeo+k].real();
								};
							};
						} else {
							for (unsigned int i=0;i<NTM;i++) {
								for (unsigned int k=0;k<dimGeo;k++) {
									var[i*dimGeo+k] = EzTM[i*dimGeo+k];
									var2[i*dimGeo+k] = pow(EzTM[i*dimGeo+k], 2);
									var3[i*dimGeo+k] = HyTM[i*dimGeo+k];
								};
							};
						};
					} else if (j == 3) {
						for (unsigned int i=0;i<NTM;i++) {
							for (unsigned int k=0;k<dimGeo;k++) {
								var[i*dimGeo+k] = cEzTM[i*dimGeo+k].imag();
								var2[i*dimGeo+k] = cHyTM[i*dimGeo+k].imag();
							};
						};
					};

					// write variables
					nc_put_var_double(cdfDom, cdfVar, var);
					nc_put_var_double(cdfDom, cdfVar2, var2);
					if ((j%2) == 0) nc_put_var_double(cdfDom, cdfVar3, var3);

					delete[] var;
					delete[] var2;
					if ((j%2) == 0) delete[] var3;
					delete[] dims;
				};
			};
		};

		// -- clean up
		if ((dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) || (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ)) {
			delete cubrast;
		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY) {
			delete xyboxrast;
		} else if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) {
			delete zlinerast;
		};

		delete dom;

		// -- store in archive
		nc_close(cdfRoot);

		s = cli->Title + "_res.cdf";
		if (prefix.length() > 0) s = prefix + "_" + s;
		refResfile = Acv::addfile(dbsplnr, xchg->acvpath, tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
		dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refResfile, VecPlnrVRMCalcMFileIo::OUT);
	};

	delete cli;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrWgmodeFd1d::calcNolossmat(
			const vector<double>& n
			, const double lam
			, const double dz
			, const bool te
			, const bool tm
			, unsigned int& NTE
			, vector<double>& ixeffTE
			, vector<double>& EyTE
			, vector<double>& HzTE
			, unsigned int& NTM
			, vector<double>& ixeffTM
			, vector<double>& EzTM
			, vector<double>& HyTM
		) {
/*
	long int N = n.size();

	vector<double> ixsqrdrv;

	double nmin, nmax;

	vector<unsigned int> ics;
	unsigned int l;

	ixsqrdrv.resize(N, 0.0);

	// square index derivative
	for (int i=1;i<(N-1);i++) ixsqrdrv[i] = 1.0/(2.0*dz) * 1.0/(n[i]*n[i]) * (n[i+1]*n[i+1] - n[i-1]*n[i-1]);

	// refractive index limits
	nmin = 1.0e6;
	nmax = 0.0;

	for (int i=0;i<N;i++) {
		if (n[i] > nmax) nmax = n[i];
		if (n[i] < nmin) nmin = n[i];
	};

	// --- eigenproblem candidates: dgeev, dgeevx, (dggev - generalized w/ matrix B), (dggevx); need right eigenvectors
	// dgeev_(char* jobvl, char* jobvr, integer* N, double* a, integer* lda, double* wr, double* wi, double* vl, integer* ldvl, double* vr, integer* ldvr, double* work, integer* lwork, integer* info);
	char jobvl = 'N';
	char jobvr = 'V';
	double* a = new double[N*N];
	long int lda = N;
	double* wr = new double[N];
	double* wi = new double[N];
	long int ldvl = 1;
	double* vr = new double[N*N];
	long int ldvr = N;
	double* work = new double[4*N];
	long int lwork = 4*N;
	long int info;

	// --- TE mode calculation
	// all LAPACK matrices are column contiguous
	if (te) {
		for (int i=0;i<(N*N);i++) a[i] = 0.0;

		// main diagonal
		for (int i=0;i<N;i++) {
			a[i*N + i] = -2.0/(dz*dz) + pow(2.0*pi/lam, 2) * n[i]*n[i];
		};

		// upper and lower diagonals
		for (int i=0;i<(N-1);i++) {
			a[(i+1)*N + i] = 1.0/(dz*dz);
			a[i*N + (i+1)] = 1.0/(dz*dz);
		};

		dgeev_(&jobvl, &jobvr, &N, a, &lda, wr, wi, NULL, &ldvl, vr, &ldvr, work, &lwork, &info);

		if (info < 0) cout << "TE calculation: dgeev() argument " << (-info) << " had an illegal value" << endl;

		// --- result analysis
		ics.resize(0);

		// find valid modes and transform eigenvalue to effective index
		for (int i=0;i<N;i++) {
			if (wi[i] == 0.0) {
				wr[i] = lam/(2.0*pi) * sqrt(wr[i]);

				if ((wr[i] > nmin) && (wr[i] < nmax)) ics.push_back(i);
			};
		};

		NTE = ics.size();

		// sort modes (neff descending)
		for (unsigned int i=0;i<NTE;i++) {
			for (unsigned int j=i+1;j<NTE;j++) {
				if (wr[ics[j]] > wr[ics[i]]) {
					l = ics[i];
					ics[i] = ics[j];
					ics[j] = l;
				};
			};
		};

		cout << "TE: " << NTE << " modes found." << endl;

		for (unsigned int i=0;i<NTE;i++) {
			cout << "\t" << wr[ics[i]] << endl;
		};

		ixeffTE.resize(NTE);

		EyTE.resize(NTE*N);
		HzTE.resize(NTE*N);

		// copy
		for (unsigned int i=0;i<NTE;i++) {
			ixeffTE[i] = wr[ics[i]];

			for (unsigned int j=0;j<N;j++) {
				// resulting field pattern is Ey
				EyTE[i*N+j] = vr[ics[i]*N + j];

				// TODO: derive HzTE
			};
		};
	};

	// --- TM mode calculation
	// all LAPACK matrices are column contiguous
	if (tm) {
		for (int i=0;i<(N*N);i++) a[i] = 0.0;

		// main diagonal
		for (int i=0;i<N;i++) {
			a[i*N + i] = -2.0/(dz*dz) + pow(2.0*pi/lam, 2) * n[i]*n[i];
		};

		// upper and lower diagonals
		for (int i=0;i<(N-1);i++) {
			// upper
			a[(i+1)*N + i] = 1.0/(dz*dz) + 1.0/(2.0*dz) * ixsqrdrv[i];

			// lower
			a[i*N + (i+1)] = 1.0/(dz*dz) - 1.0/(2.0*dz) * ixsqrdrv[i+1];
		};

		dgeev_(&jobvl, &jobvr, &N, a, &lda, wr, wi, NULL, &ldvl, vr, &ldvr, work, &lwork, &info);

		if (info < 0) cout << "TM calculation: dgeev() argument " << (-info) << " had an illegal value" << endl;

		// --- result analysis
		ics.resize(0);

		// find valid modes and transform eigenvalue to effective index
		for (int i=0;i<N;i++) {
			if (wi[i] == 0.0) {
				wr[i] = lam/(2.0*pi) * sqrt(wr[i]);

				if ((wr[i] > nmin) && (wr[i] < nmax)) ics.push_back(i);
			};
		};

		NTM = ics.size();

		// sort modes (neff descending)
		for (unsigned int i=0;i<NTM;i++) {
			for (unsigned int j=i+1;j<NTM;j++) {
				if (wr[ics[j]] > wr[ics[i]]) {
					l = ics[i];
					ics[i] = ics[j];
					ics[j] = l;
				};
			};
		};

		cout << "TM: " << NTM << " modes found." << endl;
		for (unsigned int i=0;i<NTM;i++) {
			cout << "\t" << wr[ics[i]] << endl;
		};

		ixeffTM.resize(NTM);

		EzTM.resize(NTM*N);
		HyTM.resize(NTM*N);

		// copy
		for (unsigned int i=0;i<NTM;i++) {
			ixeffTM[i] = wr[ics[i]];

			for (int j=0;j<N;j++) {
				// resulting field pattern is Hy
				HyTM[i*N+j] = vr[ics[i]*N + j];

				// derive Ez
				EzTM[i*N+j] = vr[ics[i]*N + j] * ixeffTM[i] * c0 * 4.0e-7*pi / (n[j]*n[j]);
			};
		};
	};

	// --- clean up
	delete[] a;
	delete[] work;
	delete[] wr;
	delete[] wi;
	delete[] vr;
*/
};

void PlnrWgmodeFd1d::calcLossmat(
			const vector<double>& n
			, const vector<double>& k
			, const double lam
			, const double dz
			, const bool te
			, const bool tm
			, unsigned int& NTE
			, vector<complex<double> >& ixeffTE
			, vector<complex<double> >& EyTE
			, vector<complex<double> >& HzTE
			, unsigned int& NTM
			, vector<complex<double> >& ixeffTM
			, vector<complex<double> >& EzTM
			, vector<complex<double> >& HyTM
		) {
/*
	complex<double> c;

	long int N = n.size();

	vector<complex<double> > ix;
	vector<complex<double> > ixsqrdrv;

	double nmin, nmax;

	vector<unsigned int> ics;
	unsigned int l;

	ix.resize(N, 0.0);
	ixsqrdrv.resize(N, 0.0);

	for (int i=0;i<N;i++) {
		ix[i].real() = n[i];
		ix[i].imag() = k[i];
	};

	// square index derivative
	for (int i=1;i<(N-1);i++) ixsqrdrv[i] = 1.0/(2.0*dz) * 1.0/(ix[i]*ix[i]) * (ix[i+1]*ix[i+1] - ix[i-1]*ix[i-1]);

	// refractive index limits
	nmin = 1.0e6;
	nmax = 0.0;

	for (int i=0;i<N;i++) {
		if (n[i] > nmax) nmax = n[i];
		if (n[i] < nmin) nmin = n[i];
	};

	// --- eigenproblem candidates: zgeev, zgeevx, (zggev - generalized w/ matrix B), (zggevx); need right eigenvectors
	// zgeev_(char* jobvl, char* jobvr, integer* N, doublecomplex_* a, integer* lda, doublecomplex_* w,       doublecomplex_* vl, integer* ldvl, doublecomplex_* vr, integer* ldvr, doublecomplex_* work, integer* lwork, double* rwork, integer* info);
	char jobvl = 'N';
	char jobvr = 'V';
	doublecomplex_* a = new doublecomplex_[N*N];
	long int lda = N;
	doublecomplex_* w = new doublecomplex_[N];
	long int ldvl = 1;
	doublecomplex_* vr = new doublecomplex_[N*N];
	long int ldvr = N;
	doublecomplex_* work = new doublecomplex_[2*N];
	long int lwork = 2*N;
	double* rwork = new double[2*N];
	long int info;

	// --- TE mode calculation
	// all LAPACK matrices are column contiguous
	if (te) {
		for (int i=0;i<(N*N);i++) {
			a[i].r = 0.0;
			a[i].i = 0.0;
		};

		// main diagonal
		for (int i=0;i<N;i++) {
			c = -2.0/(dz*dz) + pow(2.0*pi/lam, 2) * ix[i]*ix[i];

			a[i*N + i].r = c.real();
			a[i*N + i].i = c.imag();
		};

		// upper and lower diagonals
		for (int i=0;i<(N-1);i++) {
			a[(i+1)*N + i].r = 1.0/(dz*dz);
			a[i*N + (i+1)].r = 1.0/(dz*dz);
		};

		zgeev_(&jobvl, &jobvr, &N, a, &lda, w, NULL, &ldvl, vr, &ldvr, work, &lwork, rwork, &info);

		if (info < 0) cout << "TE calculation: zgeev() argument " << (-info) << " had an illegal value" << endl;

		// --- result analysis
		ics.resize(0);

		// find valid modes and transform eigenvalue to effective index
		for (int i=0;i<N;i++) {
			c.real() = w[i].r;
			c.imag() = w[i].i;

			c = lam/(2.0*pi) * sqrt(c);

			w[i].r = c.real();
			w[i].i = c.imag();

			if ((c.real() > nmin) && (c.real() < nmax)) ics.push_back(i);
		};

		NTE = ics.size();

		// sort modes (neff descending)
		for (unsigned int i=0;i<NTE;i++) {
			for (unsigned int j=i+1;j<NTE;j++) {
				if (w[ics[j]].r > w[ics[i]].r) {
					l = ics[i];
					ics[i] = ics[j];
					ics[j] = l;
				};
			};
		};

		cout << "TE: " << NTE << " modes found." << endl;

		for (unsigned int i=0;i<NTE;i++) {
			cout << "\t(" << w[ics[i]].r << ", " << w[ics[i]].i << ")" << endl;
		};

		ixeffTE.resize(NTE);

		EyTE.resize(NTE*N);
		HzTE.resize(NTE*N);

		// copy
		for (unsigned int i=0;i<NTE;i++) {
			ixeffTE[i].real() = w[ics[i]].r;
			ixeffTE[i].imag() = w[ics[i]].i;

			for (unsigned int j=0;j<N;j++) {
				// resulting field pattern is Ey
				EyTE[i*N+j].real() = vr[ics[i]*N + j].r;
				EyTE[i*N+j].imag() = vr[ics[i]*N + j].i;

				// TODO: derive HzTE
			};
		};
	};

	// --- TM mode calculation
	// all LAPACK matrices are column contiguous
	if (tm) {
		for (int i=0;i<(N*N);i++) {
			a[i].r = 0.0;
			a[i].i = 0.0;
		};

		// main diagonal
		for (int i=0;i<N;i++) {
			c = -2.0/(dz*dz) + pow(2.0*pi/lam, 2) * ix[i]*ix[i];

			a[i*N + i].r = c.real();
			a[i*N + i].i = c.imag();
		};

		// upper and lower diagonals
		for (int i=0;i<(N-1);i++) {
			// upper
			c = 1.0/(dz*dz) + 1.0/(2.0*dz) * ixsqrdrv[i];

			a[(i+1)*N + i].r = c.real();
			a[(i+1)*N + i].i = c.imag();

			// lower
			c = 1.0/(dz*dz) - 1.0/(2.0*dz) * ixsqrdrv[i+1];

			a[i*N + (i+1)].r = c.real();
			a[i*N + (i+1)].i = c.imag();
		};

		zgeev_(&jobvl, &jobvr, &N, a, &lda, w, NULL, &ldvl, vr, &ldvr, work, &lwork, rwork, &info);

		if (info < 0) cout << "TM calculation: zgeev() argument " << (-info) << " had an illegal value" << endl;

		// --- result analysis
		ics.resize(0);

		// find valid modes and transform eigenvalue to effective index
		for (int i=0;i<N;i++) {
			c.real() = w[i].r;
			c.imag() = w[i].i;

			c = lam/(2.0*pi) * sqrt(c);

			w[i].r = c.real();
			w[i].i = c.imag();

			if ((c.real() > nmin) && (c.real() < nmax)) ics.push_back(i);
		};

		NTM = ics.size();

		// sort modes (neff descending)
		for (unsigned int i=0;i<NTM;i++) {
			for (unsigned int j=i+1;j<NTM;j++) {
				if (w[ics[j]].r > w[ics[i]].r) {
					l = ics[i];
					ics[i] = ics[j];
					ics[j] = l;
				};
			};
		};

		cout << "TM: " << NTM << " modes found." << endl;
		for (unsigned int i=0;i<NTM;i++) {
			cout << "\t(" << w[ics[i]].r << ", " << w[ics[i]].i << ")" << endl;
		};

		ixeffTM.resize(NTM);

		EzTM.resize(NTM*N);
		HyTM.resize(NTM*N);

		// copy
		for (unsigned int i=0;i<NTM;i++) {
			ixeffTM[i].real() = w[ics[i]].r;
			ixeffTM[i].imag() = w[ics[i]].i;

			for (int j=0;j<N;j++) {
				c.real() = vr[ics[i]*N + j].r;
				c.imag() = vr[ics[i]*N + j].i;

				// resulting field pattern is Hy
				HyTM[i*N+j].real() = c.real();
				HyTM[i*N+j].imag() = c.imag();

				// derive Ez
				c = c * ixeffTM[i] * c0 * 4.0e-7*pi / (ix[j]*ix[j]);
				EzTM[i*N+j].real() = c.real();
				EzTM[i*N+j].imag() = c.imag();
			};
		};
	};

	// --- clean up
	delete[] a;
	delete[] work;
	delete[] rwork;
	delete[] w;
	delete[] vr;
*/
};
// IP cust --- IEND


