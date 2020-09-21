/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>

#include <GetInfo.hpp>
#include <StringTools.hpp>
#include <Keywords.hpp>
#include <Output/Colorized.hpp>
#include <Output/Print.hpp>

#include <FileSystem/ChangeDir.hpp>

#include <echo.hpp>

void ShellUtilities::Echo(std::string argument) {
        if(argument != "") {
                if(argument[0] == '$') { 
                        argument = argument.erase(0, 1);
                        const char* environment = ShellUtilities::GetEnvironment(CSTR(argument));
                        if(environment != NULL)
                                ShellUtilities::Print(environment);
                        else
                                ShellUtilities::Print("Not found?");
                } else
                        ShellUtilities::Print(argument);

                NEWLINE
        }
}