#include "main.h"
/**
 * print_err_m - prints the error message
 * @prog_name: name the the program called by
 * @c: cumulative sum of the number of commands given
 * Return: nothing (void)
 */
void print_err_m(char *prog_name, int c)
{
	char dig[1];

	write(1, prog_name, _strlen(prog_name));
	write(1, ": ", 2);
	while (c % 10 != 0)
	{
		dig[0] = (c % 10) + '0';
		c /= 10;
		write(1, dig, 1);
	}
	write(1, ": ", 2);
}
