/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SHELL_UTILITIES_HPP
#define SHELL_UTILITIES_HPP

#include <iostream>
#include "GetInfo.hpp"
#include "GetInput.hpp"
#include "Terminal.hpp"
#include "Execute.hpp"

#define NAME "Fegeya ShellUtilities"
#define ALL_VERSION "0.1-beta-1"
#define DESC "C++17 Library for make new CLI shell or applications that require information."

#define PWD "PWD"

class ShellVariables {
public:
        char *directory = ShellUtilities::GetEnvironment(PWD);
};

#endif /* GET_INPUT_HPP */