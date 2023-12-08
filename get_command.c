#include "headers.h"

/**
* get_command - gets the command from the user
* @user_command: user command
* Return: the user command
*/

char *get_command(char *user_command)
{
	size_t len;

	/*Case where user command is NULL*/

	if (user_command == NULL)
	{
		fprintf(stderr, "invalid buffer or size\n");
	}

	fgets(user_command, 100, stdin);
	len = strlen(user_command);
	if (user_command[len - 1] == '\n')
	{
		user_command[len - 1] = '\0';
	}
	return (user_command);

}

