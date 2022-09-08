#include "monty.h"

/**
 * create_stack - This function creates new stack
 * @data: data to allocate to the new stack
 * Author - Abdrasheed Thaoban
 *
 * Return: the newly created stack
 */
stack_t *create_stack(int data)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->next = NULL;
	new->prev = NULL;
return (new);
}




/**
 * free_stack_t - The function frees a particular stack
 * @item: pointer to stack to free
 * Author - Thaoban Abdrasheed
 *
 * Return: nothing to return
 */
void free_stack_t(stack_t *item)
{
	item->next = NULL;
	item->prev = NULL;
	free(item);
}






/**
 * push - This function add a new stack
 * @stack: The pointer to the stack address
 * @data: The data to allocate to the new stack
 * Author - Abdrasheed Thaoban
 *
 * Return: pointer to the new stack
 */
stack_t *push(stack_t **stack, int data)
{
	stack_t *added_stack = create_stack(data);

	if (added_stack == NULL)
		return (NULL);

	added_stack->next = *stack;

	if (*stack)
		(*stack)->prev = added_stack;

	*stack = added_stack;
return (added_stack);
}





/**
 * pop - This function pops out the last stack
 * @stack: pointer to the address of the stack
 * Author - Thaoban Abdrasheed
 *
 * Return: address of the popped out stack
 */
stack_t *pop(stack_t **stack)
{
	stack_t *top_stack = *stack;

	if (top_stack != NULL)
	{
		*stack = top_stack->next;
		top_stack->next = NULL;
		if (*stack)
			(*stack)->prev = NULL;
	}
return (top_stack);
}







/**
 * free_stack - This function frees a whole stack
 * @stack: pointer to the stack
 * Author - Abdrasheed Thaoban
 *
 * Return: nothing to return
 */
void free_stack(stack_t **stack)
{
	stack_t *to_free = NULL;

	while (*stack)
	{
		to_free = *stack;
		*stack = (*stack)->next;
		free(to_free);
	}

}
