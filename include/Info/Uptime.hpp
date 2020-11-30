/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef UPTIME_HPP
#define UPTIME_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

typedef struct {
	unsigned days;
	unsigned hours;
	unsigned minutes;
} timepp_t;

namespace ShellUtilities {
	/* From TimePlusPlus library */
	timepp_t Initialize();
}


#endif // UPTIME_HPP
