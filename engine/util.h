#ifndef UTIL_HG
#define UTIL_HG

/* get a random string from a string array */
const char* getRandomStringFromArray(char *arr[], int count);

/* 
    wait for the user to press return 
    (verb is what they are triggering -- e.g. "continue"; "exit")
*/
void promptToPressEnter(char *verb);

#endif