#include <stdio.h>
#include "player.h"
#include "choice.h"

void test2(struct Player *p) {
    printf("Section 2\n");
    p->current_location = NULL;
}

void test1(struct Player *p) {
    printf("Section 1\n");
    
    Choice opts[2] = {
        { 0, "first opt" },
        { 1, "second opt" }
    };
    
    int choice = makeChoice(opts, 2);
    
    if(choice == 1)
        p->current_location = &test2;
}