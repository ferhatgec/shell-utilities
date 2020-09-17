/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GET_INFO_HPP
#define GET_INFO_HPP

#include <iostream>

namespace ShellUtilities {
    std::string GetUsername();
    std::string GetHostname();
    std::string GetDesktopEnvironment();
    std::string GetOperatingSystem();
    std::string GetEnvironmentString(const char *name);

    /* From GNU C Library (GetEnvironment) */
    char * GetEnvironment(const char *name);
}

#endif /* GET_INFO_HPP */