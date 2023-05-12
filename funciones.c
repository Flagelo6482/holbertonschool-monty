#include "monty.h"

stack_t *stack = NULL;

/**
 * push - Pushes an element to the stack.
 * @line_number: The line number of the push instruction.
 * @n: The value to push onto the stack.
 */
void push(unsigned int line_number, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack();
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;

    if (stack == NULL)
    {
        new_node->next = NULL;
        stack = new_node;
    }
    else
    {
        new_node->next = stack;
        stack->prev = new_node;
        stack = new_node;
    }
    (void)line_number;
}

/**
 * pall - Prints all the values on the stack, starting from the top of the stack.
 * @line_number: The line number of the pall instruction.
 */
void pall(unsigned int line_number)
{
    stack_t *current = stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @line_number: The line number of the pint instruction.
 */
void pint(unsigned int line_number)
{
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        free_stack();
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack->n);
}

/**
 * pop - Removes the top element of the stack.
 * @line_number: The line number of the pop instruction.
 */
void pop(unsigned int line_number)
{
    stack_t *temp;

    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        free_stack();
        exit(EXIT_FAILURE);
    }

    temp = stack;
    stack = stack->next;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @line_number: The line number of the swap instruction.
 */
void swap(unsigned int line_number)
{
    int temp;

    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        free_stack();
        exit(EXIT_FAILURE);
    }

    temp = stack->n;
    stack->n = stack->next->n;
    stack->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @line_number: The line number of the add instruction.
 */
void add(unsigned int line_number)
{
    int sum;

    if (stack == NULL || stack->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        free_stack();
        exit(EXIT_FAILURE);
    }

    sum = stack->n + stack->next->n;
    pop(line_number);
    stack->n = sum;
}

/**
 * nop - Doesn't do anything.
 * @line_number: The line number of the nop instruction.
 */
void nop(unsigned int line_number)
{
    (void)line_number;
}

/**
 * free_stack - Frees a stack_t stack.
 */
void free_stack(void)
{
