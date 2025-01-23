#include <stdio.h>
#include <character.h>

int main()
{
    const char *hero_name = "Bob";

    say_hello(hero_name);
    check_armor_status(hero_name);

    equip_armor();
    check_armor_status(hero_name);

    remove_armor();
    check_armor_status(hero_name);

    return 0;
}