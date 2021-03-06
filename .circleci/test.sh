#!/usr/bin/env bash

mkdir /tmp/cnl
cd /tmp/cnl

apt-get update
apt-get install -y $1 cmake libboost-dev

cmake -DCMAKE_BUILD_TYPE=Release -DCNL_DEV=ON -DCNL_INT128=$2 -DCNL_STD=$3 /root/project
cmake --build . -- -j 8

ctest --output-on-failure -j 4
src/benchmark/Benchmark
