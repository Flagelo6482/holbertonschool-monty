#include "monty.h"

/**
 * error_argc - Print an error message
 *
 *Return: EXIT_FAILURE
 */

int error_argc(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * open_error - Open error message
 *@file_name: Name of file
 *
 *Return: EXIT_FAILURE
 */

int open_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	return (EXIT_FAILURE);
}

/**
 * error_malloc - Failed malloc
 *
 *Return EXIT_FAILURE
 */

int error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
