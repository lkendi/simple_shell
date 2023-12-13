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
		/*Display prompt*/
		_prompt();

		/*Get command from user*/
		args = get_command();

		/*Execute the command*/
		_execute(args);

		/*Free memory*/
		_free(args);
	}
	return (0);
	_free(args);

}
