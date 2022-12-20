#ifndef ROOMWITHCHIMNEY_HG
#define ROOMWITHCHIMNEY_HG
#include <stdio.h>
#include "../../player.h"
#include "../../choice.h"
#include "../../util.h"
#include "../../combat.h"
#include "../../monster.h"
#include "../../items.h"
#include "corridor7.h"

/* Last fight of the 2nd floor (defined below) */
void roomWithChimney(struct Player *player);

#include "../floor_3/corridor8.h"




/* Last fight of the 2nd floor */
void roomWithChimney(struct Player *player)
{
    //This monster is designed to be unbeatable (essentially), if you have to fight it.
    static struct Monster fly = {
        .name = "giant fly",
        .health = 1000,
        .attack = 50,
        .defense = 10,
        .attack_description_count = 1,
        .attack_descriptions = { 
            "Giant fly stabs at you."
        },
        .defense_description_count = 1,
        .defense_descriptions = { "Giant fly blocks with its wings." }
    };
    
    short flyIsAliveAndInTheRoom = (fly.health > 0);
    
    
    printf("You are standing in a large room. On the wall to your left, there is a fireplace.\n");
    printf("On the other side of the room, there is a spiral staircase, leading up to the next floor.\n");
    
    if(flyIsAliveAndInTheRoom)
    {
        printf("In front of you, there is a fly that's twice the size of your head.\n");
        printf("The fly has armour-plated wings, and a metal spike attached to its head.\n");
    }
    printf("\n");
    
    
    Choice options[2] = {
        { 0, "Go back into the corridor." },
        { 1, (flyIsAliveAndInTheRoom) ? "Fight the giant fly." : "Go up the stairs, to the next floor." }
    };
    
    short result = makeChoice(options, 2);
    
    if(result == 0)
        player->current_location = &corridor7;
    else
    {
        if(flyIsAliveAndInTheRoom)
        {
            if(playerHasCollectable(player, WEBRUNE))
            {
                //The monster is scared of the Web Rune
                printf("\nAs you get ready to fight the giant fly, it notices the Web Rune hanging from your belt.\n");
                printf("(This was the rune that you won from the old man, outside the prison area.)\n\n");
                
                printf("The fly lets out a screech as it sees the rune, and then quickly flys into the fireplace, and up the chimney.\n");
                promptToPressEnter("continue");
                fly.health = 0; // Just to take it out of play
            }
            else
            {
                //If you don't have the rune, you have to fight the fly
                printf("\n");
                short fightResult = runCombat(player, &fly);
                if(fightResult == 0)
                    player->current_location = NULL; 
                else
                {
                    printf("You stand amazed. You honestly have no idea how you just did that.\n");
                    promptToPressEnter("continue");
                    printf("\n");
                }
            }
        }
        else
            player->current_location = &corridor8;
    }
}


#endif