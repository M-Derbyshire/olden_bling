#include <stdio.h>
#include "choice.h"

int makeChoice(Choice options[], int optionCount)
{
    static short madeChoicePreviously = 0;
    
    printf("What do you do?\n");
    
    if(!madeChoicePreviously)
    {
        printf("(Enter the number of your selection, and press enter.)\n");
        madeChoicePreviously = 1;
    }
    
    //Display choices
    for(int i = 0; i < optionCount; i++)
        printf("(%d) %s\n", i + 1, options[i].optionStr);
    
    
    //Make selection (1, 2, 3, etc)
    //Print a prompt, then repeat till a valid selection is made
    int selection = 0;
    do
    {
        printf("> ");
        int scanResult = scanf("%d", &selection);
        
        // if player didn't enter a number, we need to flush out the buffer
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        
    } while(selection < 1 || selection > optionCount);
    
    
    //Return selected function's index
    return options[selection - 1].chosenSectionIndex;
}