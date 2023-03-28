#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for the program
 * @argc: Number of arguments passed to the program
 * @argv: String array of arguments passed to the program
 *
 * Return: 0 if executed successfully, 1 if not executed successfully
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_file(file);
	fclose(file);

	return (0);
}

/**
 * execute_file - starts the interpretation of the monty file
 * @file: The monty file
 *
 * Return: void(this function returns no value)
 */
void execute_file(FILE *file)
{
	unsigned int line_number;
	size_t len;
	char *opcode, *line;
	stack_t **stack;
	char *buffer;

	line_number = 1;
	len = 0;
	opcode = NULL;
	line = NULL;
	buffer = NULL;

	stack = malloc(sizeof(size_t *));
	*stack = NULL;

	while (getline(&buffer, &len, file) != -1)
	{
		line = strdup(buffer);
		opcode = get_opcode(line, line_number);
		if (opcode != NULL)
		{
			execute_opcode(stack, line_number, opcode);
		}
		line_number++;
	}

	/**TODO free stack here **/
	if (buffer)
		free(buffer);
}

/**
 * get_opcode - gets an opcode from a line of code in a monty file
 * @line: the line to be processed by the function
 * @line_number: the line number of the current line
 *
 * Return: the opcode gotten from the line
 */
char *get_opcode(char *line, unsigned int line_number)
{
	char *command;
	char *argument;

	command = NULL;

	command = strtok(strdup(line), " \t\n");

	if (command != NULL && strcmp(command, "push") == 0)
	{
		argument = strtok(NULL, " \t\n");
		if (argument != NULL && is_string_digit(strdup(argument)) == 1) 
			global.value = atoi(argument);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
		}
	}
	return (command);
}

/**
 * is_string_digit - checks if a string is a digit
 * @str: the string
 *
 * Return: 1 if it is a digit. 0 if it is not a digit
 */
int is_string_digit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

/**
 * execute_opcode - executes the opcode on the stack
 * @stack: the stack
 * @line_number: the line number of the current instruction
 * @opcode: the opcode to be executed
 *
 * Return: void(this function returns no value)
 */
void execute_opcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i, flag;

	flag = 0;

	for (i = 0; (global.instructions[i]).opcode != NULL; i++)
	{
		if (strcmp(opcode, global.instructions[i].opcode) == 0)
		{
			global.instructions[i].f(stack, line_number);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}


}
