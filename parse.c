#include "monty.h"

/**
 * tokenize_input - tokenizes the instruction
 */
void tokenize_input(void)
{
	int i = 0;
	char *line_dup, *token, *delims = " \t\n";

	line_dup = malloc(sizeof(char) * (strlen(info->line) + 1));
	if (line_dup == NULL)
		malloc_error();

	strcpy(line_dup, info->line);
	token = strtok(line_dup, delims);
	if (token == NULL)
	{
		free(line_dup);
		return;
	}

	while (token != NULL)
	{
		info->token_number += 1;
		token = strtok(NULL, delims);
	}

	initialize_tokens();
	strcpy(line_dup, info->line);
	token = strtok(line_dup, delims);
	while (token != NULL)
	{
		info->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (info->tokens[i] == NULL)
		{
			malloc_error();
		}
		strcpy(info->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}

	info->tokens[i] = NULL;
	free(line_dup);
}

/**
 * get_instruction - parses the instruction
 */
void get_instruction(void)
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop}};

	if (info->token_number == 0)
	{
		return;
	}

	while (i < 7)
	{
		if (strcmp(instruction[i].opcode, info->tokens[0]) == 0)
		{
			info->instr->opcode = instruction[i].opcode;
			info->instr->f = instruction[i].f;
			return;
		}
		i++;
	}
	invalid_instruction_error(info->tokens[0]);
}

/**
 * isInteger - chacks if a string is integer
 * @str: string to check
 *
 * Return: 1 if true, otherwise 0
 */
int isInteger(const char *str)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}