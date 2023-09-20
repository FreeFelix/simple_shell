#include "main.h"

/**
 * cd_fun - function used to change dir
 *  @av: passed parameter
 *
 * Return: always 0 otherwise.
 */
int cd_fun(char **av)
{
if (av[1] == NULL)
{
fprintf(stderr, "Entered argument to \"cd\"\n");
}
else
{
if (chdir(av[1]) != 0)
{
perror("error in cd: changing dir\n");
}
}
return (-1);
}
