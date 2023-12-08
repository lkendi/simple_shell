#include "headers.h"

/**
* get_command - gets the command from the user
* @user_command: user command
* Return: the user command
*/

char *get_command(char *user_command)
{
	size_t len;
	char *input;

	/*Case where user command is NULL*/

	if (user_command == NULL)
	{
		fprintf(stderr, "invalid buffer or size\n");
	}

	input = fgets(user_command, 100, stdin);

	if (input == NULL)
	{
		/*Handling end of file condition*/
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		printf("Error reading input\n");
		exit(EXIT_FAILURE);
	}

	len = strlen(user_command);
	if (user_command[len - 1] == '\n')
	{
		user_command[len - 1] = '\0';
	}
	return (user_command);

}

