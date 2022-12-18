#ifndef CORRIDOR1_HG
#define CORRIDOR1_HG
#include <stdio.h>
#include <stdlib.h>
#include "../../player.h"
#include "../../util.h"
#include "../../choice.h"
#include "../../items.h"
#include "../../monster.h"
#include "../../combat.h"

/* The corridor itself, with a zombie to fight (defined at the bottom of the file) */
void corridor1(struct Player *player);

#include "prison.h"





/* Win a prize, or lose and die */
void coinFlipRoom(struct Player *player)
{
    printf("You are standing in a small room. In front of you there is a strange old man, sat behind a table.\n");
    printf("The man looks up at you, and speaks.\n\n");
    
    if(!playerHasCollectable(player, BOOTRUNE))
    {
        printf("\"Well, weary prisoner. Would you like to play a game?\n");
        printf("I have here in my pocket a coin, and I do enjoy flipping it.\n");
        printf("If it lands on heads, you can win yourself a fabulous prize. But, if it lands on tails... you die.\n\n");
        
        printf("Would you like play my little game?\"\n\n");
        
        Choice options[2] = {
            { 0, "Yes." },
            { 1, "No." }
        };
        
        short result = makeChoice(options, 2);
        if(result == 0)
        {
            int landsOnHeads = rand() % 2;
            if(landsOnHeads)
            {
                printf("The coin lands on heads.\n");
                printf("\"Congratulations!\" the man says. \"Here is your reward.\"\n");
                printf("The man hands you a Rune with a picture of a boot carved into it. You look at it, then back at him.\n");
                printf("\"Yes, that's your prize. Now, move along. I have things to be thinking about.\"\n");
                addCollectibleToPlayer(player, BOOTRUNE);
            }
            else
            {
                printf("The coin lands on tails, and the man stands up.\n");
                printf("Suddenly, you feel death (It feels a lot like heartburn).\n");
                printf("You drop to the floor, and your soul leaves your body.\n");
                player->current_location = NULL;
                return;
            }
        }
        else
            printf("\"Oh well. Come back if you ever change your mind.\" The man replies.\n");
    }
    else
        printf("\"You have already won your prize. Leave me to my thoughts.\"\n");
    
    
    printf("\n");
    promptToPressEnter("leave the room");
    player->current_location = &corridor1;
}



/* The corridor itself, with a zombie to fight */
void corridor1(struct Player *player)
{
    static struct Monster zombie = {
        .name = "zombie",
        .health = 25,
        .attack = 3,
        .defense = 1,
        .attack_description_count = 2,
        .attack_descriptions = { 
            "Zombie stabs at you with its rusty sword.", 
            "Zombie slashes at you with its rusty sword." 
        },
        .defense_description_count = 1,
        .defense_descriptions = { "Zombie blocks with its hands." }
    };
    
    int zombieIsAlive = (zombie.health > 0);
    
    printf("You are standing in a long corridor.\n");
    printf("On your right is a door.\n");
    printf((zombieIsAlive) ? "In front of you there is a zombie.\n" : "There is a door to another room at the end of the corridor.\n");
    printf("\n");
    
    Choice options[3] = {
        { 0, "Go back into the jail area." },
        { 1, "Go through the door on your right." },
        { 2, (zombieIsAlive) ? "Fight with the zombie." : "Go through the door at the end of the corridor." }
    };
    
    short result = makeChoice(options, 3);
    
    if(result == 0)
        player->current_location = &prisonCorridor;
    else if(result == 1)
        player->current_location = &coinFlipRoom;
    else
    {
        if(zombieIsAlive)
        {
            printf("\n");
            int fightResult = runCombat(player, &zombie);
            if(fightResult == 0)
                player->current_location = NULL; 
            else
            {
                //If player won, we just want to return to this location again
                printf("\nYou pick up the zombie's rusty sword.\n\n");
                struct ValuedItem rustySword = { "rusty sword", "slash", (short)10 };
                player->weapon = rustySword;
                promptToPressEnter("continue");
                printf("\n");
            }
        }
        else
           player->current_location = NULL; 
    }
}


#endif