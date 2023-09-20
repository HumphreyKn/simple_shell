#include "main.h"
/**
 * get_input - reads a line and checks if it is the end.
 * @line: a double pointer to string entered by the user
 * @buffsize: pointer to the buffer size created for the line
 * Return: number of characters entered by the user
 */

ssize_t get_input(char **line, size_t *buffsize)
{
	ssize_t st;
	/* Take the command from the user and check for errors */
	st = getline(line, buffsize, stdin);
	if (st == -1)
	{
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			write(1, "\n", 1);
		free(*line);
		exit(0);
	}
	return (st);
}
