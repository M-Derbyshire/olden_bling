#ifndef PRISON_HG
#define PRISON_HG
#include <stdio.h>
#include "../../player.h"
#include "../../util.h"
#include "../../choice.h"
#include "../../items.h"


/* The corridor outside the prison cells (defined at the bottom) */
void prisonCorridor(struct Player *player);


/* The starting point of the game */
void prisonCell1(struct Player *player)
{
    static short hasReadFullDescription = 0;
    char *basicDesc = "The walls are damp, and there is a strange smell.";
    
    if(hasReadFullDescription)
    {
        printf("%s\n\n", basicDesc);
    }
    else
    {
        printf("You wake up in a dark dungeon. You have no idea how you got here.\n\n");
        printf("%s..\n\n", basicDesc);
        printf("You realise that the smell is you... you'd had some bad sushi before you were knocked unconscious.\n\n");
        printf("You can see that you are in a cell, but it looks like the cell door was left unlocked.\n\n");
        promptToPressEnter("continue");
        printf("\n");
        hasReadFullDescription = 1;
    }
    
    Choice options[2] = {
        { 0, "Leave the cell" },
        { 1, "Stay here and feel sorry for yourself" }
    };
    
    int result = makeChoice(options, 2);
    
    if(result == 0)
        player->current_location = &prisonCorridor;
}


/* Looking into the second prison cell -- The first of 2 lovers */
void prisonCell2(struct Player *player)
{
    printf("You can see a skeleton in the cell.\n");
    printf("The skeleton is leant up against the wall between this cell and the 3rd.\n\n");
    promptToPressEnter("step back");
    player->current_location = &prisonCorridor;
}

/* Looking into the third prison cell -- The second of 2 lovers */
void prisonCell3(struct Player *player)
{
    printf("You can see a skeleton in the cell.\n");
    printf("The skeleton is leant up against the wall between this cell and the 2nd.\n\n");
    promptToPressEnter("step back");
    player->current_location = &prisonCorridor;
}

/* The forth prison cell. */
void prisonCell4(struct Player *player)
{
    printf("You are standing in an empty prison cell.\n");
    if(!playerHasCollectable(player, KEYRING))
    {
        printf("There is a big ring of keys on the ground. You pick them up.\n");
        addCollectibleToPlayer(player, KEYRING);
    }
    
    printf("\n");
    promptToPressEnter("go back outside");
    player->current_location = &prisonCorridor;
}


/* The corridor outside the prison cells */
void prisonCorridor(struct Player *player)
{
    printf("You are standing in a corridor.\n");
    printf("There are 3 other cells next to yours. The door of the 4th is open.\n");
    printf("There is also a door on you right, that leads out of this room.\n\n");
    
    Choice options[5] = {
        { 0, "Go back in your cell and feel sorry for yourself." },
        { 1, "Look into the 2nd cell." },
        { 2, "Look into the 3rd cell." },
        { 3, "Go into the 4th cell." },
        { 4, "Leave the room." }
    };
    
    short result = makeChoice(options, 5);
    
    if(result == 0)
        player->current_location = &prisonCell1;
    else if(result == 1)
        player->current_location = &prisonCell2;
    else if(result == 2)
        player->current_location = &prisonCell3;
    else if(result == 3)
        player->current_location = &prisonCell4;
    else
        player->current_location = NULL;
}

#endif