#ifndef MONTY_H
#define MONTY_H

#define _GUN_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/**
 *struct stack_k - d linked list for a stack or  queue
 *@x: an integer
 *@prev: pointer to stack or queue previous element
 *@next: pointer to stack or queue next element
 *Description: d linked list node structre for queue, stack, FIFO, LIFO
 */
typedef struct stack_k
{
	int x;
	struct stack_t *prev;
	struct stack_t *next;
} stack_t;

/**
 *struct instruction - the opcode plus its functions
 *@opcode: It's the opcode
 *@func: a function for handling opcode
 *Description: the opcode plus its functions for queue, stack, FIFO, LIFO
 */
typedef struct instruction
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int LNumber);
} instruction_t;

extern stack_t *head;
typedef void (*op_fun)(stack_t **, unsigned int);

/*file process*/
void OpenMontyFile(char *FilePath);
void ReadMontyFile(FILE *FileDescriptor);
int ParseLine(char *buffer, int LNumber, int format);
void FindOpcodeFunction(char *opcode, char *value, int LNumber, int format);
void CallOpcode(op_fun, char *opcode, char *value, int LNumber, int format);

/*stack process*/
stack_t *make_node(int x);
void fr_node(void);
void print_st(stack_t **, unsigned int);
void add_st(stack_t **, unsigned int);
void add_qu(stack_t **, unsigned int);

void top_print(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/*math processs in node*/
void add_node(stack_t **, unsigned int);

/*error*/
void erro(stack_t **, unsigned int);
void many_err(stack_t **, unsigned int);
#endif
