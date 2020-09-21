/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <fstream>

#include <Keywords.hpp>
#include <FileSystem/Read.hpp>
#include <Output/Print.hpp>

void ShellUtilities::ReadText(std::string dir) {
        std::string line;
        std::ifstream readfile(CSTR(dir));
        
        if(readfile.is_open()) {
                while (std::getline(readfile, line))
                        ShellUtilities::Print(line + "\n");

                readfile.close();
        }
        
        line.erase();
}

void ShellUtilities::ReadText(std::string dir, std::string copy) {
        std::string line;
        std::ifstream readfile(CSTR(dir));

        copy.erase();

        if(readfile.is_open()) {
                while(std::getline(readfile, line))
                        copy.append(line + "\n");                

                readfile.close();
        }

        line.erase();
}