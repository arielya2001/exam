#ifndef CHARACTER_H
#define CHARACTER_H

#include "armor.h"  // We need this because check_armor_status uses is_armor_equipped

void say_hello(const char* name);
void check_armor_status(const char* name);

#endif