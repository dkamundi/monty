#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees all the nodes in a stack
 *
 * @s: Pointer to the top of the stack
 *
 * Return: Nothing
 */
void free_stack(stack_t **s)
{
	stack_t *iter, *tmp;

	iter = *s;
	tmp = (void *) 0;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		free(tmp);
	}
}
