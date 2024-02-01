#include "monty.h"
/*stack_t *head = NULL;*/

/**
 *main - function as entry point
 *@argv: the arguments list
 *@argc: count of arguments
 *Return: 0 all the time
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	OpenMontyFile(argv[1]);
	fr_node();
	return (0);
}

/**
 *make_node - function makes a new node
 *@x: number or data ain node
 *Return: a node pointer on sucess otherwise Null
 */
stack_t *make_node(int x)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		erro(4);

	node->prev = NULL;
	node->next = NULL;
	node->x = x;
	return (node);
}

/**
 *fr_node - function frees node
 *Return: void
 */
void fr_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
