#include "monty.h"

#define UNUSED(x) (void)(x)

/**
 * rotl - rotate stack to the left
 * @head: pointer to head node pointer
 * @linenum: line number instruction is being executed
 *
 */
void rotl(stack_t **head, unsigned int linenum)
{
	size_t len, i;
	stack_t *h;

	UNUSED(linenum);
	len = dlistint_len(*head);
	if (len > 1)
	{
		(*head)->next->prev = NULL;
		h = *head;
		for (i = 0; i < len - 1; i++)
			*head = (*head)->next;
		(*head)->next = h;
		h->prev = *head;
		*head = h->next;
		h->next = NULL;
	}
}

/**
 * rotr - rotate stack to the right
 * @head: pointer to head node pointer
 * @linenum: line number instruction is being executed
 *
 */
void rotr(stack_t **head, unsigned int linenum)
{
	size_t len, i;
	stack_t *h;

	UNUSED(linenum);
	len = dlistint_len(*head);
	if (len > 1)
	{
		h = *head;
		for (i = 0; i < len - 1; i++)
			*head = (*head)->next;
		h->prev = *head;
		(*head)->next = h;
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
	}
}
