#include "monty.h"

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
