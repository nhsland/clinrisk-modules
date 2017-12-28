/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QKidney-2010 (http://qkidney.org, http://svn.clinrisk.co.uk/opensource/qkidney).
 * 
 * QKidney-2010 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QKidney-2010 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QKidney-2010.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qkidney, faithfully implements QKidney-2010.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qkidney.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q54_kidney_xml_51_neph5_0.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 13:59:57 GMT 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <irisk/Q54_kidney_xml_51_neph5_0.h>

static double score[6];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2010 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QKidney-2010 (http://qkidney.org, http://svn.clinrisk.co.uk/opensource/qkidney).\n");
	printf(" * \n");
	printf(" * QKidney-2010 is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QKidney-2010 is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QKidney-2010.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qkidney, faithfully implements QKidney-2010.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qkidney.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q54_kidney_xml_51_neph5_0.xml\n");
	printf(" * STATA dta time stamp: 25 Mar 2010 07:28\n");
	printf(" * C file create date: Wed Nov 10 13:59:57 GMT 2010\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q54_kidney_xml_51_neph5_0_commandLine age b_CCF b_cvd b_pvd b_ra b_renalstones b_sle b_treatedhyp b_type1 b_type2 bmi ethrisk fh_kidney sbp smoke_cat surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=18) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_CCF = atoi(argv[2]);
	int b_cvd = atoi(argv[3]);
	int b_pvd = atoi(argv[4]);
	int b_ra = atoi(argv[5]);
	int b_renalstones = atoi(argv[6]);
	int b_sle = atoi(argv[7]);
	int b_treatedhyp = atoi(argv[8]);
	int b_type1 = atoi(argv[9]);
	int b_type2 = atoi(argv[10]);
	double bmi = atof(argv[11]);
	int ethrisk = atoi(argv[12]);
	int fh_kidney = atoi(argv[13]);
	double sbp = atof(argv[14]);
	int smoke_cat = atoi(argv[15]);
	int surv = atoi(argv[16]);
	double town = atof(argv[17]);

	double score = neph5_female(age,b_CCF,b_cvd,b_pvd,b_ra,b_renalstones,b_sle,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
