#include "shell.h"

/**
 * is_chain_delimiter - Determines if the current character
 * in the buffer is a chain delimiter
 * @info: The parameter struct
 * @buf: The character buffer
 * @p: Address of the current position in buf
 *
 * Return: 1 if it's a chain delimiter, 0 otherwise
 */
int is_chain_delimiter(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* Indicates the end of this command */
	{
		buf[j] = 0; /* Replaces semicolon with null terminator */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * should_continue_chaining - Checks if we should continue
 * chaining based on the last command's status
 * @info: The parameter struct
 * @buf: The character buffer
 * @p: Address of the current position in buf
 * @i: Starting position in buf
 * @len: Length of buf
 *
 * Return: Void
 */
void should_continue_chaining(info_t *info, char *buf, size_t *p,
		size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * aliases - Replaces aliases in the tokenized string
 * @info: The parameter struct
 *
 * Return: 1 if aliases were replaced, 0 otherwise
 */
int aliases(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = duplicate_string(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * variables - Replaces variables in the tokenized string
 * @info: The parameter struct
 *
 * Return: 1 if variables were replaced, 0 otherwise
 */
int variables(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!string_compare(info->argv[i], "$?"))
		{
			string_value(&(info->argv[i]), duplicate_string
					(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!string_compare(info->argv[i], "$$"))
		{
			string_value(&(info->argv[i]), duplicate_string
					(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			string_value(&(info->argv[i]), duplicate_string
					(_strchr(node->str, '=') + 1));
			continue;
		}
		string_value(&info->argv[i], duplicate_string(""));
	}
	return (0);
}

/**
 * string_value - Replaces a string value
 * @old: Address of the old string
 * @new: New string value
 *
 * Return: 1 if the string value was replaced, 0 otherwise
 */
int string_value(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

