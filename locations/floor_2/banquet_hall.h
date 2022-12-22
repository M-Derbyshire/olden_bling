#ifndef BANQUETHALL_HG
#define BANQUETHALL_HG
#include <stdio.h>
#include "../../player.h"
#include "../../choice.h"
#include "../../util.h"
#include "../../combat.h"
#include "../../monster.h"
#include "../../items.h"
#include "corridor6.h"

/* Banquet hall (defined below) */
void banquetHall(struct Player *player);

#include "corridor7.h"


/* Banquet hall */
void banquetHall(struct Player *player)
{
    static short chickenIsEaten = 0;
    static short doorUnlocked = 0;
    
    static struct Monster chicken = {
        .name = "giant chicken",
        .health = 100,
        .attack = 15,
        .defense = 5,
        .attack_description_count = 1,
        .attack_descriptions = { 
            "Chicken pecks at you."
        },
        .defense_description_count = 1,
        .defense_descriptions = { "Chicken blocks with its breastplate." }
    };
    
    short chickenIsAlive = (chicken.health > 0);
    
    printf("You are standing in a banquet hall. In front of you there is a huge table.\n");
    printf("At the other end of the hall, there is a door.\n");
    if(chickenIsAlive)
    {
        printf("It seems the chicken is undercooked... as it's still alive.\n");
        printf("It's also twice the size of you, and wearing a golden breastplate. You can see that it is angry.\n");
    }
    else if(!chickenIsEaten)
        printf("The corpse of the giant chicken rests in the center of the table.\n");
    
    printf("\n");
    
    
    
    Choice options[3] = {
        { 0, "Go back into the corridor, towards the staircase." },
        { 1, (chickenIsAlive) ? "Fight the giant chicken." : "Go through the door." },
        { 2, "Eat the chicken's remains." }
    };
    
    short result = makeChoice(options, (!chickenIsAlive && !chickenIsEaten) ? 3 : 2);
    
    if(result == 0)
        player->current_location = &corridor6;
    else if(result == 1)
    {
        if(chickenIsAlive)
        {
            printf("\n");
            short fightResult = runCombat(player, &chicken);
            if(fightResult == 0)
                player->current_location = NULL; 
            else
            {
                promptToPressEnter("continue");
                printf("\n");
            }
        }
        else
        {
            if(playerHasCollectable(player, KEYRING))
            {
                if(!doorUnlocked)
                {
                    printf("You unlock the door with one of the keys you found in the prison.\n");
                    promptToPressEnter("continue");
                    doorUnlocked = 1;
                }
                
                player->current_location = &corridor7;
            }
            else
            {
                printf("You try to open the door, but it's locked.\n");
                promptToPressEnter("continue");
            }
        }
    }
    else
    {
        printf("You make a fire out of some wood, and cook the chicken's remains.\n");
        printf("The chicken was so large that the meal restores you back to full health.\n");
        promptToPressEnter("continue");
        chickenIsEaten = 1;
        player->health = player->max_health;
    }
}

#endif