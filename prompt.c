#include"main.h"i
/**
 * interact_mode - Function which will to intract our shell
 * in interactive mode.
 *
 * @command: command name call program
 * name
 *
 * Return: void(no return type)
 */
void interact_mode(char *command)
{
char *input_c;
char **argument;
int status;
while (1)
{
write(1, "#cisfun$ ", 9);
input_c = get_input();
argument = strings_tokenisation(input_c);
status = exec_c(argument, input_c);
free(input_c);
free(argument);
if (status >= 0)
{
exit(status);
}
else
{
continue;
}
}
