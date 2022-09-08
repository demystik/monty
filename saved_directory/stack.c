#include "monty.h"

stack_t *create_stack(int data)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = data;
	new->next = NULL;
	new->prev = NULL;
return (new);
}


void free_stack_t(stack_t *item)
{
	item->next = NULL;
	item->prev = NULL;
	free(item);
}

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


void fun_pall(stack_t **stack, int line)
{
	stack_t *cursor = *stack;
	if (line < 0)
		fprintf(stderr, "L%d: unknown instruction pall\n",line);

	while(cursor)
	{
		printf("%d\n",cursor->n);
		cursor = cursor->next;
	}
}


void fun_pint(stack_t **stack, int line)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void fun_pop(stack_t **stack, int line)
{
	stack_t *last = pop(stack);

	if (last == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	free_stack_t(last);
}
void fun_push(stack_t **stack, int arg)
{
	push(stack, arg);
}
