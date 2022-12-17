#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "player.h"



int main()
{
    srand(time(NULL));
    
    struct Player player = createPlayer();
    
    player.current_location = NULL;
    
    while(player.current_location != NULL) 
    {
        (*player.current_location)(&player);
        printf("\n----------\n\n");
    }
    
    return 0;
}