/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <fstream>

#include <Keywords.hpp>
#include <StringTools.hpp>
#include <FileSystem/Create.hpp>

void ShellUtilities::CreateFile(std::string directory, std::string name, std::string data) {
        if(directory[directory.length() - 1] != '/')
                directory = directory + "/" + name;
        else
                directory = directory + name;
        
        std::ofstream file(directory, std::ios::app);

        file << data;
    	file.close();
}

void ShellUtilities::CreateFile(std::string directory, std::string data) {
        std::ofstream file(directory, std::ios::app);

    	file << data;

    	file.close();
}

/*
        WA : Without append.
*/
void ShellUtilities::CreateFileWA(std::string directory, std::string name) {
        if(directory[directory.length() - 1] != '/')
                directory = directory + "/" + name;
        else
                directory = directory + name;
        
    	std::ofstream file(directory);
    	file.close();
}

void ShellUtilities::CreateFileWA(std::string directory) {
    	std::ofstream file(directory);
    	file.close();
}