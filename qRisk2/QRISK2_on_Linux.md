QRISK2 on Linux
====

Installation
----

Ensure you have all the dependencies:

On Ubuntu 16.04:

```
sudo apt-get install build-essential xutils-dev g++-multilib
```

Compile from master via the following commands:

```
git clone https://github.com/robdyke/clinirisk-qRisk2.git
cd clinirisk-qRisk2
mkdir lib
mkdir executables
make
```

Symlinks for clarity
```
cd commandLine
ln -s Q80_model_4_0_commandLine female_risk
ln -s Q80_model_4_1_commandLine male_risk
```

Check Usage notes are returned

```
cd commandLine
./Q80_model_4_0_commandLine|tail --lines=2
Usage:
  Q80_model_4_0_commandLine age b_AF b_ra b_renal b_treatedhyp b_type1 b_type2 bmi ethrisk fh_cvd rati sbp smoke_cat surv town
```

```
cd commandLine
./Q80_model_4_1_commandLine|tail --lines=2
Usage:
  Q80_model_4_1_commandLine age b_AF b_ra b_renal b_treatedhyp b_type1 b_type2 bmi ethrisk fh_cvd rati sbp smoke_cat surv town
```

Notes
----

Townsend Deprivation Scores are not included by Clinrisk. To find Townsend score for a postcode I used the LSOA Townsend Deprivation Scores published by [NHS Wales](http://www.wales.nhs.uk/sitesplus/922/page/49861) and the [Postcode Lookup](http://imd-by-postcode.opendatacommunities.org/) of English indices of deprivation 2015 from DfCLG. I then cross-referenced the LOSA from the DfCLG result with the Score in the NHS Wales spreadsheet.

References
----

- [Calculating Townsend Material Deprivation Score](https://philmikejones.wordpress.com/2014/02/21/calculating-townsend-material-deprivation-score/)
- [LSOA Townsend Deprivation Scores](http://www.wales.nhs.uk/sitesplus/922/page/49861)
- [Townsend Material Deprivation Score - 2011 Data](https://github.com/philmikejones/townsendr)
- [English indices of deprivation 2015](http://imd-by-postcode.opendatacommunities.org/)