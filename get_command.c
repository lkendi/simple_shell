#include "headers.h"


void handle_eof(char *user_input);
void handle_getline_fail(char *user_input);
char *handle_comment_or_spaces(char *user_input);
void malloc_failure(void);

/**
* handle_eof - handles end of file condition
* @user_input: user command input
* Return: nothing
*/
void handle_eof(char *user_input)
{
	free(user_input);
	exit(EXIT_SUCCESS);
}
/**
* handle_getline_fail - when getline fails
* @user_input: user command input
* Return: nothing
*/

void handle_getline_fail(char *user_input)
{
	perror("error");
	free(user_input);
	exit(EXIT_FAILURE);
}

/**
* malloc_failure - displays malloc error
* Return: nothing
*/

void malloc_failure(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

/**
* get_command - gets the command from the user
* Return: the user command
*/
char **get_command(void)
{
	ssize_t input_char_count = 0;
	size_t len = 0;
	char *user_input = NULL, *input_copy, *token, **args;
	int i = 0, token_count = 0;

	input_char_count = getline(&user_input, &len, stdin);
	if (input_char_count == -1)
	{
		if (feof(stdin))
			handle_eof(user_input);
		handle_getline_fail(user_input);
	}
	/*If enter key only (newline), spaces or comment*/
	/*If enter key only (newline) or spaces*/
	if ((input_char_count == 1 && strcmp(user_input, "\n") == 0) ||
			(strspn(user_input, " \t\n") == strlen(user_input)) ||
			(user_input[0] == '#'))
	{
		free(user_input);
		return (NULL);
	}
	if (strstr(user_input, "#") != NULL)
		user_input = strtok(user_input, "#");

	input_copy = malloc((input_char_count + 1) * sizeof(char));
	if (input_copy == NULL)
		malloc_failure();
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
