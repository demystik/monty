#include "monty.h"


/**
 * fun_queue - This function sets the format of the data
 * to queue (FIFO)
 * @stack: pointer to the head stack
 * @line: current executing line
 *
 * Author - Thaoban Abdrasheed
 * Return: void
 */
void fun_queue(stack_t **stack, unsigned int line)
{
	stack_t mov = *stack;
	stack_t mov1 = *stack;

	(void) line;

	while (mov->next != NULL)
		mov = mov->next;
	mov1 = mov->prev;

	mov->next = (*stack);
	(*stack)->prev = mov;
	mov->prev = NULL;
	mov1 = mov;
	mo1 = mov1->prev;
	mov1->prev = (*stack)->next;
}
