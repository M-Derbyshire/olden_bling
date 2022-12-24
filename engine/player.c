#include "player.h"
#include "items.h"

/* The player's starting weapon -- their hands */
struct ValuedItem getPlayerInitialWeapon()
{
    struct ValuedItem playerInitialWeapon = { "hands", "punch", (short)5 };
    return playerInitialWeapon;
}

/* The player's starting shield -- their hands */
struct ValuedItem getPlayerInitialDefense()
{
    struct ValuedItem playerInitialDefense = { "hands", "block", (short)3 };
    return playerInitialDefense;
}



/* Add collectible to player's collectibles array */
void addCollectibleToPlayer(struct Player *player, Collectible collectible)
{
    player->collectibles[player->collectable_count] = collectible;
    player->collectable_count++;
}

/* Does the player have a specific collectible */
int playerHasCollectable(struct Player *player, Collectible collectible)
{
    for(int i = 0; i < player->collectable_count; i++)
        if(player->collectibles[i] == collectible)
            return 1;
    
    return 0;
}

/* Create an initialised player (doesn't initialise the current_location) */
struct Player createPlayer()
{
    struct Player player;
    player.max_health = 100;
    player.health = player.max_health;
    player.weapon = getPlayerInitialWeapon();
    player.defense = getPlayerInitialDefense();
    player.collectable_count = 0;
    
    return player;
}