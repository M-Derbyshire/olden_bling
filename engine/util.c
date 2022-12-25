#include <stdlib.h>
#include <stdio.h>

/* get a random string from a string array */
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

/* Clear the console screen, ready for the next "screen" of the game */
void clearScreen()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #elif defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        //If we can't do this with a system call, just add a large number of newlines
        for(int i = 0; i < 200; i++)
            printf("\n");
    #endif
}