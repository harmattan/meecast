#!/bin/sh
qmake -recursive
make
export LD_LIBRARY_PATH=$PWD/core:$LD_LIBRARY_PATH
test/test_omweather