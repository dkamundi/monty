#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * push_stack - Pushes a new node onto the stack
 *
 * @stack: Pointer to stack DS to push to
 * @line_number: Line number of the monty bytecode being executed
 *
 * Return: Nothing
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *psh;
	int val;
	char *tok;

	psh = malloc(sizeof(*psh));
	if (psh == (void *) 0)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok((void *) 0, " \n");
	if (validint(tok) == -1)
	{
		printf("L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(tok);
	psh->n = val;
	psh->prev = (void *) 0;
	if (*stack == (void *) 0)
		psh->next = (void *) 0;
	else
	{
		(*stack)->prev = psh;
		psh->next = *stack;
	}
	*stack = psh;
}
