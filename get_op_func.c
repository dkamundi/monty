#include "monty.h"

/**
 * _strlen - Retrieves the length of the input string
 *
 * @s: Input string
 *
 * Return: Length of s
 */
int _strlen(const char *s)
{
	if (s == (void *) 0 || s[0] == '\0')
		return (0);
	return (1 + _strlen(&s[1]));
}

/**
 * _strcmp - Compares two strings
 *
 * @s1: Input string
 * @s2: Input string
 *
 * Return: 0 if s1 and s2 are equal, -1 is s1 < s2, and 1 if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int len1, len2, i;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (len1 != len2)
		return (-1);
	for (i = 0; s1[i] != '\0' && i < len1; i++)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	return (0);
}

/**
 * get_op_func - Selects the correct function to perform the operation asked
 *
 * @s: Operator passed as argument to the program
 *
 * Return: Pointer to the function that corresponds to the opcode s
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{((void *) 0), ((void *) 0)}
	};
	int i;

	i = 0;
	while (ops[i].opcode != (void *) 0 || ops[i].f != (void *) 0)
	{
		if (_strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}
	return ((void *) 0);
}
