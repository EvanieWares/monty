#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	(void) line_number;
	if (info->elements < 2)
	{
		stack_too_short_error("swap");
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (info->elements < 2)
	{
		stack_too_short_error("add");
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
