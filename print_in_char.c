#include "monty.h"

/**
 * print_dlistchar - print content of doubly linked list
 * @h: pointer to the head node
 * @linenum: line number of the instruction in the .m file
 *
 * Return: length of the doubly linked list
 */
size_t print_dlistchar(stack_t *h, unsigned int linenum)
{
	size_t len = 0;
	char *lineptr = NULL;

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			linenum);
		free_dlistint(h);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (h->n < 0 || h->n > 132)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			linenum);
		free_dlistint(h);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
	return (len);
}

/**
 * print_dliststr - print content of doubly linked list
 * @h: pointer to the head node
 * @linenum: line number of the instruction in the .m file
 *
 * Return: length of the doubly linked list
 */
size_t print_dliststr(stack_t *h, unsigned int linenum)
{
	size_t len = 0;

	UNUSED(linenum);
	while (h != NULL  && h->n > 0 && h->n <= 132)
	{
		printf("%c", h->n);
		h = h->next;
		len++;
	}
	printf("\n");
	return (len);
}

/**
 * pchar - print content of doubly linked list
 * @head: pointer to the head node
 * @linenum: line number of the instruction in the .m file
 *
 * Return: length of the doubly linked list
 */
void pchar(stack_t **head, unsigned int linenum)
{
	print_dlistchar(*head, linenum);
}

/**
 * pstr - print content of doubly linked list
 * @head: pointer to the head node
 * @linenum: line number of the instruction in the .m file
 *
 * Return: length of the doubly linked list
 */
void pstr(stack_t **head, unsigned int linenum)
{
	print_dliststr(*head, linenum);
}
