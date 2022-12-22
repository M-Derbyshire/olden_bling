#ifndef PLAYER_HG
#define PLAYER_HG
#include "items.h"

typedef struct Player Player;

/* Function pointer type for "locations" */
typedef void (*Location)(struct Player *);



/* The player's starting weapon -- their hands */
struct ValuedItem getPlayerInitialWeapon()
{
    struct ValuedItem playerInitialWeapon = { "hands", "punch", (short)5 };
    return playerInitialWeapon;
}

/* The player's starting shield -- their hands */
struct ValuedItem getPlayerInitialDefense()
{
    // struct ValuedItem playerInitialDefense = { "hands", "block", (short)3 };
    struct ValuedItem playerInitialDefense = { "rusty shield", "block", (short)5 };
    return playerInitialDefense;
}




/* Represents a player's details */
struct Player {
    short max_health;
    short health;
    Collectible collectibles[3];
    short collectable_count; //How many collected items are in the collectibles array?
    struct ValuedItem weapon; // Weapon value is the amount of damage done by a successful attack
    struct ValuedItem defense; // Defense value determines the chance of a defense being successful. >=10 is unbeatable
    Location current_location;
};



/* Add collectible to player's collectibles array */
void addCollectibleToPlayer(struct Player *player, Collectible collectible)
{
    player->collectibles[player->collectable_count] = collectible;
    player->collectable_count++;
}

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

#endif