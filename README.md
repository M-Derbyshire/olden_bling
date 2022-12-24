# Olden Bling

*You wake up in a dark dungeon. You have no idea how you got here.
The walls are damp, and there is a strange smell...
You realise that the smell is you... you'd had some bad sushi before you were knocked unconscious.
You can see that you are in a cell, but it looks like the cell door was left unlocked.*

**Olden Bling** is a command-line role-playing game. You must escape from the strange place you find yourself in (defeating wacky monsters along the way).

## Playing The Game:

**Olden Bling** can be played from your command-line. If you just want to play the game, look in the `distributions` directory of this project.

If your OS isn't listed, you will need to compile the game yourself with a C compiler (such as GCC).

## For Developers:

### The Game Engine:

The basic game loop is defined in *olden_bling.c* (in the `main` function). 

The game uses a struct called `Player` to manage the player's state. One of the properties of this struct is `current_location`, which holds a function pointer that represent a location (See the `Location` typedef in the  *player.h* file).

After creating an instance of a `Player` struct, and setting its initial location, the game loop will continue to call the player's `current_location` property, until the property is `NULL`.

### Game files:

 - **olden_bling.c** -- The entry point for the game. Runs the game loop.
 - **/locations** -- The directory for the functions that represent locations in the game.
 - **/engine/player.h** -- Defines the `Player` struct. Also defines the `Location` function pointer type. Also contains functions for instantiating a new player, and for handling the player's collectibles.
 - **/engine/monster.h** -- Defines the `Monster` struct, used to represent enemies in the game.
 - **/engine/choice.h** -- `makeChoice` is used to present the player with a number of options.
 - **/engine/combat.h** -- `runCombat` is used to run the combat between the player and an enemy.
 - **/engine/items.h** -- Defines the collectibles in the game, and also the `ValuedItem` struct for other items (such as weapons/shields).
 - **/engine/util.h** -- Contains utility functions.

[My Twitter: @mattdarbs](http://twitter.com/mattdarbs)  
[My Portfolio](http://md-developer.uk)
