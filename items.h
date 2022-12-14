#ifndef ITEMS_HG
#define ITEMS_HG

/* Enum of possible collectible items */
typedef enum {
    BootRune = (short)1,
    KeyRing,
    OldenBling
}COLLECTIBLES;

/* Represents an item that has a name, verb, and associated value */
struct ValuedItem {
    char name[13];
    char verb[6];
    short value;
};

#endif