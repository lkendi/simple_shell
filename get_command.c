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
	int i = 0, token_count = 0;
	char **args = NULL, *token;

	input_char_count = getline(&user_input, &len, stdin);

	/*if getline fails or EOF condition*/
	if (input_char_count == -1)
	{
		if(feof(stdin))
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		perror("error");
		free(user_input);
		exit(EXIT_FAILURE);
	}

	/*If enter key only (newline) or spaces*/
	if ((input_char_count == 1 && strcmp(user_input, "\n") == 0 )|| 
			(strspn(user_input, " \t\n") == strlen(user_input)))
	{
		free(user_input);
		return (NULL);
	}

	input_copy = malloc((input_char_count + 1) * sizeof(char));
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
		args[i] = malloc((strlen(token) + 1) * sizeof(char));
		strcpy(args[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	free(input_copy);
	free(user_input);
	return (args);

}