#include"main.h"
/**
 * kernel_s_call - Fuction that split entered strings.
 *
 * @av: line of enetered string.
 * @pro_na: instance of running process.
 *
 * Return: Output of character array.
 */
int kernel_s_call(char **av, char *pro_na)
{
char path[1024], *root_path = getenv("PATH"), *dir;
int i;

i = 0;
while (av[i] != NULL)
{
if (strcmp(av[i], '|') == 0)
{
	return (pipe_func(av));
}
if ((strcmp(av[i], ":") == 0) || (strcmp(av[i], "&&") == 0))
{
	return (symbol_fun(av));
}
i++;
}
if (access(av[0], X_OK) == 0)
{
return (ax_cmd(av[0], av));
}
strcpy(path, root_path);
dir = strtok(path, ":");

while (dir != NULL)
{
char whole_path[256];
strcpy(root_path, dir);
strcat(whole_path, "/");
strcat(whole_path, av[0]);
if (access(whole_path, X_OK) == 0)
{
return (ex_cmd(whole_path, av));
}
dir = strtok(NULL, ":");
}
perror(pro_na);
return (-1);
}
