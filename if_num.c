#include "monty.h"

/**
 * if_num - This function checks if an argument is a number
 * @arg: argument to check
 * Author - Thaoban Abdrasheed
 *
 * Return: 1 if its num and 0 if otherwise
 */
int if_num(char *arg)
{
	size_t i = 0;

	if (arg == NULL)
		return (0);

	if (arg[0] == '-')
		i++;

	if (arg[i] == '\0')
		return (0);

	while (arg[i] >= '0' && arg[i] <= '9')
		i++;

	if (arg[i] != '\0')
		return (0);

return (1);
}
