#include "headers.h"

/**
* _tokenize - tokenizes the user input
* @input_copy: copy of the user input
* Return: tokenized arguments
*/
char **_tokenize(char *input_copy)
{
	int i = 0, token_count = 0;
	char **args = NULL, *token;

	token = strtok(input_copy, " \n");
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, " \n");
	}
	token_count++;
	args = malloc(token_count * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_copy, " \n");
	while (token != NULL)
	{
		args[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (args[i] == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}
		strcpy(args[i], token);
		token = strtok(NULL, " \n");
		i++;
	}
	args[i] = NULL;
	return (args);
	_free(args);
}
