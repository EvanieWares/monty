#include "monty.h"

info_t *info = NULL;

/**
 * main - entry point
 * @argc: number of arguments supplied
 * @argv: array of arguments supplied
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	validate_usage(argc);
	initialize_info();
	info->filename = argv[1];
	get_stream();

	return (0);
}
