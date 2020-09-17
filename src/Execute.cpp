/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pwd.h>
#include <endian.h>
#include <errno.h>
#include <sys/utsname.h>
#include <sys/wait.h>

#include <Execute.hpp>
#include <ShellUtilities.hpp>

#define MAXCOM 1000
#define MAXLIST 100

static char inputString[1000], *parsedArgs[100];
static char* parsedArgsPiped[MAXLIST]; 
static int execFlag = 0;
static std::string directory;

ShellVariables var;

void ShellUtilities::ExecuteName(const char* exec_name) {
	var.name = exec_name;
}
	
int ShellUtilities::PipeParser(char* str, char** strpiped) { 
  	int i; 
    for (i = 0; i < 2; i++) { 
  	    strpiped[i] = strsep(&str, "|"); 
    	if (strpiped[i] == NULL) 
      	    break; 
	} 
  
	if (strpiped[1] == NULL) 
	    return 0; // returns zero if no pipe is found. 
	else  
	    return 1;
} 

void ShellUtilities::ParseSpace(char* str, char** parsed) { 
	int i; 
	  
	for (i = 0; i < MAXLIST; i++) { 
	        parsed[i] = strsep(&str, " "); 
	  
	    if (parsed[i] == NULL) 
	        break; 
	    
        if (strlen(parsed[i]) == 0) 
	        i--; 
	} 
} 

int ShellUtilities::ProcessString(char* str, char** parsed, char** parsedpipe) {   
	char* strpiped[2]; 
	int piped = 0; 
	  
	piped = ShellUtilities::PipeParser(str, strpiped); 
  
	if (piped) { 
	    ShellUtilities::ParseSpace(strpiped[0], parsed); 
	    ShellUtilities::ParseSpace(strpiped[1], parsedpipe); 
	} else  
	    ShellUtilities::ParseSpace(str, parsed); 
	    return 1 + piped; 
} 

void ShellUtilities::ExecuteArgs(char** parsed) { 
	/* Forking a child */ 
	pid_t pid = fork();  
	  
	if (pid == -1) { 
		std::cout << var.name << " : Failed forking child..\n"; 
	    	return; 
	} else if (pid == 0) { 
		if (execvp(parsed[0], parsed) < 0)
	        	std::cout << var.name << " : " << parsed[0] << " : command not found..\n"; 
        	exit(0); 
	} else { 
		/* Waiting for child to terminate */ 
	        wait(NULL);  
	        return; 
	} 
}
	
void ShellUtilities::ExecuteArgsPiped(char** parsed, char** parsedpipe) { 
	/* 0 is read end, 1 is write end */ 
	int pipefd[2];  
	pid_t p1, p2; 
	  
	if (pipe(pipefd) < 0) { 
	    std::cout << var.name << " : Pipe could not be initialized\n";  
	    return; 
	} 
	
    	p1 = fork(); 
	if (p1 < 0) { 
	    std::cout << var.name << " : Could not fork.\n"; 
	    return; 
	} 
	  
    	if (p1 == 0) { 
		/* Child 1 executing.. 
	           It only needs to write at the write end  */
	    	close(pipefd[0]); 
	    	dup2(pipefd[1], STDOUT_FILENO); 
	    	close(pipefd[1]); 
	  
	    	if (execvp(parsed[0], parsed) < 0) { 
			std::cout << var.name << " : " << parsed[0] << " : first command not found..\n";
			exit(0); 
	    	}	 
	} else { 
	    /* Parent executing */ 
	    	p2 = fork(); 

	    	if (p2 < 0) { 
			std::cout << var.name << " : Could not fork.\n";  
            		return; 
	   	 } 
	  
        	/* Child 2 executing.. 
	       	   It only needs to read at the read end */
   	 	if (p2 == 0) { 
	        	close(pipefd[1]); 
		        dup2(pipefd[0], STDIN_FILENO); 
		        close(pipefd[0]); 
		        if (execvp(parsedpipe[0], parsedpipe) < 0) { 
				std::cout << var.name <<  " : " << parsed[0] << " : second command not found..\n";
	            		exit(0); 
	        	} 
        	} else { 
	        	/* parent executing, waiting for two children */
		        wait(NULL); 
		        wait(NULL); 
		} 
	} 
} 
	
void ShellUtilities::RunFunction(std::string name) {
	strcpy(inputString, name.c_str());
	execFlag = ShellUtilities::ProcessString(inputString, 
	    parsedArgs, parsedArgsPiped);
	
	if (execFlag == 1) 
		ShellUtilities::ExecuteArgs(parsedArgs); 
	  
	if (execFlag == 2) 
	        ShellUtilities::ExecuteArgsPiped(parsedArgs, parsedArgsPiped); 
}

void ShellUtilities::DefaultFunction(std::string name) {
	system(name.c_str());
}

std::string ShellUtilities::ExecWithOutput(std::string command) {
   	char buffer[128];
   	std::string result = "";

   	/* Open pipe to file */
   	FILE* pipe = popen(command.c_str(), "r");
   	if (!pipe) {
      		return "popen failed!";
   	}

   	/* Read till end of process: */
   	while (!feof(pipe))
      		/* Use buffer to read and add to result */
      		if (fgets(buffer, 128, pipe) != NULL)
         		result += buffer;
   	

   	pclose(pipe);
	return result;
}