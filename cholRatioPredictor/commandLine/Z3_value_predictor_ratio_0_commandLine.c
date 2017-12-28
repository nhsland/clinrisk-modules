/*
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of cholRatioPredictor (http://svn.clinrisk.co.uk/opensource/cholRatioPredictor).
 * 
 * cholRatioPredictor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * cholRatioPredictor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with cholRatioPredictor.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional disclaimer of warranty.
 * 
 * Our intention in releasing this code is to enable others to implement the cholRatioPredictor algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent others altering the value of the coefficients if they should so wish, thus, in effect, actually creating a different algorithm which has not been subject to scrutiny and peer review, and is no longer cholRatioPredictor.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/cholRatioPredictor.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Z3_value_predictor_ratio_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * This file create date: Tue Apr 27 10:48:38 BST 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <irisk/Z3_value_predictor_ratio_0.h>

static double score[0];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2010 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of cholRatioPredictor (http://svn.clinrisk.co.uk/opensource/cholRatioPredictor).\n");
	printf(" * \n");
	printf(" * cholRatioPredictor is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * cholRatioPredictor is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with cholRatioPredictor.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * As this licence permits change to the source, it is possible that the\n");
	printf(" * coefficients of the algorithm may have been changed.\n");
	printf(" * We strongly recommend that you, the end user, check that the code supplied\n");
	printf(" * with this application faithfully reproduces that published at\n");
	printf(" * http://svn.clinrisk.co.uk/opensource/cholRatioPredictor.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being\n");
	printf(" * given the wrong treatment.\n");
	printf(" * \n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Z3_value_predictor_ratio_0.xml\n");
	printf(" * STATA dta time stamp: 2 Sep 2009 08:55\n");
	printf(" * C file create date: Tue Apr 27 10:48:38 BST 2010\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Z3_value_predictor_ratio_0_commandLine age b_cvd b_treatedhyp b_type2 ethrisk smok\n");
}

int main (int argc, char *argv[]) {
	if (argc!=7) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_cvd = atoi(argv[2]);
	int b_treatedhyp = atoi(argv[3]);
	int b_type2 = atoi(argv[4]);
	int ethrisk = atoi(argv[5]);
	int smok = atoi(argv[6]);

	double score = ratio_female(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
