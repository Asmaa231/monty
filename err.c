#include "monty.h"

/**
 * HError - Prints appropriate error messages determined by their error code.
 * @ECode: The error codes are the following:
 * (1) => The user did not provide any file or provided more than one file to the program.
 * (2) => The file provided cannot be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to allocate more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for an operation.
 */
void HError(int ECode, ...)
{
    va_list args;
    char *instruction;
    int LNumber;

    va_start(args, ECode);
    if (ECode == 1)
    {
        fprintf(stderr, "USAGE: monty file\n");
    }
    else if (ECode == 2)
    {
        fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
    }
    else if (ECode == 3)
    {
        LNumber = va_arg(args, int);
        instruction = va_arg(args, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", LNumber, instruction);
    }
    else if (ECode == 4)
    {
        fprintf(stderr, "Error: malloc failed\n");
    }
    else if (ECode == 5)
    {
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * HMErrors - Handles errors.
 * @ECode: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for an operation.
 * (9) => Division by zero.
 */

void HMErrors(int ECode, ...)
{
    va_list args;
    char *instruction;
    int LNumber;

    va_start(args, ECode);
    if (ECode == 6)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
    }
    else if (ECode == 7)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
    }
    else if (ECode == 8)
    {
        LNumber = va_arg(args, unsigned int);
        instruction = va_arg(args, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", LNumber, instruction);
    }
    else if (ECode == 9)
    {
        fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * HSErrors - Handles errors.
 * @ECode: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void HSErrors(int ECode, ...)
{
    va_list args;
    int LNumber;

    va_start(args, ECode);
    LNumber = va_arg(args, int);
    if (ECode == 10)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", LNumber);
    }
    else if (ECode == 11)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", LNumber);
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}
