#include "main.h"

/**
 * non_interact_mode - runs into non_interact mode.
 *
 * Return: Nothing
 */
void non_interact_mode(void)
{
char av;
char *line_input;
int execution_status;
while (1)
{
write(STDOUT_FILENO, "$", 2);
line_input = get_line();
av = strings_tokenisation(input_line);
}
execution_status = exec_c(av);
free(line_input);
free(av);

if (execution_status == EXIT_SUCCESS)
{
exit(EXIT_SUCCESS);
}
else
{
continue;
}

