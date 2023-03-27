#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar_stack - Prints the char at the top of the string
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void pchar_stack(stack_t **s, unsigned int line_number)
{
	if ((*s) == (void *) 0)
	{
		free_all();
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	} else if ((*s)->n > 127 || (*s)->n < 0)
	{
		free_all();
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*s)->n);
	flush_line();
}
