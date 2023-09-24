#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;

	if (info->token_number < 2 || !isInteger(info->tokens[1]))
	{
		no_argument_error();
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		malloc_error();
	}

	new_node->n = atoi(info->tokens[1]);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	info->elements += 1;
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
	{
		pop_empty_stack_error();
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
	info->elements -= 1;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	stack_t *current = *stack;

	(void)line_number;

	while (i < info->elements)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
		i++;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (info->elements > 0)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
	}
	else
	{
		pint_empty_stack_error();
	}
}

/**
 * nop - doesn’t do anything
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
