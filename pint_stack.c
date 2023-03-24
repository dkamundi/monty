#include "monty.h"
#include <stdio.h>

/**
 * pint_stack - Prints the value at the top of the stack
 *
 * @s: Pointer to the stack
 * @line_number: Line number of the bytecode being executed
 *
 * Return: Nothing
 */
void pint_stack(stack_t **s, unsigned int line_number)
{
	if (line_number > 0)
	{
		if (*s == (void *) 0)
			return;
		printf("%d\n", (*s)->n);
	}
}
