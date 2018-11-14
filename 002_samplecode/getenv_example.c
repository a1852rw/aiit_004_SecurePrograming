#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char usage[100], *env_value;
    if(argc != 2) {
        snprintf(usage, 99, "usage: %s {envroment args}\n", argv[0]);
        fputs(usage, stdout);
        return EXIT_FAILURE;
    }
    
   env_value = getenv(argv[1]);
   if(!env_value) {
       snprintf(usage, 99, "cannot get envroment value of %s\n", argv[1]);
       fputs(usage, stdout);
   } else {
       snprintf(usage, 99, "the value of %s is %s \n", argv[1], env_value);
       fputs(usage, stdout);
   }

   //change env_value
   env_value = strncpy(env_value, "fang test", 9);

   env_value = getenv(argv[1]);
   if(!env_value) {
       snprintf(usage, 99, "cannot get envroment value of %s\n", argv[1]);
       fputs(usage, stdout);
   } else {
       snprintf(usage, 99, "after changed the value of %s is %s \n", argv[1], env_value);
       fputs(usage, stdout);
   }
   return EXIT_SUCCESS;
}
