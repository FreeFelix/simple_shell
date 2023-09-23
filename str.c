#include "shell.h"

/**
 * string_length - calculates the length of a string
 * @s: the string to measure
 *
 * Return: an integer representing the length of the string
 */
int string_length(char *s)
{
	int length = 0;

	if (!s)
		return (0);

	while (*s++)
		length++;
	return (length);
}

/**
 * string_compare - compares two strings lexicographically.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a negative value if s1 < s2, a positive
 * value if s1 > s2, and zero if s1 == s2
 */
int string_compare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with_string - checks if a needle starts with a haystack
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: the address of the next character in haystack or NULL if not found
 */
char *starts_with_string(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * string_concatenate - appends one string to another
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer to the destination buffer
 */
char *string_concatenate(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}

