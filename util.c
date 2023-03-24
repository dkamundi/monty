#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * get_char_no - This function get the total number of characters in the file
 *
 * @filename: Name of the file
 *
 * Return: Number of characters in file "filename"
 */
int get_char_no(char *filename)
{
	int line_no, fd_monty, tmp;
	char c;

	fd_monty = open(filename, O_RDONLY);
	if (fd_monty == -1)
		return (-1);
	tmp = line_no = 0;

	do {
		tmp = read(fd_monty, &c, 1);
		line_no++;
	} while (tmp != 0);
	close(fd_monty);
	return (line_no);
}

/**
 * read_file - Reads all the content of file and stores it in a string
 *
 * @file: Name of the file
 *
 * Return: Pointer to a string containing all of the content
 */
char *read_file(char *file)
{
	char *ret;
	int no_char, fd_monty;

	ret = (void *) 0;
	fd_monty = open(file, O_RDONLY);
	if (fd_monty == -1)
		return ((void *) 0);
	no_char = get_char_no(file);
	ret = malloc((sizeof(*ret) * no_char) + 1);
	if (ret == (void *) 0)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	read(fd_monty, ret, no_char);
	close(fd_monty);
	return (ret);
}

/**
 * validint - Checks if the input string contains only valid int characters
 *
 * @s: Input string
 *
 * Return: 1 if s contains only valid characters, -1 Otherwise
 */
bool validint(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != 43 && s[i] != 45))
			return (false);
	}
	return (true);
}

/**
 * flush_line - Flushes the whole character of a line
 *
 * Return: Nothing
 */
void flush_line(void)
{
	char **bytecode;
	int i;

	i = 0;
	bytecode = &monty_bytecode;
	while (*bytecode != (void *) 0 && (*bytecode)[i] != '\0')
	{
		if ((*bytecode)[i] == '\n')
		{
			*bytecode = &((*bytecode)[i + 1]);
			break;
		}
		i++;
	}
}
