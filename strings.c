#include "main.h"

/**
 * _strlen - calculates the length
 * @s: a pointer used to access the memory address of the string passed
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: memory address to the destination variable
 * @src: memory address to the source variable
 *
 * Return: a pointer to the dest variable containing the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *str = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (str);
}

/**
 * _strcpy - copies strings to pointers including the terminating null byte \0
 * @dest: the pointed string
 * @src: the source
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *pt = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (pt);
}

/**
 * _strcmp - compares two strings.
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if the s1 and s2 are equal
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int str;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != 0 && *(s2 + i) != 0)
		i++;
	if (*(s1 + i) == *(s2 + i))
		str = 0;
	else
		str = (int)*(s1 + i) - (int)*(s2 + i);
	return (str);
}

/**
 * _strncmp - compares two strings to spicific length.
 * @s1: First string
 * @s2: Second string
 * @n: number of bytes to compare
 *
 * Return: 0 if the s1 and s2 are equal
*/

int _strncmp(char *s1, char *s2, size_t n)
{
	int i = 0;
	int str;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		i++;
		if (i >= (int)n)
			return (0);
	}
	if (*(s1 + i) == *(s2 + i))
		str = 0;
	else
		str = (int)*(s1 + i) - (int)*(s2 + i);
	return (str);
}
