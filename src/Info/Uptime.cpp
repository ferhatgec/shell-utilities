/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <string>
#include <fstream>

#include <Info/Uptime.hpp>

timepp_t
ShellUtilities::Initialize() {
	std::ifstream file("/proc/uptime");
	std::string line;
	timepp_t time;
		
    int d, h, m, s;

    if (!file.is_open()) return time;

	while(std::getline(file, line)) { s = atoi(line.c_str()); } 
	
    d = s / 60 / 60 / 24;
    h = s / 60 / 60 % 24;
    m = s / 60 % 60;

    if(d ^ 0) time.days    = d; 
    if(h ^ 0) time.hours   = h;
    if(m ^ 0) time.minutes = m;
    	
	return time;
}
