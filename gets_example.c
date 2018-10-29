#include <stdio.h>

int main(int argc, char* argv[]) {
    char name[10];

    printf("please input your name >:");
    gets(name);
    printf("your name is : %s\n", name);
    return 0;
}
