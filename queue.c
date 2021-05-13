#include "monty.h"

/**
 * find_end_node - returns the last node
 * @h: pointer to the head node
 *
 * Return: the last node
 */
stack_t *find_end_node(stack_t *h)
{
	stack_t *head = h, *end = NULL, *temp;

	while (h != NULL)
	{
		temp = head;
		while (temp != h)
		{
			if (h->next == temp)
				return (h);
			temp = temp->next;
		}
		end = h;
		h = h->next;
	}
	return (end);
}

/**
 * add_dnodeint_end - add node at the end of doubly linked list
 * @head: pointer to the address of the head node
 * @n: data of the new node to be inserted
 *
 * Return: pointer to the new node on success, otherwise NULL
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *end, *new;
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
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
	else
	{
		end = find_end_node(*head);
		new->prev = end;
		new->next = end->next;
		end->next = new;
	}
	return (new);
}

/**
 * push_end - add node at the beginning
 * @head: points to the head node pointer
 * @linenum: line number of the instruction in the .m file
 *
 */
void push_end(stack_t **head, unsigned int linenum)
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
	add_dnodeint_end(head, n);
}
