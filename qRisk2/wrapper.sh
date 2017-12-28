#!/bin/bash
# Wrapper around qRisk2 commandline

# Input values set here
age=64
b_AF=1
b_ra=1
b_renal=1
b_treatedhyp=1
b_type1=1
b_type2=0
bmi=24.9
ethrisk=1
fh_cvd=1
rati=5
sbp=140
smoke_cat=0
surv=10
town=3.80
q_path=commandLine

# Echo the values
echo "Values : age=$age b_AF=$b_AF b_ra=$b_ra b_renal=$b_renal b_treatedhyp=$b_treatedhyp b_type1=$b_type1 b_type2=$b_type2 bmi=$bmi ethrisk=$ethrisk fh_cvd=$fh_cvd rati=$rati sbp=$sbp smoke_cat=$smoke_cat surv=$surv town=$town"

if [ $1 = male ] ; then
	q_command="Q80_model_4_1_commandLine"
#	echo "./$q_path/$q_command $age $b_AF $b_ra $b_renal $b_treatedhyp $b_type1 $b_type2 $bmi $ethrisk $fh_cvd $rati $sbp $smoke_cat $surv $town";
	q_score=`./$q_path/$q_command $age $b_AF $b_ra $b_renal $b_treatedhyp $b_type1 $b_type2 $bmi $ethrisk $fh_cvd $rati $sbp $smoke_cat $surv $town`
	echo "Score  : $q_score"
fi

if [ $1 = female ] ; then
	q_command="Q80_model_4_0_commandLine";
#	echo "./$q_path/$q_command $age $b_AF $b_ra $b_renal $b_treatedhyp $b_type1 $b_type2 $bmi $ethrisk $fh_cvd $rati $sbp $smoke_cat $surv $town";
	q_score=`./$q_path/$q_command $age $b_AF $b_ra $b_renal $b_treatedhyp $b_type1 $b_type2 $bmi $ethrisk $fh_cvd $rati $sbp $smoke_cat $surv $town`
	echo "Score  : $q_score"
fi

exit 0