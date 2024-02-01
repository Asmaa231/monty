#include "monty.h"

/**
 * erro - Prints appropriate error messages determined by their error code.
 * @erro_code: The error codes are the following:
 * (1) => The user did not provide any file or one file to the program.
 * (2) => The file provided cannot be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to allocate more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for an operation.
 */
void erro(int erro_code, ...)
{
	va_list args;
	char *instruction;
	int LNumber;

	va_start(args, erro_code);
	if (erro_code == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (erro_code == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	}
	else if (erro_code == 3)
	{
		LNumber = va_arg(args, int);
		instruction = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", LNumber, instruction);
	}
	else if (erro_code == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (erro_code == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * many_err - Handles errors.
 * @err_code: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for an operation.
 * (9) => Division by zero.
 */

void many_err(int err_code, ...)
{
	va_list args;
	char *instruction;
	int LNumber;

	va_start(args, err_code);
	if (err_code == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	}
	else if (err_code == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	}
	else if (err_code == 8)
	{
		LNumber = va_arg(args, unsigned int);
		instruction = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", LNumber, instruction);
	}
	else if (err_code == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);
}
