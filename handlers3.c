#include "monty.h"


/**
 * fun_mod - This function computes the rest of the division of
 * the second top element of the stack
 * by the top element of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_mod(stack_t **stack, unsigned int line)
{
	stack_t *a = *stack;
	*stack = (*stack)->next;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (a->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= a->n;
	(*stack)->prev = NULL;
	free_stack_t(a);
}






/**
 * fun_pchar - This function prints the char at the top of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_pchar(stack_t **stack, unsigned int line)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 177)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}






/**
 * fun_pstr - This function prints string at the top of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_pstr(stack_t **stack, unsigned int line)
{
	(void) line;
	if ((*stack) == NULL)
		printf("\n");
	while((*stack) != NULL && (*stack)->n != 0)
	{
		if ((*stack)->n <= 0 || ((*stack)->n) > 177)
			break;
		printf("%c",(*stack)->n);
		(*stack) = (*stack)->next;
	}
	printf("\n");
}

/**
 * fun_rotl - This function rotates the stack to the top
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_rotl(stack_t **stack, unsigned int line)
{
	stack_t *rot = *stack;
	stack_t *mov = *stack;

	(void) line;

	while (rot->next != NULL)
		rot = rot->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	mov->next = NULL;
	rot->next = mov;
}

/**
 * fun_rotr - This function rotates the stack to the bottom
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_rotr(stack_t **stack, unsigned int line)
{
	stack_t *rot = *stack;
	stack_t *pre = *stack;

	(void) line;
	while (rot->next != NULL)
		rot = rot->next;
	pre = rot->prev;
	pre->next = NULL;
	rot->prev = NULL;
	rot->next = *stack;
	(*stack)->prev = rot;
	*stack = (*stack)->prev;
}
