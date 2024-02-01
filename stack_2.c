#include "monty.h"
/**
 *add_node - function adds top 2 elements in stack
 *@st: a pointer to a pointer to stack top node
 *@linenum: opcode line number
 *Return: void
 */
void add_node(stack_t **st, unsigned int linenum)
{
	int total;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		many_err(8, linenum, "add");

	(*st) = (*st)->next;
	total = (*st)->x + (*st)->prev->x;
	(*st)->x = total;
	free((*st)->prev);
	(*st)->prev = NULL;
}

/**
*swap - function swaps stack top 2 elements
*@st: a pointer to a pointer to stack top node
*@linenum: opcode line number
*Return: void
*/
void swap(stack_t **st, unsigned int linenum)
{
	stack_t *temp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		many_err(8, linenum, "swap");
	temp = (*st)->next;
	(*st)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *st;
	(*st)->prev = temp;
	temp->prev = NULL;
	*st = temp;

}

/**
 *nop - function does nothing
 *@st: a pointer to a pointer to stack top node
 *@linenum: opcode line number
 *Return: void
*/
void nop(stack_t **st, unsigned int linenum)
{
	(void)st;
	(void)linenum;
}
