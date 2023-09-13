#include "main.h"
/**
 * exec_c - check every entered command if is valid,
 * check from the builtins commands during system call.
 *
 * @av: command to be executed
 * @pro_na:  Name of the program that is going to be executed.
 *
 * Return: return int type if successfull.
 */
int exec_c(char **av, char *pro_na)
{
unsigned long int idx;
char *env_b_list[] = {"exit", "env", "cd"};
int (*pre_defined_func[])(char **) = {&exit_func, &env_func, &cd_func};

if (!av)
{
return (-1);
}
for (idx = 0; idx < sizeof(env_b_list) / sizeof(char *); idx++)
{
if (strcmp(av[0], env_b_list[idx]) == 0)
{
return ((*pre_defined_func[idx])(av));
}
}
return (kernel_s_call(av, pro_na));
}
