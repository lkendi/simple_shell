#include "headers.h"

/**
 * _free - frees memory allocated for an array of strings
 * @args: array of strings
 * Return: nothing
*/

void _free(char **args)
{
	int i = 0;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
