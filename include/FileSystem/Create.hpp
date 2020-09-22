/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CREATE_HPP
#define CREATE_HPP

#include <iostream>

namespace ShellUtilities {
        void CreateFile(std::string directory, std::string name,
                std::string data);
        
        void CreateFile(std::string directory, std::string data);
       
        void CreateFileWA(std::string directory, std::string data);
        void CreateFileWA(std::string directory);
}

#endif /* CREATE_HPP */