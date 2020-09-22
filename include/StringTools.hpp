/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef STRING_TOOLS_HPP
#define STRING_TOOLS_HPP

#include <iostream>

namespace ShellUtilities {
        /* From StringTools library */
        std::string EraseAllSubString(std::string & mainString, 
                const std::string & erase);
        std::string FindStringWithReturn(std::string file, 
                std::string str);
        std::string GetBetweenString(std::string oStr, std::string sStr1, 
                std::string sStr2);
                
        void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, 
                std::string &rStr);

        int Compare(const char* str_1, const char* str_2);
}

#endif /* STRING_TOOLS_HPP */