#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees all the nodes in a stack
 *
 * Return: Nothing
 */
void free_stack()
{
	stack_t *iter, *tmp;

	iter = code_m->s;
	tmp = (void *) 0;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		free(tmp);
	}
}
