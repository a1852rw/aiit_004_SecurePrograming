#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char buf[16];
  printf("input>");
  gets(buf);
  printf("Hello, %s\n", buf);
  return 0;
}