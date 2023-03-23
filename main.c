#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

char *monty_bytecode = (void *) 0;

/**
 * run_monty - Parses the monty bytecode and makes the necessary function calls
 *
 * @bytecode: Input string containing the monty bytecode
 * @stack: A pointer to the stack data structure
 *
 * Return: Nothing
 */
void run_monty(char *bytecode, stack_t **stack)
{
	int line_no;
	char *tok;
	bool first;
	void (*func)(stack_t **, unsigned int);

	tok = (void *) 0;
	line_no = 1;
	first = true;
	do {
		if (first)
		{
			tok = strtok(bytecode, " \n");
			first = false;
		}
		else
			tok = strtok((void *) 0, " \n");
		if (tok == (void *) 0)
			break;
		func = get_op_func(tok);

		if (func == (void *) 0)
			break;
		func(stack, line_no);
		line_no++;
	} while (tok != (void *) 0);
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
	monty_bytecode = read_file(argv[1]);

	run_monty(monty_bytecode, &stack);
	return (EXIT_SUCCESS);
}
