#include "monty.h"

/**
 * free_all - frees all the allocated memory
 */
void free_all(void)
{
	free_tokens();
	free_line();
	free_stack();
	free_instruction();
	close_stream();
	free_info();
}

/**
 * free_tokens - frees all the tokens (args)
 */
void free_tokens(void)
{
	int i = 0;

	if (info->tokens)
	{
		while (info->tokens[i])
		{
			free(info->tokens[i]);
			i++;
		}

		free(info->tokens);
		info->tokens = NULL;
		info->token_number = 0;
	}
}

/**
 * free_instruction - frees the instruction
 */
void free_instruction(void)
{
	if (info->instr)
	{
		free(info->instr);
	}
}

/**
 * free_stack - frees the stack
 */
void free_stack(void)
{
	stack_t *temp;

	while (info->stack)
	{
		temp = info->stack;
		info->stack = info->stack->next;
		free(temp);
	}
}

/**
 * free_line - frees the buffer allocated by getline()
 */
void free_line(void)
{
	if (info->line)
	{
		free(info->line);
		info->line = NULL;
	}
}
