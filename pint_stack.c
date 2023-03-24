#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (*s == (void *) 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
	flush_line();
}
