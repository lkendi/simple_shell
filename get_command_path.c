#include "headers.h"

/**
* get_command_path - find the specific command in PATH
* @user_command: user command
* Return: path to the command or NULL
*/

char *get_command_path(char *user_command)
{
	char *path_val, *path_dup, *p_token, *full_cmd;
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
			full_cmd = malloc(c_length + d_length + 2);
			if (full_cmd == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(full_cmd, p_token);
			strcat(full_cmd, "/");
			strcat(full_cmd, user_command);
			strcat(full_cmd, "\0");

			if (stat(full_cmd, &stat_buffer) == 0)
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
