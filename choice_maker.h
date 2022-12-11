#include <stdio.h>

typedef struct {
    int chosenSectionIndex;
    char* optionStr;
}choice;

int makeChoice(choice options[], int optionCount)
{
    //Display choices
    for(int i = 0; i < optionCount; i++)
        printf("%c: %s\n", 'a' + i, options[i].optionStr);
    
    //Make selection
    int selection = 0;
    printf("> ");
    while(selection < 'a' || selection >= ('a' + optionCount))
        selection = getchar();
    
    //Return selected function's index
    return options[selection - 'a'].chosenSectionIndex;
}