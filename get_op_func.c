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
 * _strncmp - Compares two strings
 *
 * @s: Input string
 * @m: pointer to monty_b containing the bytecode string
 *
 * Return: 0 if s and the opcode in m are equal, -1 is s less, and 1 otherwise
 */
int _strncmp(const char *s, monty_b **m)
{
	int len1, m_i, i;

	len1 = _strlen(s);
	m_i = (*m)->start;
	if (len1 != (*m)->len)
		return (-1);
	for (i = 0; s[i] != '\0' && i < len1; i++, m_i++)
	{
		if (s[i] > (*m)->bytecode[m_i])
			return (1);
		else if (s[i] < (*m)->bytecode[m_i])
			return (-1);
	}
	return (0);
}

/**
 * get_op_func - Selects the correct function to perform the operation asked
 *
 * @monty: Pointer to monty data which contains the opcode to retrieve
 *
 * Return: Pointer to the function that corresponds to the opcode s
 */
void (*get_op_func(monty_b **monty))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{((void *) 0), ((void *) 0)}
	};
	int i;

	i = 0;
	while (ops[i].opcode != (void *) 0 || ops[i].f != (void *) 0)
	{
		if (_strncmp(ops[i].opcode, monty) == 0)
			return (ops[i].f);
		i++;
	}
	return ((void *) 0);
}
