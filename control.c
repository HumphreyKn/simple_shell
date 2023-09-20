#include "main.h"

/**
 * built_in - control built-in commands and execute if match
 * @com: command given by the user
 * Return: 1 if command is built-in, 0 if not
 */

int built_in(full_cmd com)
{
	int i;
	builtin_t builtins[] = {{"exit", sh_exit},
							{"env", Print_env},
							{NULL, NULL}};

	for (i = 0; (builtins + i)->name != NULL; i++)
	{
		if (strcmp(com.args[0], (builtins + i)->name) == 0)
		{
			(builtins + i)->func(com);
			return (1);
		}
	}
	return (0);
}
