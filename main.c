#include "headers.h"

/**
* main - entry point 
* Return: 0
*/


int main(int argc, char **argv)
{
	char user_command[100];

	(void)argc;

	while (1)
	{
		/*Display prompt*/
		display_prompt();

		/*Get command from user*/
		get_command(user_command);

		/*Execute the command*/
		exec(argv);

	}

	return (0);

}
