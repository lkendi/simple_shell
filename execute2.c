#include "headers.h"

void exec(char **args)
{
	char *cmd, *cmd_path;

	if (args == NULL)
	{
		fprintf(stderr, "no command\n", cmd);
		exit(EXIT_FAILURE);
	}
	
	cmd = args[0];
	cmd_path = get_path_cmd(cmd);
		
	if (cmd_path != NULL)
	{
		if (execve(cmd2, args, NULL) == -1)
		{
			perror("excve");
			exit(EXIT_FAILURE);
		}	
		free(cmd_path);
	}
	else
	{
		fprintf(stderr, "%s: not found\n", cmd);
		exit(EXIT_FAILURE);
	}
}
