#!/bin/sh

g++ -I../../include/ ../../src/GetInput.cpp ../../src/GetInfo.cpp \
../../src/Execute.cpp ../../src/Terminal.cpp shell.cpp -o shell