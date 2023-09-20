#include "main.h"

/**
 * Print_env - Handles env cmd and prints the environmnt
 * @c: A struct of the command.
 * Return: void
 */
void Print_env(full_cmd c)
{
	int i = 0;

	c.cmd = _which(c);
	exec_cmd(c);
	if (c.args[1] == NULL || _strcmp(c.args[1], "-v") == 0)
	{
		for (; environ[i] != NULL; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
		}
	}

	if (c.args[1] != NULL && _strcmp(c.args[1], "-0") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
		}
		write(1, "\n", 1);
	}
	free(c.cmd);
}

