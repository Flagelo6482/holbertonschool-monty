#include "monty.h"

/**
 * main - Entry point
 *
 *@argc: Number of Arguments
 *@argv: Argument list
 *
 *Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	FILE *file = NULL;

	if (argc != 2)
		return (error_argc());

	file = fopen(argv[1], "r");

	if (file == NULL)
		return (open_error(argv[1]));

	fclose(file);
}
