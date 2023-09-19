#include "main.h"
/**
 * put_ss - prints a string
 *
 * @c: string
 * Return: number of bytes
 */
int put_ss(char *c)
{
	int counter = 0;

	if (c)
	{
		for (counter = 0; c[counter] != '\0'; counter++)
		{
			put_car(c[counter]);
		}
	}
	return (counter);
}
