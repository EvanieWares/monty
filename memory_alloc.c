#include "monty.h"

/**
 * initialize_info - allocates memory to the info_t struct
 */
void initialize_info(void)
{
	info = malloc(sizeof(info_t));
	if (info == NULL)
	{
		malloc_error();
	}

	initialize_stack();
	initialize_instruction();

	info->line_number = 0;
	info->token_number = 0;
	info->elements = 0;
	info->file = NULL;
	info->filename = NULL;
	info->line = NULL;
	info->tokens = NULL;
}

/**
 * initialize_stack - allocates memory to the stack
*/
void initialize_stack(void)
{
	info->stack = malloc(sizeof(stack_t));
	if (info->stack == NULL)
	{
		malloc_error();
	}
}

/**
 * initialize_instruction - allocates memory to the instructions
*/
void initialize_instruction(void)
{
	info->instr = malloc(sizeof(instruction_t));
	if (info->instr == NULL)
	{
		malloc_error();
	}
}

/**
 * initialize_tokens - allocates memory to the tokens (args)
*/
void initialize_tokens(void)
{
	info->tokens = malloc(sizeof(char *) * (info->token_number + 1));
	if (info->tokens == NULL)
	{
		malloc_error();
	}
}
