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

#include <Keywords.hpp>
#include <GetInfo.hpp>
#include <StringTools.hpp>
#include <ShellUtilities.hpp>

#include <Output/Print.hpp>
#include <FileSystem/ChangeDir.hpp>

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

/*
	TODO: Check IsExist.
*/
void ShellUtilities::Echo(std::string argument) {
	if(argument != "") {
                if(argument[0] == '$') { 
                        argument = argument.erase(0, 1);
                        const char* environment = ShellUtilities::GetEnvironment(CSTR(argument));
                        if(environment != NULL)
                                ShellUtilities::Print(environment);
                        else
				PUT("This environment not found.")
		} else
                        ShellUtilities::Print(argument);

                NEWLINE
        }
}