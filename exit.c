#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the maximum number of characters to be copied
 *
 * Return: the pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of bytes to be used
 *
 * Return: the pointer to the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (result);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: a pointer to the first occurrence of the character in the string
 * or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

