/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */
#include <iostream>
#include <cstring>
#include <pwd.h>
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

#include <FileSystem/List.hpp>
#include <FileSystem/ChangeDir.hpp>

#include <Output/Colorized.hpp>

void ShellUtilities::DefaultList(bool current_dir,
        const char* dir) {

        int a = 0;
	DIR *directory;
	struct dirent *entryname;
        struct stat filestat;

        if(current_dir == true)
    	        directory = opendir(ShellUtilities::GetCurrentWorkingDir().c_str());
    	else
                directory = opendir(dir);

        if(directory != NULL) {
                while ((entryname = readdir(directory))) {
        	        stat(entryname->d_name, &filestat);

                        if(entryname->d_name[0] != '.') {
                                if(entryname->d_type == DT_DIR) {
            	                        BLUE_COLOR
                                        printf("%s  ", entryname->d_name);
                    	                RESETW
                                } else
                       	                printf("%s  ", entryname->d_name);
                                a++;

                                if(a % 5 == 0)
                                        printf("\n");
                        }
                }

                closedir(directory);
	}

        printf("\n");
}