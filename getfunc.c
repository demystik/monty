#include "monty.h"

void get_func(char *upcode, char *arg, int line)
{
	int num = 0;
	stack_t *buff = NULL;

	if (strcmp(upcode, "push") == 0)
	{
		if (if_num(arg) == 0)
		{
			fprintf(stderr,"L%d: usage: push integer", line);
			exit(EXIT_FAILURE);
		}
		num = atoi(arg);

		fun_push(&buff, num);
	}

	if (strcmp(upcode, "pall") == 0)
		fun_pall(&buff, line);

	else if (strcmp(upcode, "pint") == 0)
		fun_pint(&buff, line);

	else if (strcmp(upcode, "pop") == 0)
		fun_pop(&buff, line);
}
