#include "monty.h"

/**
 * add - add the first two nodes, put the result on the second node and delete
 * the head node
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void add(stack_t **head, unsigned int linenum)
{
	size_t len;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}

	((*head)->next)->n += (*head)->n;
	delete_dnodeint(head, linenum);
}

/**
 * sub - sub the first two nodes, put the result on the second node and delete
 * the head node
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void sub(stack_t **head, unsigned int linenum)
{
	size_t len;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n -= (*head)->n;
	delete_dnodeint(head, linenum);
}

/**
 * mul - mul the first two nodes, put the result on the second node and delete
 * the head node
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void mul(stack_t **head, unsigned int linenum)
{
	size_t len;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n *= (*head)->n;
	delete_dnodeint(head, linenum);
}

/**
 * divi - div the first two nodes, put the result on the second node and delete
 * the head node
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void divi(stack_t **head, unsigned int linenum)
{
	size_t len;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n = (int) (((*head)->next)->n / (*head)->n);
	delete_dnodeint(head, linenum);
}

/**
 * mod - mod the first two nodes, put the result on the second node and delete
 * the head node
 * @head: pointer to the head node pointer
 * @linenum: the line number the instruction being executed
 *
 */
void mod(stack_t **head, unsigned int linenum)
{
	size_t len;
	char *lineptr = NULL;

	len = dlistint_len(*head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", linenum);
		free_dlistint(*head);
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n %= (*head)->n;
	delete_dnodeint(head, linenum);
}
