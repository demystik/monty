#include "monty.h"


/**
 * main - monty execution starts
 * Author - Thaoban Abdrasheed
 * @argc: arg counter
 * @argv: arg vector
 *
 * Return: 0 on success
 */


int main(int argc, char *argv[])
{
	FILE *file_ptr;
	size_t count;
	ssize_t line_read;
	char *upcode = NULL, *arg = NULL, *buffer = NULL;
	unsigned int line_num = 0;
	stack_t *buff = NULL;

	if (argc != 2)
		arg_err();
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
		open_err(argv[1]);
	while ((line_read = getline(&buffer, &count, file_ptr)) != -1)
	{
		line_num += 1;
		buffer[line_read - 1] = '\0';
		upcode = strtok(buffer, " ");
		arg = strtok(NULL, " ");
		if (upcode == NULL)
			continue;
		if (strcmp(upcode, "push") == 0)
		{
			if (if_num(arg) == 0)
				push_err(line_num);
			fun_push(&buff, atoi(arg));
			continue;
		}
		if (strcmp(upcode, "pall") == 0)
			fun_pall(&buff, line_num);
		else if (strcmp(upcode, "pint") == 0)
			fun_pint(&buff, line_num);
		else if (strcmp(upcode, "pop") == 0)
			fun_pop(&buff, line_num);
		else
			else_err(line_num, upcode);
		free_stack(&buff);
	}
	free_stack(&buff);
	fclose(file_ptr);
return (0);
}
