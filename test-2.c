#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include "libsafec/safe_lib.h"

int main(void){
  int numchar;
  printf_s("Hello, world!%n\n", &numchar);
  printf("There are %d characters\n", numchar);
  return 0;
}
