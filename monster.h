#ifndef MONSTERS_HG
#define MONSTERS_HG

struct Monster {
    char name[8];
    short health;
    short attack;
    short defense;
    char attack_descriptions[3][10];
    char defense_descriptions[3][10];
};

#endif