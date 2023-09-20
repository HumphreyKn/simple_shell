#include "main.h"
/**
 * main - Entry point of the simple shell (will be updated frequent)
 * @ac: number of arguments (This argument is currently unused)
 * @av: pointer to pointer to the memory address of arguments
 * Return: 0 (Sucess)
*/
int main(int __attribute__((unused)) ac, char **av)
{
	full_cmd c;
	char *line;
	size_t buffsize;
	int i = 0;

	while (1)
	{
		/** Handling User Input And Execution */
		line = NULL;
		print_prompt();
		get_input(&line, &buffsize);
		i++;
		c = get_args(line);
		c.Gline = line;
		c.c_cmd_num = i;
		c.prog_name = av[0];
		if (c.cmd != NULL)
		{
			if (!built_in(c))
			{
				c.cmd = _which(c);
				if (c.cmd != NULL)
					exec_cmd(c);
				if (c.cmd == NULL && (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO)))
					return (127);
				free(c.cmd);/* free the memory */
			}
		}
		/** Lets free the memory of the arguments */
		_free(c.args, line, NULL);
	}
	return (0);
}
