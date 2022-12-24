#include <stdio.h>
#include "../../engine/player.h"
#include "../../engine/choice.h"
#include "../floor_2/room_with_chimney.h"
#include "corridor9.h"
#include "corridor8.h"

/* First corridor of the 3rd floor */
void corridor8(struct Player *player)
{
    static short beenHereBefore = 0;
    
    printf("You are standing in a corridor. This one has small windows, and you can see the sunlight shine in.\n");
    printf("At the other end of the corridor, there is a right turn.\n");
    printf("On your left, there is a soldier sat on a chair.\n\n");
    
    if(!beenHereBefore)
    {
        printf("The soldier looks up at you, surprised.\n");
        printf("\"Blimey!\" he exclaims. \"How did you get out of the prison?\"\n");
        printf("\"I tell you what,\" he says \"If you can get past our monsters, I'm not going to get in your way.\"\n\n");
        beenHereBefore = 1;
    }
    
    Choice options[2] = {
        { 0, "Go back down the stairs, to the floor below." },
        { 1, "Carry on down the corridor, and turn the corner." }
    };
    
    short result = makeChoice(options, 2);
    
    if(result == 0)
        player->current_location = &roomWithChimney;
    else
        player->current_location = &corridor9;
}