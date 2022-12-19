#ifndef MESSHALL_HG
#define MESSHALL_HG
#include <stdio.h>
#include "../../player.h"
#include "../../util.h"
#include "../../choice.h"
#include "../../items.h"
#include "../../monster.h"
#include "../../combat.h"

/* The mess hall (defined at the bottom of the file) */
void messHall(struct Player *player);

#include "corridor1.h"
#include "corridor2.h"




/* The armour in the antiques/trophy area of the mess hall */
void rustySuitOfArmour(struct Player *player)
{
    printf("You look at the old, rusting armour.\n");
    
    static short shieldAlreadyTaken = 0;
    
    if(!shieldAlreadyTaken)
    {
        printf("The suit has no weapon, but it does have a shield.\n");
        printf("You take the rusty shield.\n");
        
        struct ValuedItem rustyShield = { "rusty shield", "block", (short)5 };
        player->defense = rustyShield;
        shieldAlreadyTaken = 1;
    }
    
    printf("\n");
                
    promptToPressEnter("continue");
    player->current_location = &messHall;
}


/* Food left in the corner of the mess hall */
void messHallLeftOvers(struct Player *player)
{
    static short alreadyEaten = 0;
    
    if(!alreadyEaten)
    {
        int healthGain = 50;
        int healthWithGain = player->health + healthGain;
        int newHealth = (healthWithGain < player->max_health) ? healthWithGain : player->max_health;
        
        printf("You sit down at the end of the table, and start to eat the cold food.\n");
        printf("The food doesn't taste nice, but it is nourishing.\n");
        if(player->health < newHealth)
            printf("Your health increases to %d.\n", newHealth);
        
        printf("\n");
        
        player->health = newHealth;
        alreadyEaten = 1;
    }
    else
        printf("There is no more food for you to eat.\n\n");
    
    
    promptToPressEnter("continue");
    player->current_location = &messHall;
}


/* The mess hall, where guards hang out */
void messHall(struct Player *player)
{
    static struct Monster bull = {
        .name = "bull",
        .health = 75,
        .attack = 15,
        .defense = 3,
        .attack_description_count = 2,
        .attack_descriptions = { 
            "Bull swings its nose-ring at you, trying to slice you.", 
            "Bull charges at you." 
        },
        .defense_description_count = 1,
        .defense_descriptions = { "Bull blocks with its hoofs." }
    };
    
    short bullIsAlive = (bull.health > 0);
    
    
    printf("You are in a large hall, with 5 long tables.\n");
    printf("On the wall to your left, there are shelves of trophies and antiques, and also a rusty old suit of armour.\n");
    printf("To your right, there is a door out of the hall.\n");
    printf("In the corner, there is a plate of left-over food.\n");
    
    if(bullIsAlive)
    {
        printf("\nIn front of you there is a bull, stood upright on its hind legs.\n");
        printf("It has a giant nose-ring, and the outer rim of the ring has sharp metal spikes.\n");
        printf("The bull bangs its front hoofs together, and roars at you. It is ready to attack.\n");
    }
    
    printf("\n");
    
    short optionCount = (bullIsAlive) ? 2 : 4;
    Choice options[4] = {
        { 0, "Go back into the corridor that leads to the jail." },
        { 1, (bullIsAlive) ? "Fight the bull monster." : "Leave through the door to your right." },
        { 2, "Go over to the rusty suit of armour." },
        { 3, "Eat the food left in the corner." },
    };
    
    int result = makeChoice(options, optionCount);
    
    if(result == 0)
        player->current_location = &corridor1;
    else if(result == 1)
    {
        if(bullIsAlive)
        {
            printf("\n");
            short fightResult = runCombat(player, &bull);
            if(fightResult == 0)
                player->current_location = NULL; 
            else
            {
                promptToPressEnter("continue");
                printf("\n");
            }
        }
        else
            player->current_location = &corridor2;
    }
    else if(result == 2)
        player->current_location = &rustySuitOfArmour;
    else
        player->current_location = &messHallLeftOvers;
}


#endif