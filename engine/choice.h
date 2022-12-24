#ifndef CHOICE_HG
#define CHOICE_HG

typedef struct {
    int chosenSectionIndex;
    char* optionStr;
}Choice;

int makeChoice(Choice options[], int optionCount);

#endif