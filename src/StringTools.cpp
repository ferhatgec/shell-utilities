#include <iostream>
#include <fstream>
#include <FileSystem/ChangeDir.hpp>
#include <StringTools.hpp>

#ifdef _MSC_VER
#include <string>  // VisualC++
#else
#include <cstring>  // Otherwise
#endif
	

std::string ShellUtilities::EraseAllSubString(std::string & mainString, const std::string & erase) {
    	size_t pos = std::string::npos;
   	while((pos = mainString.find(erase)) != std::string::npos)
        	mainString.erase(pos, erase.length());
  	
	return mainString;
}

	
std::string ShellUtilities::FindStringWithReturn(std::string file, std::string str) {
	std::string line;
    	std::ifstream readfile(file.c_str());
    	if(readfile.is_open()) {
        while (std::getline(readfile, line)) 
		if(strstr(line.c_str(), str.c_str()))
			return line + "\n";
        	
		readfile.close();
    	} else 
        	return "error"; /* Unable to open file */

    	return "null"; /* Not found. */
}

  	

std::string ShellUtilities::GetBetweenString(std::string oStr, 
	std::string sStr1, std::string sStr2) {
	int start = oStr.find(sStr1);
    	if (start >= 0) {
     		std::string tstr = oStr.substr(start + sStr1.length());
      		int stop = tstr.find(sStr2);
      		if (stop >1)
        		return oStr.substr(start + sStr1.length(), stop);
      		else
        		return "error";
    	} else
       		return "error";
}

void ShellUtilities::GetBtwString(std::string oStr, 
	std::string sStr1, std::string sStr2, std::string &rStr) {
    	int start = oStr.find(sStr1);
    	if (start >= 0) {
      		std::string tstr = oStr.substr(start + sStr1.length());
      		int stop = tstr.find(sStr2);
      		if (stop >1)
        		rStr = oStr.substr(start + sStr1.length(), stop);
      		else
        		rStr ="error";
    	} else
       		rStr = "error";
}

int ShellUtilities::Compare(const char* str_1, const char* str_2) {
	const unsigned char *unsigned_str_1 = (const unsigned char *) str_1;
	const unsigned char *unsigned_str_2 = (const unsigned char *) str_2;

	while (*unsigned_str_1 == *unsigned_str_2 && 
		*unsigned_str_1 != '\0') {
    		
		unsigned_str_1++;
    		unsigned_str_2++;
  	}

  	return (*unsigned_str_1 > *unsigned_str_2) - (*unsigned_str_1 < *unsigned_str_2);
}