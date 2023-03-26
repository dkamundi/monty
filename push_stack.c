#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

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

	tok = (void *) 0;
	psh = malloc(sizeof(*psh));
	if (psh == (void *) 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (code_m->arg > 0)
	{
		code_m->start = code_m->arg;
		linetoken(&code_m, " \n");
		tok = _memcpy(tok, &code_m);
	}
	if (tok == (void *) 0 || !validint(tok))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
	free(tok);
	flush_line();
}
