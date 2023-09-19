#include "main.h"
#include <stdio.h>
/**
 * put_car - prints a character
 * @c: char input
 * Return: 1
 */
int put_car(char c)
{
	return (write(1, &c, 1));
}
