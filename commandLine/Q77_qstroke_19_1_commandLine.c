/* 
 * Copyright 2012 ClinRisk Ltd.
 * 
 * This file is part of QStroke (http://qstroke.org, http://svn.clinrisk.co.uk/opensource/qstroke).
 * 
 * QStroke is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QStroke is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QStroke.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qstroke, faithfully implements QStroke.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qstroke.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q77_qstroke_19_1.xml
 * STATA dta time stamp: 9 Mar 2013 15:23
 * C file create date: Sat  9 Mar 2013 16:20:30 GMT
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q77_qstroke_19_1.h>

static double score[16];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2012 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QStroke (http://qstroke.org, http://svn.clinrisk.co.uk/opensource/qstroke).\n");
	printf(" * \n");
	printf(" * QStroke is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QStroke is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QStroke.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qstroke, faithfully implements QStroke.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qstroke.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q77_qstroke_19_1.xml\n");
	printf(" * STATA dta time stamp: 9 Mar 2013 15:23\n");
	printf(" * C file create date: Sat  9 Mar 2013 16:20:30 GMT\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q77_qstroke_19_1_commandLine age b_AF b_CCF b_chd b_ra b_renal b_treatedhyp b_type1 b_type2 b_valvular bmi ethrisk fh_cvd rati sbp smoke_cat surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=19) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_AF = atoi(argv[2]);
	int b_CCF = atoi(argv[3]);
	int b_chd = atoi(argv[4]);
	int b_ra = atoi(argv[5]);
	int b_renal = atoi(argv[6]);
	int b_treatedhyp = atoi(argv[7]);
	int b_type1 = atoi(argv[8]);
	int b_type2 = atoi(argv[9]);
	int b_valvular = atoi(argv[10]);
	double bmi = atof(argv[11]);
	int ethrisk = atoi(argv[12]);
	int fh_cvd = atoi(argv[13]);
	double rati = atof(argv[14]);
	double sbp = atof(argv[15]);
	int smoke_cat = atoi(argv[16]);
	int surv = atoi(argv[17]);
	double town = atof(argv[18]);

	double score = stroke_male(age,b_AF,b_CCF,b_chd,b_ra,b_renal,b_treatedhyp,b_type1,b_type2,b_valvular,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
