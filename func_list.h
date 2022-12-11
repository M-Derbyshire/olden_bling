#include <stdio.h>


int test1(char *collectedItems[]) {
    printf("Section 1\n");
    return 1;
}

int test2(char *collectedItems[]) {
    printf("Section 2\n");
    return -1;
}



int (*sectionFuncs[10])(char**) = {
    test1,
    test2
};