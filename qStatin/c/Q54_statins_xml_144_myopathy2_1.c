/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QStatin (http://svn.clinrisk.co.uk/opensource/qstatin).
 * 
 * QStatin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QStatin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QStatin.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qstatin, faithfully implements QStatin.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qstatin.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q54_statins_xml_144_myopathy2_1.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:29 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_myopathy2_1.h>
#include <irisk/util.h>

static double myopathy2_male_raw(
int age,int b_corticosteroids,int b_type2,double bmi,int ethrisk,int statin_user,int surv
)
{
	double survivor[6] = {
		0,
		0.999862909317017,
		0.999759376049042,
		0.999643027782440,
		0.999539434909821,
		0.999462902545929
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.6730445001848017700000000,
		0.5203621569657034300000000,
		-0.5005247720528726000000000,
		-0.7262423829507156400000000,
		1.8828574020986715000000000,
		2.0630618650724735000000000,
		0.7397600055210054000000000,
		1.0421643888685721000000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);

	/* Centring the continuous variables */

	age_1 = age_1 - 122.873908996582030;
	age_2 = age_2 - 197.055297851562500;
	bmi = bmi - 26.581932067871094;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 0.0073253371353815657000000;
	a += age_2 * -0.0030552338963668281000000;
	a += bmi * 0.0257133350386265470000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 0.7361597695039536800000000;
	a += b_type2 * 0.3215625154608592900000000;
	a += statin_user * 1.8170393264592091000000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int myopathy2_male_validation(
int age,int b_corticosteroids,int b_type2,double bmi,int ethrisk,int statin_user,int surv,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,20,40)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (20,40)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(statin_user)) {
		ok=0;
		strlcat(errorBuf,"error: statin_user must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,5)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,5)\n",errorBufSize);
	}
	return ok;
}

double myopathy2_male(
int age,int b_corticosteroids,int b_type2,double bmi,int ethrisk,int statin_user,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = myopathy2_male_validation(age,b_corticosteroids,b_type2,bmi,ethrisk,statin_user,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return myopathy2_male_raw(age,b_corticosteroids,b_type2,bmi,ethrisk,statin_user,surv);
}
