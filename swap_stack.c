#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap_stack - Swaps the top two element of the stack
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void swap_stack(stack_t **s, unsigned int line_number)
{
	int swp;

	swp = 0;
	if ((*s) == (void *) 0 || (*s)->next == (void *) 0)
	{
		free_all();
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	swp = (*s)->n;
	(*s)->n = (*s)->next->n;
	(*s)->next->n = swp;
	flush_line();
}
