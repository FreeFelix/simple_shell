#include "main.h"
/**
 * main - main entry functions for all functions.
 * @ac: arguments counter in our passed function
 * @av: array contains all passed args.
 *
 * Return: Always 0(Success)
 */
int main(int ac, char *av[])
{
int file_descr = STDIN_FILENO;
if (isatty(file_descr) == 1)
{
interact_mode(av[ac - 1]);
}
else
{
non_interact_mode(av[ac - 1]);
}
return (0);
}
