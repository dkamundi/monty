#include "monty.h"
#include <stdlib.h>

/**
 * free_all - Frees all allocated memory (stack and monty_b struct)
 *
 * Return: Nothing
 */
void free_all()
{
	free_stack();
	free(code_m->bytecode);
	free(code_m);
}
