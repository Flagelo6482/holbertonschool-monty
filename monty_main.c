#include "monty.h"
/**
 * main - funcion principal
 * @argc: cantidad de argumentos
 * @argv: lista de argumento
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	int i = 0, line_number = 0;
	char buffer[1000], *opcode;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
		error_argc();
	if (file == NULL)
		open_error(argv[1]);
	while (fgets(buffer, 1000, file))
	{
		line_number++;
		opcode = strtok(buffer, " \n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		while (instruc[i].opcode)
		{
			if (strcmp(instruc[i].opcode, opcode) == 0)
			{
				instruc[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (instruc[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: desconocida instruccion %s\n",  line_number, opcode);
			exit(EXIT_FAILURE);
		}
		i = 0;
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
