#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *stream;
	char *lineptr = NULL, *opcode = NULL, *delim = " \n";
	size_t len = 0;
	unsigned int line_num = 0;
	ssize_t nread;
	void (*func)(stack_t **, unsigned int);
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&lineptr, &len, stream)) != -1)
	{
		line_num++;
		opcode = strtok(lineptr, delim);
		if (opcode == NULL)
			continue;
		func = get_opcode_function(opcode);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num,\
				opcode);
			free_dlistint(head);
			free(lineptr);
			fclose(stream);
			exit(EXIT_FAILURE);
		}
		func(&head, line_num);
	}
	free(lineptr);
	free_dlistint(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
