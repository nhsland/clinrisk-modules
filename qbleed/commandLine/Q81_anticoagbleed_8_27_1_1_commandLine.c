/* 
 * Copyright 2014 ClinRisk Ltd.
 * 
 * This file is part of QBleed (http://qbleed.org, http://svn.clinrisk.co.uk/opensource/qbleed).
 * 
 * QBleed is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QBleed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with QBleed.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qbleed, faithfully implements QBleed.
 * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 * altering the coefficients, getting the inputs wrong, or just poor programming.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qbleed.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q81_anticoagbleed_8_27_1_1.xml
 * STATA dta time stamp: 25 Jan 2014 20:52
 * C file create date: Tue 29 Jul 2014 14:05:50 BST
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q81_anticoagbleed_8_27_1_1.h>

static double score[6];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2014 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QBleed (http://qbleed.org, http://svn.clinrisk.co.uk/opensource/qbleed).\n");
	printf(" * \n");
	printf(" * QBleed is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Affero General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QBleed is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Affero General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Affero General Public License\n");
	printf(" * along with QBleed.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qbleed, faithfully implements QBleed.\n");
	printf(" * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally \n");
	printf(" * altering the coefficients, getting the inputs wrong, or just poor programming. \n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qbleed.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q81_anticoagbleed_8_27_1_1.xml\n");
	printf(" * STATA dta time stamp: 25 Jan 2014 20:52\n");
	printf(" * C file create date: Tue 29 Jul 2014 14:05:50 BST\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q81_anticoagbleed_8_27_1_1_commandLine age alcohol_cat6 b_AF b_anticonvulsant b_antidepressant b_antiplat b_anycancer b_ccf b_corticosteroids b_liverpancreas b_nsaid b_platlet b_treatedhyp b_varices b_vte bmi ethrisk exp_anticoagulant prior_anybleed smoke_cat surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=23) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int alcohol_cat6 = atoi(argv[2]);
	int b_AF = atoi(argv[3]);
	int b_anticonvulsant = atoi(argv[4]);
	int b_antidepressant = atoi(argv[5]);
	int b_antiplat = atoi(argv[6]);
	int b_anycancer = atoi(argv[7]);
	int b_ccf = atoi(argv[8]);
	int b_corticosteroids = atoi(argv[9]);
	int b_liverpancreas = atoi(argv[10]);
	int b_nsaid = atoi(argv[11]);
	int b_platlet = atoi(argv[12]);
	int b_treatedhyp = atoi(argv[13]);
	int b_varices = atoi(argv[14]);
	int b_vte = atoi(argv[15]);
	double bmi = atof(argv[16]);
	int ethrisk = atoi(argv[17]);
	int exp_anticoagulant = atoi(argv[18]);
	int prior_anybleed = atoi(argv[19]);
	int smoke_cat = atoi(argv[20]);
	int surv = atoi(argv[21]);
	double town = atof(argv[22]);

	double score = Q81_anticoagbleed_8_27_1_male(age,alcohol_cat6,b_AF,b_anticonvulsant,b_antidepressant,b_antiplat,b_anycancer,b_ccf,b_corticosteroids,b_liverpancreas,b_nsaid,b_platlet,b_treatedhyp,b_varices,b_vte,bmi,ethrisk,exp_anticoagulant,prior_anybleed,smoke_cat,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
