#ifndef ARMOR_H
#define ARMOR_H

#include "shiny.h"  // We need this because equip_armor uses make_shiny

void equip_armor(void);
void remove_armor(void);
int is_armor_equipped(void);

#endif