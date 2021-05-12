#include "monty.h"

#define UNUSED(linenum) (void)(linenum)

/**
 * push - add node at the beginning
 * @head: points to the head node pointer
 * @linenum: line number of the instruction in the .m file
 *
 */
void push(stack_t **head, unsigned int linenum)
{
	char *str;
	int n, i = 0;
	char *lineptr = NULL;

	str = strtok(NULL, " \n");
	while (str[i] != '\0')
	{
		if ((int) str[i] < 48 || (int) str[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			free_dlistint(*head);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	n = atoi(str);
	*head = add_dnodeint(head, n);
}

/**
 * pall - print doubly linked list
 * @head: points to the head node pointer
 * @linenum: line number of the instruction in the .m file
 *
 */
void pall(stack_t **head, unsigned int linenum)
{
	print_dlistint(*head, linenum, 0);
}

/**
 * pint - print only the node of doubly linked list
 * @head: points to the head node pointer
 * @linenum: line number of the instruction in the .m file
 *
 */
void pint(stack_t **head, unsigned int linenum)
{
	print_dlistint(*head, linenum, 1);
}

/**
 * pop - delete the head node and return the data
 * @head: points to the head node pointer
 * @linenum: line number of the instruction in the .m file
 *
 */
void pop(stack_t **head, unsigned int linenum)
{
	delete_dnodeint(head, linenum);
}
