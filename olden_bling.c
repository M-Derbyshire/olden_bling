#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./engine/player.h"
#include "./engine/util.h"
#include "./locations/floor_1/prison.h"



int main()
{
    srand(time(NULL));
    
    struct Player player = createPlayer();
    
    player.current_location = &prisonCell1;
    
    while(player.current_location != NULL) 
    {
        clearScreen();
        (*player.current_location)(&player);
    }
    
    printf("\n");
    promptToPressEnter("end the game");
    
    return 0;
}