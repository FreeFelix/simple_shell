#ifndef MAIN_H
#define MAIN_H
#define MAX_ARGS 64
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define TOKENISES_ALL_DELIM " \n\t\r\a\""
extern char **environ;

int exec_c(char **av, char *pro_na);
void  interact_mode(char *command);
void  non_interact_mode(void);
char *get_input(void);
char **strings_tokenisation(char *command);
int env_func(char **av);
int kernel_s_call(char **av, char *pro_na);
void fprintf(const char *msg);
int _customcd(char **av);
int _customhelp(char **av);
int cd_fun(char **av);
int ext(char **av)
#endif
