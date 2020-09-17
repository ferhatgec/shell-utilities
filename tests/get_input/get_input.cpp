/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <GetInput.hpp>
#include <GetInfo.hpp>

int main(/*int argc, char** argv*/) {
    std::cout << ShellUtilities::GetUsername() << "@" << ShellUtilities::GetHostname() << " #> ";
    std::string data = ShellUtilities::Input();
    if(strcmp(data.c_str(), "help\n") == 0)
        std::cout << "Help.\n";
    else if(strcmp(data.c_str(), "desktop\n") == 0)
        std::cout << ShellUtilities::GetDesktopEnvironment() << "\n";
    else
        std::cout << "Available commands: help, desktop\n";
}