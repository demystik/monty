#include "monty.h"

/**
 * main - monty execution starts
 * Author - Thaoban Abdrasheed
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


	
	if (argc != 2)
	{
	    fprintf(stderr,"USAGE: monty file\n");
    	    exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s",argv[1]);
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
		get_func(upcode, arg, line_num);
	}

	printf("\n end of file reached\n");
	fclose(file_ptr);
return (0);
}
