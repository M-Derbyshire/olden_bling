#include <stdio.h>
#include "../../engine/player.h"
#include "../../engine/items.h"
#include "../../engine/choice.h"
#include "../../engine/util.h"
#include "../floor_1/corridor4.h"
#include "corridor6.h"
#include "corridor5.h"

/* Beginning of the 2nd floor */
void corridor5(struct Player *player)
{
    static short swordAlreadyTaken = 0;
    
    printf("You are standing in a corridor.\n");
    printf("On your right, there is a soldier sat on a chair. He is asleep.\n");
    printf("At the other end of the corridor, there is a left turn.\n\n");
    
    Choice options[3] = {
        { 0, "Go back down the stairs, to the floor below." },
        { 1, "Continue down the corridor." },
        { 2, "Take the soldier's steel sword." } //Don't include if sword already taken
    };
    
    short result = makeChoice(options, (swordAlreadyTaken) ? 2 : 3);
    
    if(result == 0)
        player->current_location = &corridor4;
    else if(result == 1)
        player->current_location = &corridor6;
    else
    {
        printf("\nYou slowly pick up the soldier's steel sword, trying not to wake him.\n");
        
        struct ValuedItem steelSword = { "steel sword", "slash", (short)15 };
        player->weapon = steelSword;
        swordAlreadyTaken = 1;
        
        promptToPressEnter("continue");
        printf("\n");
    }
}