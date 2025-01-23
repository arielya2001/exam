#include <stdio.h>
#include <armor.h>

static int armor_equipped = 0; // Private variable to track armor state

void equip_armor(void)
{
    printf("Equipping armor...\n");
    make_shiny(); // Uses shiny.h function
    armor_equipped = 1;
}

void remove_armor(void)
{
    printf("Removing armor...\n");
    armor_equipped = 0;
}

int is_armor_equipped(void)
{
    return armor_equipped;
}