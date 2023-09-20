#include "main.h"

/**
 * exec_cmd - executes the command passed to the shell by the user
 * @com: struct with info required by the function
 * Return: Always 0(Success)
 */
int exec_cmd(full_cmd com)
{
	int child;

	/* create a child process */
	child = fork();
	/* check if it is a child process */
	if (child == 0)
	{
		/* first check execution status, print error if it fails */
		if (execve(com.cmd, com.args, NULL) == -1)
		{
			print_err_m(com.prog_name, com.c_cmd_num);
			perror("");
			exit(-1);
		}
	}
	/* stop the main process till the child process finishes execution */
	else
	{
		wait(&child);
	}
	return (0);
}
