#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

monty_b *code_m = (void *) 0;

/**
 * run_monty - Parses the monty bytecode and makes the necessary function calls
 *
 * @monty: Pointer to monty struct containing the monty bytecod to run
 * @stack: A pointer to the stack data structure
 *
 * Return: Nothing
 */
void run_monty(monty_b **monty, stack_t **stack)
{
	void (*func)(stack_t **, unsigned int);
	int line_no;
	char *tok;

	line_no = 1;
	tok = (void *) 0;
	do {
		linetoken(monty, " \n\0");
		if ((*monty)->len == -2)
		{
			line_no++;
			continue;
		}
		func = get_op_func(monty);
		if (func == (void *) 0)
		{
			tok = _memcpy(tok, monty);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, tok);
			free(tok);
			exit(EXIT_FAILURE);
		}
		func(stack, line_no);
		line_no++;
	} while ((*monty)->start != -1);
}

/**
 * main - Entry point to the monty language interpreter
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	int fd_monty;
	stack_t *stack;

	stack = (void *) 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd_monty = open(argv[1], O_RDONLY);
	if (fd_monty == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	code_m = malloc(sizeof(*code_m));
	code_m->bytecode = read_file(argv[1]);
	code_m->start = 0;
	code_m->len = -1;
	code_m->pstart = 0;
	code_m->plen = -1;
	code_m->arg = -1;

	run_monty(&code_m, &stack);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
