#include "monty.h"

/**
 * validate_usage - checks if the program usage is valid
 * @argc: number of arguments supplied to the program
*/
void validate_usage(int argc)
{
	if (argc != 2)
	{
		usage_error();
	}
}
