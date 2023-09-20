#include "main.h"

/**
 * view_c - view and access command
 * @root_path: root for system call
 * @args: passed argument
 *
 * Return: Always int
 */
int view_c(char *root_path, char **args)
{
pid_t pid, last_pid;
int status;
int exc_ve_status;

pid = fork();
if (pid == 0)
{
exc_ve_status = execve(root_path, args, environ);
if (exc_ve_status == -1)
{
return (-1);
}
}
else if (pid > 0)
}
last_pid = waitpid(pid, &status, WUNTRACED);
if (last_pid == -1)
{
perror("error while waiting for the child process to end");
return (-1);
}
else
{
perror("fork failed");
return (-1);
}
return (-1);
}
