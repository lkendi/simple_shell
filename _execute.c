#include "headers.h"


void excve(char *cmd, char **args);
/**
 * excve - execute a cmd
 * @cmd: command
 * @args: user-input
*/

void excve(char *cmd, char **args)
{
	if (execve(cmd, args, NULL) == -1)
	{
		fprintf(stderr, "./hsh: %d: %s: not found \n", getpid(), cmd);
		exit(EXIT_FAILURE);
	}
}
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
		fprintf(stderr, "invalid command\n");
		exit(EXIT_FAILURE);
	}
	cmd = args[0];
	/*PATH handling*/
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
		/*If command not found in PATH*/
		child = fork();
		if (child < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child > 0)
		{
			wait(NULL);
		}
		else
		{
			excve(cmd, args);
		}
	}
}
