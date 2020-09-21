/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>

/* Include all ShellUtilities header files */
#include <GetInput.hpp>
#include <GetInfo.hpp>
#include <Execute.hpp>
#include <Terminal.hpp>
#include <StringTools.hpp>
#include <ShellUtilities.hpp>
#include <FileSystem/ChangeDir.hpp>

#include <Colorized.hpp>

int main(/*int argc, char** argv*/) {
        /* Set directory (Default PWD) */
        ShellUtilities::SetDirectory("/home/");
        
        /* Create variables */

        /* bool 1 : username
           bool 2 : hostname
           bool 3 : directory */
        std::string term = ShellUtilities::SetTerminal(true, true, true, ">_: ", "@", "~");
        std::string data;
        
        /* Type 'exit' to exit */
        while(1) {
                /* username@hostname >_: */
                std::cout << term;

                /* White color */
                ShellUtilities::printfc(ShellUtilities::colorize(TYPE::LIGHT,
                        WHITE), false, nullptr);

                /* Input */
                data = ShellUtilities::Input();
                
                RESETB /* Reset color */

                /* Check string and delete last character */
                data = ShellUtilities::MakeCheckable(data);

                /* Execute commands (If you get an error, ExecuteName showed in terminal) */
                ShellUtilities::ExecuteName("MyShell");
    
                /* Check if data equals 'exit' */
                if(strcmp(data.c_str(), "exit") == 0)
                        exit(EXIT_SUCCESS);
                else {
                        /* Check if data equals 'help */
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
                        else /* Other commands from system */
                                ShellUtilities::RunFunction(data);
                }
        }
}