#include "headers.h"

/**
* get_command - gets the command from the user
* Return: the user command
*/
char **get_command(void)
{
	ssize_t input_char_count = 0;
	size_t len = 0;
	char *user_input = NULL, *input_copy = NULL;
	char **args;

	input_char_count = getline(&user_input, &len, stdin);

	/*if getline fails or EOF condition*/
	if (input_char_count == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(user_input);
			exit(EXIT_SUCCESS);

		}
		perror("error");
		free(user_input);
		exit(EXIT_FAILURE);
	}

	/*If enter key only (newline)*/
	if (input_char_count == 1 && strcmp(user_input, "\n") == 0)
	{
		free(user_input);
		return (NULL);
	}

	input_copy = malloc((input_char_count + 1) * sizeof(char));
	if (input_copy == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	strcpy(input_copy, user_input);

	args = _tokenize(input_copy);
	free(input_copy);
	free(user_input);
	return (args);
}
