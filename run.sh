#!/usr/bin/env bash
mkdir -p build && cd build && rm -rf * && cmake .. && make && ./quantile-filter