#!/usr/bin/env bash
mkdir build
cd build
cmake ..
make idcache
make cachelfu
python3 ./testSys/generateTests.py