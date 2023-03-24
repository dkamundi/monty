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

void push_stack(stack_t **stack, unsigned int);
void pall_stack(stack_t **stack, unsigned int);
void (*get_op_func(char *))(stack_t **, unsigned int);
int get_char_no(char *);
char *read_file(char *);
bool validint(char *);
char *linetoken(char **, char *);
bool isDelim(char, char *);
char *_memcpy(char *, char *, unsigned int);
int _strlen(const char *);
int _strcmp(const char *, const char *);

extern char *monty_bytecode;
#endif
