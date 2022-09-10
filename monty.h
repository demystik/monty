#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


stack_t *create_stack(int data);
stack_t *push(stack_t **stack, int data);
stack_t *pop(stack_t **stack);
void free_stack_t(stack_t *item);
void free_stack(stack_t **stack);
void fun_push(stack_t **stack, unsigned int arg);
void fun_pall(stack_t **stack, unsigned int line);
void fun_pint(stack_t **stack, unsigned int line);
void fun_pop(stack_t **stack, unsigned int line);
void fun_swap(stack_t **stack, unsigned int line);
void fun_add(stack_t **stack, unsigned int line);
void fun_nop(stack_t **stack, unsigned int line);
void fun_sub(stack_t **stack, unsigned int line);
void fun_div(stack_t **stack, unsigned int line);
void fun_mul(stack_t **stack, unsigned int line);
void fun_mod(stack_t **stack, unsigned int line);
void fun_pchar(stack_t **stack, unsigned int line);
void fun_pstr(stack_t **stack, unsigned int line);
void fun_rotl(stack_t **stack, unsigned int line);
void fun_rotr(stack_t **stack, unsigned int line);
void fun_queue(stack_t **stack, unsigned int line);

/* up_code handlers */
void (*select_opcode_handler(char *upcode))(stack_t **, unsigned int);


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


 /* void get_func(char *upcode,char *arg, int line); */
int if_num(char *arg);
size_t getline(char **lineptr, size_t *n, FILE *stream);




#endif /* MONTY_H */
