#include <stdio.h>
#include "choice_maker.h"


int test1(char *collectedItems[]) {
    printf("Section 1\n");
    
    choice opts[2] = {
        { 1, "first opt" },
        { -2, "second opt" }
    };
    
    return makeChoice(opts, 2);
}

int test2(char *collectedItems[]) {
    printf("Section 2\n");
    return -1;
}



int (*sectionFuncs[10])(char**) = {
    test1,
    test2
};