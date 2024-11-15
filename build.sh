#!/bin/bash

rm ./voltmeter.dll
x86_64-w64-mingw32-gcc --shared -o ./voltmeter.dll ./src/voltmeter.c
