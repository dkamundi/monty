#ifndef _MONTY_H
#define _MONTY_H

#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_op - monty bytecode and variables to help in parsing
 * @bytecode: the monty bytecode
 * @len: the length of the bytecode to read
 * @start: index to start reading opcode
 * @pstart: index to start reading opcode
 * @plen: length of the previous opcode
 * @arg: Holds the index for argument (if it has one)
 *
 * Description: This struct aid in extracting and filtering
 * the monty bytecode
 */
typedef struct monty_op
{
	char *bytecode;
	int len;
	int start;
	int pstart;
	int arg;
	int plen;
} monty_b;

void push_stack(stack_t **, unsigned int);
void pall_stack(stack_t **, unsigned int);
void pint_stack(stack_t **, unsigned int);
void pop_stack(stack_t **, unsigned int);
void swap_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void nop_stack(stack_t **, unsigned int);
void free_stack(stack_t **);
void (*get_op_func(monty_b **))(stack_t **, unsigned int);
int get_char_no(char *);
char *read_file(char *);
bool validint(char *);
void linetoken(monty_b **, char *);
int delim_type(char, char *);
char *_memcpy(char *, monty_b **);
int _strlen(const char *);
int _strncmp(const char *, monty_b **);
void flush_line(void);

extern monty_b *code_m;
#endif
