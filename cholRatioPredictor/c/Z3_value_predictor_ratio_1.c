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
 * XML source: Z3_value_predictor_ratio_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * This file create date: Tue Apr 27 10:48:48 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Z3_value_predictor_ratio_1.h>
#include <irisk/util.h>

static double ratio_male_raw(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok
)
{
	double survivor[0] = {
		
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.1100374010434674700000000,
		0.4093066105061595200000000,
		0.2874959262741853000000000,
		0.1308338501645004100000000,
		-0.3268904406779559200000000,
		-0.2269143207410783100000000,
		-0.2492322107787566200000000,
		0.0321044739270111010000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = log(dage)-1;
	double age_2 = pow(dage,3);

	/* Centring the continuous variables */

	age_1 = age_1 - 1.596475720405579;
	age_2 = age_2 - 120.232498168945310;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * -0.1814016673631636800000000;
	a += age_2 * -0.0014903322520875473000000;

	/* Sum from boolean values */

	a += b_cvd * -0.3255409069351661300000000;
	a += b_treatedhyp * -0.0914247766297792420000000;
	a += b_type2 * -0.1363936032424035700000000;
	a += smok * 0.1129269427748361800000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = a + 4.3604054874307758000000000;
	return score;
}

static int ratio_male_validation(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(smok)) {
		ok=0;
		strlcat(errorBuf,"error: smok must be in range (0,1)\n",errorBufSize);
	}
	return ok;
}

double ratio_male(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = ratio_male_validation(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return ratio_male_raw(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok);
}
