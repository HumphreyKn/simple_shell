#include "main.h"

/**
 * print_notfound - print error message if the exe is nit found in the PATH
 * @exe_name: executable file name
 * @c: sum of the number of commands from user
 * @cmd: the command that is not exist
 * Description: format to print is:  <prog_name>: <c>: <error message>
 *
 * Return: nothing (void)
 */

void print_notfound(char *exe_name, int c, char *cmd)
{
	char dig[1];

	write(2, exe_name, _strlen(exe_name));
	write(2, ": ", 2);
	while (c % 10 != 0)
	{
		dig[0] = (c % 10) + '0';
		c /= 10;
		write(2, dig, 1);
	}
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", _strlen(": not found\n"));
}
