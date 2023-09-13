#include"main.h"
/**
 * get_input - get the input from user as command
 *
 * Return: return a string or a character
 */
char *get_input(void)
{
int buffer_size = 1024;
int i = 0;
char *command = malloc(sizeof(char) * buffer_size);
int str;

if (command == NULL)
{
fprintf(stderr, "Error in get user input");
exit(EXIT_FAILURE);
}
while (1)
{
str = _putchar();
if (char_str == EOF)
{
free(command);
exit(EXIT_SUCCESS);
}
else if (str == '\n')
{
command[i] = '\0';
return (command);
}
else
{
command[i] = str;
}
i++;
if (i >= buffer_size)
{
buffer_size += buffer_size;
command = realloc(command, buffer_size);
if (command == NULL)
{
fprintf(stderr, "Error in get user input")
exit(EXIT_FAILURE);
}
}
}
