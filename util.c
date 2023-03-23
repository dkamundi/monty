#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

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
 * _getline - Get's the specified line number from the input string
 *
 * @s: Input string
 * @line_no: Line number to retrieve
 *
 * Return: Pointer to a string that contains the line number specified
 * Description: This function works under the assumption that each line
 * end with a new line.
 */
char *_getline(char *s, unsigned int line_no)
{
	int curr_lineno;
	unsigned int char_count, i, start;
	char *line;

	start = char_count = 0;
	curr_lineno = 0;
	for (i = 0; s[i] != '\0' && (curr_lineno != line_no); i++, char_count++)
	{
		if (s[i] == '\n')
		{
			start = i + 1;
			char_count = 0;
			curr_lineno++;
		}
		char_count++;
	}

	line = malloc(sizeof(*line) * char_count);
	strncpy(line, &s[start], char_count);
	return (line);
}

/**
 * validint - Checks if the input string contains only valid int characters
 *
 * @s: Input string
 *
 * Return: 1 if s contains only valid characters, -1 Otherwise
 */
int validint(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
	}
	return (1);
}
