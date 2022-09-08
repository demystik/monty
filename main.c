#include "monty.h"

/**
 * main - monty execution starts
 * Author - Thaoban Abdrasheed
 * @lineptr: pointer to a buffer
 * @n: number of size to read
 * @stream: The file stream to read from
 *
 * Return: 0 on success
 */

size_t getline(char **lineptr, size_t *n, FILE *stream);
int main(int argc, char *argv[])
{
	FILE *file_ptr;
	char *buffer = NULL;
	size_t count;
	ssize_t line_read;
	char *upcode = NULL;
	char *arg = NULL;
	int line_num = 0;
	int num = 0;
	stack_t *buff = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
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
			{
				fprintf(stderr, "L%d: usage: push integer", line_num);
				exit(EXIT_FAILURE);
			}
			num = atoi(arg);
			fun_push(&buff, num);
		}

		if (strcmp(upcode, "pall") == 0)
			fun_pall(&buff, line_num);

		else if (strcmp(upcode, "pint") == 0)
			fun_pint(&buff, line_num);

		else if (strcmp(upcode, "pop") == 0)
			fun_pop(&buff, line_num);
	}

	fclose(file_ptr);
return (0);
}
