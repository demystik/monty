#include "monty.h"



/**
 * fun_add - This function adds two elements of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_add(stack_t **stack, unsigned int line)
{
	stack_t *new = *stack;
	stack_t *to_free = *stack;

	new = (*stack)->next;
	if (new == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	to_free = new;
	(*stack)->n += new->n;
	new = new->next;
	(*stack)->next = new;
	if (new)
		new->prev = (*stack)->next;
	free_stack_t(to_free);
}





/**
 * fun_nop - This function does not do anything
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_nop(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
}





/**
 * fun_sub - This function substrac the top element form the
 * second top element of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_sub(stack_t **stack, unsigned int line)
{
	stack_t *a = *stack;
	stack_t *b = *stack;

	b = (*stack)->next;
	if (b == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack) = b;
	(*stack)->n -= a->n;
	(*stack)->prev = NULL;
}






/**
 * fun_div - This function divides second top element of the
 * stack by the top element of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_div(stack_t **stack, unsigned int line)
{
	stack_t *a = *stack;
	*stack = (*stack)->next;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (a->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= a->n;
	(*stack)->prev = NULL;
	free_stack_t(a);
}





/**
 * fun_mul - This functionmultiplies the second top element
 * of the stack with the top element of the stack.
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_mul(stack_t **stack, unsigned int line)
{
	stack_t *a = *stack;
	*stack = (*stack)->next;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->n *= a->n;
	(*stack)->prev = NULL;
	free_stack_t(a);
}

