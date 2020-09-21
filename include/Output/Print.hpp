/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>


#define PUT(x) ShellUtilities::Print(x);

namespace ShellUtilities {
        int Print(std::string, ...);
        int Print(char*, ...);
        int Print(const char*, ...);

        void Echo(std::string);
}

#endif /* PRINT_HPP */