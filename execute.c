#include "headers.h"

/**
<<<<<<< HEAD
=======
* get_env_var - gets the value of an environment variable
* @var: name of the environment variable
* Return: <TBD>
*/

char *get_env_var(const char *var)
{
	if (var == NULL)
	{
		return (NULL);
	}

	extern char **environ;
	char **current_env;
	char *token;

	if (var == NULL)
	{
		return (NULL);
	}

	current_env = environ;

	while (current_env != NULL)
	{
		token = strtok(*current_env, "=");
		if (token != NULL)
		{
			if (strcmp(var, token) == 0)
			{
				return (strtok(NULL, "="));
			}
		}
		current_env++;
	}
	return (NULL);
}

/**
>>>>>>> 1c3c04c875675bb3252eda1f6595adc64ea1e127
* execute - execute command
* @user_command: user command
*/
void execute(char *user_command)
{
	pid_t child;
	char *args[2];
<<<<<<< HEAD
	char *path_val, *path_dup, *p_token, *full_cmd;
	struct stat b_stat;
=======

	char *path_val;

	char *token;
>>>>>>> 1c3c04c875675bb3252eda1f6595adc64ea1e127

	if (user_command == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		exit(EXIT_FAILURE);
	}
	path_val = get_env_var("PATH");
	if (path_val != NULL)
	{
		path_dup = strdup(path_val);
	}
	p_token = strtok(path_dup, ":");
	while (p_token != NULL)
	{
		full_cmd = malloc(strlen(user_command) + strlen(p_token) + 2);
		strcpy(full_cmd, p_token);
		strcat(full_cmd, '/');
		strcat(full_cmd, user_command);
		strcat(full_cmd, '\0');

		if (stat(full_cmd, &b_stat) == 0)
		{
			return (full_cmd);
			free(path_dup);
		}
		else
		{
			free(full_cmd);
			p_token = strtok(NULL, ":");
		}
	}	
}
