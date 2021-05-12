#include "monty.h"

/**
 * print_dlistint - print content of doubly linked list
 * @h: pointer to the head node
 * @linenum: line number of the instruction in the .m file
 * @pint_flag: a pint flag to differentiate pint from pall
 *
 * Return: length of the doubly linked list
 */
size_t print_dlistint(stack_t *h, unsigned int linenum, int pint_flag)
{
	size_t len = 0;
	char *lineptr = NULL;

	if (pint_flag)
	{
		if (h == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
			free_dlistint(h);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		printf("%d\n", h->n);
		return (len);
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}
	return (len);
}

/**
 * add_dnodeint - insert node at the begining of doubly linked list
 * @head: a pointer to the head node address
 * @n: node data
 *
 * Return: address of the new node on success, otherwise null
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;
	char *lineptr = NULL;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head != NULL)
		new->prev = (*head)->prev;
	else
		new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (*head);
}

/**
 * delete_dnodeint - delete the head node and return the data
 * @head: pointer to head node
 * @linenum: line number of the instruction in the .m file
 *
 * Return: return the data of the head node
 */
int delete_dnodeint(stack_t **head, unsigned int linenum)
{
	int data;
	stack_t *next;
	char *lineptr = NULL;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	next = (*head)->next;
	data = (*head)->n;
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head)->next->prev = NULL;
		free(*head);
		*head = NULL;
		*head = next;
	}
	return (data);
}

/**
 * dlistint_len - return the length of doubly linked list
 * @h: pointer to the head node
 *
 * Return: length of the doubly linked list
 */
size_t dlistint_len(const stack_t *h)
{
	size_t len = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			len++;
			h = h->next;
		}
	}
	return (len);
}

/**
 * free_dlistint - free doubly linked list
 * @head: pointer to the head node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = NULL;
		head = next;
	}
	free(head);
	head = NULL;
}
