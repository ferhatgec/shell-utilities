#!/bin/sh

g++ -I../../include/ \
../../src/GetInput.cpp \
../../src/GetInfo.cpp \
../../src/Execute.cpp \
../../src/Terminal.cpp \
../../src/FileSystem/ChangeDir.cpp \
../../src/FileSystem/Read.cpp \
../../src/StringTools.cpp \
../../src/Output/Colorized.cpp \
../../src/Output/Print.cpp \
../../src/FileSystem/List.cpp shell.cpp -o shell