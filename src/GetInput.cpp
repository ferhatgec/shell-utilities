/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <GetInput.hpp>

int ShellUtilities::CharInput(void) {
    return getchar();
}

std::string ShellUtilities::Input() {
    int ch_int;
    char ch;
    std::string str;
    do {
        ch_int = ShellUtilities::CharInput();
        str.push_back(ch_int);
    } while(ch_int != '\n');
    return str;
}

std::string ShellUtilities::MakeCheckable(std::string input) {
        return input.erase(input.length() - 1, input.length());
}