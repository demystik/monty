#include "monty.h"

void (*select_opcode_handler(char *upcode))(stack_t **, unsigned int)
{
	if (strcmp(upcode, "pall") == 0)
		return (fun_pall);
	if (strcmp(upcode, "pint") == 0)
		return (fun_pint);
	if (strcmp(upcode, "pop") == 0)
		return (fun_pop);
	if (strcmp(upcode, "swap") == 0)
		return (fun_swap);
	if (strcmp(upcode, "add") == 0)
		return (fun_add);
	if (strcmp(upcode, "nop") == 0)
		return (fun_nop);
	if (strcmp(upcode, "sub") == 0)
		return (fun_sub);
	if (strcmp(upcode, "div") == 0)
		return (fun_div);
	if (strcmp(upcode, "mul") == 0)
		return (fun_mul);
	if (strcmp(upcode, "mod") == 0)
		return (fun_mod);
	if (strcmp(upcode, "pchar") == 0)
		return (fun_pchar);
	if (strcmp(upcode, "pstr") == 0)
		return (fun_pstr);
	if (strcmp(upcode, "rotl") == 0)
		return (fun_rotl);
	if (strcmp(upcode, "rotr") == 0)
		return (fun_rotr);
	if (strcmp(upcode, "queue") == 0)
		return (fun_queue);

	return (NULL);


}
