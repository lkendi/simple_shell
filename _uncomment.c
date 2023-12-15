#include "headers.h"

/**
 * _uncomment - removes a comment
 * @str: string to uncomment
*/

void _uncomment(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
	}
}
