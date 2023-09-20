#include "main.h"
/**
 * print_prompt - print a prompt if in interactive mode.
 *
 * Return: nothing(void)
 */
void print_prompt(void)
{
	char command_prompt[] = "$ ";
	int len = _strlen(command_prompt);

	/* Printing the prompt */
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		write(1, command_prompt, len);
}
