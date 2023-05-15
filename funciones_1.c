#include "monty.h"

/**
 * push - Add elements to the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *valor = strtok(NULL, " \n");
	stack_t *nuevo;
	int i;

	if (!valor)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; valor[i]; i++)
	{
		if ((valor[i] >= '0' && valor[i] <= '9') || (i == 0 && valor[i] == '-'))
			continue;

		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	nuevo = malloc(sizeof(stack_t));
	if (!nuevo)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	nuevo->n = atoi(valor);
	nuevo->prev = NULL;
	nuevo->next = *stack;

	if (*stack)
		(*stack)->prev = nuevo;

	*stack = nuevo;
}

/**
 * pall - this function print in the  output
 * @stack: double linked list of a stack
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *actual = *stack;

	while (actual)
	{
		printf("%d\n", actual->n);
		actual = actual->next;
	}
}

/**
  * pint - print the value at the top of the stack
  * @stack: stack
  * @line_number: line number
  * Return:nothing
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",  line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
  * pop - removes the top element of the stack
  * @stack: stack
  * @line_number: linea
  * Return: nothing
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
  * swap - swaps the top two elements of the stack
  * @stack: stack
  * @line_number: line number
  * Return: nothing
  */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
