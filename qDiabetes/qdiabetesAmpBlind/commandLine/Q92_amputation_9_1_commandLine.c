/* 
 * Copyright 2014 ClinRisk Ltd.
 * 
 * This file is part of QDiabetesAmpBlind (http://qdiabetes.org/amputation-blindness, http://svn.clinrisk.co.uk/opensource/qdiabetes).
 * 
 * QDiabetesAmpBlind is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QDiabetesAmpBlind is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with QDiabetesAmpBlind.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qdiabetes, faithfully implements QDiabetesAmpBlind.
 * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 * altering the coefficients, getting the inputs wrong, or just poor programming.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qdiabetes.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q92_amputation_9_1.xml
 * STATA dta time stamp: 16 Jan 2015 13:01
 * C file create date: Mon  9 Nov 2015 09:52:15 GMT
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q92_amputation_9_1.h>

static double score[16];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2014 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QDiabetesAmpBlind (http://qdiabetes.org/amputation-blindness, http://svn.clinrisk.co.uk/opensource/qdiabetes).\n");
	printf(" * \n");
	printf(" * QDiabetesAmpBlind is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Affero General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QDiabetesAmpBlind is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Affero General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Affero General Public License\n");
	printf(" * along with QDiabetesAmpBlind.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qdiabetes, faithfully implements QDiabetesAmpBlind.\n");
	printf(" * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally \n");
	printf(" * altering the coefficients, getting the inputs wrong, or just poor programming. \n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qdiabetes.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q92_amputation_9_1.xml\n");
	printf(" * STATA dta time stamp: 16 Jan 2015 13:01\n");
	printf(" * C file create date: Mon  9 Nov 2015 09:52:15 GMT\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q92_amputation_9_1_commandLine age b_AF b_CCF b_pvd b_ra b_renal b_type1 diabetes_years2 ethrisk hba1c sbp smoke_cat surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=15) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_AF = atoi(argv[2]);
	int b_CCF = atoi(argv[3]);
	int b_pvd = atoi(argv[4]);
	int b_ra = atoi(argv[5]);
	int b_renal = atoi(argv[6]);
	int b_type1 = atoi(argv[7]);
	int diabetes_years2 = atoi(argv[8]);
	int ethrisk = atoi(argv[9]);
	double hba1c = atof(argv[10]);
	double sbp = atof(argv[11]);
	int smoke_cat = atoi(argv[12]);
	int surv = atoi(argv[13]);
	double town = atof(argv[14]);

	double score = amputation_male(age,b_AF,b_CCF,b_pvd,b_ra,b_renal,b_type1,diabetes_years2,ethrisk,hba1c,sbp,smoke_cat,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
