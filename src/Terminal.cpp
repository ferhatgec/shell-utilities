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

void ShellUtilities::SetTerminal(bool username, bool hostname, 
        std::string input_sign, std::string special_sign) {
        std::string terminal;
        if(username == true)
                terminal.append(ShellUtilities::GetUsername());

        if(username == true && hostname == true)
                terminal.append(special_sign + ShellUtilities::GetHostname());

        if(hostname == true && username != true)
                terminal.append(ShellUtilities::GetHostname());

        terminal.append(" " + input_sign + " ");

        std::cout << terminal;
}