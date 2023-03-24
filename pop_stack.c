#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop_stack - Removes the element of the stack
 *
 * @s: Pointer to the stack (top)
 * @line_number: Line number of bytecode being executed
 *
 * Return: Nothing
 */
void pop_stack(stack_t **s, unsigned int line_number)
{
	if (*s == (void *) 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*s)->next != (void *) 0)
	{
		*s = (*s)->next;
		(*s)->prev = (void *) 0;
	} else
		*s = (void *) 0;
	flush_line();
}

