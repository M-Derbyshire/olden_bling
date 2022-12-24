#ifndef COMBAT_HG
#define COMBAT_HG
#include "monster.h"
#include "player.h"

/* Runs a fight between the player and a monster. Returns 1 if player wins; 0 if player loses */
int runCombat(struct Player *player, struct Monster *monster);

#endif