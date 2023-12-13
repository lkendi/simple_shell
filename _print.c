#include "headers.h"

/**
 * _print - prints a string
 * @str: string to print
 * Return: nothing
*/

void _print(char *str)
{
	write(0, str, strlen(str));
}
