#ifndef CORRIDOR2_HG
#define CORRIDOR2_HG
#include <stdio.h>
#include "../../player.h"
#include "../../util.h"
#include "../../choice.h"

/* The corridor after the mess hall (defined at the bottom of this file) */
void corridor2(struct Player *player);

#include "mess_hall.h"
#include "corridor3.h"




/* Toilet. Give a guy some privacy, would you */
void privy(struct Player *player)
{
    static short alreadyOpenedDoor = 0;
    
    printf("The room is a toilet. There is a man sat on it.\n");
    
    if(!alreadyOpenedDoor)
    {
        printf("He looks up, and seems to be terrified of you.\n");
        printf("\"...You don't have a crossbow on you, do you?\" the man asks. You tell him that you don't, and he seems to relax.\n");
        printf("\"So, you must be the new prisoner.\" he says. \"It looks like someone hasn't done their job very well.\"\n\n");
        
        printf("You ask him where you are, and why you are here.\n");
        printf("\"You are in the dungeons of the castle of the great King Namso.\" the man explains. You ask who King Namso is.\n");
        printf("\"He is a man of much knowledge, and great stature. And the reason you are here is because you made a very big mistake.\"\n");
        printf("You don't remember making a mistake, and the man sees the look of confusion on your face, so he explains:\n\n");
        printf("\"When one has drunk too much, one should be careful who's lap one throws up on.\n\"");
        printf("Your eyes widen suddenly, as you remember something from the night before.\n");
        
        alreadyOpenedDoor = 1;
    }
    else
    {
        printf("\"Please leave me be, I may be in here a while. Those clams were NOT ok!\"\n");
    }
    
    printf("\n");
    promptToPressEnter("close the door");
    player->current_location = &corridor2;
}


/* The corridor after the mess hall */
void corridor2(struct Player *player)
{
    printf("You are standing in a corridor.\n");
    printf("There is a door on your right.\n");
    printf("At the other end of the corridor, there is a left turn.\n\n");
    
    Choice options[3] = {
        { 0, "Go back into the hall." },
        { 1, "Open the door on your right." },
        { 2, "Go down the corridor, and turn the corner." },
    };
    
    short result = makeChoice(options, 3);
    
    if(result == 0)
        player->current_location = &messHall;
    else if(result == 1)
        player->current_location = &privy;
    else
        player->current_location = &corridor3;
}

#endif