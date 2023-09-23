#include "shell.h"

/**
 * copy_string - duplicates a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to the destination
 */
char *copy_string(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = 0;
	return (destination);
}

/**
 * duplicate_string - creates a copy of a string
 * @str: the string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *duplicate_string(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--str;
	return (result);
}

/**
 * print_string - displays an input string
 * @str: the string to be displayed
 *
 * Return: Nothing
 */
void print_string(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
 * _putchar - writes the character to the standard output
 * @character: The character to be printed
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set accordingly.
 */
int _putchar(char character)
{
	static int buffer_index;
	static char buffer[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
	if (character != BUF_FLUSH)
		buffer[buffer_index++] = character;
	return (1);
}

