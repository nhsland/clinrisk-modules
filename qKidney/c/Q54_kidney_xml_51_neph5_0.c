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
 * XML source: Q54_kidney_xml_51_neph5_0.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 13:59:57 GMT 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_kidney_xml_51_neph5_0.h>
#include <irisk/util.h>

static double neph5_female_raw(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999950349330902,
		0.999883890151978,
		0.999821722507477,
		0.999749183654785,
		0.999661386013031
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.1467681155300852000000000,
		0.9069329917093114100000000,
		-0.0769419044292020130000000,
		1.1224305908740781000000000,
		0.0118706084001904200000000,
		0.4913159784965747100000000,
		1.2513498001807077000000000,
		0.3049631962804313400000000
	};
	double Ismoke[5] = {
		0,
		0.1982163678862090000000000,
		0.3696807115042248800000000,
		0.0805652774486685930000000,
		0.3552419997737879500000000
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

	age_1 = age_1 - 135.125152587890630;
	age_2 = age_2 - 220.983749389648440;
	bmi_1 = bmi_1 - 0.142878264188766;
	bmi_2 = bmi_2 - 0.139003574848175;
	sbp_1 = sbp_1 - 0.582698464393616;
	sbp_2 = sbp_2 - 0.157353490591049;
	town = town - -0.601529955863953;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0044905211680529760000000;
	a += age_2 * 0.0013741026779469333000000;
	a += bmi_1 * 6.2772064718078511000000000;
	a += bmi_2 * -16.2325496798837570000000000;
	a += sbp_1 * -3.4926352766269355000000000;
	a += sbp_2 * -9.8319594804682797000000000;
	a += town * 0.0418789835204452860000000;

	/* Sum from boolean values */

	a += b_CCF * 1.4931034261471803000000000;
	a += b_cvd * 0.2965409385629423400000000;
	a += b_pvd * 0.5311042284323143100000000;
	a += b_ra * 0.4182846073717931300000000;
	a += b_renalstones * 0.7263237599546400500000000;
	a += b_sle * 1.5446429177437644000000000;
	a += b_treatedhyp * 1.5689061804732225000000000;
	a += b_type1 * 3.1035727563953652000000000;
	a += b_type2 * 1.5424275118825657000000000;
	a += fh_kidney * 1.8581736287905835000000000;

	/* Sum from interaction terms */

	a += age_1 * b_treatedhyp * -0.0962810052821665010000000;
	a += age_1 * b_type1 * 0.1286871175982452500000000;
	a += age_1 * b_type2 * 0.0669892258796831310000000;
	a += age_2 * b_treatedhyp * 0.0423111167651291990000000;
	a += age_2 * b_type1 * -0.0630262286739049910000000;
	a += age_2 * b_type2 * -0.0317986736216282070000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int neph5_female_validation(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,char *errorBuf,int errorBufSize
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

double neph5_female(
int age,int b_CCF,int b_cvd,int b_pvd,int b_ra,int b_renalstones,int b_sle,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int fh_kidney,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = neph5_female_validation(age,b_CCF,b_cvd,b_pvd,b_ra,b_renalstones,b_sle,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return neph5_female_raw(age,b_CCF,b_cvd,b_pvd,b_ra,b_renalstones,b_sle,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,fh_kidney,sbp,smoke_cat,surv,town);
}
