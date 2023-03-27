#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sub_stack - Subtracts the top two elements of the stack
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void sub_stack(stack_t **s, unsigned int line_number)
{
	stack_t *tmp;

	tmp = (void *) 0;
	if ((*s) == (void *) 0 || (*s)->next == (void *) 0)
	{
		free_all();
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *s;
	(*s)->next->n -= (*s)->n;
	(*s)->next->prev = (void *) 0;
	*s = (*s)->next;
	free(tmp);
	flush_line();
}
