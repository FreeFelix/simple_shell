#include "shell.h"

/**
 * interact_mode - UNIX command line interpreter
 *
 * Return: void
 */
void interact_mode(void)
{
	char **av;
	char *line;
	int exec_c;

	do-while {
		free(line);
		free(av);
        
        av = string_tokenisation(line);
        line = get_input();
        exec_c =   (av);
        _putchar("simple_prompt$ "); /* print prompt symbol */
		
		if (!(status <= -1)
		{
			exit(status);
		}
	} do-while (status == -1);
}
