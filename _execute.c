#include "headers.h"

/**
 * _execute - executing the command
 * @args: command input from the user
 * Return: nothing
*/
void _execute(char **args)
{
	pid_t child;
	char *cmd = NULL, *cmd_path = NULL;
	int cmd_count = 1;

	if (args == NULL)
		return;

	cmd = args[0];
	cmd_path = (cmd[0] == '/') ? strdup(cmd) : get_command_path(cmd);

	if (strcmp(cmd, "exit") == 0)
		exit(EXIT_SUCCESS);

	if (cmd_path != NULL)
	{
		child = fork();
		if (child < 0)
		{
			perror("fork");
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			if (execve(cmd_path, args, __environ) == -1)
			{
				perror("execve");
				free(cmd_path);
				_free(args);
				exit(EXIT_FAILURE);
			}
			free(cmd_path);
			_free(args);
			_exit(0);
		}
		else if (child > 0)
		{
			wait(NULL);
			free(cmd_path);
		}
		cmd_count++;
	}
	else
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", cmd_count, cmd);
		cmd_count++;
	}
	
	

}


