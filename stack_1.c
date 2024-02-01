#include "monty.h"

/**
 * AddNodeToStack - Adds a node to the stack.
 * @new_node: new node.
 * @LNumber: Integer representing the line number of the opcode.
 */
void AddNodeToStack(stack_t **new_node, unsigned int LNumber)
{
	stack_t *Tem;

	(void) LNumber;

	if (new_node == NULL || *new_node == NULL)
	{
		fprintf(stderr, "Error: Invalid parameters\n");
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	Tem = head;
	head = *new_node;
	head->next = Tem;
	Tem->prev = head;
}
/**
 * PstackContents - Prints all the values on the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @LNumber: Line number of the opcode.
 */
void PstackContents(stack_t **stack, unsigned int LNumber)
{
	stack_t *Tem;

	(void) LNumber;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	Tem = *stack;

	while (Tem != NULL)
	{
		printf("%d\n", Tem->n);
		Tem = Tem->next;
	}
}
/**
 * PopFromStack - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @LNumber: Integer representing the line number of the opcode.
 */
void PopFromStack(stack_t **stack, unsigned int LNumber)
{
	stack_t *Tem;

	if (stack == NULL || *stack == NULL)
		more_err(7, LNumber);

	Tem = *stack;
	*stack = Tem->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(Tem);
}
/**
 * PTopOfStack - Prints the value at the top of the stack.
 *@stack: Pointer to a pointer pointing to the top node of the stack.
 * @LNumber: Integer representing the line number of the opcode.
 */
void PTopOfStack(stack_t **stack, unsigned int LNumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, LNumber);
	printf("%d\n", (*stack)->n);
}

