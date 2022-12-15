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
    struct ValuedItem playerInitialDefense = { "hands", "block", (short)5 };
    return playerInitialDefense;
}




/* Represents a player's details */
struct Player {
    short max_health;
    short health;
    COLLECTIBLES collectibles[3];
    struct ValuedItem weapon;
    struct ValuedItem defense;
    Location current_location;
};


struct Player createPlayer()
{
    struct Player player;
    player.max_health = 100;
    player.health = player.max_health;
    player.weapon = getPlayerInitialWeapon();
    player.defense = getPlayerInitialDefense();
    
    return player;
}

#endif