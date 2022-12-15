#include "monty.h"

/**
 * check_for_digit - checks that a string only containes digits
 * @str: string to check
 *
 * Return: 0 if only digits, and 1 if otherwise.
 */

static int check_for_digit(char *str)
{
	int n;

	for (n = 0; str[n]; n++)
	{
		if (str[n] == '-' && n == 0)
			continue;
		if (isdigit(str[n]) == 0)
			return (1);
	}
	return (0);
}

/**
 * m_push - Adds an element at the top o stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	char *str;
	int num;

	str = strtok(NULL, "\n\t\r ");
	if (str == NULL || check_for_digit(str))
	{
		dprint(STDOUT_FILENO,
				"L%u: usage: push integer\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(str);
	if (!add_node(stack, num))
	{
		dprint(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
