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
 * isDelim - Checks whether or not a character is part of the delimiter
 *
 * @c: Input character to check
 * @delim: Input string containing the delimiters
 *
 * Return: true if it c is a delimiting character, flase otherwise
 */
bool isDelim(char c, char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (delim[i] == c)
			return (true);
	}
	return (false);
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
	int i, start, c_len;
	char *ret;
	bool r_delim, is_delim;

	is_delim = r_delim = false;
	start = c_len = i = 0;
	ret = (void *) 0;
	while ((*s)[i] != '\0')
	{
		is_delim = isDelim((*s)[i], delim);
		if (is_delim)
		{
			if (!r_delim)
			{
				ret = malloc(sizeof(*ret) * c_len);
				_memcpy(ret, &((*s)[start]), c_len);
				r_delim = true;
			}
		} else if (r_delim && !is_delim)
		{
			*s = &((*s)[i]);
			return (ret);
		}
		if (!r_delim)
			c_len++;
		i++;
	}

	if ((*s)[i] == '\0')
	{
		*s = &((*s)[i]);
	}
	return (ret);
}
