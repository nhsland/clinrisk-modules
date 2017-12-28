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
 * XML source: Q54_kidney_xml_51_neph3_0.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 13:59:22 GMT 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_kidney_xml_51_neph3_0.h>
#include <irisk/util.h>

static double neph3_female_raw(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999198436737061,
		0.998197913169861,
		0.996961772441864,
		0.995605170726776,
		0.994150519371033
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.0297650380606283470000000,
		0.4355484308510417800000000,
		0.4023403121262871300000000,
		0.1510682354063334300000000,
		-0.7276014058191869700000000,
		-0.5721584379149783400000000,
		0.1202074407607906200000000,
		0.2033300432421270600000000
	};
	double Ismoke[5] = {
		0,
		0.1729462730516562200000000,
		0.2650781109145369800000000,
		0.2382936894338313600000000,
		0.3575551750075979800000000
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
	double sbp_2 = pow(dsbp,-2)*log(dsbp);

	/* Centring the continuous variables */

	age_1 = age_1 - 134.033187866210940;
	age_2 = age_2 - 218.835433959960940;
	bmi_1 = bmi_1 - 0.143204286694527;
	bmi_2 = bmi_2 - 0.139157548546791;
	sbp_1 = sbp_1 - 0.583845973014832;
	sbp_2 = sbp_2 - 0.157089039683342;
	town = town - -0.607831299304962;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0484371529894231380000000;
	a += age_2 * -0.0176947701133479510000000;
	a += bmi_1 * 1.1105635237480727000000000;
	a += bmi_2 * -12.3690966232258340000000000;
	a += sbp_1 * -2.1086300793705433000000000;
	a += sbp_2 * -5.6186919081620603000000000;
	a += town * 0.0292990623642085740000000;

	/* Sum from boolean values */

	a += b_CCF * 0.8212875143069400300000000;
	a += b_cvd * 0.3154860928614339800000000;
	a += b_nsaid * 0.2632188743293689700000000;
	a += b_pvd * 0.3010113193737247200000000;
	a += b_ra * 0.4833725257627346500000000;
	a += b_renalstones * 0.2396724646518308700000000;
	a += b_sle * 0.8756342355289874500000000;
	a += b_treatedhyp * 0.9124721274488373200000000;
	a += b_type1 * 2.1047508138768976000000000;
	a += b_type2 * 1.5036808227335385000000000;
	a += fh_kidney * 0.7566335640404944200000000;

	/* Sum from interaction terms */

	a += age_1 * b_treatedhyp * -0.0160237949945248210000000;
	a += age_1 * b_type1 * -0.0315227477366860010000000;
	a += age_1 * b_type2 * -0.0280393344533675890000000;
	a += age_2 * b_treatedhyp * 0.0064950068136830665000000;
	a += age_2 * b_type1 * 0.0123621801957671720000000;
	a += age_2 * b_type2 * 0.0112916792022569050000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int neph3_female_validation(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,char *errorBuf,int errorBufSize
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
	if (!is_boolean(b_renalstones)) {
		ok=0;
		strlcat(errorBuf,"error: b_renalstones must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_sle)) {
		ok=0;
		strlcat(errorBuf,"error: b_sle must be in range (0,1)\n",errorBufSize);
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

double neph3_female(
int age,int b_CCF,int b_cvd,int b_nsaid,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = neph3_female_validation(age,b_CCF,b_cvd,b_nsaid,b_pvd,b_ra,b_renalstones,b_sle,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return neph3_female_raw(age,b_CCF,b_cvd,b_nsaid,b_pvd,b_ra,b_renalstones,b_sle,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town);
}
