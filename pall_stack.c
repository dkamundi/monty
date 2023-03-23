#include "monty.h"
#include <stdio.h>

/**
 * pall_stack - Prints all the value of the nodes in the stack
 *
 * @stack: Pointer to the stack to print
 * @line_number: Line number of the monty bytecode file being executed
 *
 * Return: Nothing
 */
void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *iter;

	iter = *stack;
	while (iter)
	{
		printf("%d\n", iter->n);
		iter = iter->next;
	}
}
