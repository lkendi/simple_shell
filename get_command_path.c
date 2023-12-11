#include "headers.h"

/**
* get_command_path - find the specific command in PATH
* @user_command: user command
* Return: path to the command or NULL
*/

char *get_command_path(char *user_command)
{
	char *path_val, *path_dup, *p_token, *full_path;
	struct stat stat_buffer;
	int c_length, d_length;

	if (user_command == NULL)
	{
		fprintf(stderr, "Invalid command\n");
		exit(EXIT_FAILURE);
	}

	path_val = getenv("PATH");
	if (path_val != NULL)
	{
		
		path_dup = strdup(path_val);
		c_length = strlen(user_command);
		p_token = strtok(path_dup, ":");
			
		while (p_token != NULL)
		{
			d_length = strlen(p_token);
			full_path = malloc(c_length + d_length + 2);
			if (full_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			strcpy(full_path, p_token);
			strcat(full_path, "/");
			strcat(full_path, user_command);
			/*strcat(full_path, "\0");*/

			if (stat(full_path, &stat_buffer) == 0)
			{
				free(path_dup);
				return (full_path);
			}
			else
			{
				free(full_path);
				p_token = strtok(NULL, ":");
			}
		}
		free(path_dup);
	}
	
		perror("getenv");
		exit(EXIT_FAILURE);
		return (NULL);
}

