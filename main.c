#include "headers.h"

/**
* main - entry point 
* Return: 0
*/

int main(void)
{
	char **args;
	int i = 0;

	while (1)
	{
		/*Display prompt*/
		_prompt();

		/*Get command from user*/
		args = get_command();

		/*Execute the command*/
		_execute(args);

		/*Free args memory*/
		if (args != NULL)
		{
			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}
	}

	return (0);

}
