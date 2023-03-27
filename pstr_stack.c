#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pstr_stack - Prints the string starting at the top of the string
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void pstr_stack(stack_t **s, unsigned int line_number)
{
	stack_t *iter;

	if (line_number)
		iter = (void *) 0;
	if ((*s) == (void *) 0)
	{
		printf("\n");
	}

	for (iter = *s; iter != (void *) 0; iter = iter->next)
	{
		if (iter->n > 127 || iter->n < 0 || iter->n == 0)
			break;
		printf("%c", iter->n);
	}
	printf("\n");
	flush_line();
}
