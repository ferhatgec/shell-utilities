/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

namespace ShellUtilities {
        int Print(std::string, ...);
        int Print(char*, ...);
        int Print(const char*, ...);
}

#endif /* PRINT_HPP */