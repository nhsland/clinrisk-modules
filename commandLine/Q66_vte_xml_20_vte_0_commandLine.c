/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QThrombosis (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).
 * 
 * QThrombosis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QThrombosis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QThrombosis.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q66_vte_xml_20_vte_0.xml
 * STATA dta time stamp: 20 Mar 2011 13:10
 * C file create date: Mon 15 Aug 2011 18:50:57 BST
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q66_vte_xml_20_vte_0.h>

static double score[6];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2011 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QThrombosis (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).\n");
	printf(" * \n");
	printf(" * QThrombosis is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QThrombosis is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QThrombosis.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q66_vte_xml_20_vte_0.xml\n");
	printf(" * STATA dta time stamp: 20 Mar 2011 13:10\n");
	printf(" * C file create date: Mon 15 Aug 2011 18:50:57 BST\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q66_vte_xml_20_vte_0_commandLine age antipsychotics_current b_CCF b_anycancer b_copd b_ibd b_renal b_varicosevein bmi cop_current hrt_current smoke_cat surv tamoxifen_current z1_admit\n");
}

int main (int argc, char *argv[]) {
	if (argc!=16) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int antipsychotics_current = atoi(argv[2]);
	int b_CCF = atoi(argv[3]);
	int b_anycancer = atoi(argv[4]);
	int b_copd = atoi(argv[5]);
	int b_ibd = atoi(argv[6]);
	int b_renal = atoi(argv[7]);
	int b_varicosevein = atoi(argv[8]);
	double bmi = atof(argv[9]);
	int cop_current = atoi(argv[10]);
	int hrt_current = atoi(argv[11]);
	int smoke_cat = atoi(argv[12]);
	int surv = atoi(argv[13]);
	int tamoxifen_current = atoi(argv[14]);
	int z1_admit = atoi(argv[15]);

	double score = vte_female(age,antipsychotics_current,b_CCF,b_anycancer,b_copd,b_ibd,b_renal,b_varicosevein,bmi,cop_current,hrt_current,smoke_cat,surv,tamoxifen_current,z1_admit,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
