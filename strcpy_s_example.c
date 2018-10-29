#include <stdio.h>
#include <string.h>
#include "libsafec/safe_lib.h"
#include "libsafec/safe_str_lib.h"

int main(int argc, char *argv[]) {
    char copy_from[16], copy_to[10];

    printf("please input the string which is copyed from(more than 10 characters):\n");
    gets_s(copy_from, sizeof(copy_from));
    strcpy_s(copy_to, sizeof(copy_to), copy_from);

    printf("the string which is copyed to is : \n");
    printf("%s\n", copy_to);
}
