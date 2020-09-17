/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef CHANGE_DIR_HPP
#define CHANGE_DIR_HPP

#include <iostream>

namespace ShellUtilities {
        /* From ExecutePlusPlus library */
        void ChangeDir(std::string directory);
        //void SetDirectory(std::string directory);

        bool IsFileExist(const std::string &file);

        std::string GetCurrentWorkingDir(void);

        char * GetCurrentWorkingDirChar(void);
}

#endif /* CHANGE_DIR_HPP */