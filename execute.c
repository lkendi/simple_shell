#include "headers.h"

/**
* execute - execute command
* @user_command: user command
*/
void execute(char *user_command)
{
	pid_t child;
	char *args[2];
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
