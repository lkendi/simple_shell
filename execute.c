#include "headers.h"

/*Extern variable containing the env vars*/
char **env_vars;

/**
 * get_env_var - gets the value of an environment variable
 * @var: name of the environment variable
 * Return: <TBD>
 */

char *get_env_var(const char *var)
{
	char **current_env;
	char *token;

	if (var == NULL)
	{
		return (NULL);
	}

	current_env = env_vars;
	while (current_env != NULL)
	{
		token = strtok(current_env, "=");
		if (token != NULL)
		{
			if (strcmp(var, token) == 0)
			{
				return (strtok("NULL", "="));
			}
			current_env++;
		}
	}
	return (NULL);
}

/**
* execute - execute command
* @user_command: user command
*/
void execute(char *user_command)
{
	pid_t child;
	char *args[2];
	char *path_val;
	char *token;

	if (user_command == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		exit(EXIT_FAILURE);
	}

	path_val = get_env_var("PATH");
	if (path_val == NULL)
	{
		fprintf("PATH: not found\n");
	}

	token = strtok(path_val, ":");

	/*Create a child process*/
	child = fork();

	if (child < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child > 0)
	{
		/*Parent process*/
		wait(NULL);
	}
	else
	{
		args[0] = user_command;
		args[1] = NULL;

		/*Execute the child process*/
		if (execve(user_command, args, NULL) == -1)
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", child, user_command);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
}
