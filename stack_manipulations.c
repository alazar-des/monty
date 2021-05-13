#include "monty.h"

#define UNUSED(x) (void)(x)

/**
 * swap - swap the content of the first two nodes
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void swap(stack_t **head, unsigned int linenum)
{
	size_t len;
	int temp;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n;
	(*head)->n = ((*head)->next)->n;
	((*head)->next)->n = temp;
}

/**
 * nop - doesn't to do anything
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void nop(stack_t **head, unsigned int linenum)
{
	UNUSED(linenum);
	UNUSED(head);
}
