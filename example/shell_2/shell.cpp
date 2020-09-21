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
#include <Keywords.hpp>

#include <FileSystem/ChangeDir.hpp>
#include <FileSystem/List.hpp>
#include <FileSystem/Read.hpp>

#include <Output/Colorized.hpp>
#include <Output/Print.hpp>

/* Help */
void Help() {
        ShellUtilities::Print("Available commands: fcat, cd, ls, version, exit, help, desktop\n");
}

/* ~directory::username @> */
void TInput() {
        BLUE_COLOR
        ShellUtilities::SetDirectorySign("~");
        LIGHT_CYAN_COLOR
        ShellUtilities::SetDirectoryName();

        LIGHT_GREEN_COLOR
        ShellUtilities::SetSign("::");

        LIGHT_MAGENTA_COLOR
        ShellUtilities::SetUsername(false, "");
        
        YELLOW_COLOR
        /* Input sign looks like ice cream */
        ShellUtilities::SetInputSign("@> ");
}

int main(/*int argc, char** argv*/) {
        /* Set directory (Default PWD) */
        ShellUtilities::SetDirectory(ShellUtilities::GetEnvironmentString("HOME"));
        
        /* Create variables */

        /* bool 1 : username
           bool 2 : hostname
           bool 3 : directory */
        std::string data;
        
        /* Type 'exit' to exit */
        while(1) {
                /* username@hostname >_: */
                TInput();

                /* White color */
                LIGHT_WHITE_COLOR
                /* Input */
                data = ShellUtilities::Input();
                
                RESETB /* Reset color */

                /* Check string and delete last character */
                data = ShellUtilities::MakeCheckable(data);

                /* Execute commands (If you get an error, ExecuteName showed in terminal) */
                ShellUtilities::ExecuteName("MyShell");
    
                /* Check if data equals 'exit' */
                if(ShellUtilities::Compare(CSTR(data), "exit") == 0)
                        exit(EXIT_SUCCESS);
                else {
                        /* Check if data equals 'help */
                        if(ShellUtilities::Compare(CSTR(data), "help") == 0)
                                Help();
                        else if(ShellUtilities::Compare(CSTR(data), "desktop") == 0)
                                ShellUtilities::Print(ShellUtilities::GetDesktopEnvironment() + "\n");
                        else if(ShellUtilities::Compare(CSTR(data), "version") == 0)
                                ShellUtilities::Print(NAME + STRC(" - ")  + ALL_VERSION + "\n" + DESC + "\n");
                        else if(data.rfind("cd", 0) == 0)
                                ShellUtilities::ChangeDir(ShellUtilities::EraseAllSubString(data,
                                        "cd "));
                        else if(ShellUtilities::Compare(CSTR(data), "ls") == 0)
                                ShellUtilities::DefaultList(true, "");
                        else if(data.rfind("fcat", 0) == 0) {
                                data = ShellUtilities::EraseAllSubString(data, "fcat ");
                                ShellUtilities::ReadText(ShellUtilities::GetCurrentWorkingDir() + "/" + data);
                        } else /* Other commands from system */
                                ShellUtilities::RunFunction(data);
                }
        }
}