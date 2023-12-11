#include "headers.h"

/**
* get_command - gets the command from the user
* @user_command: user command
* Return: the user command
*/

char **get_command(void)
{
	size_t len = 0;
	ssize_t input_char_count;
	char *user_input = NULL, *input_copy = NULL;
	int i = 0, token_count = 0;
	char **args = NULL, *token;

	input_char_count = getline(&user_input, &len, stdin);

	/*if getline fails or EOF condition*/
	if (input_char_count == -1)
	{
		printf("\n");
		exit(EXIT_FAILURE);
	}

	input_copy = malloc(input_char_count * sizeof(char));
	if (input_copy == NULL)
	{
		perror("malloc error");
		exit (EXIT_FAILURE);
	}
	strcpy(input_copy, user_input);

	/*split the user_input string*/
	token = strtok(user_input, " \n");
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, " \n");
	}
	token_count++;

	/*add each token to an array*/
	args = malloc(token_count * sizeof(char *));
	token = strtok(input_copy, " \n");
	while (token != NULL)
	{
		args[i] = malloc(strlen(token) * sizeof(char));
		strcpy(args[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	free(input_copy);
	free(user_input);
	return (args);
}
