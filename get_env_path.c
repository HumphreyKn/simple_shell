#include "main.h"

/**
 * get_envpath - gets PATH from the environment
 *
 * Return: PATH as a string, NULL if PATH is not found
 */

char *get_envpath(void)
{
	int i;
	char *Path;
	char varname[] = "PATH=";

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!_strncmp(varname, environ[i], 5))
		{
			Path = malloc(_strlen(environ[i]) + 1);
			if (Path == NULL)
				exit(-1);
			_strcpy(Path, environ[i]);
			return (Path);
		}
	}
	return (NULL);
}


