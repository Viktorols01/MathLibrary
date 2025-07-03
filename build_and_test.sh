#!/usr/bin/env bash
cmake -S src -B build -G "Ninja"; ninja -C build ManualTest AutoTest
ctest --test-dir build
