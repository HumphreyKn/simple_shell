#include "main.h"

/**
 * _free - frees pointer
 * @p1: pointer memory to free
 *
 * Return: nothing
 */
void _free(void *p1, ...)
{
	void *ptr;

	va_list ptrs;

	va_start(ptrs, p1);

	ptr = p1;
	while (ptr != NULL)
	{
		free(ptr);
		ptr = va_arg(ptrs, void*);
	}
	va_end(ptrs);
}
