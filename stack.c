#include "monty.h"

/**
 * stack_created - Create a stackt_t
 *
 *@stack: Pointer to stack_t
 *
 *Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int stack_created(stack_t **stack)
{
	stack_t *head;

	head = malloc(sizeof(stack_t));

	if (head == NULL)
		return (error_malloc());

	head->n = STACK;
	head->prev = NULL;
	head->next = NULL;

	*stack = head;

	return (EXIT_SUCCESS);
}
