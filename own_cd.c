#include "shell.h"

/**
 * _customcd - changes the working dir of the current shell executon env
 * @av: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int _customcd(char **av)
{
	if (av[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(av[1]) != 0)
		{
			perror("error in _customcd.c: changing dir\n");
		}
	}
	return (-1);
}
