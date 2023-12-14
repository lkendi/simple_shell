#include "headers.h"

/**
 * get_command_path - find the specific command in PATH
 * @user_command: user command
 * Return: path to the command or NULL
 */
char *get_command_path(char *user_command)
{
	char *path_val, *path_dup, *full_path, *p_token;
	struct stat stat_buffer;

	path_val = getenv("PATH");
	if (path_val == NULL)
		return (NULL);

	path_dup = strdup(path_val);
	if (path_dup == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	p_token = strtok(path_dup, ":");
	while (p_token != NULL)
	{
		full_path = malloc(strlen(p_token) + strlen(user_command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_dup);
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", p_token, user_command);
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
	return (NULL);
}
