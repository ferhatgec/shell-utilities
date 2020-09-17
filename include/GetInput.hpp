/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef GET_INPUT_HPP
#define GET_INPUT_HPP

#include <iostream>

namespace ShellUtilities {
        int CharInput(void);

        std::string Input();
        std::string MakeCheckable(std::string input);
}

#endif /* GET_INPUT_HPP */