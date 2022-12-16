#include "monty.h"

/**
 * m_mod - compute remainder (modulus) of second element divided by top element
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int num;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->num;
	m_pop(stack, line_number);
	if (num == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->num %= num;
}
