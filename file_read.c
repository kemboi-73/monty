#include "monty.h"

/**
 * checkopcode - determine if a particular code is valid
 * @opcode: opcode to check
 * @linenum: line number of code in file
 * @stream: file stream
 * @line: buffer having line content
 *
 * Return: nothing
 */
void checkopcode(char *opcode, int linenum, FILE *stream, char *line)
{
	int i, code_exist = 0;
	char *opcodes[8] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};

	opcodes[7] = NULL;
	for (i = 0; opcodes[i]; i++)
	{
		if (strcmp(opcodes[i], opcode) == 0)
		{
			code_exist += 1;
			break;
		}
	}
	if (code_exist == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, opcode);
		free(line);
		free_stack(stack);
		fclose(stream);
		exit(EXIT_FAILURE);
	}

}

/**
 * isit_number - determine if string is a number or not
 * @num: possible number string
 * @linenum: current line number
 * @stream: file stream
 * @line: current line buffer
 *
 * Return: nothing
 */

void isit_number(char *num, int linenum, FILE *stream, char *line)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (isdigit(num[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			free(line);
			free_stack(stack);
			fclose(stream);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * readandtok - read a file, perform checks and run opcode
 * @stream: file stream
 *
 * Return: nothing
 */
void readandtok(FILE *stream)
{
	char *line = NULL, *opcode, *arg;
	size_t len = 0;
	int linenum = 1, argi = 0;

	while (getline(&line, &len, stream) != -1)
	{
		line[strlen(line) - 1] = '\0';
		opcode = strtok(line, " ");
		if (opcode == NULL)
			opcode = ""; /* instance of an empty line*/
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " ");
			isit_number(arg, linenum, stream, line);
			argi = atoi(arg);
		}
		checkopcode(opcode, linenum, stream, line);
		checknrun(opcode, argi, linenum);

		linenum += 1;
	}

	free(line);
}
