#include "monty.h"

/**
 * pop_error - Prints pop error messages when stack is empty.
 * @line_number: Line number in Monty bytecodes file where error ocurred.
 *
 *Return: (EXIT_FAILURE)
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division by zero error messages.
 * @line_number: Line number in Monty bytecodes file where error ocurred.
 *
 *Return: (EXIT_FAILURE)
 */

int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages when stack is empty
 * @line_number: Line number in Monty bytecodes file where error ocurred.
 *
 *Return: (EXIT_FAILURE)
 */

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
