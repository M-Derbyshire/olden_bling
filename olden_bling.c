#include <stdio.h>
#include "func_list.h"


char *collectedItems[5];

int main()
{
    int currentSection = 0;
    while(currentSection > -1) {
        currentSection = (*sectionFuncs[currentSection])(collectedItems);
        printf("\n----------\n\n");
    }
    
    return 0;
}