#include "monty.h"

/**
 * rotl_stack - Rotates the stack to the top
 *
 * @s: Pointer to the top of the stack
 * @line_number: Line number of bytecode being executed
 *
 * Return: Nothing
 */
void rotl_stack(stack_t **s, unsigned int line_number)
{
	stack_t *head, *tail, *iter;

	tail = *s;
	if (*s != (void *) 0 && (*s)->next != (void *) 0 && line_number > 0)
	{
		head = (*s)->next;
		head->prev = (void *) 0;

		for (iter = *s; iter->next != (void *) 0; iter = iter->next)
			continue;
		tail->prev = iter;
		tail->next = (void *) 0;
		iter->next = tail;
		*s = head;
	}
	flush_line();
}
