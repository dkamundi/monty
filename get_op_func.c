#include "monty.h"
#include <string.h>

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
		{((void *) 0), ((void *) 0)}
	};
	int i;

	i = 0;
	while (ops[i].opcode != (void *) 0 || ops[i].f != (void *) 0)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}
	return ((void *) 0);
}
