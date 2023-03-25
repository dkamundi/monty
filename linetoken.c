#include "monty.h"
#include <stdlib.h>

/**
 * _memcpy - Copies a number of characters from m to dest
 *
 * @dest: Destination string
 * @m: Pointer to monty struct containing the opcode string
 *
 * Return: Pointer to destination string
 */
char *_memcpy(char *dest, monty_b **m)
{
	int i, j;

	if ((*m)->len == -2 || (*m)->len < 0)
		return ((void *) 0);
	if (dest == (void *) 0)
	{
		dest = malloc(sizeof(*dest) * (*m)->len + 1);
		if (dest == (void *) 0)
			return (dest);
	}
	for (j = 0, i = (*m)->start; i < ((*m)->start + (*m)->len); i++, j++)
	{
		dest[j] = (*m)->bytecode[i];
	}
	dest[j] = '\0';
	return (dest);
}

/**
 * delim_type - Checks the type if c is a delimiter and if it is, what type
 *
 * @c: Input character to check
 * @delim: Input string containing the delimiters
 *
 * Return: if c is a delimiting char return 1, 2 if it's a newline, 0 otherwise
 * Description: This function is customised to work with the linetoken function
 * it's shouldn't be assumed to work like the strtok function from the string.h
 * library
 */
int delim_type(char c, char *delim)
{
	int i;

	if (c == '\n')
		return (2);
	for (i = 0; delim[i] != '\0'; i++)
	{
		if (delim[i] == c)
			return (1);
	}
	return (0);
}

/**
 * linetoken - Retrieves token on a line (string line)
 *
 * @monty: Pointer to monty struct containing the string with tokens
 * @delim: Strings containing the delimiters
 *
 * Return: Ponter to the token retrieved
 */
void linetoken(monty_b **monty, char *delim)
{
	int i, c_len, delim_typ;
	bool r_delim, not_first;

	not_first = r_delim = false;
	c_len = delim_typ = 0;
	i = (*monty)->start;
	while ((*monty)->bytecode[i] != '\0')
	{
		delim_typ = delim_type((*monty)->bytecode[i], delim);
		if (delim_typ == 0)
		{
			(*monty)->start = !not_first ? i : (*monty)->start;
			not_first = true;
			c_len++;
		} else if (delim_typ == 1 || delim_typ == 2)
		{
			if (delim_typ == 2 && c_len == 0)
			{
				flush_line();
				break;
			}
			if (!r_delim && c_len > 0)
			{
				(*monty)->len = c_len;
				r_delim = true;
			}
		}

		if (r_delim && (delim_typ == 0 || delim_typ == 2))
		{
			(*monty)->arg = delim_typ == 0 ? i : -1;
			break;
		}
		i++;
	}
	if ((*monty)->bytecode[i] == '\0')
		(*monty)->start = -1;
}
