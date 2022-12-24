#ifndef PLAYER_HG
#define PLAYER_HG
#include "items.h"

typedef struct Player Player;

/* Function pointer type for "locations" */
typedef void (*Location)(struct Player *);


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
void addCollectibleToPlayer(struct Player *player, Collectible collectible);

/* Does the player have a specific collectible */
int playerHasCollectable(struct Player *player, Collectible collectible);


/* Create an initialised player (doesn't initialise the current_location) */
struct Player createPlayer();

#endif