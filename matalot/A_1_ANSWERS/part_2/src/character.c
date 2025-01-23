#include <stdio.h>
#include <character.h>

void say_hello(const char *name)
{
    printf("Hello! I am %s!\n", name);
}

void check_armor_status(const char *name)
{
    if (is_armor_equipped())
    {
        printf("%s is protected by armor\n", name);
    }
    else
    {
        printf("%s is not protected!\n", name);
    }
}