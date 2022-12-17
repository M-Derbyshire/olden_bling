#ifndef MONSTERS_HG
#define MONSTERS_HG

struct Monster {
    char *name;
    short health;
    short attack; // The amount of damage done by a successful attack
    short defense; // Defense value determines the chance of a defense being successful. >=10 is unbeatable
    char *attack_descriptions[3]; // descriptions of the different attacks the monster can perform
    int attack_description_count;
    char *defense_descriptions[3]; // descriptions of the different defensive actions the monster can perform
    int defense_description_count;
};

#endif