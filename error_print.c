#include "monty.h"

/**
 * arg_err - arg error for error arguments
 *
 * Return: void
 */
void arg_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * open_err - open error
 * @arg: argument
 *
 * Return: void
 */
void open_err(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);
}



/**
 * push_err - push error
 * @line: line
 *
 * Return: void
 */
void push_err(unsigned int line)
{
	fprintf(stderr, "L%d: usage: push integers\n", line);
	exit(EXIT_FAILURE);
}



/**
 * else_err - else error
 * @line: line
 * @upcode: upcode
 * Return: void
 */
void else_err(unsigned int line, char *upcode)
{

	fprintf(stderr, "L%d: unknown instruction %s", line, upcode);
	exit(EXIT_FAILURE);
}
