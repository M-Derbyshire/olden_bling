#ifndef TREASUREROOM_HG
#define TREASUREROOM_HG
#include <stdio.h>
#include "../../player.h"
#include "../../choice.h"
#include "../../util.h"
#include "../../items.h"
#include "../../monster.h"
#include "../../combat.h"
#include "corridor9.h"

/* The treasure room (defined at the bottom of this file) */
void treasureRoom(struct Player *player);





/* The chest that contains the Olden Bling */
void treasureChest(struct Player *player)
{
    if(playerHasCollectable(player, OLDENBLING))
        printf("The chest is empty.\n");
    else
    {
        printf("You open the chest, and find that there is only one piece of treasure inside.\n");
        printf("You pick it up, and examine it. It is a golden bracelet, with a small plaque on one side.\n");
        printf("The plaque has letters engraved into it: G.A.N.G.S.T.A\n\n");
        
        printf("You stand up, having suddenly realised that this bracelet matches the description of the legendary Olden Bling!\n");
        printf("It was said that this piece of jewellery would give the one wearing it the strengh of 20 men!\n");
        
        addCollectibleToPlayer(player, OLDENBLING);
    }
    
    promptToPressEnter("step back");
    player->current_location = &treasureRoom;
}


/* The treasure room */
void treasureRoom(struct Player *player)
{
    static struct Monster soldier = {
        .name = "soldier",
        .health = 100,
        .attack = 20,
        .defense = 10,
        .attack_description_count = 1,
        .attack_descriptions = { 
            "Soldier swings his axe at you."
        },
        .defense_description_count = 1,
        .defense_descriptions = { "Soldier blocks with his shield." }
    };
    
    short soldierIsAlive = (soldier.health > 0);
    
    
    printf("You enter a large room. There are mounds of gold and jewels piled up against the walls.\n");
    printf("In the far corner, you notice a chest. It has a padlock on it, but the padlock is open.\n\n");
    
    if(soldierIsAlive)
    {
        printf("In the center of the room, there stands a soldier.\n");
        printf("He is wearing a silver suit of armour, though there are some gaps in it.\n");
        printf("He is holding a golden shield, and a large axe.\n\n");
    }
    
    
    Choice options[2] = {
        { 0, "Go back out into the corridor." },
        { 1, (soldierIsAlive) ? "Fight the soldier." : "Open the chest in the corner." }
    };
    
    short result = makeChoice(options, 2);
    
    if(result == 0)
        player->current_location = &corridor9;
    else
    {
        if(soldierIsAlive)
        {
            printf("\n");
            short fightResult = runCombat(player, &soldier);
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
            player->current_location = &treasureChest;
        }
    }
}



#endif