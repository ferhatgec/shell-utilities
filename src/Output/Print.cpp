/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>

#include <Output/Print.hpp>
#include <Keywords.hpp>

int ShellUtilities::Print(std::string format, ...) {
        va_list arg;
  	int done;

  	va_start (arg, format);
  	done = vfprintf (stdout, CSTR(format), arg);
  	va_end (arg);

  	return done;
}

int ShellUtilities::Print(char* format, ...) {
        va_list arg;
  	int done;

  	va_start (arg, format);
        done = vfprintf (stdout, format, arg);
  	va_end (arg);

  	return done;
}

int ShellUtilities::Print(const char* format, ...) {
        va_list arg;
  	int done;

  	va_start (arg, format);
        done = vfprintf (stdout, format, arg);
  	va_end (arg);

  	return done;
}