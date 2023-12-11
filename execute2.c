#include "headers.h"

void _execute(char **args)
{
	char *cmd = NULL, *cmd_path = NULL;

	if (args == NULL)
	{
		fprintf(stderr, "invalid command\n");
		exit(EXIT_FAILURE);
	}
	
	cmd = args[0];
	cmd_path = get_command_path(cmd);
		
	if (cmd_path != NULL)
	{
		if (execve(cmd_path, args, NULL) == -1)
		{
			perror("excve");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}	
	}
	else
	{
		fprintf(stderr, "./hsh: %s: not found\n", cmd);
		exit(EXIT_FAILURE);
	}
}
