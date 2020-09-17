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
#include <StringTools.hpp>
#include <ShellUtilities.hpp>
#include <FileSystem/ChangeDir.hpp>

int main(/*int argc, char** argv*/) {
    ShellVariables var;
    //ShellUtilities::ChangeDir(var.directory);
    while(1) {
        ShellUtilities::SetTerminal(true, true, ">_:", "@");
        std::string data = ShellUtilities::Input();

        data = ShellUtilities::MakeCheckable(data);
        ShellUtilities::ExecuteName("MyShell");
    
        if(strcmp(data.c_str(), "exit") == 0)
                exit(EXIT_SUCCESS);
        else {
                if(strcmp(data.c_str(), "help") == 0)
                        std::cout << "Available commands: cd, version, exit, help, desktop\n";
                else if(strcmp(data.c_str(), "desktop") == 0)
                        std::cout << ShellUtilities::GetDesktopEnvironment() << "\n";
                else if(strcmp(data.c_str(), "version") == 0)
                        std::cout << NAME << " - " << ALL_VERSION << "\n" <<
                        DESC << "\n";
                else if(data.rfind("cd", 0) == 0)
                        ShellUtilities::ChangeDir(ShellUtilities::EraseAllSubString(data,
                                "cd "));
                else
                        ShellUtilities::RunFunction(data);
        }
    }
}