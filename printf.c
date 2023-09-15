#include"main.h"
/**
 * fprintf - function which display output in stdout
 *
 * @msg: passed args
 *
 * Return: nothing to return
 */

void fprintf(const char *msg)
{
write(STDOUT_FILENO, message, strlen(msg));
}
