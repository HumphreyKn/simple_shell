#include "main.h"

/**
 * token_num - gets the token number in a string
 * @str: the string to tokenize
 * @delim: the delimiter(seperator) to check to tokenize
 *
 * Return: number of tokens in the string or -1 on fail
 */
int token_num(char *str, char *delim)
{
	char *copystr;
	int num = 0;

	if (str == NULL || delim == NULL)
		return (-1);
	copystr = malloc(_strlen(str) + 1);
	if (copystr == NULL)
	{
		perror("Error");
		exit(-1);
	}
	_strcpy(copystr, str);
	if (strtok(copystr, delim) != NULL)
		num = 1;
	while (strtok(NULL, delim))
		num++;
	free(copystr);
	return (num);
}

/**
 * tokenize - tokenize a given string
 * @string: a string to tokinize (pointer)
 *
 * Return: double pointer to an array of strings
 */
char **tokenize(char *string)
{
	char **argv;
	char *token;
	int toknum, i;
	char delim[] = {' ', '\t', '\n'};

	toknum = token_num(string, delim);
	argv = malloc(sizeof(char *) * (toknum + 1));

	if (argv == NULL)
	{
		perror("Error");
		exit(-1);
	}
	if (toknum == 0)
	{
		argv[0] = NULL;
		return (argv);
	}
	else
	{
		token = strtok(string, delim);
		argv[0] = token;
		for (i = 1; i < toknum; i++)
			argv[i] = strtok(NULL, delim);
		argv[i] = NULL;
		return (argv);
	}
}

/**
 * get_args - splits the strings from user input.
 * @line: pointer to the line passed to the program.
 *
 * Return: A struct containing the command and arguments
 */
full_cmd get_args(char *line)
{
	full_cmd c;

	c.args = tokenize(line);
	c.cmd = c.args[0];
	return (c);
}
