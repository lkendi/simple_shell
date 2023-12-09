#include "headers.h"

/**
* main - entry point 
* Return: 0
*/


int main()
{
	char user_command[100];

	while (1)
	{
		/*Display prompt*/
		display_prompt();

		/*Get command from user*/
		get_command(user_command);

		/*Execute the command*/
		execute(user_command);

	}

	return (0);

}
