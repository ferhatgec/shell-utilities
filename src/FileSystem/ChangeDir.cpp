#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>

#include <ShellUtilities.hpp>
#include <GetInfo.hpp>
#include <StringTools.hpp>
#include <FileSystem/ChangeDir.hpp>

#ifdef WINDOWS
        #include <direct.h>
        #define GetCurrentDir _getcwd
#else
        #include <unistd.h>
        #define GetCurrentDir getcwd
#endif

void ShellUtilities::ChangeDir(std::string name) {
        ShellVariables var;
	if(name.rfind("#", 0) == 0) {
	        name = ShellUtilities::EraseAllSubString(name, "#");
	    	std::string new_name(ShellUtilities::GetEnvironment(name.c_str()));
	    	if(new_name.rfind("/") == 0) {
	    		if(ShellUtilities::IsFileExist(new_name) == true) {
            		    strcpy(var.directory, new_name.c_str());
	    		    chdir(new_name.c_str());
            		} else {
            		    std::cout << "scrift : " << new_name << " : This directory is not exist!\n";
            		    return;
            		}
           	} else {
	    		std::string path;
            		path.append(var.directory);
            		path.append("/");
            		path.append(new_name);
            		if(ShellUtilities::IsFileExist(path) == true) {
            		    std::strcat(var.directory, "/");
            		    std::strcat(var.directory, new_name.c_str());
            		    chdir(new_name.c_str());
            		} else {
            		    std::cout << "scrift : " << new_name << " : This directory is not exist!\n";
            		    return;
            		}
            	}
	} else {
	    	if(name.rfind("/") == 0) {
	    		if(ShellUtilities::IsFileExist(name) == true) {
	    		    std::strcpy(var.directory, name.c_str());
	    		    chdir(name.c_str());
            		} else {
                                std::cout << "scrift : " <<  name << 
                                        " : This directory is not exist!\n";
            		}
            		return;
	    	} else {
		        std::string path;
        	    	/*if(command->_file_path_cd_function == "/") {
	        		path.append(command->_file_path_cd_function);
		        	path.append(name);
        		} else {*/
            		path.append(var.directory);
            		path.append("/");
            		path.append(name);
            	//}
            	        if(ShellUtilities::IsFileExist(path) == true) {
            	                chdir(name.c_str());
		                //char *path(&fsplusplus::GetCurrentWorkingDir()[0]);
                                std::strcpy(var.directory, &ShellUtilities::GetCurrentWorkingDir()[0]);
		        }  else {
            	                std::cout << "scrift : " << name << 
                                        " : This directory is not exist!\n";
                                return;
            	        }
            	}
            }
    return;
}

bool ShellUtilities::IsFileExist(const std::string &file) {
        return access(file.c_str(), 0) == 0;
}

char * ShellUtilities::GetCurrentWorkingDirChar(void) {
        char buff[FILENAME_MAX];
  	GetCurrentDir(buff, FILENAME_MAX);
  	return &buff[0];
}

std::string ShellUtilities::GetCurrentWorkingDir(void) {
  	char buff[FILENAME_MAX];
  	GetCurrentDir( buff, FILENAME_MAX );
  	std::string current_working_dir(buff);
  	return current_working_dir;
}