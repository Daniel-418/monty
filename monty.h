#ifndef MONTY_GUARD
#define MONTY_GUARD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure
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
 * Descriptioni: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - a struct for global variables
 * @instructions: the array of instructions and associated functions
 * @value: the value associated with a command
 *
 * Description: this struct carries essential variables in between functions.
 */
typedef struct global_s
{
	instruction_t *instructions;
	int value;
} global_t;

/** Variables to be shared among functions **/
extern global_t global;

/** Utility functions **/
void execute_file(FILE *file);
char *get_opcode(char *line, unsigned int line_number);
void execute_opcode(stack_t **stack, unsigned int line_number, char *opcode);
int is_string_digit(char *str);
char *strdup(const char *s);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**Stack functions**/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
#endif
