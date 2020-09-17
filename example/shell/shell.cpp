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
#include <Execute.hpp>
#include <Terminal.hpp>

int main(/*int argc, char** argv*/) {
    while(1) {
        ShellUtilities::SetTerminal(true, true, ">_:", "@");
        std::string data = ShellUtilities::Input();

        data = ShellUtilities::MakeCheckable(data);
        ShellUtilities::ExecuteName("MyShell");
    
        if(strcmp(data.c_str(), "exit") == 0)
                exit(EXIT_SUCCESS);
        else {
                if(strcmp(data.c_str(), "help") == 0)
                        std::cout << "Available commands: exit, help, desktop\n";
                else if(strcmp(data.c_str(), "desktop") == 0)
                        std::cout << ShellUtilities::GetDesktopEnvironment() << "\n";
                else
                        ShellUtilities::RunFunction(data);
        }
    }
}