#include "monty.h"

/**
 * rotr_stack - Rotates the stack to the bottom
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of bytecode being executed
 *
 * Return: Nothing
 */
void rotr_stack(stack_t **s, unsigned int line_number)
{
	stack_t *tail, *iter;

	if (*s != (void *) 0 && (*s)->next != (void *) 0 && line_number > 0)
	{
		for (iter = *s; iter->next != (void *) 0; iter = iter->next)
			continue;
		tail = iter->prev;
		tail->next = (void *) 0;
		iter->prev = (void *) 0;
		iter->next = *s;
		*s = iter;
	}
	flush_line();
}
