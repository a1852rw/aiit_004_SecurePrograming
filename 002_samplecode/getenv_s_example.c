#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "libsafec/safe_lib.h"

int main(int argc, char *argv[]) {
    char usage[100], env_value[100], *pEnvValue;
    size_t len;
    int ret;
    if(argc != 2) {
        snprintf(usage, 99, "usage: %s {envroment args}\n", argv[0]);
        fputs(usage, stdout);
        return EXIT_FAILURE;
    }
    
   ret = getenv_s(&len, env_value, 99, argv[1]);
   if(-1 == ret) {
       snprintf(usage, 99, "cannot get envroment value of %s\n", argv[1]);
       fputs(usage, stdout);
   } else {
       snprintf(usage, 99, "the value of %s is %s \n", argv[1], env_value);
       fputs(usage, stdout);
   }

   //change env_value
   pEnvValue = strncpy(env_value, "fang test", 9);
   ret = getenv_s(&len, env_value, 99, argv[1]);
   if(-1 == ret) {
       snprintf(usage, 99, "cannot get envroment value of %s\n", argv[1]);
       fputs(usage, stdout);
   } else {
       snprintf(usage, 99, "after changed the value of %s is %s \n", argv[1], env_value);
       fputs(usage, stdout);
   }
   return EXIT_SUCCESS;
}
