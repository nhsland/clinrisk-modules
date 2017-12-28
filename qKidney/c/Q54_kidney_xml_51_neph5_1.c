/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QKidney-2010 (http://qkidney.org, http://svn.clinrisk.co.uk/opensource/qkidney).
 * 
 * QKidney-2010 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QKidney-2010 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QKidney-2010.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qkidney, faithfully implements QKidney-2010.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qkidney.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q54_kidney_xml_51_neph5_1.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 14:00:12 GMT 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_kidney_xml_51_neph5_1.h>
#include <irisk/util.h>

static double neph5_male_raw(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999939739704132,
		0.999862551689148,
		0.999781429767609,
		0.999686837196350,
		0.999580204486847
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.3118422281234448600000000,
		0.6046214991605259900000000,
		0.1997351989363300700000000,
		0.8719077058136131000000000,
		0.4472807032846115000000000,
		0.6239995832114189100000000,
		-39.8772311231235220000000000,
		-0.0403646857587661450000000
	};
	double Ismoke[5] = {
		0,
		0.1448433047793812300000000,
		0.1604938050389068700000000,
		0.2879969011526650200000000,
		0.0857451407666546960000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = pow(dbmi,-2)*log(dbmi);
	double dsbp = sbp;
	dsbp=dsbp/100;
	double sbp_1 = pow(dsbp,-2);
	double sbp_2 = pow(dsbp,-.5);

	/* Centring the continuous variables */

	age_1 = age_1 - 130.458740234375000;
	age_2 = age_2 - 211.823989868164060;
	bmi_1 = bmi_1 - 0.138219580054283;
	bmi_2 = bmi_2 - 0.136762171983719;
	sbp_1 = sbp_1 - 0.551189959049225;
	sbp_2 = sbp_2 - 0.861638963222504;
	town = town - -0.442067831754684;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0184006601576099170000000;
	a += age_2 * -0.0048768304842849858000000;
	a += bmi_1 * 10.3099642227217410000000000;
	a += bmi_2 * -23.3594109892901290000000000;
	a += sbp_1 * 6.4536856404376355000000000;
	a += sbp_2 * -19.1115753263925220000000000;
	a += town * 0.0191429999185772260000000;

	/* Sum from boolean values */

	a += b_CCF * 1.3921380045634140000000000;
	a += b_cvd * 0.2955530208386106300000000;
	a += b_pvd * 0.6843946875219021300000000;
	a += b_ra * 0.4270658680222138600000000;
	a += b_treatedhyp * 1.9121501989990664000000000;
	a += b_type1 * 2.4260612036077056000000000;
	a += b_type2 * 1.0249996940958706000000000;
	a += fh_kidney * 2.2703957707797713000000000;

	/* Sum from interaction terms */

	a += age_1 * b_treatedhyp * -0.0814284149461020350000000;
	a += age_1 * b_type1 * 0.0058630274302377793000000;
	a += age_1 * b_type2 * 0.0409331247189833530000000;
	a += age_2 * b_treatedhyp * 0.0349522187288968940000000;
	a += age_2 * b_type1 * -0.0053628404874913266000000;
	a += age_2 * b_type2 * -0.0195394363574293430000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int neph5_male_validation(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,35,74)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (35,74)\n",errorBufSize);
	}
	if (!is_boolean(b_CCF)) {
		ok=0;
		strlcat(errorBuf,"error: b_CCF must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_pvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_pvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_ra)) {
		ok=0;
		strlcat(errorBuf,"error: b_ra must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type1)) {
		ok=0;
		strlcat(errorBuf,"error: b_type1 must be in range (0,1)\n",errorBufSize);
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
	if (!is_boolean(fh_kidney)) {
		ok=0;
		strlcat(errorBuf,"error: fh_kidney must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(sbp,70,210)) {
		ok=0;
		strlcat(errorBuf,"error: sbp must be in range (70,210)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,5)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,5)\n",errorBufSize);
	}
	if (!d_in_range(town,-7,11)) {
		ok=0;
		strlcat(errorBuf,"error: town must be in range (-7,11)\n",errorBufSize);
	}
	return ok;
}

double neph5_male(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = neph5_male_validation(age,b_CCF,b_cvd,b_pvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return neph5_male_raw(age,b_CCF,b_cvd,b_pvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town);
}
