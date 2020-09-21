/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>

#include <GetInfo.hpp>
#include <Terminal.hpp>
#include <ShellUtilities.hpp>

std::string ShellUtilities::SetTerminal(bool username, bool hostname, bool directory,
        std::string input_sign, std::string special_sign, std::string directory_sign) {
        ShellVariables var;
        std::string terminal;

        if(username == true) {
                terminal.append(ShellUtilities::GetUsername());
                if(hostname == true) {
                        terminal.append(special_sign + ShellUtilities::GetHostname());
                        if(directory == true) {
                                terminal.append(" " + directory_sign + var.directory);
                        } 

                } else
                        if(directory == true)
                                terminal.append(" " + directory_sign + var.directory);
        }
        
        if(username != true) {
                if(hostname == true) {
                        terminal.append(ShellUtilities::GetHostname());
                        if(directory == true) {
                                terminal.append(" " + directory_sign + var.directory);
                        }
                } else {
                        if(directory == true)
                                terminal.append(" " + directory_sign + var.directory); 
                }
        }

        terminal.append(" " + input_sign);

        return terminal;
}

void
ShellUtilities::SetUsername(bool different, std::string different_tag) {
        if(different == true)
                std::cout << different_tag;
        else
                std::cout << ShellUtilities::GetUsername();
}

void
ShellUtilities::SetHostname(bool different, std::string different_tag) {
        if(different == true)
                std::cout << different_tag;
        else
                std::cout << ShellUtilities::GetHostname();
}

void
ShellUtilities::SetDirectoryName() {
        ShellVariables var;
        std::cout << var.directory;
}

void 
ShellUtilities::SetInputSign(std::string input_sign) {
        std::cout << input_sign;
}

void
ShellUtilities::SetDirectorySign(std::string dir_sign) {
        std::cout << dir_sign;
}

void
ShellUtilities::SetSign(std::string sign) {
        std::cout << sign;
}