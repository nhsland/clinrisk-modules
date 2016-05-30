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

Example
--------

Check Usage notes are returned

```
cd commandLine
./Q80_model_4_0_commandLine
```