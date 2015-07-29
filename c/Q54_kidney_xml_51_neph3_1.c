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
 * XML source: Q54_kidney_xml_51_neph3_1.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 13:59:40 GMT 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_kidney_xml_51_neph3_1.h>
#include <irisk/util.h>

static double neph3_male_raw(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999482631683350,
		0.998838543891907,
		0.997995197772980,
		0.997083306312561,
		0.996157050132751
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.1503591855029934300000000,
		0.6943866103945839400000000,
		0.3024824702548107900000000,
		0.3642866825390685400000000,
		-0.1882622611530610500000000,
		0.1607974560923533000000000,
		0.3066453676549667500000000,
		0.2851705993387653200000000
	};
	double Ismoke[5] = {
		0,
		0.1214425082432345500000000,
		0.1382410437354289800000000,
		0.2137214276315931300000000,
		0.2196760294878585000000000
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

	age_1 = age_1 - 129.786895751953120;
	age_2 = age_2 - 210.509735107421870;
	bmi_1 = bmi_1 - 0.138382270932198;
	bmi_2 = bmi_2 - 0.136841759085655;
	sbp_1 = sbp_1 - 0.551519691944122;
	sbp_2 = sbp_2 - 0.861767768859863;
	town = town - -0.442225903272629;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0372566306865022980000000;
	a += age_2 * -0.0124595530436500700000000;
	a += bmi_1 * 4.0321363736131879000000000;
	a += bmi_2 * -16.7941762226878630000000000;
	a += sbp_1 * 5.0163247808020985000000000;
	a += sbp_2 * -14.8269303572075850000000000;
	a += town * 0.0196103062056626580000000;

	/* Sum from boolean values */

	a += b_CCF * 1.0432290439580310000000000;
	a += b_cvd * 0.3335059339906052400000000;
	a += b_nsaid * 0.2536071471853483300000000;
	a += b_pvd * 0.3838631945620650800000000;
	a += b_ra * 0.3906860206278776100000000;
	a += b_treatedhyp * 1.0232261464655623000000000;
	a += b_type1 * 2.5075410232894906000000000;
	a += b_type2 * 1.8034937790520313000000000;
	a += fh_kidney * 1.2749066751148557000000000;

	/* Sum from interaction terms */

	a += age_1 * b_treatedhyp * -0.0259849886240969550000000;
	a += age_1 * b_type1 * -0.0426774334972716550000000;
	a += age_1 * b_type2 * -0.0233621962388147270000000;
	a += age_2 * b_treatedhyp * 0.0109255079387530760000000;
	a += age_2 * b_type1 * 0.0172196192195575690000000;
	a += age_2 * b_type2 * 0.0087552424939960610000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int neph3_male_validation(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,char *errorBuf,int errorBufSize
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
	if (!is_boolean(b_nsaid)) {
		ok=0;
		strlcat(errorBuf,"error: b_nsaid must be in range (0,1)\n",errorBufSize);
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

double neph3_male(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = neph3_male_validation(age,b_CCF,b_cvd,b_nsaid,b_pvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return neph3_male_raw(age,b_CCF,b_cvd,b_nsaid,b_pvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town);
}
