/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <sstream>

#include <Output/Colorized.hpp>
#include <Output/Print.hpp>

std::string
ShellUtilities::colorize(TYPE type, int color) {
        return Templatestr + std::to_string(type) + Semicolonstr + std::to_string(color) + Markstr;
}

void
ShellUtilities::textBackground(int color) {
	printf("%c[%dm", ESC, 40+color);
}

void
ShellUtilities::setColor(const std::string color) {
        ShellUtilities::Print(color);
}

void
ShellUtilities::setColor(TYPE type, int color) {
        ShellUtilities::setColor(ShellUtilities::colorize(type,color));
}

void
ShellUtilities::printfc(const std::string color, bool reset, char* msg) {
        ShellUtilities::setColor(color);
        ShellUtilities::Print(msg);
        if(reset)
                ShellUtilities::Print(WBLACK_COLOR);
}

void
ShellUtilities::printfc(const std::string color, char* msg) {
        ShellUtilities::printfc(color,1,msg);
}