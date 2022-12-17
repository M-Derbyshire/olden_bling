#ifndef UTIL_HG
#define UTIL_HG
#include <stdlib.h>
#include <stdio.h>

/* get a random string from a monster's description array (rand should be seeded elsewhere) */
const char* getRandomStringFromArray(char *arr[], int count)
{
    return arr[rand() % count];
}

/* 
    wait for the user to press return 
    (verb is what they are triggering -- e.g. "continue"; "exit")
*/
void promptToPressEnter(char *verb)
{
    printf("Press enter to %s...", verb);
    int c;
    while((c = getchar()) != '\n' && c != '\r');
}

#endif