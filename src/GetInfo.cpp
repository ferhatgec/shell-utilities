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

#include <GetInfo.hpp>

#define DESKTOP_ENVIRONMENT "XDG_CURRENT_DESKTOP"

std::string ShellUtilities::GetUsername() {
    /* Other way, get environment value */
    struct passwd *pass = getpwuid(geteuid());
    std::string username(pass->pw_name);
    return username;
}

std::string ShellUtilities::GetHostname() {
    /* Other way, get environment value */ 
    char hostname_buffer[256];
    gethostname(hostname_buffer, sizeof(hostname_buffer)); /* char array */
    
    std::string hostname(hostname_buffer);

    return hostname;
}

std::string ShellUtilities::GetDesktopEnvironment() {
    std::string desktop(ShellUtilities::GetEnvironment(DESKTOP_ENVIRONMENT));
    return desktop;
}

/* buf.sysname : char array */
std::string ShellUtilities::GetOperatingSystem() {
    struct utsname buf;
    std::string os_name(buf.sysname);
	if(!uname(&buf))
		return os_name; 
	else {
		perror("uname");
		return "?";
	}
}


/*
    This function (GetEnvironment) is part of the GNU C Library.

    Copyright (C) 1991-2019 Free Software Foundation, Inc.
    
    <http://www.gnu.org/licenses/>
*/
char * ShellUtilities::GetEnvironment(const char *name) {
    size_t len = strlen (name);
    char **ep;
    uint16_t name_start;
    if (__environ == NULL || name[0] == '\0')
        return NULL;

    if (name[1] == '\0') {
        /* The name of the variable consists of only one character.  Therefore
         the first two characters of the environment entry are this character
         and a '=' character.  */
        #if __BYTE_ORDER == __LITTLE_ENDIAN || !_STRING_ARCH_unaligned
            name_start = ('=' << 8) | *(const unsigned char *) name;
        #else
            name_start = '=' | ((*(const unsigned char *) name) << 8);
        #endif
        for (ep = __environ; *ep != NULL; ++ep) {
            #if _STRING_ARCH_unaligned
                uint16_t ep_start = *(uint16_t *) *ep;
            #else
            uint16_t ep_start = (((unsigned char *) *ep)[0]
                               | (((unsigned char *) *ep)[1] << 8));
            #endif
          
            if (name_start == ep_start)
                return &(*ep)[2];
        }
    } else {
        #if _STRING_ARCH_unaligned
            name_start = *(const uint16_t *) name;
        #else
            name_start = (((const unsigned char *) name)[0]
                    | (((const unsigned char *) name)[1] << 8));
        #endif
      
        len -= 2;
        name += 2;
        for (ep = __environ; *ep != NULL; ++ep) {
            #if _STRING_ARCH_unaligned
                uint16_t ep_start = *(uint16_t *) *ep;
            #else
                uint16_t ep_start = (((unsigned char *) *ep)[0]
                               | (((unsigned char *) *ep)[1] << 8));
            #endif
          
            if (name_start == ep_start && !strncmp (*ep + 2, name, len)
                && (*ep)[len + 2] == '=')
                    return &(*ep)[len + 3];
        }
    }
  
    return NULL;
}

std::string ShellUtilities::GetEnvironmentString(const char *name) {
    std::string get_name(ShellUtilities::GetEnvironment(name));
    return get_name;
}