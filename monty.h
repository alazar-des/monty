#ifndef HF
#define HF

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

extern char *lineptr;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_opcode_function(char *str, int queueflag))(stack_t **, unsigned int);
void push_begin(stack_t **head, unsigned int linenum);
void push_end(stack_t **head, unsigned int linenum);
void pall(stack_t **head, unsigned int linenum);
void pint(stack_t **head, unsigned int linenum);
void pop(stack_t **head, unsigned int linenum);
void swap(stack_t **head, unsigned int linenum);
void nop(stack_t **head, unsigned int linenum);
void add(stack_t **head, unsigned int linenum);
void sub(stack_t **head, unsigned int linenum);
void mul(stack_t **head, unsigned int linenum);
void divi(stack_t **head, unsigned int linenum);
void mod(stack_t **head, unsigned int linenum);
void pchar(stack_t **head, unsigned int linenum);
void pstr(stack_t **head, unsigned int linenum);
void rotl(stack_t **head, unsigned int linenum);
void rotr(stack_t **head, unsigned int linenum);

size_t print_dlistint(stack_t *h, unsigned int linenum, int pint_flag);
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint(stack_t **head, unsigned int linenum);
size_t dlistint_len(const stack_t *h);
void free_dlistint(stack_t *head);

#endif
