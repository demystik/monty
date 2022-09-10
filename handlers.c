#include "monty.h"





/**
 * fun_pall - print all stack handler
 * @stack: pointer the stack
 * @line: current executing line
 * Author - Thaoban Abdrasheed
 *
 * Return: void
 */
void fun_pall(stack_t **stack,  unsigned int line)
{

	stack_t *cursor = *stack;


	(void) line;

	if (cursor == NULL)
		return;

	/* if (line == 0)*/
		/*fprintf(stderr, "L%d: unknown instruction pall\n", line);*/

	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}





/**
 * fun_pint - print the data of the last stack
 * @stack: pointer to the stack
 * @line: current executing lien
 * Author - Thaoban Abdrasheed
 *
 * Return: void
 */
void fun_pint(stack_t **stack, unsigned int line)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}




/**
 * fun_pop - handler for pop function
 * @stack: pointer to the stack
 * @line: current executing line
 * Author - Thaoban Abdrasheed
 *
 * Return: void
 */
void fun_pop(stack_t **stack, unsigned int line)
{
	stack_t *last = pop(stack);

	if (last == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	free_stack_t(last);
}

/**
 * fun_swap - This function swaps two element of the stack
 * @stack: pointer to the head stack
 * @line: current executing line
 * Author - Thaoban Abdrasheed
 *
 * Return: void
 */
void fun_swap(stack_t **stack, unsigned int line)
{
	stack_t *swp = *stack;
	stack_t *hold = *stack;

	swp = (*stack)->next;
	if (swp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	hold = malloc(sizeof(stack_t));
	if (hold == NULL)
	{
		free_stack_t(hold);
		exit(EXIT_FAILURE);
	}
	hold->n = (*stack)->n;
	(*stack)->n = swp->n;
	swp->n = hold->n;
	free_stack_t(hold);
}

/**
 * fun_push - handler for push function
 * @stack: pointer to the stack
 * @arg: integer data
 * Author - Thaoban Abdrasheed
 *
 * Return: void
 */
void fun_push(stack_t **stack, unsigned int arg)
{
	push(stack, arg);
}
