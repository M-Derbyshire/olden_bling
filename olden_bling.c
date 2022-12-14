#include <stdio.h>
#include "func_list.h"
#include "player.h"



int main()
{
    struct Player player;
    player.max_health = 100;
    player.health = player.max_health;
    player.weapon = getPlayerInitialWeapon();
    player.defense = getPlayerInitialDefense();
    
    player.current_location = &test1;
    
    while(player.current_location != NULL) {
        (*player.current_location)(&player);
        printf("\n----------\n\n");
    }
    
    return 0;
}