#include "monty.h"
#include <stdlib.h>

/**
 * _memcpy - Copies n number of characters from src to dest
 *
 * @dest: Destination string
 * @src: Source string
 * @n: Number of bytes to copy
 *
 * Return: Pointer to destination string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	if (src == (void *) 0)
		return ((void *) 0);
	if (dest == (void *) 0)
	{
		dest = malloc(sizeof(*dest) * n);
		if (dest == (void *) 0)
			return (dest);
	}
	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}
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
 * @s: Input string containing the tokens
 * @delim: Strings containing the delimiters
 *
 * Return: Ponter to the token retrieved
 * Description: This function modifies the original string so make sure to
 * make a copy of the original
 */
char *linetoken(char **s, char *delim)
{
	int i, start, c_len, delim_typ;
	char *ret;
	bool r_delim, not_first;

	not_first = r_delim = false;
	delim_typ = start = c_len = i = 0;
	ret = (void *) 0;
	while (((*s)[i] != '\0'))
	{
		delim_typ = delim_type((*s)[i], delim);
		if (delim_typ == 0)
		{
			start = !not_first ? i : start;
			not_first = true;
			c_len++;
		}
		else if (delim_typ == 1 || delim_typ == 2)
		{
			if (delim_typ == 2 && c_len == 0)
			{
				flush_line();
				break;
			}
			if (!r_delim && c_len > 0)
			{
				ret = malloc(sizeof(*ret) * c_len);
				_memcpy(ret, &((*s)[start]), c_len);
				r_delim = true;
			}
		}
		if (r_delim && (delim_typ == 0 || delim_typ == 2))
		{
			*s = &((*s)[i]);
			return (ret);
		}
		i++;
	}
	if ((*s)[i] == '\0')
		*s = &((*s)[i]);
	return (ret);
}
