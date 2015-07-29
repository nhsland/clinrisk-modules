/*
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of bmiPredictor (http://svn.clinrisk.co.uk/opensource/bmiPredictor).
 * 
 * bmiPredictor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * bmiPredictor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with bmiPredictor.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional disclaimer of warranty.
 * 
 * Our intention in releasing this code is to enable others to implement the bmiPredictor algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent others altering the value of the coefficients if they should so wish, thus, in effect, actually creating a different algorithm which has not been subject to scrutiny and peer review, and is no longer bmiPredictor.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/bmiPredictor.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Z3_value_predictor_bmi_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * This file create date: Tue Apr 27 10:22:40 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Z3_value_predictor_bmi_1.h>
#include <irisk/util.h>

static double bmi_male_raw(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok
)
{
	double survivor[0] = {
		
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		-2.1042160128013245000000000,
		-1.4419229744210469000000000,
		-2.8553325672263821000000000,
		-1.7150155796255639000000000,
		-0.5947710630002244200000000,
		-0.9690210547452095000000000,
		-3.2251765711555191000000000,
		-0.8458696734492524600000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);

	/* Centring the continuous variables */

	age_1 = age_1 - 120.232498168945310;
	age_2 = age_2 - 191.948272705078120;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 0.0110800150275389630000000;
	a += age_2 * -0.0072500972309126341000000;

	/* Sum from boolean values */

	a += b_cvd * 0.3803271155735959400000000;
	a += b_treatedhyp * 1.6470485255197904000000000;
	a += b_type2 * 2.2897921814125404000000000;
	a += smok * -1.0622108176736400000000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = a + 27.7661149628103270000000000;
	return score;
}

static int bmi_male_validation(
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

double bmi_male(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = bmi_male_validation(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return bmi_male_raw(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok);
}
