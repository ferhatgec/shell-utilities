/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <iostream>

namespace ShellUtilities {
        void SetTerminal(bool username, bool hostname, std::string input_sign,
                std::string special_sign);
}

#endif /* TERMINAL_HPP */