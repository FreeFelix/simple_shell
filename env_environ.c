#include "main.h"
/**
 * environment_functions - Functions that print environment using
 * by local and global variable of our shell
 *
 * @av: All variable are stored in array.
 *
 * Return: 1 if success else -1
 */
int environment_functions(char **av)
{
int idx = 0;
av = env;
while (av[idx])
{
write(STDOUT_FILENO, env[idx], strlen(env[idx]));
write(STDOUT_FILENO, "\n", 1);
idx++;
}
return (-1);
}
