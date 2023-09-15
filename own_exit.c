#include "main.h"

/**
 * _customexit - couses normal process termination
 * @av: empty args
 *
 * Return: 0 to terminate the process
 */
int _customexit(char **av)
{
	/* exit with status */
	if (av & av[1])
	{
		return (atoi(args[1]));
	}
	return (0);
	}
}
