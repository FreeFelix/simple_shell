#include "shell.h"

/**
 * split_string - Splits a given string into individual words.
 * Repeated delimiters are ignored.
 * @str: The input string
 * @delimiters: The delimiter string
 *
 * Return: A pointer to an array of words, or NULL on failure
 */
char **split_string(char *str, char *delimiters)
{
	int i, j, k, m, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!delimiters)
		delimiters = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delimiter(str[i], delimiters) && (is_delimiter
					(str[i + 1], delimiters) || !str[i + 1]))
			word_count++;

	if (word_count == 0)
		return (NULL);
	words = malloc((1 + word_count) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < word_count; j++)
	{
		while (is_delimiter(str[i], delimiters))
			i++;
		k = 0;
		while (!is_delimiter(str[i + k], delimiters) && str[i + k])
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = '\0';
	}
	words[j] = NULL;
	return (words);
}

/**
 * split_string_v2 - Splits a string into individual
 * words based on a single delimiter character.
 * @str: The input string
 * @delimiter: The delimiter character
 *
 * Return: A pointer to an array of words, or NULL on failure
 */
char **split_string_v2(char *str, char delimiter)
{
	int i, j, k, m, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delimiter && str[i + 1] == delimiter) ||
				(str[i] != delimiter && !str[i + 1]) || str[i + 1] == delimiter)
			word_count++;
	if (word_count == 0)
		return (NULL);
	words = malloc((1 + word_count) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < word_count; j++)
	{
		while (str[i] == delimiter && str[i] != '\0')
			i++;
		k = 0;
		while (str[i + k] != delimiter && str[i + k] && str[i + k] != delimiter)
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = '\0';
	}
	words[j] = NULL;
	return (words);
}

