#include "headers.h"

/**
 * get_command - gets the command from the user
 * @command: user command
 * @c_size: command length
 * Return: the user command
 */

char *get_command(char *user_command)
{
	size_t len;
	
	fgets(user_command, 100, stdin);
	len = strlen(user_command);
	if (user_command[len - 1] == '\n')
	{
		user_command[len - 1] = '\0'
	}
	return (user_command);

	/*Add case where user command is NULL*/
}
