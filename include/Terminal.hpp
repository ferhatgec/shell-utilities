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
        std::string SetTerminal(bool username, bool hostname, bool directory,
                std::string input_sign, std::string special_sign,
                std::string directory_sign);

        void SetUsername(bool different,
                std::string different_tag);
        
        void SetHostname(bool different,
                std::string different_tag);

        void SetDirectoryName();
        void SetInputSign(std::string input_sign);
        void SetDirectorySign(std::string dir_sign);
        void SetSign(std::string sign);
}
        
#endif /* TERMINAL_HPP */