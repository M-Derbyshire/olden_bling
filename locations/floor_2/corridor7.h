#ifndef CORRIDOR7_HG
#define CORRIDOR7_HG
#include <stdio.h>
#include "../../player.h"
#include "../../choice.h"
#include "../../util.h"
#include "../../items.h"
#include "banquet_hall.h"

/* Corridor after the banquet hall (defined below) */
void corridor7(struct Player *player);

#include "room_with_chimney.h"




/* Corridor after the banquet hall */
void corridor7(struct Player *player)
{
    static short shieldHasBeenTaken = 0;
    
    printf("You are standing in a corridor.\n");
    printf("There are suits of armour lined up along the wall to your right. Somebody has drawn a moustache on one of them.\n");
    printf("At the other end of the corridor, there is a door.\n\n");
    
    Choice options[3] = {
        { 0, "Go back into the banquet hall." },
        { 1, "Go down the corridor, through the door." },
        { 2, "Look at the suit of armour with the moustache." }
    };
    
    short result = makeChoice(options, (shieldHasBeenTaken) ? 2 : 3);
    
    if(result == 0)
        player->current_location = &banquetHall;
    else if(result == 1)
        player->current_location = &roomWithChimney;
    else
    {
        printf("\nYou stand in front of the suit of armour. You notice that it is the only one with a shield.\n");
        printf("It is a nice, steel shield. You decide to take it.\n");
        
        struct ValuedItem steelShield = { "steel shield", "block", (short)7 };
        player->defense = steelShield;
        
        shieldHasBeenTaken = 1;
        promptToPressEnter("continue");
        printf("\n");
    }
}

#endif