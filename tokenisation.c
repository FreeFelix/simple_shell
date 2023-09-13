#include "main.h"
/**
 * strings_tokenisation - Fuction tokinezes string entered as a commnand
 * added into an array of string or characters
 *
 * @command: command input prompt
 *
 * Return: characters in an array
 */
char **strings_tokenisation(char *command)
{
int buf_size = 64;
int i = 0;
char *token1, **token2;
token2 = malloc(buf_size * sizeof(char *));

if (!tokens2)
{
perror("memory allocation failure token2");
exit(EXIT_FAILURE);
}
token1 = strtok(command, "\t\n");
while (token1 != NULL)
{
token2[i] = token1;
i++;
if (i >= buf_size)
{
buf_size += buf_size;
token2 = realloc(token2, buf_size * sizeof(char*));
if (token2 == NULL)
{
perror("reallocation token failed");
exit(EXIT_FAILURE);
}
}
token1 = strtok(NULL, "\t\n");
}
token2[i] = NULL;
return (token2);
}
