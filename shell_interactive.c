#include "main.h"

/**
 * interact_mode - definition for function
 * for interactive mode
 * @command: apps name identification
 *
 * Return: void
 */
void  interact_mode(char *command)
{
char *c_input;
char **args;
int exec_status;

while (1)
{
write(0, "$ ", 2);
line = get_input();
args = strings_tokenisation(c_input);
exec_status = exec_c(args, command);
free(c_input);
free(args);
if (exec_status >= 0)
{
exit(exec_status);
}
else
{
continue;
}
}
}
