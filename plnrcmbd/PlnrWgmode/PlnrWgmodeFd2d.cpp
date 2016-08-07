/**
  * \file PlnrWgmodeFd2d.cpp
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

#include "PlnrWgmodeFd2d.h"

DpchRetPlnrWgmodeFd2d* PlnrWgmodeFd2d::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrWgmodeFd2d* dpchinv
		) {
	DpchRetPlnrWgmodeFd2d* dpchret = new DpchRetPlnrWgmodeFd2d();

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
	// situation:
	// - .m file and tab-delimited n file in temporary directory
	// - octave in path
	// - modesolver with tools in subdirectory "modesolver" of executable

	ostringstream sqlstr;
	ubigint ref;

	ubigint refBasedsn;
	PlnrMCalcitem* cli = NULL;

	map<string, string> env;

	double lam;

	PlnrMDomain* dom = NULL;

	unsigned int ixDom;
	
	vector<unsigned int> icsEval;
	unsigned int ixEval;

	double x, y, z;

	string tmpfolder;
	string tmpfile;

	string trvaxis, gdaxis;

	fstream infile;
	char* buf = NULL;

	double sumExy, sumEz;

	unsigned int N;
	vector<double> neff;
	vector<double> keff;

	vector<double> Exy_sqr;
	vector<double> Ez_sqr;

	unsigned int txN;

	unsigned int teN;
	vector<double> neffTE;
	vector<double> keffTE;
	vector<double> ExyTE_sqr;

	unsigned int tmN;
	vector<double> neffTM;
	vector<double> keffTM;
	vector<double> EzTM_sqr;

	unsigned int dimXY, dimZ;

	int cdfRoot, cdfDoms;
	int cdfDom;
	int cdfDimX, cdfDimY, cdfDimXY, cdfDimZ;
	int cdfDimTE, cdfDimTM;
	int cdfVar, cdfVar2;

	int* dims = NULL;

	double* var;
	double* var2;

	double nmin, nmax;

	ostringstream str;

	string s, s2;

	unsigned int ix, ixXy, ixZ;
	unsigned int domDimXY, domDimZ;
	double domDz, domZ0, domZ1, domB3;
	double d;

	fstream txtfile;
	fstream mfile;

	char* cwd = NULL;

	ubigint refMpafile, refResfile;

	sqlstr.str(""); sqlstr << "SELECT refPlnrMDesign FROM TblPlnrMCalc WHERE ref = " << refPlnrMCalc;
	dbsplnr->loadUbigintBySQL(sqlstr.str(), refBasedsn);

	dbsplnr->tblplnrmcalcitem->loadRecByRef(refPlnrMCalcitem, &cli);

	// -- prepare result folder
	tmpfolder = Tmp::newfolder(xchg->tmppath);

	// -- load calculation environment (mainly, lam)
	Env::setForCli(dbsplnr, env, refPlnrMCalc, refPlnrMCalcitem);
	lam = Env::getDoubleVal(env, "lam");

	// -- determine domain type
	sqlstr.str(""); sqlstr << "SELECT TblPlnrMDomain.ref FROM TblPlnrMDomain, TblPlnrMDesign, TblPlnrMCalc WHERE TblPlnrMDomain.dsnRefPlnrMDesign = TblPlnrMDesign.ref"
				<< " AND TblPlnrMDesign.ref = TblPlnrMCalc.refPlnrMDesign AND TblPlnrMCalc.ref = " << refPlnrMCalc << " AND TblPlnrMDomain.sref = '" << srefDom << "'";
	dbsplnr->loadUbigintBySQL(sqlstr.str(), ref);

	if (dbsplnr->tblplnrmdomain->loadRecByRef(ref, &dom)) {
		if (dom->ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
			trvaxis = "xy";
			gdaxis = "z";

			// -- obtain n, k
			Cubrast rast(dbsplnr, xchg->acvpath, env, refBasedsn, cli->refPlnrMDesign, refRastfile, "phot;phot", "n;k");

			// -- retrieve main simulation domain
			rast.getDomIx(srefDom, ixDom);

			dimXY = rast.domDimXY[ixDom];
			dimZ = rast.domDimZ[ixDom];

			// -- retrieve other domains (put main domain first, for file writing)
			icsEval.push_back(ixDom);
			for (unsigned int i=0;i<srefsDomEval.size();i++) {
				rast.getDomIx(srefsDomEval[i], ixEval);
				icsEval.push_back(ixEval);
			};

			// -- output refractive index (cdf)
			tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "n");
			s = cli->Title + "_n.cdf";
			if (prefix.length() > 0) s = prefix + "_" + s;
			refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);

			if (lossmat) {
				tmpfile = rast.matparCdf(xchg->tmppath, srefDom, "phot", "k");
				s = cli->Title + "_k.cdf";
				if (prefix.length() > 0) s = prefix + "_" + s;
				refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, xchg->tmppath + "/" + tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
				dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);
			};

			// -- output refractive index (txt) ; determine nmin, nmax on the way
			s = xchg->tmppath + "/" + tmpfolder + "/n.txt";
			txtfile.open(s.c_str(), ios::out);

			nmin = 1.0e6;
			nmax = -1.0e6;

			for (unsigned int i=0;i<dimXY;i++) {
				for (unsigned int j=0;j<dimZ;j++) {
					x = rast.domA11[ixDom]*(rast.domXy0[ixDom]+i*rast.domDxy[ixDom])+rast.domB1[ixDom];
					y = rast.domA21[ixDom]*(rast.domXy0[ixDom]+i*rast.domDxy[ixDom])+rast.domB2[ixDom];
					z = rast.domZ0[ixDom]+j*rast.domDz[ixDom]+rast.domB3[ixDom];

					d = rast.getMatpar(x, y, z, 0);

					if (d < nmin) nmin = d;
					if (d > nmax) nmax = d;

					if (j != 0) txtfile << ";";
					txtfile << d;
				};

				txtfile << endl;
			};

			txtfile.close();

			if (lossmat) {
				s = xchg->tmppath + "/" + tmpfolder + "/k.txt";
				txtfile.open(s.c_str(), ios::out);

				for (unsigned int i=0;i<dimXY;i++) {
					for (unsigned int j=0;j<dimZ;j++) {
						x = rast.domA11[ixDom]*(rast.domXy0[ixDom]+i*rast.domDxy[ixDom])+rast.domB1[ixDom];
						y = rast.domA21[ixDom]*(rast.domXy0[ixDom]+i*rast.domDxy[ixDom])+rast.domB2[ixDom];
						z = rast.domZ0[ixDom]+j*rast.domDz[ixDom]+rast.domB3[ixDom];

						d = rast.getMatpar(x, y, z, 1);

						if (j != 0) txtfile << ";";
						txtfile << d;
					};

					txtfile << endl;
				};

				txtfile.close();
			};

			// -- write .m file
			s = xchg->tmppath + "/" + tmpfolder + "/runwgmodes.m";
			mfile.open(s.c_str(), ios::out);

			// - make sure octave finds data and tools
			cwd = new char[1024];
			getcwd(cwd, 1024);

			mfile << "clear all;" << endl;
			mfile << endl;

			mfile << "cd '" << xchg->tmppath << "/" << tmpfolder << "';" << endl;
			mfile << "addpath('" << cwd << "/modesolver');" << endl;
			mfile << "addpath('" << cwd << "/modesolver/tools');" << endl;
			mfile << endl;

			delete[] cwd;

			// - read n, k into workspace
			mfile << "n = dlmread('n.txt', ';');" << endl;
			if (lossmat) {
				mfile << "k = dlmread('k.txt', ';');" << endl;
				mfile << "eps = (n-i*k).^2; % -i*k seems more appropriate than +i*k" << endl;
			} else {
				mfile << "eps = n.*n;" << endl;
			};
			mfile << endl;

			// - prepare mesh
			mfile << "dx = " << rast.domDxy[ixDom] << ";" << endl;
			mfile << "dy = " << rast.domDz[ixDom] << ";" << endl;
			mfile << endl;

			// - calculate modes
			mfile << "lam = " << lam << ";" << endl;
			mfile << "[Hx,Hy,neff] = wgmodes(lam, " << nmax << ", 8, dx, dy, eps, '0000');" << endl;
			mfile << "Nmodes = length(neff);" << endl;
			mfile << endl;

			// - write results into text files
			mfile << "dlmwrite('neff.txt', real(neff), ';');" << endl;
			mfile << "dlmwrite('keff.txt', -imag(neff), ';');" << endl;
			mfile << endl;

			mfile << "for j=1:Nmodes" << endl;
			mfile << "\t[Hz,Ex,Ey,Ez] = postprocess(lam, neff(j,1), Hx(:,:,j), Hy(:,:,j), dx, dy, eps, '0000');" << endl;
			mfile << endl;

			mfile << "\tExsqr = Ex.*conj(Ex);" << endl;
			mfile << "\tfilename = sprintf('Ex%d_sqr.txt', j);" << endl;
			mfile << "\tdlmwrite(filename, real(Exsqr), ';'); % real() should be obsolete" << endl;
			mfile << endl;

			mfile << "\tEysqr = Ey.*conj(Ey);" << endl;
			mfile << "\tfilename = sprintf('Ey%d_sqr.txt', j);" << endl;
			mfile << "\tdlmwrite(filename, real(Eysqr), ';');" << endl;
			mfile << "end" << endl;

			mfile.close();

			// -- invoke octave
			s = "octave '" + xchg->tmppath + "/" + tmpfolder + "/runwgmodes.m'";
			system(s.c_str());

			// -- read results from text files
			N = 0;
			teN = 0;
			tmN = 0;

			buf = new char[65536];

			// - propagation indices
			neff.resize(0);
			keff.resize(0);

			s = xchg->tmppath + "/" + tmpfolder + "/neff.txt";
			infile.open(s.c_str(), ifstream::in);

			while (infile.good() && (!infile.eof())) {
				infile.getline(buf, 65536, '\n');
				s = string(buf);

				StrMod::stringToDoublevec(s, neff, true);
			};

			infile.close();

			s = xchg->tmppath + "/" + tmpfolder + "/keff.txt";
			infile.open(s.c_str(), ifstream::in);

			while (infile.good() && (!infile.eof())) {
				infile.getline(buf, 65536, '\n');
				s = string(buf);

				StrMod::stringToDoublevec(s, keff, true);
			};

			infile.close();

			N = neff.size();

			// - field components
			for (int i=N-1;i>=0;i--) {
				if ((neff[i] >= nmin) && (neff[i] <= nmax)) {
					Exy_sqr.resize(0);
					Ez_sqr.resize(0);

					// Exy_sqr
					str.str(""); str << xchg->tmppath << "/" << tmpfolder << "/Ex" << i << "_sqr.txt";
					if (access(str.str().c_str(), R_OK) == -1) break;

					infile.open(str.str().c_str(), ifstream::in);

					while (infile.good() && (!infile.eof())) {
						infile.getline(buf, 65536, '\n');
						s = string(buf);

						StrMod::stringToDoublevec(s, Exy_sqr, true);
					};

					infile.close();

					// Ez_sqr
					str.str(""); str << xchg->tmppath << "/" << tmpfolder << "/Ey" << i << "_sqr.txt";
					if (access(str.str().c_str(), R_OK) == -1) break;

					infile.open(str.str().c_str(), ifstream::in);

					while (infile.good() && (!infile.eof())) {
						infile.getline(buf, 65536, '\n');
						s = string(buf);

						StrMod::stringToDoublevec(s, Ez_sqr, true);
					};

					infile.close();

					// determine TE/TM
					sumExy = 0.0;
					for (unsigned int j=0;j<Exy_sqr.size();j++) sumExy += Exy_sqr[j];

					sumEz = 0.0;
					for (unsigned int j=0;j<Ez_sqr.size();j++) sumEz += Ez_sqr[j];

					// append to modes while discarding minor components
					if (sumExy > sumEz) {
						// TE
						teN++;
						neffTE.push_back(neff[i]);
						keffTE.push_back(keff[i]);

						ix = ExyTE_sqr.size();
						ExyTE_sqr.resize(ix + Exy_sqr.size());

						for (unsigned int k=0;k<Exy_sqr.size();k++) ExyTE_sqr[ix+k] = Exy_sqr[k];

					} else {
						// TM
						tmN++;
						neffTM.push_back(neff[i]);
						keffTM.push_back(keff[i]);

						ix = EzTM_sqr.size();
						EzTM_sqr.resize(ix + Ez_sqr.size());

						for (unsigned int k=0;k<Ez_sqr.size();k++) EzTM_sqr[ix+k] = Ez_sqr[k];
					};
				};
			};

			delete[] buf;

			// -- write results into .cdf file

			// dimensions dimTE, dimTM
			// index variables neffTE, keffTE, neffTM, keffTM (dimTE / dimTM)
			// mode pattern variables for TE: ExyTE_sqr (dimTE x dimXYxdimZ)
			// mode pattern variables for TM: EzTM_sqr (dimTM x dimXYxdimZ)
			// zcsbox: propagation in yx direction; TE has Exy, TM has Ez

			// - create and open cdf file
			tmpfile = Tmp::newfile(xchg->tmppath, "cdf");
			tmpfile = xchg->tmppath + "/" + tmpfile;

			nc_create(tmpfile.c_str(), NC_NETCDF4, &cdfRoot);
			nc_def_grp(cdfRoot, "doms", &cdfDoms);

			// - set up cdf file
			nc_enddef(cdfRoot);

			for (unsigned int i=0;i<icsEval.size();i++) {
				ixEval = icsEval[i];

				cdfDom = rast.domCdf(ixEval, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);

				dimXY = rast.domDimXY[ixEval];
				dimZ = rast.domDimZ[ixEval];

				// - add TE and TM domains
				nc_redef(cdfRoot);
					if (te && (teN > 0)) nc_def_dim(cdfDom, "dimTE", teN, &cdfDimTE);
					if (tm && (tmN > 0)) nc_def_dim(cdfDom, "dimTM", tmN, &cdfDimTM);
				nc_enddef(cdfRoot);

				// - mode indices and profiles
				for (unsigned int j=0;j<2;j++) {
					// j == 0: TE
					// j == 1: TM

					if ( ((j == 0) && te && (teN > 0)) || ((j == 1) && tm && (tmN > 0)) ) {
						if (ixEval == ixDom) {
							// variables with dimension dimTE/dimTM
							nc_redef(cdfRoot);

							dims = new int[1];
							if (j == 0) {
								var = new double[teN];
								var2 = new double[teN];
								dims[0] = cdfDimTE;
							} else {
								var = new double[tmN];
								var2 = new double[tmN];
								dims[0] = cdfDimTM;
							};

							s = "neff";
							s2 = "keff";
							if (j == 0) {
								s = s + "TE";
								s2 = s2 + "TE";
							} else {
								s = s + "TM";
								s2 = s2 + "TM";
							};

							nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
							nc_def_var(cdfDom, s2.c_str(), NC_DOUBLE, 1, dims, &cdfVar2);

							if (j == 0) {
								s = "TE mode ";
								s2 = "TE mode ";
							} else {
								s = "TM mode ";
								s2 = "TM mode ";
							};
							s = s + "propagation index";
							s2 = s2 + "extinction coefficient";

							nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
							nc_put_att_text(cdfDom, cdfVar2, "title", s2.length(), s2.c_str());

							nc_enddef(cdfRoot);

							if (j == 0) {
								for (unsigned int k=0;k<teN;k++) {
									var[k] = neffTE[k];
									var2[k] = keffTE[k];
								};
							} else {
								for (unsigned int k=0;k<tmN;k++) {
									var[k] = neffTM[k];
									var2[k] = keffTM[k];
								};
							};

							nc_put_var_double(cdfDom, cdfVar, var);
							nc_put_var_double(cdfDom, cdfVar2, var2);

							delete[] var;
							delete[] var2;

							delete[] dims;

							// variables with dimension dimTE/dimTM x dimXYxdimZ

							// j == 0: ExyTE_sqr
							// j == 1: EzTM_sqr

							nc_redef(cdfRoot);

							dims = new int[3];
							if (j == 0) {
								var = new double[teN*dimXY*dimZ];

								dims[0] = cdfDimTE;

							} else {
								var = new double[tmN*dimXY*dimZ];

								dims[0] = cdfDimTM;
							};
							dims[1] = cdfDimXY;
							dims[2] = cdfDimZ;

							// define variables
							if (j == 0) {
								s = "E" + trvaxis + "TE_sqr";
							} else {
								s = "E" + gdaxis + "TM_sqr";
							};

							nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 3, dims, &cdfVar);

							// set long names
							if (j == 0) {
								s = "|E" + trvaxis + "TE(" + gdaxis + ")|^2 [V^2/m^2]";
							} else {
								s = "|E" + gdaxis + "TM(" + gdaxis + ")|^2 [V^2/m^2]";
							};

							nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());

							// set titles
							if (j == 0) {
								s = "TE mode electric field pattern absolute value squared, " + trvaxis + "-component";
							} else {
								s = "TM mode electric field pattern absolute value squared, " + gdaxis + "-component";
							};

							nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());

							nc_enddef(cdfRoot);

							// assemble variables
							if (j == 0) {
								for (unsigned int k=0;k<teN;k++) {
									for (unsigned int l=0;l<dimXY;l++) {
										for (unsigned int m=0;m<dimZ;m++) {
											ix = k*(dimXY*dimZ) + l*dimZ + m;

											var[ix] = ExyTE_sqr[ix];
										};
									};
								};
							} else {
								for (unsigned int k=0;k<tmN;k++) {
									for (unsigned int l=0;l<dimXY;l++) {
										for (unsigned int m=0;m<dimZ;m++) {
											ix = k*(dimXY*dimZ) + l*dimZ + m;

											var[ix] = EzTM_sqr[ix];
										};
									};
								};
							};

							// write variables
							nc_put_var_double(cdfDom, cdfVar, var);

							delete[] var;
							delete[] dims;

						} else {
							// evaluate profile on specified domain
							if (rast.domIxVBasetype[ixEval] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
								if (j == 0) txN = teN; else txN = tmN;

								// variables with dimension dimTE/dimTM x dimZ

								// j == 0: ExyTE_sqr
								// j == 1: EzTM_sqr

								nc_redef(cdfRoot);

								dims = new int[2];
								if (j == 0) {
									var = new double[teN*dimZ];
									dims[0] = cdfDimTE;
								} else {
									var = new double[tmN*dimZ];
									dims[0] = cdfDimTM;
								};
								dims[1] = cdfDimZ;

								// define variables
								if (j == 0) {
									s = "E" + trvaxis + "TE_sqr";
								} else {
									s = "E" + gdaxis + "TM_sqr";
								};

								nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 2, dims, &cdfVar);

								// set long names
								if (j == 0) {
									s = "|E" + trvaxis + "TE(" + gdaxis + ")|^2 [V^2/m^2]";
								} else {
									s = "|E" + gdaxis + "TM(" + gdaxis + ")|^2 [V^2/m^2]";
								};

								nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());

								// set titles
								if (j == 0) {
									s = "TE mode electric field pattern absolute value squared, " + trvaxis + "-component";
								} else {
									s = "TM mode electric field pattern absolute value squared, " + gdaxis + "-component";
								};

								nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());

								nc_enddef(cdfRoot);

								// - prepare interpolation
								domDimXY = rast.domDimXY[ixDom];
								domDimZ = rast.domDimZ[ixDom];
								domDz = rast.domDz[ixDom];
								domZ0 = rast.domZ0[ixDom];
								domZ1 = rast.domZ1[ixDom];
								domB3 = rast.domB3[ixDom];

								if (rast.domZ0[ixEval] == 0.0) {
									cout << "BUG ALERT!" << endl;
									rast.domZ0[ixEval] = -rast.domZ1[ixEval];
								};

								var2 = new double[txN*domDimZ]; // f(z)

								// find closest xy coordinate of main simulation domain
								x = rast.domB1[ixEval];
								d = (((x-rast.domB1[ixDom])/rast.domA11[ixDom]) - rast.domXy0[ixDom])/rast.domDxy[ixDom]; // dangerous, domA11 could be 0
								if (d < 0.0) d = 0.0;
								ixXy = roundf(d);
								if (ixXy >= domDimXY) ixXy = domDimXY-1;

								// fill f(z) vectors
								if (j == 0) {
									for (unsigned int k=0;k<txN;k++) {
										for (unsigned int l=0;l<domDimZ;l++) {
											ix = k*(domDimXY*domDimZ) + ixXy*domDimZ + l;
											var2[k*domDimZ+l] = ExyTE_sqr[ix];
										};
									};
								} else {
									for (unsigned int k=0;k<txN;k++) {
										for (unsigned int l=0;l<domDimZ;l++) {
											ix = k*(domDimXY*domDimZ) + ixXy*domDimZ + l;
											var2[k*domDimZ+l] = EzTM_sqr[ix];
										};
									};
								};

								// normalize f(z) vectors
								for (unsigned int k=0;k<txN;k++) {
									d = 0.0;
									for (unsigned int l=0;l<domDimZ;l++) d += var2[k*domDimZ+l];
									d *= domDz;
									if (d != 0.0) for (unsigned int l=0;l<domDimZ;l++) var2[k*domDimZ+l] /= d;
								};

								// - fill variables by interpolation
								for (unsigned int k=0;k<txN;k++) {
									for (unsigned int l=0;l<dimZ;l++) {
										ix = k*dimZ + l;

										z = rast.domZ0[ixEval]+((double) l)*rast.domDz[ixEval]+rast.domB3[ixEval];
										
										if (z <= (domB3+domZ0)) {
											var[ix] = var2[k*domDimZ];
										} else if (z >= (domB3+domZ1)) {
											var[ix] = var2[(k+1)*domDimZ-1];
										} else {
											d = (z-rast.domB3[ixDom]-domZ0)/domDz;
											ixZ = roundf(floor(d));

											d = d - floor(d);
											var[ix] = (1.0-d)* var2[k*domDimZ + ixZ] + d* var2[k*domDimZ + ixZ+1];
										};
									};
								};

								delete[] var2;

								// write variables
								nc_put_var_double(cdfDom, cdfVar, var);

								delete[] var;
								delete[] dims;
							};
						};
					};
				};
			};

			// - store in archive
			nc_close(cdfRoot);

			s = cli->Title + "_res.cdf";
			if (prefix.length() > 0) s = prefix + "_" + s;
			refResfile = Acv::addfile(dbsplnr, xchg->acvpath, tmpfile, VecPlnrVMFileRefTbl::CLI, cli->ref, "dgrid", s, "nc", "");
			dbsplnr->tblplnrrmcalcmfile->insertNewRec(NULL, cli->ref, cli->calRefPlnrMCalc, refResfile, VecPlnrVRMCalcMFileIo::OUT);
		};

		delete dom;
	};

	dpchret->teN = teN;
	dpchret->tmN = tmN;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


