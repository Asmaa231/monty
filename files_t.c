#include "monty.h"

/**
 * OpenMontyFile - Opens a Monty bytecode file.
 * @FilePath: The path to the Monty file.
 * Return: void
 */
void OpenMontyFile(char *FilePath)
{
	FILE *FileDescriptor = fopen(FilePath, "r");

	if (FilePath == NULL || FileDescriptor == NULL)
		handle_file_error(2, FilePath);

	ReadMontyFile(FileDescriptor);
	fclose(FileDescriptor);
}

/**
 * ReadMontyFile - Reads a Monty bytecode file.
 * @FileDescriptor: Pointer to the file descriptor.
 * Return: void
 */
void ReadMontyFile(FILE *FileDescriptor)
{
	int LNumber, format = 0;
	char *buffer = NULL;
	size_t buffer_size = 0;

	for (LNumber = 1; getline(&buffer, &buffer_size, FileDescriptor) != -1; LNumber++)
	{
		format = ParseLine(buffer, LNumber, format);
	}
	free(buffer);
}

/**
 * ParseLine - Separates each line into tokens to determine
 * which function to call.
 * @buffer: Line from the file.
 * @LNumber: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int ParseLine(char *buffer, int LNumber, int format)
{
	char *opcode, *value;
	const char *delimiters = "\n ";

	if (buffer == NULL)
		handle_file_error(4);

	opcode = strtok(buffer, delimiters);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimiters);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	FindOpcodeFunction(opcode, value, LNumber, format);
	return (format);
}

/**
 * FindOpcodeFunction - Finds the appropriate function for the opcode.
 * @opcode: Opcode.
 * @value: Argument of opcode.
 * @LNumber: Line number.
 * @format: Storage format. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 * Return: void
 */
void FindOpcodeFunction(char *opcode, char *value, int LNumber, int format)
{
	int i;
	int flag;

	instruction_t opcode_functions[] = {
		{"push", push_node},
		{"pall", PstackContents},
		{"pint", PTopOfStack},
		{"pop", PopFromStack},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", AddNodeToStack},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; opcode_functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcode_functions[i].opcode) == 0)
		{
			CallOpcode(opcode_functions[i].f, opcode, value, LNumber, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_file_error(3, LNumber, opcode);
}


/**
 * CallOpcode - Calls the required function for the opcode.
 * @function: Pointer to the function that is about to be called.
 * @opcode: String representing the opcode.
 * @value: String representing a numeric value.
 * @LNumber: Line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 * If 1, nodes will be entered as a queue.
 */

void CallOpcode(op_fun funct, char *opcode, char *value, int LNumber, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			handle_file_error(5, LNumber);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				handle_file_error(5, LNumber);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			funct(&node, LNumber);
		if (format == 1)
			add_to_queue(&node, LNumber);
	}
	else
		funct(&head, LNumber);
}

