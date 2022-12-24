#include "player.h"
#include "monster.h"
#include "choice.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

#define RECORDED_ACTION_COUNT 7


/* Used to keep track of the last few actions the player has chosen, during a fight */
static short lastActions[RECORDED_ACTION_COUNT] = { -1 }; //-1 is unset

/*
    If the player is repeating the same choice, we want the monster to react to that.
    returns 1 if too many repeats, or 0 if not
*/
short tooManyActionRepeats(int currentAction)
{
    short earliestAction = lastActions[0];
    for(short i = 0; i < RECORDED_ACTION_COUNT; i++)
    {
        //First, shift the values down the array
        if(i > 0)
            lastActions[i-1] = lastActions[i];
        
        //check if this action is the same as the one before it
        if(lastActions[i] != earliestAction)
            return 0;
        
        //now add the latest action to the last index
        if(i == RECORDED_ACTION_COUNT - 1)
            lastActions[i] = currentAction;
    }
    
    return 1;
}

/* reset the static lastActions array */
void resetActionRecord()
{
    for(int i = 0; i < RECORDED_ACTION_COUNT; i++)
        lastActions[i] = -1;
}


/* Prints a description of a player's attack */
void printPlayerAttackDesc(struct Player *p) {
    printf("You %s the enemy with your %s.\n", p->weapon.verb, p->weapon.name);
}

/* Prints a description of a player's defense */
void printPlayerDefenseDesc(struct Player *p) {
    printf("You %s with your %s.\n", p->defense.verb, p->defense.name);
}

/* Prints a random attack description for a monster */
void printMonsterAttackDesc(struct Monster *m) {
    printf("%s\n", getRandomStringFromArray(m->attack_descriptions, m->attack_description_count));
}

/* Prints a random defense description for a monster */
void printMonsterDefenseDesc(struct Monster *m) {
    printf("%s\n", getRandomStringFromArray(m->defense_descriptions, m->defense_description_count));
}


void printHealthInfo(struct Player *player, struct Monster *monster)
{
    printf("Your health: %d - Enemy health: %d\n", player->health, monster->health);
}

/* 
    Should a defense attempt be considered succesful? 
    The greater the defenseValue, the greater the chance of success
 */
int defenseSuccessful(int defenseValue)
{
    //defense value of >=10 is unbeatable
    return (rand() % 9) < defenseValue;
}


/* 
    Determines and handles the result of the player's/monster's choices 
    playerAction - 0 = attack; 1 = defend; 2 = dodge
    enemyDefends - treated as a boolean
*/
void runCombatRound(int playerAction, int enemyDefends, struct Player *player, struct Monster *monster)
{
    // First just print out the 2 actions 
    //(works out cleaner to do the action-check twice, as the action printing always happens)
    if(playerAction == 0)
        printPlayerAttackDesc(player);
    else if(playerAction == 1)
        printPlayerDefenseDesc(player);
    
    if(enemyDefends)
        printMonsterDefenseDesc(monster);
    else
        printMonsterAttackDesc(monster);
    
    
    
    // Now we do any extra stuff, based on what actually happened
    if(playerAction == 0) // Player attacks
    {
        if(enemyDefends)
        {
            int enemyDefenseSuccessful = defenseSuccessful(monster->defense);
            printf((enemyDefenseSuccessful) ? "Enemy defense was successful.\n" : "Enemy defense failed.\n");
            
            if(!enemyDefenseSuccessful)
                monster->health -= player->weapon.value;
        }
        else
        {
            printf("You both succeed with your attacks.\n");
            player->health -= monster->attack;
            monster->health -= player->weapon.value;
        }
    }
    else if(playerAction == 1) // Player defends
    {
        if(enemyDefends)
            printf("You both succeed with your defense.\n");
        else
        {
            int playerDefenseSuccessful = defenseSuccessful(player->defense.value);
            printf((playerDefenseSuccessful) ? "Your defense was successful.\n" : "Your defense failed.\n");
            
            if(!playerDefenseSuccessful)
                player->health -= monster->attack;
        }
    }
    else // Player dodges (50/50 chance of success -- unless enemy is defending)
    {
        int dodgeSucceeds = enemyDefends || (rand() % 2);
        
        if(!enemyDefends && !dodgeSucceeds)
            player->health -= monster->attack;
        
        printf((dodgeSucceeds) ? "You successfully dodge.\n" : "You fail to dodge.\n");
    }
}




/* Runs a fight between the player and a monster. Returns 1 if player wins; 0 if player loses */
int runCombat(struct Player *player, struct Monster *monster)
{
    Choice playerChoices[3] = {
        { 0, "Attack" },
        { 1, "Defend" },
        { 2, "Dodge" }
    };
    
    do
    {
        printHealthInfo(player, monster);
        
        // Determine actions
        int chosenAction = makeChoice(playerChoices, 3);
        short actionRepeatedTooMuch = tooManyActionRepeats(chosenAction);
        
        short enemyDefends;
        if(actionRepeatedTooMuch)
        {
            enemyDefends = 0;
        }
        else
            enemyDefends = (rand() % 3) > 0;
        
        
        // Run round
        runCombatRound(chosenAction, enemyDefends, player, monster);
        printf("\n");
        promptToPressEnter("continue");
        printf("\n");
        
        
        // End the fight?
        if (monster->health <= 0 && player->health > 0)
        {
            printf("\n\n\n\nYou have defeated the %s.\n", monster->name);
            resetActionRecord();
            return 1;
        }
    }
    while(player->health > 0);
    
    printf("\n\n\n\nYou have been defeated by the %s.\n", monster->name);
    return 0;
}