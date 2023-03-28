#include "monty.h"
/**
 * push - pushes a number to a stack
 * @stack: The stack
 * @line_number: the line number of the instruction
 *
 * Return: void(this function returns no value)
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *new;

	new = malloc(sizeof(stack_t *));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = global.value;

	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new;
		new->prev = temp;
		new->next = NULL;
	}
	line_number = line_number;
}

/**
 * pall - prints all the elements in a stack
 * @stack: the stack
 * @line_number: the line number of the instruction
 *
 * Return: void(this function returns no value)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
	line_number = line_number;
}
