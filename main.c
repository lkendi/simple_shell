#include "headers.h"

/**
* main - entry point
* Return: to be determined
*/


int main(void)
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

}
