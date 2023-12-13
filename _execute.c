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

	if (args == NULL)
	{
		return;
	}
	cmd = args[0];

	if (strcmp(cmd, "exit") == 0)
		exit(EXIT_SUCCESS);

	cmd_path = (cmd[0] == '/') ? strdup(cmd) : get_command_path(cmd);
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
			if (execve(cmd_path, args, NULL) == -1)
			{
				perror("excve");
				free(cmd_path);
				exit(EXIT_FAILURE);
			}
		}
		else if (child > 0)
		{
			wait(NULL);
			free(cmd_path);
		}
	}
	else
		fprintf(stderr, "./hsh: %d: %s: not found \n", getpid(), cmd);
}

