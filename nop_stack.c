#include "monty.h"

/**
 * nop_stack - Does nothing
 *
 * @s: Pointer to the stack
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void nop_stack(stack_t **s, unsigned int line_number)
{
	if (line_number >= 1)
		*s = *s;
	flush_line();
}
