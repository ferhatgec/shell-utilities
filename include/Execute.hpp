/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include <iostream>

namespace ShellUtilities {
    /* From ExecutePlusPlus library */
    void ExecuteName(const char* exec_name);
    void ParseSpace(char* str, char** parsed);
    void ExecuteArgs(char** parsed);
    void ExecuteArgsPiped(char** parsed, char** parsedpipe);
    void RunFunction(std::string name);
    void DefaultFunction(std::string name);

    int PipeParser(char* str, char** strpiped);
    int ProcessString(char* str, char** parsed, char** parsedpipe);
    
    std::string ExecWithOutput(std::string command);
}

#endif /* EXECUTE_HPP */