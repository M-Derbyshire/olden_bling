#ifndef MONSTERS_HG
#define MONSTERS_HG

struct Monster {
    char *name;
    short health;
    short attack;
    short defense; // >=10 is unbeatable
    char *attack_descriptions[3];
    int attack_description_count;
    char *defense_descriptions[3];
    int defense_description_count;
};

#endif