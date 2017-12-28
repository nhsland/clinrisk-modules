/* 
 * Copyright 2014 ClinRisk Ltd.
 * 
 * This file is part of QThrombosis-2014 (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).
 * 
 * QThrombosis-2014 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QThrombosis-2014 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with QThrombosis-2014.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis-2014.
 * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 * altering the coefficients, getting the inputs wrong, or just poor programming.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q88_vte_2014_0.xml
 * STATA dta time stamp: 17 Jun 2014 22:53
 * C file create date: Fri 11 Sep 2015 10:36:27 BST
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q88_vte_2014_0.h>

static double score[6];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2014 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QThrombosis-2014 (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).\n");
	printf(" * \n");
	printf(" * QThrombosis-2014 is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Affero General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QThrombosis-2014 is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Affero General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Affero General Public License\n");
	printf(" * along with QThrombosis-2014.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis-2014.\n");
	printf(" * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally \n");
	printf(" * altering the coefficients, getting the inputs wrong, or just poor programming. \n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q88_vte_2014_0.xml\n");
	printf(" * STATA dta time stamp: 17 Jun 2014 22:53\n");
	printf(" * C file create date: Fri 11 Sep 2015 10:36:27 BST\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q88_vte_2014_0_commandLine age b_CCF b_admit b_antipsychotic b_anycancer b_cop b_copd b_hrt b_ibd b_renal b_tamoxifen b_varicosevein bmi smoke_cat surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=17) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_CCF = atoi(argv[2]);
	int b_admit = atoi(argv[3]);
	int b_antipsychotic = atoi(argv[4]);
	int b_anycancer = atoi(argv[5]);
	int b_cop = atoi(argv[6]);
	int b_copd = atoi(argv[7]);
	int b_hrt = atoi(argv[8]);
	int b_ibd = atoi(argv[9]);
	int b_renal = atoi(argv[10]);
	int b_tamoxifen = atoi(argv[11]);
	int b_varicosevein = atoi(argv[12]);
	double bmi = atof(argv[13]);
	int smoke_cat = atoi(argv[14]);
	int surv = atoi(argv[15]);
	double town = atof(argv[16]);

	double score = vte_female(age,b_CCF,b_admit,b_antipsychotic,b_anycancer,b_cop,b_copd,b_hrt,b_ibd,b_renal,b_tamoxifen,b_varicosevein,bmi,smoke_cat,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
