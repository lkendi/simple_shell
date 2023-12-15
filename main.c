#include "headers.h"

/**
* main - entry point
* Return: 0
*/

int main(void)
{
	char **args;



	while (1)
	{
		args = get_command();
		_execute(args);
		if (args != NULL)
		{
			_free(args);
		}
	}
	return (0);

}
