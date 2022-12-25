#include <stdio.h>
#include "../../engine/player.h"
#include "../../engine/choice.h"
#include "../../engine/util.h"
#include "../../engine/items.h"
#include "corridor8.h"
#include "treasure_room.h"
#include "corridor9.h"

/* The game's ending */
void endGameText()
{
    printf("You push and push with all of your new-found might, and the door starts to open.\n");
    printf("As it opens, you can feel the sunlight shining on your face. It feels good.\n\n");
    
    printf("You get out, and run away from the castle.\n");
    printf("You are free once again.\n\n");
    
    promptToPressEnter("finish the game");
}


/* The 2nd part of the corridor on the 3rd floor. (Also has the exit door) */
void corridor9(struct Player *player)
{
    static short triedToOpenDoorBefore = 0; //(without the Olden Bling)
    
    printf("You are standing in a long corridor.\n");
    printf("At the other end of the corridor, there is a door.\n");
    printf("Halfway down the corridor, on the left, there is a very large door (it looks too heavy for you to open). There is a man sat next to it.\n\n");
    
    Choice options[3] = {
        { 0, "Go back down the corridor, towards the staircase." },
        { 1, "Go through the door at the other end of the corridor." },
        { 2, "Try to open the large door on the left." }
    };
    
    short result = makeChoice(options, 3);
    
    if(result == 0)
        player->current_location = &corridor8;
    else if(result == 1)
        player->current_location = &treasureRoom;
    else
    {
        clearScreen();
        
        if(playerHasCollectable(player, OLDENBLING)) //End game
        {
            endGameText();
            player->current_location = NULL;
        }
        else //Can't open the door
        {
            printf("You push against the door, but nothing happens.\n");
            if(!triedToOpenDoorBefore)
            {
                printf("The man sat next to the door looks up at you and speaks.\n");
                printf("\"You can try that all you like,\" he says, \"it isn't going to move.\"\n");
                printf("\"It takes 20 of the king's men to get that door open.\"\n");
                triedToOpenDoorBefore = 1;
            }
            
            promptToPressEnter("continue");
        }
    }
}