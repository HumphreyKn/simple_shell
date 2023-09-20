#include "main.h"

/**
 * _strdup - returns pointer that contains a copy
 * of the given string
 * @str: the string to be copied
 *
 * Return: pointer to the duplicated string, NULL if
 * memory is insufficient
 */

char *_strdup(char *str)
{
	int i;
	char *dup = malloc(_strlen(str) + 1);

	if (dup == NULL)
	{
		perror("Error");
		exit(-1);
	}
	for (i = 0; str[i] != '\0'; i++)
		*(dup + i) = *(str + i);
	*(dup + i) = *(str + i);
	return (dup);
}

/**
 * _which - searches for an exe program in the PATH environment
 * @c: the specific exe to search
 *
 * Return: absolute path if found, NULL if path not found
 */

char *_which(full_cmd c)
{
	char *fullpath;
	char *token;
	char *Path;
	struct stat statbuf;

	if (stat(c.cmd, &statbuf) == 0)
		return (_strdup(c.cmd));
	Path = get_envpath();
	strtok(Path, "=");
	token = strtok(NULL, ":");
	/* Search the PATH environment */
	while (token != NULL)
	{
		fullpath = malloc(_strlen(c.cmd) + _strlen(token) + 2);
		if (fullpath == NULL)
		{
			free(Path);
			perror("Error: ");
			exit(-1);
		}
		_strcpy(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, c.cmd);

		/* Check if the absolute path exists or correct */
		if (stat(fullpath, &statbuf) == 0)
		{
			free(Path);
			return (fullpath);
		}
		free(fullpath);
		token = strtok(NULL, ":");
	}
	/* When the path does not exist print error and return NULL */
	free(Path);
	print_notfound(c.prog_name, c.c_cmd_num, c.cmd);
	return (NULL);
}
