#ifndef CORRIDOR3_HG
#define CORRIDOR3_HG
#include <stdio.h>
#include "../../player.h"
#include "../../util.h"
#include "../../choice.h"

/* The second part of the corridor after the mess hall (defined at the bottom of this file) */
void corridor3(struct Player *player);

#include "corridor2.h"
#include "corridor4.h"




/* If you're here, you've just made a mistake */
void exitFromLife(struct Player *player)
{
    static short doorOpenedBefore = 0;
    
    printf("As you open the door, you see a sign on a wall that reads: \"FROM LIFE\".\n");
    
    if(!doorOpenedBefore)
    {
        printf("There is a massive axe attached to the wall, with a spring behind it.\n");
        printf("The axe (pushed by the spring) swings down at you. It slashes you through the chest.\n\n");
        
        player->health = player->health / 10; //We're OK with a little truncation here
        printf("Your health is now %d.\n", player->health);
        doorOpenedBefore = 1;
    }
    else
        printf("There is an axe hanging off the wall, attached by an axle.\n");
    
    printf("\n");
    promptToPressEnter("close the door");
    player->current_location = &corridor3;
}

/* The second part of the corridor after the mess hall */
void corridor3(struct Player *player)
{
    printf("You are standing in a corridor.\n");
    printf("There is a door on your left, marked \"EXIT\".\n");
    printf("At the other end of the corridor, there is a left turn.\n\n");
    
    Choice options[3] = {
        { 0, "Head back towards the hall." },
        { 1, "Open the door on your left." },
        { 2, "Go down the corridor, and turn the corner." },
    };
    
    short result = makeChoice(options, 3);
    
    if(result == 0)
        player->current_location = &corridor2;
    else if(result == 1)
        player->current_location = &exitFromLife;
    else
        player->current_location = &corridor4;
}


#endif