#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsafec/safe_lib.h>
#include <libsafec/safe_str_lib.h>

int main(void)
{
  char buf[16];
  printf("Input>");
  gets_s(buf, sizeof(buf), stdin);
  printf("Hello, %s\n", buf);
  return 0;
}
