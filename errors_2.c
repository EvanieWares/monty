#include "monty.h"

/**
 * no_argument_error - prints error when no arguments was found
*/
void no_argument_error(void)
{
	fprintf(stderr, "L%u: usage: push integer\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pint_empty_stack_error - prints error when pinting an empty stack
*/
void pint_empty_stack_error(void)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pop_empty_stack_error - prints error when poping an empty stack
*/
void pop_empty_stack_error(void)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", info->line_number);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * stack_too_short_error - prints error when stack is too short
 * @inst: the opcode (instruction)
*/
void stack_too_short_error(char *inst)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", info->line_number, inst);
	free_all();
	exit(EXIT_FAILURE);
}
