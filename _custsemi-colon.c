#include "main.h"
/**
 * _custexecutecmd - fun is being executed
 * @cmdargs: command arguments
 *
 * Return: nothing
 */
void _custexecutecmd(char **cmdargs)
{
execvp(cmdargs[0], cmdargs);
perror("failed");
exit(EXIT_FAILURE);
}

/**
 * _custpipe_func - customize number of pipe.
 * @args: passes arguments to fun
 * @num_pipes: the number of pipes to use
 *
 * Return: integer is succesful
 */
int _custsemicolon_func(char *args[], int num_pipes)
{
int i, j, scmdargcount;
pid_t c1, c2;
char **fmdargs = NULL;
char **scmdargs = NULL;
char **cmdargs_list[num_pipes];

for (i = 0; args[i] != NULL; i++)
{
if ((strcmp(args[i], ";") == 0) || (strcmp(args[i], "&&") == 0))
{
args[i] = NULL;
break;
}
}
{
for (i = 0; i < num_pipes; i++)
{
cmdargs_list[i] = malloc((i + 1) * sizeof(char *));
for (j = 0; j < i; j++) {
cmdargs_list[i][j] = args[j];
}
cmdargs_list[i][i] = NULL;
}

for (i = 0; i < num_pipes; i++)
{
c1 = fork();
if (c1 < 0)
{
perror("failed");
exit(EXIT_FAILURE);
}
else if (c1 == 0)
{
_custexecutecmd(cmdargs_list[i]);
}
c2 = fork();
if (c2 < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
else if (c2 == 0)
{
_custexecutecmd(cmdargs_list[i + 1]);
fprintf(stderr, "No second command provided\n");
exit(EXIT_FAILURE);
}
else if (c2 > 0)
{
waitpid(c1, NULL, 0);
waitpid(c2, NULL, 0);
}
}

for (i = 0; i < num_pipes; i++)
{
free(cmdargs_list[i]);
}

return (-1);
}
