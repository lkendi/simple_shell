#include "header.h"


/*Main function*/
int main(void)
{
	char *user_input = NULL; /*command input from the user*/
	ssize_t input_char_count; /*getline output*/
	size_t buffer_size = 0; /*number of bytes for getline*/
	char *input_copy = NULL; /*user input duplicate*/
	const char *delimiter = " \n"; /*space and newline are the delimiters to separate cmds and args*/
	char *token;
	int token_count = 0; /*number of tokens in the user_input*/
	char **args; /*array containing the separate parts of the user string*/
	int i;
	
	while (1)
	{
		/*HANDLING COMMANDS WITHOUT ARGUMENTS*/

		/*Display prompt*/
		printf("$ ");

		/*Prompt for interactive mode*/
		/*printf("($) ");*/ 

		/*Get user command*/
		input_char_count = getline(&user_input, &buffer_size, stdin);

		/*if getline fails or end of file condition*/
		if (input_char_count == -1)
		{
			printf("\n");
			return (-1);
		}
		
		/*Make a copy of the input string*/
		input_copy = malloc(sizeof(char) * input_char_count);
		if(input_copy == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
		strcpy(input_copy, user_input);

		/*tokenize/split the user_input string and count the number of tokens*/
		token = strtok(user_input, delimiter);
		while (token != NULL)
		{
			token_count++;
			token = strtok(NULL, delimiter);
		}
		token_count++;

		/*array of strings after tokenization*/
		args = malloc(sizeof(char *) * token_count);

		/*store each token in the array*/
		token = strtok(input_copy, delimiter);
		for (i = 0; token != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * strlen(token));
			strcpy(args[i], token);
			token = strtok(NULL, delimiter);
		}
		args[i] = NULL;


		/*Execute the user command*/
		execute(args);

		/*exit command*/
		if (strcmp(user_input, "exit\n") == 0)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}

	}

	/*free memory*/
	free(input_copy);
	free(user_input);
	return (0);
}
