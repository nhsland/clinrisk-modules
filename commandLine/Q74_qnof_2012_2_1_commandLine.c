/* 
 * Copyright 2012 ClinRisk Ltd.
 * 
 * This file is part of QFracture-2012 (http://qfracture.org, http://svn.clinrisk.co.uk/qfracture).
 * 
 * QFracture-2012 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QFracture-2012 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QFracture-2012.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/qfracture, faithfully implements QFracture-2012.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/qfracture.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q74_qnof_2012_2_1.xml
 * STATA dta time stamp: 1 Mar 2012 11:21
 * C file create date: Mon  5 Mar 2012 11:14:42 GMT
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q74_qnof_2012_2_1.h>

static double score[19];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2012 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QFracture-2012 (http://qfracture.org, http://svn.clinrisk.co.uk/qfracture).\n");
	printf(" * \n");
	printf(" * QFracture-2012 is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QFracture-2012 is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QFracture-2012.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/qfracture, faithfully implements QFracture-2012.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/qfracture.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q74_qnof_2012_2_1.xml\n");
	printf(" * STATA dta time stamp: 1 Mar 2012 11:21\n");
	printf(" * C file create date: Mon  5 Mar 2012 11:14:42 GMT\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q74_qnof_2012_2_1_commandLine age alcohol_cat6 b_antidepressant b_anycancer b_asthmacopd b_carehome b_corticosteroids b_cvd b_dementia b_epilepsy2 b_falls b_fracture4 b_liver b_parkinsons b_ra_sle b_renal b_type1 b_type2 bmi ethrisk fh_osteoporosis smoke_cat surv\n");
}

int main (int argc, char *argv[]) {
	if (argc!=24) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int alcohol_cat6 = atoi(argv[2]);
	int b_antidepressant = atoi(argv[3]);
	int b_anycancer = atoi(argv[4]);
	int b_asthmacopd = atoi(argv[5]);
	int b_carehome = atoi(argv[6]);
	int b_corticosteroids = atoi(argv[7]);
	int b_cvd = atoi(argv[8]);
	int b_dementia = atoi(argv[9]);
	int b_epilepsy2 = atoi(argv[10]);
	int b_falls = atoi(argv[11]);
	int b_fracture4 = atoi(argv[12]);
	int b_liver = atoi(argv[13]);
	int b_parkinsons = atoi(argv[14]);
	int b_ra_sle = atoi(argv[15]);
	int b_renal = atoi(argv[16]);
	int b_type1 = atoi(argv[17]);
	int b_type2 = atoi(argv[18]);
	double bmi = atof(argv[19]);
	int ethrisk = atoi(argv[20]);
	int fh_osteoporosis = atoi(argv[21]);
	int smoke_cat = atoi(argv[22]);
	int surv = atoi(argv[23]);

	double score = nof_male(age,alcohol_cat6,b_antidepressant,b_anycancer,b_asthmacopd,b_carehome,b_corticosteroids,b_cvd,b_dementia,b_epilepsy2,b_falls,b_fracture4,b_liver,b_parkinsons,b_ra_sle,b_renal,b_type1,b_type2,bmi,ethrisk,fh_osteoporosis,smoke_cat,surv,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
