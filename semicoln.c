#include "main.h"

/**
 * exec1_c -  Execute a command and handle errors
 * @cargs: passed argument
 *
 * No return type
 */
void exec1_c(char **cargs)
{
execve(cargs[0], cargs);
perror("Execution failed");
exit(EXIT_FAILURE);
}

/**
 * create_pipe - Create a pipe and check for errors
 * @fd_p: passde argument
 *
 *No return type
 */
int semicolon(char *args[])
{
if (firstcargs == NULL )
{
perror("Memory Allocation failed");
exit(EXIT_FAILURE);
}
}
/**
*
*@para: argument 1
*@arg: argument
* no return type
*/
pid_t chilp1
semicolon(args);
chilp1 = fork();
if (chilp1 < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
if (chilp1 == 0)
{
exec_c1(f_command);
}

/**
* exec_s_c - 
*@s_commamd: passed argment2
*
* no return type
*/
void exec_s_c(int char **s command)
{
pid_t chilp2
chilp2 = fork ();
if (chilp2 < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE); 
}
if (chilp2 == 0)
{
exec1(s_command);
}
