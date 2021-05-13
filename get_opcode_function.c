#include "monty.h"

/**
 * get_opcode_function - returns function depending the opcode
 * @str: opcode input
 *
 * Return: function if opcode exists, otherwise NULL
 */
void (*get_opcode_function(char *str))(stack_t **, unsigned int)
{
	instruction_t ops_inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", divi},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; i < 11; i++)
		if (strcmp(str, ops_inst[i].opcode) == 0)
			return (ops_inst[i].f);
	return (NULL);
}
