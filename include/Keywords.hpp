/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef KEYWORDS_HPP
#define KEYWORDS_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <Output/Print.hpp>

#define NEWLINE ShellUtilities::Print("\n");

inline const char* CSTR(std::string str) {
        return str.c_str();
}

inline std::string STRC(const char* ch) {
        return (std::string)ch;
}

#endif /* KEYWORDS_HPP */