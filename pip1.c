#include "main.h"

/**
 * exec_c -  Execute a command and handle errors
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
void create_pipe(int *fd_p)
{
if (pipe(fd_p) == -1)
{
perror("Pipe creation failed");
exit(EXIT_FAILURE);
}
}

/**
 * close_pipe - Close file descriptors associated with the pipe
 * @fd_p: passed argumet
 *
 * No return type
 */
void close_pipe(int *fd_p)
{
close(fd_p[0]);
close(fd_p[1]);
}

/**
 * exec_f_c - Handle the execution of the first command
 * @fd_p: arugment1
 * @f_command: argument
 *
 * No return type
 */
void exec_f_c(int *fd_p, char **f_command)
{
pid_t chilp1;
create_pipe(fd_p);
chilp1 = fork();
if (chilp1 < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
if (chilp1 == 0)
{
close(fd_p[0]);
dup2(fd_p[1], STDOUT_FILENO);
close(fd_p[1]);
exec_c1(f_command);
}
}

/**
 * exec_s_c - Handle the execution of the second command
 * @fd_p: passed argument1
 * @s_command: passed argment2
 *
 * No return type
 */
void exec_s_c(int *fd_p, char **s_command)
{
pid_t chilp2;
chilp2 = fork();
if (chilp2 < 0)
{
perror("Fork failed");
exit(EXIT_FAILURE);
}
if (chilp2 == 0)
{
close(fd_p[1]);
dup2(fd_p[0], STDIN_FILENO);
close(fd_p[0]);
exec_c1(s_command);
}
}
