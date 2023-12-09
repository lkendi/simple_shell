#include "headers.h"

/**
* get_path_cmd - find the command in PATH
* @user_command: user command
* Return: path to the cmd or NULL
*/

char *get_path_cmd(char *user_command)
{
	char *path_val, *path_dup, *p_token, *full_cmd;
	struct stat b_stat;

	if (user_command == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		exit(EXIT_FAILURE);
	}
	path_val = get_env_var("PATH");
	if (path_val != NULL)
	{
		path_dup = strdup(path_val);
		p_token = strtok(path_dup, ":");
		
		while (p_token != NULL)
		{
			full_cmd = malloc(strlen(user_command) + strlen(p_token) + 2);
			if (full_cmd == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(full_cmd, p_token);
			strcat(full_cmd, "/");
			strcat(full_cmd, user_command);
			strcat(full_cmd, "\0");

			if (stat(full_cmd, &b_stat) == 0)
			{
				free(path_dup);
				return (full_cmd);
			}

			else
			{
				free(full_cmd);
				p_token = strtok(NULL, ":");
			}
		}
		free(path_dup);
	}
	return (NULL);	
}
