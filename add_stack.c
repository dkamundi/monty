#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_stack - Adds the top two elements of the stack
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void add_stack(stack_t **s, unsigned int line_number)
{
	if ((*s) == (void *) 0 || (*s)->next == (void *) 0)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*s)->next->n += (*s)->n;
	(*s)->next->prev = (void *) 0;
	*s = (*s)->next;
}
